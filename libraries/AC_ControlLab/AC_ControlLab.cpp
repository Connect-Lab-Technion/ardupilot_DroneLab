#include "AC_ControlLab.h"

// AC_AttitudeControl *AC_AttitudeControl::_singleton;


// // table of user settable parameters
// const AP_Param::GroupInfo AC_ControlLab::var_info[] = {
//     // @Param: _TYPE
//     // @DisplayName: Custom control type
//     // @Description: Custom control type to be used
//     // @Values: 0:None, 1:Empty, 2:PID
//     // @RebootRequired: True
//     // @User: Advanced
//     AP_GROUPINFO_FLAGS("_TYPE", 1, AC_ControlLab, _controller_type, 0, AP_PARAM_FLAG_ENABLE),

//     // parameters for empty controller. only used as a template, no need for param table 
//     AP_SUBGROUPVARPTR(_backend, "1_", 6, AC_ControlLab, _backend_var_info[0]),

//     // parameters for PID controller
//     AP_SUBGROUPVARPTR(_backend, "2_", 7, AC_ControlLab, _backend_var_info[1]),

//     // parameters for Simulink controller
//     AP_SUBGROUPVARPTR(_backend, "3_", 8, AC_ControlLab, _backend_var_info[2]),

//     AP_GROUPEND
// };

// const struct AP_Param::GroupInfo *AC_ControlLab::_backend_var_info[CUSTOMCONTROL_MAX_TYPES];

AC_ControlLab::AC_ControlLab(AP_AHRS_View*& ahrs, 
            AP_InertialNav & inav,
            AP_InertialSensor &ins,
            AP_MotorsMulticopter *& motors) :
    _ahrs(ahrs),
    _inav(inav),
    _ins(ins),
    _motors(motors)
{
    // AP_Param::setup_object_defaults(this, var_info);
}

void AC_ControlLab::init(void)
{
    controller.initialize(); 
    GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AC_ControlLab: INIT");

}

void AC_ControlLab::update(void)
{
    // reset controller based on spool state
    switch (_motors->get_spool_state()) {
        case AP_Motors::SpoolState::SHUT_DOWN:
        case AP_Motors::SpoolState::GROUND_IDLE:
            break;

        case AP_Motors::SpoolState::THROTTLE_UNLIMITED:
        case AP_Motors::SpoolState::SPOOLING_UP:
        case AP_Motors::SpoolState::SPOOLING_DOWN:
            // we are off the ground
            break;
    }
}

std::array<float, 4> AC_ControlLab::controlWrapper() 
{
    // Get accel and gyro data
    Vector3f accel = _ins.get_accel();
    Vector3f gyro = _ins.get_gyro();

    // Get position and velocity estimates
    const Vector3f &curr_pos = _inav.get_position_neu_cm();  // TODO: convert to meters
    const Vector3f &curr_vel = _inav.get_velocity_neu_cms(); // TODO: convert to meters per second

    // // Get RC inputs
    // RC_Channel *rc6 = RC_Channels::rc_channel(5); // Channels are 0-indexed, so channel 6 is at index 5
    // RC_Channel *rc7 = RC_Channels::rc_channel(6);
    // RC_Channel *rc8 = RC_Channels::rc_channel(7);
    // RC_Channel *rc9 = RC_Channels::rc_channel(8);

    // Get battery voltage
    // float battery_voltage = AP::battery().voltage();

    /////////////////////////////////
    // '<Root>/accel'
    float arg_accel[3]{ accel.x, accel.y, accel.z };

    // '<Root>/gyro'
    float arg_gyro[3]{ gyro.x, gyro.y, gyro.z };

    // '<Root>/bat_V'
    float arg_bat_V{  0.0F  };

    // '<Root>/pos_est'
    float arg_pos_est[3]{ curr_pos.x, curr_pos.y, curr_pos.z };

    // '<Root>/vel_est'
    float arg_vel_est[3]{ curr_vel.x, curr_vel.y, curr_vel.z };

    // '<Root>/yaw_opticalfow'
    float arg_yaw_opticalfow{ 0.0F };

    // '<Root>/pos_ref'
    float arg_pos_ref[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/orient_ref'
    float arg_orient_ref[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/motors_refout'
    float arg_Out1[4];
    
    // Step the model
    controller.step(arg_accel, arg_gyro, &arg_bat_V, arg_pos_est,
                        arg_vel_est, &arg_yaw_opticalfow, arg_pos_ref,
                        arg_orient_ref, arg_Out1);
    
    std::array<float, 4> result{ arg_Out1[0], arg_Out1[1], arg_Out1[2], arg_Out1[3]};
    return result;
    
};
