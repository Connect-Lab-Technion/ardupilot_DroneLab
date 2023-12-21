//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: wrapper_template_model.h
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
#ifndef RTW_HEADER_wrapper_template_model_h_
#define RTW_HEADER_wrapper_template_model_h_
#include "rtwtypes.h"
#include "wrapper_template_model_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model wrapper_template_model
class wrapper_template_model final
{
  // public data and function members
 public:
  // Parameters (default storage)
  struct P_wrapper_template_model_T {
    real32_T Gain_Gain[3];             // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<Root>/Gain'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_wrapper_template_mod_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  wrapper_template_model(wrapper_template_model const&) = delete;

  // Assignment Operator
  wrapper_template_model& operator= (wrapper_template_model const&) & = delete;

  // Move Constructor
  wrapper_template_model(wrapper_template_model &&) = delete;

  // Move Assignment Operator
  wrapper_template_model& operator= (wrapper_template_model &&) = delete;

  // Real-Time Model get method
  wrapper_template_model::RT_MODEL_wrapper_template_mod_T * getRTM();

  // Tunable parameters
  static P_wrapper_template_model_T wrapper_template_model_P;

  // model initialize function
  static void initialize();

  // model step function
  void step(real32_T arg_accel[3], real32_T arg_gyro[3], real32_T *arg_bat_V,
            real32_T arg_pos_est[3], real32_T arg_vel_est[3], real32_T
            *arg_yaw_opticalfow, real32_T arg_pos_ref[3], real32_T
            arg_orient_ref[3], real32_T (&arg_torque_ref)[3]) const;

  // model terminate function
  static void terminate();

  // Constructor
  wrapper_template_model();

  // Destructor
  ~wrapper_template_model();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_wrapper_template_mod_T wrapper_template_model_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'wrapper_template_model'

#endif                                 // RTW_HEADER_wrapper_template_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
