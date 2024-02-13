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
    AC_ControlLab(
        AP_AHRS_View*& ahrs, 
        AP_InertialNav & inav,
        AP_InertialSensor &ins,
        AP_MotorsMulticopter *& motors);
    // AC_ControlLab() = default;
    std::array<float, 4> controlWrapper();
     
    // Empty destructor to suppress compiler warning
    virtual ~AC_ControlLab() {}

    CLASS_NO_COPY(AC_ControlLab);  /* Do not allow copies */

    void init(void);
    void update(void);

    static const struct AP_Param::GroupInfo var_info[];




protected:
    AP_AHRS_View*&           _ahrs;
    AP_InertialNav &   _inav;
    AP_InertialSensor & _ins;
    AP_MotorsMulticopter *&  _motors;
    dmitry_model controller;
private:
    // AP_Enum<CustomControlType> _controller_type;

};