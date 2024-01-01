#include "Copter.h"


#if MODE_LAB_ENABLED == ENABLED

/*
 * Init and run calls for lab flight mode
 */

// lab_init - initialise lab controller
bool ModeLab::init(bool ignore_checks)
{

    return true;
}


// lab_run - runs the lab controller
// should be called at 100hz or more
void ModeLab::run()
{
    float target_roll, target_pitch, target_yaw;
    float target_x, target_y, target_z;

}

#endif
