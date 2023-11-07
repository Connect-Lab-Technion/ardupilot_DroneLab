//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ardupilot_controller_v1.h
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
#ifndef RTW_HEADER_ardupilot_controller_v1_h_
#define RTW_HEADER_ardupilot_controller_v1_h_
#include "rtwtypes.h"
#include "ardupilot_controller_v1_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ardupilot_controller_v1
class ardupilot_controller_v1 final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_ardupilot_controller_v1_T {
    real32_T Integrator_DSTATE;        // '<S35>/Integrator'
    real32_T Filter_DSTATE;            // '<S30>/Filter'
    real32_T Integrator_DSTATE_j;      // '<S83>/Integrator'
    real32_T Filter_DSTATE_d;          // '<S78>/Filter'
    real32_T Integrator_DSTATE_h;      // '<S131>/Integrator'
    real32_T Filter_DSTATE_c;          // '<S126>/Filter'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_ardupilot_controller_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ardupilot_controller_v1(ardupilot_controller_v1 const&) = delete;

  // Assignment Operator
  ardupilot_controller_v1& operator= (ardupilot_controller_v1 const&) & = delete;

  // Move Constructor
  ardupilot_controller_v1(ardupilot_controller_v1 &&) = delete;

  // Move Assignment Operator
  ardupilot_controller_v1& operator= (ardupilot_controller_v1 &&) = delete;

  // Real-Time Model get method
  ardupilot_controller_v1::RT_MODEL_ardupilot_controller_T * getRTM();

  // Block states
  DW_ardupilot_controller_v1_T ardupilot_controller_v1_DW;

  // model initialize function
  static void initialize();

  // model step function
  void step(real32_T arg_attitude_error[3], real32_T arg_rate_ff[3], real32_T
            arg_rate_meas[3], real32_T (&arg_Output)[3]);

  // model terminate function
  static void terminate();

  // Constructor
  ardupilot_controller_v1();

  // Destructor
  ~ardupilot_controller_v1();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_ardupilot_controller_T ardupilot_controller_v1_M;
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
//  '<Root>' : 'ardupilot_controller_v1'
//  '<S1>'   : 'ardupilot_controller_v1/Discrete PID Controller'
//  '<S2>'   : 'ardupilot_controller_v1/Discrete PID Controller1'
//  '<S3>'   : 'ardupilot_controller_v1/Discrete PID Controller2'
//  '<S4>'   : 'ardupilot_controller_v1/Discrete PID Controller/Anti-windup'
//  '<S5>'   : 'ardupilot_controller_v1/Discrete PID Controller/D Gain'
//  '<S6>'   : 'ardupilot_controller_v1/Discrete PID Controller/Filter'
//  '<S7>'   : 'ardupilot_controller_v1/Discrete PID Controller/Filter ICs'
//  '<S8>'   : 'ardupilot_controller_v1/Discrete PID Controller/I Gain'
//  '<S9>'   : 'ardupilot_controller_v1/Discrete PID Controller/Ideal P Gain'
//  '<S10>'  : 'ardupilot_controller_v1/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S11>'  : 'ardupilot_controller_v1/Discrete PID Controller/Integrator'
//  '<S12>'  : 'ardupilot_controller_v1/Discrete PID Controller/Integrator ICs'
//  '<S13>'  : 'ardupilot_controller_v1/Discrete PID Controller/N Copy'
//  '<S14>'  : 'ardupilot_controller_v1/Discrete PID Controller/N Gain'
//  '<S15>'  : 'ardupilot_controller_v1/Discrete PID Controller/P Copy'
//  '<S16>'  : 'ardupilot_controller_v1/Discrete PID Controller/Parallel P Gain'
//  '<S17>'  : 'ardupilot_controller_v1/Discrete PID Controller/Reset Signal'
//  '<S18>'  : 'ardupilot_controller_v1/Discrete PID Controller/Saturation'
//  '<S19>'  : 'ardupilot_controller_v1/Discrete PID Controller/Saturation Fdbk'
//  '<S20>'  : 'ardupilot_controller_v1/Discrete PID Controller/Sum'
//  '<S21>'  : 'ardupilot_controller_v1/Discrete PID Controller/Sum Fdbk'
//  '<S22>'  : 'ardupilot_controller_v1/Discrete PID Controller/Tracking Mode'
//  '<S23>'  : 'ardupilot_controller_v1/Discrete PID Controller/Tracking Mode Sum'
//  '<S24>'  : 'ardupilot_controller_v1/Discrete PID Controller/Tsamp - Integral'
//  '<S25>'  : 'ardupilot_controller_v1/Discrete PID Controller/Tsamp - Ngain'
//  '<S26>'  : 'ardupilot_controller_v1/Discrete PID Controller/postSat Signal'
//  '<S27>'  : 'ardupilot_controller_v1/Discrete PID Controller/preSat Signal'
//  '<S28>'  : 'ardupilot_controller_v1/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S29>'  : 'ardupilot_controller_v1/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S30>'  : 'ardupilot_controller_v1/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S31>'  : 'ardupilot_controller_v1/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S32>'  : 'ardupilot_controller_v1/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S33>'  : 'ardupilot_controller_v1/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S34>'  : 'ardupilot_controller_v1/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S35>'  : 'ardupilot_controller_v1/Discrete PID Controller/Integrator/Discrete'
//  '<S36>'  : 'ardupilot_controller_v1/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S37>'  : 'ardupilot_controller_v1/Discrete PID Controller/N Copy/Disabled'
//  '<S38>'  : 'ardupilot_controller_v1/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S39>'  : 'ardupilot_controller_v1/Discrete PID Controller/P Copy/Disabled'
//  '<S40>'  : 'ardupilot_controller_v1/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S41>'  : 'ardupilot_controller_v1/Discrete PID Controller/Reset Signal/Disabled'
//  '<S42>'  : 'ardupilot_controller_v1/Discrete PID Controller/Saturation/Passthrough'
//  '<S43>'  : 'ardupilot_controller_v1/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S44>'  : 'ardupilot_controller_v1/Discrete PID Controller/Sum/Sum_PID'
//  '<S45>'  : 'ardupilot_controller_v1/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S46>'  : 'ardupilot_controller_v1/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S47>'  : 'ardupilot_controller_v1/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S48>'  : 'ardupilot_controller_v1/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S49>'  : 'ardupilot_controller_v1/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S50>'  : 'ardupilot_controller_v1/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S51>'  : 'ardupilot_controller_v1/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S52>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Anti-windup'
//  '<S53>'  : 'ardupilot_controller_v1/Discrete PID Controller1/D Gain'
//  '<S54>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Filter'
//  '<S55>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Filter ICs'
//  '<S56>'  : 'ardupilot_controller_v1/Discrete PID Controller1/I Gain'
//  '<S57>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Ideal P Gain'
//  '<S58>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S59>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Integrator'
//  '<S60>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Integrator ICs'
//  '<S61>'  : 'ardupilot_controller_v1/Discrete PID Controller1/N Copy'
//  '<S62>'  : 'ardupilot_controller_v1/Discrete PID Controller1/N Gain'
//  '<S63>'  : 'ardupilot_controller_v1/Discrete PID Controller1/P Copy'
//  '<S64>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Parallel P Gain'
//  '<S65>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Reset Signal'
//  '<S66>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Saturation'
//  '<S67>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Saturation Fdbk'
//  '<S68>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Sum'
//  '<S69>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Sum Fdbk'
//  '<S70>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Tracking Mode'
//  '<S71>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Tracking Mode Sum'
//  '<S72>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Tsamp - Integral'
//  '<S73>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Tsamp - Ngain'
//  '<S74>'  : 'ardupilot_controller_v1/Discrete PID Controller1/postSat Signal'
//  '<S75>'  : 'ardupilot_controller_v1/Discrete PID Controller1/preSat Signal'
//  '<S76>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Anti-windup/Passthrough'
//  '<S77>'  : 'ardupilot_controller_v1/Discrete PID Controller1/D Gain/Internal Parameters'
//  '<S78>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S79>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S80>'  : 'ardupilot_controller_v1/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S81>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S82>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S83>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Integrator/Discrete'
//  '<S84>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S85>'  : 'ardupilot_controller_v1/Discrete PID Controller1/N Copy/Disabled'
//  '<S86>'  : 'ardupilot_controller_v1/Discrete PID Controller1/N Gain/Internal Parameters'
//  '<S87>'  : 'ardupilot_controller_v1/Discrete PID Controller1/P Copy/Disabled'
//  '<S88>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S89>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S90>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Saturation/Passthrough'
//  '<S91>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S92>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Sum/Sum_PID'
//  '<S93>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S94>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S95>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S96>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Tsamp - Integral/Passthrough'
//  '<S97>'  : 'ardupilot_controller_v1/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S98>'  : 'ardupilot_controller_v1/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S99>'  : 'ardupilot_controller_v1/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S100>' : 'ardupilot_controller_v1/Discrete PID Controller2/Anti-windup'
//  '<S101>' : 'ardupilot_controller_v1/Discrete PID Controller2/D Gain'
//  '<S102>' : 'ardupilot_controller_v1/Discrete PID Controller2/Filter'
//  '<S103>' : 'ardupilot_controller_v1/Discrete PID Controller2/Filter ICs'
//  '<S104>' : 'ardupilot_controller_v1/Discrete PID Controller2/I Gain'
//  '<S105>' : 'ardupilot_controller_v1/Discrete PID Controller2/Ideal P Gain'
//  '<S106>' : 'ardupilot_controller_v1/Discrete PID Controller2/Ideal P Gain Fdbk'
//  '<S107>' : 'ardupilot_controller_v1/Discrete PID Controller2/Integrator'
//  '<S108>' : 'ardupilot_controller_v1/Discrete PID Controller2/Integrator ICs'
//  '<S109>' : 'ardupilot_controller_v1/Discrete PID Controller2/N Copy'
//  '<S110>' : 'ardupilot_controller_v1/Discrete PID Controller2/N Gain'
//  '<S111>' : 'ardupilot_controller_v1/Discrete PID Controller2/P Copy'
//  '<S112>' : 'ardupilot_controller_v1/Discrete PID Controller2/Parallel P Gain'
//  '<S113>' : 'ardupilot_controller_v1/Discrete PID Controller2/Reset Signal'
//  '<S114>' : 'ardupilot_controller_v1/Discrete PID Controller2/Saturation'
//  '<S115>' : 'ardupilot_controller_v1/Discrete PID Controller2/Saturation Fdbk'
//  '<S116>' : 'ardupilot_controller_v1/Discrete PID Controller2/Sum'
//  '<S117>' : 'ardupilot_controller_v1/Discrete PID Controller2/Sum Fdbk'
//  '<S118>' : 'ardupilot_controller_v1/Discrete PID Controller2/Tracking Mode'
//  '<S119>' : 'ardupilot_controller_v1/Discrete PID Controller2/Tracking Mode Sum'
//  '<S120>' : 'ardupilot_controller_v1/Discrete PID Controller2/Tsamp - Integral'
//  '<S121>' : 'ardupilot_controller_v1/Discrete PID Controller2/Tsamp - Ngain'
//  '<S122>' : 'ardupilot_controller_v1/Discrete PID Controller2/postSat Signal'
//  '<S123>' : 'ardupilot_controller_v1/Discrete PID Controller2/preSat Signal'
//  '<S124>' : 'ardupilot_controller_v1/Discrete PID Controller2/Anti-windup/Passthrough'
//  '<S125>' : 'ardupilot_controller_v1/Discrete PID Controller2/D Gain/Internal Parameters'
//  '<S126>' : 'ardupilot_controller_v1/Discrete PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S127>' : 'ardupilot_controller_v1/Discrete PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S128>' : 'ardupilot_controller_v1/Discrete PID Controller2/I Gain/Internal Parameters'
//  '<S129>' : 'ardupilot_controller_v1/Discrete PID Controller2/Ideal P Gain/Passthrough'
//  '<S130>' : 'ardupilot_controller_v1/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S131>' : 'ardupilot_controller_v1/Discrete PID Controller2/Integrator/Discrete'
//  '<S132>' : 'ardupilot_controller_v1/Discrete PID Controller2/Integrator ICs/Internal IC'
//  '<S133>' : 'ardupilot_controller_v1/Discrete PID Controller2/N Copy/Disabled'
//  '<S134>' : 'ardupilot_controller_v1/Discrete PID Controller2/N Gain/Internal Parameters'
//  '<S135>' : 'ardupilot_controller_v1/Discrete PID Controller2/P Copy/Disabled'
//  '<S136>' : 'ardupilot_controller_v1/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S137>' : 'ardupilot_controller_v1/Discrete PID Controller2/Reset Signal/Disabled'
//  '<S138>' : 'ardupilot_controller_v1/Discrete PID Controller2/Saturation/Passthrough'
//  '<S139>' : 'ardupilot_controller_v1/Discrete PID Controller2/Saturation Fdbk/Disabled'
//  '<S140>' : 'ardupilot_controller_v1/Discrete PID Controller2/Sum/Sum_PID'
//  '<S141>' : 'ardupilot_controller_v1/Discrete PID Controller2/Sum Fdbk/Disabled'
//  '<S142>' : 'ardupilot_controller_v1/Discrete PID Controller2/Tracking Mode/Disabled'
//  '<S143>' : 'ardupilot_controller_v1/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S144>' : 'ardupilot_controller_v1/Discrete PID Controller2/Tsamp - Integral/Passthrough'
//  '<S145>' : 'ardupilot_controller_v1/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S146>' : 'ardupilot_controller_v1/Discrete PID Controller2/postSat Signal/Forward_Path'
//  '<S147>' : 'ardupilot_controller_v1/Discrete PID Controller2/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_ardupilot_controller_v1_h_

//
// File trailer for generated code.
//
// [EOF]
//
