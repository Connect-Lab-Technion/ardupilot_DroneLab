//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.203
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sun Jun 29 13:35:16 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FCS_model.h"

// Block parameters (default storage)
FCS_model::P_FCS_model_T FCS_model::FCS_model_P{
  // Variable: Vehicle
  //  Referenced by:
  //    '<S27>/Constant1'
  //    '<S37>/Saturation'
  //    '<S38>/Bias'
  //    '<S38>/thrustToMotor'
  //    '<S31>/Constant'

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
      0.0769,

      { 3.5212e-5, 0.0, 0.0, 0.0, 4.9812e-5, 0.0, 0.0, 0.0, 5.855e-5 },
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

  // Variable: Controller
  //  Referenced by: '<S27>/SaturationThrust'

  {
    { 1.0, 0.00037148027839331457, -0.044123463146040563, 0.044123463146040563,
      1.0, -0.00037148027839331457, 0.044123463146040563, 0.044123463146040563,
      1.0, -0.00037148027839331457, -0.044123463146040563, -0.044123463146040563,
      1.0, 0.00037148027839331457, 0.044123463146040563, -0.044123463146040563 },

    { 0.24999999999999994, 0.25000000000000006, 0.25000000000000006,
      0.24999999999999994, 672.98323636795044, -672.98323636795044,
      -672.98323636795044, 672.98323636795044, -5.6659197210460546,
      5.6659197210460546, -5.6659197210460546, 5.6659197210460546,
      5.6659197210460546, 5.6659197210460546, -5.6659197210460546,
      -5.6659197210460546 },
    0.92,
    120.0
  },

  // Variable: KDphi
  //  Referenced by: '<S9>/KDphi'

  0.0008249799999999999,

  // Variable: KDpsi
  //  Referenced by: '<S10>/KDpsi'

  0.00045760000000000006,

  // Variable: KDtheta
  //  Referenced by: '<S8>/KDtheta'

  0.0019779759999999998,

  // Variable: KDz
  //  Referenced by: '<S27>/KDz'

  0.34980000000000006,

  // Variable: Ts
  //  Referenced by:
  //    '<S31>/Ts'
  //    '<S201>/Gain'

  0.0025,

  // Variable: g
  //  Referenced by:
  //    '<S27>/Constant1'
  //    '<S198>/Constant'

  9.81,

  // Variable: sensorCalibrationData
  //  Referenced by: '<Root>/Constant'

  { 0.09, -0.06, -9.473, -0.0095, -0.0075, 0.0015, 101270.95, 0.2 },

  // Variable: w_c_pitch
  //  Referenced by: '<S196>/Gain'

  0.03,

  // Variable: w_c_roll
  //  Referenced by: '<S197>/Gain'

  0.03,

  // Variable: w_c_yaw
  //  Referenced by: '<S203>/Gain'

  55.0,

  // Variable: zDphi
  //  Referenced by: '<S9>/zDphi'

  1.3157894736842106,

  // Variable: zDpsi
  //  Referenced by: '<S10>/zDpsi'

  2.2727272727272729,

  // Variable: zDtheta
  //  Referenced by: '<S8>/zDtheta'

  1.3157894736842106,

  // Variable: zDz
  //  Referenced by: '<S27>/zDz'

  3.0303030303030303,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S58>/UD'

  0.0,

  // Mask Parameter: LowPassFilterDiscreteorContinuo
  //  Referenced by: '<S124>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_d
  //  Referenced by: '<S123>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_l
  //  Referenced by: '<S132>/Time constant'

  0.1,

  // Mask Parameter: LowPassFilterDiscreteorContin_a
  //  Referenced by: '<S125>/Time constant'

  0.1,

  // Mask Parameter: maxp_const
  //  Referenced by: '<S61>/Constant'

  0.6,

  // Mask Parameter: maxq_const
  //  Referenced by: '<S63>/Constant'

  0.6,

  // Mask Parameter: maxw1_const
  //  Referenced by: '<S65>/Constant'

  7.0,

  // Mask Parameter: maxw2_const
  //  Referenced by: '<S66>/Constant'

  7.0,

  // Mask Parameter: maxdw1_const
  //  Referenced by: '<S59>/Constant'

  80.0,

  // Mask Parameter: maxdw2_const
  //  Referenced by: '<S60>/Constant'

  80.0,

  // Mask Parameter: maxp2_const
  //  Referenced by: '<S62>/Constant'

  0.5,

  // Mask Parameter: maxq2_const
  //  Referenced by: '<S64>/Constant'

  0.5,

  // Mask Parameter: maxw3_const
  //  Referenced by: '<S67>/Constant'

  5.0,

  // Mask Parameter: maxw4_const
  //  Referenced by: '<S68>/Constant'

  5.0,

  // Mask Parameter: minHeightforOF_const
  //  Referenced by: '<S69>/Constant'

  -0.1,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S135>/Constant'

  2.0,

  // Mask Parameter: CompareToConstant_const_p
  //  Referenced by: '<S128>/Constant'

  2.0,

  // Mask Parameter: DeactivateAccelerationIfOFisnot
  //  Referenced by: '<S53>/Constant'

  -0.1,

  // Mask Parameter: donotuseaccifopticalflowneverav
  //  Referenced by: '<S55>/Constant'

  0.0,

  // Mask Parameter: donotuseaccifopticalflownever_c
  //  Referenced by: '<S56>/Constant'

  0.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_i
  //  Referenced by: '<S132>/Constant'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorConti_d0
  //  Referenced by: '<S125>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S120>/L*(y[k]-yhat[k|k-1])'

  0.0,

  // Expression: 0
  //  Referenced by: '<S122>/deltax'

  0.0,

  // Expression: 0
  //  Referenced by: '<S192>/L*(y[k]-yhat[k|k-1])'

  0.0,

  // Expression: 0
  //  Referenced by: '<S194>/deltax'

  0.0,

  // Expression: [num_yaw_disc]
  //  Referenced by: '<S203>/Discrete Transfer Fcn'

  { 0.0, 0.0023357390909607661 },

  // Expression: [den_yaw_disc]
  //  Referenced by: '<S203>/Discrete Transfer Fcn'

  { 1.0, -0.87153434999715784 },

  // Expression: 0
  //  Referenced by: '<S203>/Discrete Transfer Fcn'

  0.0,

  // Expression: 1/(60*60)
  //  Referenced by: '<S39>/Gain'

  0.00027777777777777778,

  // Expression: 0
  //  Referenced by: '<S43>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S129>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S136>/Constant'

  0.0,

  // Expression: pInitialization.A
  //  Referenced by: '<S141>/A'

  { 1.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0, 0.0, 3.125E-6, 0.0025, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S41>/Constant'

  1.0,

  // Expression: [0 0 +g 0 0 0]
  //  Referenced by: '<S3>/Assuming that calib was done level!'

  { 0.0, 0.0, 9.81, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S41>/Memory'

  0.0,

  // Expression: [num_pitch_disc]
  //  Referenced by: '<S196>/Discrete Transfer Fcn'

  { 0.0, 0.0024999062523437059 },

  // Expression: [den_pitch_disc]
  //  Referenced by: '<S196>/Discrete Transfer Fcn'

  { 1.0, -0.99992500281242969 },

  // Expression: 0
  //  Referenced by: '<S196>/Discrete Transfer Fcn'

  0.0,

  // Expression: [num_roll_disc]
  //  Referenced by: '<S197>/Discrete Transfer Fcn'

  { 0.0, 0.0024999062523437059 },

  // Expression: [den_roll_disc]
  //  Referenced by: '<S197>/Discrete Transfer Fcn'

  { 1.0, -0.99992500281242969 },

  // Expression: 0
  //  Referenced by: '<S197>/Discrete Transfer Fcn'

  0.0,

  // Expression: pInitialization.M
  //  Referenced by: '<S143>/KalmanGainM'

  { 0.069297876880651837, 0.030804669082180422, 0.0068131533667670574,
    0.0068131533667684513, -6.970361322763154E-14, -1.9322842662890616E-14,
    2.4937593615145497E-6, -0.0024937593671888521 },

  // Expression: pInitialization.C
  //  Referenced by: '<S141>/C'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0 },

  // Expression: pInitialization.L
  //  Referenced by: '<S143>/KalmanGainL'

  { 0.0693749098444617, 0.030821701965597498, 0.0068131533667686473,
    0.0068131533667685033, 7.7236986736014027E-12, 6.2343811745024791E-9,
    -0.0024937593671870246, -0.0024937593671871048 },

  // Expression: 0
  //  Referenced by: '<S3>/FIR_IMUaccel'

  0.0,

  // Expression: Estimator.IMU.filterAccel.Coefficients
  //  Referenced by: '<S3>/FIR_IMUaccel'

  { 0.026407724923238066, 0.14053136276241623, 0.3330609123143457,
    0.3330609123143457, 0.14053136276241623, 0.026407724923238066 },

  // Expression: [0 0 g]
  //  Referenced by: '<S140>/gravity'

  { 0.0, 0.0, 9.81 },

  // Expression: 0
  //  Referenced by: '<S140>/Constant'

  0.0,

  // Expression: Estimator.alt.filterPrsNum
  //  Referenced by: '<S140>/Discrete Filter1'

  { 3.7568380197512489E-6, 1.1270514059253748E-5, 1.1270514059253748E-5,
    3.7568380197512489E-6 },

  // Expression: Estimator.alt.filterPrsDen
  //  Referenced by: '<S140>/Discrete Filter1'

  { 1.0, -2.9371707284498907, 2.8762997234793319, -0.939098940325283 },

  // Expression: 0
  //  Referenced by: '<S140>/Discrete Filter1'

  0.0,

  // Expression: pInitialization.D
  //  Referenced by: '<S141>/D'

  { 0.0, 0.0 },

  // Expression: pInitialization.X0
  //  Referenced by: '<S141>/X0'

  { 0.0, 0.0, 9.81, 0.0 },

  // Expression: pInitialization.B
  //  Referenced by: '<S141>/B'

  { 0.0, 0.0, 1.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S27>/Constant'

  1.0,

  // Expression: 2
  //  Referenced by: '<S31>/signal_max'

  2.0,

  // Expression: 0.1
  //  Referenced by: '<S31>/cycle_time'

  0.1,

  // Expression: .5
  //  Referenced by: '<S31>/Gain'

  0.5,

  // Expression: 0
  //  Referenced by: '<S27>/WithTakeoff=1 WithoutTakeoff=0'

  0.0,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S30>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B
  //  Referenced by: '<S30>/Internal'

  0.03125,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S30>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: 0
  //  Referenced by: '<S30>/Internal'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/sw_states_passthrough'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: -1
  //  Referenced by: '<S27>/Gain'

  -1.0,

  // Expression: [0 0]
  //  Referenced by: '<S40>/Constant'

  { 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: -1
  //  Referenced by: '<S27>/Gain1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S27>/WithControl=1 WithoutControl=0'

  1.0,

  // Expression: 1
  //  Referenced by: '<S1>/On=1//Off=0 for thrust'

  1.0,

  // Expression: 0
  //  Referenced by: '<S4>/yaw equilibrium'

  0.0,

  // Computed Parameter: Internal_A_l
  //  Referenced by: '<S23>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B_e
  //  Referenced by: '<S23>/Internal'

  0.03125,

  // Computed Parameter: Internal_C_j
  //  Referenced by: '<S23>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: 0
  //  Referenced by: '<S23>/Internal'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jzz'

  0.6,

  // Expression: 1
  //  Referenced by: '<S1>/On=1//Off=1 for yaw'

  1.0,

  // Expression: 0
  //  Referenced by: '<S4>/pitch equilibrium'

  0.0,

  // Expression: pInitialization.X0
  //  Referenced by: '<S51>/X0'

  { 0.0, 0.0 },

  // Expression: pInitialization.M
  //  Referenced by: '<S70>/KalmanGainM'

  { 0.12546560898608972, 0.0, 0.0, 0.12546560898608972 },

  // Expression: pInitialization.C
  //  Referenced by: '<S51>/C'

  { 1.0, 0.0, 0.0, 1.0 },

  // Expression: Estimator.IMU.filterGyroNum
  //  Referenced by: '<S50>/IIRgyroz'

  { 0.28212412246252078, 1.2725392917168599, 2.4208439774454429,
    2.420843977445442, 1.2725392917168588, 0.28212412246252028 },

  // Expression: Estimator.IMU.filterGyroDen
  //  Referenced by: '<S50>/IIRgyroz'

  { 1.0, 2.2287149173647669, 2.5244618916938615, 1.5772531712757021,
    0.5410224068298175, 0.079562396085500878 },

  // Expression: 0
  //  Referenced by: '<S50>/IIRgyroz'

  0.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S58>/TSamp'

  400.0,

  // Expression: 0
  //  Referenced by: '<S45>/Delay'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S138>/Integrator'

  0.0025,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S138>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S138>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S138>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S138>/Saturation'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S52>/Delay2'

  0.0,

  // Expression: 2
  //  Referenced by: '<S52>/Bias3'

  2.0,

  // Expression: 1/100
  //  Referenced by: '<S52>/Gain5'

  0.01,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S131>/Integrator'

  0.0025,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S131>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S131>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S131>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S131>/Saturation'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S52>/Delay1'

  0.0,

  // Expression: 2
  //  Referenced by: '<S52>/Bias2'

  2.0,

  // Expression: 1/100
  //  Referenced by: '<S52>/Gain4'

  0.01,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: .2
  //  Referenced by: '<S28>/Gain4'

  0.2,

  // Computed Parameter: SimplyIntegrateVelocity_gainval
  //  Referenced by: '<S44>/SimplyIntegrateVelocity'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S44>/SimplyIntegrateVelocity'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: .2
  //  Referenced by: '<S28>/Gain3'

  0.2,

  // Expression: -1
  //  Referenced by: '<S28>/Gain1'

  -1.0,

  // Expression: pi/4
  //  Referenced by: '<S28>/Saturation'

  0.78539816339744828,

  // Expression: -pi/4
  //  Referenced by: '<S28>/Saturation'

  -0.78539816339744828,

  // Expression: 1
  //  Referenced by: '<S1>/Pos=1//Dashboard=0'

  1.0,

  // Expression: 0
  //  Referenced by: '<S4>/Switch1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Computed Parameter: Internal_A_o
  //  Referenced by: '<S11>/Internal'

  1.0,

  // Computed Parameter: Internal_B_b
  //  Referenced by: '<S11>/Internal'

  0.0625,

  // Computed Parameter: Internal_C_p
  //  Referenced by: '<S11>/Internal'

  0.039999999999999147,

  // Computed Parameter: Internal_D_b
  //  Referenced by: '<S11>/Internal'

  0.62,

  // Expression: 0
  //  Referenced by: '<S11>/Internal'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jyy'

  0.6,

  // Expression: 1
  //  Referenced by: '<S1>/On=1//Off=2 for pitch'

  1.0,

  // Expression: 0
  //  Referenced by: '<S4>/roll equilibrium'

  0.0,

  // Computed Parameter: Internal_A_d
  //  Referenced by: '<S15>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B_g
  //  Referenced by: '<S15>/Internal'

  0.03125,

  // Computed Parameter: Internal_C_n
  //  Referenced by: '<S15>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: 0
  //  Referenced by: '<S15>/Internal'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Computed Parameter: Internal_A_n
  //  Referenced by: '<S16>/Internal'

  1.0,

  // Computed Parameter: Internal_B_j
  //  Referenced by: '<S16>/Internal'

  0.0625,

  // Computed Parameter: Internal_C_a
  //  Referenced by: '<S16>/Internal'

  0.039999999999999147,

  // Computed Parameter: Internal_D_jy
  //  Referenced by: '<S16>/Internal'

  0.84,

  // Expression: 0
  //  Referenced by: '<S16>/Internal'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jxx'

  0.6,

  // Expression: 1
  //  Referenced by: '<S1>/On=1//Off=1 for roll'

  1.0,

  // Expression: pInitialization.A
  //  Referenced by: '<S51>/A'

  { 1.0, 0.0, 0.0, 1.0 },

  // Expression: pInitialization.B
  //  Referenced by: '<S51>/B'

  { 0.0025, 0.0, 0.0, 0.0025 },

  // Expression: pInitialization.L
  //  Referenced by: '<S70>/KalmanGainL'

  { 0.12546560898608977, 0.0, 0.0, 0.12546560898608977 },

  // Expression: pInitialization.D
  //  Referenced by: '<S51>/D'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0 0 -g]
  //  Referenced by: '<S49>/gravity'

  { 0.0, 0.0, -9.81 },

  // Expression: Estimator.pos.accelerationInputGain
  //  Referenced by: '<S49>/gainaccinput'

  1.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: .2
  //  Referenced by: '<S29>/Gain4'

  0.2,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: .2
  //  Referenced by: '<S29>/Gain3'

  0.2,

  // Expression: 1
  //  Referenced by: '<S29>/Gain1'

  1.0,

  // Expression: pi/4
  //  Referenced by: '<S29>/Saturation'

  0.78539816339744828,

  // Expression: -pi/4
  //  Referenced by: '<S29>/Saturation'

  -0.78539816339744828,

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/Switch2'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S39>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S39>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Switch'

  0.0,

  // Expression: -1
  //  Referenced by: '<S198>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S198>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S198>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S198>/Gain3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S199>/Gain'

  -1.0,

  // Expression: pInitialization.Z
  //  Referenced by: '<S143>/CovarianceZ'

  { 0.0013859575376130369, 0.0006160933816436086, 0.00013626306733534115,
    0.00013626306733536904, 0.00061609338164360849, 0.018197662912787155,
    0.0040560751311424286, 0.0040560751311424365, 0.00013626306733534113,
    0.0040560751311424286, 0.0018040319943725307, 0.0018040309968687862,
    0.00013626306733536904, 0.0040560751311424365, 0.0018040309968687864,
    0.0018050285006156617 },

  // Expression: pInitialization.Z
  //  Referenced by: '<S70>/CovarianceZ'

  { 0.62732804493044869, 0.0, 0.0, 0.62732804493044869 },

  // Expression: Controller.Q2Ts
  //  Referenced by: '<S36>/TorqueTotalThrustToThrustPerMotor'

  { 0.25F, 0.25F, 0.25F, 0.25F, 672.983215F, -672.983215F, -672.983215F,
    672.983215F, -5.66592F, 5.66592F, -5.66592F, 5.66592F, 5.66592F, 5.66592F,
    -5.66592F, -5.66592F },

  // Computed Parameter: inverseIMU_gain_Gain
  //  Referenced by: '<S3>/inverseIMU_gain'

  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F },

  // Computed Parameter: RangfinderScaleGain1_Gain
  //  Referenced by: '<S140>/RangfinderScaleGain1'

  -0.01F,

  // Expression: true()
  //  Referenced by: '<S141>/Enable'

  true,

  // Computed Parameter: Memory_InitialCondition_h
  //  Referenced by: '<S31>/Memory'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S190>/isSqrtUsed'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S118>/isSqrtUsed'

  false
};

//
// File trailer for generated code.
//
// [EOF]
//
