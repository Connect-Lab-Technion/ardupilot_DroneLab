#include "AC_CustomControl_Simulink.h"

#if CUSTOMCONTROL_Simulink_ENABLED

#include <GCS_MAVLink/GCS.h>

// table of user settable parameters
const AP_Param::GroupInfo AC_CustomControl_Simulink::var_info[] = {
    // @Param: PARAM1
    // @DisplayName: Empty param1
    // @Description: Dummy parameter for empty custom controller backend
    // @User: Advanced
    AP_GROUPINFO("PARAM1", 1, AC_CustomControl_Simulink, param1, 0.0f),

    // @Param: PARAM2
    // @DisplayName: Empty param2
    // @Description: Dummy parameter for empty custom controller backend
    // @User: Advanced
    AP_GROUPINFO("PARAM2", 2, AC_CustomControl_Simulink, param2, 0.0f),

    // @Param: PARAM3
    // @DisplayName: Empty param3
    // @Description: Dummy parameter for empty custom controller backend
    // @User: Advanced
    AP_GROUPINFO("PARAM3", 3, AC_CustomControl_Simulink, param3, 0.0f),

    AP_GROUPEND
};

// initialize in the constructor
AC_CustomControl_Simulink::AC_CustomControl_Simulink(AC_CustomControl& frontend, AP_AHRS_View*& ahrs, AC_AttitudeControl_Multi*& att_control, AP_MotorsMulticopter*& motors, float dt) :
    AC_CustomControl_Backend(frontend, ahrs, att_control, motors, dt)
{
    AP_Param::setup_object_defaults(this, var_info);

    simulink_controller.initialize();
}

// update controller
// return roll, pitch, yaw controller output
Vector3f AC_CustomControl_Simulink::update(void)
{
    // reset controller based on spool state
    switch (_motors->get_spool_state()) {
        case AP_Motors::SpoolState::SHUT_DOWN:
        case AP_Motors::SpoolState::GROUND_IDLE:
            // We are still at the ground. Reset custom controller to avoid
            // build up, ex: integrator
            reset();
            break;

        case AP_Motors::SpoolState::THROTTLE_UNLIMITED:
        case AP_Motors::SpoolState::SPOOLING_UP:
        case AP_Motors::SpoolState::SPOOLING_DOWN:
            // we are off the ground
            break;
    }

    // *** run custom controller after here ***


    // Here are the reference calls for each input 

    // '<Root>/accel'
    // Vector3f accel_ef = _ahrs.get_accel_ef();
    AP_InertialSensor &_ins = AP::ins(); 
    Vector3f accVec = _ins.get_accel(); 

    // '<Root>/gyro'

    // '<Root>/bat_V'

    // '<Root>/pos_est'

    // '<Root>/vel_est'

    // '<Root>/yaw_opticalfow'

    // '<Root>/pos_ref'

    // '<Root>/orient_ref'


    // Below is the integration between reference calls and the simulink code.
    // '<Root>/accel'
    float arg_accel[3]{ accVec.x, accVec.y, accVec.z };

    // '<Root>/gyro'
    float arg_gyro[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/bat_V'
    float arg_bat_V{ 0.0F };

    // '<Root>/pos_est'
    float arg_pos_est[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/vel_est'
    float arg_vel_est[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/yaw_opticalfow'
    float arg_yaw_opticalfow{ 0.0F };

    // '<Root>/pos_ref'
    float arg_pos_ref[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/orient_ref'
    float arg_orient_ref[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/torque_ref'
    float arg_torque_ref[3];


    simulink_controller.step(arg_accel, arg_gyro, &arg_bat_V, arg_pos_est,
        arg_vel_est, &arg_yaw_opticalfow, arg_pos_ref, arg_orient_ref,
        arg_torque_ref);

    // return what arducopter main controller outputted
    return Vector3f(arg_torque_ref[0], arg_torque_ref[1], arg_torque_ref[2]);
}

// reset controller to avoid build up on the ground
// or to provide bumpless transfer from arducopter main controller
void AC_CustomControl_Simulink::reset(void)
{
}

#endif
