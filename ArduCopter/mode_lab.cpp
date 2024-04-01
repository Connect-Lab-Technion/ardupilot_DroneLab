#include "Copter.h"
#include <AC_Simulink/FCS_model.h>  
FCS_model labController;
#include <array>
#include <SRV_Channel/SRV_Channel.h>
#include <AP_Common/AP_Common.h>


#if MODE_LAB_ENABLED == ENABLED

/*
 * Init and run calls for lab flight mode
 */

// lab_init - initialise lab controller
bool ModeLab::init(bool ignore_checks)
{
    // initialise the lab controller
    labController.initialize();

    // arm motors
    arm_motors();

    // turn on notify leds
    AP_Notify::flags.esc_calibration = true;
    
    // set the initial motor out values
    motor_out_1         = 0.0f;
    motor_out_2         = 0.0f;
    motor_out_3         = 0.0f;
    motor_out_4         = 0.0f;
    
    // set the initial reference values - to be updated by the dashboard
    master_switch       = 0;
    ref_power_gain      = 0.0f;
    ref_pos_x           = 0.0f;
    ref_pos_y           = 0.0f;
    ref_pos_z           = 0.0f;
    ref_orient_yaw      = 0.0f;
    ref_orient_pitch    = 0.0f;
    ref_orient_roll     = 0.0f; 

    gcs().send_text(MAV_SEVERITY_INFO, "LAB: intitialised");
    return true;
}

// lab_run - runs the lab controller
// should be called at 100hz or more
void ModeLab::run()
{
    // std::ostringstream oss;
    // gcs().send_text(MAV_SEVERITY_INFO, "GYRO:: %f,%f,%f", gyro_vals.x,gyro_vals.y,gyro_vals.z);

    // TODO: This has been causing the mode to bounce between lab and stabilize for the first few seconds
    // // check if we have received a message from the dashboard in the last second, otherwise exit
    // uint32_t now = AP_HAL::millis();
    // if (now - last_dashboard_msg_ms > 1000) {
    //     // exit mode if we haven't received a message from the dashboard in the last second
    //     gcs().send_text(MAV_SEVERITY_WARNING, "LAB: no message from dashboard");
    //     exit();
    //     // switch back to the default mode 
    //     set_mode(Mode::Number::STABILIZE, ModeReason::GCS_COMMAND);
    // }


    // '<Root>/accel' -------------------------------------
    Vector3f accel_vals = ahrs.get_accel();
    float arg_accel[3]{ accel_vals.x, accel_vals.y, accel_vals.z };

    // '<Root>/gyro' --------------------------------------
    Vector3f gyro_vals = ahrs.get_gyro();
    float arg_gyro[3]{ gyro_vals.x, gyro_vals.y, gyro_vals.z };

    // '<Root>/bat_V' -------------------------------------
    float arg_bat_V{ 0.0F };

    // '<Root>/pos_est' -----------------------------------
    Vector3f position;
    float arg_pos_est[3];
    if (ahrs.get_relative_position_NED_home(position)) {
        arg_pos_est[0] = position.x;
        arg_pos_est[1] = position.y;
        arg_pos_est[2] = position.z;
    } else {
        // This should instead return the previous value
        // Assign the previous values to arg_pos_est
        arg_pos_est[0] = 0.0F;
        arg_pos_est[1] = 0.0F;
        arg_pos_est[2] = 0.0F;
    }

    // '<Root>/vel_est' -----------------------------------
    Vector3f velocity;
    float arg_vel_est[3];
    if (ahrs.get_velocity_NED(velocity)) {
        arg_vel_est[0] = velocity.x;
        arg_vel_est[1] = velocity.y;
        arg_vel_est[2] = velocity.z;
    } else {
        // This should instead return the previous value
        // Assign the previous values to arg_vel_est
        arg_vel_est[0] = 0.0F;
        arg_vel_est[1] = 0.0F;
        arg_vel_est[2] = 0.0F;
    }

    // '<Root>/yaw_opticalfow' ----------------------------
    // const AP_OpticalFlow *optflow = AP::opticalflow();
    const Vector2f &flowRate = Vector2f(0.0F, 0.0F); //optflow->flowRate();
    float arg_yaw_opticalfow{ atan2f(flowRate.y, flowRate.x) };

    // '<Root>/pos_ref' -----------------------------------
    float arg_pos_ref[3]{ 0.0F, 0.0F, 0.0F };

    // '<Root>/orient_ref' --------------------------------
    float arg_orient_ref[3]{ 0.0F, 0.0F, 0.0F };

    // Return variables from the controller ---------------
    // '<Root>/motors_refout' 
    float motors_out[4];

    // '<Root>/logging_refout' 
    float logging_out[10];

    labController.step(arg_accel, arg_gyro, &arg_bat_V, arg_pos_est, arg_vel_est,
        &arg_yaw_opticalfow, arg_pos_ref, arg_orient_ref, motors_out, logging_out);

    // update the motor output, if the master switch is off, set all motors to 0
    // otherwise set the motors to the output from the controller times the power gain
    if (master_switch == 0) {
        motor_out_1 = 0.0F;
        motor_out_2 = 0.0F;
        motor_out_3 = 0.0F;
        motor_out_4 = 0.0F;
    }
    else if (master_switch == 1) {  
        if (ref_power_gain > 1.0f || ref_power_gain < 0.0f) {
            ref_power_gain = 0.0f;
            gcs().send_text(MAV_SEVERITY_WARNING, "LAB: power gain out of (0-1) range: %f", ref_power_gain);
        }  
        motor_out_1 = motors_out[0] * ref_power_gain;
        motor_out_2 = motors_out[1] * ref_power_gain;
        motor_out_3 = motors_out[2] * ref_power_gain;
        motor_out_4 = motors_out[3] * ref_power_gain;
    }

    // send logging data to the dashboard
    mavlink_channel_t chan = MAVLINK_COMM_0;
    mavlink_msg_lab_to_dashboard_send(chan, logging_out);
    gcs().send_message(MSG_LAB_TO_DASHBOARD);
}


void ModeLab::exit()
{
    disarm_motors();

    // turn off notify leds
    AP_Notify::flags.esc_calibration = false;
}

void ModeLab::disarm_motors()
{
    if (!hal.util->get_soft_armed()) {
        return;
    }

    // disarm
    motors->armed(false);
    hal.util->set_soft_armed(false);

    // un-reverse the motors
    change_motor_direction(false);
    hal.rcout->enable_channel_mask_updates();

    // re-enable failsafes
    g.failsafe_throttle.load();
    g.failsafe_gcs.load();
    g.fs_ekf_action.load();
}

void ModeLab::change_motor_direction(bool reverse)
{
    AP_HAL::RCOutput::BLHeliDshotCommand direction = reverse ? AP_HAL::RCOutput::DSHOT_REVERSE : AP_HAL::RCOutput::DSHOT_NORMAL;
    AP_HAL::RCOutput::BLHeliDshotCommand inverse_direction = reverse ? AP_HAL::RCOutput::DSHOT_NORMAL : AP_HAL::RCOutput::DSHOT_REVERSE;

    if (!hal.rcout->get_reversed_mask()) {
        hal.rcout->send_dshot_command(direction, AP_HAL::RCOutput::ALL_CHANNELS, 0, 10, true);
    } else {
        for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; ++i) {
            if (!motors->is_motor_enabled(i)) {
                continue;
            }

            if ((hal.rcout->get_reversed_mask() & (1U << i)) == 0) {
                hal.rcout->send_dshot_command(direction, i, 0, 10, true);
            } else {
                hal.rcout->send_dshot_command(inverse_direction, i, 0, 10, true);
            }
        }
    }
}

void ModeLab::arm_motors()
{
    if (hal.util->get_soft_armed()) {
        return;
    }

    // stop the spoolup block activating
    motors->set_spoolup_block(false);

    // reverse the motors
    hal.rcout->disable_channel_mask_updates();
    change_motor_direction(true);

    // disable throttle and gps failsafe
    g.failsafe_throttle.set(FS_THR_DISABLED);
    g.failsafe_gcs.set(FS_GCS_DISABLED);
    g.fs_ekf_action.set(0);

    // arm
    motors->armed(true);
    hal.util->set_soft_armed(true);
}


// actually write values to the motors
void ModeLab::output_to_motors()
{

    // check if motor are allowed to spin
    const bool allow_output = motors->armed() && motors->get_interlock();
    if (allow_output) {
        
        float motor_outputs[] = {motor_out_1, motor_out_2, motor_out_3, motor_out_4};
        gcs().send_text(MAV_SEVERITY_INFO, "PWM:: %f,%f,%f,%f", motor_out_1, motor_out_2, motor_out_3, motor_out_4);

        // convert output to PWM and send to each motor
        int8_t i;   
        for (i = 0; i <= 3; i++) {
            if (motors->is_motor_enabled(i)) {
                motors->rc_write(i, motor_outputs[i]);
            }
        }
    }
}


// handle a mavlink message coming in from the dashboard 
void ModeLab::handle_message(const mavlink_message_t &msg)
{
    // keep track of the last time we received a message from the dashboard
    last_dashboard_msg_ms = AP_HAL::millis();

    if (msg.msgid != MAVLINK_MSG_ID_LAB_FROM_DASHBOARD) {
        return;
    }
    mavlink_lab_from_dashboard_t m;
    mavlink_msg_lab_from_dashboard_decode(&msg, &m);

    master_switch       = m.master_switch;
    ref_pos_x           = m.ref_x;
    ref_pos_y           = m.ref_y;
    ref_pos_z           = m.ref_z;
    ref_orient_yaw      = m.ref_yaw;
    ref_orient_pitch    = m.ref_pitch;
    ref_orient_roll     = m.ref_roll; 
    ref_power_gain      = m.power;

}

#endif
