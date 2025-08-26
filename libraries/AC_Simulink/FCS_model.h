//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.h
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.216
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Aug 13 18:22:23 2025
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
    real_T Probe[2];                   // '<S127>/Probe'
    real_T Probe_c[2];                 // '<S120>/Probe'
    real_T Product2[4];                // '<S189>/Product2'
    real_T Product3[4];                // '<S187>/Product3'
    real_T Product2_c[2];              // '<S117>/Product2'
    real_T Product3_d[2];              // '<S115>/Product3'
    real_T signal_out;                 // '<S27>/takeoff_acceleration'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_FCS_model_T {
    real_T DiscreteTransferFcn_states; // '<S191>/Discrete Transfer Fcn'
    real_T DiscreteTransferFcn_states_j;// '<S192>/Discrete Transfer Fcn'
    real_T FIR_IMUaccel_states[15];    // '<S3>/FIR_IMUaccel'
    real_T DiscreteFilter1_states[3];  // '<S135>/Discrete Filter1'
    real_T MemoryX_DSTATE[4];          // '<S136>/MemoryX'
    real_T Internal_DSTATE[2];         // '<S26>/Internal'
    real_T Internal_DSTATE_f[2];       // '<S19>/Internal'
    real_T MemoryX_DSTATE_o[2];        // '<S46>/MemoryX'
    real_T IIRgyroz_states[10];        // '<S45>/IIRgyroz'
    real_T UD_DSTATE[2];               // '<S53>/UD'
    real_T Delay_DSTATE[2];            // '<S40>/Delay'
    real_T Integrator_DSTATE;          // '<S133>/Integrator'
    real_T Delay2_DSTATE[40];          // '<S47>/Delay2'
    real_T Integrator_DSTATE_e;        // '<S126>/Integrator'
    real_T Delay1_DSTATE[40];          // '<S47>/Delay1'
    real_T SimplyIntegrateVelocity_DSTATE[2];// '<S39>/SimplyIntegrateVelocity'
    real_T Internal_DSTATE_d;          // '<S11>/Internal'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S9>/Discrete-Time Integrator'
    real_T Internal_DSTATE_k[2];       // '<S15>/Internal'
    real_T DiscreteTimeIntegrator_DSTATE_o;// '<S35>/Discrete-Time Integrator'
    real_T DiscreteTransferFcn_states_p;// '<S198>/Discrete Transfer Fcn'
    real_T Memory_PreviousInput;       // '<S37>/Memory'
    int32_T FIR_IMUaccel_circBuf;      // '<S3>/FIR_IMUaccel'
    int8_T Integrator_PrevResetState;  // '<S133>/Integrator'
    int8_T Integrator_PrevResetState_e;// '<S126>/Integrator'
    uint8_T Integrator_IC_LOADING;     // '<S133>/Integrator'
    uint8_T Integrator_IC_LOADING_g;   // '<S126>/Integrator'
    uint8_T is_c1_FCS_model;           // '<S27>/takeoff_acceleration'
    uint8_T is_active_c1_FCS_model;    // '<S27>/takeoff_acceleration'
    boolean_T icLoad;                  // '<S136>/MemoryX'
    boolean_T Memory_PreviousInput_j;  // '<S27>/Memory'
    boolean_T icLoad_n;                // '<S46>/MemoryX'
    boolean_T EnabledSubsystem_MODE;   // '<S164>/Enabled Subsystem'
    boolean_T MeasurementUpdate_MODE;  // '<S158>/MeasurementUpdate'
    boolean_T EnabledSubsystem_MODE_g; // '<S91>/Enabled Subsystem'
    boolean_T MeasurementUpdate_MODE_h;// '<S84>/MeasurementUpdate'
  };

  // Parameters (default storage)
  struct P_FCS_model_T {
    struct_UHvAqkoSM4a4grTGLmN7a Vehicle;// Variable: Vehicle
                                            //  Referenced by:
                                            //    '<S23>/Constant1'
                                            //    '<S33>/Saturation'
                                            //    '<S34>/Bias'
                                            //    '<S34>/thrustToMotor'
                                            //    '<S27>/Constant'

    struct_sfjjhK32Dt7MmV2O18UsO Controller;// Variable: Controller
                                               //  Referenced by: '<S23>/SaturationThrust'

    real_T KDpsi;                      // Variable: KDpsi
                                          //  Referenced by: '<S10>/KDpsi'

    real_T KDtheta;                    // Variable: KDtheta
                                          //  Referenced by: '<S8>/KDtheta'

    real_T Ts;                         // Variable: Ts
                                          //  Referenced by:
                                          //    '<S27>/Ts'
                                          //    '<S196>/Gain'

    real_T g;                          // Variable: g
                                          //  Referenced by:
                                          //    '<S23>/Constant1'
                                          //    '<S193>/Constant'

    real_T kd_alt;                     // Variable: kd_alt
                                          //  Referenced by: '<S23>/kd_alt'

    real_T kd_rol;                     // Variable: kd_rol
                                          //  Referenced by: '<S9>/kd_rol'

    real_T ki_rol;                     // Variable: ki_rol
                                          //  Referenced by: '<S9>/ki_rol'

    real_T kp_alt;                     // Variable: kp_alt
                                          //  Referenced by: '<S23>/kp_alt'

    real_T kp_rol;                     // Variable: kp_rol
                                          //  Referenced by: '<S9>/kp_rol'

    real_T sensorCalibrationData[8];   // Variable: sensorCalibrationData
                                          //  Referenced by: '<Root>/Constant'

    real_T w_c_pitch;                  // Variable: w_c_pitch
                                          //  Referenced by: '<S191>/Gain'

    real_T w_c_roll;                   // Variable: w_c_roll
                                          //  Referenced by: '<S192>/Gain'

    real_T w_c_yaw;                    // Variable: w_c_yaw
                                          //  Referenced by: '<S198>/Gain'

    real_T zDpsi;                      // Variable: zDpsi
                                          //  Referenced by: '<S10>/zDpsi'

    real_T zDtheta;                    // Variable: zDtheta
                                          //  Referenced by: '<S8>/zDtheta'

    real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S53>/UD'

    real_T LowPassFilterDiscreteorContinuo;
                              // Mask Parameter: LowPassFilterDiscreteorContinuo
                                 //  Referenced by: '<S119>/K'

    real_T LowPassFilterDiscreteorContin_d;
                              // Mask Parameter: LowPassFilterDiscreteorContin_d
                                 //  Referenced by: '<S118>/K'

    real_T LowPassFilterDiscreteorContin_l;
                              // Mask Parameter: LowPassFilterDiscreteorContin_l
                                 //  Referenced by: '<S127>/Time constant'

    real_T LowPassFilterDiscreteorContin_a;
                              // Mask Parameter: LowPassFilterDiscreteorContin_a
                                 //  Referenced by: '<S120>/Time constant'

    real_T maxp_const;                 // Mask Parameter: maxp_const
                                          //  Referenced by: '<S56>/Constant'

    real_T maxq_const;                 // Mask Parameter: maxq_const
                                          //  Referenced by: '<S58>/Constant'

    real_T maxw1_const;                // Mask Parameter: maxw1_const
                                          //  Referenced by: '<S60>/Constant'

    real_T maxw2_const;                // Mask Parameter: maxw2_const
                                          //  Referenced by: '<S61>/Constant'

    real_T maxdw1_const;               // Mask Parameter: maxdw1_const
                                          //  Referenced by: '<S54>/Constant'

    real_T maxdw2_const;               // Mask Parameter: maxdw2_const
                                          //  Referenced by: '<S55>/Constant'

    real_T maxp2_const;                // Mask Parameter: maxp2_const
                                          //  Referenced by: '<S57>/Constant'

    real_T maxq2_const;                // Mask Parameter: maxq2_const
                                          //  Referenced by: '<S59>/Constant'

    real_T maxw3_const;                // Mask Parameter: maxw3_const
                                          //  Referenced by: '<S62>/Constant'

    real_T maxw4_const;                // Mask Parameter: maxw4_const
                                          //  Referenced by: '<S63>/Constant'

    real_T minHeightforOF_const;       // Mask Parameter: minHeightforOF_const
                                          //  Referenced by: '<S64>/Constant'

    real_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S130>/Constant'

    real_T CompareToConstant_const_p;
                                    // Mask Parameter: CompareToConstant_const_p
                                       //  Referenced by: '<S123>/Constant'

    real_T DeactivateAccelerationIfOFisnot;
                              // Mask Parameter: DeactivateAccelerationIfOFisnot
                                 //  Referenced by: '<S48>/Constant'

    real_T donotuseaccifopticalflowneverav;
                              // Mask Parameter: donotuseaccifopticalflowneverav
                                 //  Referenced by: '<S50>/Constant'

    real_T donotuseaccifopticalflownever_c;
                              // Mask Parameter: donotuseaccifopticalflownever_c
                                 //  Referenced by: '<S51>/Constant'

    real_T LowPassFilterDiscreteorContin_i;
                              // Mask Parameter: LowPassFilterDiscreteorContin_i
                                 //  Referenced by: '<S127>/Constant'

    real_T LowPassFilterDiscreteorConti_d0;
                              // Mask Parameter: LowPassFilterDiscreteorConti_d0
                                 //  Referenced by: '<S120>/Constant'

    real_T Lykyhatkk1_Y0;              // Expression: 0
                                          //  Referenced by: '<S115>/L*(y[k]-yhat[k|k-1])'

    real_T deltax_Y0;                  // Expression: 0
                                          //  Referenced by: '<S117>/deltax'

    real_T Lykyhatkk1_Y0_c;            // Expression: 0
                                          //  Referenced by: '<S187>/L*(y[k]-yhat[k|k-1])'

    real_T deltax_Y0_k;                // Expression: 0
                                          //  Referenced by: '<S189>/deltax'

    real_T DiscreteTransferFcn_NumCoef[2];// Expression: [num_yaw_disc]
                                             //  Referenced by: '<S198>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef[2];// Expression: [den_yaw_disc]
                                             //  Referenced by: '<S198>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                              //  Referenced by: '<S198>/Discrete Transfer Fcn'

    real_T Constant_Value;             // Expression: 0
                                          //  Referenced by: '<S124>/Constant'

    real_T Constant_Value_o;           // Expression: 0
                                          //  Referenced by: '<S131>/Constant'

    real_T A_Value[16];                // Expression: pInitialization.A
                                          //  Referenced by: '<S136>/A'

    real_T Constant_Value_c;           // Expression: 1
                                          //  Referenced by: '<S37>/Constant'

    real_T Assumingthatcalibwasdonelevel_B[6];// Expression: [0 0 +g 0 0 0]
                                                 //  Referenced by: '<S3>/Assuming that calib was done level!'

    real_T Memory_InitialCondition;    // Expression: 0
                                          //  Referenced by: '<S37>/Memory'

    real_T DiscreteTransferFcn_NumCoef_o[2];// Expression: [num_pitch_disc]
                                               //  Referenced by: '<S191>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef_b[2];// Expression: [den_pitch_disc]
                                               //  Referenced by: '<S191>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialSt_e;// Expression: 0
                                              //  Referenced by: '<S191>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_NumCoef_f[2];// Expression: [num_roll_disc]
                                               //  Referenced by: '<S192>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef_p[2];// Expression: [den_roll_disc]
                                               //  Referenced by: '<S192>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialSt_b;// Expression: 0
                                              //  Referenced by: '<S192>/Discrete Transfer Fcn'

    real_T KalmanGainM_Value[8];       // Expression: pInitialization.M
                                          //  Referenced by: '<S138>/KalmanGainM'

    real_T C_Value[8];                 // Expression: pInitialization.C
                                          //  Referenced by: '<S136>/C'

    real_T KalmanGainL_Value[8];       // Expression: pInitialization.L
                                          //  Referenced by: '<S138>/KalmanGainL'

    real_T FIR_IMUaccel_InitialStates; // Expression: 0
                                          //  Referenced by: '<S3>/FIR_IMUaccel'

    real_T FIR_IMUaccel_Coefficients[6];
                           // Expression: Estimator.IMU.filterAccel.Coefficients
                              //  Referenced by: '<S3>/FIR_IMUaccel'

    real_T gravity_Value[3];           // Expression: [0 0 g]
                                          //  Referenced by: '<S135>/gravity'

    real_T Constant_Value_e;           // Expression: 0
                                          //  Referenced by: '<S135>/Constant'

    real_T DiscreteFilter1_NumCoef[4]; // Expression: Estimator.alt.filterPrsNum
                                          //  Referenced by: '<S135>/Discrete Filter1'

    real_T DiscreteFilter1_DenCoef[4]; // Expression: Estimator.alt.filterPrsDen
                                          //  Referenced by: '<S135>/Discrete Filter1'

    real_T DiscreteFilter1_InitialStates;// Expression: 0
                                            //  Referenced by: '<S135>/Discrete Filter1'

    real_T D_Value[2];                 // Expression: pInitialization.D
                                          //  Referenced by: '<S136>/D'

    real_T X0_Value[4];                // Expression: pInitialization.X0
                                          //  Referenced by: '<S136>/X0'

    real_T B_Value[4];                 // Expression: pInitialization.B
                                          //  Referenced by: '<S136>/B'

    real_T Constant_Value_i;           // Expression: 1
                                          //  Referenced by: '<S23>/Constant'

    real_T signal_max_Value;           // Expression: 2
                                          //  Referenced by: '<S27>/signal_max'

    real_T cycle_time_Value;           // Expression: 0.1
                                          //  Referenced by: '<S27>/cycle_time'

    real_T Gain_Gain;                  // Expression: .5
                                          //  Referenced by: '<S27>/Gain'

    real_T WithTakeoff1WithoutTakeoff0_Gai;// Expression: 0
                                              //  Referenced by: '<S23>/WithTakeoff=1 WithoutTakeoff=0'

    real_T Internal_A[3];              // Computed Parameter: Internal_A
                                          //  Referenced by: '<S26>/Internal'

    real_T Internal_B;                 // Computed Parameter: Internal_B
                                          //  Referenced by: '<S26>/Internal'

    real_T Internal_C[2];              // Computed Parameter: Internal_C
                                          //  Referenced by: '<S26>/Internal'

    real_T Internal_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S26>/Internal'

    real_T Gain_Gain_f;                // Expression: -1
                                          //  Referenced by: '<S23>/Gain'

    real_T Constant_Value_c1[2];       // Expression: [0 0]
                                          //  Referenced by: '<S36>/Constant'

    real_T Gain1_Gain;                 // Expression: -1
                                          //  Referenced by: '<S23>/Gain1'

    real_T rateFeedbackONOFF_Gain;     // Expression: 1
                                          //  Referenced by: '<S23>/rateFeedback ON//OFF'

    real_T WithControl1WithoutControl0_Gai;// Expression: 1
                                              //  Referenced by: '<S23>/WithControl=1 WithoutControl=0'

    real_T On1Off0forthrust_Gain;      // Expression: 1
                                          //  Referenced by: '<S1>/On=1//Off=0 for thrust'

    real_T yawequilibrium_Value;       // Expression: 0
                                          //  Referenced by: '<S4>/yaw equilibrium'

    real_T Internal_A_l[3];            // Computed Parameter: Internal_A_l
                                          //  Referenced by: '<S19>/Internal'

    real_T Internal_B_e;               // Computed Parameter: Internal_B_e
                                          //  Referenced by: '<S19>/Internal'

    real_T Internal_C_j[2];            // Computed Parameter: Internal_C_j
                                          //  Referenced by: '<S19>/Internal'

    real_T Internal_InitialCondition_a;// Expression: 0
                                          //  Referenced by: '<S19>/Internal'

    real_T Gain2_Gain;                 // Expression: -1
                                          //  Referenced by: '<S193>/Gain2'

    real_T Gain3_Gain;                 // Expression: -1
                                          //  Referenced by: '<S193>/Gain3'

    real_T Gain1_Gain_e;               // Expression: -1
                                          //  Referenced by: '<S193>/Gain1'

    real_T Gain_Gain_e;                // Expression: -1
                                          //  Referenced by: '<S193>/Gain'

    real_T ChangingofJzz_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jzz'

    real_T On1Off1foryaw_Gain;         // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=1 for yaw'

    real_T pitchequilibrium_Value;     // Expression: 0
                                          //  Referenced by: '<S4>/pitch equilibrium'

    real_T X0_Value_h[2];              // Expression: pInitialization.X0
                                          //  Referenced by: '<S46>/X0'

    real_T KalmanGainM_Value_e[4];     // Expression: pInitialization.M
                                          //  Referenced by: '<S65>/KalmanGainM'

    real_T C_Value_h[4];               // Expression: pInitialization.C
                                          //  Referenced by: '<S46>/C'

    real_T IIRgyroz_NumCoef[6];       // Expression: Estimator.IMU.filterGyroNum
                                         //  Referenced by: '<S45>/IIRgyroz'

    real_T IIRgyroz_DenCoef[6];       // Expression: Estimator.IMU.filterGyroDen
                                         //  Referenced by: '<S45>/IIRgyroz'

    real_T IIRgyroz_InitialStates;     // Expression: 0
                                          //  Referenced by: '<S45>/IIRgyroz'

    real_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S53>/TSamp'

    real_T Delay_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S40>/Delay'

    real_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S133>/Integrator'

    real_T Integrator_UpperSat;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S133>/Integrator'

    real_T Integrator_LowerSat;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S133>/Integrator'

    real_T Saturation_UpperSat;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S133>/Saturation'

    real_T Saturation_LowerSat;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S133>/Saturation'

    real_T Delay2_InitialCondition;    // Expression: 0.0
                                          //  Referenced by: '<S47>/Delay2'

    real_T Bias3_Bias;                 // Expression: 2
                                          //  Referenced by: '<S47>/Bias3'

    real_T Gain5_Gain;                 // Expression: 1/100
                                          //  Referenced by: '<S47>/Gain5'

    real_T Integrator_gainval_g;     // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S126>/Integrator'

    real_T Integrator_UpperSat_i;      // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S126>/Integrator'

    real_T Integrator_LowerSat_l;      // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S126>/Integrator'

    real_T Saturation_UpperSat_k;      // Expression: windupUpperLimit
                                          //  Referenced by: '<S126>/Saturation'

    real_T Saturation_LowerSat_h;      // Expression: windupLowerLimit
                                          //  Referenced by: '<S126>/Saturation'

    real_T Delay1_InitialCondition;    // Expression: 0.0
                                          //  Referenced by: '<S47>/Delay1'

    real_T Bias2_Bias;                 // Expression: 2
                                          //  Referenced by: '<S47>/Bias2'

    real_T Gain4_Gain;                 // Expression: 1/100
                                          //  Referenced by: '<S47>/Gain4'

    real_T Gain4_Gain_m;               // Expression: .2
                                          //  Referenced by: '<S24>/Gain4'

    real_T SimplyIntegrateVelocity_gainval;
                          // Computed Parameter: SimplyIntegrateVelocity_gainval
                             //  Referenced by: '<S39>/SimplyIntegrateVelocity'

    real_T SimplyIntegrateVelocity_IC; // Expression: 0
                                          //  Referenced by: '<S39>/SimplyIntegrateVelocity'

    real_T Gain3_Gain_g;               // Expression: .2
                                          //  Referenced by: '<S24>/Gain3'

    real_T Gain1_Gain_b;               // Expression: -1
                                          //  Referenced by: '<S24>/Gain1'

    real_T Saturation_UpperSat_d;      // Expression: pi/4
                                          //  Referenced by: '<S24>/Saturation'

    real_T Saturation_LowerSat_a;      // Expression: -pi/4
                                          //  Referenced by: '<S24>/Saturation'

    real_T Pos1Dashboard0_Value;       // Expression: 1
                                          //  Referenced by: '<S1>/Pos=1//Dashboard=0'

    real_T Switch1_Threshold;          // Expression: 0
                                          //  Referenced by: '<S4>/Switch1'

    real_T Internal_A_o;               // Computed Parameter: Internal_A_o
                                          //  Referenced by: '<S11>/Internal'

    real_T Internal_B_b;               // Computed Parameter: Internal_B_b
                                          //  Referenced by: '<S11>/Internal'

    real_T Internal_C_p;               // Computed Parameter: Internal_C_p
                                          //  Referenced by: '<S11>/Internal'

    real_T Internal_D_b;               // Computed Parameter: Internal_D_b
                                          //  Referenced by: '<S11>/Internal'

    real_T Internal_InitialCondition_p;// Expression: 0
                                          //  Referenced by: '<S11>/Internal'

    real_T Gain_Gain_p;                // Expression: -1
                                          //  Referenced by: '<S194>/Gain'

    real_T ChangingofJyy_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jyy'

    real_T On1Off2forpitch_Gain;       // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=2 for pitch'

    real_T rollequilibrium_Value;      // Expression: 0
                                          //  Referenced by: '<S4>/roll equilibrium'

    real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S9>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_IC;  // Expression: 0
                                          //  Referenced by: '<S9>/Discrete-Time Integrator'

    real_T Internal_A_d[3];            // Computed Parameter: Internal_A_d
                                          //  Referenced by: '<S15>/Internal'

    real_T Internal_B_g;               // Computed Parameter: Internal_B_g
                                          //  Referenced by: '<S15>/Internal'

    real_T Internal_C_n[2];            // Computed Parameter: Internal_C_n
                                          //  Referenced by: '<S15>/Internal'

    real_T Internal_InitialCondition_h;// Expression: 0
                                          //  Referenced by: '<S15>/Internal'

    real_T ChangingofJxx_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jxx'

    real_T On1Off1forroll_Gain;        // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=1 for roll'

    real_T A_Value_p[4];               // Expression: pInitialization.A
                                          //  Referenced by: '<S46>/A'

    real_T B_Value_p[4];               // Expression: pInitialization.B
                                          //  Referenced by: '<S46>/B'

    real_T KalmanGainL_Value_f[4];     // Expression: pInitialization.L
                                          //  Referenced by: '<S65>/KalmanGainL'

    real_T D_Value_b[4];               // Expression: pInitialization.D
                                          //  Referenced by: '<S46>/D'

    real_T gravity_Value_a[3];         // Expression: [0 0 -g]
                                          //  Referenced by: '<S44>/gravity'

    real_T gainaccinput_Gain; // Expression: Estimator.pos.accelerationInputGain
                                 //  Referenced by: '<S44>/gainaccinput'

    real_T Gain4_Gain_h;               // Expression: .2
                                          //  Referenced by: '<S25>/Gain4'

    real_T Gain3_Gain_i;               // Expression: .2
                                          //  Referenced by: '<S25>/Gain3'

    real_T Gain1_Gain_i;               // Expression: 1
                                          //  Referenced by: '<S25>/Gain1'

    real_T Saturation_UpperSat_ku;     // Expression: pi/4
                                          //  Referenced by: '<S25>/Saturation'

    real_T Saturation_LowerSat_j;      // Expression: -pi/4
                                          //  Referenced by: '<S25>/Saturation'

    real_T Constant_Value_e2;          // Expression: 0
                                          //  Referenced by: '<S6>/Constant'

    real_T Switch2_Threshold;          // Expression: 0
                                          //  Referenced by: '<S4>/Switch2'

    real_T DiscreteTimeIntegrator_gainva_i;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_i
                             //  Referenced by: '<S35>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_IC_p;// Expression: 0
                                          //  Referenced by: '<S35>/Discrete-Time Integrator'

    real_T Gain_Gain_h;                // Expression: 1/(60*60)
                                          //  Referenced by: '<S35>/Gain'

    real_T CovarianceZ_Value[16];      // Expression: pInitialization.Z
                                          //  Referenced by: '<S138>/CovarianceZ'

    real_T CovarianceZ_Value_c[4];     // Expression: pInitialization.Z
                                          //  Referenced by: '<S65>/CovarianceZ'

    real32_T TorqueTotalThrustToThrustPerMot[16];// Expression: Controller.Q2Ts
                                                    //  Referenced by: '<S32>/TorqueTotalThrustToThrustPerMotor'

    real32_T inverseIMU_gain_Gain[6];// Computed Parameter: inverseIMU_gain_Gain
                                        //  Referenced by: '<S3>/inverseIMU_gain'

    real32_T RangfinderScaleGain1_Gain;
                                // Computed Parameter: RangfinderScaleGain1_Gain
                                   //  Referenced by: '<S135>/RangfinderScaleGain1'

    boolean_T Enable_Value;            // Expression: true()
                                          //  Referenced by: '<S136>/Enable'

    boolean_T Memory_InitialCondition_h;
                                // Computed Parameter: Memory_InitialCondition_h
                                   //  Referenced by: '<S27>/Memory'

    boolean_T isSqrtUsed_Value;        // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S185>/isSqrtUsed'

    boolean_T isSqrtUsed_Value_l;      // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S113>/isSqrtUsed'

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
//  Block '<S23>/Display' : Unused code path elimination
//  Block '<S23>/Display2' : Unused code path elimination
//  Block '<S23>/Scope' : Unused code path elimination
//  Block '<S23>/z_dz_est' : Unused code path elimination
//  Block '<S23>/z_ref-est' : Unused code path elimination
//  Block '<S24>/Scope1' : Unused code path elimination
//  Block '<S25>/Scope' : Unused code path elimination
//  Block '<S1>/Scope1' : Unused code path elimination
//  Block '<S34>/Scope1' : Unused code path elimination
//  Block '<S34>/Scope2' : Unused code path elimination
//  Block '<S53>/Data Type Duplicate' : Unused code path elimination
//  Block '<S107>/Data Type Duplicate' : Unused code path elimination
//  Block '<S108>/Data Type Duplicate' : Unused code path elimination
//  Block '<S109>/Conversion' : Unused code path elimination
//  Block '<S109>/Data Type Duplicate' : Unused code path elimination
//  Block '<S110>/Data Type Duplicate' : Unused code path elimination
//  Block '<S68>/Data Type Duplicate' : Unused code path elimination
//  Block '<S69>/Data Type Duplicate' : Unused code path elimination
//  Block '<S70>/Data Type Duplicate' : Unused code path elimination
//  Block '<S71>/Data Type Duplicate' : Unused code path elimination
//  Block '<S72>/Data Type Duplicate' : Unused code path elimination
//  Block '<S73>/Data Type Duplicate' : Unused code path elimination
//  Block '<S74>/Data Type Duplicate' : Unused code path elimination
//  Block '<S75>/Conversion' : Unused code path elimination
//  Block '<S75>/Data Type Duplicate' : Unused code path elimination
//  Block '<S76>/Data Type Duplicate' : Unused code path elimination
//  Block '<S77>/Data Type Duplicate' : Unused code path elimination
//  Block '<S78>/Data Type Duplicate' : Unused code path elimination
//  Block '<S80>/Data Type Duplicate' : Unused code path elimination
//  Block '<S81>/Data Type Duplicate' : Unused code path elimination
//  Block '<S46>/G' : Unused code path elimination
//  Block '<S46>/H' : Unused code path elimination
//  Block '<S46>/N' : Unused code path elimination
//  Block '<S46>/P0' : Unused code path elimination
//  Block '<S46>/Q' : Unused code path elimination
//  Block '<S46>/R' : Unused code path elimination
//  Block '<S96>/CheckSignalProperties' : Unused code path elimination
//  Block '<S105>/CheckSignalProperties' : Unused code path elimination
//  Block '<S106>/CheckSignalProperties' : Unused code path elimination
//  Block '<S40>/dxy_est' : Unused code path elimination
//  Block '<S40>/optical flow' : Unused code path elimination
//  Block '<S135>/Constant1' : Unused code path elimination
//  Block '<S135>/Discrete Filter' : Unused code path elimination
//  Block '<S180>/Data Type Duplicate' : Unused code path elimination
//  Block '<S181>/Data Type Duplicate' : Unused code path elimination
//  Block '<S182>/Conversion' : Unused code path elimination
//  Block '<S182>/Data Type Duplicate' : Unused code path elimination
//  Block '<S183>/Data Type Duplicate' : Unused code path elimination
//  Block '<S139>/Product' : Unused code path elimination
//  Block '<S141>/Data Type Duplicate' : Unused code path elimination
//  Block '<S142>/Data Type Duplicate' : Unused code path elimination
//  Block '<S143>/Data Type Duplicate' : Unused code path elimination
//  Block '<S144>/Data Type Duplicate' : Unused code path elimination
//  Block '<S146>/Data Type Duplicate' : Unused code path elimination
//  Block '<S147>/Data Type Duplicate' : Unused code path elimination
//  Block '<S148>/Data Type Duplicate' : Unused code path elimination
//  Block '<S149>/Conversion' : Unused code path elimination
//  Block '<S149>/Data Type Duplicate' : Unused code path elimination
//  Block '<S150>/Data Type Duplicate' : Unused code path elimination
//  Block '<S151>/Data Type Duplicate' : Unused code path elimination
//  Block '<S152>/Data Type Duplicate' : Unused code path elimination
//  Block '<S154>/Data Type Duplicate' : Unused code path elimination
//  Block '<S155>/Data Type Duplicate' : Unused code path elimination
//  Block '<S136>/G' : Unused code path elimination
//  Block '<S136>/H' : Unused code path elimination
//  Block '<S136>/N' : Unused code path elimination
//  Block '<S136>/P0' : Unused code path elimination
//  Block '<S136>/Q' : Unused code path elimination
//  Block '<S136>/R' : Unused code path elimination
//  Block '<S136>/Reshapeyhat' : Unused code path elimination
//  Block '<S178>/CheckSignalProperties' : Unused code path elimination
//  Block '<S179>/CheckSignalProperties' : Unused code path elimination
//  Block '<S135>/Product3' : Unused code path elimination
//  Block '<S135>/Scope' : Unused code path elimination
//  Block '<S135>/Scope1' : Unused code path elimination
//  Block '<S135>/Scope2' : Unused code path elimination
//  Block '<S135>/Sum1' : Unused code path elimination
//  Block '<S135>/gravity1' : Unused code path elimination
//  Block '<S135>/prsToAltGain' : Unused code path elimination
//  Block '<S135>/thrust2acc' : Unused code path elimination
//  Block '<S36>/Scope' : Unused code path elimination
//  Block '<S36>/Scope1' : Unused code path elimination
//  Block '<S8>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S8>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S33>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S43>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S52>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S107>/Conversion' : Eliminate redundant data type conversion
//  Block '<S108>/Conversion' : Eliminate redundant data type conversion
//  Block '<S110>/Conversion' : Eliminate redundant data type conversion
//  Block '<S46>/DataTypeConversionEnable' : Eliminate redundant data type conversion
//  Block '<S80>/Conversion' : Eliminate redundant data type conversion
//  Block '<S84>/Reshape' : Reshape block reduction
//  Block '<S46>/ReshapeX0' : Reshape block reduction
//  Block '<S46>/Reshapeu' : Reshape block reduction
//  Block '<S46>/Reshapexhat' : Reshape block reduction
//  Block '<S135>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S180>/Conversion' : Eliminate redundant data type conversion
//  Block '<S181>/Conversion' : Eliminate redundant data type conversion
//  Block '<S183>/Conversion' : Eliminate redundant data type conversion
//  Block '<S154>/Conversion' : Eliminate redundant data type conversion
//  Block '<S158>/Reshape' : Reshape block reduction
//  Block '<S136>/ReshapeX0' : Reshape block reduction
//  Block '<S136>/Reshapeu' : Reshape block reduction
//  Block '<S136>/Reshapexhat' : Reshape block reduction
//  Block '<S190>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S193>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S193>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S193>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S193>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S194>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S194>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S194>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S194>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S194>/Zero-Order Hold4' : Eliminated since input and output rates are identical


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
//  '<S12>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/PI/IO Delay'
//  '<S13>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/PI/Input Delay'
//  '<S14>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/PI/Output Delay'
//  '<S15>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5'
//  '<S16>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5/IO Delay'
//  '<S17>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5/Input Delay'
//  '<S18>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5/Output Delay'
//  '<S19>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5'
//  '<S20>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5/IO Delay'
//  '<S21>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5/Input Delay'
//  '<S22>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5/Output Delay'
//  '<S23>'  : 'FCS_model/Controllers/Position/Altitude'
//  '<S24>'  : 'FCS_model/Controllers/Position/X_controller'
//  '<S25>'  : 'FCS_model/Controllers/Position/Y_controller'
//  '<S26>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5'
//  '<S27>'  : 'FCS_model/Controllers/Position/Altitude/Subsystem'
//  '<S28>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5/IO Delay'
//  '<S29>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5/Input Delay'
//  '<S30>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5/Output Delay'
//  '<S31>'  : 'FCS_model/Controllers/Position/Altitude/Subsystem/takeoff_acceleration'
//  '<S32>'  : 'FCS_model/Controllers/post_processing/ControlMixer'
//  '<S33>'  : 'FCS_model/Controllers/post_processing/power_slider'
//  '<S34>'  : 'FCS_model/Controllers/post_processing/thrustsToMotorCommands'
//  '<S35>'  : 'FCS_model/Estimatiors/Battery'
//  '<S36>'  : 'FCS_model/Estimatiors/Position Estimation'
//  '<S37>'  : 'FCS_model/Estimatiors/Subsystem Reference'
//  '<S38>'  : 'FCS_model/Estimatiors/estimators actve'
//  '<S39>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYPosition'
//  '<S40>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity'
//  '<S41>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ'
//  '<S42>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix'
//  '<S43>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S44>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling'
//  '<S45>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling'
//  '<S46>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy'
//  '<S47>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup'
//  '<S48>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/Deactivate Acceleration If OF is not used due to low altitude'
//  '<S49>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix'
//  '<S50>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)'
//  '<S51>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)1'
//  '<S52>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S53>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/DiscreteDerivative'
//  '<S54>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxdw1'
//  '<S55>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxdw2'
//  '<S56>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxp'
//  '<S57>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxp2'
//  '<S58>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxq'
//  '<S59>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxq2'
//  '<S60>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw1'
//  '<S61>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw2'
//  '<S62>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw3'
//  '<S63>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw4'
//  '<S64>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/minHeightforOF'
//  '<S65>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL'
//  '<S66>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculateYhat'
//  '<S67>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator'
//  '<S68>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionA'
//  '<S69>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionB'
//  '<S70>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionC'
//  '<S71>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionD'
//  '<S72>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionG'
//  '<S73>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionH'
//  '<S74>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionN'
//  '<S75>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionP'
//  '<S76>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionP0'
//  '<S77>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionQ'
//  '<S78>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionR'
//  '<S79>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionReset'
//  '<S80>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionX'
//  '<S81>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionX0'
//  '<S82>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionu'
//  '<S83>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/MemoryP'
//  '<S84>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Observer'
//  '<S85>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ReducedQRN'
//  '<S86>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Reset'
//  '<S87>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Reshapeyhat'
//  '<S88>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ScalarExpansionP0'
//  '<S89>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ScalarExpansionQ'
//  '<S90>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ScalarExpansionR'
//  '<S91>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/UseCurrentEstimator'
//  '<S92>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkA'
//  '<S93>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkB'
//  '<S94>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkC'
//  '<S95>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkD'
//  '<S96>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkEnable'
//  '<S97>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkG'
//  '<S98>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkH'
//  '<S99>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkN'
//  '<S100>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkP0'
//  '<S101>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkQ'
//  '<S102>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkR'
//  '<S103>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkReset'
//  '<S104>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkX0'
//  '<S105>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checku'
//  '<S106>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checky'
//  '<S107>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionL'
//  '<S108>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionM'
//  '<S109>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionP'
//  '<S110>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionZ'
//  '<S111>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/Ground'
//  '<S112>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculateYhat/Ground'
//  '<S113>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator/decideOutput'
//  '<S114>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S115>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Observer/MeasurementUpdate'
//  '<S116>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ReducedQRN/Ground'
//  '<S117>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/UseCurrentEstimator/Enabled Subsystem'
//  '<S118>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2'
//  '<S119>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3'
//  '<S120>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant'
//  '<S121>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Initialization'
//  '<S122>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Integrator (Discrete or Continuous)'
//  '<S123>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant/Compare To Constant'
//  '<S124>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant/Compare To Zero'
//  '<S125>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Initialization/Init_u'
//  '<S126>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Integrator (Discrete or Continuous)/Discrete'
//  '<S127>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant'
//  '<S128>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Initialization'
//  '<S129>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Integrator (Discrete or Continuous)'
//  '<S130>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant/Compare To Constant'
//  '<S131>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant/Compare To Zero'
//  '<S132>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Initialization/Init_u'
//  '<S133>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Integrator (Discrete or Continuous)/Discrete'
//  '<S134>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher'
//  '<S135>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3'
//  '<S136>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1'
//  '<S137>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/Rotation Angles to Direction Cosine Matrix'
//  '<S138>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL'
//  '<S139>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculateYhat'
//  '<S140>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CovarianceOutputConfigurator'
//  '<S141>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionA'
//  '<S142>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionB'
//  '<S143>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionC'
//  '<S144>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionD'
//  '<S145>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionEnable'
//  '<S146>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionG'
//  '<S147>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionH'
//  '<S148>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionN'
//  '<S149>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionP'
//  '<S150>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionP0'
//  '<S151>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionQ'
//  '<S152>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionR'
//  '<S153>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionReset'
//  '<S154>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionX'
//  '<S155>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionX0'
//  '<S156>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/DataTypeConversionu'
//  '<S157>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/MemoryP'
//  '<S158>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/Observer'
//  '<S159>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ReducedQRN'
//  '<S160>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/Reset'
//  '<S161>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ScalarExpansionP0'
//  '<S162>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ScalarExpansionQ'
//  '<S163>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ScalarExpansionR'
//  '<S164>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/UseCurrentEstimator'
//  '<S165>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkA'
//  '<S166>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkB'
//  '<S167>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkC'
//  '<S168>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkD'
//  '<S169>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkEnable'
//  '<S170>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkG'
//  '<S171>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkH'
//  '<S172>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkN'
//  '<S173>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkP0'
//  '<S174>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkQ'
//  '<S175>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkR'
//  '<S176>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkReset'
//  '<S177>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checkX0'
//  '<S178>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checku'
//  '<S179>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/checky'
//  '<S180>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/DataTypeConversionL'
//  '<S181>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/DataTypeConversionM'
//  '<S182>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/DataTypeConversionP'
//  '<S183>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/DataTypeConversionZ'
//  '<S184>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CalculatePL/Ground'
//  '<S185>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CovarianceOutputConfigurator/decideOutput'
//  '<S186>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S187>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/Observer/MeasurementUpdate'
//  '<S188>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/ReducedQRN/Ground'
//  '<S189>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/KalmanFilter_altitude1/UseCurrentEstimator/Enabled Subsystem'
//  '<S190>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/KF3/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S191>' : 'FCS_model/Estimatiors/Subsystem Reference/Complementary Filter for Pitch (disc.)'
//  '<S192>' : 'FCS_model/Estimatiors/Subsystem Reference/Complementary Filter for Roll (disc.)'
//  '<S193>' : 'FCS_model/Estimatiors/Subsystem Reference/Roll and Pitch Angles (Lecture 2, slide 39)'
//  '<S194>' : 'FCS_model/Estimatiors/Subsystem Reference/Roll, Pitch, and Yaw Rates (Lecture1, slide 22)1'
//  '<S195>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator'
//  '<S196>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator/If Action Subsystem3'
//  '<S197>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator/If Action Subsystem'
//  '<S198>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator/If Action Subsystem/Complementary Filter for Yaw (disc.)'

#endif                                 // RTW_HEADER_FCS_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
