//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.h
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 5.21
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Apr 18 15:33:46 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_FCS_model_h_
#define RTW_HEADER_FCS_model_h_
#include "rtwtypes.h"
#include "FCS_model_types.h"
#include <cstring>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include "rt_defines.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model FCS_model
class FCS_model final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_FCS_model_T {
    real_T DiscreteTransferFcn_states; // '<S36>/Discrete Transfer Fcn'
    real_T DiscreteTransferFcn_states_e;// '<S37>/Discrete Transfer Fcn'
    real_T Internal_DSTATE[2];         // '<S12>/Internal'
    real_T Internal_DSTATE_h[2];       // '<S32>/Internal'
    real_T Internal_DSTATE_a[2];       // '<S16>/Internal'
    real_T Internal_DSTATE_g;          // '<S17>/Internal'
    real_T Internal_DSTATE_l[2];       // '<S24>/Internal'
    real_T Internal_DSTATE_gs;         // '<S25>/Internal'
    real_T DiscreteTransferFcn_states_n;// '<S43>/Discrete Transfer Fcn'
    real_T Memory_PreviousInput;       // '<S2>/Memory'
  };

  // Parameters (default storage)
  struct P_FCS_model_T {
    struct_OSJpyIZcrpXqReVWwh9iuG Vehicle;// Variable: Vehicle
                                             //  Referenced by: '<S6>/Constant1'

    real_T KDphi;                      // Variable: KDphi
                                          //  Referenced by: '<S9>/KDphi'

    real_T KDpsi;                      // Variable: KDpsi
                                          //  Referenced by: '<S10>/KDpsi'

    real_T KDtheta;                    // Variable: KDtheta
                                          //  Referenced by: '<S8>/KDtheta'

    real_T KDz;                        // Variable: KDz
                                          //  Referenced by: '<S6>/KDz'

    real_T Ts;                         // Variable: Ts
                                          //  Referenced by: '<S41>/Gain'

    real_T g;                          // Variable: g
                                          //  Referenced by:
                                          //    '<S38>/Constant'
                                          //    '<S6>/Constant1'

    real_T w_c_pitch;                  // Variable: w_c_pitch
                                          //  Referenced by: '<S36>/Gain'

    real_T w_c_roll;                   // Variable: w_c_roll
                                          //  Referenced by: '<S37>/Gain'

    real_T w_c_yaw;                    // Variable: w_c_yaw
                                          //  Referenced by: '<S43>/Gain'

    real_T zDphi;                      // Variable: zDphi
                                          //  Referenced by: '<S9>/zDphi'

    real_T zDpsi;                      // Variable: zDpsi
                                          //  Referenced by: '<S10>/zDpsi'

    real_T zDtheta;                    // Variable: zDtheta
                                          //  Referenced by: '<S8>/zDtheta'

    real_T zDz;                        // Variable: zDz
                                          //  Referenced by: '<S6>/zDz'

    real_T DiscreteTransferFcn_NumCoef[2];// Expression: [num_yaw_disc]
                                             //  Referenced by: '<S43>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef[2];// Expression: [den_yaw_disc]
                                             //  Referenced by: '<S43>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                              //  Referenced by: '<S43>/Discrete Transfer Fcn'

    real_T Constant_Value;             // Expression: 0
                                          //  Referenced by: '<S2>/Constant'

    real_T Memory_InitialCondition;    // Expression: 0
                                          //  Referenced by: '<S2>/Memory'

    real_T DiscreteTransferFcn_NumCoef_n[2];// Expression: [num_pitch_disc]
                                               //  Referenced by: '<S36>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef_n[2];// Expression: [den_pitch_disc]
                                               //  Referenced by: '<S36>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialSt_c;// Expression: 0
                                              //  Referenced by: '<S36>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_NumCoef_a[2];// Expression: [num_roll_disc]
                                               //  Referenced by: '<S37>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef_o[2];// Expression: [den_roll_disc]
                                               //  Referenced by: '<S37>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialSt_g;// Expression: 0
                                              //  Referenced by: '<S37>/Discrete Transfer Fcn'

    real_T Internal_A[3];              // Computed Parameter: Internal_A
                                          //  Referenced by: '<S12>/Internal'

    real_T Internal_B;                 // Computed Parameter: Internal_B
                                          //  Referenced by: '<S12>/Internal'

    real_T Internal_C[2];              // Computed Parameter: Internal_C
                                          //  Referenced by: '<S12>/Internal'

    real_T Internal_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S12>/Internal'

    real_T yawequilibrium_Value;       // Expression: 0
                                          //  Referenced by: '<S5>/yaw equilibrium'

    real_T Internal_A_d[3];            // Computed Parameter: Internal_A_d
                                          //  Referenced by: '<S32>/Internal'

    real_T Internal_B_f;               // Computed Parameter: Internal_B_f
                                          //  Referenced by: '<S32>/Internal'

    real_T Internal_C_a[2];            // Computed Parameter: Internal_C_a
                                          //  Referenced by: '<S32>/Internal'

    real_T Internal_InitialCondition_p;// Expression: 0
                                          //  Referenced by: '<S32>/Internal'

    real_T ChangingofJzz_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S5>/Changing of Jzz'

    real_T On1Off1foryaw_Gain;         // Expression: 0
                                          //  Referenced by: '<S5>/On=1//Off=1 for yaw'

    real_T pitchequilibrium_Value;     // Expression: 0
                                          //  Referenced by: '<S5>/pitch equilibrium'

    real_T Internal_A_j[3];            // Computed Parameter: Internal_A_j
                                          //  Referenced by: '<S16>/Internal'

    real_T Internal_B_k;               // Computed Parameter: Internal_B_k
                                          //  Referenced by: '<S16>/Internal'

    real_T Internal_C_i[2];            // Computed Parameter: Internal_C_i
                                          //  Referenced by: '<S16>/Internal'

    real_T Internal_InitialCondition_ps;// Expression: 0
                                           //  Referenced by: '<S16>/Internal'

    real_T Internal_A_f;               // Computed Parameter: Internal_A_f
                                          //  Referenced by: '<S17>/Internal'

    real_T Internal_B_b;               // Computed Parameter: Internal_B_b
                                          //  Referenced by: '<S17>/Internal'

    real_T Internal_C_ai;              // Computed Parameter: Internal_C_ai
                                          //  Referenced by: '<S17>/Internal'

    real_T Internal_D_e;               // Computed Parameter: Internal_D_e
                                          //  Referenced by: '<S17>/Internal'

    real_T Internal_InitialCondition_l;// Expression: 0
                                          //  Referenced by: '<S17>/Internal'

    real_T ChangingofJyy_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S5>/Changing of Jyy'

    real_T On1Off2forpitch_Gain;       // Expression: 1
                                          //  Referenced by: '<S5>/On=1//Off=2 for pitch'

    real_T rollequilibrium_Value;      // Expression: 0
                                          //  Referenced by: '<S5>/roll equilibrium'

    real_T Internal_A_a[3];            // Computed Parameter: Internal_A_a
                                          //  Referenced by: '<S24>/Internal'

    real_T Internal_B_h;               // Computed Parameter: Internal_B_h
                                          //  Referenced by: '<S24>/Internal'

    real_T Internal_C_c[2];            // Computed Parameter: Internal_C_c
                                          //  Referenced by: '<S24>/Internal'

    real_T Internal_InitialCondition_c;// Expression: 0
                                          //  Referenced by: '<S24>/Internal'

    real_T Internal_A_l;               // Computed Parameter: Internal_A_l
                                          //  Referenced by: '<S25>/Internal'

    real_T Internal_B_e;               // Computed Parameter: Internal_B_e
                                          //  Referenced by: '<S25>/Internal'

    real_T Internal_C_g;               // Computed Parameter: Internal_C_g
                                          //  Referenced by: '<S25>/Internal'

    real_T Internal_D_h;               // Computed Parameter: Internal_D_h
                                          //  Referenced by: '<S25>/Internal'

    real_T Internal_InitialCondition_n;// Expression: 0
                                          //  Referenced by: '<S25>/Internal'

    real_T ChangingofJxx_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S5>/Changing of Jxx'

    real_T On1Off1forroll_Gain;        // Expression: 0
                                          //  Referenced by: '<S5>/On=1//Off=1 for roll'

    real_T Gain2_Gain;                 // Expression: -1
                                          //  Referenced by: '<S38>/Gain2'

    real_T Gain3_Gain;                 // Expression: -1
                                          //  Referenced by: '<S38>/Gain3'

    real_T Gain4_Gain;                 // Expression: -1
                                          //  Referenced by: '<S38>/Gain4'

    real_T Gain1_Gain;                 // Expression: -1
                                          //  Referenced by: '<S38>/Gain1'

    real_T Gain_Gain;                  // Expression: -1
                                          //  Referenced by: '<S39>/Gain'

    real32_T TorqueTotalThrustToThrustPerMot[16];// Expression: Controller.Q2Ts
                                                    //  Referenced by: '<S7>/TorqueTotalThrustToThrustPerMotor'

    real32_T SaturationThrust_UpperSat;
                                // Computed Parameter: SaturationThrust_UpperSat
                                   //  Referenced by: '<S6>/SaturationThrust'

    real32_T SaturationThrust_LowerSat;
                                // Computed Parameter: SaturationThrust_LowerSat
                                   //  Referenced by: '<S6>/SaturationThrust'

    real32_T On1Off0forthrust_Gain; // Computed Parameter: On1Off0forthrust_Gain
                                       //  Referenced by: '<S5>/On=1//Off=0 for thrust'

    real32_T Gain_Gain_n;              // Computed Parameter: Gain_Gain_n
                                          //  Referenced by: '<S11>/Gain'

    real32_T uDLookupTable_tableData[9];
                                  // Computed Parameter: uDLookupTable_tableData
                                     //  Referenced by: '<S11>/1-D Lookup Table'

    real32_T uDLookupTable_bp01Data[9];
                                   // Computed Parameter: uDLookupTable_bp01Data
                                      //  Referenced by: '<S11>/1-D Lookup Table'

    real32_T Saturation_UpperSat;     // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S11>/Saturation'

    real32_T Saturation_LowerSat;     // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S11>/Saturation'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_FCS_model_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  FCS_model(FCS_model const&) = delete;

  // Assignment Operator
  FCS_model& operator= (FCS_model const&) & = delete;

  // Move Constructor
  FCS_model(FCS_model &&) = delete;

  // Move Assignment Operator
  FCS_model& operator= (FCS_model &&) = delete;

  // Real-Time Model get method
  FCS_model::RT_MODEL_FCS_model_T * getRTM();

  // Block states
  DW_FCS_model_T FCS_model_DW;

  // Tunable parameters
  static P_FCS_model_T FCS_model_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T arg_accel[3], real32_T arg_gyro[3], real32_T *arg_bat_V,
            real32_T arg_pos_est[3], real32_T arg_vel_est[3], real32_T
            *arg_yaw_opticalfow, real32_T arg_pos_ref[3], real32_T
            arg_orient_ref[3], real32_T arg_motors_refout[4], real32_T
            arg_logging_refout[22]);

  // model terminate function
  static void terminate();

  // Constructor
  FCS_model();

  // Destructor
  ~FCS_model();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_FCS_model_T FCS_model_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S11>/KV [rpm//V]' : Unused code path elimination
//  Block '<S11>/K_tau [Nm//A]' : Unused code path elimination
//  Block '<S39>/Divide1' : Unused code path elimination
//  Block '<S39>/Divide2' : Unused code path elimination
//  Block '<S39>/Product8' : Unused code path elimination
//  Block '<S39>/Product9' : Unused code path elimination
//  Block '<S39>/Sum2' : Unused code path elimination
//  Block '<S39>/Trigonometric Function3' : Unused code path elimination
//  Block '<S4>/Data Type Conversion3' : Unused code path elimination
//  Block '<S6>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S6>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S5>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S8>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S8>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S38>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S38>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S38>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S38>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S39>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S39>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S39>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S39>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S39>/Zero-Order Hold4' : Eliminated since input and output rates are identical
//  Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion8' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion9' : Eliminate redundant data type conversion


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
//  '<Root>' : 'FCS_model'
//  '<S1>'   : 'FCS_model/Controller'
//  '<S2>'   : 'FCS_model/Estimator'
//  '<S3>'   : 'FCS_model/Logging'
//  '<S4>'   : 'FCS_model/bus_prep'
//  '<S5>'   : 'FCS_model/Controller/Flight Controller'
//  '<S6>'   : 'FCS_model/Controller/Flight Controller/Altitude Controller'
//  '<S7>'   : 'FCS_model/Controller/Flight Controller/ControlMixer'
//  '<S8>'   : 'FCS_model/Controller/Flight Controller/Pitch Controller'
//  '<S9>'   : 'FCS_model/Controller/Flight Controller/Roll Controller'
//  '<S10>'  : 'FCS_model/Controller/Flight Controller/Yaw Controller'
//  '<S11>'  : 'FCS_model/Controller/Flight Controller/thrustsToMotorCommands'
//  '<S12>'  : 'FCS_model/Controller/Flight Controller/Altitude Controller/LTI System5'
//  '<S13>'  : 'FCS_model/Controller/Flight Controller/Altitude Controller/LTI System5/IO Delay'
//  '<S14>'  : 'FCS_model/Controller/Flight Controller/Altitude Controller/LTI System5/Input Delay'
//  '<S15>'  : 'FCS_model/Controller/Flight Controller/Altitude Controller/LTI System5/Output Delay'
//  '<S16>'  : 'FCS_model/Controller/Flight Controller/Pitch Controller/LTI System5'
//  '<S17>'  : 'FCS_model/Controller/Flight Controller/Pitch Controller/PI'
//  '<S18>'  : 'FCS_model/Controller/Flight Controller/Pitch Controller/LTI System5/IO Delay'
//  '<S19>'  : 'FCS_model/Controller/Flight Controller/Pitch Controller/LTI System5/Input Delay'
//  '<S20>'  : 'FCS_model/Controller/Flight Controller/Pitch Controller/LTI System5/Output Delay'
//  '<S21>'  : 'FCS_model/Controller/Flight Controller/Pitch Controller/PI/IO Delay'
//  '<S22>'  : 'FCS_model/Controller/Flight Controller/Pitch Controller/PI/Input Delay'
//  '<S23>'  : 'FCS_model/Controller/Flight Controller/Pitch Controller/PI/Output Delay'
//  '<S24>'  : 'FCS_model/Controller/Flight Controller/Roll Controller/LTI System5'
//  '<S25>'  : 'FCS_model/Controller/Flight Controller/Roll Controller/PI'
//  '<S26>'  : 'FCS_model/Controller/Flight Controller/Roll Controller/LTI System5/IO Delay'
//  '<S27>'  : 'FCS_model/Controller/Flight Controller/Roll Controller/LTI System5/Input Delay'
//  '<S28>'  : 'FCS_model/Controller/Flight Controller/Roll Controller/LTI System5/Output Delay'
//  '<S29>'  : 'FCS_model/Controller/Flight Controller/Roll Controller/PI/IO Delay'
//  '<S30>'  : 'FCS_model/Controller/Flight Controller/Roll Controller/PI/Input Delay'
//  '<S31>'  : 'FCS_model/Controller/Flight Controller/Roll Controller/PI/Output Delay'
//  '<S32>'  : 'FCS_model/Controller/Flight Controller/Yaw Controller/LTI System5'
//  '<S33>'  : 'FCS_model/Controller/Flight Controller/Yaw Controller/LTI System5/IO Delay'
//  '<S34>'  : 'FCS_model/Controller/Flight Controller/Yaw Controller/LTI System5/Input Delay'
//  '<S35>'  : 'FCS_model/Controller/Flight Controller/Yaw Controller/LTI System5/Output Delay'
//  '<S36>'  : 'FCS_model/Estimator/Complementary Filter for Pitch (disc.)'
//  '<S37>'  : 'FCS_model/Estimator/Complementary Filter for Roll (disc.)'
//  '<S38>'  : 'FCS_model/Estimator/Roll and Pitch Angles (Lecture 2, slide 39)'
//  '<S39>'  : 'FCS_model/Estimator/Roll, Pitch, and Yaw Rates (Lecture1, slide 22)1'
//  '<S40>'  : 'FCS_model/Estimator/yaw estimator'
//  '<S41>'  : 'FCS_model/Estimator/yaw estimator/If Action Subsystem3'
//  '<S42>'  : 'FCS_model/Estimator/yaw estimator/If Action Subsystem'
//  '<S43>'  : 'FCS_model/Estimator/yaw estimator/If Action Subsystem/Complementary Filter for Yaw (disc.)'

#endif                                 // RTW_HEADER_FCS_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
