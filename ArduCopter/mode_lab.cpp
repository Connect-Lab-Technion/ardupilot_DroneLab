// Description: ModeLab class is a child class of the Mode class. It is used to run a simulink controller.

#include "Copter.h"
#include <SRV_Channel/SRV_Channel.h>
#include <AP_Common/AP_Common.h>
#include <AC_Simulink/AC_Simulink.h>

#if MODE_LAB_ENABLED == ENABLED

// lab_init - initialise lab controller
bool ModeLab::init(bool ignore_checks)
{   
    copter.simulinkController.inititalize();

    // Arm motors. Overrides and disables failsafes. 
    arm_motors();

    // Turn on notify leds
    AP_Notify::flags.esc_calibration = true;
    
    // Debug message to the GCS
    gcs().send_text(MAV_SEVERITY_INFO, "LAB: intitialised"); // Reaches this point
    return true;
}

// lab_run - runs the lab controller
// should be called at 100hz to match the controller rate
void ModeLab::run()
{
    // check if we have received a message from the dashboard
    monitorDashboardMessage(2000);

    // run the controller
    copter.simulinkController.runController(motor_out);

    // send the logging data to the dashboard
    gcs().send_message(MSG_LAB_TO_DASHBOARD); // TODO: Implement this message /home/joseph/ardupilot_DroneLab/libraries/GCS_MAVLink/GCS_Common.cpp:5445
    
}

void ModeLab::monitorDashboardMessage(float threshold_ms)
{
    if(!copter.simulinkController.recentDashboardMessage(threshold_ms)) {
        // Send a warning message to the GCS
        gcs().send_text(MAV_SEVERITY_WARNING, "LAB: no message from dashboard in: %f ms" , threshold_ms);
        // Run internal exit function
        // exit();
        // Switch back to the default mode 
        set_mode(Mode::Number::STABILIZE, ModeReason::GCS_COMMAND);
    }
}


void ModeLab::exit()
{
    disarm_motors();
    gcs().send_text(MAV_SEVERITY_WARNING, "LAB:EXITING");
    // turn off notify leds
    AP_Notify::flags.esc_calibration = false;
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
    change_motor_direction(false);

    // disable throttle and gps failsafe
    g.failsafe_throttle.set(FS_THR_DISABLED);
    g.failsafe_gcs.set(FS_GCS_DISABLED);
    g.fs_ekf_action.set(0);

    // arm
    motors->armed(true);
    hal.util->set_soft_armed(true);
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

// actually write values to the motors
void ModeLab::output_to_motors()
{

    // check if motor are allowed to spin
    const bool allow_output = motors->armed() && motors->get_interlock();

    if (allow_output && copter.simulinkController.get_master_switch()) {

        // get power gain from the controller - between 0 and 1
        float powerGain = copter.simulinkController.get_power_gain();
        // convert output to PWM and send to each motor
        int8_t i;   
        for (i = 0; i <= 3; i++) {
            if (motors->is_motor_enabled(i)) {
                float motor_pwm = motor_out[i]  * powerGain * 1000 + 1000;;
                motors->rc_write(i, motor_pwm);
            }
        }
    }
}



#endif
