//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 11.147
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Tue Nov 10 18:31:25 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FCS_model.h"

// Block parameters (default storage)
FCS_model::P_FCS_model_T FCS_model::FCS_model_P = {
  // Variable: Vehicle
  //  Referenced by:
  //    '<S29>/Saturation'
  //    '<S30>/thrustToMotor'

  {
    {
      0.0,
      1.0
    },

    {
      -71.3232,

      {
        0.0
      }
    },

    {
      0.077,

      { 2.8799e-5, 0.0, 0.0, 0.0, 4.3333e-5, 0.0, 0.0, 0.0, 5.8483e-5 },
      0.0624,
      0.044123463146040563,
      -0.015876,
      0.0,
      0.0,
      0.01
    },

    {
      5.065e-8,
      4.9687650000000007e-10,
      3.0,
      0.022,
      0.0015205308443374597,
      0.01,
      0.0,
      0.00043,
      5.202999999999999e-8,
      0.0,
      0.0,
      5.202999999999999e-8,
      0.00057023800510402694,
      9.6287351312041945e-6,
      0.43405893570516918,
      0.59341194567807209,
      0.33161255787892263,
      -0.26179938779914946,
      0.39706240482871,
      5.5,
      0.29319144186046509,
      4.9687650000000007e-10,
      1.8457982054709583e-13,
      4.9687650000000007e-10
    },

    {
      0.95,
      0.15,
      1500000000.0,
      0.1,
      0.013162224415926292,
      1.9902
    }
  },

  // Variable: Veh
  //  Referenced by:
  //    '<S9>/Saturation'
  //    '<S10>/Saturation'
  //    '<S21>/g-feedforward'

  {
    {
      0.0836,
      2.8799e-5,
      4.3333e-5,
      5.8483e-5,

      { 2.8799e-5, 0.0, 0.0, 0.0, 4.3333e-5, 0.0, 0.0, 0.0, 5.8483e-5 },
      0.08
    },

    {
      3.0,
      0.022,
      0.0015205308443374597,
      0.01,
      0.0004225,
      5.11225e-8
    },

    {
      0.0
    },

    {
      1.9,
      0.0167
    },

    {
      2.0
    }
  },

  // Variable: Env
  //  Referenced by: '<S21>/g-feedforward'

  {
    9.81,
    1.184
  },

  // Variable: Ts
  //  Referenced by: '<S195>/Gain'

  0.0025,

  // Variable: g
  //  Referenced by: '<S191>/Constant'

  9.81,

  // Variable: kd_pit
  //  Referenced by: '<S9>/Kd'

  0.00156518796,

  // Variable: kd_rol
  //  Referenced by: '<S10>/kd_rol'

  0.0010579224489795918,

  // Variable: kd_yaw
  //  Referenced by: '<S11>/Kd'

  0.00023393199999999998,

  // Variable: ki_pit
  //  Referenced by: '<S9>/Ki'

  0.008407544021739129,

  // Variable: ki_rol
  //  Referenced by: '<S10>/ki_rol1'

  0.004198104956268222,

  // Variable: kp_pit
  //  Referenced by: '<S9>/Kp'

  0.00521267729347826,

  // Variable: kp_rol
  //  Referenced by: '<S10>/kp_rol'

  0.0039021385568513119,

  // Variable: kp_yaw
  //  Referenced by: '<S11>/Kp'

  0.00066940175981915033,

  // Variable: w_c_pitch
  //  Referenced by: '<S189>/Gain'

  0.3,

  // Variable: w_c_roll
  //  Referenced by: '<S190>/Gain'

  0.2,

  // Variable: w_c_yaw
  //  Referenced by: '<S197>/Gain'

  55.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S49>/UD'

  0.0,

  // Mask Parameter: LowPassFilterDiscreteorContinuo
  //  Referenced by: '<S115>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_d
  //  Referenced by: '<S114>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_l
  //  Referenced by: '<S123>/Time constant'

  0.1,

  // Mask Parameter: LowPassFilterDiscreteorContin_a
  //  Referenced by: '<S116>/Time constant'

  0.1,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S8>/Constant'

  0.0,

  // Mask Parameter: maxp_const
  //  Referenced by: '<S52>/Constant'

  0.6,

  // Mask Parameter: maxq_const
  //  Referenced by: '<S54>/Constant'

  0.6,

  // Mask Parameter: maxw1_const
  //  Referenced by: '<S56>/Constant'

  7.0,

  // Mask Parameter: maxw2_const
  //  Referenced by: '<S57>/Constant'

  7.0,

  // Mask Parameter: maxdw1_const
  //  Referenced by: '<S50>/Constant'

  80.0,

  // Mask Parameter: maxdw2_const
  //  Referenced by: '<S51>/Constant'

  80.0,

  // Mask Parameter: maxp2_const
  //  Referenced by: '<S53>/Constant'

  0.5,

  // Mask Parameter: maxq2_const
  //  Referenced by: '<S55>/Constant'

  0.5,

  // Mask Parameter: maxw3_const
  //  Referenced by: '<S58>/Constant'

  5.0,

  // Mask Parameter: maxw4_const
  //  Referenced by: '<S59>/Constant'

  5.0,

  // Mask Parameter: rangefinderOutlier_const
  //  Referenced by: '<S187>/Constant'

  0.3,

  // Mask Parameter: minHeightforOF_const
  //  Referenced by: '<S60>/Constant'

  -0.1,

  // Mask Parameter: CompareToConstant_const_m
  //  Referenced by: '<S126>/Constant'

  2.0,

  // Mask Parameter: CompareToConstant_const_p
  //  Referenced by: '<S119>/Constant'

  2.0,

  // Mask Parameter: DeactivateAccelerationIfOFisnot
  //  Referenced by: '<S44>/Constant'

  -0.1,

  // Mask Parameter: donotuseaccifopticalflowneverav
  //  Referenced by: '<S46>/Constant'

  0.0,

  // Mask Parameter: donotuseaccifopticalflownever_c
  //  Referenced by: '<S47>/Constant'

  0.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_i
  //  Referenced by: '<S123>/Constant'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorConti_d0
  //  Referenced by: '<S116>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S111>/L*(y[k]-yhat[k|k-1])'

  0.0,

  // Expression: 0
  //  Referenced by: '<S113>/deltax'

  0.0,

  // Expression: 0
  //  Referenced by: '<S183>/L*(y[k]-yhat[k|k-1])'

  0.0,

  // Expression: 0
  //  Referenced by: '<S185>/deltax'

  0.0,

  // Expression: [num_yaw_disc]
  //  Referenced by: '<S197>/Discrete Transfer Fcn'

  { 0.0, 0.0023357390909607661 },

  // Expression: [den_yaw_disc]
  //  Referenced by: '<S197>/Discrete Transfer Fcn'

  { 1.0, -0.87153434999715784 },

  // Expression: 0
  //  Referenced by: '<S197>/Discrete Transfer Fcn'

  0.0,

  // Expression: 0
  //  Referenced by: '<S120>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S127>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S190>/Memory'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Constant2'

  0.0,

  // Expression: -1
  //  Referenced by: '<S191>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S191>/Gain3'

  -1.0,

  // Expression: Estimator.IMU.filterGyroNum
  //  Referenced by: '<S3>/IIR_IMUgyro_r'

  { 0.28212412246252078, 1.2725392917168605, 2.4208439774454451,
    2.4208439774454451, 1.27253929171686, 0.28212412246252072 },

  // Expression: Estimator.IMU.filterGyroDen
  //  Referenced by: '<S3>/IIR_IMUgyro_r'

  { 1.0, 2.2287149173647669, 2.5244618916938615, 1.5772531712757021,
    0.5410224068298175, 0.079562396085500878 },

  // Expression: 0
  //  Referenced by: '<S3>/IIR_IMUgyro_r'

  0.0,

  // Expression: -1
  //  Referenced by: '<S191>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S191>/Gain'

  -1.0,

  // Expression: [num_roll_disc]
  //  Referenced by: '<S190>/Discrete Transfer Fcn'

  { 0.0012496875781054736, 0.0012496875781054736 },

  // Expression: [den_roll_disc]
  //  Referenced by: '<S190>/Discrete Transfer Fcn'

  { 1.0, -0.99950012496875773 },

  // Expression: -1
  //  Referenced by: '<S192>/Gain'

  -1.0,

  // Expression: [num_pitch_disc]
  //  Referenced by: '<S189>/Discrete Transfer Fcn'

  { 0.0012495314257153568, 0.0012495314257153568 },

  // Expression: [den_pitch_disc]
  //  Referenced by: '<S189>/Discrete Transfer Fcn'

  { 1.0, -0.99925028114457093 },

  // Expression: 0
  //  Referenced by: '<S189>/Discrete Transfer Fcn'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Memory'

  0.0,

  // Expression: 0.7
  //  Referenced by: '<S21>/Gain'

  0.7,

  // Expression: 1
  //  Referenced by: '<S1>/On=1//Off=0 for thrust'

  1.0,

  // Expression: 0
  //  Referenced by: '<S4>/roll equilibrium'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S10>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S10>/Discrete-Time Integrator'

  0.0,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S15>/Internal'

  { 1.9893934974557008, -0.98944944993464679, 1.0 },

  // Computed Parameter: Internal_B
  //  Referenced by: '<S15>/Internal'

  0.0078125,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S15>/Internal'

  { 0.003587288952907052, 0.003574628352175261 },

  // Expression: xinit
  //  Referenced by: '<S15>/Internal'

  0.0,

  // Expression: num_rate{1}
  //  Referenced by: '<S33>/Discrete Transfer Fcn'

  { 0.0, 0.060586937186524213 },

  // Expression: den_rate{1}
  //  Referenced by: '<S33>/Discrete Transfer Fcn'

  { 1.0, -0.93941306281347581 },

  // Expression: 0
  //  Referenced by: '<S33>/Discrete Transfer Fcn'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jxx'

  0.6,

  // Expression: -1
  //  Referenced by: '<S1>/On=-1//Off=0 for roll'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S4>/pitch equilibrium'

  0.0,

  // Computed Parameter: Internal_A_e
  //  Referenced by: '<S12>/Internal'

  { 1.9893934974557008, -0.98944944993464679, 1.0 },

  // Computed Parameter: Internal_B_j
  //  Referenced by: '<S12>/Internal'

  0.0078125,

  // Computed Parameter: Internal_C_n
  //  Referenced by: '<S12>/Internal'

  { 0.003587288952907052, 0.003574628352175261 },

  // Expression: xinit
  //  Referenced by: '<S12>/Internal'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_k
  //  Referenced by: '<S9>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S9>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/imbalance feed forward'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jyy'

  0.6,

  // Expression: 0
  //  Referenced by: '<S1>/On=-1//Off=0 for pitch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/yaw equilibrium'

  0.0,

  // Computed Parameter: Internal_A_l
  //  Referenced by: '<S18>/Internal'

  { 1.9893934974557008, -0.98944944993464679, 1.0 },

  // Computed Parameter: Internal_B_e
  //  Referenced by: '<S18>/Internal'

  0.0078125,

  // Computed Parameter: Internal_C_j
  //  Referenced by: '<S18>/Internal'

  { 0.003587288952907052, 0.003574628352175261 },

  // Expression: xinit
  //  Referenced by: '<S18>/Internal'

  0.0,

  // Expression: 0.00001
  //  Referenced by: '<S11>/Saturation'

  1.0E-5,

  // Expression: -0.00001
  //  Referenced by: '<S11>/Saturation'

  -1.0E-5,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jzz'

  0.6,

  // Expression: -1
  //  Referenced by: '<S1>/On=-1//Off=0 for yaw'

  -1.0,

  // Expression: pInitialization.M
  //  Referenced by: '<S61>/KalmanGainM'

  { 0.12546560898608972, 0.0, 0.0, 0.12546560898608972 },

  // Expression: pInitialization.C
  //  Referenced by: '<S42>/C'

  { 1.0, 0.0, 0.0, 1.0 },

  // Expression: pInitialization.A
  //  Referenced by: '<S42>/A'

  { 1.0, 0.0, 0.0, 1.0 },

  // Expression: pInitialization.B
  //  Referenced by: '<S42>/B'

  { 0.0025, 0.0, 0.0, 0.0025 },

  // Expression: pInitialization.L
  //  Referenced by: '<S61>/KalmanGainL'

  { 0.12546560898608977, 0.0, -0.0, 0.12546560898608977 },

  // Expression: pInitialization.D
  //  Referenced by: '<S42>/D'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: pInitialization.A
  //  Referenced by: '<S132>/A'

  { 1.0, 0.0, 0.0025, 1.0 },

  // Expression: pInitialization.X0
  //  Referenced by: '<S42>/X0'

  { 0.0, 0.0 },

  // Expression: Estimator.IMU.filterGyroNum
  //  Referenced by: '<S41>/IIRgyroz'

  { 0.28212412246252078, 1.2725392917168605, 2.4208439774454451,
    2.4208439774454451, 1.27253929171686, 0.28212412246252072 },

  // Expression: Estimator.IMU.filterGyroDen
  //  Referenced by: '<S41>/IIRgyroz'

  { 1.0, 2.2287149173647669, 2.5244618916938615, 1.5772531712757021,
    0.5410224068298175, 0.079562396085500878 },

  // Expression: 0
  //  Referenced by: '<S41>/IIRgyroz'

  0.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S49>/TSamp'

  400.0,

  // Expression: 0
  //  Referenced by: '<S36>/Delay'

  0.0,

  // Expression: pInitialization.X0
  //  Referenced by: '<S132>/X0'

  { 0.0, 0.0 },

  // Expression: Estimator.alt.filterSonarNum
  //  Referenced by: '<S3>/Discrete Filter1'

  { 3.7568380197512489E-6, 1.1270514059253748E-5, 1.1270514059253748E-5,
    3.7568380197512489E-6 },

  // Expression: Estimator.alt.filterSonarDen
  //  Referenced by: '<S3>/Discrete Filter1'

  { 1.0, -2.9371707284498907, 2.8762997234793319, -0.939098940325283 },

  // Expression: 0
  //  Referenced by: '<S3>/Discrete Filter1'

  0.0,

  // Expression: -0.01
  //  Referenced by: '<S3>/Convert to meters'

  -0.01,

  // Expression: [0;0]
  //  Referenced by: '<S131>/Constant'

  { 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S131>/Delay One Step'

  0.0,

  // Expression: pInitialization.M
  //  Referenced by: '<S135>/KalmanGainM'

  { 0.01111810095321515, 0.024860635287623042 },

  // Expression: pInitialization.C
  //  Referenced by: '<S132>/C'

  { 1.0, 0.0 },

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S129>/Integrator'

  0.0025,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S129>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S129>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S129>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S129>/Saturation'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S43>/Delay2'

  0.0,

  // Expression: 2
  //  Referenced by: '<S43>/Bias3'

  2.0,

  // Expression: 1/100
  //  Referenced by: '<S43>/Gain5'

  0.01,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S122>/Integrator'

  0.0025,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S122>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S122>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S122>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S122>/Saturation'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S43>/Delay1'

  0.0,

  // Expression: 2
  //  Referenced by: '<S43>/Bias2'

  2.0,

  // Expression: 1/100
  //  Referenced by: '<S43>/Gain4'

  0.01,

  // Expression: [0 0]
  //  Referenced by: '<S32>/Constant'

  { 0.0, 0.0 },

  // Expression: [0 0 g]
  //  Referenced by: '<S131>/gravity'

  { 0.0, 0.0, 9.81 },

  // Expression: [0 0 -g]
  //  Referenced by: '<S40>/gravity'

  { 0.0, 0.0, -9.81 },

  // Expression: Estimator.pos.accelerationInputGain
  //  Referenced by: '<S40>/gainaccinput'

  1.0,

  // Expression: pInitialization.B
  //  Referenced by: '<S132>/B'

  { 0.0, 0.0025 },

  // Expression: pInitialization.D
  //  Referenced by: '<S132>/D'

  0.0,

  // Expression: pInitialization.L
  //  Referenced by: '<S135>/KalmanGainL'

  { 0.01118025254143421, 0.024860635287623029 },

  // Computed Parameter: SimplyIntegrateVelocity_gainval
  //  Referenced by: '<S35>/SimplyIntegrateVelocity'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S35>/SimplyIntegrateVelocity'

  0.0,

  // Expression: .2
  //  Referenced by: '<S22>/Gain3'

  0.2,

  // Expression: .2
  //  Referenced by: '<S22>/Gain4'

  0.2,

  // Expression: -1
  //  Referenced by: '<S22>/Gain1'

  -1.0,

  // Expression: pi/4
  //  Referenced by: '<S22>/Saturation'

  0.78539816339744828,

  // Expression: -pi/4
  //  Referenced by: '<S22>/Saturation'

  -0.78539816339744828,

  // Expression: .2
  //  Referenced by: '<S23>/Gain4'

  0.2,

  // Expression: .2
  //  Referenced by: '<S23>/Gain3'

  0.2,

  // Expression: 1
  //  Referenced by: '<S23>/Gain1'

  1.0,

  // Expression: pi/4
  //  Referenced by: '<S23>/Saturation'

  0.78539816339744828,

  // Expression: -pi/4
  //  Referenced by: '<S23>/Saturation'

  -0.78539816339744828,

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/Pos=1//Dashboard=0'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/Switch2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/Switch1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_i
  //  Referenced by: '<S31>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S31>/Discrete-Time Integrator'

  0.0,

  // Expression: 1/(60*60)
  //  Referenced by: '<S31>/Gain'

  0.00027777777777777778,

  // Expression: Estimator.alt.filterPrsNum
  //  Referenced by: '<S3>/Discrete Filter2'

  { 3.7568380197512489E-6, 1.1270514059253748E-5, 1.1270514059253748E-5,
    3.7568380197512489E-6 },

  // Expression: Estimator.alt.filterPrsDen
  //  Referenced by: '<S3>/Discrete Filter2'

  { 1.0, -2.9371707284498907, 2.8762997234793319, -0.939098940325283 },

  // Expression: 0
  //  Referenced by: '<S3>/Discrete Filter2'

  0.0,

  // Expression: pInitialization.Z
  //  Referenced by: '<S61>/CovarianceZ'

  { 0.62732804493044869, 0.0, 0.0, 0.62732804493044869 },

  // Expression: pInitialization.Z
  //  Referenced by: '<S135>/CovarianceZ'

  { 0.001111810095321515, 0.0024860635287623041, 0.0024860635287623041,
    0.011180427234244863 },

  // Expression: Controller.Q2Ts
  //  Referenced by: '<S28>/TorqueTotalThrustToThrustPerMotor'

  { 0.25F, 0.25F, 0.25F, 0.25F, 5.66592F, 5.66592F, -5.66592F, -5.66592F,
    -5.66592F, 5.66592F, -5.66592F, 5.66592F, 672.983215F, -672.983215F,
    -672.983215F, 672.983215F },

  // Computed Parameter: inverseIMU_gain_Gain
  //  Referenced by: '<S3>/inverseIMU_gain'

  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F },

  // Computed Parameter: DelayOneStep_InitialCondition_k
  //  Referenced by: '<S190>/Delay One Step'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S109>/isSqrtUsed'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S181>/isSqrtUsed'

  false
};

//
// File trailer for generated code.
//
// [EOF]
//
