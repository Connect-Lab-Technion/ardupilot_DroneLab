#include "AC_ControlLab.h"

AC_AttitudeControl *AC_AttitudeControl::_singleton;


std::array<float, 4> AC_ControlLab::controlWrapper() 
{
    // Get accel and gyro data
    Vector3f accel = _ins.get_accel();
    Vector3f gyro = _ins.get_gyro();

    // Get position and velocity estimates
    const Vector3f &curr_pos = _inav.get_position_neu_cm(); 
    const Vector3f &curr_vel = _inav.get_velocity_neu_cms(); 

    // // Get RC inputs
    RC_Channel *rc6 = RC_Channels::rc_channel(5); // Channels are 0-indexed, so channel 6 is at index 5
    RC_Channel *rc7 = RC_Channels::rc_channel(6);
    RC_Channel *rc8 = RC_Channels::rc_channel(7);
    RC_Channel *rc9 = RC_Channels::rc_channel(8);

    // Get battery voltage
    // float battery_voltage = AP::battery().voltage();

    /////////////////////////////////
    // '<Root>/accel'
    static float arg_accel[3]{ accel.x, accel.y, accel.z };

    // '<Root>/gyro'
    static float arg_gyro[3]{ gyro.x, gyro.y, gyro.z };

    // '<Root>/bat_V'
    static float arg_bat_V{ battery_voltage };

    // '<Root>/pos_est'
    static float arg_pos_est[3]{ curr_pos.x, curr_pos.y, curr_pos.z };

    // '<Root>/vel_est'
    static float arg_vel_est[3]{ curr_vel.x, curr_vel.y, curr_vel.z };

    // '<Root>/yaw_opticalfow'
    static float arg_yaw_opticalfow{ 0.0F };

    // '<Root>/pos_ref'
    static float arg_pos_ref[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/orient_ref'
    static float arg_orient_ref[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/motors_refout'
    static float arg_Out1[4];
    
    // Step the model
    controller.step(arg_accel, arg_gyro, &arg_bat_V, arg_pos_est,
                        arg_vel_est, &arg_yaw_opticalfow, arg_pos_ref,
                        arg_orient_ref, arg_Out1);
    
    std::array<float, 4> result{ arg_Out1[0], arg_Out1[1], arg_Out1[2], arg_Out1[3]};
    return result;
    
};
