//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ardupilot_controller_v1_model.cpp
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
#include "rtwtypes.h"

// Model step function
void ardupilot_controller_v1_model::step(real32_T arg_attitude_error[3],
  real32_T arg_rate_ff[3], real32_T arg_rate_meas[3], real32_T (&arg_Output)[3])
{
  real32_T rtb_FilterCoefficient;
  real32_T rtb_FilterCoefficient_c;
  real32_T rtb_FilterCoefficient_oz;
  real32_T rtb_Sum1;
  real32_T rtb_Sum2;
  real32_T rtb_Sum_nz;

  // Sum: '<Root>/Sum' incorporates:
  //   Gain: '<Root>/Gain'
  //   Inport: '<Root>/attitude_error'
  //   Inport: '<Root>/rate_ff'
  //   Inport: '<Root>/rate_meas'
  //   Sum: '<Root>/Sum3'

  rtb_Sum_nz = (ardupilot_controller_v1_model_P.RAT_RLL_FF * arg_attitude_error
                [0] + arg_rate_ff[0]) - arg_rate_meas[0];

  // Gain: '<S86>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S78>/Filter'
  //   Gain: '<S77>/Derivative Gain'
  //   Sum: '<S78>/SumD'

  rtb_FilterCoefficient = (ardupilot_controller_v1_model_P.RAT_RLL_D *
    rtb_Sum_nz - ardupilot_controller_v1_mode_DW.Filter_DSTATE) *
    ardupilot_controller_v1_model_P.DiscretePIDControllerRoll_N;

  // Sum: '<Root>/Sum1' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Inport: '<Root>/attitude_error'
  //   Inport: '<Root>/rate_ff'
  //   Inport: '<Root>/rate_meas'
  //   Sum: '<Root>/Sum4'

  rtb_Sum1 = (ardupilot_controller_v1_model_P.RAT_PIT_FF * arg_attitude_error[1]
              + arg_rate_ff[1]) - arg_rate_meas[1];

  // Gain: '<S38>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S30>/Filter'
  //   Gain: '<S29>/Derivative Gain'
  //   Sum: '<S30>/SumD'

  rtb_FilterCoefficient_c = (ardupilot_controller_v1_model_P.RAT_PIT_D *
    rtb_Sum1 - ardupilot_controller_v1_mode_DW.Filter_DSTATE_d) *
    ardupilot_controller_v1_model_P.DiscretePIDControllerPitch_N;

  // Sum: '<Root>/Sum2' incorporates:
  //   Gain: '<Root>/Gain2'
  //   Inport: '<Root>/attitude_error'
  //   Inport: '<Root>/rate_ff'
  //   Inport: '<Root>/rate_meas'
  //   Sum: '<Root>/Sum5'

  rtb_Sum2 = (ardupilot_controller_v1_model_P.RAT_YAW_FF * arg_attitude_error[2]
              + arg_rate_ff[2]) - arg_rate_meas[2];

  // Gain: '<S134>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S126>/Filter'
  //   Gain: '<S125>/Derivative Gain'
  //   Sum: '<S126>/SumD'

  rtb_FilterCoefficient_oz = (ardupilot_controller_v1_model_P.RAT_YAW_D *
    rtb_Sum2 - ardupilot_controller_v1_mode_DW.Filter_DSTATE_c) *
    ardupilot_controller_v1_model_P.DiscretePIDControllerYaw_N;

  // Outport: '<Root>/Output' incorporates:
  //   DiscreteIntegrator: '<S131>/Integrator'
  //   DiscreteIntegrator: '<S35>/Integrator'
  //   DiscreteIntegrator: '<S83>/Integrator'
  //   Gain: '<S136>/Proportional Gain'
  //   Gain: '<S40>/Proportional Gain'
  //   Gain: '<S88>/Proportional Gain'
  //   Sum: '<S140>/Sum'
  //   Sum: '<S44>/Sum'
  //   Sum: '<S92>/Sum'

  arg_Output[0] = (ardupilot_controller_v1_model_P.RAT_RLL_P * rtb_Sum_nz +
                   ardupilot_controller_v1_mode_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;
  arg_Output[1] = (ardupilot_controller_v1_model_P.RAT_PIT_P * rtb_Sum1 +
                   ardupilot_controller_v1_mode_DW.Integrator_DSTATE_j) +
    rtb_FilterCoefficient_c;
  arg_Output[2] = (ardupilot_controller_v1_model_P.RAT_YAW_P * rtb_Sum2 +
                   ardupilot_controller_v1_mode_DW.Integrator_DSTATE_h) +
    rtb_FilterCoefficient_oz;

  // Update for DiscreteIntegrator: '<S83>/Integrator' incorporates:
  //   Gain: '<S80>/Integral Gain'

  ardupilot_controller_v1_mode_DW.Integrator_DSTATE +=
    ardupilot_controller_v1_model_P.RAT_RLL_I * rtb_Sum_nz *
    ardupilot_controller_v1_model_P.Integrator_gainval;
  if (ardupilot_controller_v1_mode_DW.Integrator_DSTATE >=
      ardupilot_controller_v1_model_P.RAT_RLL_IMAX) {
    ardupilot_controller_v1_mode_DW.Integrator_DSTATE =
      ardupilot_controller_v1_model_P.RAT_RLL_IMAX;
  } else if (ardupilot_controller_v1_mode_DW.Integrator_DSTATE <=
             ardupilot_controller_v1_model_P.DiscretePIDControllerRoll_Lower) {
    ardupilot_controller_v1_mode_DW.Integrator_DSTATE =
      ardupilot_controller_v1_model_P.DiscretePIDControllerRoll_Lower;
  }

  // End of Update for DiscreteIntegrator: '<S83>/Integrator'

  // Update for DiscreteIntegrator: '<S78>/Filter'
  ardupilot_controller_v1_mode_DW.Filter_DSTATE +=
    ardupilot_controller_v1_model_P.Filter_gainval * rtb_FilterCoefficient;

  // Update for DiscreteIntegrator: '<S35>/Integrator' incorporates:
  //   Gain: '<S32>/Integral Gain'

  ardupilot_controller_v1_mode_DW.Integrator_DSTATE_j +=
    ardupilot_controller_v1_model_P.RAT_PIT_I * rtb_Sum1 *
    ardupilot_controller_v1_model_P.Integrator_gainval_i;
  if (ardupilot_controller_v1_mode_DW.Integrator_DSTATE_j >=
      ardupilot_controller_v1_model_P.RAT_PIT_IMAX) {
    ardupilot_controller_v1_mode_DW.Integrator_DSTATE_j =
      ardupilot_controller_v1_model_P.RAT_PIT_IMAX;
  } else if (ardupilot_controller_v1_mode_DW.Integrator_DSTATE_j <=
             ardupilot_controller_v1_model_P.DiscretePIDControllerPitch_Lowe) {
    ardupilot_controller_v1_mode_DW.Integrator_DSTATE_j =
      ardupilot_controller_v1_model_P.DiscretePIDControllerPitch_Lowe;
  }

  // End of Update for DiscreteIntegrator: '<S35>/Integrator'

  // Update for DiscreteIntegrator: '<S30>/Filter'
  ardupilot_controller_v1_mode_DW.Filter_DSTATE_d +=
    ardupilot_controller_v1_model_P.Filter_gainval_f * rtb_FilterCoefficient_c;

  // Update for DiscreteIntegrator: '<S131>/Integrator' incorporates:
  //   Gain: '<S128>/Integral Gain'

  ardupilot_controller_v1_mode_DW.Integrator_DSTATE_h +=
    ardupilot_controller_v1_model_P.RAT_YAW_I * rtb_Sum2 *
    ardupilot_controller_v1_model_P.Integrator_gainval_a;
  if (ardupilot_controller_v1_mode_DW.Integrator_DSTATE_h >=
      ardupilot_controller_v1_model_P.RAT_YAW_IMAX) {
    ardupilot_controller_v1_mode_DW.Integrator_DSTATE_h =
      ardupilot_controller_v1_model_P.RAT_YAW_IMAX;
  } else if (ardupilot_controller_v1_mode_DW.Integrator_DSTATE_h <=
             ardupilot_controller_v1_model_P.DiscretePIDControllerYaw_LowerI) {
    ardupilot_controller_v1_mode_DW.Integrator_DSTATE_h =
      ardupilot_controller_v1_model_P.DiscretePIDControllerYaw_LowerI;
  }

  // End of Update for DiscreteIntegrator: '<S131>/Integrator'

  // Update for DiscreteIntegrator: '<S126>/Filter'
  ardupilot_controller_v1_mode_DW.Filter_DSTATE_c +=
    ardupilot_controller_v1_model_P.Filter_gainval_c * rtb_FilterCoefficient_oz;
}

// Model initialize function
void ardupilot_controller_v1_model::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<S83>/Integrator'
  ardupilot_controller_v1_mode_DW.Integrator_DSTATE =
    ardupilot_controller_v1_model_P.RAT_RLL_FLTE;

  // InitializeConditions for DiscreteIntegrator: '<S78>/Filter'
  ardupilot_controller_v1_mode_DW.Filter_DSTATE =
    ardupilot_controller_v1_model_P.RAT_RLL_FLTD;

  // InitializeConditions for DiscreteIntegrator: '<S35>/Integrator'
  ardupilot_controller_v1_mode_DW.Integrator_DSTATE_j =
    ardupilot_controller_v1_model_P.RAT_PIT_FLTE;

  // InitializeConditions for DiscreteIntegrator: '<S30>/Filter'
  ardupilot_controller_v1_mode_DW.Filter_DSTATE_d =
    ardupilot_controller_v1_model_P.RAT_PIT_FLTD;

  // InitializeConditions for DiscreteIntegrator: '<S131>/Integrator'
  ardupilot_controller_v1_mode_DW.Integrator_DSTATE_h =
    ardupilot_controller_v1_model_P.RAT_YAW_FLTE;

  // InitializeConditions for DiscreteIntegrator: '<S126>/Filter'
  ardupilot_controller_v1_mode_DW.Filter_DSTATE_c =
    ardupilot_controller_v1_model_P.RAT_YAW_FLTD;
}

// Model terminate function
void ardupilot_controller_v1_model::terminate()
{
  // (no terminate code required)
}

// Constructor
ardupilot_controller_v1_model::ardupilot_controller_v1_model() :
  ardupilot_controller_v1_mode_DW(),
  ardupilot_controller_v1_mode_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ardupilot_controller_v1_model::~ardupilot_controller_v1_model()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ardupilot_controller_v1_model::RT_MODEL_ardupilot_controller_T
  * ardupilot_controller_v1_model::getRTM()
{
  return (&ardupilot_controller_v1_mode_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
