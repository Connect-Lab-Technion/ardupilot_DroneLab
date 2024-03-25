//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 3.4
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Mon Mar 25 17:55:09 2024
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
  //  Referenced by: '<S6>/Constant'

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
      0.068,

      { 6.86e-5, 0.0, 0.0, 0.0, 9.2e-5, 0.0, 0.0, 0.0, 0.0001366 },
      0.0624,
      0.044123463146040563,
      -0.015876,
      0.0,
      0.0,
      0.01
    },

    {
      2.0,
      0.033,
      0.008,
      0.0,
      0.000375,
      1.0209375000000001e-7,
      0.0,
      0.0,
      1.0209375000000001e-7,
      0.0107,
      0.00078263752785053692,
      0.15433206602850458,
      0.25481807079117214,
      0.11868238913561441,
      -0.13613568165555773,
      0.15271630954950383,
      5.5,
      0.0034211943997592849,
      0.605147136,
      4.7199903669109095e-8,
      1.1392838555498841e-10,
      4.7199903669109095e-8
    },

    {
      500.0,
      10.0,
      13840.8,
      1530.72683064892
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
  //    '<S6>/Constant'

  9.81,

  // Variable: w_c_pitch
  //  Referenced by: '<S36>/Gain'

  0.3,

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

  { 0.0, 0.0099850149887567487 },

  // Expression: [den_pitch_disc]
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 1.0, -0.997004495503373 },

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

  // Expression: 1
  //  Referenced by: '<S3>/Constant'

  1.0,

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

  // Expression: 1
  //  Referenced by: '<S5>/On=1//Off=2 for pitch'

  1.0,

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
  //  Referenced by: '<S38>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S38>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S38>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S38>/Gain3'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S39>/Gain'

  -1.0,

  // Expression: Controller.Q2Ts
  //  Referenced by: '<S7>/TorqueTotalThrustToThrustPerMotor'

  { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
    -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F, 5.66592F,
    5.66592F, -5.66592F },

  // Computed Parameter: SaturationThrust_UpperSat
  //  Referenced by: '<S6>/SaturationThrust'

  1.20204329F,

  // Computed Parameter: SaturationThrust_LowerSat
  //  Referenced by: '<S6>/SaturationThrust'

  -1.20204329F,

  // Computed Parameter: On1Off0forthrust_Gain
  //  Referenced by: '<S5>/On=1//Off=0 for thrust'

  0.0F,

  // Computed Parameter: uThrustoff_Gain
  //  Referenced by: '<S5>/0 = Thrust off'

  1.0F,

  // Computed Parameter: ThrustToMotorCommand_Gain
  //  Referenced by: '<S11>/ThrustToMotorCommand'

  -1530.72681F,

  // Expression: Vehicle.Motor.maxLimit
  //  Referenced by: '<S11>/Saturation5'

  500.0F,

  // Expression: Vehicle.Motor.minLimit
  //  Referenced by: '<S11>/Saturation5'

  10.0F,

  // Computed Parameter: MotorDirections_Gain
  //  Referenced by: '<S11>/MotorDirections'

  { 1.0F, -1.0F, 1.0F, -1.0F }
};

//
// File trailer for generated code.
//
// [EOF]
//
