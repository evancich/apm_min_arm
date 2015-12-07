
#include "SPIDriver.h"

using namespace IMX6S;

IMX6SSPIDeviceDriver::IMX6SSPIDeviceDriver()
{}

void IMX6SSPIDeviceDriver::init()
{}

AP_HAL::Semaphore* IMX6SSPIDeviceDriver::get_semaphore()
{
    return &_semaphore;
}

bool IMX6SSPIDeviceDriver::transaction(const uint8_t *tx, uint8_t *rx, uint16_t len)
{
    return true;
}


void IMX6SSPIDeviceDriver::cs_assert()
{}

void IMX6SSPIDeviceDriver::cs_release()
{}

uint8_t IMX6SSPIDeviceDriver::transfer (uint8_t data)
{
    return 0;
}

void IMX6SSPIDeviceDriver::transfer (const uint8_t *data, uint16_t len)
{
}

IMX6SSPIDeviceManager::IMX6SSPIDeviceManager()
{}

void IMX6SSPIDeviceManager::init(void *)
{}

AP_HAL::SPIDeviceDriver* IMX6SSPIDeviceManager::device(enum AP_HAL::SPIDevice, uint8_t index)
{
    return &_device;
}

