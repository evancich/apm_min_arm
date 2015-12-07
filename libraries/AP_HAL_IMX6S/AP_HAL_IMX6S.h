
#ifndef __AP_HAL_IMX6S_H__
#define __AP_HAL_IMX6S_H__

/* Your layer exports should depend on AP_HAL.h ONLY. */
#include <AP_HAL/AP_HAL.h>

/**
 * Umbrella header for AP_HAL_IMX6S module.
 * The module header exports singleton instances which must conform the
 * AP_HAL::HAL interface. It may only expose implementation details (class
 * names, headers) via the IMX6S namespace.
 * The class implementing AP_HAL::HAL should be called HAL_IMX6S and exist
 * in the global namespace. There should be a single const instance of the
 * HAL_IMX6S class called AP_HAL_IMX6S, instantiated in the HAL_IMX6S_Class.cpp
 * and exported as `extern const HAL_IMX6S AP_HAL_IMX6S;` in HAL_IMX6S_Class.h
 *
 * All declaration and compilation should be guarded by CONFIG_HAL_BOARD macros.
 * In this case, we're using CONFIG_HAL_BOARD == HAL_BOARD_IMX6S.
 * When creating a new HAL, declare a new HAL_BOARD_ in AP_HAL/AP_HAL_Boards.h
 */

#include "HAL_IMX6S_Class.h"

#endif //__AP_HAL_IMX6S_H__

