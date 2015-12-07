
#include "Scheduler.h"

#include <stdarg.h>

using namespace IMX6S;

extern const AP_HAL::HAL& hal;

IMX6SScheduler::IMX6SScheduler()
{}

void IMX6SScheduler::init(void* machtnichts)
{}

void IMX6SScheduler::delay(uint16_t ms)
{}

uint64_t IMX6SScheduler::millis64() {
    return 10000;
}

uint64_t IMX6SScheduler::micros64() {
    return 200000;
}

uint32_t IMX6SScheduler::millis() {
    return millis64();
}

uint32_t IMX6SScheduler::micros() {
    return micros64();
}

void IMX6SScheduler::delay_microseconds(uint16_t us)
{}

void IMX6SScheduler::register_delay_callback(AP_HAL::Proc k,
            uint16_t min_time_ms)
{}

void IMX6SScheduler::register_timer_process(AP_HAL::MemberProc k)
{}

void IMX6SScheduler::register_io_process(AP_HAL::MemberProc k)
{}

void IMX6SScheduler::register_timer_failsafe(AP_HAL::Proc, uint32_t period_us)
{}

void IMX6SScheduler::suspend_timer_procs()
{}

void IMX6SScheduler::resume_timer_procs()
{}

bool IMX6SScheduler::in_timerprocess() {
    return false;
}

void IMX6SScheduler::begin_atomic()
{}

void IMX6SScheduler::end_atomic()
{}

bool IMX6SScheduler::system_initializing() {
    return false;
}

void IMX6SScheduler::system_initialized()
{}

void IMX6SScheduler::panic(const char *errormsg, ...)
{
    va_list ap;

    va_start(ap, errormsg);
    hal.console->vprintf(errormsg, ap);
    va_end(ap);
    hal.console->printf("\n");

    for(;;);
}

void IMX6SScheduler::reboot(bool hold_in_bootloader) {
    for(;;);
}
