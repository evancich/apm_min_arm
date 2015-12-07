#include "AnalogIn.h"

using namespace IMX6S;

IMX6SAnalogSource::IMX6SAnalogSource(float v) :
    _v(v)
{}

float IMX6SAnalogSource::read_average() {
    return _v;
}

float IMX6SAnalogSource::voltage_average() {
    return 5.0f * _v / 1024.0f;
}

float IMX6SAnalogSource::voltage_latest() {
    return 5.0f * _v / 1024.0f;
}

float IMX6SAnalogSource::read_latest() {
    return _v;
}

void IMX6SAnalogSource::set_pin(uint8_t p)
{}

void IMX6SAnalogSource::set_stop_pin(uint8_t p)
{}

void IMX6SAnalogSource::set_settle_time(uint16_t settle_time_ms)
{}

IMX6SAnalogIn::IMX6SAnalogIn()
{}

void IMX6SAnalogIn::init(void* machtnichts)
{}

AP_HAL::AnalogSource* IMX6SAnalogIn::channel(int16_t n) {
    return new IMX6SAnalogSource(1.11);
}

float IMX6SAnalogIn::board_voltage(void)
{
    return 0;
}
