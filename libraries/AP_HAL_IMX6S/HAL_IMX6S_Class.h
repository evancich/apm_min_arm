
#ifndef __AP_HAL_IMX6S_CLASS_H__
#define __AP_HAL_IMX6S_CLASS_H__

#include <AP_HAL/AP_HAL.h>

#include "AP_HAL_IMX6S_Namespace.h"
#include "PrivateMember.h"

class HAL_IMX6S : public AP_HAL::HAL {
public:
    HAL_IMX6S();
    void run(int argc, char* const* argv, Callbacks* callbacks) const override;
private:
    IMX6S::IMX6SPrivateMember *_member;
};

extern const HAL_IMX6S AP_HAL_IMX6S;

#endif // __AP_HAL_IMX6S_CLASS_H__

