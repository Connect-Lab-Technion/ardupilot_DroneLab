# include "AC_Simulink.h"

AC_Simulink::AC_Simulink() {
    // _singleton = this;
}

AC_Simulink *AC_Simulink::_singleton; 

void AC_Simulink::inititalize() {

    // Initialize the Simulink controller
    simulinkModel.initialize();
    
    // Initialize the variables from the dashboard 
    master_switch   = 0;
    ref_power_gain  = 0.0f;
    ref_pos_x       = 0.0f;
    ref_pos_y       = 0.0f;
    ref_pos_z       = 0.0f;
    ref_orient_yaw  = 0.0f;
    ref_orient_pitch = 0.0f;
    ref_orient_roll  = 0.0f;

    // Initialize the time variables
    last_dashboard_msg_ms = AP_HAL::millis();
    start_time = AP_HAL::millis();
}

// Method to wrap the Simulink controller
void AC_Simulink::runController(float* arg_motors_refout) {
    // Prepare the arguments for the controller, given by the generated ert_main ------------

    // '<Root>/accel' -------------------------------------
    const AP_AHRS &ahrs = AP::ahrs();
    Vector3f accel_vals = ahrs.get_accel();
    float arg_accel[3]{ accel_vals.x, accel_vals.y, accel_vals.z };

    // '<Root>/gyro' --------------------------------------
    Vector3f gyro_vals = ahrs.get_gyro();
    float arg_gyro[3]{ gyro_vals.x, gyro_vals.y, gyro_vals.z };

    // '<Root>/bat_V' -------------------------------------
    AP_BattMonitor &battery = AP::battery(); 
    float arg_bat_V{ battery.voltage() };

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
    // const AP_OpticalFlow *optflow = AP::opticalflow();
    // const Vector2f &flowRate = optflow->flowRate();

    Vector2f flowRate = {0.0f, 0.0f};
    float arg_yaw_opticalfow{ atan2f(flowRate.y, flowRate.x) };

    // '<Root>/pos_ref' -----------------------------------
    float arg_pos_ref[3]{ ref_pos_x, ref_pos_y, ref_pos_z};

    // '<Root>/orient_ref' --------------------------------
    float arg_orient_ref[3]{ ref_orient_yaw, ref_orient_pitch, ref_orient_roll};

    // Return variables from the controller ---------------
    // '<Root>/motors_refout' 
    // float arg_motors_refout[4];

    // '<Root>/logging_refout' !! The array size is modified during the build process. See also common.xml !!
    // float arg_logging_refout[23];

    simulinkModel.step(arg_accel, arg_gyro, &arg_bat_V, arg_pos_est, arg_vel_est,
        &arg_yaw_opticalfow, arg_pos_ref, arg_orient_ref, arg_motors_refout, arg_logging_refout);
    
}

// TODO: change the build process to change this instead
static int lengthOfLogging_Simulink = 23;
static int lengthOfLogging_Internal = 1;
float* arg_logging_refout = new float[lengthOfLogging_Simulink];
float* logging_data = new float[lengthOfLogging_Internal + lengthOfLogging_Simulink];

// Method to get the logging data from the controller. Used for mavlink message
float* AC_Simulink::get_logging_data() {

    // log internal messages first
    float timeSinceStart_s = float(AP_HAL::millis() - start_time) / 1000.0f; // in seconds
    logging_data[0] = timeSinceStart_s;
    
    // log the data from the controller
    for (int i = 0; i < lengthOfLogging_Simulink; ++i) {
        logging_data[i + 1] = arg_logging_refout[i];
    }

    return logging_data;
}

float AC_Simulink::get_power_gain() {
    return ref_power_gain;
}

bool AC_Simulink::get_master_switch() {
    return master_switch;
}

bool AC_Simulink::recentDashboardMessage(float threshold_ms) {
    uint32_t dashboard_msg_time = AP_HAL::millis() - last_dashboard_msg_ms;
    if (dashboard_msg_time > threshold_ms) {
        return false;
    }
    return true;
}

// handle a mavlink message coming in from the dashboard 
void AC_Simulink::handle_message(const mavlink_message_t &msg)
{
    // keep track of the last time we received a message from the dashboard
    last_dashboard_msg_ms = AP_HAL::millis();

    if (msg.msgid != MAVLINK_MSG_ID_LAB_FROM_DASHBOARD) {
        return;
    }
    mavlink_lab_from_dashboard_t m;
    mavlink_msg_lab_from_dashboard_decode(&msg, &m);

    master_switch       = m.master_switch;
    ref_power_gain      = m.power;
    ref_pos_x           = m.ref_x;
    ref_pos_y           = m.ref_y;
    ref_pos_z           = m.ref_z;
    ref_orient_yaw      = m.ref_yaw;
    ref_orient_pitch    = m.ref_pitch;
    ref_orient_roll     = m.ref_roll; 

}





