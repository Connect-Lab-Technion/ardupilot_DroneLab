//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dmitry_model.h
//
// Code generated for Simulink model 'dmitry_model'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Jan  9 20:04:14 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_dmitry_model_h_
#define RTW_HEADER_dmitry_model_h_
#include "rtwtypes.h"
#include "dmitry_model_types.h"
#include <cstring>

extern "C"
{

#include "rtGetInf.h"

}

#include "rt_defines.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model dmitry_model
class dmitry_model final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_dmitry_model_T {
    real_T DiscreteTransferFcn_states; // '<S35>/Discrete Transfer Fcn'
    real_T Internal_DSTATE;            // '<S16>/Internal'
    real_T DiscreteTransferFcn_states_e;// '<S36>/Discrete Transfer Fcn'
    real_T Internal_DSTATE_g;          // '<S24>/Internal'
    real32_T Internal_DSTATE_m[2];     // '<S11>/Internal'
    real32_T Internal_DSTATE_h[2];     // '<S31>/Internal'
    real32_T Internal_DSTATE_a[2];     // '<S15>/Internal'
    real32_T Internal_DSTATE_l[2];     // '<S23>/Internal'
    real32_T DiscreteTransferFcn_states_n;// '<S42>/Discrete Transfer Fcn'
    real32_T Memory_PreviousInput;     // '<S2>/Memory'
  };

  // Parameters (default storage)
  struct P_dmitry_model_T {
    struct_OSJpyIZcrpXqReVWwh9iuG Vehicle;// Variable: Vehicle
                                             //  Referenced by: '<S5>/Constant'

    real_T KDphi;                      // Variable: KDphi
                                          //  Referenced by: '<S8>/KDphi'

    real_T KDtheta;                    // Variable: KDtheta
                                          //  Referenced by: '<S7>/KDtheta'

    real_T g;                          // Variable: g
                                          //  Referenced by:
                                          //    '<S37>/Constant'
                                          //    '<S5>/Constant'

    real_T w_c_pitch;                  // Variable: w_c_pitch
                                          //  Referenced by: '<S35>/Gain'

    real_T zDphi;                      // Variable: zDphi
                                          //  Referenced by: '<S8>/zDphi'

    real_T zDtheta;                    // Variable: zDtheta
                                          //  Referenced by: '<S7>/zDtheta'

    real32_T KDz;                      // Variable: KDz
                                          //  Referenced by: '<S5>/KDz'

    real32_T Ts;                       // Variable: Ts
                                          //  Referenced by: '<S40>/Gain'

    real32_T w_c_roll;                 // Variable: w_c_roll
                                          //  Referenced by: '<S36>/Gain'

    real32_T w_c_yaw;                  // Variable: w_c_yaw
                                          //  Referenced by: '<S42>/Gain'

    real32_T zDz;                      // Variable: zDz
                                          //  Referenced by: '<S5>/zDz'

    real_T yawequilibrium_Value;       // Expression: 0
                                          //  Referenced by: '<S4>/yaw equilibrium'

    real_T Constant_Value;             // Expression: 0
                                          //  Referenced by: '<S2>/Constant'

    real_T On1Off1foryaw_Gain;         // Expression: 0
                                          //  Referenced by: '<S4>/On=1//Off=1 for yaw'

    real_T pitchequilibrium_Value;     // Expression: 0
                                          //  Referenced by: '<S4>/pitch equilibrium'

    real_T DiscreteTransferFcn_NumCoef[2];// Expression: [num_pitch_disc]
                                             //  Referenced by: '<S35>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef[2];// Expression: [den_pitch_disc]
                                             //  Referenced by: '<S35>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                              //  Referenced by: '<S35>/Discrete Transfer Fcn'

    real_T Internal_A;                 // Computed Parameter: Internal_A
                                          //  Referenced by: '<S16>/Internal'

    real_T Internal_B;                 // Computed Parameter: Internal_B
                                          //  Referenced by: '<S16>/Internal'

    real_T Internal_C;                 // Computed Parameter: Internal_C
                                          //  Referenced by: '<S16>/Internal'

    real_T Internal_D;                 // Computed Parameter: Internal_D
                                          //  Referenced by: '<S16>/Internal'

    real_T Internal_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S16>/Internal'

    real_T ChangingofJyy_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jyy'

    real_T On1Off2forpitch_Gain;       // Expression: 1
                                          //  Referenced by: '<S4>/On=1//Off=2 for pitch'

    real_T rollequilibrium_Value;      // Expression: 0
                                          //  Referenced by: '<S4>/roll equilibrium'

    real_T DiscreteTransferFcn_NumCoef_a[2];// Expression: [num_roll_disc]
                                               //  Referenced by: '<S36>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef_o[2];// Expression: [den_roll_disc]
                                               //  Referenced by: '<S36>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialSt_g;// Expression: 0
                                              //  Referenced by: '<S36>/Discrete Transfer Fcn'

    real_T Internal_A_l;               // Computed Parameter: Internal_A_l
                                          //  Referenced by: '<S24>/Internal'

    real_T Internal_B_e;               // Computed Parameter: Internal_B_e
                                          //  Referenced by: '<S24>/Internal'

    real_T Internal_C_g;               // Computed Parameter: Internal_C_g
                                          //  Referenced by: '<S24>/Internal'

    real_T Internal_D_h;               // Computed Parameter: Internal_D_h
                                          //  Referenced by: '<S24>/Internal'

    real_T Internal_InitialCondition_n;// Expression: 0
                                          //  Referenced by: '<S24>/Internal'

    real_T ChangingofJxx_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jxx'

    real_T On1Off1forroll_Gain;        // Expression: 0
                                          //  Referenced by: '<S4>/On=1//Off=1 for roll'

    real_T Gain_Gain;                  // Expression: -1
                                          //  Referenced by: '<S37>/Gain'

    real32_T DiscreteTransferFcn_NumCoef_j[2];
                            // Computed Parameter: DiscreteTransferFcn_NumCoef_j
                               //  Referenced by: '<S42>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_DenCoef_a[2];
                            // Computed Parameter: DiscreteTransferFcn_DenCoef_a
                               //  Referenced by: '<S42>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_InitialSt_a;
                          // Computed Parameter: DiscreteTransferFcn_InitialSt_a
                             //  Referenced by: '<S42>/Discrete Transfer Fcn'

    real32_T TorqueTotalThrustToThrustPerMot[16];// Expression: Controller.Q2Ts
                                                    //  Referenced by: '<S6>/TorqueTotalThrustToThrustPerMotor'

    real32_T Internal_A_n[3];          // Computed Parameter: Internal_A_n
                                          //  Referenced by: '<S11>/Internal'

    real32_T Internal_B_c;             // Computed Parameter: Internal_B_c
                                          //  Referenced by: '<S11>/Internal'

    real32_T Internal_C_n[2];          // Computed Parameter: Internal_C_n
                                          //  Referenced by: '<S11>/Internal'

    real32_T Internal_InitialCondition_e;
                              // Computed Parameter: Internal_InitialCondition_e
                                 //  Referenced by: '<S11>/Internal'

    real32_T SaturationThrust_UpperSat;
                                // Computed Parameter: SaturationThrust_UpperSat
                                   //  Referenced by: '<S5>/SaturationThrust'

    real32_T SaturationThrust_LowerSat;
                                // Computed Parameter: SaturationThrust_LowerSat
                                   //  Referenced by: '<S5>/SaturationThrust'

    real32_T On1Off0forthrust_Gain; // Computed Parameter: On1Off0forthrust_Gain
                                       //  Referenced by: '<S4>/On=1//Off=0 for thrust'

    real32_T uThrustoff_Gain;          // Computed Parameter: uThrustoff_Gain
                                          //  Referenced by: '<S4>/0 = Thrust off'

    real32_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S2>/Memory'

    real32_T Internal_A_d[3];          // Computed Parameter: Internal_A_d
                                          //  Referenced by: '<S31>/Internal'

    real32_T Internal_B_f;             // Computed Parameter: Internal_B_f
                                          //  Referenced by: '<S31>/Internal'

    real32_T Internal_C_a[2];          // Computed Parameter: Internal_C_a
                                          //  Referenced by: '<S31>/Internal'

    real32_T Internal_InitialCondition_p;
                              // Computed Parameter: Internal_InitialCondition_p
                                 //  Referenced by: '<S31>/Internal'

    real32_T zDpsi_Gain;               // Computed Parameter: zDpsi_Gain
                                          //  Referenced by: '<S9>/zDpsi'

    real32_T KDpsi_Gain;               // Computed Parameter: KDpsi_Gain
                                          //  Referenced by: '<S9>/KDpsi'

    real32_T ChangingofJzz_Gain;       // Computed Parameter: ChangingofJzz_Gain
                                          //  Referenced by: '<S4>/Changing of Jzz'

    real32_T Internal_A_j[3];          // Computed Parameter: Internal_A_j
                                          //  Referenced by: '<S15>/Internal'

    real32_T Internal_B_k;             // Computed Parameter: Internal_B_k
                                          //  Referenced by: '<S15>/Internal'

    real32_T Internal_C_i[2];          // Computed Parameter: Internal_C_i
                                          //  Referenced by: '<S15>/Internal'

    real32_T Internal_InitialCondition_ps;
                             // Computed Parameter: Internal_InitialCondition_ps
                                //  Referenced by: '<S15>/Internal'

    real32_T Internal_A_a[3];          // Computed Parameter: Internal_A_a
                                          //  Referenced by: '<S23>/Internal'

    real32_T Internal_B_h;             // Computed Parameter: Internal_B_h
                                          //  Referenced by: '<S23>/Internal'

    real32_T Internal_C_c[2];          // Computed Parameter: Internal_C_c
                                          //  Referenced by: '<S23>/Internal'

    real32_T Internal_InitialCondition_c;
                              // Computed Parameter: Internal_InitialCondition_c
                                 //  Referenced by: '<S23>/Internal'

    real32_T ThrustToMotorCommand_Gain;
                                // Computed Parameter: ThrustToMotorCommand_Gain
                                   //  Referenced by: '<S10>/ThrustToMotorCommand'

    real32_T Saturation5_UpperSat;     // Expression: Vehicle.Motor.maxLimit
                                          //  Referenced by: '<S10>/Saturation5'

    real32_T Saturation5_LowerSat;     // Expression: Vehicle.Motor.minLimit
                                          //  Referenced by: '<S10>/Saturation5'

    real32_T MotorDirections_Gain[4];// Computed Parameter: MotorDirections_Gain
                                        //  Referenced by: '<S10>/MotorDirections'

    real32_T Gain1_Gain;               // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S37>/Gain1'

    real32_T Gain2_Gain;               // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S37>/Gain2'

    real32_T Gain3_Gain;               // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S37>/Gain3'

    real32_T Gain_Gain_i;              // Computed Parameter: Gain_Gain_i
                                          //  Referenced by: '<S38>/Gain'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_dmitry_model_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  dmitry_model(dmitry_model const&) = delete;

  // Assignment Operator
  dmitry_model& operator= (dmitry_model const&) & = delete;

  // Move Constructor
  dmitry_model(dmitry_model &&) = delete;

  // Move Assignment Operator
  dmitry_model& operator= (dmitry_model &&) = delete;

  // Real-Time Model get method
  dmitry_model::RT_MODEL_dmitry_model_T * getRTM();

  // Block states
  DW_dmitry_model_T dmitry_model_DW;

  // Tunable parameters
  static P_dmitry_model_T dmitry_model_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T arg_accel[3], real32_T arg_gyro[3], real32_T *arg_bat_V,
            real32_T arg_pos_est[3], real32_T arg_vel_est[3], real32_T
            *arg_yaw_opticalfow, real32_T arg_pos_ref[3], real32_T
            arg_orient_ref[3], real32_T arg_Out1[4]);

  // model terminate function
  static void terminate();

  // Constructor
  dmitry_model();

  // Destructor
  ~dmitry_model();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_dmitry_model_T dmitry_model_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S38>/Divide1' : Unused code path elimination
//  Block '<S38>/Divide2' : Unused code path elimination
//  Block '<S38>/Product8' : Unused code path elimination
//  Block '<S38>/Product9' : Unused code path elimination
//  Block '<S38>/Sum2' : Unused code path elimination
//  Block '<S38>/Trigonometric Function3' : Unused code path elimination
//  Block '<S5>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S5>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S4>/Cast To Single2' : Eliminate redundant data type conversion
//  Block '<S7>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S7>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S8>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S8>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S37>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S37>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S37>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S37>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S38>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S38>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S38>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S38>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S38>/Zero-Order Hold4' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'dmitry_model'
//  '<S1>'   : 'dmitry_model/Controller'
//  '<S2>'   : 'dmitry_model/Estimator'
//  '<S3>'   : 'dmitry_model/bus_prep'
//  '<S4>'   : 'dmitry_model/Controller/Flight Controller'
//  '<S5>'   : 'dmitry_model/Controller/Flight Controller/Altitude Controller'
//  '<S6>'   : 'dmitry_model/Controller/Flight Controller/ControlMixer'
//  '<S7>'   : 'dmitry_model/Controller/Flight Controller/Pitch Controller'
//  '<S8>'   : 'dmitry_model/Controller/Flight Controller/Roll Controller'
//  '<S9>'   : 'dmitry_model/Controller/Flight Controller/Yaw Controller'
//  '<S10>'  : 'dmitry_model/Controller/Flight Controller/thrustsToMotorCommands'
//  '<S11>'  : 'dmitry_model/Controller/Flight Controller/Altitude Controller/LTI System5'
//  '<S12>'  : 'dmitry_model/Controller/Flight Controller/Altitude Controller/LTI System5/IO Delay'
//  '<S13>'  : 'dmitry_model/Controller/Flight Controller/Altitude Controller/LTI System5/Input Delay'
//  '<S14>'  : 'dmitry_model/Controller/Flight Controller/Altitude Controller/LTI System5/Output Delay'
//  '<S15>'  : 'dmitry_model/Controller/Flight Controller/Pitch Controller/LTI System5'
//  '<S16>'  : 'dmitry_model/Controller/Flight Controller/Pitch Controller/PI'
//  '<S17>'  : 'dmitry_model/Controller/Flight Controller/Pitch Controller/LTI System5/IO Delay'
//  '<S18>'  : 'dmitry_model/Controller/Flight Controller/Pitch Controller/LTI System5/Input Delay'
//  '<S19>'  : 'dmitry_model/Controller/Flight Controller/Pitch Controller/LTI System5/Output Delay'
//  '<S20>'  : 'dmitry_model/Controller/Flight Controller/Pitch Controller/PI/IO Delay'
//  '<S21>'  : 'dmitry_model/Controller/Flight Controller/Pitch Controller/PI/Input Delay'
//  '<S22>'  : 'dmitry_model/Controller/Flight Controller/Pitch Controller/PI/Output Delay'
//  '<S23>'  : 'dmitry_model/Controller/Flight Controller/Roll Controller/LTI System5'
//  '<S24>'  : 'dmitry_model/Controller/Flight Controller/Roll Controller/PI'
//  '<S25>'  : 'dmitry_model/Controller/Flight Controller/Roll Controller/LTI System5/IO Delay'
//  '<S26>'  : 'dmitry_model/Controller/Flight Controller/Roll Controller/LTI System5/Input Delay'
//  '<S27>'  : 'dmitry_model/Controller/Flight Controller/Roll Controller/LTI System5/Output Delay'
//  '<S28>'  : 'dmitry_model/Controller/Flight Controller/Roll Controller/PI/IO Delay'
//  '<S29>'  : 'dmitry_model/Controller/Flight Controller/Roll Controller/PI/Input Delay'
//  '<S30>'  : 'dmitry_model/Controller/Flight Controller/Roll Controller/PI/Output Delay'
//  '<S31>'  : 'dmitry_model/Controller/Flight Controller/Yaw Controller/LTI System5'
//  '<S32>'  : 'dmitry_model/Controller/Flight Controller/Yaw Controller/LTI System5/IO Delay'
//  '<S33>'  : 'dmitry_model/Controller/Flight Controller/Yaw Controller/LTI System5/Input Delay'
//  '<S34>'  : 'dmitry_model/Controller/Flight Controller/Yaw Controller/LTI System5/Output Delay'
//  '<S35>'  : 'dmitry_model/Estimator/Complementary Filter for Pitch (disc.)'
//  '<S36>'  : 'dmitry_model/Estimator/Complementary Filter for Roll (disc.)'
//  '<S37>'  : 'dmitry_model/Estimator/Roll and Pitch Angles (Lecture 2, slide 39)'
//  '<S38>'  : 'dmitry_model/Estimator/Roll, Pitch, and Yaw Rates (Lecture1, slide 22)1'
//  '<S39>'  : 'dmitry_model/Estimator/yaw estimator'
//  '<S40>'  : 'dmitry_model/Estimator/yaw estimator/If Action Subsystem3'
//  '<S41>'  : 'dmitry_model/Estimator/yaw estimator/If Action Subsystem'
//  '<S42>'  : 'dmitry_model/Estimator/yaw estimator/If Action Subsystem/Complementary Filter for Yaw (disc.)'

#endif                                 // RTW_HEADER_dmitry_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
