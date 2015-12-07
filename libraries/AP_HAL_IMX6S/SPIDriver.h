
#ifndef __AP_HAL_IMX6S_SPIDRIVER_H__
#define __AP_HAL_IMX6S_SPIDRIVER_H__

#include "AP_HAL_IMX6S.h"
#include "Semaphores.h"

class IMX6S::IMX6SSPIDeviceDriver : public AP_HAL::SPIDeviceDriver {
public:
    IMX6SSPIDeviceDriver();
    void init();
    AP_HAL::Semaphore* get_semaphore();
    bool transaction(const uint8_t *tx, uint8_t *rx, uint16_t len);

    void cs_assert();
    void cs_release();
    uint8_t transfer (uint8_t data);
    void transfer (const uint8_t *data, uint16_t len);
private:
    IMX6SSemaphore _semaphore;
};

class IMX6S::IMX6SSPIDeviceManager : public AP_HAL::SPIDeviceManager {
public:
    IMX6SSPIDeviceManager();
    void init(void *);
    AP_HAL::SPIDeviceDriver* device(enum AP_HAL::SPIDevice, uint8_t index);
private:
    IMX6SSPIDeviceDriver _device;
};

#endif // __AP_HAL_IMX6S_SPIDRIVER_H__
