//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.h
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 11.6
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr  8 15:47:50 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FCS_model_h_
#define FCS_model_h_
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

#include "zero_crossing_types.h"

// Class declaration for model FCS_model
class FCS_model
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_FCS_model_T {
    real_T Probe[2];                   // '<S123>/Probe'
    real_T Probe_c[2];                 // '<S116>/Probe'
    real_T Product2[4];                // '<S183>/Product2'
    real_T Product3[4];                // '<S181>/Product3'
    real_T Product2_c[2];              // '<S113>/Product2'
    real_T Product3_d[2];              // '<S111>/Product3'
    real_T signal_out;                 // '<S24>/takeoff_acceleration'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_FCS_model_T {
    real_T DiscreteTransferFcn_states; // '<S186>/Discrete Transfer Fcn'
    real_T FIR_IMUaccel_states[15];    // '<S3>/FIR_IMUaccel'
    real_T DiscreteTransferFcn_states_a;// '<S185>/Discrete Transfer Fcn'
    real_T DiscreteFilter1_states[3];  // '<S131>/Discrete Filter1'
    real_T MemoryX_DSTATE[4];          // '<S132>/MemoryX'
    real_T MemoryX_DSTATE_o[2];        // '<S42>/MemoryX'
    real_T IIRgyroz_states[10];        // '<S41>/IIRgyroz'
    real_T UD_DSTATE[2];               // '<S49>/UD'
    real_T Delay_DSTATE[2];            // '<S36>/Delay'
    real_T Integrator_DSTATE;          // '<S129>/Integrator'
    real_T Delay2_DSTATE[40];          // '<S43>/Delay2'
    real_T Integrator_DSTATE_e;        // '<S122>/Integrator'
    real_T Delay1_DSTATE[40];          // '<S43>/Delay1'
    real_T SimplyIntegrateVelocity_DSTATE[2];// '<S35>/SimplyIntegrateVelocity'
    real_T Internal_DSTATE;            // '<S11>/Internal'
    real_T Internal_DSTATE_f[2];       // '<S17>/Internal'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S9>/Discrete-Time Integrator'
    real_T Internal_DSTATE_k[2];       // '<S14>/Internal'
    real_T DiscreteTimeIntegrator_DSTATE_o;// '<S31>/Discrete-Time Integrator'
    real_T DiscreteTransferFcn_states_p;// '<S192>/Discrete Transfer Fcn'
    real_T Memory_PreviousInput;       // '<S33>/Memory'
    int32_T FIR_IMUaccel_circBuf;      // '<S3>/FIR_IMUaccel'
    int8_T Integrator_PrevResetState;  // '<S129>/Integrator'
    int8_T Integrator_PrevResetState_e;// '<S122>/Integrator'
    uint8_T Integrator_IC_LOADING;     // '<S129>/Integrator'
    uint8_T Integrator_IC_LOADING_g;   // '<S122>/Integrator'
    uint8_T is_active_c1_FCS_model;    // '<S24>/takeoff_acceleration'
    uint8_T is_c1_FCS_model;           // '<S24>/takeoff_acceleration'
    boolean_T icLoad;                  // '<S132>/MemoryX'
    boolean_T icLoad_n;                // '<S42>/MemoryX'
    boolean_T Memory_PreviousInput_j;  // '<S24>/Memory'
    boolean_T EnabledSubsystem_MODE;   // '<S158>/Enabled Subsystem'
    boolean_T MeasurementUpdate_MODE;  // '<S153>/MeasurementUpdate'
    boolean_T EnabledSubsystem_MODE_g; // '<S87>/Enabled Subsystem'
    boolean_T MeasurementUpdate_MODE_h;// '<S80>/MeasurementUpdate'
  };

  // Zero-crossing (trigger) state
  struct PrevZCX_FCS_model_T {
    ZCSigState MemoryX_Reset_ZCE;      // '<S132>/MemoryX'
  };

  // Parameters (default storage)
  struct P_FCS_model_T {
    struct_UHvAqkoSM4a4grTGLmN7a Vehicle;// Variable: Vehicle
                                            //  Referenced by: '<S29>/Saturation'

    real_T KDpsi;                      // Variable: KDpsi
                                          //  Referenced by: '<S10>/KDpsi'

    real_T KDtheta;                    // Variable: KDtheta
                                          //  Referenced by: '<S8>/KDtheta'

    real_T Ts;                         // Variable: Ts
                                          //  Referenced by:
                                          //    '<S24>/Ts'
                                          //    '<S190>/Gain'

    real_T g;                          // Variable: g
                                          //  Referenced by: '<S187>/Constant'

    real_T kd_rol;                     // Variable: kd_rol
                                          //  Referenced by: '<S9>/kd_rol'

    real_T ki_rol;                     // Variable: ki_rol
                                          //  Referenced by: '<S9>/ki_rol'

    real_T kp_rol;                     // Variable: kp_rol
                                          //  Referenced by: '<S9>/kp_rol'

    real_T sensorCalibrationData[8];   // Variable: sensorCalibrationData
                                          //  Referenced by: '<Root>/Constant'

    real_T w_c_pitch;                  // Variable: w_c_pitch
                                          //  Referenced by: '<S185>/Gain'

    real_T w_c_roll;                   // Variable: w_c_roll
                                          //  Referenced by: '<S186>/Gain'

    real_T w_c_yaw;                    // Variable: w_c_yaw
                                          //  Referenced by: '<S192>/Gain'

    real_T zDpsi;                      // Variable: zDpsi
                                          //  Referenced by: '<S10>/zDpsi'

    real_T zDtheta;                    // Variable: zDtheta
                                          //  Referenced by: '<S8>/zDtheta'

    real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S49>/UD'

    real_T LowPassFilterDiscreteorContinuo;
                              // Mask Parameter: LowPassFilterDiscreteorContinuo
                                 //  Referenced by: '<S115>/K'

    real_T LowPassFilterDiscreteorContin_d;
                              // Mask Parameter: LowPassFilterDiscreteorContin_d
                                 //  Referenced by: '<S114>/K'

    real_T LowPassFilterDiscreteorContin_l;
                              // Mask Parameter: LowPassFilterDiscreteorContin_l
                                 //  Referenced by: '<S123>/Time constant'

    real_T LowPassFilterDiscreteorContin_a;
                              // Mask Parameter: LowPassFilterDiscreteorContin_a
                                 //  Referenced by: '<S116>/Time constant'

    real_T maxp_const;                 // Mask Parameter: maxp_const
                                          //  Referenced by: '<S52>/Constant'

    real_T maxq_const;                 // Mask Parameter: maxq_const
                                          //  Referenced by: '<S54>/Constant'

    real_T maxw1_const;                // Mask Parameter: maxw1_const
                                          //  Referenced by: '<S56>/Constant'

    real_T maxw2_const;                // Mask Parameter: maxw2_const
                                          //  Referenced by: '<S57>/Constant'

    real_T maxdw1_const;               // Mask Parameter: maxdw1_const
                                          //  Referenced by: '<S50>/Constant'

    real_T maxdw2_const;               // Mask Parameter: maxdw2_const
                                          //  Referenced by: '<S51>/Constant'

    real_T maxp2_const;                // Mask Parameter: maxp2_const
                                          //  Referenced by: '<S53>/Constant'

    real_T maxq2_const;                // Mask Parameter: maxq2_const
                                          //  Referenced by: '<S55>/Constant'

    real_T maxw3_const;                // Mask Parameter: maxw3_const
                                          //  Referenced by: '<S58>/Constant'

    real_T maxw4_const;                // Mask Parameter: maxw4_const
                                          //  Referenced by: '<S59>/Constant'

    real_T minHeightforOF_const;       // Mask Parameter: minHeightforOF_const
                                          //  Referenced by: '<S60>/Constant'

    real_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S126>/Constant'

    real_T CompareToConstant_const_p;
                                    // Mask Parameter: CompareToConstant_const_p
                                       //  Referenced by: '<S119>/Constant'

    real_T DeactivateAccelerationIfOFisnot;
                              // Mask Parameter: DeactivateAccelerationIfOFisnot
                                 //  Referenced by: '<S44>/Constant'

    real_T donotuseaccifopticalflowneverav;
                              // Mask Parameter: donotuseaccifopticalflowneverav
                                 //  Referenced by: '<S46>/Constant'

    real_T donotuseaccifopticalflownever_c;
                              // Mask Parameter: donotuseaccifopticalflownever_c
                                 //  Referenced by: '<S47>/Constant'

    real_T LowPassFilterDiscreteorContin_i;
                              // Mask Parameter: LowPassFilterDiscreteorContin_i
                                 //  Referenced by: '<S123>/Constant'

    real_T LowPassFilterDiscreteorConti_d0;
                              // Mask Parameter: LowPassFilterDiscreteorConti_d0
                                 //  Referenced by: '<S116>/Constant'

    real_T Lykyhatkk1_Y0;              // Expression: 0
                                          //  Referenced by: '<S111>/L*(y[k]-yhat[k|k-1])'

    real_T deltax_Y0;                  // Expression: 0
                                          //  Referenced by: '<S113>/deltax'

    real_T Lykyhatkk1_Y0_c;            // Expression: 0
                                          //  Referenced by: '<S181>/L*(y[k]-yhat[k|k-1])'

    real_T deltax_Y0_k;                // Expression: 0
                                          //  Referenced by: '<S183>/deltax'

    real_T DiscreteTransferFcn_NumCoef[2];// Expression: [num_yaw_disc]
                                             //  Referenced by: '<S192>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef[2];// Expression: [den_yaw_disc]
                                             //  Referenced by: '<S192>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                              //  Referenced by: '<S192>/Discrete Transfer Fcn'

    real_T Constant_Value;             // Expression: 0
                                          //  Referenced by: '<S120>/Constant'

    real_T Constant_Value_o;           // Expression: 0
                                          //  Referenced by: '<S127>/Constant'

    real_T A_Value[16];                // Expression: pInitialization.A
                                          //  Referenced by: '<S132>/A'

    real_T DiscreteTransferFcn_NumCoef_f[2];// Expression: [num_roll_disc]
                                               //  Referenced by: '<S186>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef_p[2];// Expression: [den_roll_disc]
                                               //  Referenced by: '<S186>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialSt_b;// Expression: 0
                                              //  Referenced by: '<S186>/Discrete Transfer Fcn'

    real_T Assumingthatcalibwasdonelevel_B[6];// Expression: [0 0 +g 0 0 0]
                                                 //  Referenced by: '<S3>/Assuming that calib was done level!'

    real_T FIR_IMUaccel_InitialStates; // Expression: 0
                                          //  Referenced by: '<S3>/FIR_IMUaccel'

    real_T FIR_IMUaccel_Coefficients[6];
                           // Expression: Estimator.IMU.filterAccel.Coefficients
                              //  Referenced by: '<S3>/FIR_IMUaccel'

    real_T Gain1_Gain;                 // Expression: -1
                                          //  Referenced by: '<S187>/Gain1'

    real_T Gain_Gain;                  // Expression: -1
                                          //  Referenced by: '<S187>/Gain'

    real_T Gain2_Gain;                 // Expression: -1
                                          //  Referenced by: '<S187>/Gain2'

    real_T Gain3_Gain;                 // Expression: -1
                                          //  Referenced by: '<S187>/Gain3'

    real_T Gain_Gain_p;                // Expression: -1
                                          //  Referenced by: '<S188>/Gain'

    real_T DiscreteTransferFcn_NumCoef_o[2];// Expression: [num_pitch_disc]
                                               //  Referenced by: '<S185>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef_b[2];// Expression: [den_pitch_disc]
                                               //  Referenced by: '<S185>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialSt_e;// Expression: 0
                                              //  Referenced by: '<S185>/Discrete Transfer Fcn'

    real_T Constant_Value_c;           // Expression: 1
                                          //  Referenced by: '<S33>/Constant'

    real_T Memory_InitialCondition;    // Expression: 0
                                          //  Referenced by: '<S33>/Memory'

    real_T KalmanGainM_Value[8];       // Expression: pInitialization.M
                                          //  Referenced by: '<S134>/KalmanGainM'

    real_T C_Value[8];                 // Expression: pInitialization.C
                                          //  Referenced by: '<S132>/C'

    real_T KalmanGainL_Value[8];       // Expression: pInitialization.L
                                          //  Referenced by: '<S134>/KalmanGainL'

    real_T gravity_Value[3];           // Expression: [0 0 g]
                                          //  Referenced by: '<S131>/gravity'

    real_T Constant_Value_e;           // Expression: 0
                                          //  Referenced by: '<S131>/Constant'

    real_T DiscreteFilter1_NumCoef[4]; // Expression: Estimator.alt.filterPrsNum
                                          //  Referenced by: '<S131>/Discrete Filter1'

    real_T DiscreteFilter1_DenCoef[4]; // Expression: Estimator.alt.filterPrsDen
                                          //  Referenced by: '<S131>/Discrete Filter1'

    real_T DiscreteFilter1_InitialStates;// Expression: 0
                                            //  Referenced by: '<S131>/Discrete Filter1'

    real_T D_Value[2];                 // Expression: pInitialization.D
                                          //  Referenced by: '<S132>/D'

    real_T X0_Value[4];                // Expression: pInitialization.X0
                                          //  Referenced by: '<S132>/X0'

    real_T B_Value[4];                 // Expression: pInitialization.B
                                          //  Referenced by: '<S132>/B'

    real_T Constant_Value_j[4];        // Expression: [1,1,1,1]
                                          //  Referenced by: '<S29>/Constant'

    real_T KalmanGainM_Value_e[4];     // Expression: pInitialization.M
                                          //  Referenced by: '<S61>/KalmanGainM'

    real_T C_Value_h[4];               // Expression: pInitialization.C
                                          //  Referenced by: '<S42>/C'

    real_T A_Value_p[4];               // Expression: pInitialization.A
                                          //  Referenced by: '<S42>/A'

    real_T B_Value_p[4];               // Expression: pInitialization.B
                                          //  Referenced by: '<S42>/B'

    real_T KalmanGainL_Value_f[4];     // Expression: pInitialization.L
                                          //  Referenced by: '<S61>/KalmanGainL'

    real_T D_Value_b[4];               // Expression: pInitialization.D
                                          //  Referenced by: '<S42>/D'

    real_T Constant_Value_c1[2];       // Expression: [0 0]
                                          //  Referenced by: '<S32>/Constant'

    real_T X0_Value_h[2];              // Expression: pInitialization.X0
                                          //  Referenced by: '<S42>/X0'

    real_T IIRgyroz_NumCoef[6];       // Expression: Estimator.IMU.filterGyroNum
                                         //  Referenced by: '<S41>/IIRgyroz'

    real_T IIRgyroz_DenCoef[6];       // Expression: Estimator.IMU.filterGyroDen
                                         //  Referenced by: '<S41>/IIRgyroz'

    real_T IIRgyroz_InitialStates;     // Expression: 0
                                          //  Referenced by: '<S41>/IIRgyroz'

    real_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S49>/TSamp'

    real_T Delay_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S36>/Delay'

    real_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S129>/Integrator'

    real_T Integrator_UpperSat;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S129>/Integrator'

    real_T Integrator_LowerSat;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S129>/Integrator'

    real_T Saturation_UpperSat;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S129>/Saturation'

    real_T Saturation_LowerSat;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S129>/Saturation'

    real_T Delay2_InitialCondition;    // Expression: 0.0
                                          //  Referenced by: '<S43>/Delay2'

    real_T Bias3_Bias;                 // Expression: 2
                                          //  Referenced by: '<S43>/Bias3'

    real_T Gain5_Gain;                 // Expression: 1/100
                                          //  Referenced by: '<S43>/Gain5'

    real_T Integrator_gainval_g;     // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S122>/Integrator'

    real_T Integrator_UpperSat_i;      // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S122>/Integrator'

    real_T Integrator_LowerSat_l;      // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S122>/Integrator'

    real_T Saturation_UpperSat_k;      // Expression: windupUpperLimit
                                          //  Referenced by: '<S122>/Saturation'

    real_T Saturation_LowerSat_h;      // Expression: windupLowerLimit
                                          //  Referenced by: '<S122>/Saturation'

    real_T Delay1_InitialCondition;    // Expression: 0.0
                                          //  Referenced by: '<S43>/Delay1'

    real_T Bias2_Bias;                 // Expression: 2
                                          //  Referenced by: '<S43>/Bias2'

    real_T Gain4_Gain;                 // Expression: 1/100
                                          //  Referenced by: '<S43>/Gain4'

    real_T gravity_Value_a[3];         // Expression: [0 0 -g]
                                          //  Referenced by: '<S40>/gravity'

    real_T gainaccinput_Gain; // Expression: Estimator.pos.accelerationInputGain
                                 //  Referenced by: '<S40>/gainaccinput'

    real_T SimplyIntegrateVelocity_gainval;
                          // Computed Parameter: SimplyIntegrateVelocity_gainval
                             //  Referenced by: '<S35>/SimplyIntegrateVelocity'

    real_T SimplyIntegrateVelocity_IC; // Expression: 0
                                          //  Referenced by: '<S35>/SimplyIntegrateVelocity'

    real_T Gain3_Gain_g;               // Expression: .2
                                          //  Referenced by: '<S21>/Gain3'

    real_T Gain4_Gain_m;               // Expression: .2
                                          //  Referenced by: '<S21>/Gain4'

    real_T Gain1_Gain_b;               // Expression: -1
                                          //  Referenced by: '<S21>/Gain1'

    real_T Saturation_UpperSat_d;      // Expression: pi/4
                                          //  Referenced by: '<S21>/Saturation'

    real_T Saturation_LowerSat_a;      // Expression: -pi/4
                                          //  Referenced by: '<S21>/Saturation'

    real_T Pos1Dashboard0_Value;       // Expression: 1
                                          //  Referenced by: '<S1>/Pos=1//Dashboard=0'

    real_T Switch1_Threshold;          // Expression: 0
                                          //  Referenced by: '<S4>/Switch1'

    real_T Internal_A;                 // Computed Parameter: Internal_A
                                          //  Referenced by: '<S11>/Internal'

    real_T Internal_B;                 // Computed Parameter: Internal_B
                                          //  Referenced by: '<S11>/Internal'

    real_T Internal_C;                 // Computed Parameter: Internal_C
                                          //  Referenced by: '<S11>/Internal'

    real_T Internal_D;                 // Computed Parameter: Internal_D
                                          //  Referenced by: '<S11>/Internal'

    real_T Internal_InitialCondition;  // Expression: xinit
                                          //  Referenced by: '<S11>/Internal'

    real_T ChangingofJyy_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jyy'

    real_T pitchequilibrium_Value;     // Expression: 0
                                          //  Referenced by: '<S4>/pitch equilibrium'

    real_T On1Off2forpitch_Gain;       // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=2 for pitch'

    real_T Constant_Value_f;           // Expression: 100
                                          //  Referenced by: '<S1>/Constant'

    real_T On1Off0forthrust_Gain;      // Expression: 1
                                          //  Referenced by: '<S1>/On=1//Off=0 for thrust'

    real_T yawequilibrium_Value;       // Expression: 0
                                          //  Referenced by: '<S4>/yaw equilibrium'

    real_T Internal_A_l[3];            // Computed Parameter: Internal_A_l
                                          //  Referenced by: '<S17>/Internal'

    real_T Internal_B_e;               // Computed Parameter: Internal_B_e
                                          //  Referenced by: '<S17>/Internal'

    real_T Internal_C_j[2];            // Computed Parameter: Internal_C_j
                                          //  Referenced by: '<S17>/Internal'

    real_T Internal_InitialCondition_a;// Expression: xinit
                                          //  Referenced by: '<S17>/Internal'

    real_T ChangingofJzz_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jzz'

    real_T On1Off1foryaw_Gain;         // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=1 for yaw'

    real_T rollequilibrium_Value;      // Expression: 0
                                          //  Referenced by: '<S4>/roll equilibrium'

    real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S9>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_IC;  // Expression: 0
                                          //  Referenced by: '<S9>/Discrete-Time Integrator'

    real_T Internal_A_d[3];            // Computed Parameter: Internal_A_d
                                          //  Referenced by: '<S14>/Internal'

    real_T Internal_B_g;               // Computed Parameter: Internal_B_g
                                          //  Referenced by: '<S14>/Internal'

    real_T Internal_C_n[2];            // Computed Parameter: Internal_C_n
                                          //  Referenced by: '<S14>/Internal'

    real_T Internal_InitialCondition_h;// Expression: xinit
                                          //  Referenced by: '<S14>/Internal'

    real_T ChangingofJxx_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jxx'

    real_T On1Off1forroll_Gain;        // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=1 for roll'

    real_T Gain4_Gain_h;               // Expression: .2
                                          //  Referenced by: '<S22>/Gain4'

    real_T Gain3_Gain_i;               // Expression: .2
                                          //  Referenced by: '<S22>/Gain3'

    real_T Gain1_Gain_i;               // Expression: 1
                                          //  Referenced by: '<S22>/Gain1'

    real_T Saturation_UpperSat_ku;     // Expression: pi/4
                                          //  Referenced by: '<S22>/Saturation'

    real_T Saturation_LowerSat_j;      // Expression: -pi/4
                                          //  Referenced by: '<S22>/Saturation'

    real_T Constant_Value_e2;          // Expression: 0
                                          //  Referenced by: '<S6>/Constant'

    real_T Switch2_Threshold;          // Expression: 0
                                          //  Referenced by: '<S4>/Switch2'

    real_T DiscreteTimeIntegrator_gainva_i;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_i
                             //  Referenced by: '<S31>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_IC_p;// Expression: 0
                                          //  Referenced by: '<S31>/Discrete-Time Integrator'

    real_T Gain_Gain_h;                // Expression: 1/(60*60)
                                          //  Referenced by: '<S31>/Gain'

    real_T Constant_Value_i;           // Expression: 1
                                          //  Referenced by: '<S20>/Constant'

    real_T signal_max_Value;           // Expression: 2
                                          //  Referenced by: '<S24>/signal_max'

    real_T cycle_time_Value;           // Expression: 0.1
                                          //  Referenced by: '<S24>/cycle_time'

    real_T Gain_Gain_n;                // Expression: .5
                                          //  Referenced by: '<S24>/Gain'

    real_T CovarianceZ_Value[16];      // Expression: pInitialization.Z
                                          //  Referenced by: '<S134>/CovarianceZ'

    real_T CovarianceZ_Value_c[4];     // Expression: pInitialization.Z
                                          //  Referenced by: '<S61>/CovarianceZ'

    real32_T inverseIMU_gain_Gain[6];// Computed Parameter: inverseIMU_gain_Gain
                                        //  Referenced by: '<S3>/inverseIMU_gain'

    real32_T RangfinderScaleGain1_Gain;
                                // Computed Parameter: RangfinderScaleGain1_Gain
                                   //  Referenced by: '<S131>/RangfinderScaleGain1'

    boolean_T Enable_Value;            // Expression: true()
                                          //  Referenced by: '<S132>/Enable'

    boolean_T Memory_InitialCondition_h;
                                // Computed Parameter: Memory_InitialCondition_h
                                   //  Referenced by: '<S24>/Memory'

    boolean_T isSqrtUsed_Value;        // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S179>/isSqrtUsed'

    boolean_T isSqrtUsed_Value_l;      // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S109>/isSqrtUsed'

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

    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const volatile aErrorStatus);
  };

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
  void step(in_dashboard *arg_in_dashboard, in_parameters *arg_in_parameters,
            out_controllers *arg_out_controllers, out_estimators
            *arg_out_estimators, out_sensors *arg_out_sensors);

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
//  Block '<S8>/Scope' : Unused code path elimination
//  Block '<S8>/Scope1' : Unused code path elimination
//  Block '<S9>/RollScope' : Unused code path elimination
//  Block '<S20>/Constant1' : Unused code path elimination
//  Block '<S20>/Display' : Unused code path elimination
//  Block '<S20>/Display2' : Unused code path elimination
//  Block '<S20>/Gain' : Unused code path elimination
//  Block '<S20>/Gain1' : Unused code path elimination
//  Block '<S23>/Internal' : Unused code path elimination
//  Block '<S20>/SaturationThrust' : Unused code path elimination
//  Block '<S20>/Scope' : Unused code path elimination
//  Block '<S24>/Constant' : Unused code path elimination
//  Block '<S24>/Product' : Unused code path elimination
//  Block '<S20>/Sum1' : Unused code path elimination
//  Block '<S20>/Sum2' : Unused code path elimination
//  Block '<S20>/Sum3' : Unused code path elimination
//  Block '<S20>/Sum4' : Unused code path elimination
//  Block '<S20>/WithControl=1 WithoutControl=0' : Unused code path elimination
//  Block '<S20>/WithTakeoff=1 WithoutTakeoff=0' : Unused code path elimination
//  Block '<S20>/kd_alt' : Unused code path elimination
//  Block '<S20>/kp_alt' : Unused code path elimination
//  Block '<S20>/rateFeedback ON//OFF' : Unused code path elimination
//  Block '<S20>/z_dz_est' : Unused code path elimination
//  Block '<S20>/z_ref-est' : Unused code path elimination
//  Block '<S21>/Scope1' : Unused code path elimination
//  Block '<S22>/Scope' : Unused code path elimination
//  Block '<S1>/Scope1' : Unused code path elimination
//  Block '<S28>/Product' : Unused code path elimination
//  Block '<S28>/TorqueTotalThrustToThrustPerMotor' : Unused code path elimination
//  Block '<S30>/Bias' : Unused code path elimination
//  Block '<S30>/Scope1' : Unused code path elimination
//  Block '<S30>/Scope2' : Unused code path elimination
//  Block '<S30>/thrustToMotor' : Unused code path elimination
//  Block '<S49>/Data Type Duplicate' : Unused code path elimination
//  Block '<S103>/Data Type Duplicate' : Unused code path elimination
//  Block '<S104>/Data Type Duplicate' : Unused code path elimination
//  Block '<S105>/Conversion' : Unused code path elimination
//  Block '<S105>/Data Type Duplicate' : Unused code path elimination
//  Block '<S106>/Data Type Duplicate' : Unused code path elimination
//  Block '<S64>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/Data Type Duplicate' : Unused code path elimination
//  Block '<S66>/Data Type Duplicate' : Unused code path elimination
//  Block '<S67>/Data Type Duplicate' : Unused code path elimination
//  Block '<S68>/Data Type Duplicate' : Unused code path elimination
//  Block '<S69>/Data Type Duplicate' : Unused code path elimination
//  Block '<S70>/Data Type Duplicate' : Unused code path elimination
//  Block '<S71>/Conversion' : Unused code path elimination
//  Block '<S71>/Data Type Duplicate' : Unused code path elimination
//  Block '<S72>/Data Type Duplicate' : Unused code path elimination
//  Block '<S73>/Data Type Duplicate' : Unused code path elimination
//  Block '<S74>/Data Type Duplicate' : Unused code path elimination
//  Block '<S76>/Data Type Duplicate' : Unused code path elimination
//  Block '<S77>/Data Type Duplicate' : Unused code path elimination
//  Block '<S42>/G' : Unused code path elimination
//  Block '<S42>/H' : Unused code path elimination
//  Block '<S42>/N' : Unused code path elimination
//  Block '<S42>/P0' : Unused code path elimination
//  Block '<S42>/Q' : Unused code path elimination
//  Block '<S42>/R' : Unused code path elimination
//  Block '<S92>/CheckSignalProperties' : Unused code path elimination
//  Block '<S101>/CheckSignalProperties' : Unused code path elimination
//  Block '<S102>/CheckSignalProperties' : Unused code path elimination
//  Block '<S36>/dxy_est' : Unused code path elimination
//  Block '<S36>/optical flow' : Unused code path elimination
//  Block '<S131>/Constant1' : Unused code path elimination
//  Block '<S131>/Discrete Filter' : Unused code path elimination
//  Block '<S174>/Data Type Duplicate' : Unused code path elimination
//  Block '<S175>/Data Type Duplicate' : Unused code path elimination
//  Block '<S176>/Conversion' : Unused code path elimination
//  Block '<S176>/Data Type Duplicate' : Unused code path elimination
//  Block '<S177>/Data Type Duplicate' : Unused code path elimination
//  Block '<S135>/Product' : Unused code path elimination
//  Block '<S137>/Data Type Duplicate' : Unused code path elimination
//  Block '<S138>/Data Type Duplicate' : Unused code path elimination
//  Block '<S139>/Data Type Duplicate' : Unused code path elimination
//  Block '<S140>/Data Type Duplicate' : Unused code path elimination
//  Block '<S142>/Data Type Duplicate' : Unused code path elimination
//  Block '<S143>/Data Type Duplicate' : Unused code path elimination
//  Block '<S144>/Data Type Duplicate' : Unused code path elimination
//  Block '<S145>/Conversion' : Unused code path elimination
//  Block '<S145>/Data Type Duplicate' : Unused code path elimination
//  Block '<S146>/Data Type Duplicate' : Unused code path elimination
//  Block '<S147>/Data Type Duplicate' : Unused code path elimination
//  Block '<S148>/Data Type Duplicate' : Unused code path elimination
//  Block '<S149>/Data Type Duplicate' : Unused code path elimination
//  Block '<S150>/Data Type Duplicate' : Unused code path elimination
//  Block '<S132>/G' : Unused code path elimination
//  Block '<S132>/H' : Unused code path elimination
//  Block '<S132>/N' : Unused code path elimination
//  Block '<S132>/P0' : Unused code path elimination
//  Block '<S132>/Q' : Unused code path elimination
//  Block '<S132>/R' : Unused code path elimination
//  Block '<S132>/Reshapeyhat' : Unused code path elimination
//  Block '<S170>/CheckSignalProperties' : Unused code path elimination
//  Block '<S172>/CheckSignalProperties' : Unused code path elimination
//  Block '<S173>/CheckSignalProperties' : Unused code path elimination
//  Block '<S131>/Product3' : Unused code path elimination
//  Block '<S131>/Scope' : Unused code path elimination
//  Block '<S131>/Scope1' : Unused code path elimination
//  Block '<S131>/Scope2' : Unused code path elimination
//  Block '<S131>/Sum1' : Unused code path elimination
//  Block '<S131>/gravity1' : Unused code path elimination
//  Block '<S131>/prsToAltGain' : Unused code path elimination
//  Block '<S131>/thrust2acc' : Unused code path elimination
//  Block '<S32>/Scope' : Unused code path elimination
//  Block '<S32>/Scope1' : Unused code path elimination
//  Block '<S8>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S8>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S29>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S39>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S48>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S103>/Conversion' : Eliminate redundant data type conversion
//  Block '<S104>/Conversion' : Eliminate redundant data type conversion
//  Block '<S106>/Conversion' : Eliminate redundant data type conversion
//  Block '<S42>/DataTypeConversionEnable' : Eliminate redundant data type conversion
//  Block '<S76>/Conversion' : Eliminate redundant data type conversion
//  Block '<S80>/Reshape' : Reshape block reduction
//  Block '<S42>/ReshapeX0' : Reshape block reduction
//  Block '<S42>/Reshapeu' : Reshape block reduction
//  Block '<S42>/Reshapexhat' : Reshape block reduction
//  Block '<S131>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S174>/Conversion' : Eliminate redundant data type conversion
//  Block '<S175>/Conversion' : Eliminate redundant data type conversion
//  Block '<S177>/Conversion' : Eliminate redundant data type conversion
//  Block '<S132>/DataTypeConversionReset' : Eliminate redundant data type conversion
//  Block '<S149>/Conversion' : Eliminate redundant data type conversion
//  Block '<S153>/Reshape' : Reshape block reduction
//  Block '<S132>/ReshapeX0' : Reshape block reduction
//  Block '<S132>/Reshapeu' : Reshape block reduction
//  Block '<S132>/Reshapexhat' : Reshape block reduction
//  Block '<S184>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S187>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S187>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S187>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S187>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S188>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S188>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S188>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S188>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S188>/Zero-Order Hold4' : Eliminated since input and output rates are identical


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
//  '<S1>'   : 'FCS_model/Controllers'
//  '<S2>'   : 'FCS_model/Estimatiors'
//  '<S3>'   : 'FCS_model/SensorPreprocessing'
//  '<S4>'   : 'FCS_model/Controllers/Orientation'
//  '<S5>'   : 'FCS_model/Controllers/Position'
//  '<S6>'   : 'FCS_model/Controllers/busCreation'
//  '<S7>'   : 'FCS_model/Controllers/post_processing'
//  '<S8>'   : 'FCS_model/Controllers/Orientation/Pitch Controller'
//  '<S9>'   : 'FCS_model/Controllers/Orientation/Roll Controller'
//  '<S10>'  : 'FCS_model/Controllers/Orientation/Yaw Controller'
//  '<S11>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/PI'
//  '<S12>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/PI/Input Delay'
//  '<S13>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/PI/Output Delay'
//  '<S14>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5'
//  '<S15>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5/Input Delay'
//  '<S16>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5/Output Delay'
//  '<S17>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5'
//  '<S18>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5/Input Delay'
//  '<S19>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5/Output Delay'
//  '<S20>'  : 'FCS_model/Controllers/Position/Altitude'
//  '<S21>'  : 'FCS_model/Controllers/Position/X_controller'
//  '<S22>'  : 'FCS_model/Controllers/Position/Y_controller'
//  '<S23>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5'
//  '<S24>'  : 'FCS_model/Controllers/Position/Altitude/Subsystem'
//  '<S25>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5/Input Delay'
//  '<S26>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5/Output Delay'
//  '<S27>'  : 'FCS_model/Controllers/Position/Altitude/Subsystem/takeoff_acceleration'
//  '<S28>'  : 'FCS_model/Controllers/post_processing/ControlMixer'
//  '<S29>'  : 'FCS_model/Controllers/post_processing/power_slider'
//  '<S30>'  : 'FCS_model/Controllers/post_processing/thrustsToMotorCommands'
//  '<S31>'  : 'FCS_model/Estimatiors/Battery'
//  '<S32>'  : 'FCS_model/Estimatiors/Position Estimation'
//  '<S33>'  : 'FCS_model/Estimatiors/Subsystem Reference'
//  '<S34>'  : 'FCS_model/Estimatiors/estimators actve'
//  '<S35>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYPosition'
//  '<S36>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity'
//  '<S37>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ'
//  '<S38>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix'
//  '<S39>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S40>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling'
//  '<S41>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling'
//  '<S42>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy'
//  '<S43>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup'
//  '<S44>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/Deactivate Acceleration If OF is not used due to low altitude'
//  '<S45>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix'
//  '<S46>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)'
//  '<S47>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)1'
//  '<S48>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S49>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/DiscreteDerivative'
//  '<S50>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxdw1'
//  '<S51>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxdw2'
//  '<S52>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxp'
//  '<S53>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxp2'
//  '<S54>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxq'
//  '<S55>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxq2'
//  '<S56>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw1'
//  '<S57>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw2'
//  '<S58>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw3'
//  '<S59>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw4'
//  '<S60>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/minHeightforOF'
//  '<S61>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL'
//  '<S62>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculateYhat'
//  '<S63>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator'
//  '<S64>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionA'
//  '<S65>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionB'
//  '<S66>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionC'
//  '<S67>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionD'
//  '<S68>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionG'
//  '<S69>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionH'
//  '<S70>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionN'
//  '<S71>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionP'
//  '<S72>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionP0'
//  '<S73>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionQ'
//  '<S74>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionR'
//  '<S75>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionReset'
//  '<S76>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionX'
//  '<S77>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionX0'
//  '<S78>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionu'
//  '<S79>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/MemoryP'
//  '<S80>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Observer'
//  '<S81>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ReducedQRN'
//  '<S82>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Reset'
//  '<S83>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Reshapeyhat'
//  '<S84>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ScalarExpansionP0'
//  '<S85>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ScalarExpansionQ'
//  '<S86>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ScalarExpansionR'
//  '<S87>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/UseCurrentEstimator'
//  '<S88>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkA'
//  '<S89>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkB'
//  '<S90>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkC'
//  '<S91>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkD'
//  '<S92>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkEnable'
//  '<S93>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkG'
//  '<S94>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkH'
//  '<S95>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkN'
//  '<S96>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkP0'
//  '<S97>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkQ'
//  '<S98>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkR'
//  '<S99>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkReset'
//  '<S100>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkX0'
//  '<S101>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checku'
//  '<S102>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checky'
//  '<S103>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionL'
//  '<S104>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionM'
//  '<S105>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionP'
//  '<S106>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionZ'
//  '<S107>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/Ground'
//  '<S108>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculateYhat/Ground'
//  '<S109>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator/decideOutput'
//  '<S110>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S111>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Observer/MeasurementUpdate'
//  '<S112>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ReducedQRN/Ground'
//  '<S113>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/UseCurrentEstimator/Enabled Subsystem'
//  '<S114>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2'
//  '<S115>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3'
//  '<S116>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant'
//  '<S117>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Initialization'
//  '<S118>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Integrator (Discrete or Continuous)'
//  '<S119>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant/Compare To Constant'
//  '<S120>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant/Compare To Zero'
//  '<S121>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Initialization/Init_u'
//  '<S122>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Integrator (Discrete or Continuous)/Discrete'
//  '<S123>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant'
//  '<S124>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Initialization'
//  '<S125>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Integrator (Discrete or Continuous)'
//  '<S126>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant/Compare To Constant'
//  '<S127>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant/Compare To Zero'
//  '<S128>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Initialization/Init_u'
//  '<S129>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Integrator (Discrete or Continuous)/Discrete'
//  '<S130>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher'
//  '<S131>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3'
//  '<S132>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1'
//  '<S133>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/Rotation Angles to Direction Cosine Matrix'
//  '<S134>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL'
//  '<S135>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculateYhat'
//  '<S136>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CovarianceOutputConfigurator'
//  '<S137>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionA'
//  '<S138>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionB'
//  '<S139>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionC'
//  '<S140>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionD'
//  '<S141>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionEnable'
//  '<S142>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionG'
//  '<S143>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionH'
//  '<S144>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionN'
//  '<S145>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionP'
//  '<S146>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionP0'
//  '<S147>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionQ'
//  '<S148>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionR'
//  '<S149>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionX'
//  '<S150>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionX0'
//  '<S151>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionu'
//  '<S152>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/MemoryP'
//  '<S153>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/Observer'
//  '<S154>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ReducedQRN'
//  '<S155>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ScalarExpansionP0'
//  '<S156>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ScalarExpansionQ'
//  '<S157>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ScalarExpansionR'
//  '<S158>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/UseCurrentEstimator'
//  '<S159>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkA'
//  '<S160>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkB'
//  '<S161>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkC'
//  '<S162>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkD'
//  '<S163>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkEnable'
//  '<S164>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkG'
//  '<S165>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkH'
//  '<S166>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkN'
//  '<S167>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkP0'
//  '<S168>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkQ'
//  '<S169>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkR'
//  '<S170>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkReset'
//  '<S171>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkX0'
//  '<S172>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checku'
//  '<S173>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checky'
//  '<S174>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/DataTypeConversionL'
//  '<S175>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/DataTypeConversionM'
//  '<S176>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/DataTypeConversionP'
//  '<S177>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/DataTypeConversionZ'
//  '<S178>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/Ground'
//  '<S179>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CovarianceOutputConfigurator/decideOutput'
//  '<S180>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S181>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/Observer/MeasurementUpdate'
//  '<S182>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ReducedQRN/Ground'
//  '<S183>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/UseCurrentEstimator/Enabled Subsystem'
//  '<S184>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S185>' : 'FCS_model/Estimatiors/Subsystem Reference/Complementary Filter for Pitch (disc.)'
//  '<S186>' : 'FCS_model/Estimatiors/Subsystem Reference/Complementary Filter for Roll (disc.)'
//  '<S187>' : 'FCS_model/Estimatiors/Subsystem Reference/Roll and Pitch Angles (Lecture 2, slide 39)'
//  '<S188>' : 'FCS_model/Estimatiors/Subsystem Reference/Roll, Pitch, and Yaw Rates (Lecture1, slide 22)1'
//  '<S189>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator'
//  '<S190>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator/If Action Subsystem3'
//  '<S191>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator/If Action Subsystem'
//  '<S192>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator/If Action Subsystem/Complementary Filter for Yaw (disc.)'

#endif                                 // FCS_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
