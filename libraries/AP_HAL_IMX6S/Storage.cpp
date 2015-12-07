
#include <string.h>
#include "Storage.h"

using namespace IMX6S;

IMX6SStorage::IMX6SStorage()
{}

void IMX6SStorage::init(void*)
{}

void IMX6SStorage::read_block(void* dst, uint16_t src, size_t n) {
    memset(dst, 0, n);
}

void IMX6SStorage::write_block(uint16_t loc, const void* src, size_t n)
{}

