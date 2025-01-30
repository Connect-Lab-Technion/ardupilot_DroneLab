#include "Copter.h"
#include <AC_Simulink/FCS_model.h>  
FCS_model labController;
#include <array>
#include <SRV_Channel/SRV_Channel.h>
#include <AP_Common/AP_Common.h>


#if MODE_SIMULINK_ENABLED == ENABLED

/*
 * Init and run calls for simulink flight mode
 */

// simulink_init - initialise lab controller
bool ModeSimulink::init(bool ignore_checks)
{
    // initialise the lab controller
    labController.initialize();

    // arm motors
    arm_motors();

    // Start timers 
    start_time = AP_HAL::millis();
    last_dashboard_msg_ms = AP_HAL::millis();
    last_drone_msg_ms = AP_HAL::millis();

    // // set the home for the ahrs TODO: returns zeros 
    // copter.set_home_to_current_location_inflight();

    // turn on notify leds
    AP_Notify::flags.esc_calibration = true;
    
    // set the initial motor out values
    motor_out_1         = 0.0f;
    motor_out_2         = 0.0f;
    motor_out_3         = 0.0f;
    motor_out_4         = 0.0f;
    
    // set the initial reference values 
    ref_master_switch   = 0;
    ref_power_gain      = 0.0f;
    ref_pos_x           = 0.0f;
    ref_pos_y           = 0.0f;
    ref_pos_z           = 0.0f;
    ref_orient_yaw      = 0.0f;
    ref_orient_pitch    = 0.0f;
    ref_orient_roll     = 0.0f; 

    gcs().send_text(MAV_SEVERITY_INFO, "SIMULINK: intitialised");
    return true;
}

void ModeSimulink::check_if_received_message_from_dashboard(float threshold_ms)
{
    uint32_t dashboard_msg_time = AP_HAL::millis() - last_dashboard_msg_ms;
    if (dashboard_msg_time > threshold_ms) {
        // Send a warning message to the GCS
        gcs().send_text(MAV_SEVERITY_WARNING, "SIMULINK: no message from dashboard in: %f ms" , double(dashboard_msg_time));
        // Run internal exit function
        exit();
        // Switch back to the default mode 
        set_mode(Mode::Number::STABILIZE, ModeReason::GCS_COMMAND);
    }
}

// simulink_run - runs the simulink controller
// is called at 400Hz for most flight controllers. Always greater than 100Hz
void ModeSimulink::run()
{
    // check if we have received a message from the dashboard within a given time, otherwise exit
    check_if_received_message_from_dashboard(2000); // 2 seconds

    // Prepare the arguments for the controller, given by the generated ert_main ------------

    // '<Root>/master_switch'
    u_int8_t arg_switch{ ref_master_switch };

    // '<Root>/power gain'
    float arg_gain{ ref_power_gain };

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
    if (ahrs.get_relative_position_NED_origin(position)) {        
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
    // float arg_yaw{ ahrs.get_yaw()}; // Drifts
    float arg_yaw{ (float)ahrs.yaw_sensor }; // Doesn't seem to drift. Don't know why

    // '<Root>/flowRate' --------------------------------
    
    // Get the optical flow sensor
    Vector2f optFlow_Rate = copter.optflow.flowRate();
    float arg_flowRate[2]{ optFlow_Rate.x, optFlow_Rate.y };
    
    // '<Root>/baro' ----------------------------
    float baro_altitude = copter.barometer.get_pressure();
    float arg_baro{ baro_altitude };

    // '<Root>/rangefinder' ----------------------------
    float rangefinder_distance = copter.rangefinder_state.alt_cm;
    float arg_rangefinder{ rangefinder_distance };

    // '<Root>/pos_ref' -----------------------------------
    float arg_pos_ref[3]{ ref_pos_x, ref_pos_y, ref_pos_z};

    // '<Root>/orient_ref' --------------------------------
    float arg_orient_ref[3]{ ref_orient_yaw, ref_orient_pitch, ref_orient_roll};

    // Return variables from the controller ---------------
    // '<Root>/motors_refout' 
    float arg_motors_refout[4];

    // '<Root>/logging_refout' !! The array size is modified during the build process. See also common.xml !!
    float arg_logging_refout[40];

    // Step the model
    labController.step(&arg_switch, &arg_gain, arg_accel, arg_gyro, &arg_bat_V,
                     arg_flowRate, &arg_baro, &arg_rangefinder, arg_pos_est,
                     arg_vel_est, &arg_yaw, arg_pos_ref, arg_orient_ref,
                     arg_motors_refout, arg_logging_refout);

    // PWM output is between 1000 and 2000 (0% - 100%)
    motor_out_1 = arg_motors_refout[0] * 1000 + 1000;
    motor_out_2 = arg_motors_refout[1] * 1000 + 1000;
    motor_out_4 = arg_motors_refout[3] * 1000 + 1000;
    motor_out_3 = arg_motors_refout[2] * 1000 + 1000;

    // Mavlink message to the dashboard
    float rate_drone_to_dashboard = 400; // Hz
    uint32_t drone_msg_time = AP_HAL::millis() - last_drone_msg_ms;
    if (drone_msg_time > (1000 / rate_drone_to_dashboard)) {
        if (arg_logging_refout != nullptr) {
            uint8_t chan;
            for(chan = 0; chan < MAVLINK_COMM_NUM_BUFFERS; chan++){
                mavlink_msg_drone_to_dashboard_send((mavlink_channel_t)chan, arg_logging_refout);
                last_drone_msg_ms = AP_HAL::millis();
            }
        } else {
            gcs().send_text(MAV_SEVERITY_WARNING, "SIMULINK: logging data is null");
        }
    }
}


void ModeSimulink::exit()
{
    disarm_motors();

    // turn off notify leds
    AP_Notify::flags.esc_calibration = false;
}

void ModeSimulink::disarm_motors()
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

void ModeSimulink::change_motor_direction(bool reverse)
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

void ModeSimulink::arm_motors()
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
void ModeSimulink::output_to_motors()
{

    // check if motor are allowed to spin
    const bool allow_output = motors->armed() && motors->get_interlock();
    if (allow_output) {
        
        float motor_outputs[] = {motor_out_1, motor_out_2, motor_out_3, motor_out_4};

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
void ModeSimulink::handle_message(const mavlink_message_t &msg)
{
    // keep track of the last time we received a message from the dashboard
    last_dashboard_msg_ms = AP_HAL::millis();

    if (msg.msgid != MAVLINK_MSG_ID_DASHBOARD_TO_DRONE) {
        return;
    }
    mavlink_dashboard_to_drone_t m;
    mavlink_msg_dashboard_to_drone_decode(&msg, &m);

    ref_master_switch       = m.master_switch;
    ref_power_gain      = m.power;
    ref_pos_x           = m.ref_x;
    ref_pos_y           = m.ref_y;
    ref_pos_z           = m.ref_z;
    ref_orient_yaw      = m.ref_yaw;
    ref_orient_pitch    = m.ref_pitch;
    ref_orient_roll     = m.ref_roll; 

}

#endif