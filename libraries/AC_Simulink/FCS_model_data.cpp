//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
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
#include "FCS_model.h"

// Block parameters (default storage)
FCS_model::P_FCS_model_T FCS_model::FCS_model_P = {
  // Variable: Vehicle
  //  Referenced by:
  //    '<S28>/Saturation'
  //    '<S29>/Bias'
  //    '<S29>/thrustToMotor'

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
      0.1,
      1500000000.0,
      0.1,
      0.013162224415926292,
      1.3417150271076748
    }
  },

  // Variable: KDpsi
  //  Referenced by: '<S10>/KDpsi'

  0.00045760000000000006,

  // Variable: Ts
  //  Referenced by: '<S191>/Gain'

  0.0025,

  // Variable: g
  //  Referenced by: '<S188>/Constant'

  9.81,

  // Variable: kd_rol
  //  Referenced by: '<S9>/kd_rol'

  0.002,

  // Variable: ki_rol
  //  Referenced by: '<S9>/ki_rol'

  0.050135555048837037,

  // Variable: kp_rol
  //  Referenced by: '<S9>/kp_rol'

  0.01787557639106185,

  // Variable: w_c_pitch
  //  Referenced by: '<S186>/Gain'

  0.3,

  // Variable: w_c_roll
  //  Referenced by: '<S187>/Gain'

  0.3,

  // Variable: w_c_yaw
  //  Referenced by: '<S193>/Gain'

  55.0,

  // Variable: zDpsi
  //  Referenced by: '<S10>/zDpsi'

  2.2727272727272729,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S48>/UD'

  0.0,

  // Mask Parameter: LowPassFilterDiscreteorContinuo
  //  Referenced by: '<S114>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_d
  //  Referenced by: '<S113>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_l
  //  Referenced by: '<S122>/Time constant'

  0.1,

  // Mask Parameter: LowPassFilterDiscreteorContin_a
  //  Referenced by: '<S115>/Time constant'

  0.1,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S11>/Constant'

  0.7,

  // Mask Parameter: maxp_const
  //  Referenced by: '<S51>/Constant'

  0.6,

  // Mask Parameter: maxq_const
  //  Referenced by: '<S53>/Constant'

  0.6,

  // Mask Parameter: maxw1_const
  //  Referenced by: '<S55>/Constant'

  7.0,

  // Mask Parameter: maxw2_const
  //  Referenced by: '<S56>/Constant'

  7.0,

  // Mask Parameter: maxdw1_const
  //  Referenced by: '<S49>/Constant'

  80.0,

  // Mask Parameter: maxdw2_const
  //  Referenced by: '<S50>/Constant'

  80.0,

  // Mask Parameter: maxp2_const
  //  Referenced by: '<S52>/Constant'

  0.5,

  // Mask Parameter: maxq2_const
  //  Referenced by: '<S54>/Constant'

  0.5,

  // Mask Parameter: maxw3_const
  //  Referenced by: '<S57>/Constant'

  5.0,

  // Mask Parameter: maxw4_const
  //  Referenced by: '<S58>/Constant'

  5.0,

  // Mask Parameter: minHeightforOF_const
  //  Referenced by: '<S59>/Constant'

  -0.1,

  // Mask Parameter: CompareToConstant_const_m
  //  Referenced by: '<S125>/Constant'

  2.0,

  // Mask Parameter: CompareToConstant_const_p
  //  Referenced by: '<S118>/Constant'

  2.0,

  // Mask Parameter: DeactivateAccelerationIfOFisnot
  //  Referenced by: '<S43>/Constant'

  -0.1,

  // Mask Parameter: donotuseaccifopticalflowneverav
  //  Referenced by: '<S45>/Constant'

  0.0,

  // Mask Parameter: donotuseaccifopticalflownever_c
  //  Referenced by: '<S46>/Constant'

  0.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_i
  //  Referenced by: '<S122>/Constant'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorConti_d0
  //  Referenced by: '<S115>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S8>/Constant'

  0.0,

  // Expression: 4
  //  Referenced by: '<S8>/Kp'

  4.0,

  // Expression: 0.001511390152616
  //  Referenced by: '<S8>/Kd'

  0.001511390152616,

  // Expression: 0
  //  Referenced by: '<S110>/L*(y[k]-yhat[k|k-1])'

  0.0,

  // Expression: 0
  //  Referenced by: '<S112>/deltax'

  0.0,

  // Expression: 0
  //  Referenced by: '<S182>/L*(y[k]-yhat[k|k-1])'

  0.0,

  // Expression: 0
  //  Referenced by: '<S184>/deltax'

  0.0,

  // Expression: [num_yaw_disc]
  //  Referenced by: '<S193>/Discrete Transfer Fcn'

  { 0.0, 0.0023357390909607661 },

  // Expression: [den_yaw_disc]
  //  Referenced by: '<S193>/Discrete Transfer Fcn'

  { 1.0, -0.87153434999715784 },

  // Expression: 0
  //  Referenced by: '<S193>/Discrete Transfer Fcn'

  0.0,

  // Expression: 0
  //  Referenced by: '<S119>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S126>/Constant'

  0.0,

  // Expression: [num_roll_disc]
  //  Referenced by: '<S187>/Discrete Transfer Fcn'

  { 0.0, 0.0024990627343310615 },

  // Expression: [den_roll_disc]
  //  Referenced by: '<S187>/Discrete Transfer Fcn'

  { 1.0, -0.99925028117970072 },

  // Expression: 0
  //  Referenced by: '<S187>/Discrete Transfer Fcn'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/FIR_IMUaccel'

  0.0,

  // Expression: Estimator.IMU.filterAccel.Coefficients
  //  Referenced by: '<S3>/FIR_IMUaccel'

  { 0.026407724923238066, 0.14053136276241623, 0.3330609123143457,
    0.3330609123143457, 0.14053136276241623, 0.026407724923238066 },

  // Expression: -1
  //  Referenced by: '<S188>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S188>/Gain'

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
  //  Referenced by: '<S188>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S188>/Gain3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S189>/Gain'

  -1.0,

  // Expression: [num_pitch_disc]
  //  Referenced by: '<S186>/Discrete Transfer Fcn'

  { 0.0012495314257153568, 0.0012495314257153568 },

  // Expression: [den_pitch_disc]
  //  Referenced by: '<S186>/Discrete Transfer Fcn'

  { 1.0, -0.99925028114457093 },

  // Expression: 0
  //  Referenced by: '<S186>/Discrete Transfer Fcn'

  0.0,

  // Expression: 0
  //  Referenced by: '<S32>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S32>/Memory'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=0 for thrust'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/yaw equilibrium'

  0.0,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S18>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B
  //  Referenced by: '<S18>/Internal'

  0.03125,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S18>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: xinit
  //  Referenced by: '<S18>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jzz'

  0.6,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=0 for yaw'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/pitch equilibrium'

  0.0,

  // Computed Parameter: Internal_A_e
  //  Referenced by: '<S12>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B_j
  //  Referenced by: '<S12>/Internal'

  0.03125,

  // Computed Parameter: Internal_C_n
  //  Referenced by: '<S12>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: xinit
  //  Referenced by: '<S12>/Internal'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S8>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S8>/Discrete-Time Integrator'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jyy'

  0.6,

  // Expression: 1
  //  Referenced by: '<S1>/On=1//Off=0 for pitch'

  1.0,

  // Expression: 0
  //  Referenced by: '<S4>/roll equilibrium'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_k
  //  Referenced by: '<S9>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S9>/Discrete-Time Integrator'

  0.0,

  // Computed Parameter: Internal_A_d
  //  Referenced by: '<S15>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B_g
  //  Referenced by: '<S15>/Internal'

  0.03125,

  // Computed Parameter: Internal_C_nj
  //  Referenced by: '<S15>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: xinit
  //  Referenced by: '<S15>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jxx'

  0.6,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=0 for roll'

  0.0,

  // Expression: pInitialization.M
  //  Referenced by: '<S60>/KalmanGainM'

  { 0.12546560898608972, 0.0, 0.0, 0.12546560898608972 },

  // Expression: pInitialization.C
  //  Referenced by: '<S41>/C'

  { 1.0, 0.0, 0.0, 1.0 },

  // Expression: pInitialization.A
  //  Referenced by: '<S41>/A'

  { 1.0, 0.0, 0.0, 1.0 },

  // Expression: pInitialization.B
  //  Referenced by: '<S41>/B'

  { 0.0025, 0.0, 0.0, 0.0025 },

  // Expression: pInitialization.L
  //  Referenced by: '<S60>/KalmanGainL'

  { 0.12546560898608977, 0.0, -0.0, 0.12546560898608977 },

  // Expression: pInitialization.D
  //  Referenced by: '<S41>/D'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: pInitialization.A
  //  Referenced by: '<S131>/A'

  { 1.0, 0.0, 0.0025, 1.0 },

  // Expression: pInitialization.X0
  //  Referenced by: '<S41>/X0'

  { 0.0, 0.0 },

  // Expression: Estimator.IMU.filterGyroNum
  //  Referenced by: '<S40>/IIRgyroz'

  { 0.28212412246252078, 1.2725392917168605, 2.4208439774454451,
    2.4208439774454451, 1.27253929171686, 0.28212412246252072 },

  // Expression: Estimator.IMU.filterGyroDen
  //  Referenced by: '<S40>/IIRgyroz'

  { 1.0, 2.2287149173647669, 2.5244618916938615, 1.5772531712757021,
    0.5410224068298175, 0.079562396085500878 },

  // Expression: 0
  //  Referenced by: '<S40>/IIRgyroz'

  0.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S48>/TSamp'

  400.0,

  // Expression: 0
  //  Referenced by: '<S35>/Delay'

  0.0,

  // Expression: pInitialization.X0
  //  Referenced by: '<S131>/X0'

  { 0.0, 0.0 },

  // Expression: -0.01
  //  Referenced by: '<S3>/Convert to meters'

  -0.01,

  // Expression: [0;0]
  //  Referenced by: '<S130>/Constant'

  { 0.0, 0.0 },

  // Expression: pInitialization.M
  //  Referenced by: '<S133>/KalmanGainM'

  { 0.005272903957336322, 0.0055754122494506451 },

  // Expression: pInitialization.C
  //  Referenced by: '<S131>/C'

  { 1.0, 0.0 },

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S128>/Integrator'

  0.0025,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S128>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S128>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S128>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S128>/Saturation'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S42>/Delay2'

  0.0,

  // Expression: 2
  //  Referenced by: '<S42>/Bias3'

  2.0,

  // Expression: 1/100
  //  Referenced by: '<S42>/Gain5'

  0.01,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S121>/Integrator'

  0.0025,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S121>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S121>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S121>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S121>/Saturation'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S42>/Delay1'

  0.0,

  // Expression: 2
  //  Referenced by: '<S42>/Bias2'

  2.0,

  // Expression: 1/100
  //  Referenced by: '<S42>/Gain4'

  0.01,

  // Expression: [0 0]
  //  Referenced by: '<S31>/Constant'

  { 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S130>/FIR_IMUaccel'

  0.0,

  // Expression: Estimator.IMU.filterAccel.Coefficients
  //  Referenced by: '<S130>/FIR_IMUaccel'

  { 0.026407724923238066, 0.14053136276241623, 0.3330609123143457,
    0.3330609123143457, 0.14053136276241623, 0.026407724923238066 },

  // Expression: [0 0 g]
  //  Referenced by: '<S130>/gravity'

  { 0.0, 0.0, 9.81 },

  // Expression: [0 0 -g]
  //  Referenced by: '<S39>/gravity'

  { 0.0, 0.0, -9.81 },

  // Expression: Estimator.pos.accelerationInputGain
  //  Referenced by: '<S39>/gainaccinput'

  1.0,

  // Expression: pInitialization.B
  //  Referenced by: '<S131>/B'

  { 3.125E-6, 0.0025 },

  // Expression: pInitialization.D
  //  Referenced by: '<S131>/D'

  0.0,

  // Expression: pInitialization.L
  //  Referenced by: '<S133>/KalmanGainL'

  { 0.0052868424879599554, 0.0055754122494506564 },

  // Computed Parameter: SimplyIntegrateVelocity_gainval
  //  Referenced by: '<S34>/SimplyIntegrateVelocity'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S34>/SimplyIntegrateVelocity'

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

  // Expression: 0
  //  Referenced by: '<S1>/Pos=1//Dashboard=0'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/Switch1'

  0.0,

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
  //  Referenced by: '<S4>/Switch2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_i
  //  Referenced by: '<S30>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S30>/Discrete-Time Integrator'

  0.0,

  // Expression: 1/(60*60)
  //  Referenced by: '<S30>/Gain'

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

  // Expression: 0
  //  Referenced by: '<S8>/Ki'

  0.0,

  // Expression: pInitialization.Z
  //  Referenced by: '<S60>/CovarianceZ'

  { 0.62732804493044869, 0.0, 0.0, 0.62732804493044869 },

  // Expression: pInitialization.Z
  //  Referenced by: '<S133>/CovarianceZ'

  { 0.0005272903957336322, 0.00055754122494506458, 0.00055754122494506458,
    0.0011806155438429992 },

  // Expression: Controller.Q2Ts
  //  Referenced by: '<S27>/TorqueTotalThrustToThrustPerMotor'

  { 0.25F, 0.25F, 0.25F, 0.25F, 672.983215F, -672.983215F, -672.983215F,
    672.983215F, -5.66592F, 5.66592F, -5.66592F, 5.66592F, 5.66592F, 5.66592F,
    -5.66592F, -5.66592F },

  // Computed Parameter: inverseIMU_gain_Gain
  //  Referenced by: '<S3>/inverseIMU_gain'

  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F },

  // Expression: true()
  //  Referenced by: '<S131>/Enable'

  true,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S108>/isSqrtUsed'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S180>/isSqrtUsed'

  false
};

//
// File trailer for generated code.
//
// [EOF]
//
