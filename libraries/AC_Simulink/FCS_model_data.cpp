//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
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
#include "FCS_model.h"

// Block parameters (default storage)
FCS_model::P_FCS_model_T FCS_model::FCS_model_P = {
  // Variable: Vehicle
  //  Referenced by: '<S29>/Saturation'

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
      0.083,

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

  // Variable: KDtheta
  //  Referenced by: '<S8>/KDtheta'

  0.0019779759999999998,

  // Variable: Ts
  //  Referenced by:
  //    '<S24>/Ts'
  //    '<S190>/Gain'

  0.0025,

  // Variable: g
  //  Referenced by: '<S187>/Constant'

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

  // Variable: sensorCalibrationData
  //  Referenced by: '<Root>/Constant'

  { 0.09, -0.06, -9.473, -0.0095, -0.0075, 0.0015, 101270.95, 0.2 },

  // Variable: w_c_pitch
  //  Referenced by: '<S185>/Gain'

  5.5,

  // Variable: w_c_roll
  //  Referenced by: '<S186>/Gain'

  0.03,

  // Variable: w_c_yaw
  //  Referenced by: '<S192>/Gain'

  55.0,

  // Variable: zDpsi
  //  Referenced by: '<S10>/zDpsi'

  2.2727272727272729,

  // Variable: zDtheta
  //  Referenced by: '<S8>/zDtheta'

  1.3157894736842106,

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

  // Mask Parameter: minHeightforOF_const
  //  Referenced by: '<S60>/Constant'

  -0.1,

  // Mask Parameter: CompareToConstant_const
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
  //  Referenced by: '<S181>/L*(y[k]-yhat[k|k-1])'

  0.0,

  // Expression: 0
  //  Referenced by: '<S183>/deltax'

  0.0,

  // Expression: [num_yaw_disc]
  //  Referenced by: '<S192>/Discrete Transfer Fcn'

  { 0.0, 0.0023357390909607661 },

  // Expression: [den_yaw_disc]
  //  Referenced by: '<S192>/Discrete Transfer Fcn'

  { 1.0, -0.87153434999715784 },

  // Expression: 0
  //  Referenced by: '<S192>/Discrete Transfer Fcn'

  0.0,

  // Expression: 0
  //  Referenced by: '<S120>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S127>/Constant'

  0.0,

  // Expression: pInitialization.A
  //  Referenced by: '<S132>/A'

  { 1.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0, 0.0, 3.125E-6, 0.0025, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0 },

  // Expression: [num_roll_disc]
  //  Referenced by: '<S186>/Discrete Transfer Fcn'

  { 0.0, 0.0024999062523437059 },

  // Expression: [den_roll_disc]
  //  Referenced by: '<S186>/Discrete Transfer Fcn'

  { 1.0, -0.99992500281242969 },

  // Expression: 0
  //  Referenced by: '<S186>/Discrete Transfer Fcn'

  0.0,

  // Expression: [0 0 +g 0 0 0]
  //  Referenced by: '<S3>/Assuming that calib was done level!'

  { 0.0, 0.0, 9.81, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S3>/FIR_IMUaccel'

  0.0,

  // Expression: Estimator.IMU.filterAccel.Coefficients
  //  Referenced by: '<S3>/FIR_IMUaccel'

  { 0.026407724923238066, 0.14053136276241623, 0.3330609123143457,
    0.3330609123143457, 0.14053136276241623, 0.026407724923238066 },

  // Expression: -1
  //  Referenced by: '<S187>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S187>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S187>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S187>/Gain3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S188>/Gain'

  -1.0,

  // Expression: [num_pitch_disc]
  //  Referenced by: '<S185>/Discrete Transfer Fcn'

  { 0.0012414649286157666, 0.0012414649286157666 },

  // Expression: [den_pitch_disc]
  //  Referenced by: '<S185>/Discrete Transfer Fcn'

  { 1.0, -0.98634388578522658 },

  // Expression: 0
  //  Referenced by: '<S185>/Discrete Transfer Fcn'

  0.0,

  // Expression: 1
  //  Referenced by: '<S33>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S33>/Memory'

  0.0,

  // Expression: pInitialization.M
  //  Referenced by: '<S134>/KalmanGainM'

  { 0.069297876880651837, 0.030804669082180412, 0.0068131533667670167,
    0.006813153366768453, -7.1779623368887751E-14, -1.70911387730494E-14,
    2.4937593631519923E-6, -0.0024937593671866755 },

  // Expression: pInitialization.C
  //  Referenced by: '<S132>/C'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0 },

  // Expression: pInitialization.L
  //  Referenced by: '<S134>/KalmanGainL'

  { 0.069374909844461832, 0.030821701965597571, 0.006813153366768669,
    0.0068131533667685354, 7.7210971940159948E-12, 6.2343818761981251E-9,
    -0.0024937593671857314, -0.0024937593671861655 },

  // Expression: [0 0 g]
  //  Referenced by: '<S131>/gravity'

  { 0.0, 0.0, 9.81 },

  // Expression: 0
  //  Referenced by: '<S131>/Constant'

  0.0,

  // Expression: Estimator.alt.filterPrsNum
  //  Referenced by: '<S131>/Discrete Filter1'

  { 3.7568380197512489E-6, 1.1270514059253748E-5, 1.1270514059253748E-5,
    3.7568380197512489E-6 },

  // Expression: Estimator.alt.filterPrsDen
  //  Referenced by: '<S131>/Discrete Filter1'

  { 1.0, -2.9371707284498907, 2.8762997234793319, -0.939098940325283 },

  // Expression: 0
  //  Referenced by: '<S131>/Discrete Filter1'

  0.0,

  // Expression: pInitialization.D
  //  Referenced by: '<S132>/D'

  { 0.0, 0.0 },

  // Expression: pInitialization.X0
  //  Referenced by: '<S132>/X0'

  { 0.0, 0.0, 9.81, 0.0 },

  // Expression: pInitialization.B
  //  Referenced by: '<S132>/B'

  { 0.0, 0.0, 1.0, 0.0 },

  // Expression: [1,1,1,1]
  //  Referenced by: '<S29>/Constant'

  { 1.0, 1.0, 1.0, 1.0 },

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

  // Expression: [0 0]
  //  Referenced by: '<S32>/Constant'

  { 0.0, 0.0 },

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

  // Expression: [0 0 -g]
  //  Referenced by: '<S40>/gravity'

  { 0.0, 0.0, -9.81 },

  // Expression: Estimator.pos.accelerationInputGain
  //  Referenced by: '<S40>/gainaccinput'

  1.0,

  // Computed Parameter: SimplyIntegrateVelocity_gainval
  //  Referenced by: '<S35>/SimplyIntegrateVelocity'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S35>/SimplyIntegrateVelocity'

  0.0,

  // Expression: .2
  //  Referenced by: '<S21>/Gain3'

  0.2,

  // Expression: .2
  //  Referenced by: '<S21>/Gain4'

  0.2,

  // Expression: -1
  //  Referenced by: '<S21>/Gain1'

  -1.0,

  // Expression: pi/4
  //  Referenced by: '<S21>/Saturation'

  0.78539816339744828,

  // Expression: -pi/4
  //  Referenced by: '<S21>/Saturation'

  -0.78539816339744828,

  // Expression: 1
  //  Referenced by: '<S1>/Pos=1//Dashboard=0'

  1.0,

  // Expression: 0
  //  Referenced by: '<S4>/Switch1'

  0.0,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S11>/Internal'

  1.0,

  // Computed Parameter: Internal_B
  //  Referenced by: '<S11>/Internal'

  0.0625,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S11>/Internal'

  0.039999999999999147,

  // Computed Parameter: Internal_D
  //  Referenced by: '<S11>/Internal'

  0.62,

  // Expression: xinit
  //  Referenced by: '<S11>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jyy'

  0.6,

  // Expression: 0
  //  Referenced by: '<S4>/pitch equilibrium'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=2 for pitch'

  0.0,

  // Expression: 100
  //  Referenced by: '<S1>/Constant'

  100.0,

  // Expression: 1
  //  Referenced by: '<S1>/On=1//Off=0 for thrust'

  1.0,

  // Expression: 0
  //  Referenced by: '<S4>/yaw equilibrium'

  0.0,

  // Computed Parameter: Internal_A_l
  //  Referenced by: '<S17>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B_e
  //  Referenced by: '<S17>/Internal'

  0.03125,

  // Computed Parameter: Internal_C_j
  //  Referenced by: '<S17>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: xinit
  //  Referenced by: '<S17>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jzz'

  0.6,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=1 for yaw'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/roll equilibrium'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S9>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S9>/Discrete-Time Integrator'

  0.0,

  // Computed Parameter: Internal_A_d
  //  Referenced by: '<S14>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B_g
  //  Referenced by: '<S14>/Internal'

  0.03125,

  // Computed Parameter: Internal_C_n
  //  Referenced by: '<S14>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: xinit
  //  Referenced by: '<S14>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jxx'

  0.6,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=1 for roll'

  0.0,

  // Expression: .2
  //  Referenced by: '<S22>/Gain4'

  0.2,

  // Expression: .2
  //  Referenced by: '<S22>/Gain3'

  0.2,

  // Expression: 1
  //  Referenced by: '<S22>/Gain1'

  1.0,

  // Expression: pi/4
  //  Referenced by: '<S22>/Saturation'

  0.78539816339744828,

  // Expression: -pi/4
  //  Referenced by: '<S22>/Saturation'

  -0.78539816339744828,

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/Switch2'

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

  // Expression: 1
  //  Referenced by: '<S20>/Constant'

  1.0,

  // Expression: 2
  //  Referenced by: '<S24>/signal_max'

  2.0,

  // Expression: 0.1
  //  Referenced by: '<S24>/cycle_time'

  0.1,

  // Expression: .5
  //  Referenced by: '<S24>/Gain'

  0.5,

  // Expression: pInitialization.Z
  //  Referenced by: '<S134>/CovarianceZ'

  { 0.0013859575376130367, 0.00061609338164360828, 0.00013626306733534037,
    0.00013626306733536907, 0.00061609338164360828, 0.018197662912787148,
    0.0040560751311424286, 0.0040560751311424356, 0.00013626306733534034,
    0.0040560751311424286, 0.0018040319943725327, 0.0018040309968687875,
    0.00013626306733536904, 0.0040560751311424356, 0.0018040309968687877,
    0.0018050285006156624 },

  // Expression: pInitialization.Z
  //  Referenced by: '<S61>/CovarianceZ'

  { 0.62732804493044869, 0.0, 0.0, 0.62732804493044869 },

  // Computed Parameter: inverseIMU_gain_Gain
  //  Referenced by: '<S3>/inverseIMU_gain'

  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F },

  // Computed Parameter: RangfinderScaleGain1_Gain
  //  Referenced by: '<S131>/RangfinderScaleGain1'

  -0.01F,

  // Expression: true()
  //  Referenced by: '<S132>/Enable'

  true,

  // Computed Parameter: Memory_InitialCondition_h
  //  Referenced by: '<S24>/Memory'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S179>/isSqrtUsed'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S109>/isSqrtUsed'

  false
};

//
// File trailer for generated code.
//
// [EOF]
//
