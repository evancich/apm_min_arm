
#include "UARTDriver.h"

using namespace IMX6S;

IMX6SUARTDriver::IMX6SUARTDriver() {}

void IMX6SUARTDriver::begin(uint32_t b) {}
void IMX6SUARTDriver::begin(uint32_t b, uint16_t rxS, uint16_t txS) {}
void IMX6SUARTDriver::end() {}
void IMX6SUARTDriver::flush() {}
bool IMX6SUARTDriver::is_initialized() { return false; }
void IMX6SUARTDriver::set_blocking_writes(bool blocking) {}
bool IMX6SUARTDriver::tx_pending() { return false; }

/* IMX6S implementations of Stream virtual methods */
int16_t IMX6SUARTDriver::available() { return 0; }
int16_t IMX6SUARTDriver::txspace() { return 1; }
int16_t IMX6SUARTDriver::read() { return -1; }

/* IMX6S implementations of Print virtual methods */
size_t IMX6SUARTDriver::write(uint8_t c) { return 0; }

size_t IMX6SUARTDriver::write(const uint8_t *buffer, size_t size)
{
    size_t n = 0;
    while (size--) {
        n += write(*buffer++);
    }
    return n;
}
