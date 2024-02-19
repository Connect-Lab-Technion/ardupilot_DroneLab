#include "Copter.h"
#include <AC_ControlLab/AC_ControlLab.h>
#include <AC_Simulink/dmitry_model.h>
dmitry_model customcontroller;
#include <array>

#if MODE_LAB_ENABLED == ENABLED

/*
 * Init and run calls for lab flight mode
 */

// lab_init - initialise lab controller
bool ModeLab::init(bool ignore_checks)
{
    gcs().send_text(MAV_SEVERITY_INFO, "LAB: intitialised");

    // turn on notify leds
    AP_Notify::flags.esc_calibration = true;
    motor_out_1 = 0.0f;
    motor_out_2 = 0.0f;
    motor_out_3 = 0.0f;
    motor_out_4 = 0.0f;
    return true;
}


// lab_run - runs the lab controller
// should be called at 100hz or more
void ModeLab::run()
{
    // std::ostringstream oss;
    Vector3f gyroresponse = ahrs.get_gyro();
    // // const char * logmessage_gyro; // = gyroresponse.tofloat().tos;
    // // oss << "LAB: GYRO (" << gyroresponse.x << "," << gyroresponse.y << "," << gyroresponse.z << ")";
    // // std::string str = oss.str();
    // // const char * logMessage_test = str.c_str();
    // char logMessage_test[50];
    // std::string str_log = //"LAB: GYRO (" + std::to_string(gyroresponse.x) + "," + std::to_string(gyroresponse.y) + "," + std::to_string(gyroresponse.z) + ") %d\n";
    // std:strcpy(logMessage_test, str_log.c_str());

    // const char *message_out = "asdfasdfasdfasdfasdfasdfasdfasdfasdfa";
    gcs().send_text(MAV_SEVERITY_INFO, "%f,%f,%f", gyroresponse.x,gyroresponse.y,gyroresponse.x);

    std::array<float, 4> motors_out{0,0,0,0};//lab.controlWrapper();
    motor_out_1 = motors_out[0];
    motor_out_2 = motors_out[1];
    motor_out_3 = motors_out[2];
    motor_out_4 = motors_out[3];
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
    // throttle needs to be raised
    if (is_zero(channel_throttle->norm_input_dz())) {
        const uint32_t now = AP_HAL::millis();
        if (now - last_throttle_warning_output_ms > 5000) {
            gcs().send_text(MAV_SEVERITY_WARNING, "LAB: raise throttle to arm");
            last_throttle_warning_output_ms = now;
        }

        disarm_motors();
        return;
    }

    arm_motors();

    // check if motor are allowed to spin
    const bool allow_output = motors->armed() && motors->get_interlock();

    float motor_outputs[] = {motor_out_1, motor_out_2, motor_out_3, motor_out_4};
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; ++i) {
        if (!motors->is_motor_enabled(i)) {
            continue;
        }

        const Vector2f output{motors->get_roll_factor(i), motors->get_pitch_factor(i)};
        
        // if output aligns with input then use this motor
        if (!allow_output ) { // || (motors_input - output).length() > 0.5) {
            motors->rc_write(i, motors->get_pwm_output_min());
            continue;
        }

        int16_t pwm = motors->get_pwm_output_min() + (motors->get_pwm_output_max() - motors->get_pwm_output_min()) * motor_outputs[i];

        motors->rc_write(i, pwm);
    }
}


#endif
