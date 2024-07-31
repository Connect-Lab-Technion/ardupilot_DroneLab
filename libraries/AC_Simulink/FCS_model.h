//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.h
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.39
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Jul 31 08:29:29 2024
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

#include "rtGetInf.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

#include "zero_crossing_types.h"

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
  // Block signals (default storage)
  struct B_FCS_model_T {
    real_T Product2[4];                // '<S91>/Product2'
    real_T Product3[4];                // '<S89>/Product3'
    real32_T position[3];              // '<S104>/position'
    real32_T u;                        // '<S103>/1'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_FCS_model_T {
    real_T MemoryX_DSTATE[4];          // '<S39>/MemoryX'
    real32_T DiscreteTransferFcn_states;// '<S93>/Discrete Transfer Fcn'
    real32_T DiscreteTransferFcn_states_e;// '<S94>/Discrete Transfer Fcn'
    real32_T Internal_DSTATE[2];       // '<S12>/Internal'
    real32_T Internal_DSTATE_h[2];     // '<S32>/Internal'
    real32_T Internal_DSTATE_a[2];     // '<S16>/Internal'
    real32_T Internal_DSTATE_g;        // '<S17>/Internal'
    real32_T Internal_DSTATE_l[2];     // '<S24>/Internal'
    real32_T Internal_DSTATE_gs;       // '<S25>/Internal'
    real32_T DiscreteTransferFcn_states_n;// '<S100>/Discrete Transfer Fcn'
    real32_T Memory_PreviousInput;     // '<S37>/Memory'
    boolean_T icLoad;                  // '<S39>/MemoryX'
    boolean_T EnabledSubsystem_MODE;   // '<S66>/Enabled Subsystem'
    boolean_T MeasurementUpdate_MODE;  // '<S60>/MeasurementUpdate'
  };

  // Zero-crossing (trigger) state
  struct PrevZCX_FCS_model_T {
    ZCSigState TriggeredSubsystem_Trig_ZCE;// '<S102>/Triggered Subsystem'
    ZCSigState TriggeredSubsystem_Trig_ZCE_d;// '<S101>/Triggered Subsystem'
  };

  // Parameters (default storage)
  struct P_FCS_model_T {
    struct_p4xwbJBU4TOx0OKqnGpJsD Sensors;// Variable: Sensors
                                             //  Referenced by: '<S38>/prsToAltGain'

    real32_T KDz;                      // Variable: KDz
                                          //  Referenced by: '<S5>/KDz'

    real32_T Ts;                       // Variable: Ts
                                          //  Referenced by: '<S98>/Gain'

    real32_T w_c_pitch;                // Variable: w_c_pitch
                                          //  Referenced by: '<S93>/Gain'

    real32_T w_c_roll;                 // Variable: w_c_roll
                                          //  Referenced by: '<S94>/Gain'

    real32_T w_c_yaw;                  // Variable: w_c_yaw
                                          //  Referenced by: '<S100>/Gain'

    real32_T zDz;                      // Variable: zDz
                                          //  Referenced by: '<S5>/zDz'

    real_T Constant_Value[4];          // Expression: [0 0 0 0]
                                          //  Referenced by: '<S9>/Constant'

    real_T Lykyhatkk1_Y0;              // Expression: 0
                                          //  Referenced by: '<S89>/L*(y[k]-yhat[k|k-1])'

    real_T deltax_Y0;                  // Expression: 0
                                          //  Referenced by: '<S91>/deltax'

    real_T A_Value[16];                // Expression: pInitialization.A
                                          //  Referenced by: '<S39>/A'

    real_T KalmanGainM_Value[12];      // Expression: pInitialization.M
                                          //  Referenced by: '<S41>/KalmanGainM'

    real_T C_Value[12];                // Expression: pInitialization.C
                                          //  Referenced by: '<S39>/C'

    real_T KalmanGainL_Value[12];      // Expression: pInitialization.L
                                          //  Referenced by: '<S41>/KalmanGainL'

    real_T Constant_Value_a;           // Expression: 1
                                          //  Referenced by: '<S37>/Constant'

    real_T X0_Value[4];                // Expression: pInitialization.X0
                                          //  Referenced by: '<S39>/X0'

    real_T Constant_Value_n;           // Expression: 0
                                          //  Referenced by: '<S38>/Constant'

    real_T gravity_Value[3];           // Expression: [0 0 g]
                                          //  Referenced by: '<S38>/gravity'

    real_T Constant1_Value;            // Expression: (Vehicle.Airframe.mass)*g
                                          //  Referenced by: '<S5>/Constant1'

    real_T yawequilibrium_Value;       // Expression: 0
                                          //  Referenced by: '<S1>/yaw equilibrium'

    real_T On1Off1foryaw_Gain;         // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=1 for yaw'

    real_T pitchequilibrium_Value;     // Expression: 0
                                          //  Referenced by: '<S1>/pitch equilibrium'

    real_T On1Off2forpitch_Gain;       // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=2 for pitch'

    real_T rollequilibrium_Value;      // Expression: 0
                                          //  Referenced by: '<S1>/roll equilibrium'

    real_T On1Off1forroll_Gain;        // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=1 for roll'

    real_T D_Value[3];                 // Expression: pInitialization.D
                                          //  Referenced by: '<S39>/D'

    real_T u_Value;                    // Expression: 0
                                          //  Referenced by: '<S39>/u'

    real_T B_Value[4];                 // Expression: pInitialization.B
                                          //  Referenced by: '<S39>/B'

    real_T CovarianceZ_Value[16];      // Expression: pInitialization.Z
                                          //  Referenced by: '<S41>/CovarianceZ'

    real32_T TorqueTotalThrustToThrustPerMot[16];// Expression: Controller.Q2Ts
                                                    //  Referenced by: '<S6>/TorqueTotalThrustToThrustPerMotor'

    real32_T uDLookupTable2_tableData[10];
                                 // Computed Parameter: uDLookupTable2_tableData
                                    //  Referenced by: '<S11>/1-D Lookup Table2'

    real32_T uDLookupTable2_bp01Data[10];
                                  // Computed Parameter: uDLookupTable2_bp01Data
                                     //  Referenced by: '<S11>/1-D Lookup Table2'

    real32_T Saturation_UpperSat;     // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S9>/Saturation'

    real32_T Saturation_LowerSat;     // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S9>/Saturation'

    real32_T DiscreteTransferFcn_NumCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_NumCoef
                                 //  Referenced by: '<S100>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_DenCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_DenCoef
                                 //  Referenced by: '<S100>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_InitialStat;
                          // Computed Parameter: DiscreteTransferFcn_InitialStat
                             //  Referenced by: '<S100>/Discrete Transfer Fcn'

    real32_T baro_0_Y0;                // Computed Parameter: baro_0_Y0
                                          //  Referenced by: '<S103>/baro_0'

    real32_T Out1_Y0[3];               // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S104>/Out1'

    real32_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S37>/Memory'

    real32_T DiscreteTransferFcn_NumCoef_n[2];
                            // Computed Parameter: DiscreteTransferFcn_NumCoef_n
                               //  Referenced by: '<S93>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_DenCoef_n[2];
                            // Computed Parameter: DiscreteTransferFcn_DenCoef_n
                               //  Referenced by: '<S93>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_InitialSt_c;
                          // Computed Parameter: DiscreteTransferFcn_InitialSt_c
                             //  Referenced by: '<S93>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_NumCoef_a[2];
                            // Computed Parameter: DiscreteTransferFcn_NumCoef_a
                               //  Referenced by: '<S94>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_DenCoef_o[2];
                            // Computed Parameter: DiscreteTransferFcn_DenCoef_o
                               //  Referenced by: '<S94>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_InitialSt_g;
                          // Computed Parameter: DiscreteTransferFcn_InitialSt_g
                             //  Referenced by: '<S94>/Discrete Transfer Fcn'

    real32_T RangfinderScaleGain1_Gain;
                                // Computed Parameter: RangfinderScaleGain1_Gain
                                   //  Referenced by: '<S38>/RangfinderScaleGain1'

    real32_T Internal_A[3];            // Computed Parameter: Internal_A
                                          //  Referenced by: '<S12>/Internal'

    real32_T Internal_B;               // Computed Parameter: Internal_B
                                          //  Referenced by: '<S12>/Internal'

    real32_T Internal_C[2];            // Computed Parameter: Internal_C
                                          //  Referenced by: '<S12>/Internal'

    real32_T Internal_InitialCondition;
                                // Computed Parameter: Internal_InitialCondition
                                   //  Referenced by: '<S12>/Internal'

    real32_T Gain_Gain;                // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S5>/Gain'

    real32_T WithControl1WithoutControl0_Gai;
                          // Computed Parameter: WithControl1WithoutControl0_Gai
                             //  Referenced by: '<S5>/WithControl=1 WithoutControl=0'

    real32_T SaturationThrust_UpperSat;
                                // Computed Parameter: SaturationThrust_UpperSat
                                   //  Referenced by: '<S5>/SaturationThrust'

    real32_T SaturationThrust_LowerSat;
                                // Computed Parameter: SaturationThrust_LowerSat
                                   //  Referenced by: '<S5>/SaturationThrust'

    real32_T On1Off0forthrust_Gain; // Computed Parameter: On1Off0forthrust_Gain
                                       //  Referenced by: '<S1>/On=1//Off=0 for thrust'

    real32_T Internal_A_d[3];          // Computed Parameter: Internal_A_d
                                          //  Referenced by: '<S32>/Internal'

    real32_T Internal_B_f;             // Computed Parameter: Internal_B_f
                                          //  Referenced by: '<S32>/Internal'

    real32_T Internal_C_a[2];          // Computed Parameter: Internal_C_a
                                          //  Referenced by: '<S32>/Internal'

    real32_T Internal_InitialCondition_p;
                              // Computed Parameter: Internal_InitialCondition_p
                                 //  Referenced by: '<S32>/Internal'

    real32_T zDpsi_Gain;               // Computed Parameter: zDpsi_Gain
                                          //  Referenced by: '<S10>/zDpsi'

    real32_T KDpsi_Gain;               // Computed Parameter: KDpsi_Gain
                                          //  Referenced by: '<S10>/KDpsi'

    real32_T ChangingofJzz_Gain;       // Computed Parameter: ChangingofJzz_Gain
                                          //  Referenced by: '<S1>/Changing of Jzz'

    real32_T Internal_A_j[3];          // Computed Parameter: Internal_A_j
                                          //  Referenced by: '<S16>/Internal'

    real32_T Internal_B_k;             // Computed Parameter: Internal_B_k
                                          //  Referenced by: '<S16>/Internal'

    real32_T Internal_C_i[2];          // Computed Parameter: Internal_C_i
                                          //  Referenced by: '<S16>/Internal'

    real32_T Internal_InitialCondition_ps;
                             // Computed Parameter: Internal_InitialCondition_ps
                                //  Referenced by: '<S16>/Internal'

    real32_T Internal_A_f;             // Computed Parameter: Internal_A_f
                                          //  Referenced by: '<S17>/Internal'

    real32_T Internal_B_b;             // Computed Parameter: Internal_B_b
                                          //  Referenced by: '<S17>/Internal'

    real32_T Internal_C_ai;            // Computed Parameter: Internal_C_ai
                                          //  Referenced by: '<S17>/Internal'

    real32_T Internal_D_e;             // Computed Parameter: Internal_D_e
                                          //  Referenced by: '<S17>/Internal'

    real32_T Internal_InitialCondition_l;
                              // Computed Parameter: Internal_InitialCondition_l
                                 //  Referenced by: '<S17>/Internal'

    real32_T zDtheta_Gain;             // Computed Parameter: zDtheta_Gain
                                          //  Referenced by: '<S7>/zDtheta'

    real32_T KDtheta_Gain;             // Computed Parameter: KDtheta_Gain
                                          //  Referenced by: '<S7>/KDtheta'

    real32_T ChangingofJyy_Gain;       // Computed Parameter: ChangingofJyy_Gain
                                          //  Referenced by: '<S1>/Changing of Jyy'

    real32_T Internal_A_a[3];          // Computed Parameter: Internal_A_a
                                          //  Referenced by: '<S24>/Internal'

    real32_T Internal_B_h;             // Computed Parameter: Internal_B_h
                                          //  Referenced by: '<S24>/Internal'

    real32_T Internal_C_c[2];          // Computed Parameter: Internal_C_c
                                          //  Referenced by: '<S24>/Internal'

    real32_T Internal_InitialCondition_c;
                              // Computed Parameter: Internal_InitialCondition_c
                                 //  Referenced by: '<S24>/Internal'

    real32_T Internal_A_l;             // Computed Parameter: Internal_A_l
                                          //  Referenced by: '<S25>/Internal'

    real32_T Internal_B_e;             // Computed Parameter: Internal_B_e
                                          //  Referenced by: '<S25>/Internal'

    real32_T Internal_C_g;             // Computed Parameter: Internal_C_g
                                          //  Referenced by: '<S25>/Internal'

    real32_T Internal_D_h;             // Computed Parameter: Internal_D_h
                                          //  Referenced by: '<S25>/Internal'

    real32_T Internal_InitialCondition_n;
                              // Computed Parameter: Internal_InitialCondition_n
                                 //  Referenced by: '<S25>/Internal'

    real32_T zDphi_Gain;               // Computed Parameter: zDphi_Gain
                                          //  Referenced by: '<S8>/zDphi'

    real32_T KDphi_Gain;               // Computed Parameter: KDphi_Gain
                                          //  Referenced by: '<S8>/KDphi'

    real32_T ChangingofJxx_Gain;       // Computed Parameter: ChangingofJxx_Gain
                                          //  Referenced by: '<S1>/Changing of Jxx'

    real32_T Gain1_Gain;               // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S95>/Gain1'

    real32_T Constant_Value_o;         // Expression: g
                                          //  Referenced by: '<S95>/Constant'

    real32_T Gain2_Gain;               // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S95>/Gain2'

    real32_T Gain3_Gain;               // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S95>/Gain3'

    real32_T Gain_Gain_i;              // Computed Parameter: Gain_Gain_i
                                          //  Referenced by: '<S96>/Gain'

    boolean_T isSqrtUsed_Value;        // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S87>/isSqrtUsed'

    uint8_T Switch_Threshold;          // Computed Parameter: Switch_Threshold
                                          //  Referenced by: '<S9>/Switch'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_FCS_model_T {
    const char_T * volatile errorStatus;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
    } Timing;
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

  // Block signals
  B_FCS_model_T FCS_model_B;

  // Block states
  DW_FCS_model_T FCS_model_DW;

  // Tunable parameters
  static P_FCS_model_T FCS_model_P;

  // Triggered events
  PrevZCX_FCS_model_T FCS_model_PrevZCX;

  // model initialize function
  void initialize();

  // model step function
  void step(uint8_T *arg_switch, real32_T *arg_gain, real32_T arg_accel[3],
            real32_T arg_gyro[3], real32_T *arg_bat_V, real32_T arg_flowRate[2],
            real32_T *arg_baro, real32_T *arg_rangefinder, real32_T arg_pos_est
            [3], real32_T arg_vel_est[3], real32_T *arg_yaw, real32_T
            arg_pos_ref[3], real32_T arg_orient_ref[3], real32_T
            arg_motors_refout[4], real32_T arg_logging_refout[40]);

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
//  Block '<S1>/Constant' : Unused code path elimination
//  Block '<S82>/Data Type Duplicate' : Unused code path elimination
//  Block '<S83>/Data Type Duplicate' : Unused code path elimination
//  Block '<S84>/Conversion' : Unused code path elimination
//  Block '<S84>/Data Type Duplicate' : Unused code path elimination
//  Block '<S85>/Data Type Duplicate' : Unused code path elimination
//  Block '<S42>/Product' : Unused code path elimination
//  Block '<S44>/Data Type Duplicate' : Unused code path elimination
//  Block '<S45>/Data Type Duplicate' : Unused code path elimination
//  Block '<S46>/Data Type Duplicate' : Unused code path elimination
//  Block '<S47>/Data Type Duplicate' : Unused code path elimination
//  Block '<S48>/Data Type Duplicate' : Unused code path elimination
//  Block '<S49>/Data Type Duplicate' : Unused code path elimination
//  Block '<S50>/Data Type Duplicate' : Unused code path elimination
//  Block '<S51>/Conversion' : Unused code path elimination
//  Block '<S51>/Data Type Duplicate' : Unused code path elimination
//  Block '<S52>/Data Type Duplicate' : Unused code path elimination
//  Block '<S53>/Data Type Duplicate' : Unused code path elimination
//  Block '<S54>/Data Type Duplicate' : Unused code path elimination
//  Block '<S56>/Data Type Duplicate' : Unused code path elimination
//  Block '<S57>/Data Type Duplicate' : Unused code path elimination
//  Block '<S58>/Data Type Duplicate' : Unused code path elimination
//  Block '<S39>/G' : Unused code path elimination
//  Block '<S39>/H' : Unused code path elimination
//  Block '<S39>/N' : Unused code path elimination
//  Block '<S39>/P0' : Unused code path elimination
//  Block '<S39>/Q' : Unused code path elimination
//  Block '<S39>/R' : Unused code path elimination
//  Block '<S39>/Reshapeyhat' : Unused code path elimination
//  Block '<S71>/CheckSignalProperties' : Unused code path elimination
//  Block '<S81>/CheckSignalProperties' : Unused code path elimination
//  Block '<S96>/Divide1' : Unused code path elimination
//  Block '<S96>/Divide2' : Unused code path elimination
//  Block '<S96>/Product8' : Unused code path elimination
//  Block '<S96>/Product9' : Unused code path elimination
//  Block '<S96>/Sum2' : Unused code path elimination
//  Block '<S96>/Trigonometric Function3' : Unused code path elimination
//  Block '<S5>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S5>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S7>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S7>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S8>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S8>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S36>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S38>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S82>/Conversion' : Eliminate redundant data type conversion
//  Block '<S83>/Conversion' : Eliminate redundant data type conversion
//  Block '<S85>/Conversion' : Eliminate redundant data type conversion
//  Block '<S56>/Conversion' : Eliminate redundant data type conversion
//  Block '<S60>/Reshape' : Reshape block reduction
//  Block '<S39>/ReshapeX0' : Reshape block reduction
//  Block '<S39>/Reshapeu' : Reshape block reduction
//  Block '<S39>/Reshapexhat' : Reshape block reduction
//  Block '<S92>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S95>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S95>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S95>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S95>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S96>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S96>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S96>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S96>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S96>/Zero-Order Hold4' : Eliminated since input and output rates are identical
//  Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion8' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion9' : Eliminate redundant data type conversion


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
//  '<S2>'   : 'FCS_model/Estimatiors'
//  '<S3>'   : 'FCS_model/Logging'
//  '<S4>'   : 'FCS_model/bus_prep'
//  '<S5>'   : 'FCS_model/Controller/Altitude Controller'
//  '<S6>'   : 'FCS_model/Controller/ControlMixer'
//  '<S7>'   : 'FCS_model/Controller/Pitch Controller'
//  '<S8>'   : 'FCS_model/Controller/Roll Controller'
//  '<S9>'   : 'FCS_model/Controller/Subsystem'
//  '<S10>'  : 'FCS_model/Controller/Yaw Controller'
//  '<S11>'  : 'FCS_model/Controller/thrustsToMotorCommands'
//  '<S12>'  : 'FCS_model/Controller/Altitude Controller/LTI System5'
//  '<S13>'  : 'FCS_model/Controller/Altitude Controller/LTI System5/IO Delay'
//  '<S14>'  : 'FCS_model/Controller/Altitude Controller/LTI System5/Input Delay'
//  '<S15>'  : 'FCS_model/Controller/Altitude Controller/LTI System5/Output Delay'
//  '<S16>'  : 'FCS_model/Controller/Pitch Controller/LTI System5'
//  '<S17>'  : 'FCS_model/Controller/Pitch Controller/PI'
//  '<S18>'  : 'FCS_model/Controller/Pitch Controller/LTI System5/IO Delay'
//  '<S19>'  : 'FCS_model/Controller/Pitch Controller/LTI System5/Input Delay'
//  '<S20>'  : 'FCS_model/Controller/Pitch Controller/LTI System5/Output Delay'
//  '<S21>'  : 'FCS_model/Controller/Pitch Controller/PI/IO Delay'
//  '<S22>'  : 'FCS_model/Controller/Pitch Controller/PI/Input Delay'
//  '<S23>'  : 'FCS_model/Controller/Pitch Controller/PI/Output Delay'
//  '<S24>'  : 'FCS_model/Controller/Roll Controller/LTI System5'
//  '<S25>'  : 'FCS_model/Controller/Roll Controller/PI'
//  '<S26>'  : 'FCS_model/Controller/Roll Controller/LTI System5/IO Delay'
//  '<S27>'  : 'FCS_model/Controller/Roll Controller/LTI System5/Input Delay'
//  '<S28>'  : 'FCS_model/Controller/Roll Controller/LTI System5/Output Delay'
//  '<S29>'  : 'FCS_model/Controller/Roll Controller/PI/IO Delay'
//  '<S30>'  : 'FCS_model/Controller/Roll Controller/PI/Input Delay'
//  '<S31>'  : 'FCS_model/Controller/Roll Controller/PI/Output Delay'
//  '<S32>'  : 'FCS_model/Controller/Yaw Controller/LTI System5'
//  '<S33>'  : 'FCS_model/Controller/Yaw Controller/LTI System5/IO Delay'
//  '<S34>'  : 'FCS_model/Controller/Yaw Controller/LTI System5/Input Delay'
//  '<S35>'  : 'FCS_model/Controller/Yaw Controller/LTI System5/Output Delay'
//  '<S36>'  : 'FCS_model/Estimatiors/Altitude Estimation'
//  '<S37>'  : 'FCS_model/Estimatiors/Attitude Estimation'
//  '<S38>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1'
//  '<S39>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude'
//  '<S40>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/Rotation Angles to Direction Cosine Matrix'
//  '<S41>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CalculatePL'
//  '<S42>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CalculateYhat'
//  '<S43>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CovarianceOutputConfigurator'
//  '<S44>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionA'
//  '<S45>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionB'
//  '<S46>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionC'
//  '<S47>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionD'
//  '<S48>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionG'
//  '<S49>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionH'
//  '<S50>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionN'
//  '<S51>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionP'
//  '<S52>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionP0'
//  '<S53>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionQ'
//  '<S54>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionR'
//  '<S55>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionReset'
//  '<S56>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionX'
//  '<S57>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionX0'
//  '<S58>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/DataTypeConversionu'
//  '<S59>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/MemoryP'
//  '<S60>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/Observer'
//  '<S61>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/ReducedQRN'
//  '<S62>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/Reset'
//  '<S63>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/ScalarExpansionP0'
//  '<S64>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/ScalarExpansionQ'
//  '<S65>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/ScalarExpansionR'
//  '<S66>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/UseCurrentEstimator'
//  '<S67>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkA'
//  '<S68>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkB'
//  '<S69>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkC'
//  '<S70>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkD'
//  '<S71>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkEnable'
//  '<S72>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkG'
//  '<S73>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkH'
//  '<S74>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkN'
//  '<S75>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkP0'
//  '<S76>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkQ'
//  '<S77>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkR'
//  '<S78>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkReset'
//  '<S79>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checkX0'
//  '<S80>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checku'
//  '<S81>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/checky'
//  '<S82>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CalculatePL/DataTypeConversionL'
//  '<S83>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CalculatePL/DataTypeConversionM'
//  '<S84>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CalculatePL/DataTypeConversionP'
//  '<S85>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CalculatePL/DataTypeConversionZ'
//  '<S86>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CalculatePL/Ground'
//  '<S87>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CovarianceOutputConfigurator/decideOutput'
//  '<S88>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S89>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/Observer/MeasurementUpdate'
//  '<S90>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/ReducedQRN/Ground'
//  '<S91>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/KalmanFilter_altitude/UseCurrentEstimator/Enabled Subsystem'
//  '<S92>'  : 'FCS_model/Estimatiors/Altitude Estimation/EstimatorAltitude1/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S93>'  : 'FCS_model/Estimatiors/Attitude Estimation/Complementary Filter for Pitch (disc.)'
//  '<S94>'  : 'FCS_model/Estimatiors/Attitude Estimation/Complementary Filter for Roll (disc.)'
//  '<S95>'  : 'FCS_model/Estimatiors/Attitude Estimation/Roll and Pitch Angles (Lecture 2, slide 39)'
//  '<S96>'  : 'FCS_model/Estimatiors/Attitude Estimation/Roll, Pitch, and Yaw Rates (Lecture1, slide 22)1'
//  '<S97>'  : 'FCS_model/Estimatiors/Attitude Estimation/yaw estimator'
//  '<S98>'  : 'FCS_model/Estimatiors/Attitude Estimation/yaw estimator/If Action Subsystem3'
//  '<S99>'  : 'FCS_model/Estimatiors/Attitude Estimation/yaw estimator/If Action Subsystem'
//  '<S100>' : 'FCS_model/Estimatiors/Attitude Estimation/yaw estimator/If Action Subsystem/Complementary Filter for Yaw (disc.)'
//  '<S101>' : 'FCS_model/bus_prep/master_switch_zero_baro'
//  '<S102>' : 'FCS_model/bus_prep/master_switch_zero_position'
//  '<S103>' : 'FCS_model/bus_prep/master_switch_zero_baro/Triggered Subsystem'
//  '<S104>' : 'FCS_model/bus_prep/master_switch_zero_position/Triggered Subsystem'

#endif                                 // RTW_HEADER_FCS_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
