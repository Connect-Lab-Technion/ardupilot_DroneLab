//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: wrapper_template_model.cpp
//
// Code generated for Simulink model 'wrapper_template_model'.
//
// Model version                  : 1.10
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sun Dec 17 23:19:46 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "wrapper_template_model.h"
#include "rtwtypes.h"

// Model step function
void wrapper_template_model::step(real32_T arg_accel[3], real32_T arg_gyro[3],
  real32_T *arg_bat_V, real32_T arg_pos_est[3], real32_T arg_vel_est[3],
  real32_T *arg_yaw_opticalfow, real32_T arg_pos_ref[3], real32_T
  arg_orient_ref[3], real32_T (&arg_torque_ref)[3]) const
{
  real32_T rtb_Sum6;

  // Sum: '<Root>/Sum6' incorporates:
  //   Inport: '<Root>/accel'
  //   Inport: '<Root>/bat_V'
  //   Inport: '<Root>/gyro'
  //   Inport: '<Root>/orient_ref'
  //   Inport: '<Root>/pos_est'
  //   Inport: '<Root>/pos_ref'
  //   Inport: '<Root>/vel_est'
  //   Inport: '<Root>/yaw_opticalfow'
  //   Sum: '<Root>/Sum'
  //   Sum: '<Root>/Sum1'
  //   Sum: '<Root>/Sum2'
  //   Sum: '<Root>/Sum3'
  //   Sum: '<Root>/Sum4'
  //   Sum: '<Root>/Sum5'

  rtb_Sum6 = ((((((((arg_accel[0] + arg_accel[1]) + arg_accel[2]) + ((arg_gyro[0]
    + arg_gyro[1]) + arg_gyro[2])) + *arg_bat_V) + ((arg_pos_est[0] +
    arg_pos_est[1]) + arg_pos_est[2])) + ((arg_vel_est[0] + arg_vel_est[1]) +
    arg_vel_est[2])) + *arg_yaw_opticalfow) + ((arg_pos_ref[0] + arg_pos_ref[1])
    + arg_pos_ref[2])) + ((arg_orient_ref[0] + arg_orient_ref[1]) +
    arg_orient_ref[2]);

  // Outport: '<Root>/torque_ref' incorporates:
  //   Gain: '<Root>/Gain'

  arg_torque_ref[0] = wrapper_template_model_P.Gain_Gain[0] * rtb_Sum6;
  arg_torque_ref[1] = wrapper_template_model_P.Gain_Gain[1] * rtb_Sum6;
  arg_torque_ref[2] = wrapper_template_model_P.Gain_Gain[2] * rtb_Sum6;
}

// Model initialize function
void wrapper_template_model::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void wrapper_template_model::terminate()
{
  // (no terminate code required)
}

// Constructor
wrapper_template_model::wrapper_template_model() :
  wrapper_template_model_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
wrapper_template_model::~wrapper_template_model()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
wrapper_template_model::RT_MODEL_wrapper_template_mod_T * wrapper_template_model::
  getRTM()
{
  return (&wrapper_template_model_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
