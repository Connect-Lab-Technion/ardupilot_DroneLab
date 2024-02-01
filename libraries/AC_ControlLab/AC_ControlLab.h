#pragma once

/// @file    AC_ControlLab.h
/// @brief   Technion Control Lab library for simulink wrapper

#include <AP_HAL/AP_HAL.h>
#include <AP_Math/AP_Math.h>
#include <AP_InertialNav/AP_InertialNav.h>
#include <AP_InertialSensor/AP_InertialSensor.h> 
#include <AC_Simulink/dmitry_model.h>
#include <array>
#include <AP_Motors/AP_Motors.h>
#include <AP_AHRS/AP_AHRS_View.h>


class AC_ControlLab {
public:
    AC_ControlLab(AP_AHRS_View& ahrs, const AP_InertialNav& inav,
                  const class AP_Motors& motors) :
        _ahrs(ahrs),
        _inav(inav),
        _motors(motors)
        {
            _controller.initialize();
        }


protected:
    // references to inertial nav and ahrs libraries

    AP_AHRS_View&           _ahrs;
    const AP_InertialNav&   _inav;
    const class AP_Motors&  _motors;
    static dmitry_model _controller;
private:

};