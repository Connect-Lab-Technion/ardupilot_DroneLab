//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ardupilot_controller_v1.cpp
//
// Code generated for Simulink model 'ardupilot_controller_v1'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Nov  7 14:38:48 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ardupilot_controller_v1.h"
#include "rtwtypes.h"

// Model step function
void ardupilot_controller_v1::step(real32_T arg_attitude_error[3], real32_T
  arg_rate_ff[3], real32_T arg_rate_meas[3], real32_T (&arg_Output)[3])
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

  rtb_Sum_nz = (0.0F * arg_attitude_error[0] + arg_rate_ff[0]) - arg_rate_meas[0];

  // Gain: '<S38>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S30>/Filter'
  //   Gain: '<S29>/Derivative Gain'
  //   Sum: '<S30>/SumD'

  rtb_FilterCoefficient = (0.00324F * rtb_Sum_nz -
    ardupilot_controller_v1_DW.Filter_DSTATE) * 50.2654839F;

  // Sum: '<Root>/Sum1' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Inport: '<Root>/attitude_error'
  //   Inport: '<Root>/rate_ff'
  //   Inport: '<Root>/rate_meas'
  //   Sum: '<Root>/Sum4'

  rtb_Sum1 = (0.0F * arg_attitude_error[1] + arg_rate_ff[1]) - arg_rate_meas[1];

  // Gain: '<S86>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S78>/Filter'
  //   Gain: '<S77>/Derivative Gain'
  //   Sum: '<S78>/SumD'

  rtb_FilterCoefficient_c = (0.00324F * rtb_Sum1 -
    ardupilot_controller_v1_DW.Filter_DSTATE_d) * 50.2654839F;

  // Sum: '<Root>/Sum2' incorporates:
  //   Gain: '<Root>/Gain2'
  //   Inport: '<Root>/attitude_error'
  //   Inport: '<Root>/rate_ff'
  //   Inport: '<Root>/rate_meas'
  //   Sum: '<Root>/Sum5'

  rtb_Sum2 = (0.0F * arg_attitude_error[2] + arg_rate_ff[2]) - arg_rate_meas[2];

  // Gain: '<S134>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S126>/Filter'
  //   Gain: '<S125>/Derivative Gain'
  //   Sum: '<S126>/SumD'

  rtb_FilterCoefficient_oz = (0.00324F * rtb_Sum2 -
    ardupilot_controller_v1_DW.Filter_DSTATE_c) * 50.2654839F;

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

  arg_Output[0] = (0.1215F * rtb_Sum_nz +
                   ardupilot_controller_v1_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;
  arg_Output[1] = (0.1215F * rtb_Sum1 +
                   ardupilot_controller_v1_DW.Integrator_DSTATE_j) +
    rtb_FilterCoefficient_c;
  arg_Output[2] = (0.1215F * rtb_Sum2 +
                   ardupilot_controller_v1_DW.Integrator_DSTATE_h) +
    rtb_FilterCoefficient_oz;

  // Update for DiscreteIntegrator: '<S35>/Integrator' incorporates:
  //   Gain: '<S32>/Integral Gain'

  ardupilot_controller_v1_DW.Integrator_DSTATE += 0.1215F * rtb_Sum_nz * 0.02F;
  if (ardupilot_controller_v1_DW.Integrator_DSTATE >= 0.45F) {
    ardupilot_controller_v1_DW.Integrator_DSTATE = 0.45F;
  } else if (ardupilot_controller_v1_DW.Integrator_DSTATE <= -0.45F) {
    ardupilot_controller_v1_DW.Integrator_DSTATE = -0.45F;
  }

  // End of Update for DiscreteIntegrator: '<S35>/Integrator'

  // Update for DiscreteIntegrator: '<S30>/Filter'
  ardupilot_controller_v1_DW.Filter_DSTATE += 0.02F * rtb_FilterCoefficient;

  // Update for DiscreteIntegrator: '<S83>/Integrator' incorporates:
  //   Gain: '<S80>/Integral Gain'

  ardupilot_controller_v1_DW.Integrator_DSTATE_j += 0.1215F * rtb_Sum1 * 0.02F;
  if (ardupilot_controller_v1_DW.Integrator_DSTATE_j >= 0.45F) {
    ardupilot_controller_v1_DW.Integrator_DSTATE_j = 0.45F;
  } else if (ardupilot_controller_v1_DW.Integrator_DSTATE_j <= -0.45F) {
    ardupilot_controller_v1_DW.Integrator_DSTATE_j = -0.45F;
  }

  // End of Update for DiscreteIntegrator: '<S83>/Integrator'

  // Update for DiscreteIntegrator: '<S78>/Filter'
  ardupilot_controller_v1_DW.Filter_DSTATE_d += 0.02F * rtb_FilterCoefficient_c;

  // Update for DiscreteIntegrator: '<S131>/Integrator' incorporates:
  //   Gain: '<S128>/Integral Gain'

  ardupilot_controller_v1_DW.Integrator_DSTATE_h += 0.1215F * rtb_Sum2 * 0.02F;
  if (ardupilot_controller_v1_DW.Integrator_DSTATE_h >= 0.45F) {
    ardupilot_controller_v1_DW.Integrator_DSTATE_h = 0.45F;
  } else if (ardupilot_controller_v1_DW.Integrator_DSTATE_h <= -0.45F) {
    ardupilot_controller_v1_DW.Integrator_DSTATE_h = -0.45F;
  }

  // End of Update for DiscreteIntegrator: '<S131>/Integrator'

  // Update for DiscreteIntegrator: '<S126>/Filter'
  ardupilot_controller_v1_DW.Filter_DSTATE_c += 0.02F * rtb_FilterCoefficient_oz;
}

// Model initialize function
void ardupilot_controller_v1::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ardupilot_controller_v1::terminate()
{
  // (no terminate code required)
}

// Constructor
ardupilot_controller_v1::ardupilot_controller_v1() :
  ardupilot_controller_v1_DW(),
  ardupilot_controller_v1_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ardupilot_controller_v1::~ardupilot_controller_v1()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ardupilot_controller_v1::RT_MODEL_ardupilot_controller_T
  * ardupilot_controller_v1::getRTM()
{
  return (&ardupilot_controller_v1_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
