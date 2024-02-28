//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ardupilot_controller_v1_model.h
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
#ifndef RTW_HEADER_ardupilot_controller_v1_model_h_
#define RTW_HEADER_ardupilot_controller_v1_model_h_
#include "rtwtypes.h"
#include "ardupilot_controller_v1_model_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ardupilot_controller_v1_model
class ardupilot_controller_v1_model final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_ardupilot_controller_v1_mo_T {
    real32_T Integrator_DSTATE;        // '<S83>/Integrator'
    real32_T Filter_DSTATE;            // '<S78>/Filter'
    real32_T Integrator_DSTATE_j;      // '<S35>/Integrator'
    real32_T Filter_DSTATE_d;          // '<S30>/Filter'
    real32_T Integrator_DSTATE_h;      // '<S131>/Integrator'
    real32_T Filter_DSTATE_c;          // '<S126>/Filter'
  };

  // Parameters (default storage)
  struct P_ardupilot_controller_v1_mod_T {
    real32_T RAT_PIT_D;                // Variable: RAT_PIT_D
                                          //  Referenced by: '<S29>/Derivative Gain'

    real32_T RAT_PIT_FF;               // Variable: RAT_PIT_FF
                                          //  Referenced by: '<Root>/Gain1'

    real32_T RAT_PIT_FLTD;             // Variable: RAT_PIT_FLTD
                                          //  Referenced by: '<S30>/Filter'

    real32_T RAT_PIT_FLTE;             // Variable: RAT_PIT_FLTE
                                          //  Referenced by: '<S35>/Integrator'

    real32_T RAT_PIT_I;                // Variable: RAT_PIT_I
                                          //  Referenced by: '<S32>/Integral Gain'

    real32_T RAT_PIT_IMAX;             // Variable: RAT_PIT_IMAX
                                          //  Referenced by: '<S35>/Integrator'

    real32_T RAT_PIT_P;                // Variable: RAT_PIT_P
                                          //  Referenced by: '<S40>/Proportional Gain'

    real32_T RAT_RLL_D;                // Variable: RAT_RLL_D
                                          //  Referenced by: '<S77>/Derivative Gain'

    real32_T RAT_RLL_FF;               // Variable: RAT_RLL_FF
                                          //  Referenced by: '<Root>/Gain'

    real32_T RAT_RLL_FLTD;             // Variable: RAT_RLL_FLTD
                                          //  Referenced by: '<S78>/Filter'

    real32_T RAT_RLL_FLTE;             // Variable: RAT_RLL_FLTE
                                          //  Referenced by: '<S83>/Integrator'

    real32_T RAT_RLL_I;                // Variable: RAT_RLL_I
                                          //  Referenced by: '<S80>/Integral Gain'

    real32_T RAT_RLL_IMAX;             // Variable: RAT_RLL_IMAX
                                          //  Referenced by: '<S83>/Integrator'

    real32_T RAT_RLL_P;                // Variable: RAT_RLL_P
                                          //  Referenced by: '<S88>/Proportional Gain'

    real32_T RAT_YAW_D;                // Variable: RAT_YAW_D
                                          //  Referenced by: '<S125>/Derivative Gain'

    real32_T RAT_YAW_FF;               // Variable: RAT_YAW_FF
                                          //  Referenced by: '<Root>/Gain2'

    real32_T RAT_YAW_FLTD;             // Variable: RAT_YAW_FLTD
                                          //  Referenced by: '<S126>/Filter'

    real32_T RAT_YAW_FLTE;             // Variable: RAT_YAW_FLTE
                                          //  Referenced by: '<S131>/Integrator'

    real32_T RAT_YAW_I;                // Variable: RAT_YAW_I
                                          //  Referenced by: '<S128>/Integral Gain'

    real32_T RAT_YAW_IMAX;             // Variable: RAT_YAW_IMAX
                                          //  Referenced by: '<S131>/Integrator'

    real32_T RAT_YAW_P;                // Variable: RAT_YAW_P
                                          //  Referenced by: '<S136>/Proportional Gain'

    real32_T DiscretePIDControllerRoll_Lower;
                              // Mask Parameter: DiscretePIDControllerRoll_Lower
                                 //  Referenced by: '<S83>/Integrator'

    real32_T DiscretePIDControllerPitch_Lowe;
                              // Mask Parameter: DiscretePIDControllerPitch_Lowe
                                 //  Referenced by: '<S35>/Integrator'

    real32_T DiscretePIDControllerYaw_LowerI;
                              // Mask Parameter: DiscretePIDControllerYaw_LowerI
                                 //  Referenced by: '<S131>/Integrator'

    real32_T DiscretePIDControllerRoll_N;
                                  // Mask Parameter: DiscretePIDControllerRoll_N
                                     //  Referenced by: '<S86>/Filter Coefficient'

    real32_T DiscretePIDControllerPitch_N;
                                 // Mask Parameter: DiscretePIDControllerPitch_N
                                    //  Referenced by: '<S38>/Filter Coefficient'

    real32_T DiscretePIDControllerYaw_N;
                                   // Mask Parameter: DiscretePIDControllerYaw_N
                                      //  Referenced by: '<S134>/Filter Coefficient'

    real32_T Integrator_gainval;       // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S83>/Integrator'

    real32_T Filter_gainval;           // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S78>/Filter'

    real32_T Integrator_gainval_i;   // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S35>/Integrator'

    real32_T Filter_gainval_f;         // Computed Parameter: Filter_gainval_f
                                          //  Referenced by: '<S30>/Filter'

    real32_T Integrator_gainval_a;   // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S131>/Integrator'

    real32_T Filter_gainval_c;         // Computed Parameter: Filter_gainval_c
                                          //  Referenced by: '<S126>/Filter'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_ardupilot_controller_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ardupilot_controller_v1_model(ardupilot_controller_v1_model const&) = delete;

  // Assignment Operator
  ardupilot_controller_v1_model& operator= (ardupilot_controller_v1_model const&)
    & = delete;

  // Move Constructor
  ardupilot_controller_v1_model(ardupilot_controller_v1_model &&) = delete;

  // Move Assignment Operator
  ardupilot_controller_v1_model& operator= (ardupilot_controller_v1_model &&) =
    delete;

  // Real-Time Model get method
  ardupilot_controller_v1_model::RT_MODEL_ardupilot_controller_T * getRTM();

  // Block states
  DW_ardupilot_controller_v1_mo_T ardupilot_controller_v1_mode_DW;

  // Tunable parameters
  static P_ardupilot_controller_v1_mod_T ardupilot_controller_v1_model_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T arg_attitude_error[3], real32_T arg_rate_ff[3], real32_T
            arg_rate_meas[3], real32_T (&arg_Output)[3]);

  // model terminate function
  static void terminate();

  // Constructor
  ardupilot_controller_v1_model();

  // Destructor
  ~ardupilot_controller_v1_model();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_ardupilot_controller_T ardupilot_controller_v1_mode_M;
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
//  '<Root>' : 'ardupilot_controller_v1_model'
//  '<S1>'   : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch'
//  '<S2>'   : 'ardupilot_controller_v1_model/Discrete PID Controller Roll'
//  '<S3>'   : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw'
//  '<S4>'   : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Anti-windup'
//  '<S5>'   : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/D Gain'
//  '<S6>'   : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Filter'
//  '<S7>'   : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Filter ICs'
//  '<S8>'   : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/I Gain'
//  '<S9>'   : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Ideal P Gain'
//  '<S10>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Ideal P Gain Fdbk'
//  '<S11>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Integrator'
//  '<S12>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Integrator ICs'
//  '<S13>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/N Copy'
//  '<S14>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/N Gain'
//  '<S15>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/P Copy'
//  '<S16>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Parallel P Gain'
//  '<S17>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Reset Signal'
//  '<S18>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Saturation'
//  '<S19>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Saturation Fdbk'
//  '<S20>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Sum'
//  '<S21>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Sum Fdbk'
//  '<S22>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Tracking Mode'
//  '<S23>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Tracking Mode Sum'
//  '<S24>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Tsamp - Integral'
//  '<S25>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Tsamp - Ngain'
//  '<S26>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/postSat Signal'
//  '<S27>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/preSat Signal'
//  '<S28>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Anti-windup/Passthrough'
//  '<S29>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/D Gain/Internal Parameters'
//  '<S30>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Filter/Disc. Forward Euler Filter'
//  '<S31>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Filter ICs/Internal IC - Filter'
//  '<S32>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/I Gain/Internal Parameters'
//  '<S33>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Ideal P Gain/Passthrough'
//  '<S34>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Ideal P Gain Fdbk/Disabled'
//  '<S35>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Integrator/Discrete'
//  '<S36>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Integrator ICs/Internal IC'
//  '<S37>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/N Copy/Disabled'
//  '<S38>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/N Gain/Internal Parameters'
//  '<S39>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/P Copy/Disabled'
//  '<S40>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Parallel P Gain/Internal Parameters'
//  '<S41>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Reset Signal/Disabled'
//  '<S42>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Saturation/Passthrough'
//  '<S43>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Saturation Fdbk/Disabled'
//  '<S44>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Sum/Sum_PID'
//  '<S45>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Sum Fdbk/Disabled'
//  '<S46>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Tracking Mode/Disabled'
//  '<S47>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Tracking Mode Sum/Passthrough'
//  '<S48>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Tsamp - Integral/Passthrough'
//  '<S49>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/Tsamp - Ngain/Passthrough'
//  '<S50>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/postSat Signal/Forward_Path'
//  '<S51>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Pitch/preSat Signal/Forward_Path'
//  '<S52>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Anti-windup'
//  '<S53>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/D Gain'
//  '<S54>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Filter'
//  '<S55>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Filter ICs'
//  '<S56>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/I Gain'
//  '<S57>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Ideal P Gain'
//  '<S58>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Ideal P Gain Fdbk'
//  '<S59>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Integrator'
//  '<S60>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Integrator ICs'
//  '<S61>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/N Copy'
//  '<S62>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/N Gain'
//  '<S63>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/P Copy'
//  '<S64>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Parallel P Gain'
//  '<S65>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Reset Signal'
//  '<S66>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Saturation'
//  '<S67>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Saturation Fdbk'
//  '<S68>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Sum'
//  '<S69>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Sum Fdbk'
//  '<S70>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Tracking Mode'
//  '<S71>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Tracking Mode Sum'
//  '<S72>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Tsamp - Integral'
//  '<S73>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Tsamp - Ngain'
//  '<S74>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/postSat Signal'
//  '<S75>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/preSat Signal'
//  '<S76>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Anti-windup/Passthrough'
//  '<S77>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/D Gain/Internal Parameters'
//  '<S78>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Filter/Disc. Forward Euler Filter'
//  '<S79>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Filter ICs/Internal IC - Filter'
//  '<S80>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/I Gain/Internal Parameters'
//  '<S81>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Ideal P Gain/Passthrough'
//  '<S82>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Ideal P Gain Fdbk/Disabled'
//  '<S83>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Integrator/Discrete'
//  '<S84>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Integrator ICs/Internal IC'
//  '<S85>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/N Copy/Disabled'
//  '<S86>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/N Gain/Internal Parameters'
//  '<S87>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/P Copy/Disabled'
//  '<S88>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Parallel P Gain/Internal Parameters'
//  '<S89>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Reset Signal/Disabled'
//  '<S90>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Saturation/Passthrough'
//  '<S91>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Saturation Fdbk/Disabled'
//  '<S92>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Sum/Sum_PID'
//  '<S93>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Sum Fdbk/Disabled'
//  '<S94>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Tracking Mode/Disabled'
//  '<S95>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Tracking Mode Sum/Passthrough'
//  '<S96>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Tsamp - Integral/Passthrough'
//  '<S97>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/Tsamp - Ngain/Passthrough'
//  '<S98>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/postSat Signal/Forward_Path'
//  '<S99>'  : 'ardupilot_controller_v1_model/Discrete PID Controller Roll/preSat Signal/Forward_Path'
//  '<S100>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Anti-windup'
//  '<S101>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/D Gain'
//  '<S102>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Filter'
//  '<S103>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Filter ICs'
//  '<S104>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/I Gain'
//  '<S105>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Ideal P Gain'
//  '<S106>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Ideal P Gain Fdbk'
//  '<S107>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Integrator'
//  '<S108>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Integrator ICs'
//  '<S109>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/N Copy'
//  '<S110>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/N Gain'
//  '<S111>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/P Copy'
//  '<S112>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Parallel P Gain'
//  '<S113>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Reset Signal'
//  '<S114>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Saturation'
//  '<S115>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Saturation Fdbk'
//  '<S116>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Sum'
//  '<S117>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Sum Fdbk'
//  '<S118>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Tracking Mode'
//  '<S119>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Tracking Mode Sum'
//  '<S120>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Tsamp - Integral'
//  '<S121>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Tsamp - Ngain'
//  '<S122>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/postSat Signal'
//  '<S123>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/preSat Signal'
//  '<S124>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Anti-windup/Passthrough'
//  '<S125>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/D Gain/Internal Parameters'
//  '<S126>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Filter/Disc. Forward Euler Filter'
//  '<S127>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Filter ICs/Internal IC - Filter'
//  '<S128>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/I Gain/Internal Parameters'
//  '<S129>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Ideal P Gain/Passthrough'
//  '<S130>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Ideal P Gain Fdbk/Disabled'
//  '<S131>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Integrator/Discrete'
//  '<S132>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Integrator ICs/Internal IC'
//  '<S133>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/N Copy/Disabled'
//  '<S134>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/N Gain/Internal Parameters'
//  '<S135>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/P Copy/Disabled'
//  '<S136>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Parallel P Gain/Internal Parameters'
//  '<S137>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Reset Signal/Disabled'
//  '<S138>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Saturation/Passthrough'
//  '<S139>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Saturation Fdbk/Disabled'
//  '<S140>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Sum/Sum_PID'
//  '<S141>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Sum Fdbk/Disabled'
//  '<S142>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Tracking Mode/Disabled'
//  '<S143>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Tracking Mode Sum/Passthrough'
//  '<S144>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Tsamp - Integral/Passthrough'
//  '<S145>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/Tsamp - Ngain/Passthrough'
//  '<S146>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/postSat Signal/Forward_Path'
//  '<S147>' : 'ardupilot_controller_v1_model/Discrete PID Controller Yaw/preSat Signal/Forward_Path'

#endif                           // RTW_HEADER_ardupilot_controller_v1_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
