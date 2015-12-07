
#include "RCInput.h"

using namespace IMX6S;
IMX6SRCInput::IMX6SRCInput()
{}

void IMX6SRCInput::init(void* machtnichts)
{}

bool IMX6SRCInput::new_input() {
    return false;
}

uint8_t IMX6SRCInput::num_channels() {
    return 0;
}

uint16_t IMX6SRCInput::read(uint8_t ch) {
    if (ch == 2) return 900; /* throttle should be low, for safety */
    else return 1500;
}

uint8_t IMX6SRCInput::read(uint16_t* periods, uint8_t len) {
    for (uint8_t i = 0; i < len; i++){
        if (i == 2) periods[i] = 900;
        else periods[i] = 1500;
    }
    return len;
}

bool IMX6SRCInput::set_overrides(int16_t *overrides, uint8_t len) {
    return true;
}

bool IMX6SRCInput::set_override(uint8_t channel, int16_t override) {
    return true;
}

void IMX6SRCInput::clear_overrides()
{}

