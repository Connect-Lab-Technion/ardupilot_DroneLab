//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.24
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Jul 17 11:32:30 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FCS_model.h"

// Block parameters (default storage)
FCS_model::P_FCS_model_T FCS_model::FCS_model_P{
  // Variable: KDz
  //  Referenced by: '<S5>/KDz'

  0.3498F,

  // Variable: Ts
  //  Referenced by: '<S41>/Gain'

  0.0025F,

  // Variable: w_c_pitch
  //  Referenced by: '<S36>/Gain'

  0.03F,

  // Variable: w_c_roll
  //  Referenced by: '<S37>/Gain'

  0.3F,

  // Variable: w_c_yaw
  //  Referenced by: '<S43>/Gain'

  55.0F,

  // Variable: zDz
  //  Referenced by: '<S5>/zDz'

  3.030303F,

  // Expression: [0 0 0 0]
  //  Referenced by: '<S9>/Constant'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: (Vehicle.Airframe.mass)*g
  //  Referenced by: '<S5>/Constant1'

  0.754389,

  // Expression: 0
  //  Referenced by: '<S1>/yaw equilibrium'

  0.0,

  // Expression: 1
  //  Referenced by: '<S2>/Constant'

  1.0,

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

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S9>/Saturation'

  1.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S9>/Saturation'

  0.0F,

  // Expression: Controller.Q2Ts
  //  Referenced by: '<S6>/TorqueTotalThrustToThrustPerMotor'

  { 0.25F, 0.25F, 0.25F, 0.25F, 151.90799F, -151.90799F, -151.90799F, 151.90799F,
    -5.66592F, 5.66592F, -5.66592F, 5.66592F, 5.66592F, 5.66592F, -5.66592F,
    -5.66592F },

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<S11>/1-D Lookup Table'

  { 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 1.0F },

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<S11>/1-D Lookup Table'

  { 0.0F, 0.005F, 0.01F, 0.02F, 0.03F, 0.04F, 0.05F, 0.06F, 0.07F, 0.08F },

  // Computed Parameter: Saturation_UpperSat_e
  //  Referenced by: '<S11>/Saturation'

  1.0F,

  // Computed Parameter: Saturation_LowerSat_j
  //  Referenced by: '<S11>/Saturation'

  0.0F,

  // Computed Parameter: DiscreteTransferFcn_NumCoef
  //  Referenced by: '<S43>/Discrete Transfer Fcn'

  { 0.0F, 0.00233573909F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef
  //  Referenced by: '<S43>/Discrete Transfer Fcn'

  { 1.0F, -0.871534348F },

  // Computed Parameter: DiscreteTransferFcn_InitialStat
  //  Referenced by: '<S43>/Discrete Transfer Fcn'

  0.0F,

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

  0.0F,

  // Computed Parameter: SaturationThrust_UpperSat
  //  Referenced by: '<S5>/SaturationThrust'

  441.6F,

  // Computed Parameter: SaturationThrust_LowerSat
  //  Referenced by: '<S5>/SaturationThrust'

  -441.6F,

  // Computed Parameter: On1Off0forthrust_Gain
  //  Referenced by: '<S1>/On=1//Off=0 for thrust'

  1.0F,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S2>/Memory'

  0.0F,

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

  // Computed Parameter: DiscreteTransferFcn_NumCoef_n
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 0.0F, 0.00249990635F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef_n
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 1.0F, -0.999925F },

  // Computed Parameter: DiscreteTransferFcn_InitialSt_c
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

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

  // Computed Parameter: DiscreteTransferFcn_NumCoef_a
  //  Referenced by: '<S37>/Discrete Transfer Fcn'

  { 0.0F, 0.0024990628F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef_o
  //  Referenced by: '<S37>/Discrete Transfer Fcn'

  { 1.0F, -0.999250293F },

  // Computed Parameter: DiscreteTransferFcn_InitialSt_g
  //  Referenced by: '<S37>/Discrete Transfer Fcn'

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

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S38>/Gain2'

  -1.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S38>/Gain3'

  -1.0F,

  // Computed Parameter: Gain_Gain_i
  //  Referenced by: '<S39>/Gain'

  -1.0F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S38>/Gain1'

  -1.0F,

  // Expression: g
  //  Referenced by: '<S38>/Constant'

  9.81F,

  // Computed Parameter: Switch_Threshold
  //  Referenced by: '<S9>/Switch'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
