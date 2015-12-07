
#include "RCOutput.h"

using namespace IMX6S;

void IMX6SRCOutput::init(void* machtnichts) {}

void IMX6SRCOutput::set_freq(uint32_t chmask, uint16_t freq_hz) {}

uint16_t IMX6SRCOutput::get_freq(uint8_t ch) {
    return 50;
}

void IMX6SRCOutput::enable_ch(uint8_t ch)
{}

void IMX6SRCOutput::disable_ch(uint8_t ch)
{}

void IMX6SRCOutput::write(uint8_t ch, uint16_t period_us)
{}

uint16_t IMX6SRCOutput::read(uint8_t ch) {
    return 900;
}

void IMX6SRCOutput::read(uint16_t* period_us, uint8_t len)
{}

