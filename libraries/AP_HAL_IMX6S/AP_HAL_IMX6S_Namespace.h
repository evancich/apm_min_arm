
#ifndef __AP_HAL_IMX6S_NAMESPACE_H__
#define __AP_HAL_IMX6S_NAMESPACE_H__

/* While not strictly required, names inside the IMX6S namespace are prefixed
 * with IMX6S for clarity. (Some of our users aren't familiar with all of the
 * C++ namespace rules.)
 */

namespace IMX6S {
    class IMX6SUARTDriver;
    class IMX6SI2CDriver;
    class IMX6SSPIDeviceManager;
    class IMX6SSPIDeviceDriver;
    class IMX6SAnalogSource;
    class IMX6SAnalogIn;
    class IMX6SStorage;
    class IMX6SGPIO;
    class IMX6SDigitalSource;
    class IMX6SRCInput;
    class IMX6SRCOutput;
    class IMX6SSemaphore;
    class IMX6SScheduler;
    class IMX6SUtil;
    class IMX6SPrivateMember;
}

#endif // __AP_HAL_IMX6S_NAMESPACE_H__

