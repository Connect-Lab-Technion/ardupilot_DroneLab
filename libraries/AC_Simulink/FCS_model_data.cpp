//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 5.19
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Apr 18 17:44:11 2024
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
  //  Referenced by: '<S6>/Constant1'

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

      { 6.86e-5, 0.0, 0.0, 0.0, 9.2e-5, 0.0, 0.0, 0.0, 0.0001366 },
      0.0624,
      0.044123463146040563,
      -0.015876,
      0.0,
      0.0,
      0.01
    },

    {
      3.0,
      0.0225,
      0.008,
      0.0,
      0.000375,
      4.7460937499999996e-8,
      0.0,
      0.0,
      4.7460937499999996e-8,
      0.0107,
      0.00078263752785053692,
      0.33953054526271004,
      0.25481807079117214,
      0.11868238913561441,
      -0.13613568165555773,
      0.15271630954950383,
      5.5,
      0.0015904312808798326,
      0.28131839999999997,
      1.0200358254425275e-8,
      1.6787067408153957e-11,
      1.0200358254425275e-8
    },

    {
      2000.0,
      1000.0,
      13840.8,
      7083.1001370961685
    }
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
  //  Referenced by: '<S6>/KDz'

  0.34980000000000006,

  // Variable: Ts
  //  Referenced by: '<S41>/Gain'

  0.01,

  // Variable: g
  //  Referenced by:
  //    '<S38>/Constant'
  //    '<S6>/Constant1'

  9.81,

  // Variable: w_c_pitch
  //  Referenced by: '<S36>/Gain'

  0.03,

  // Variable: w_c_roll
  //  Referenced by: '<S37>/Gain'

  0.3,

  // Variable: w_c_yaw
  //  Referenced by: '<S43>/Gain'

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
  //  Referenced by: '<S6>/zDz'

  3.0303030303030303,

  // Expression: [num_yaw_disc]
  //  Referenced by: '<S43>/Discrete Transfer Fcn'

  { 0.0, 0.0076918216294456975 },

  // Expression: [den_yaw_disc]
  //  Referenced by: '<S43>/Discrete Transfer Fcn'

  { 1.0, -0.57694981038048665 },

  // Expression: 0
  //  Referenced by: '<S43>/Discrete Transfer Fcn'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Memory'

  0.0,

  // Expression: [num_pitch_disc]
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 0.0, 0.009998500149988751 },

  // Expression: [den_pitch_disc]
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 1.0, -0.99970004499550036 },

  // Expression: 0
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  0.0,

  // Expression: [num_roll_disc]
  //  Referenced by: '<S37>/Discrete Transfer Fcn'

  { 0.0, 0.0099850149887567487 },

  // Expression: [den_roll_disc]
  //  Referenced by: '<S37>/Discrete Transfer Fcn'

  { 1.0, -0.997004495503373 },

  // Expression: 0
  //  Referenced by: '<S37>/Discrete Transfer Fcn'

  0.0,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S12>/Internal'

  { 1.7886221677380256, -0.808857893484718, 1.0 },

  // Computed Parameter: Internal_B
  //  Referenced by: '<S12>/Internal'

  0.125,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S12>/Internal'

  { 0.083804666191405475, 0.078081139782133921 },

  // Expression: 0
  //  Referenced by: '<S12>/Internal'

  0.0,

  // Expression: 0
  //  Referenced by: '<S6>/Gain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/yaw equilibrium'

  0.0,

  // Computed Parameter: Internal_A_d
  //  Referenced by: '<S32>/Internal'

  { 1.7886221677380256, -0.808857893484718, 1.0 },

  // Computed Parameter: Internal_B_f
  //  Referenced by: '<S32>/Internal'

  0.125,

  // Computed Parameter: Internal_C_a
  //  Referenced by: '<S32>/Internal'

  { 0.083804666191405475, 0.078081139782133921 },

  // Expression: 0
  //  Referenced by: '<S32>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S5>/Changing of Jzz'

  0.6,

  // Expression: 0
  //  Referenced by: '<S5>/On=1//Off=1 for yaw'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/pitch equilibrium'

  0.0,

  // Computed Parameter: Internal_A_j
  //  Referenced by: '<S16>/Internal'

  { 1.7886221677380256, -0.808857893484718, 1.0 },

  // Computed Parameter: Internal_B_k
  //  Referenced by: '<S16>/Internal'

  0.125,

  // Computed Parameter: Internal_C_i
  //  Referenced by: '<S16>/Internal'

  { 0.083804666191405475, 0.078081139782133921 },

  // Expression: 0
  //  Referenced by: '<S16>/Internal'

  0.0,

  // Computed Parameter: Internal_A_f
  //  Referenced by: '<S17>/Internal'

  1.0,

  // Computed Parameter: Internal_B_b
  //  Referenced by: '<S17>/Internal'

  0.125,

  // Computed Parameter: Internal_C_ai
  //  Referenced by: '<S17>/Internal'

  0.080000000000000071,

  // Computed Parameter: Internal_D_e
  //  Referenced by: '<S17>/Internal'

  0.62,

  // Expression: 0
  //  Referenced by: '<S17>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S5>/Changing of Jyy'

  0.6,

  // Expression: 0
  //  Referenced by: '<S5>/On=1//Off=2 for pitch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/roll equilibrium'

  0.0,

  // Computed Parameter: Internal_A_a
  //  Referenced by: '<S24>/Internal'

  { 1.7886221677380256, -0.808857893484718, 1.0 },

  // Computed Parameter: Internal_B_h
  //  Referenced by: '<S24>/Internal'

  0.125,

  // Computed Parameter: Internal_C_c
  //  Referenced by: '<S24>/Internal'

  { 0.083804666191405475, 0.078081139782133921 },

  // Expression: 0
  //  Referenced by: '<S24>/Internal'

  0.0,

  // Computed Parameter: Internal_A_l
  //  Referenced by: '<S25>/Internal'

  1.0,

  // Computed Parameter: Internal_B_e
  //  Referenced by: '<S25>/Internal'

  0.125,

  // Computed Parameter: Internal_C_g
  //  Referenced by: '<S25>/Internal'

  0.079999999999999183,

  // Computed Parameter: Internal_D_h
  //  Referenced by: '<S25>/Internal'

  0.84,

  // Expression: 0
  //  Referenced by: '<S25>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S5>/Changing of Jxx'

  0.6,

  // Expression: 0
  //  Referenced by: '<S5>/On=1//Off=1 for roll'

  0.0,

  // Expression: -1
  //  Referenced by: '<S38>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S38>/Gain3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S39>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S38>/Gain1'

  -1.0,

  // Expression: Controller.Q2Ts
  //  Referenced by: '<S7>/TorqueTotalThrustToThrustPerMotor'

  { 0.25F, 0.25F, 0.25F, 0.25F, 151.90799F, -151.90799F, -151.90799F, 151.90799F,
    -5.66592F, 5.66592F, -5.66592F, 5.66592F, 5.66592F, 5.66592F, -5.66592F,
    -5.66592F },

  // Computed Parameter: SaturationThrust_UpperSat
  //  Referenced by: '<S6>/SaturationThrust'

  1.03909302F,

  // Computed Parameter: SaturationThrust_LowerSat
  //  Referenced by: '<S6>/SaturationThrust'

  -1.03909302F,

  // Computed Parameter: On1Off0forthrust_Gain
  //  Referenced by: '<S5>/On=1//Off=0 for thrust'

  1.0F,

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<S11>/1-D Lookup Table'

  { 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 1.0F },

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<S11>/1-D Lookup Table'

  { 0.0F, 0.005F, 0.01F, 0.02F, 0.03F, 0.04F, 0.05F, 0.06F, 0.07F, 0.08F },

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S11>/Saturation'

  1.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S11>/Saturation'

  0.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
