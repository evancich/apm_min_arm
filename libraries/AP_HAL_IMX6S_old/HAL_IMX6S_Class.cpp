/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S

#include <AP_HAL_IMX6S.h>
#include "HAL_IMX6S_Class.h"
#include <SchedulerIMX6S.h>
#include "UARTDriver.h"
#include "I2CDriver.h"
#include "Semaphores.h"
#include "Storage.h"
#include "RCInput.h"
#include "RCOutput.h"
#include "AnalogIn.h"
#include "Util.h"
#include "GPIO.h"

//#include <AP_HAL_Empty.h>
//#include <AP_HAL_Empty_Private.h>

#include <stdlib.h>
//#include <systemlib/systemlib.h>
//#include <nuttx/config.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
//#include <poll.h>
//#include <drivers/drv_hrt.h>

using namespace IMX6S;

static IMX6SSemaphore  i2cSemaphore;
static IMX6SI2CDriver i2cDriver(&i2cSemaphore);
//static Empty::EmptySPIDeviceManager spiDeviceManager;
static IMX6SGPIO gpioDriver;
static IMX6SScheduler schedulerInstance;
//static IMX6SStorage storageDriver;
static IMX6SRCInput rcinDriver;
static IMX6SRCOutput rcoutDriver;
//static IMX6SAnalogIn analogIn;
static IMX6SUtil utilInstance;

#if defined(CONFIG_ARCH_BOARD_PX4FMU_V2)
#define UARTA_DEFAULT_DEVICE "/dev/ttyACM0"
#define UARTB_DEFAULT_DEVICE "/dev/ttyS3"
#define UARTC_DEFAULT_DEVICE "/dev/ttyS1"
#define UARTD_DEFAULT_DEVICE "/dev/ttyS2"
#define UARTE_DEFAULT_DEVICE "/dev/ttyS6"
#else
#define UARTA_DEFAULT_DEVICE "/dev/ttyACM0"
#define UARTB_DEFAULT_DEVICE "/dev/ttyS3"
#define UARTC_DEFAULT_DEVICE "/dev/ttyS2"
#define UARTD_DEFAULT_DEVICE "/dev/null"
#define UARTE_DEFAULT_DEVICE "/dev/null"
#endif

// 3 UART drivers, for GPS plus two mavlink-enabled devices
static IMX6SUARTDriver uartADriver(UARTB_DEFAULT_DEVICE, "APM_uartB");
static IMX6SUARTDriver uartBDriver(UARTB_DEFAULT_DEVICE, "APM_uartB");
static IMX6SUARTDriver uartCDriver(UARTC_DEFAULT_DEVICE, "APM_uartC");
static IMX6SUARTDriver uartDDriver(UARTD_DEFAULT_DEVICE, "APM_uartD");
static IMX6SUARTDriver uartEDriver(UARTE_DEFAULT_DEVICE, "APM_uartE");

HAL_IMX6S::HAL_IMX6S() :
    AP_HAL::HAL(
        &uartADriver,  /* uartA */
	    &uartBDriver,  /* uartB */
		&uartCDriver,  /* uartC */
		NULL,          //&uartDDriver,  /* uartD */
		NULL,          //&uartEDriver,  /* uartE */
        &i2cDriver,    /* i2c */
        NULL,          /* only one i2c */
        NULL,          /* only one i2c */
        NULL, //&spiDeviceManager, /* spi */
		NULL, //&analogIn, /* analogin */
		NULL, //&storageDriver, /* storage */
		&uartADriver, /* console */
		&gpioDriver, /* gpio */
		&rcinDriver,  /* rcinput */
		NULL, //&rcoutDriver, /* rcoutput */
		&schedulerInstance, /* scheduler */
		&utilInstance) /* util */
{}

bool _IMX6S_thread_should_exit;// = false;        /**< Daemon exit flag */
static bool thread_running;// = false;        /**< Daemon status flag */
static int daemon_task;                /**< Handle of daemon task / thread */
bool IMX6S_ran_overtime;

extern const AP_HAL::HAL& hal;

/*
  set the priority of the main APM task
 */
void hal_IMX6S_set_priority(uint8_t priority)
{
#if 0
    struct sched_param param;
    param.sched_priority = priority;
    sched_setscheduler(daemon_task, SCHED_FIFO, &param);    
#endif
}

/*
  this is called when loop() takes more than 1 second to run. If that
  happens then something is blocking for a long time in the main
  sketch - probably waiting on a low priority driver. Set the priority
  of the APM task low to let the driver run.
 */
static void loop_overtime(void *)
{
    hal_IMX6S_set_priority(APM_OVERTIME_PRIORITY);
    IMX6S_ran_overtime = true;
}

static int main_loop(int argc, char **argv)
{
#if 0
    extern void setup(void);
    extern void loop(void);


    hal.uartA->begin(115200);
    hal.uartB->begin(38400);
    hal.uartC->begin(57600);
    hal.uartD->begin(57600);
    hal.uartE->begin(57600);
    hal.scheduler->init(NULL);
    hal.rcin->init(NULL);
    hal.rcout->init(NULL);
    hal.analogin->init(NULL);
    hal.gpio->init();


    /*
      run setup() at low priority to ensure CLI doesn't hang the
      system, and to allow initial sensor read loops to run
     */
    hal_IMX6S_set_priority(APM_STARTUP_PRIORITY);

    schedulerInstance.hal_initialized();

    setup();
    hal.scheduler->system_initialized();

    perf_counter_t perf_loop = perf_alloc(PC_ELAPSED, "APM_loop");
    perf_counter_t perf_overrun = perf_alloc(PC_COUNT, "APM_overrun");
    struct hrt_call loop_overtime_call;

    thread_running = true;

    /*
      switch to high priority for main loop
     */
    hal_IMX6S_set_priority(APM_MAIN_PRIORITY);

    while (!_IMX6S_thread_should_exit) {
        perf_begin(perf_loop);
        
        /*
          this ensures a tight loop waiting on a lower priority driver
          will eventually give up some time for the driver to run. It
          will only ever be called if a loop() call runs for more than
          0.1 second
         */
        hrt_call_after(&loop_overtime_call, 100000, (hrt_callout)loop_overtime, NULL);

        loop();

        if (IMX6S_ran_overtime) {
            /*
              we ran over 1s in loop(), and our priority was lowered
              to let a driver run. Set it back to high priority now.
             */
            hal_IMX6S_set_priority(APM_MAIN_PRIORITY);
            perf_count(perf_overrun);
            IMX6S_ran_overtime = false;
        }

        perf_end(perf_loop);

        /*
          give up 250 microseconds of time, to ensure drivers get a
          chance to run. This relies on the accurate semaphore wait
          using hrt in semaphore.cpp
         */
        hal.scheduler->delay_microseconds(250);
    }
    thread_running = false;
#endif
    return 0;
}

static void usage(void)
{
#if 0
    printf("Usage: %s [options] {start,stop,status}\n", SKETCHNAME);
    printf("Options:\n");
    printf("\t-d  DEVICE         set terminal device (default %s)\n", UARTA_DEFAULT_DEVICE);
    printf("\t-d2 DEVICE         set second terminal device (default %s)\n", UARTC_DEFAULT_DEVICE);
    printf("\t-d3 DEVICE         set 3rd terminal device (default %s)\n", UARTD_DEFAULT_DEVICE);
    printf("\t-d4 DEVICE         set 2nd GPS device (default %s)\n", UARTE_DEFAULT_DEVICE);
    printf("\n");
#endif
}


void HAL_IMX6S::init(int argc, char * const argv[]) const
{

	// To do - Initialize all MCU Specific Code here ....
	// It is Expected that basic services such as Attach Platform Resources have been
	//  sucessfully called prior to calling this function.  THis function is the main entry point
	//  for the HAL layer for the Nitrogen IMX6.

#if 0
    int i;
    const char *deviceA = UARTA_DEFAULT_DEVICE;
    const char *deviceC = UARTC_DEFAULT_DEVICE;
    const char *deviceD = UARTD_DEFAULT_DEVICE;
    const char *deviceE = UARTE_DEFAULT_DEVICE;

    if (argc < 1) {
        printf("%s: missing command (try '%s start')", 
               SKETCHNAME, SKETCHNAME);
        usage();
        exit(1);
    }

    for (i=0; i<argc; i++) {
        if (strcmp(argv[i], "start") == 0) {
            if (thread_running) {
                printf("%s already running\n", SKETCHNAME);
                /* this is not an error */
                exit(0);
            }

            uartADriver.set_device_path(deviceA);
            uartCDriver.set_device_path(deviceC);
            uartDDriver.set_device_path(deviceD);
            uartEDriver.set_device_path(deviceE);
            printf("Starting %s uartA=%s uartC=%s uartD=%s uartE=%s\n", 
                   SKETCHNAME, deviceA, deviceC, deviceD, deviceE);

            _IMX6S_thread_should_exit = false;
            daemon_task = IMX6S_task_spawn_cmd(SKETCHNAME,
                                             SCHED_FIFO,
                                             APM_MAIN_PRIORITY,
                                             APM_MAIN_THREAD_STACK_SIZE,
                                             main_loop,
                                             NULL);
            exit(0);
        }

        if (strcmp(argv[i], "stop") == 0) {
            _IMX6S_thread_should_exit = true;
            exit(0);
        }
 
        if (strcmp(argv[i], "status") == 0) {
            if (_IMX6S_thread_should_exit && thread_running) {
                printf("\t%s is exiting\n", SKETCHNAME);
            } else if (thread_running) {
                printf("\t%s is running\n", SKETCHNAME);
            } else {
                printf("\t%s is not started\n", SKETCHNAME);
            }
            exit(0);
        }

        if (strcmp(argv[i], "-d") == 0) {
            // set terminal device
            if (argc > i + 1) {
                deviceA = strdup(argv[i+1]);
            } else {
                printf("missing parameter to -d DEVICE\n");
                usage();
                exit(1);
            }
        }

        if (strcmp(argv[i], "-d2") == 0) {
            // set uartC terminal device
            if (argc > i + 1) {
                deviceC = strdup(argv[i+1]);
            } else {
                printf("missing parameter to -d2 DEVICE\n");
                usage();
                exit(1);
            }
        }

        if (strcmp(argv[i], "-d3") == 0) {
            // set uartD terminal device
            if (argc > i + 1) {
                deviceD = strdup(argv[i+1]);
            } else {
                printf("missing parameter to -d3 DEVICE\n");
                usage();
                exit(1);
            }
        }

        if (strcmp(argv[i], "-d4") == 0) {
            // set uartE 2nd GPS device
            if (argc > i + 1) {
                deviceE = strdup(argv[i+1]);
            } else {
                printf("missing parameter to -d4 DEVICE\n");
                usage();
                exit(1);
            }
        }
    }
 
    usage();
    exit(1);
#endif
}

const AP_HAL::HAL& AP_HAL::get_HAL() {
    static const HAL_Empty hal;
    return hal;
}
const HAL_IMX6S AP_HAL_IMX6S;

#endif // CONFIG_HAL_BOARD == HAL_BOARD_IMX6S

