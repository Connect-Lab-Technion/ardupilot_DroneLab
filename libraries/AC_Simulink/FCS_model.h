//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.h
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 11.80
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Mon Aug 24 18:19:14 2026
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

// Class declaration for model FCS_model
class FCS_model
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_FCS_model_T {
    real_T Probe[2];                   // '<S122>/Probe'
    real_T Probe_c[2];                 // '<S115>/Probe'
    real_T Product2[2];                // '<S184>/Product2'
    real_T Product3[2];                // '<S182>/Product3'
    real_T Product2_c[2];              // '<S112>/Product2'
    real_T Product3_d[2];              // '<S110>/Product3'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_FCS_model_T {
    real_T DiscreteTransferFcn_states; // '<S187>/Discrete Transfer Fcn'
    real_T FIR_IMUaccel_states[15];    // '<S3>/FIR_IMUaccel'
    real_T IIR_IMUgyro_r_states[15];   // '<S3>/IIR_IMUgyro_r'
    real_T DiscreteTransferFcn_states_a;// '<S186>/Discrete Transfer Fcn'
    real_T Internal_DSTATE[2];         // '<S18>/Internal'
    real_T Internal_DSTATE_l[2];       // '<S12>/Internal'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S8>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator_DSTATE_p;// '<S9>/Discrete-Time Integrator'
    real_T Internal_DSTATE_k[2];       // '<S15>/Internal'
    real_T MemoryX_DSTATE[2];          // '<S41>/MemoryX'
    real_T IIRgyroz_states[10];        // '<S40>/IIRgyroz'
    real_T UD_DSTATE[2];               // '<S48>/UD'
    real_T Delay_DSTATE[2];            // '<S35>/Delay'
    real_T MemoryX_DSTATE_f[2];        // '<S131>/MemoryX'
    real_T Integrator_DSTATE;          // '<S128>/Integrator'
    real_T Delay2_DSTATE[40];          // '<S42>/Delay2'
    real_T Integrator_DSTATE_e;        // '<S121>/Integrator'
    real_T Delay1_DSTATE[40];          // '<S42>/Delay1'
    real_T FIR_IMUaccel_states_i[15];  // '<S130>/FIR_IMUaccel'
    real_T SimplyIntegrateVelocity_DSTATE[2];// '<S34>/SimplyIntegrateVelocity'
    real_T DiscreteTimeIntegrator_DSTATE_o;// '<S30>/Discrete-Time Integrator'
    real_T DiscreteFilter2_states[3];  // '<S3>/Discrete Filter2'
    real_T DiscreteTransferFcn_states_p;// '<S193>/Discrete Transfer Fcn'
    real_T Memory_PreviousInput;       // '<S32>/Memory'
    int32_T FIR_IMUaccel_circBuf;      // '<S3>/FIR_IMUaccel'
    int32_T FIR_IMUaccel_circBuf_b;    // '<S130>/FIR_IMUaccel'
    int8_T Integrator_PrevResetState;  // '<S128>/Integrator'
    int8_T Integrator_PrevResetState_e;// '<S121>/Integrator'
    uint8_T Integrator_IC_LOADING;     // '<S128>/Integrator'
    uint8_T Integrator_IC_LOADING_g;   // '<S121>/Integrator'
    boolean_T icLoad;                  // '<S41>/MemoryX'
    boolean_T icLoad_m;                // '<S131>/MemoryX'
    boolean_T EnabledSubsystem_MODE;   // '<S159>/Enabled Subsystem'
    boolean_T MeasurementUpdate_MODE;  // '<S153>/MeasurementUpdate'
    boolean_T EnabledSubsystem_MODE_g; // '<S86>/Enabled Subsystem'
    boolean_T MeasurementUpdate_MODE_h;// '<S79>/MeasurementUpdate'
  };

  // Parameters (default storage)
  struct P_FCS_model_T {
    struct_UHvAqkoSM4a4grTGLmN7a Vehicle;// Variable: Vehicle
                                            //  Referenced by:
                                            //    '<S28>/Saturation'
                                            //    '<S29>/Bias'
                                            //    '<S29>/thrustToMotor'

    real_T KDpsi;                      // Variable: KDpsi
                                          //  Referenced by: '<S10>/KDpsi'

    real_T Ts;                         // Variable: Ts
                                          //  Referenced by: '<S191>/Gain'

    real_T g;                          // Variable: g
                                          //  Referenced by: '<S188>/Constant'

    real_T kd_rol;                     // Variable: kd_rol
                                          //  Referenced by: '<S9>/kd_rol'

    real_T ki_rol;                     // Variable: ki_rol
                                          //  Referenced by: '<S9>/ki_rol'

    real_T kp_rol;                     // Variable: kp_rol
                                          //  Referenced by: '<S9>/kp_rol'

    real_T w_c_pitch;                  // Variable: w_c_pitch
                                          //  Referenced by: '<S186>/Gain'

    real_T w_c_roll;                   // Variable: w_c_roll
                                          //  Referenced by: '<S187>/Gain'

    real_T w_c_yaw;                    // Variable: w_c_yaw
                                          //  Referenced by: '<S193>/Gain'

    real_T zDpsi;                      // Variable: zDpsi
                                          //  Referenced by: '<S10>/zDpsi'

    real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S48>/UD'

    real_T LowPassFilterDiscreteorContinuo;
                              // Mask Parameter: LowPassFilterDiscreteorContinuo
                                 //  Referenced by: '<S114>/K'

    real_T LowPassFilterDiscreteorContin_d;
                              // Mask Parameter: LowPassFilterDiscreteorContin_d
                                 //  Referenced by: '<S113>/K'

    real_T LowPassFilterDiscreteorContin_l;
                              // Mask Parameter: LowPassFilterDiscreteorContin_l
                                 //  Referenced by: '<S122>/Time constant'

    real_T LowPassFilterDiscreteorContin_a;
                              // Mask Parameter: LowPassFilterDiscreteorContin_a
                                 //  Referenced by: '<S115>/Time constant'

    real_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S11>/Constant'

    real_T maxp_const;                 // Mask Parameter: maxp_const
                                          //  Referenced by: '<S51>/Constant'

    real_T maxq_const;                 // Mask Parameter: maxq_const
                                          //  Referenced by: '<S53>/Constant'

    real_T maxw1_const;                // Mask Parameter: maxw1_const
                                          //  Referenced by: '<S55>/Constant'

    real_T maxw2_const;                // Mask Parameter: maxw2_const
                                          //  Referenced by: '<S56>/Constant'

    real_T maxdw1_const;               // Mask Parameter: maxdw1_const
                                          //  Referenced by: '<S49>/Constant'

    real_T maxdw2_const;               // Mask Parameter: maxdw2_const
                                          //  Referenced by: '<S50>/Constant'

    real_T maxp2_const;                // Mask Parameter: maxp2_const
                                          //  Referenced by: '<S52>/Constant'

    real_T maxq2_const;                // Mask Parameter: maxq2_const
                                          //  Referenced by: '<S54>/Constant'

    real_T maxw3_const;                // Mask Parameter: maxw3_const
                                          //  Referenced by: '<S57>/Constant'

    real_T maxw4_const;                // Mask Parameter: maxw4_const
                                          //  Referenced by: '<S58>/Constant'

    real_T minHeightforOF_const;       // Mask Parameter: minHeightforOF_const
                                          //  Referenced by: '<S59>/Constant'

    real_T CompareToConstant_const_m;
                                    // Mask Parameter: CompareToConstant_const_m
                                       //  Referenced by: '<S125>/Constant'

    real_T CompareToConstant_const_p;
                                    // Mask Parameter: CompareToConstant_const_p
                                       //  Referenced by: '<S118>/Constant'

    real_T DeactivateAccelerationIfOFisnot;
                              // Mask Parameter: DeactivateAccelerationIfOFisnot
                                 //  Referenced by: '<S43>/Constant'

    real_T donotuseaccifopticalflowneverav;
                              // Mask Parameter: donotuseaccifopticalflowneverav
                                 //  Referenced by: '<S45>/Constant'

    real_T donotuseaccifopticalflownever_c;
                              // Mask Parameter: donotuseaccifopticalflownever_c
                                 //  Referenced by: '<S46>/Constant'

    real_T LowPassFilterDiscreteorContin_i;
                              // Mask Parameter: LowPassFilterDiscreteorContin_i
                                 //  Referenced by: '<S122>/Constant'

    real_T LowPassFilterDiscreteorConti_d0;
                              // Mask Parameter: LowPassFilterDiscreteorConti_d0
                                 //  Referenced by: '<S115>/Constant'

    real_T Constant_Value;             // Expression: 0
                                          //  Referenced by: '<S8>/Constant'

    real_T Kp_Gain;                    // Expression: 4
                                          //  Referenced by: '<S8>/Kp'

    real_T Kd_Gain;                    // Expression: 0.001511390152616
                                          //  Referenced by: '<S8>/Kd'

    real_T Lykyhatkk1_Y0;              // Expression: 0
                                          //  Referenced by: '<S110>/L*(y[k]-yhat[k|k-1])'

    real_T deltax_Y0;                  // Expression: 0
                                          //  Referenced by: '<S112>/deltax'

    real_T Lykyhatkk1_Y0_h;            // Expression: 0
                                          //  Referenced by: '<S182>/L*(y[k]-yhat[k|k-1])'

    real_T deltax_Y0_k;                // Expression: 0
                                          //  Referenced by: '<S184>/deltax'

    real_T DiscreteTransferFcn_NumCoef[2];// Expression: [num_yaw_disc]
                                             //  Referenced by: '<S193>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef[2];// Expression: [den_yaw_disc]
                                             //  Referenced by: '<S193>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                              //  Referenced by: '<S193>/Discrete Transfer Fcn'

    real_T Constant_Value_l;           // Expression: 0
                                          //  Referenced by: '<S119>/Constant'

    real_T Constant_Value_o;           // Expression: 0
                                          //  Referenced by: '<S126>/Constant'

    real_T DiscreteTransferFcn_NumCoef_f[2];// Expression: [num_roll_disc]
                                               //  Referenced by: '<S187>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef_p[2];// Expression: [den_roll_disc]
                                               //  Referenced by: '<S187>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialSt_b;// Expression: 0
                                              //  Referenced by: '<S187>/Discrete Transfer Fcn'

    real_T Constant2_Value;            // Expression: 0
                                          //  Referenced by: '<S3>/Constant2'

    real_T FIR_IMUaccel_InitialStates; // Expression: 0
                                          //  Referenced by: '<S3>/FIR_IMUaccel'

    real_T FIR_IMUaccel_Coefficients[6];
                           // Expression: Estimator.IMU.filterAccel.Coefficients
                              //  Referenced by: '<S3>/FIR_IMUaccel'

    real_T Gain1_Gain;                 // Expression: -1
                                          //  Referenced by: '<S188>/Gain1'

    real_T Gain_Gain;                  // Expression: -1
                                          //  Referenced by: '<S188>/Gain'

    real_T IIR_IMUgyro_r_NumCoef[6];  // Expression: Estimator.IMU.filterGyroNum
                                         //  Referenced by: '<S3>/IIR_IMUgyro_r'

    real_T IIR_IMUgyro_r_DenCoef[6];  // Expression: Estimator.IMU.filterGyroDen
                                         //  Referenced by: '<S3>/IIR_IMUgyro_r'

    real_T IIR_IMUgyro_r_InitialStates;// Expression: 0
                                          //  Referenced by: '<S3>/IIR_IMUgyro_r'

    real_T Gain2_Gain;                 // Expression: -1
                                          //  Referenced by: '<S188>/Gain2'

    real_T Gain3_Gain;                 // Expression: -1
                                          //  Referenced by: '<S188>/Gain3'

    real_T Gain_Gain_p;                // Expression: -1
                                          //  Referenced by: '<S189>/Gain'

    real_T DiscreteTransferFcn_NumCoef_o[2];// Expression: [num_pitch_disc]
                                               //  Referenced by: '<S186>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_DenCoef_b[2];// Expression: [den_pitch_disc]
                                               //  Referenced by: '<S186>/Discrete Transfer Fcn'

    real_T DiscreteTransferFcn_InitialSt_e;// Expression: 0
                                              //  Referenced by: '<S186>/Discrete Transfer Fcn'

    real_T Constant_Value_c;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant'

    real_T Memory_InitialCondition;    // Expression: 0
                                          //  Referenced by: '<S32>/Memory'

    real_T On1Off0forthrust_Gain;      // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=0 for thrust'

    real_T yawequilibrium_Value;       // Expression: 0
                                          //  Referenced by: '<S4>/yaw equilibrium'

    real_T Internal_A[3];              // Computed Parameter: Internal_A
                                          //  Referenced by: '<S18>/Internal'

    real_T Internal_B;                 // Computed Parameter: Internal_B
                                          //  Referenced by: '<S18>/Internal'

    real_T Internal_C[2];              // Computed Parameter: Internal_C
                                          //  Referenced by: '<S18>/Internal'

    real_T Internal_InitialCondition;  // Expression: xinit
                                          //  Referenced by: '<S18>/Internal'

    real_T ChangingofJzz_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jzz'

    real_T On1Off0foryaw_Gain;         // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=0 for yaw'

    real_T pitchequilibrium_Value;     // Expression: 0
                                          //  Referenced by: '<S4>/pitch equilibrium'

    real_T Internal_A_e[3];            // Computed Parameter: Internal_A_e
                                          //  Referenced by: '<S12>/Internal'

    real_T Internal_B_j;               // Computed Parameter: Internal_B_j
                                          //  Referenced by: '<S12>/Internal'

    real_T Internal_C_n[2];            // Computed Parameter: Internal_C_n
                                          //  Referenced by: '<S12>/Internal'

    real_T Internal_InitialCondition_l;// Expression: xinit
                                          //  Referenced by: '<S12>/Internal'

    real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S8>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_IC;  // Expression: 0
                                          //  Referenced by: '<S8>/Discrete-Time Integrator'

    real_T ChangingofJyy_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jyy'

    real_T On1Off0forpitch_Gain;       // Expression: 1
                                          //  Referenced by: '<S1>/On=1//Off=0 for pitch'

    real_T rollequilibrium_Value;      // Expression: 0
                                          //  Referenced by: '<S4>/roll equilibrium'

    real_T DiscreteTimeIntegrator_gainva_k;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_k
                             //  Referenced by: '<S9>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_IC_f;// Expression: 0
                                          //  Referenced by: '<S9>/Discrete-Time Integrator'

    real_T Internal_A_d[3];            // Computed Parameter: Internal_A_d
                                          //  Referenced by: '<S15>/Internal'

    real_T Internal_B_g;               // Computed Parameter: Internal_B_g
                                          //  Referenced by: '<S15>/Internal'

    real_T Internal_C_nj[2];           // Computed Parameter: Internal_C_nj
                                          //  Referenced by: '<S15>/Internal'

    real_T Internal_InitialCondition_h;// Expression: xinit
                                          //  Referenced by: '<S15>/Internal'

    real_T ChangingofJxx_Gain;         // Expression: 0.6
                                          //  Referenced by: '<S4>/Changing of Jxx'

    real_T On1Off0forroll_Gain;        // Expression: 0
                                          //  Referenced by: '<S1>/On=1//Off=0 for roll'

    real_T KalmanGainM_Value[4];       // Expression: pInitialization.M
                                          //  Referenced by: '<S60>/KalmanGainM'

    real_T C_Value[4];                 // Expression: pInitialization.C
                                          //  Referenced by: '<S41>/C'

    real_T A_Value[4];                 // Expression: pInitialization.A
                                          //  Referenced by: '<S41>/A'

    real_T B_Value[4];                 // Expression: pInitialization.B
                                          //  Referenced by: '<S41>/B'

    real_T KalmanGainL_Value[4];       // Expression: pInitialization.L
                                          //  Referenced by: '<S60>/KalmanGainL'

    real_T D_Value[4];                 // Expression: pInitialization.D
                                          //  Referenced by: '<S41>/D'

    real_T A_Value_p[4];               // Expression: pInitialization.A
                                          //  Referenced by: '<S131>/A'

    real_T X0_Value[2];                // Expression: pInitialization.X0
                                          //  Referenced by: '<S41>/X0'

    real_T IIRgyroz_NumCoef[6];       // Expression: Estimator.IMU.filterGyroNum
                                         //  Referenced by: '<S40>/IIRgyroz'

    real_T IIRgyroz_DenCoef[6];       // Expression: Estimator.IMU.filterGyroDen
                                         //  Referenced by: '<S40>/IIRgyroz'

    real_T IIRgyroz_InitialStates;     // Expression: 0
                                          //  Referenced by: '<S40>/IIRgyroz'

    real_T TSamp_WtEt;                 // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S48>/TSamp'

    real_T Delay_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S35>/Delay'

    real_T X0_Value_n[2];              // Expression: pInitialization.X0
                                          //  Referenced by: '<S131>/X0'

    real_T Converttometers_Gain;       // Expression: -0.01
                                          //  Referenced by: '<S3>/Convert to meters'

    real_T Constant_Value_h[2];        // Expression: [0;0]
                                          //  Referenced by: '<S130>/Constant'

    real_T KalmanGainM_Value_b[2];     // Expression: pInitialization.M
                                          //  Referenced by: '<S133>/KalmanGainM'

    real_T C_Value_f[2];               // Expression: pInitialization.C
                                          //  Referenced by: '<S131>/C'

    real_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S128>/Integrator'

    real_T Integrator_UpperSat;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S128>/Integrator'

    real_T Integrator_LowerSat;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S128>/Integrator'

    real_T Saturation_UpperSat;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S128>/Saturation'

    real_T Saturation_LowerSat;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S128>/Saturation'

    real_T Delay2_InitialCondition;    // Expression: 0.0
                                          //  Referenced by: '<S42>/Delay2'

    real_T Bias3_Bias;                 // Expression: 2
                                          //  Referenced by: '<S42>/Bias3'

    real_T Gain5_Gain;                 // Expression: 1/100
                                          //  Referenced by: '<S42>/Gain5'

    real_T Integrator_gainval_g;     // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S121>/Integrator'

    real_T Integrator_UpperSat_i;      // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S121>/Integrator'

    real_T Integrator_LowerSat_l;      // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S121>/Integrator'

    real_T Saturation_UpperSat_k;      // Expression: windupUpperLimit
                                          //  Referenced by: '<S121>/Saturation'

    real_T Saturation_LowerSat_h;      // Expression: windupLowerLimit
                                          //  Referenced by: '<S121>/Saturation'

    real_T Delay1_InitialCondition;    // Expression: 0.0
                                          //  Referenced by: '<S42>/Delay1'

    real_T Bias2_Bias;                 // Expression: 2
                                          //  Referenced by: '<S42>/Bias2'

    real_T Gain4_Gain;                 // Expression: 1/100
                                          //  Referenced by: '<S42>/Gain4'

    real_T Constant_Value_c1[2];       // Expression: [0 0]
                                          //  Referenced by: '<S31>/Constant'

    real_T FIR_IMUaccel_InitialStates_b;// Expression: 0
                                           //  Referenced by: '<S130>/FIR_IMUaccel'

    real_T FIR_IMUaccel_Coefficients_a[6];
                           // Expression: Estimator.IMU.filterAccel.Coefficients
                              //  Referenced by: '<S130>/FIR_IMUaccel'

    real_T gravity_Value[3];           // Expression: [0 0 g]
                                          //  Referenced by: '<S130>/gravity'

    real_T gravity_Value_a[3];         // Expression: [0 0 -g]
                                          //  Referenced by: '<S39>/gravity'

    real_T gainaccinput_Gain; // Expression: Estimator.pos.accelerationInputGain
                                 //  Referenced by: '<S39>/gainaccinput'

    real_T B_Value_o[2];               // Expression: pInitialization.B
                                          //  Referenced by: '<S131>/B'

    real_T D_Value_k;                  // Expression: pInitialization.D
                                          //  Referenced by: '<S131>/D'

    real_T KalmanGainL_Value_m[2];     // Expression: pInitialization.L
                                          //  Referenced by: '<S133>/KalmanGainL'

    real_T SimplyIntegrateVelocity_gainval;
                          // Computed Parameter: SimplyIntegrateVelocity_gainval
                             //  Referenced by: '<S34>/SimplyIntegrateVelocity'

    real_T SimplyIntegrateVelocity_IC; // Expression: 0
                                          //  Referenced by: '<S34>/SimplyIntegrateVelocity'

    real_T Gain3_Gain_g;               // Expression: .2
                                          //  Referenced by: '<S22>/Gain3'

    real_T Gain4_Gain_m;               // Expression: .2
                                          //  Referenced by: '<S22>/Gain4'

    real_T Gain1_Gain_b;               // Expression: -1
                                          //  Referenced by: '<S22>/Gain1'

    real_T Saturation_UpperSat_d;      // Expression: pi/4
                                          //  Referenced by: '<S22>/Saturation'

    real_T Saturation_LowerSat_a;      // Expression: -pi/4
                                          //  Referenced by: '<S22>/Saturation'

    real_T Pos1Dashboard0_Value;       // Expression: 0
                                          //  Referenced by: '<S1>/Pos=1//Dashboard=0'

    real_T Switch1_Threshold;          // Expression: 0
                                          //  Referenced by: '<S4>/Switch1'

    real_T Gain4_Gain_h;               // Expression: .2
                                          //  Referenced by: '<S23>/Gain4'

    real_T Gain3_Gain_i;               // Expression: .2
                                          //  Referenced by: '<S23>/Gain3'

    real_T Gain1_Gain_i;               // Expression: 1
                                          //  Referenced by: '<S23>/Gain1'

    real_T Saturation_UpperSat_ku;     // Expression: pi/4
                                          //  Referenced by: '<S23>/Saturation'

    real_T Saturation_LowerSat_j;      // Expression: -pi/4
                                          //  Referenced by: '<S23>/Saturation'

    real_T Switch2_Threshold;          // Expression: 0
                                          //  Referenced by: '<S4>/Switch2'

    real_T Constant_Value_e;           // Expression: 0
                                          //  Referenced by: '<S6>/Constant'

    real_T DiscreteTimeIntegrator_gainva_i;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_i
                             //  Referenced by: '<S30>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_IC_p;// Expression: 0
                                          //  Referenced by: '<S30>/Discrete-Time Integrator'

    real_T Gain_Gain_h;                // Expression: 1/(60*60)
                                          //  Referenced by: '<S30>/Gain'

    real_T DiscreteFilter2_NumCoef[4]; // Expression: Estimator.alt.filterPrsNum
                                          //  Referenced by: '<S3>/Discrete Filter2'

    real_T DiscreteFilter2_DenCoef[4]; // Expression: Estimator.alt.filterPrsDen
                                          //  Referenced by: '<S3>/Discrete Filter2'

    real_T DiscreteFilter2_InitialStates;// Expression: 0
                                            //  Referenced by: '<S3>/Discrete Filter2'

    real_T Ki_Gain;                    // Expression: 0
                                          //  Referenced by: '<S8>/Ki'

    real_T CovarianceZ_Value[4];       // Expression: pInitialization.Z
                                          //  Referenced by: '<S60>/CovarianceZ'

    real_T CovarianceZ_Value_g[4];     // Expression: pInitialization.Z
                                          //  Referenced by: '<S133>/CovarianceZ'

    real32_T TorqueTotalThrustToThrustPerMot[16];// Expression: Controller.Q2Ts
                                                    //  Referenced by: '<S27>/TorqueTotalThrustToThrustPerMotor'

    real32_T inverseIMU_gain_Gain[6];// Computed Parameter: inverseIMU_gain_Gain
                                        //  Referenced by: '<S3>/inverseIMU_gain'

    boolean_T Enable_Value;            // Expression: true()
                                          //  Referenced by: '<S131>/Enable'

    boolean_T isSqrtUsed_Value;        // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S108>/isSqrtUsed'

    boolean_T isSqrtUsed_Value_a;      // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S180>/isSqrtUsed'

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
  // private member function(s) for subsystem '<S108>/SqrtUsedFcn'
  static void FCS_model_SqrtUsedFcn(const real_T rtu_u[4], boolean_T
    rtu_isSqrtUsed, real_T rty_P[4]);

  // Real-Time Model
  RT_MODEL_FCS_model_T FCS_model_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Constant' : Unused code path elimination
//  Block '<S9>/RollScope' : Unused code path elimination
//  Block '<S21>/Gain' : Unused code path elimination
//  Block '<S21>/Gain1' : Unused code path elimination
//  Block '<S21>/Gain2' : Unused code path elimination
//  Block '<S24>/Internal' : Unused code path elimination
//  Block '<S21>/Sum' : Unused code path elimination
//  Block '<S22>/Scope1' : Unused code path elimination
//  Block '<S23>/Scope' : Unused code path elimination
//  Block '<S1>/Scope1' : Unused code path elimination
//  Block '<S29>/Scope1' : Unused code path elimination
//  Block '<S29>/Scope2' : Unused code path elimination
//  Block '<S48>/Data Type Duplicate' : Unused code path elimination
//  Block '<S102>/Data Type Duplicate' : Unused code path elimination
//  Block '<S103>/Data Type Duplicate' : Unused code path elimination
//  Block '<S104>/Conversion' : Unused code path elimination
//  Block '<S104>/Data Type Duplicate' : Unused code path elimination
//  Block '<S105>/Data Type Duplicate' : Unused code path elimination
//  Block '<S63>/Data Type Duplicate' : Unused code path elimination
//  Block '<S64>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/Data Type Duplicate' : Unused code path elimination
//  Block '<S66>/Data Type Duplicate' : Unused code path elimination
//  Block '<S67>/Data Type Duplicate' : Unused code path elimination
//  Block '<S68>/Data Type Duplicate' : Unused code path elimination
//  Block '<S69>/Data Type Duplicate' : Unused code path elimination
//  Block '<S70>/Conversion' : Unused code path elimination
//  Block '<S70>/Data Type Duplicate' : Unused code path elimination
//  Block '<S71>/Data Type Duplicate' : Unused code path elimination
//  Block '<S72>/Data Type Duplicate' : Unused code path elimination
//  Block '<S73>/Data Type Duplicate' : Unused code path elimination
//  Block '<S75>/Data Type Duplicate' : Unused code path elimination
//  Block '<S76>/Data Type Duplicate' : Unused code path elimination
//  Block '<S41>/G' : Unused code path elimination
//  Block '<S41>/H' : Unused code path elimination
//  Block '<S41>/N' : Unused code path elimination
//  Block '<S41>/P0' : Unused code path elimination
//  Block '<S41>/Q' : Unused code path elimination
//  Block '<S41>/R' : Unused code path elimination
//  Block '<S91>/CheckSignalProperties' : Unused code path elimination
//  Block '<S100>/CheckSignalProperties' : Unused code path elimination
//  Block '<S101>/CheckSignalProperties' : Unused code path elimination
//  Block '<S35>/dxy_est' : Unused code path elimination
//  Block '<S35>/optical flow' : Unused code path elimination
//  Block '<S130>/Constant1' : Unused code path elimination
//  Block '<S130>/Discrete Filter' : Unused code path elimination
//  Block '<S175>/Data Type Duplicate' : Unused code path elimination
//  Block '<S176>/Data Type Duplicate' : Unused code path elimination
//  Block '<S177>/Conversion' : Unused code path elimination
//  Block '<S177>/Data Type Duplicate' : Unused code path elimination
//  Block '<S178>/Data Type Duplicate' : Unused code path elimination
//  Block '<S134>/Product' : Unused code path elimination
//  Block '<S136>/Data Type Duplicate' : Unused code path elimination
//  Block '<S137>/Data Type Duplicate' : Unused code path elimination
//  Block '<S138>/Data Type Duplicate' : Unused code path elimination
//  Block '<S139>/Data Type Duplicate' : Unused code path elimination
//  Block '<S141>/Data Type Duplicate' : Unused code path elimination
//  Block '<S142>/Data Type Duplicate' : Unused code path elimination
//  Block '<S143>/Data Type Duplicate' : Unused code path elimination
//  Block '<S144>/Conversion' : Unused code path elimination
//  Block '<S144>/Data Type Duplicate' : Unused code path elimination
//  Block '<S145>/Data Type Duplicate' : Unused code path elimination
//  Block '<S146>/Data Type Duplicate' : Unused code path elimination
//  Block '<S147>/Data Type Duplicate' : Unused code path elimination
//  Block '<S149>/Data Type Duplicate' : Unused code path elimination
//  Block '<S150>/Data Type Duplicate' : Unused code path elimination
//  Block '<S131>/G' : Unused code path elimination
//  Block '<S131>/H' : Unused code path elimination
//  Block '<S131>/N' : Unused code path elimination
//  Block '<S131>/P0' : Unused code path elimination
//  Block '<S131>/Q' : Unused code path elimination
//  Block '<S131>/R' : Unused code path elimination
//  Block '<S131>/Reshapeyhat' : Unused code path elimination
//  Block '<S173>/CheckSignalProperties' : Unused code path elimination
//  Block '<S174>/CheckSignalProperties' : Unused code path elimination
//  Block '<S130>/Product3' : Unused code path elimination
//  Block '<S130>/Scope' : Unused code path elimination
//  Block '<S130>/Scope1' : Unused code path elimination
//  Block '<S130>/Scope2' : Unused code path elimination
//  Block '<S130>/Sum1' : Unused code path elimination
//  Block '<S130>/gravity1' : Unused code path elimination
//  Block '<S130>/prsToAltGain' : Unused code path elimination
//  Block '<S130>/thrust2acc' : Unused code path elimination
//  Block '<S31>/Scope' : Unused code path elimination
//  Block '<S31>/Scope1' : Unused code path elimination
//  Block '<S3>/Constant' : Unused code path elimination
//  Block '<S3>/Constant1' : Unused code path elimination
//  Block '<S3>/Discrete-Time Integrator' : Unused code path elimination
//  Block '<S3>/Gain' : Unused code path elimination
//  Block '<S3>/Multiply' : Unused code path elimination
//  Block '<S3>/Sum' : Unused code path elimination
//  Block '<S3>/Switch' : Unused code path elimination
//  Block '<S3>/Switch1' : Unused code path elimination
//  Block '<S9>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S9>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S10>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S28>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S38>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S47>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S102>/Conversion' : Eliminate redundant data type conversion
//  Block '<S103>/Conversion' : Eliminate redundant data type conversion
//  Block '<S105>/Conversion' : Eliminate redundant data type conversion
//  Block '<S41>/DataTypeConversionEnable' : Eliminate redundant data type conversion
//  Block '<S75>/Conversion' : Eliminate redundant data type conversion
//  Block '<S79>/Reshape' : Reshape block reduction
//  Block '<S41>/ReshapeX0' : Reshape block reduction
//  Block '<S41>/Reshapeu' : Reshape block reduction
//  Block '<S41>/Reshapexhat' : Reshape block reduction
//  Block '<S130>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S175>/Conversion' : Eliminate redundant data type conversion
//  Block '<S176>/Conversion' : Eliminate redundant data type conversion
//  Block '<S178>/Conversion' : Eliminate redundant data type conversion
//  Block '<S149>/Conversion' : Eliminate redundant data type conversion
//  Block '<S153>/Reshape' : Reshape block reduction
//  Block '<S131>/ReshapeX0' : Reshape block reduction
//  Block '<S131>/Reshapeu' : Reshape block reduction
//  Block '<S131>/Reshapexhat' : Reshape block reduction
//  Block '<S131>/Reshapey' : Reshape block reduction
//  Block '<S185>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S188>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S188>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S188>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S188>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S189>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S189>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S189>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S189>/Zero-Order Hold3' : Eliminated since input and output rates are identical
//  Block '<S189>/Zero-Order Hold4' : Eliminated since input and output rates are identical


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
//  '<S11>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/Compare To Constant'
//  '<S12>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/LTI System5'
//  '<S13>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/LTI System5/Input Delay'
//  '<S14>'  : 'FCS_model/Controllers/Orientation/Pitch Controller/LTI System5/Output Delay'
//  '<S15>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5'
//  '<S16>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5/Input Delay'
//  '<S17>'  : 'FCS_model/Controllers/Orientation/Roll Controller/LTI System5/Output Delay'
//  '<S18>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5'
//  '<S19>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5/Input Delay'
//  '<S20>'  : 'FCS_model/Controllers/Orientation/Yaw Controller/LTI System5/Output Delay'
//  '<S21>'  : 'FCS_model/Controllers/Position/Altitude'
//  '<S22>'  : 'FCS_model/Controllers/Position/X_controller'
//  '<S23>'  : 'FCS_model/Controllers/Position/Y_controller'
//  '<S24>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5'
//  '<S25>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5/Input Delay'
//  '<S26>'  : 'FCS_model/Controllers/Position/Altitude/LTI System5/Output Delay'
//  '<S27>'  : 'FCS_model/Controllers/post_processing/ControlMixer'
//  '<S28>'  : 'FCS_model/Controllers/post_processing/power_slider'
//  '<S29>'  : 'FCS_model/Controllers/post_processing/thrustsToMotorCommands'
//  '<S30>'  : 'FCS_model/Estimatiors/Battery'
//  '<S31>'  : 'FCS_model/Estimatiors/Position Estimation'
//  '<S32>'  : 'FCS_model/Estimatiors/Subsystem Reference'
//  '<S33>'  : 'FCS_model/Estimatiors/estimators actve'
//  '<S34>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYPosition'
//  '<S35>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity'
//  '<S36>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ'
//  '<S37>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix'
//  '<S38>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S39>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling'
//  '<S40>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling'
//  '<S41>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy'
//  '<S42>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup'
//  '<S43>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/Deactivate Acceleration If OF is not used due to low altitude'
//  '<S44>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix'
//  '<S45>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)'
//  '<S46>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)1'
//  '<S47>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S48>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/DiscreteDerivative'
//  '<S49>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxdw1'
//  '<S50>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxdw2'
//  '<S51>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxp'
//  '<S52>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxp2'
//  '<S53>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxq'
//  '<S54>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxq2'
//  '<S55>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw1'
//  '<S56>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw2'
//  '<S57>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw3'
//  '<S58>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/maxw4'
//  '<S59>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/DataHandling/minHeightforOF'
//  '<S60>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL'
//  '<S61>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculateYhat'
//  '<S62>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator'
//  '<S63>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionA'
//  '<S64>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionB'
//  '<S65>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionC'
//  '<S66>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionD'
//  '<S67>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionG'
//  '<S68>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionH'
//  '<S69>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionN'
//  '<S70>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionP'
//  '<S71>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionP0'
//  '<S72>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionQ'
//  '<S73>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionR'
//  '<S74>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionReset'
//  '<S75>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionX'
//  '<S76>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionX0'
//  '<S77>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/DataTypeConversionu'
//  '<S78>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/MemoryP'
//  '<S79>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Observer'
//  '<S80>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ReducedQRN'
//  '<S81>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Reset'
//  '<S82>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Reshapeyhat'
//  '<S83>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ScalarExpansionP0'
//  '<S84>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ScalarExpansionQ'
//  '<S85>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ScalarExpansionR'
//  '<S86>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/UseCurrentEstimator'
//  '<S87>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkA'
//  '<S88>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkB'
//  '<S89>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkC'
//  '<S90>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkD'
//  '<S91>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkEnable'
//  '<S92>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkG'
//  '<S93>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkH'
//  '<S94>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkN'
//  '<S95>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkP0'
//  '<S96>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkQ'
//  '<S97>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkR'
//  '<S98>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkReset'
//  '<S99>'  : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checkX0'
//  '<S100>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checku'
//  '<S101>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/checky'
//  '<S102>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionL'
//  '<S103>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionM'
//  '<S104>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionP'
//  '<S105>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionZ'
//  '<S106>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculatePL/Ground'
//  '<S107>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CalculateYhat/Ground'
//  '<S108>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator/decideOutput'
//  '<S109>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S110>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/Observer/MeasurementUpdate'
//  '<S111>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/ReducedQRN/Ground'
//  '<S112>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/KalmanFilter_dxdy/UseCurrentEstimator/Enabled Subsystem'
//  '<S113>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2'
//  '<S114>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3'
//  '<S115>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant'
//  '<S116>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Initialization'
//  '<S117>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Integrator (Discrete or Continuous)'
//  '<S118>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant/Compare To Constant'
//  '<S119>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Enable//disable time constant/Compare To Zero'
//  '<S120>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Initialization/Init_u'
//  '<S121>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)2/Integrator (Discrete or Continuous)/Discrete'
//  '<S122>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant'
//  '<S123>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Initialization'
//  '<S124>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Integrator (Discrete or Continuous)'
//  '<S125>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant/Compare To Constant'
//  '<S126>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Enable//disable time constant/Compare To Zero'
//  '<S127>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Initialization/Init_u'
//  '<S128>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorXYVelocity/OpticalFlowCleanup/Low-Pass Filter (Discrete or Continuous)3/Integrator (Discrete or Continuous)/Discrete'
//  '<S129>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher'
//  '<S130>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot'
//  '<S131>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1'
//  '<S132>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/Rotation Angles to Direction Cosine Matrix'
//  '<S133>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CalculatePL'
//  '<S134>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CalculateYhat'
//  '<S135>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CovarianceOutputConfigurator'
//  '<S136>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionA'
//  '<S137>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionB'
//  '<S138>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionC'
//  '<S139>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionD'
//  '<S140>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionEnable'
//  '<S141>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionG'
//  '<S142>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionH'
//  '<S143>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionN'
//  '<S144>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionP'
//  '<S145>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionP0'
//  '<S146>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionQ'
//  '<S147>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionR'
//  '<S148>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionReset'
//  '<S149>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionX'
//  '<S150>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionX0'
//  '<S151>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/DataTypeConversionu'
//  '<S152>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/MemoryP'
//  '<S153>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/Observer'
//  '<S154>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/ReducedQRN'
//  '<S155>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/Reset'
//  '<S156>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/ScalarExpansionP0'
//  '<S157>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/ScalarExpansionQ'
//  '<S158>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/ScalarExpansionR'
//  '<S159>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/UseCurrentEstimator'
//  '<S160>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkA'
//  '<S161>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkB'
//  '<S162>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkC'
//  '<S163>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkD'
//  '<S164>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkEnable'
//  '<S165>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkG'
//  '<S166>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkH'
//  '<S167>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkN'
//  '<S168>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkP0'
//  '<S169>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkQ'
//  '<S170>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkR'
//  '<S171>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkReset'
//  '<S172>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checkX0'
//  '<S173>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checku'
//  '<S174>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/checky'
//  '<S175>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CalculatePL/DataTypeConversionL'
//  '<S176>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CalculatePL/DataTypeConversionM'
//  '<S177>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CalculatePL/DataTypeConversionP'
//  '<S178>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CalculatePL/DataTypeConversionZ'
//  '<S179>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CalculatePL/Ground'
//  '<S180>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CovarianceOutputConfigurator/decideOutput'
//  '<S181>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S182>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/Observer/MeasurementUpdate'
//  '<S183>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/ReducedQRN/Ground'
//  '<S184>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/KalmanFilter_altitude1/UseCurrentEstimator/Enabled Subsystem'
//  '<S185>' : 'FCS_model/Estimatiors/Position Estimation/EstimatorZ/Estimator Switcher/Parrot/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S186>' : 'FCS_model/Estimatiors/Subsystem Reference/Complementary Filter for Pitch (disc.)'
//  '<S187>' : 'FCS_model/Estimatiors/Subsystem Reference/Complementary Filter for Roll (disc.)'
//  '<S188>' : 'FCS_model/Estimatiors/Subsystem Reference/Roll and Pitch Angles (Lecture 2, slide 39)'
//  '<S189>' : 'FCS_model/Estimatiors/Subsystem Reference/Roll, Pitch, and Yaw Rates (Lecture1, slide 22)1'
//  '<S190>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator'
//  '<S191>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator/If Action Subsystem3'
//  '<S192>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator/If Action Subsystem'
//  '<S193>' : 'FCS_model/Estimatiors/Subsystem Reference/yaw estimator/If Action Subsystem/Complementary Filter for Yaw (disc.)'

#endif                                 // FCS_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
