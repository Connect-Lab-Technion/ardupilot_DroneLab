// Description: This is the header file for the AC_Simulink class. 
// This class wraps the Simulink controller and handles the communication between the controller, dashboard, and the rest of the ArduPilot code.
// The class includes methods to: 
//   1. Wrap a simulink based controller,
//   2. Package logging data from simulink into a mavlink message for the dashboard,
//   3. Process mavlink messages coming in from the dashboard for the controller,
//   4. House safety checks for the controller, like checking if a message was received from the dashboard within a certain threshold,


#pragma once

#ifndef MODE_LAB_ENABLED
#define MODE_LAB_ENABLED 1
#endif

#include <AC_Simulink/FCS_model.h>
#include <SRV_Channel/SRV_Channel.h>
#include <AP_Common/AP_Common.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_HAL/AP_HAL.h>
#include <GCS_MAVLink/GCS.h>
#include <AP_BattMonitor/AP_BattMonitor.h>
#include <AP_OpticalFlow/AP_OpticalFlow.h>


class AC_Simulink {
public:
    // Constructor
    AC_Simulink();

    void inititalize();
    
    // Method to run the wrapped Simulink controller
    void runController(float* motor_out);
    
    // Method to handle a mavlink message coming in from the dashboard
    void handle_message(const mavlink_message_t &msg);

    // Method to check if a message was received from the dashboard within a certain threshold
    bool recentDashboardMessage(float threshold_ms);

    // Method to get the logging data from the controller. Used for mavlink message
    float* get_logging_data();

    // Methods to get the power gain and master switch from the dashboard. Used for motor output
    float get_power_gain();
    bool get_master_switch();

    // get singleton instance
    static AC_Simulink *get_singleton() { return _singleton; }

private:
    static AC_Simulink *_singleton;

    // Simulink controller
    FCS_model simulinkModel;
    
    // Variables from the dashboard
    bool master_switch;
    float ref_power_gain; 
    float ref_pos_x,ref_pos_y,ref_pos_z;
    float ref_orient_yaw, ref_orient_pitch, ref_orient_roll; 
    
    // Counter for the last time a message was received from the dashboard
    uint32_t last_dashboard_msg_ms;

    // Time value for the logging data
    uint32_t start_time;
    
    // Pointers for variable length logging data
    float* logging_data;
    float* arg_logging_refout;

};
