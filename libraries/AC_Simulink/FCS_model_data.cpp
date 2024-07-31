//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
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
#include "FCS_model.h"

// Block parameters (default storage)
FCS_model::P_FCS_model_T FCS_model::FCS_model_P{
  // Variable: Sensors
  //  Referenced by: '<S38>/prsToAltGain'

  {
    { 1.00596, 1.00383, 0.99454 },

    { 0.99861, 1.00644, 0.99997 },

    {
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0 },
      190.0,
      0.707,

      { 1.00596, 0.0, 0.0, 0.0, 1.00383, 0.0, 0.0, 0.0, 0.99454 },

      { 0.09, -0.06, 0.33699999999999974 },

      { -50.0, -50.0, -50.0, 50.0, 50.0, 50.0 },
      190.0,
      0.707,

      { 0.99861, 0.0, 0.0, 0.0, 1.00644, 0.0, 0.0, 0.0, 0.99997 },

      { -0.0095, -0.0075, 0.0015 },

      { 0.0, 0.0, 0.0 },

      { -10.0, -10.0, -10.0, 10.0, 10.0, 10.0 },

      { 41.0, 41.0, 41.0, 41.0, 41.0, 41.0 },

      { 0.8, 0.8, 0.8, 0.025, 0.025, 0.025 },

      { 0.00021831529882618725, 0.00018641345254680647, 0.00037251068300213613,
        1.0651514622688397e-8, 1.3021327403798377e-8, 1.1929474437781302e-8 }
    },

    {
      1.0,
      41.0
    },
    -99.0,
    -9.0,

    {
      { -99.0, 0.0, 0.0, -9.0 },
      0.0,

      { 3.5, 70.0 }
    },
    1.0,
    1.225,
    12.01725,
    101270.95,

    { 0.99407531114557246, 0.99618461293246863, 1.0054899752649467,
      1.0013919347893572, 0.99360120821906917, 1.0000300009000269 },
    0.44,

    { 160.0, 120.0 }
  },

  // Variable: KDz
  //  Referenced by: '<S5>/KDz'

  0.3498F,

  // Variable: Ts
  //  Referenced by: '<S98>/Gain'

  0.0025F,

  // Variable: w_c_pitch
  //  Referenced by: '<S93>/Gain'

  0.03F,

  // Variable: w_c_roll
  //  Referenced by: '<S94>/Gain'

  0.3F,

  // Variable: w_c_yaw
  //  Referenced by: '<S100>/Gain'

  55.0F,

  // Variable: zDz
  //  Referenced by: '<S5>/zDz'

  3.030303F,

  // Expression: [0 0 0 0]
  //  Referenced by: '<S9>/Constant'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S89>/L*(y[k]-yhat[k|k-1])'

  0.0,

  // Expression: 0
  //  Referenced by: '<S91>/deltax'

  0.0,

  // Expression: pInitialization.A
  //  Referenced by: '<S39>/A'

  { 1.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0 },

  // Expression: pInitialization.M
  //  Referenced by: '<S41>/KalmanGainM'

  { 2.3640237993003584E-5, 6.2650522961656867E-5, 7.9342391514520768E-5,
    7.9342391513559027E-5, 0.014775148745627239, 0.039156576851035532,
    0.049588994696575468, 0.049588994695974394, 9.6173948526584967E-14,
    3.1242186433829413E-7, 0.99987498125273067, -4.9993753911877424E-8 },

  // Expression: pInitialization.C
  //  Referenced by: '<S39>/C'

  { 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0 },

  // Expression: pInitialization.L
  //  Referenced by: '<S41>/KalmanGainL'

  { 2.3796864300407757E-5, 6.2848878940443382E-5, 7.9342391514523967E-5,
    7.9342391513559176E-5, 0.014873040187755364, 0.0392805493377795,
    0.049588994696601274, 0.049588994695976725, 7.811508357610397E-10,
    0.0024999998749961664, 0.99987498125273067, -4.9993753911355281E-8 },

  // Expression: 1
  //  Referenced by: '<S37>/Constant'

  1.0,

  // Expression: pInitialization.X0
  //  Referenced by: '<S39>/X0'

  { 0.0, 0.0, 0.0, -0.2 },

  // Expression: 0
  //  Referenced by: '<S38>/Constant'

  0.0,

  // Expression: [0 0 g]
  //  Referenced by: '<S38>/gravity'

  { 0.0, 0.0, 9.81 },

  // Expression: (Vehicle.Airframe.mass)*g
  //  Referenced by: '<S5>/Constant1'

  0.754389,

  // Expression: 0
  //  Referenced by: '<S1>/yaw equilibrium'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=1 for yaw'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/pitch equilibrium'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=2 for pitch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/roll equilibrium'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=1 for roll'

  0.0,

  // Expression: pInitialization.D
  //  Referenced by: '<S39>/D'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S39>/u'

  0.0,

  // Expression: pInitialization.B
  //  Referenced by: '<S39>/B'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: pInitialization.Z
  //  Referenced by: '<S41>/CovarianceZ'

  { 5.910059498250896E-6, 1.5662630740414217E-5, 1.9835597878630189E-5,
    1.983559787838976E-5, 1.5662630740414213E-5, 7.3974317413854647E-5,
    0.00011918164444944701, 0.00011918086339478616, 1.9835597878630192E-5,
    0.000119181644449447, 0.0028155362388445917, 0.00031584878571276414,
    1.9835597878389757E-5, 0.00011918086339478616, 0.00031584878571276409,
    0.00031584891069714891 },

  // Expression: Controller.Q2Ts
  //  Referenced by: '<S6>/TorqueTotalThrustToThrustPerMotor'

  { 0.25F, 0.25F, 0.25F, 0.25F, 151.90799F, -151.90799F, -151.90799F, 151.90799F,
    -5.66592F, 5.66592F, -5.66592F, 5.66592F, 5.66592F, 5.66592F, -5.66592F,
    -5.66592F },

  // Computed Parameter: uDLookupTable2_tableData
  //  Referenced by: '<S11>/1-D Lookup Table2'

  { 0.15F, 0.25F, 0.35F, 0.45F, 0.55F, 0.65F, 0.75F, 0.85F, 0.95F, 1.05F },

  // Computed Parameter: uDLookupTable2_bp01Data
  //  Referenced by: '<S11>/1-D Lookup Table2'

  { 0.0F, 0.05F, 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F },

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S9>/Saturation'

  1.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S9>/Saturation'

  0.0F,

  // Computed Parameter: DiscreteTransferFcn_NumCoef
  //  Referenced by: '<S100>/Discrete Transfer Fcn'

  { 0.0F, 0.00233573909F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef
  //  Referenced by: '<S100>/Discrete Transfer Fcn'

  { 1.0F, -0.871534348F },

  // Computed Parameter: DiscreteTransferFcn_InitialStat
  //  Referenced by: '<S100>/Discrete Transfer Fcn'

  0.0F,

  // Computed Parameter: baro_0_Y0
  //  Referenced by: '<S103>/baro_0'

  0.0F,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S104>/Out1'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S37>/Memory'

  0.0F,

  // Computed Parameter: DiscreteTransferFcn_NumCoef_n
  //  Referenced by: '<S93>/Discrete Transfer Fcn'

  { 0.0F, 0.00249990635F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef_n
  //  Referenced by: '<S93>/Discrete Transfer Fcn'

  { 1.0F, -0.999925F },

  // Computed Parameter: DiscreteTransferFcn_InitialSt_c
  //  Referenced by: '<S93>/Discrete Transfer Fcn'

  0.0F,

  // Computed Parameter: DiscreteTransferFcn_NumCoef_a
  //  Referenced by: '<S94>/Discrete Transfer Fcn'

  { 0.0F, 0.0024990628F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef_o
  //  Referenced by: '<S94>/Discrete Transfer Fcn'

  { 1.0F, -0.999250293F },

  // Computed Parameter: DiscreteTransferFcn_InitialSt_g
  //  Referenced by: '<S94>/Discrete Transfer Fcn'

  0.0F,

  // Computed Parameter: RangfinderScaleGain1_Gain
  //  Referenced by: '<S38>/RangfinderScaleGain1'

  -0.01F,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S12>/Internal'

  { 1.94697928F, -0.948348701F, 1.0F },

  // Computed Parameter: Internal_B
  //  Referenced by: '<S12>/Internal'

  0.03125F,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S12>/Internal'

  { 0.0221048892F, 0.0217175502F },

  // Computed Parameter: Internal_InitialCondition
  //  Referenced by: '<S12>/Internal'

  0.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S5>/Gain'

  -1.0F,

  // Computed Parameter: WithControl1WithoutControl0_Gai
  //  Referenced by: '<S5>/WithControl=1 WithoutControl=0'

  1.0F,

  // Computed Parameter: SaturationThrust_UpperSat
  //  Referenced by: '<S5>/SaturationThrust'

  441.6F,

  // Computed Parameter: SaturationThrust_LowerSat
  //  Referenced by: '<S5>/SaturationThrust'

  -441.6F,

  // Computed Parameter: On1Off0forthrust_Gain
  //  Referenced by: '<S1>/On=1//Off=0 for thrust'

  1.0F,

  // Computed Parameter: Internal_A_d
  //  Referenced by: '<S32>/Internal'

  { 1.94697928F, -0.948348701F, 1.0F },

  // Computed Parameter: Internal_B_f
  //  Referenced by: '<S32>/Internal'

  0.03125F,

  // Computed Parameter: Internal_C_a
  //  Referenced by: '<S32>/Internal'

  { 0.0221048892F, 0.0217175502F },

  // Computed Parameter: Internal_InitialCondition_p
  //  Referenced by: '<S32>/Internal'

  0.0F,

  // Computed Parameter: zDpsi_Gain
  //  Referenced by: '<S10>/zDpsi'

  4.5454545F,

  // Computed Parameter: KDpsi_Gain
  //  Referenced by: '<S10>/KDpsi'

  0.00059488F,

  // Computed Parameter: ChangingofJzz_Gain
  //  Referenced by: '<S1>/Changing of Jzz'

  0.6F,

  // Computed Parameter: Internal_A_j
  //  Referenced by: '<S16>/Internal'

  { 1.94697928F, -0.948348701F, 1.0F },

  // Computed Parameter: Internal_B_k
  //  Referenced by: '<S16>/Internal'

  0.03125F,

  // Computed Parameter: Internal_C_i
  //  Referenced by: '<S16>/Internal'

  { 0.0221048892F, 0.0217175502F },

  // Computed Parameter: Internal_InitialCondition_ps
  //  Referenced by: '<S16>/Internal'

  0.0F,

  // Computed Parameter: Internal_A_f
  //  Referenced by: '<S17>/Internal'

  1.0F,

  // Computed Parameter: Internal_B_b
  //  Referenced by: '<S17>/Internal'

  0.0625F,

  // Computed Parameter: Internal_C_ai
  //  Referenced by: '<S17>/Internal'

  0.04F,

  // Computed Parameter: Internal_D_e
  //  Referenced by: '<S17>/Internal'

  0.62F,

  // Computed Parameter: Internal_InitialCondition_l
  //  Referenced by: '<S17>/Internal'

  0.0F,

  // Computed Parameter: zDtheta_Gain
  //  Referenced by: '<S7>/zDtheta'

  9.21052647F,

  // Computed Parameter: KDtheta_Gain
  //  Referenced by: '<S7>/KDtheta'

  0.00276916637F,

  // Computed Parameter: ChangingofJyy_Gain
  //  Referenced by: '<S1>/Changing of Jyy'

  0.6F,

  // Computed Parameter: Internal_A_a
  //  Referenced by: '<S24>/Internal'

  { 1.94697928F, -0.948348701F, 1.0F },

  // Computed Parameter: Internal_B_h
  //  Referenced by: '<S24>/Internal'

  0.03125F,

  // Computed Parameter: Internal_C_c
  //  Referenced by: '<S24>/Internal'

  { 0.0221048892F, 0.0217175502F },

  // Computed Parameter: Internal_InitialCondition_c
  //  Referenced by: '<S24>/Internal'

  0.0F,

  // Computed Parameter: Internal_A_l
  //  Referenced by: '<S25>/Internal'

  1.0F,

  // Computed Parameter: Internal_B_e
  //  Referenced by: '<S25>/Internal'

  0.0625F,

  // Computed Parameter: Internal_C_g
  //  Referenced by: '<S25>/Internal'

  0.04F,

  // Computed Parameter: Internal_D_h
  //  Referenced by: '<S25>/Internal'

  0.84F,

  // Computed Parameter: Internal_InitialCondition_n
  //  Referenced by: '<S25>/Internal'

  0.0F,

  // Computed Parameter: zDphi_Gain
  //  Referenced by: '<S8>/zDphi'

  9.21052647F,

  // Computed Parameter: KDphi_Gain
  //  Referenced by: '<S8>/KDphi'

  0.00115497201F,

  // Computed Parameter: ChangingofJxx_Gain
  //  Referenced by: '<S1>/Changing of Jxx'

  0.6F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S95>/Gain1'

  -1.0F,

  // Expression: g
  //  Referenced by: '<S95>/Constant'

  9.81F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S95>/Gain2'

  -1.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S95>/Gain3'

  -1.0F,

  // Computed Parameter: Gain_Gain_i
  //  Referenced by: '<S96>/Gain'

  -1.0F,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S87>/isSqrtUsed'

  false,

  // Computed Parameter: Switch_Threshold
  //  Referenced by: '<S9>/Switch'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
