//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'ardupilot_controller_v1_model'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Nov  9 12:19:14 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stdio.h>              // This example main program uses printf/fflush
#include "ardupilot_controller_v1_model.h" // Model header file

static ardupilot_controller_v1_model ardupilot_controller_v1_mod_Obj;// Instance of model class 

// '<Root>/attitude_error'
static real32_T arg_attitude_error[3]{ 0.0F, 0.0F, 0.0F };

// '<Root>/rate_ff'
static real32_T arg_rate_ff[3]{ 0.0F, 0.0F, 0.0F };

// '<Root>/rate_meas'
static real32_T arg_rate_meas[3]{ 0.0F, 0.0F, 0.0F };

// '<Root>/Output'
static real32_T arg_Output[3];

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag{ false };

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(ardupilot_controller_v1_mod_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  ardupilot_controller_v1_mod_Obj.step(arg_attitude_error, arg_rate_ff,
    arg_rate_meas, arg_Output);

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example main function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific. This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Initialize model
  ardupilot_controller_v1_mod_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.02 seconds (base rate of the model) here.
  //  The call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((nullptr));
  while (rtmGetErrorStatus(ardupilot_controller_v1_mod_Obj.getRTM()) == (nullptr))
  {
    //  Perform application tasks here
  }

  // Terminate model
  ardupilot_controller_v1_mod_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
