
#ifndef __AP_HAL_IMX6S_STORAGE_H__
#define __AP_HAL_IMX6S_STORAGE_H__

#include "AP_HAL_IMX6S.h"

class IMX6S::IMX6SStorage : public AP_HAL::Storage {
public:
    IMX6SStorage();
    void init(void *);
    void read_block(void *dst, uint16_t src, size_t n);
    void write_block(uint16_t dst, const void* src, size_t n);
};

#endif // __AP_HAL_IMX6S_STORAGE_H__
