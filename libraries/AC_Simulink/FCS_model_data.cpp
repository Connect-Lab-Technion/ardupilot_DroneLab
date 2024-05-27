//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.6
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Mon May 27 18:48:57 2024
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
  //  Referenced by: '<S5>/Constant1'

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
  //  Referenced by: '<S8>/KDphi'

  0.0008249799999999999,

  // Variable: KDpsi
  //  Referenced by: '<S9>/KDpsi'

  0.00045760000000000006,

  // Variable: KDtheta
  //  Referenced by: '<S7>/KDtheta'

  0.0019779759999999998,

  // Variable: KDz
  //  Referenced by: '<S5>/KDz'

  0.34980000000000006,

  // Variable: Ts
  //  Referenced by: '<S40>/Gain'

  0.0025,

  // Variable: g
  //  Referenced by:
  //    '<S5>/Constant1'
  //    '<S37>/Constant'

  9.81,

  // Variable: w_c_pitch
  //  Referenced by: '<S35>/Gain'

  0.03,

  // Variable: w_c_roll
  //  Referenced by: '<S36>/Gain'

  0.3,

  // Variable: w_c_yaw
  //  Referenced by: '<S42>/Gain'

  55.0,

  // Variable: zDphi
  //  Referenced by: '<S8>/zDphi'

  1.3157894736842106,

  // Variable: zDpsi
  //  Referenced by: '<S9>/zDpsi'

  2.2727272727272729,

  // Variable: zDtheta
  //  Referenced by: '<S7>/zDtheta'

  1.3157894736842106,

  // Variable: zDz
  //  Referenced by: '<S5>/zDz'

  3.0303030303030303,

  // Expression: [num_yaw_disc]
  //  Referenced by: '<S42>/Discrete Transfer Fcn'

  { 0.0, 0.0023357390909607661 },

  // Expression: [den_yaw_disc]
  //  Referenced by: '<S42>/Discrete Transfer Fcn'

  { 1.0, -0.87153434999715784 },

  // Expression: 0
  //  Referenced by: '<S42>/Discrete Transfer Fcn'

  0.0,

  // Expression: 1
  //  Referenced by: '<S2>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S2>/Memory'

  0.0,

  // Expression: [num_pitch_disc]
  //  Referenced by: '<S35>/Discrete Transfer Fcn'

  { 0.0, 0.0024999062523437059 },

  // Expression: [den_pitch_disc]
  //  Referenced by: '<S35>/Discrete Transfer Fcn'

  { 1.0, -0.99992500281242969 },

  // Expression: 0
  //  Referenced by: '<S35>/Discrete Transfer Fcn'

  0.0,

  // Expression: [num_roll_disc]
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 0.0, 0.0024990627343310615 },

  // Expression: [den_roll_disc]
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 1.0, -0.99925028117970072 },

  // Expression: 0
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  0.0,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S11>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B
  //  Referenced by: '<S11>/Internal'

  0.03125,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S11>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: 0
  //  Referenced by: '<S11>/Internal'

  0.0,

  // Expression: 0
  //  Referenced by: '<S5>/Gain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/yaw equilibrium'

  0.0,

  // Computed Parameter: Internal_A_d
  //  Referenced by: '<S31>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B_f
  //  Referenced by: '<S31>/Internal'

  0.03125,

  // Computed Parameter: Internal_C_a
  //  Referenced by: '<S31>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: 0
  //  Referenced by: '<S31>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S1>/Changing of Jzz'

  0.6,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=1 for yaw'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/pitch equilibrium'

  0.0,

  // Computed Parameter: Internal_A_j
  //  Referenced by: '<S15>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B_k
  //  Referenced by: '<S15>/Internal'

  0.03125,

  // Computed Parameter: Internal_C_i
  //  Referenced by: '<S15>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: 0
  //  Referenced by: '<S15>/Internal'

  0.0,

  // Computed Parameter: Internal_A_f
  //  Referenced by: '<S16>/Internal'

  1.0,

  // Computed Parameter: Internal_B_b
  //  Referenced by: '<S16>/Internal'

  0.0625,

  // Computed Parameter: Internal_C_ai
  //  Referenced by: '<S16>/Internal'

  0.039999999999999147,

  // Computed Parameter: Internal_D_e
  //  Referenced by: '<S16>/Internal'

  0.62,

  // Expression: 0
  //  Referenced by: '<S16>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S1>/Changing of Jyy'

  0.6,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=2 for pitch'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/roll equilibrium'

  0.0,

  // Computed Parameter: Internal_A_a
  //  Referenced by: '<S23>/Internal'

  { 1.9469792571014031, -0.948348708312915, 1.0 },

  // Computed Parameter: Internal_B_h
  //  Referenced by: '<S23>/Internal'

  0.03125,

  // Computed Parameter: Internal_C_c
  //  Referenced by: '<S23>/Internal'

  { 0.022104889031669659, 0.021717549736707954 },

  // Expression: 0
  //  Referenced by: '<S23>/Internal'

  0.0,

  // Computed Parameter: Internal_A_l
  //  Referenced by: '<S24>/Internal'

  1.0,

  // Computed Parameter: Internal_B_e
  //  Referenced by: '<S24>/Internal'

  0.0625,

  // Computed Parameter: Internal_C_g
  //  Referenced by: '<S24>/Internal'

  0.039999999999999147,

  // Computed Parameter: Internal_D_h
  //  Referenced by: '<S24>/Internal'

  0.84,

  // Expression: 0
  //  Referenced by: '<S24>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S1>/Changing of Jxx'

  0.6,

  // Expression: 0
  //  Referenced by: '<S1>/On=1//Off=1 for roll'

  0.0,

  // Expression: -1
  //  Referenced by: '<S37>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S37>/Gain3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S38>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S37>/Gain1'

  -1.0,

  // Expression: Controller.Q2Ts
  //  Referenced by: '<S6>/TorqueTotalThrustToThrustPerMotor'

  { 0.25F, 0.25F, 0.25F, 0.25F, 151.90799F, -151.90799F, -151.90799F, 151.90799F,
    -5.66592F, 5.66592F, -5.66592F, 5.66592F, 5.66592F, 5.66592F, -5.66592F,
    -5.66592F },

  // Computed Parameter: SaturationThrust_UpperSat
  //  Referenced by: '<S5>/SaturationThrust'

  1.03909302F,

  // Computed Parameter: SaturationThrust_LowerSat
  //  Referenced by: '<S5>/SaturationThrust'

  -1.03909302F,

  // Computed Parameter: On1Off0forthrust_Gain
  //  Referenced by: '<S1>/On=1//Off=0 for thrust'

  1.0F,

  // Computed Parameter: uDLookupTable_tableData
  //  Referenced by: '<S10>/1-D Lookup Table'

  { 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 1.0F },

  // Computed Parameter: uDLookupTable_bp01Data
  //  Referenced by: '<S10>/1-D Lookup Table'

  { 0.0F, 0.005F, 0.01F, 0.02F, 0.03F, 0.04F, 0.05F, 0.06F, 0.07F, 0.08F },

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S10>/Saturation'

  1.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S10>/Saturation'

  0.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
