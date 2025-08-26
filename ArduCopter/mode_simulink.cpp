#include "Copter.h"
#include <AC_Simulink/FCS_model.h>
#include <AC_Simulink/FCS_model_types.h> // Make sure this is included
FCS_model labController;
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
    ref_time_world      = 0.0f;
    ref_master_switch   = 0;
    ref_power_gain      = 0.0f;
    ref_pos_x           = 0.0f;
    ref_pos_y           = 0.0f;
    ref_pos_z           = 0.0f;
    ref_orient_yaw      = 0.0f;
    ref_orient_pitch    = 0.0f;
    ref_orient_roll     = 0.0f; 

    // Initialize stored structures
    memset(&mavlink_data, 0, sizeof(mavlink_data));

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

    ////////////////////////////////////////////////////////
    // Prepare the arguments for the controller, given by the generated ert_main ------------

    Vector3f accel_vals = ahrs.get_accel();

    Vector3f gyro_vals = ahrs.get_gyro();
    
    Vector2f optFlow_Rate = copter.optflow.flowRate();
    
    float current = 0.0f;

    // ESC telemetry data, rpm 
    float gather_rpm[4];
    for (int i = 0; i < 4; i++) {
        float rpm;
        if (copter.esc_telem.get_rpm(i, rpm)) {
            // gcs().send_text(MAV_SEVERITY_INFO, "SIMULINK: ESC %i RPM: %f", i, rpm);
            gather_rpm[i] = rpm;
        } else {
            gather_rpm[i] = 0.0f;
        }
    }
    float arg_rpm[4]{ gather_rpm[0], gather_rpm[1], gather_rpm[2], gather_rpm[3] };
    
    // Vector3f position;
    // float arg_pos_est[3];
    // if (ahrs.get_relative_position_NED_origin(position)) {        
    //     arg_pos_est[0] = position.x;
    //     arg_pos_est[1] = position.y;
    //     arg_pos_est[2] = position.z;
    // } else {
    //     // This should instead return the previous value
    //     // Assign the previous values to arg_pos_est
    //     arg_pos_est[0] = 0.0F;
    //     arg_pos_est[1] = 0.0F;
    //     arg_pos_est[2] = 0.0F;
    // }

    // Vector3f velocity;
    // float arg_vel_est[3];
    // if (ahrs.get_velocity_NED(velocity)) {
    //     arg_vel_est[0] = velocity.x;
    //     arg_vel_est[1] = velocity.y;
    //     arg_vel_est[2] = velocity.z;
    // } else {
    //     // This should instead return the previous value
    //     // Assign the previous values to arg_vel_est
    //     arg_vel_est[0] = 0.0F;
    //     arg_vel_est[1] = 0.0F;
    //     arg_vel_est[2] = 0.0F;
    // }
    
    //////////////////////////////////////////////////////// 
    // Prepare input structures for the new step function interface 
    in_dashboard dashboard_data = {};
    dashboard_data.time_world       = (real_T)ref_time_world;
    dashboard_data.master_switch    = (boolean_T)ref_master_switch;
    dashboard_data.power            = (real_T)ref_power_gain;
    dashboard_data.ref_x            = (real_T)ref_pos_x;
    dashboard_data.ref_y            = (real_T)ref_pos_y;
    dashboard_data.ref_z            = (real_T)ref_pos_z;
    dashboard_data.ref_yaw          = (real_T)ref_orient_yaw;
    dashboard_data.ref_pitch        = (real_T)ref_orient_pitch;
    dashboard_data.ref_roll         = (real_T)ref_orient_roll;

    in_parameters parameter_data = {};
    parameter_data.accelerometer_x  = (real_T)accel_vals.x;
    parameter_data.accelerometer_y  = (real_T)accel_vals.y;
    parameter_data.accelerometer_z  = (real_T)accel_vals.z;
    parameter_data.gyroscope_x      = (real_T)gyro_vals.x;
    parameter_data.gyroscope_y      = (real_T)gyro_vals.y;
    parameter_data.gyroscope_z      = (real_T)gyro_vals.z;
    parameter_data.opticalflow_x    = (real_T)optFlow_Rate.x;
    parameter_data.opticalflow_y    = (real_T)optFlow_Rate.y;
    parameter_data.barometer_pressure       = (real_T)copter.barometer.get_pressure();
    parameter_data.rangefinder_distance     = (real_T)copter.rangefinder_state.alt_cm;
    parameter_data.rpm_1            = (real_T)arg_rpm[0];
    parameter_data.rpm_2            = (real_T)arg_rpm[1];
    parameter_data.rpm_3            = (real_T)arg_rpm[2];
    parameter_data.rpm_4            = (real_T)arg_rpm[3];
    parameter_data.battery_voltage  = (real_T)copter.battery.voltage();
    parameter_data.battery_current  = (real_T)(copter.battery.current_amps(current) ? current : 0.0F);
    parameter_data.yaw              =  (real_T)ahrs.yaw;

    // Output structures
    out_controllers controller_outputs = {};
    out_estimators estimator_outputs = {};
    out_sensors sensor_outputs = {};
    
    // Step the model with new structure interface
    labController.step(&dashboard_data, &parameter_data, 
                      &controller_outputs, &estimator_outputs, &sensor_outputs);
    

    // PWM output is between 1000 and 2000 (0% - 100%) 
    motor_out_1 = (float)controller_outputs.motor1 * 1000 + 1000;
    motor_out_2 = (float)controller_outputs.motor2 * 1000 + 1000;
    motor_out_3 = (float)controller_outputs.motor3 * 1000 + 1000;
    motor_out_4 = (float)controller_outputs.motor4 * 1000 + 1000;

    /////////////////////////////////////////////////////////
    // Create mavlink structure and populate from stored Simulink structures 
    // Lock mutex before accessing shared data
    {
        WITH_SEMAPHORE(mavlink_data_mutex);
        
        // Dashboard inputs 
        mavlink_data.in_dashboard_time_world = (float)dashboard_data.time_world;
        mavlink_data.in_dashboard_master_switch = (float)dashboard_data.master_switch;
        mavlink_data.in_dashboard_power = (float)dashboard_data.power;    
        mavlink_data.in_dashboard_ref_x = (float)dashboard_data.ref_x;
        mavlink_data.in_dashboard_ref_y = (float)dashboard_data.ref_y;
        mavlink_data.in_dashboard_ref_z = (float)dashboard_data.ref_z;
        mavlink_data.in_dashboard_ref_yaw = (float)dashboard_data.ref_yaw;
        mavlink_data.in_dashboard_ref_pitch = (float)dashboard_data.ref_pitch;
        mavlink_data.in_dashboard_ref_roll = (float)dashboard_data.ref_roll;
        
        // Parameter inputs 
        mavlink_data.in_parameters_accelerometer_x = (float)parameter_data.accelerometer_x;
        mavlink_data.in_parameters_accelerometer_y = (float)parameter_data.accelerometer_y;
        mavlink_data.in_parameters_accelerometer_z = (float)parameter_data.accelerometer_z;
        mavlink_data.in_parameters_gyroscope_x = (float)parameter_data.gyroscope_x;
        mavlink_data.in_parameters_gyroscope_y = (float)parameter_data.gyroscope_y;
        mavlink_data.in_parameters_gyroscope_z = (float)parameter_data.gyroscope_z;
        mavlink_data.in_parameters_battery_voltage = (float)parameter_data.battery_voltage;
        mavlink_data.in_parameters_battery_current = (float)parameter_data.battery_current;
        mavlink_data.in_parameters_opticalflow_x = (float)parameter_data.opticalflow_x;
        mavlink_data.in_parameters_opticalflow_y = (float)parameter_data.opticalflow_y;
        mavlink_data.in_parameters_barometer_pressure = (float)parameter_data.barometer_pressure;
        mavlink_data.in_parameters_rangefinder_distance = (float)parameter_data.rangefinder_distance;
        mavlink_data.in_parameters_rpm_1 = (float)parameter_data.rpm_1;
        mavlink_data.in_parameters_rpm_2 = (float)parameter_data.rpm_2;
        mavlink_data.in_parameters_rpm_3 = (float)parameter_data.rpm_3;
        mavlink_data.in_parameters_rpm_4 = (float)parameter_data.rpm_4;
        mavlink_data.in_parameters_yaw = (float)parameter_data.yaw;
        
        // Estimator outputs 
        mavlink_data.out_estimators_orient_roll = (float)estimator_outputs.orient_roll;
        mavlink_data.out_estimators_orient_pitch = (float)estimator_outputs.orient_pitch;
        mavlink_data.out_estimators_orient_yaw = (float)estimator_outputs.orient_yaw;
        mavlink_data.out_estimators_orient_rate_roll = (float)estimator_outputs.orient_rate_roll;
        mavlink_data.out_estimators_orient_rate_pitch = (float)estimator_outputs.orient_rate_pitch;
        mavlink_data.out_estimators_orient_rate_yaw = (float)estimator_outputs.orient_rate_yaw;
        mavlink_data.out_estimators_pos_x = (float)estimator_outputs.pos_x;
        mavlink_data.out_estimators_pos_y = (float)estimator_outputs.pos_y;
        mavlink_data.out_estimators_pos_z = (float)estimator_outputs.pos_z;
        mavlink_data.out_estimators_pos_dx = (float)estimator_outputs.pos_dx;
        mavlink_data.out_estimators_pos_dy = (float)estimator_outputs.pos_dy;
        mavlink_data.out_estimators_pos_dz = (float)estimator_outputs.pos_dz;
        mavlink_data.out_estimators_battery_SOC = (float)estimator_outputs.battery_SOC;
        
        // Controller outputs 
        mavlink_data.out_controllers_motor1 = (float)controller_outputs.motor1;
        mavlink_data.out_controllers_motor2 = (float)controller_outputs.motor2;
        mavlink_data.out_controllers_motor3 = (float)controller_outputs.motor3;
        mavlink_data.out_controllers_motor4 = (float)controller_outputs.motor4;
        mavlink_data.out_controllers_cmd_thrust = (float)controller_outputs.cmd_thrust;
        mavlink_data.out_controllers_cmd_tau_roll = (float)controller_outputs.cmd_tau_roll;
        mavlink_data.out_controllers_cmd_tau_pitch = (float)controller_outputs.cmd_tau_pitch;
        mavlink_data.out_controllers_cmd_tau_yaw = (float)controller_outputs.cmd_tau_yaw;
        mavlink_data.out_controllers_cmd_roll = (float)controller_outputs.cmd_roll;
        mavlink_data.out_controllers_cmd_pitch = (float)controller_outputs.cmd_pitch;
        mavlink_data.out_controllers_cmd_yaw = (float)controller_outputs.cmd_yaw;
        
        // Sensor outputs 
        mavlink_data.out_sensors_clock           = (float)sensor_outputs.clock;
        mavlink_data.out_sensors_accelerometer_x = (float)sensor_outputs.accelerometer_x;
        mavlink_data.out_sensors_accelerometer_y = (float)sensor_outputs.accelerometer_y;
        mavlink_data.out_sensors_accelerometer_z = (float)sensor_outputs.accelerometer_z;
        mavlink_data.out_sensors_gyroscope_x = (float)sensor_outputs.gyroscope_x;
        mavlink_data.out_sensors_gyroscope_y = (float)sensor_outputs.gyroscope_y;
        mavlink_data.out_sensors_gyroscope_z = (float)sensor_outputs.gyroscope_z;
        mavlink_data.out_sensors_barometer_pressure = (float)sensor_outputs.barometer_pressure;
        mavlink_data.out_sensors_rangefinder_distance = (float)sensor_outputs.rangefinder_distance;
    }
}

// send_modeSimulink_log
void ModeSimulink::send_drone_to_dashboard(uint8_t chan)
{
    // Create a local copy to avoid holding the mutex during the mavlink send
    mavlink_drone_to_dashboard_t local_mavlink_data;
    {
        WITH_SEMAPHORE(mavlink_data_mutex);
        local_mavlink_data = mavlink_data;
    }
    
    // Send the mavlink message using the local copy
    mavlink_msg_drone_to_dashboard_send_struct((mavlink_channel_t)chan, &local_mavlink_data);
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
    change_motor_direction(false);

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
    ref_time_world      = (float)m.time_world;        // Convert double to float
    ref_master_switch   = m.master_switch;
    ref_power_gain      = (float)m.power;             // Convert double to float
    ref_pos_x           = (float)m.ref_x;             // Convert double to float
    ref_pos_y           = (float)m.ref_y;             // Convert double to float
    ref_pos_z           = (float)m.ref_z;             // Convert double to float
    ref_orient_yaw      = (float)m.ref_yaw;           // Convert double to float
    ref_orient_pitch    = (float)m.ref_pitch;         // Convert double to float
    ref_orient_roll     = (float)m.ref_roll;          // Convert double to float 

}

#endif