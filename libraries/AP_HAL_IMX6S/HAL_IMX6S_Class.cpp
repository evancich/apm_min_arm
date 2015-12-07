
#include <AP_HAL/AP_HAL.h>
#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S

#include <assert.h>

#include "HAL_IMX6S_Class.h"
#include "AP_HAL_IMX6S_Private.h"

using namespace IMX6S;

static IMX6SUARTDriver uartADriver;
static IMX6SUARTDriver uartBDriver;
static IMX6SUARTDriver uartCDriver;
static IMX6SSemaphore  i2cSemaphore;
static IMX6SI2CDriver  i2cDriver(&i2cSemaphore);
static IMX6SSPIDeviceManager spiDeviceManager;
static IMX6SAnalogIn analogIn;
static IMX6SStorage storageDriver;
static IMX6SGPIO gpioDriver;
static IMX6SRCInput rcinDriver;
static IMX6SRCOutput rcoutDriver;
static IMX6SScheduler schedulerInstance;
static IMX6SUtil utilInstance;

HAL_IMX6S::HAL_IMX6S() :
    AP_HAL::HAL(
        &uartADriver,
        &uartBDriver,
        &uartCDriver,
        NULL,            /* no uartD */
        NULL,            /* no uartE */
        &i2cDriver,
        NULL, /* only one i2c */
        NULL, /* only one i2c */
        &spiDeviceManager,
        &analogIn,
        &storageDriver,
        &uartADriver,
        &gpioDriver,
        &rcinDriver,
        &rcoutDriver,
        &schedulerInstance,
        &utilInstance),
    _member(new IMX6SPrivateMember(123))
{}

void HAL_IMX6S::run(int argc, char* const argv[], Callbacks* callbacks) const
{
    assert(callbacks);

    /* initialize all drivers and private members here.
     * up to the programmer to do this in the correct order.
     * Scheduler should likely come first. */
    scheduler->init(NULL);
    uartA->begin(115200);
    _member->init();

    callbacks->setup();
    scheduler->system_initialized();

    for (;;) {
        callbacks->loop();
    }
}

const AP_HAL::HAL& AP_HAL::get_HAL() {
    static const HAL_IMX6S hal;
    return hal;
}

#endif
