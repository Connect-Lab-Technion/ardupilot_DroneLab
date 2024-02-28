//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_data.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 1.12
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Feb 27 17:32:46 2024
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
  //  Referenced by: '<S5>/Constant'

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
  //  Referenced by: '<S8>/KDphi'

  0.0008249799999999999,

  // Variable: KDtheta
  //  Referenced by: '<S7>/KDtheta'

  0.0019779759999999998,

  // Variable: g
  //  Referenced by:
  //    '<S37>/Constant'
  //    '<S5>/Constant'

  9.81,

  // Variable: w_c_pitch
  //  Referenced by: '<S35>/Gain'

  0.3,

  // Variable: zDphi
  //  Referenced by: '<S8>/zDphi'

  1.3157894736842106,

  // Variable: zDtheta
  //  Referenced by: '<S7>/zDtheta'

  1.3157894736842106,

  // Variable: KDz
  //  Referenced by: '<S5>/KDz'

  0.3498F,

  // Variable: Ts
  //  Referenced by: '<S40>/Gain'

  0.02F,

  // Variable: w_c_roll
  //  Referenced by: '<S36>/Gain'

  0.3F,

  // Variable: w_c_yaw
  //  Referenced by: '<S42>/Gain'

  55.0F,

  // Variable: zDz
  //  Referenced by: '<S5>/zDz'

  3.030303F,

  // Expression: 0
  //  Referenced by: '<S4>/yaw equilibrium'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/On=1//Off=1 for yaw'

  0.0,

  // Expression: 0
  //  Referenced by: '<S4>/pitch equilibrium'

  0.0,

  // Expression: [num_pitch_disc]
  //  Referenced by: '<S35>/Discrete Transfer Fcn'

  { 0.0, 0.019940119820215783 },

  // Expression: [den_pitch_disc]
  //  Referenced by: '<S35>/Discrete Transfer Fcn'

  { 1.0, -0.99401796405393528 },

  // Expression: 0
  //  Referenced by: '<S35>/Discrete Transfer Fcn'

  0.0,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S16>/Internal'

  1.0,

  // Computed Parameter: Internal_B
  //  Referenced by: '<S16>/Internal'

  0.125,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S16>/Internal'

  0.16000000000000014,

  // Computed Parameter: Internal_D
  //  Referenced by: '<S16>/Internal'

  0.62,

  // Expression: 0
  //  Referenced by: '<S16>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jyy'

  0.6,

  // Expression: 1
  //  Referenced by: '<S4>/On=1//Off=2 for pitch'

  1.0,

  // Expression: 0
  //  Referenced by: '<S4>/roll equilibrium'

  0.0,

  // Expression: [num_roll_disc]
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 0.0, 0.019940119820215783 },

  // Expression: [den_roll_disc]
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 1.0, -0.99401796405393528 },

  // Expression: 0
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  0.0,

  // Computed Parameter: Internal_A_l
  //  Referenced by: '<S24>/Internal'

  1.0,

  // Computed Parameter: Internal_B_e
  //  Referenced by: '<S24>/Internal'

  0.125,

  // Computed Parameter: Internal_C_g
  //  Referenced by: '<S24>/Internal'

  0.16000000000000014,

  // Computed Parameter: Internal_D_h
  //  Referenced by: '<S24>/Internal'

  0.84,

  // Expression: 0
  //  Referenced by: '<S24>/Internal'

  0.0,

  // Expression: 0.6
  //  Referenced by: '<S4>/Changing of Jxx'

  0.6,

  // Expression: 0
  //  Referenced by: '<S4>/On=1//Off=1 for roll'

  0.0,

  // Expression: -1
  //  Referenced by: '<S37>/Gain'

  -1.0,

  // Computed Parameter: DiscreteTransferFcn_NumCoef_j
  //  Referenced by: '<S42>/Discrete Transfer Fcn'

  { 0.0F, 0.0121296169F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef_a
  //  Referenced by: '<S42>/Discrete Transfer Fcn'

  { 1.0F, -0.332871079F },

  // Computed Parameter: DiscreteTransferFcn_InitialSt_a
  //  Referenced by: '<S42>/Discrete Transfer Fcn'

  0.0F,

  // Expression: Controller.Q2Ts
  //  Referenced by: '<S6>/TorqueTotalThrustToThrustPerMotor'

  { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
    -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F, 5.66592F,
    5.66592F, -5.66592F },

  // Computed Parameter: Internal_A_n
  //  Referenced by: '<S11>/Internal'

  { 1.58145344F, -0.654251099F, 1.0F },

  // Computed Parameter: Internal_B_c
  //  Referenced by: '<S11>/Internal'

  0.25F,

  // Computed Parameter: Internal_C_n
  //  Referenced by: '<S11>/Internal'

  { 0.155890346F, 0.13530013F },

  // Computed Parameter: Internal_InitialCondition_e
  //  Referenced by: '<S11>/Internal'

  0.0F,

  // Computed Parameter: SaturationThrust_UpperSat
  //  Referenced by: '<S5>/SaturationThrust'

  1.20204329F,

  // Computed Parameter: SaturationThrust_LowerSat
  //  Referenced by: '<S5>/SaturationThrust'

  -1.20204329F,

  // Computed Parameter: On1Off0forthrust_Gain
  //  Referenced by: '<S4>/On=1//Off=0 for thrust'

  0.0F,

  // Computed Parameter: uThrustoff_Gain
  //  Referenced by: '<S4>/0 = Thrust off'

  1.0F,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S2>/Memory'

  0.0F,

  // Computed Parameter: Internal_A_d
  //  Referenced by: '<S31>/Internal'

  { 1.58145344F, -0.654251099F, 1.0F },

  // Computed Parameter: Internal_B_f
  //  Referenced by: '<S31>/Internal'

  0.25F,

  // Computed Parameter: Internal_C_a
  //  Referenced by: '<S31>/Internal'

  { 0.155890346F, 0.13530013F },

  // Computed Parameter: Internal_InitialCondition_p
  //  Referenced by: '<S31>/Internal'

  0.0F,

  // Computed Parameter: zDpsi_Gain
  //  Referenced by: '<S9>/zDpsi'

  4.5454545F,

  // Computed Parameter: KDpsi_Gain
  //  Referenced by: '<S9>/KDpsi'

  0.00059488F,

  // Computed Parameter: ChangingofJzz_Gain
  //  Referenced by: '<S4>/Changing of Jzz'

  0.6F,

  // Computed Parameter: Internal_A_j
  //  Referenced by: '<S15>/Internal'

  { 1.58145344F, -0.654251099F, 1.0F },

  // Computed Parameter: Internal_B_k
  //  Referenced by: '<S15>/Internal'

  0.25F,

  // Computed Parameter: Internal_C_i
  //  Referenced by: '<S15>/Internal'

  { 0.155890346F, 0.13530013F },

  // Computed Parameter: Internal_InitialCondition_ps
  //  Referenced by: '<S15>/Internal'

  0.0F,

  // Computed Parameter: Internal_A_a
  //  Referenced by: '<S23>/Internal'

  { 1.58145344F, -0.654251099F, 1.0F },

  // Computed Parameter: Internal_B_h
  //  Referenced by: '<S23>/Internal'

  0.25F,

  // Computed Parameter: Internal_C_c
  //  Referenced by: '<S23>/Internal'

  { 0.155890346F, 0.13530013F },

  // Computed Parameter: Internal_InitialCondition_c
  //  Referenced by: '<S23>/Internal'

  0.0F,

  // Computed Parameter: ThrustToMotorCommand_Gain
  //  Referenced by: '<S10>/ThrustToMotorCommand'

  -1530.72681F,

  // Expression: Vehicle.Motor.maxLimit
  //  Referenced by: '<S10>/Saturation5'

  500.0F,

  // Expression: Vehicle.Motor.minLimit
  //  Referenced by: '<S10>/Saturation5'

  10.0F,

  // Computed Parameter: MotorDirections_Gain
  //  Referenced by: '<S10>/MotorDirections'

  { 1.0F, -1.0F, 1.0F, -1.0F },

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S37>/Gain1'

  -1.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S37>/Gain2'

  -1.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S37>/Gain3'

  -1.0F,

  // Computed Parameter: Gain_Gain_i
  //  Referenced by: '<S38>/Gain'

  -1.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
