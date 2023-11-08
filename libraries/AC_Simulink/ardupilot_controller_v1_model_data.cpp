//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ardupilot_controller_v1_model_data.cpp
//
// Code generated for Simulink model 'ardupilot_controller_v1_model'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Nov  8 14:17:45 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ardupilot_controller_v1_model.h"

// Block parameters (default storage)
ardupilot_controller_v1_model::P_ardupilot_controller_v1_mod_T
  ardupilot_controller_v1_model::ardupilot_controller_v1_model_P{
  // Variable: RAT_PIT_D
  //  Referenced by: '<S29>/Derivative Gain'

  0.00324F,

  // Variable: RAT_PIT_FF
  //  Referenced by: '<Root>/Gain1'

  0.0F,

  // Variable: RAT_PIT_FLTD
  //  Referenced by: '<S30>/Filter'

  8.0F,

  // Variable: RAT_PIT_FLTE
  //  Referenced by: '<S35>/Integrator'

  0.0F,

  // Variable: RAT_PIT_I
  //  Referenced by: '<S32>/Integral Gain'

  0.1215F,

  // Variable: RAT_PIT_IMAX
  //  Referenced by: '<S35>/Integrator'

  0.45F,

  // Variable: RAT_PIT_P
  //  Referenced by: '<S40>/Proportional Gain'

  0.1215F,

  // Variable: RAT_RLL_D
  //  Referenced by: '<S77>/Derivative Gain'

  0.00324F,

  // Variable: RAT_RLL_FF
  //  Referenced by: '<Root>/Gain'

  0.0F,

  // Variable: RAT_RLL_FLTD
  //  Referenced by: '<S78>/Filter'

  8.0F,

  // Variable: RAT_RLL_FLTE
  //  Referenced by: '<S83>/Integrator'

  0.0F,

  // Variable: RAT_RLL_I
  //  Referenced by: '<S80>/Integral Gain'

  0.1215F,

  // Variable: RAT_RLL_IMAX
  //  Referenced by: '<S83>/Integrator'

  0.45F,

  // Variable: RAT_RLL_P
  //  Referenced by: '<S88>/Proportional Gain'

  0.1215F,

  // Variable: RAT_YAW_D
  //  Referenced by: '<S125>/Derivative Gain'

  0.00324F,

  // Variable: RAT_YAW_FF
  //  Referenced by: '<Root>/Gain2'

  0.0F,

  // Variable: RAT_YAW_FLTD
  //  Referenced by: '<S126>/Filter'

  8.0F,

  // Variable: RAT_YAW_FLTE
  //  Referenced by: '<S131>/Integrator'

  0.0F,

  // Variable: RAT_YAW_I
  //  Referenced by: '<S128>/Integral Gain'

  0.1215F,

  // Variable: RAT_YAW_IMAX
  //  Referenced by: '<S131>/Integrator'

  0.45F,

  // Variable: RAT_YAW_P
  //  Referenced by: '<S136>/Proportional Gain'

  0.1215F,

  // Mask Parameter: DiscretePIDControllerRoll_Lower
  //  Referenced by: '<S83>/Integrator'

  -0.45F,

  // Mask Parameter: DiscretePIDControllerPitch_Lowe
  //  Referenced by: '<S35>/Integrator'

  -0.45F,

  // Mask Parameter: DiscretePIDControllerYaw_LowerI
  //  Referenced by: '<S131>/Integrator'

  -0.45F,

  // Mask Parameter: DiscretePIDControllerRoll_N
  //  Referenced by: '<S86>/Filter Coefficient'

  50.2654839F,

  // Mask Parameter: DiscretePIDControllerPitch_N
  //  Referenced by: '<S38>/Filter Coefficient'

  50.2654839F,

  // Mask Parameter: DiscretePIDControllerYaw_N
  //  Referenced by: '<S134>/Filter Coefficient'

  50.2654839F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S83>/Integrator'

  0.02F,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S78>/Filter'

  0.02F,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S35>/Integrator'

  0.02F,

  // Computed Parameter: Filter_gainval_f
  //  Referenced by: '<S30>/Filter'

  0.02F,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S131>/Integrator'

  0.02F,

  // Computed Parameter: Filter_gainval_c
  //  Referenced by: '<S126>/Filter'

  0.02F
};

//
// File trailer for generated code.
//
// [EOF]
//
