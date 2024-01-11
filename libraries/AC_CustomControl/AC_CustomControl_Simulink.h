#pragma once

#include "AC_CustomControl_Backend.h"
#include <AC_Simulink/dmitry_model.h>

#ifndef CUSTOMCONTROL_Simulink_ENABLED
    #define CUSTOMCONTROL_Simulink_ENABLED AP_CUSTOMCONTROL_ENABLED
#endif

#if CUSTOMCONTROL_Simulink_ENABLED

class AC_CustomControl_Simulink : public AC_CustomControl_Backend {
public:
    AC_CustomControl_Simulink(AC_CustomControl& frontend, AP_AHRS_View*& ahrs, AC_AttitudeControl_Multi*& att_control, AP_MotorsMulticopter*& motors, float dt);


    Vector3f update(void) override;
    void reset(void) override;

    dmitry_model simulink_controller;

    // user settable parameters
    static const struct AP_Param::GroupInfo var_info[];

protected:
    // declare parameters here
    AP_Float param1;
    AP_Float param2;
    AP_Float param3;
};

#endif
