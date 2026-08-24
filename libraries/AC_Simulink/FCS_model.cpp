//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
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
#include "rtwtypes.h"
#include "FCS_model_types.h"
#include <cmath>
#include "FCS_model_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

//
// Output and update for atomic system:
//    '<S108>/SqrtUsedFcn'
//    '<S180>/SqrtUsedFcn'
//
void FCS_model::FCS_model_SqrtUsedFcn(const real_T rtu_u[4], boolean_T
  rtu_isSqrtUsed, real_T rty_P[4])
{
  if (rtu_isSqrtUsed) {
    for (int32_T i = 0; i < 2; i++) {
      real_T tmp;
      tmp = rtu_u[i + 2];
      rty_P[i] = tmp * rtu_u[2] + rtu_u[i] * rtu_u[0];
      rty_P[i + 2] = tmp * rtu_u[3] + rtu_u[i] * rtu_u[1];
    }
  } else {
    for (int32_T i = 0; i < 2; i++) {
      rty_P[i] = rtu_u[i];
      rty_P[i + 2] = rtu_u[i + 2];
    }
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

// Model step function
void FCS_model::step(in_dashboard *arg_in_dashboard, in_parameters
                     *arg_in_parameters, out_controllers *arg_out_controllers,
                     out_estimators *arg_out_estimators, out_sensors
                     *arg_out_sensors)
{
  // local block i/o variables
  real_T rtb_Switch1;
  real_T rtb_Switch2;
  real_T rtb_ref_yaw;
  real_T rtb_On1Off0forroll;
  real_T rtb_On1Off0forpitch;
  real_T rtb_On1Off0foryaw;
  real_T rtb_MathFunction[9];
  real_T rtb_VectorConcatenate[9];
  real_T rtb_VectorConcatenate_k[9];
  real_T inverseIMU_gain[6];
  real_T rtb_Product1_i[4];
  real_T FIR_IMUaccel[3];
  real_T IIR_IMUgyro_r_tmp[3];
  real_T rtb_Product[3];
  real_T rtb_Product_l[3];
  real_T rtb_r[3];
  real_T rtb_sincos_o1[3];
  real_T rtb_sincos_o1_n[3];
  real_T tmp[3];
  real_T IIRgyroz_tmp[2];
  real_T rtb_Add_c[2];
  real_T rtb_TSamp[2];
  real_T tmp_0[2];
  real_T tmp_1[2];
  real_T DiscreteFilter2_tmp;
  real_T DiscreteTransferFcn_tmp;
  real_T acc1;
  real_T rtb_AvoidDividebyZero;
  real_T rtb_Converttometers;
  real_T rtb_DiscreteTimeIntegrator_j;
  real_T rtb_Integrator_b;
  real_T rtb_K_i;
  real_T rtb_On1Off0forthrust;
  real_T rtb_Product_g_idx_0;
  real_T rtb_Product_g_idx_1;
  real_T rtb_Reshapey_idx_1;
  real_T rtb_Saturation;
  real_T rtb_Saturation_l;
  real_T rtb_Sum1;
  real_T rtb_Sum1_e;
  real_T rtb_VectorConcatenate_tmp;
  real_T rtb_VectorConcatenate_tmp_0;
  real_T rtb_VectorConcatenate_tmp_1;
  real_T rtb_VectorConcatenate_tmp_2;
  real_T rtb_VectorConcatenate_tmp_3;
  real_T rtb_clock;
  real_T rtb_pitchrate;
  real_T rtb_roll;
  real_T rtb_rollrate;
  real_T rtb_sincos_o2_tmp;
  real_T rtb_yawrate;
  real_T tmp_2;
  real_T tmp_3;
  int32_T cff;
  int32_T j;
  int32_T k;
  int32_T memIdx_tmp;
  boolean_T rtb_AND;
  boolean_T rtb_Compare_jy;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator_e3;
  boolean_T rtb_LogicalOperator_f0;

  // DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn'
  rtb_AvoidDividebyZero = FCS_model_P.DiscreteTransferFcn_NumCoef_f[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // Gain: '<S3>/inverseIMU_gain' incorporates:
  //   Constant: '<S3>/Constant2'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S3>/Sum1'

  inverseIMU_gain[0] = (arg_in_parameters->accelerometer_x -
                        FCS_model_P.Constant2_Value) *
    FCS_model_P.inverseIMU_gain_Gain[0];
  inverseIMU_gain[1] = (arg_in_parameters->accelerometer_y -
                        FCS_model_P.Constant2_Value) *
    FCS_model_P.inverseIMU_gain_Gain[1];
  inverseIMU_gain[2] = (arg_in_parameters->accelerometer_z -
                        FCS_model_P.Constant2_Value) *
    FCS_model_P.inverseIMU_gain_Gain[2];
  inverseIMU_gain[3] = (arg_in_parameters->gyroscope_x -
                        FCS_model_P.Constant2_Value) *
    FCS_model_P.inverseIMU_gain_Gain[3];
  inverseIMU_gain[4] = (arg_in_parameters->gyroscope_y -
                        FCS_model_P.Constant2_Value) *
    FCS_model_P.inverseIMU_gain_Gain[4];
  inverseIMU_gain[5] = (arg_in_parameters->gyroscope_z -
                        FCS_model_P.Constant2_Value) *
    FCS_model_P.inverseIMU_gain_Gain[5];
  for (k = 0; k < 3; k++) {
    // DiscreteFir: '<S3>/FIR_IMUaccel' incorporates:
    //   DiscreteFilter: '<S3>/IIR_IMUgyro_r'

    memIdx_tmp = k * 5;
    acc1 = inverseIMU_gain[k] * FCS_model_P.FIR_IMUaccel_Coefficients[0];
    cff = 1;
    for (j = FCS_model_DW.FIR_IMUaccel_circBuf; j < 5; j++) {
      acc1 += FCS_model_DW.FIR_IMUaccel_states[memIdx_tmp + j] *
        FCS_model_P.FIR_IMUaccel_Coefficients[cff];
      cff++;
    }

    for (j = 0; j < FCS_model_DW.FIR_IMUaccel_circBuf; j++) {
      acc1 += FCS_model_DW.FIR_IMUaccel_states[memIdx_tmp + j] *
        FCS_model_P.FIR_IMUaccel_Coefficients[cff];
      cff++;
    }

    FIR_IMUaccel[k] = acc1;

    // End of DiscreteFir: '<S3>/FIR_IMUaccel'

    // DiscreteFilter: '<S3>/IIR_IMUgyro_r'
    rtb_Converttometers = inverseIMU_gain[k + 3];
    for (j = 0; j < 5; j++) {
      rtb_Converttometers -= FCS_model_P.IIR_IMUgyro_r_DenCoef[j + 1] *
        FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp + j];
    }

    rtb_roll = rtb_Converttometers / FCS_model_P.IIR_IMUgyro_r_DenCoef[0];
    IIR_IMUgyro_r_tmp[k] = rtb_roll;
    DiscreteFilter2_tmp = FCS_model_P.IIR_IMUgyro_r_NumCoef[0] * rtb_roll;
    for (j = 0; j < 5; j++) {
      DiscreteFilter2_tmp += FCS_model_P.IIR_IMUgyro_r_NumCoef[j + 1] *
        FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp + j];
    }

    rtb_r[k] = DiscreteFilter2_tmp;
  }

  // Product: '<S188>/Divide' incorporates:
  //   Constant: '<S188>/Constant'
  //   Gain: '<S188>/Gain1'

  rtb_Converttometers = FCS_model_P.Gain1_Gain * FIR_IMUaccel[0] / FCS_model_P.g;

  // Trigonometry: '<S188>/Trigonometric Function1'
  if (rtb_Converttometers > 1.0) {
    rtb_Converttometers = 1.0;
  } else if (rtb_Converttometers < -1.0) {
    rtb_Converttometers = -1.0;
  }

  // Gain: '<S188>/Gain' incorporates:
  //   Trigonometry: '<S188>/Trigonometric Function1'

  rtb_Integrator_b = FCS_model_P.Gain_Gain * std::asin(rtb_Converttometers);

  // Trigonometry: '<S188>/Trigonometric Function' incorporates:
  //   Gain: '<S188>/Gain2'
  //   Gain: '<S188>/Gain3'

  rtb_roll = rt_atan2d_snf(FCS_model_P.Gain2_Gain * FIR_IMUaccel[1],
    FCS_model_P.Gain3_Gain * FIR_IMUaccel[2]);

  // Trigonometry: '<S189>/Trigonometric Function2'
  rtb_rollrate = std::sin(rtb_roll);
  rtb_Converttometers = std::cos(rtb_roll);

  // Sum: '<S189>/Sum1' incorporates:
  //   Gain: '<S189>/Gain'
  //   Product: '<S189>/Product4'
  //   Product: '<S189>/Product5'

  rtb_pitchrate = FCS_model_P.Gain_Gain_p * rtb_rollrate * rtb_r[2] +
    rtb_Converttometers * rtb_r[1];

  // DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn' incorporates:
  //   Gain: '<S186>/Gain'
  //   Sum: '<S186>/Sum'

  DiscreteTransferFcn_tmp = ((FCS_model_P.w_c_pitch * rtb_Integrator_b +
    rtb_pitchrate) - FCS_model_P.DiscreteTransferFcn_DenCoef_b[1] *
    FCS_model_DW.DiscreteTransferFcn_states_a) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_b[0];
  DiscreteFilter2_tmp = FCS_model_P.DiscreteTransferFcn_NumCoef_o[0] *
    DiscreteTransferFcn_tmp + FCS_model_P.DiscreteTransferFcn_NumCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states_a;

  // If: '<S190>/If1' incorporates:
  //   Constant: '<S32>/Constant'
  //   DataTypeConversion: '<S190>/Data Type Conversion'

  if (static_cast<real32_T>(FCS_model_P.Constant_Value_c) > 0.0F) {
    // Outputs for IfAction SubSystem: '<S190>/If Action Subsystem' incorporates:
    //   ActionPort: '<S192>/Action Port'

    // Merge: '<S190>/Merge1' incorporates:
    //   DiscreteTransferFcn: '<S193>/Discrete Transfer Fcn'

    FCS_model_DW.Memory_PreviousInput = FCS_model_P.DiscreteTransferFcn_NumCoef
      [1] * FCS_model_DW.DiscreteTransferFcn_states_p;

    // Update for DiscreteTransferFcn: '<S193>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S193>/Gain'
    //   Inport: '<Root>/in_parameters'
    //   Sum: '<S193>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_p = ((FCS_model_P.w_c_yaw *
      arg_in_parameters->yaw + rtb_r[2]) -
      FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_p) /
      FCS_model_P.DiscreteTransferFcn_DenCoef[0];

    // End of Outputs for SubSystem: '<S190>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S190>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S191>/Action Port'

    // Merge: '<S190>/Merge1' incorporates:
    //   Gain: '<S191>/Gain'
    //   Memory: '<S32>/Memory'
    //   Sum: '<S191>/Sum'

    FCS_model_DW.Memory_PreviousInput += FCS_model_P.Ts * rtb_r[2];

    // End of Outputs for SubSystem: '<S190>/If Action Subsystem3'
  }

  // End of If: '<S190>/If1'

  // SignalConversion generated from: '<S37>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn'

  rtb_sincos_o1[0] = FCS_model_DW.Memory_PreviousInput;
  rtb_sincos_o1[1] = DiscreteFilter2_tmp;
  rtb_sincos_o1[2] = rtb_AvoidDividebyZero;

  // Trigonometry: '<S132>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn'
  //   SignalConversion generated from: '<S37>/sincos'
  //   Trigonometry: '<S44>/sincos'

  rtb_On1Off0forthrust = std::sin(FCS_model_DW.Memory_PreviousInput);
  rtb_sincos_o2_tmp = std::cos(FCS_model_DW.Memory_PreviousInput);
  rtb_Product_g_idx_0 = std::sin(DiscreteFilter2_tmp);
  rtb_Sum1 = std::cos(DiscreteFilter2_tmp);
  rtb_yawrate = std::sin(rtb_AvoidDividebyZero);
  rtb_Sum1_e = std::cos(rtb_AvoidDividebyZero);

  // Fcn: '<S132>/Fcn11' incorporates:
  //   Fcn: '<S44>/Fcn11'
  //   Trigonometry: '<S132>/sincos'

  rtb_Product_g_idx_1 = rtb_sincos_o2_tmp * rtb_Sum1;
  rtb_VectorConcatenate[0] = rtb_Product_g_idx_1;

  // Fcn: '<S132>/Fcn21' incorporates:
  //   Fcn: '<S132>/Fcn22'
  //   Fcn: '<S44>/Fcn21'
  //   Trigonometry: '<S132>/sincos'

  rtb_clock = rtb_Product_g_idx_0 * rtb_yawrate;
  rtb_VectorConcatenate_tmp_0 = rtb_clock * rtb_sincos_o2_tmp -
    rtb_On1Off0forthrust * rtb_Sum1_e;
  rtb_VectorConcatenate[1] = rtb_VectorConcatenate_tmp_0;

  // Fcn: '<S132>/Fcn31' incorporates:
  //   Fcn: '<S132>/Fcn32'
  //   Fcn: '<S44>/Fcn31'
  //   Trigonometry: '<S132>/sincos'

  rtb_VectorConcatenate_tmp = rtb_Product_g_idx_0 * rtb_Sum1_e;
  rtb_VectorConcatenate_tmp_1 = rtb_VectorConcatenate_tmp * rtb_sincos_o2_tmp +
    rtb_On1Off0forthrust * rtb_yawrate;
  rtb_VectorConcatenate[2] = rtb_VectorConcatenate_tmp_1;

  // Fcn: '<S132>/Fcn12' incorporates:
  //   Fcn: '<S44>/Fcn12'
  //   Trigonometry: '<S132>/sincos'

  rtb_VectorConcatenate_tmp_2 = rtb_On1Off0forthrust * rtb_Sum1;
  rtb_VectorConcatenate[3] = rtb_VectorConcatenate_tmp_2;

  // Fcn: '<S132>/Fcn22' incorporates:
  //   Fcn: '<S44>/Fcn22'
  //   Trigonometry: '<S132>/sincos'

  rtb_clock = rtb_clock * rtb_On1Off0forthrust + rtb_sincos_o2_tmp * rtb_Sum1_e;
  rtb_VectorConcatenate[4] = rtb_clock;

  // Fcn: '<S132>/Fcn32' incorporates:
  //   Fcn: '<S44>/Fcn32'
  //   Trigonometry: '<S132>/sincos'

  rtb_VectorConcatenate_tmp = rtb_VectorConcatenate_tmp * rtb_On1Off0forthrust -
    rtb_sincos_o2_tmp * rtb_yawrate;
  rtb_VectorConcatenate[5] = rtb_VectorConcatenate_tmp;

  // Fcn: '<S132>/Fcn13' incorporates:
  //   Trigonometry: '<S132>/sincos'

  rtb_VectorConcatenate[6] = -rtb_Product_g_idx_0;

  // Fcn: '<S132>/Fcn23' incorporates:
  //   Fcn: '<S44>/Fcn23'
  //   Trigonometry: '<S132>/sincos'

  rtb_sincos_o2_tmp = rtb_Sum1 * rtb_yawrate;
  rtb_VectorConcatenate[7] = rtb_sincos_o2_tmp;

  // Fcn: '<S132>/Fcn33' incorporates:
  //   Fcn: '<S44>/Fcn33'
  //   Trigonometry: '<S132>/sincos'

  rtb_VectorConcatenate_tmp_3 = rtb_Sum1 * rtb_Sum1_e;
  rtb_VectorConcatenate[8] = rtb_VectorConcatenate_tmp_3;
  for (k = 0; k < 3; k++) {
    // Math: '<S130>/Math Function' incorporates:
    //   Concatenate: '<S185>/Vector Concatenate'

    rtb_MathFunction[3 * k] = rtb_VectorConcatenate[k];
    rtb_MathFunction[3 * k + 1] = rtb_VectorConcatenate[k + 3];
    rtb_MathFunction[3 * k + 2] = rtb_VectorConcatenate[k + 6];

    // Trigonometry: '<S37>/sincos'
    rtb_Sum1 = rtb_sincos_o1[k];
    rtb_sincos_o1_n[k] = std::sin(rtb_Sum1);
    rtb_Product_l[k] = std::cos(rtb_Sum1);
  }

  // Fcn: '<S37>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_Product_l[0] * rtb_Product_l[1];

  // Fcn: '<S37>/Fcn21' incorporates:
  //   Fcn: '<S37>/Fcn22'

  rtb_Sum1 = rtb_sincos_o1_n[1] * rtb_sincos_o1_n[2];
  rtb_VectorConcatenate_k[1] = rtb_Sum1 * rtb_Product_l[0] - rtb_sincos_o1_n[0] *
    rtb_Product_l[2];

  // Fcn: '<S37>/Fcn31' incorporates:
  //   Fcn: '<S37>/Fcn32'

  rtb_Sum1_e = rtb_sincos_o1_n[1] * rtb_Product_l[2];
  rtb_VectorConcatenate_k[2] = rtb_Sum1_e * rtb_Product_l[0] + rtb_sincos_o1_n[0]
    * rtb_sincos_o1_n[2];

  // Fcn: '<S37>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_sincos_o1_n[0] * rtb_Product_l[1];

  // Fcn: '<S37>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_Sum1 * rtb_sincos_o1_n[0] + rtb_Product_l[0] *
    rtb_Product_l[2];

  // Fcn: '<S37>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_Sum1_e * rtb_sincos_o1_n[0] - rtb_Product_l[0]
    * rtb_sincos_o1_n[2];

  // Fcn: '<S37>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_sincos_o1_n[1];

  // Fcn: '<S37>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_Product_l[1] * rtb_sincos_o1_n[2];

  // Fcn: '<S37>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_Product_l[1] * rtb_Product_l[2];

  // Gain: '<S1>/On=1//Off=0 for thrust'
  rtb_On1Off0forthrust = FCS_model_P.On1Off0forthrust_Gain * 0.0;

  // DiscreteStateSpace: '<S18>/Internal'
  {
    rtb_On1Off0foryaw = (FCS_model_P.Internal_C[0])*
      FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_C[1])*FCS_model_DW.Internal_DSTATE[1];
  }

  // Sum: '<S10>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn'

  rtb_Sum1 = rtb_On1Off0foryaw - rtb_AvoidDividebyZero;

  // Gain: '<S1>/On=1//Off=0 for yaw' incorporates:
  //   Trigonometry: '<S189>/Trigonometric Function3'

  rtb_On1Off0foryaw = std::cos(rtb_Integrator_b);

  // Product: '<S189>/Divide1'
  rtb_yawrate = rtb_rollrate / rtb_On1Off0foryaw;

  // Gain: '<S1>/On=1//Off=0 for yaw' incorporates:
  //   Product: '<S189>/Divide2'
  //   Product: '<S189>/Product9'

  rtb_On1Off0foryaw = rtb_Converttometers / rtb_On1Off0foryaw;
  rtb_On1Off0foryaw *= rtb_r[2];

  // Sum: '<S189>/Sum2' incorporates:
  //   Product: '<S189>/Product8'

  rtb_yawrate = rtb_yawrate * rtb_r[1] + rtb_On1Off0foryaw;

  // Gain: '<S1>/On=1//Off=0 for yaw' incorporates:
  //   Constant: '<S4>/yaw equilibrium'
  //   Gain: '<S10>/KDpsi'
  //   Gain: '<S10>/zDpsi'
  //   Gain: '<S4>/Changing of Jzz'
  //   Sum: '<S10>/Sum3'
  //   Sum: '<S4>/Sum3'

  rtb_On1Off0foryaw = ((FCS_model_P.zDpsi * 2.0 * rtb_Sum1 - rtb_yawrate) *
                       (FCS_model_P.KDpsi * 1.3) *
                       FCS_model_P.ChangingofJzz_Gain +
                       FCS_model_P.yawequilibrium_Value) *
    FCS_model_P.On1Off0foryaw_Gain;

  // Abs: '<S8>/Abs' incorporates:
  //   Abs: '<S40>/Abs2'
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'

  rtb_Saturation = std::abs(DiscreteFilter2_tmp);

  // Gain: '<S1>/On=1//Off=0 for pitch' incorporates:
  //   Abs: '<S8>/Abs'

  rtb_On1Off0forpitch = rtb_Saturation;

  // Logic: '<S8>/AND' incorporates:
  //   Constant: '<S11>/Constant'
  //   Inport: '<Root>/in_dashboard'
  //   Logic: '<S8>/NOT'
  //   RelationalOperator: '<S11>/Compare'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  rtb_AND = ((rtb_On1Off0forpitch >= FCS_model_P.CompareToConstant_const) ||
             (!arg_in_dashboard->master_switch));

  // DiscreteStateSpace: '<S12>/Internal'
  {
    rtb_On1Off0forpitch = (FCS_model_P.Internal_C_n[0])*
      FCS_model_DW.Internal_DSTATE_l[0]
      + (FCS_model_P.Internal_C_n[1])*FCS_model_DW.Internal_DSTATE_l[1];
  }

  // Sum: '<S8>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'

  rtb_Sum1 = rtb_On1Off0forpitch - DiscreteFilter2_tmp;

  // DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
  if (rtb_AND) {
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE =
      FCS_model_P.DiscreteTimeIntegrator_IC;

    // Gain: '<S1>/On=1//Off=0 for pitch' incorporates:
    //   Constant: '<S8>/Constant'
    //   DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
    //   Switch: '<S8>/Switch'

    rtb_On1Off0forpitch = FCS_model_P.Constant_Value;
  } else {
    // Gain: '<S1>/On=1//Off=0 for pitch' incorporates:
    //   Gain: '<S8>/Kd'
    //   Gain: '<S8>/Kp'
    //   Sum: '<S8>/Sum'
    //   Sum: '<S8>/Sum3'
    //   Switch: '<S8>/Switch'

    rtb_On1Off0forpitch = ((FCS_model_P.Kp_Gain * rtb_Sum1 +
      FCS_model_DW.DiscreteTimeIntegrator_DSTATE) - rtb_pitchrate) *
      FCS_model_P.Kd_Gain;
  }

  // End of DiscreteIntegrator: '<S8>/Discrete-Time Integrator'

  // Gain: '<S1>/On=1//Off=0 for pitch' incorporates:
  //   Constant: '<S4>/pitch equilibrium'
  //   Gain: '<S4>/Changing of Jyy'
  //   Sum: '<S4>/Sum1'

  rtb_On1Off0forpitch = (FCS_model_P.ChangingofJyy_Gain * rtb_On1Off0forpitch +
    FCS_model_P.pitchequilibrium_Value) * FCS_model_P.On1Off0forpitch_Gain;

  // DiscreteStateSpace: '<S15>/Internal'
  {
    rtb_On1Off0forroll = (FCS_model_P.Internal_C_nj[0])*
      FCS_model_DW.Internal_DSTATE_k[0]
      + (FCS_model_P.Internal_C_nj[1])*FCS_model_DW.Internal_DSTATE_k[1];
  }

  // Sum: '<S9>/Sum1'
  rtb_Sum1_e = rtb_On1Off0forroll - FCS_model_DW.Memory_PreviousInput;

  // Trigonometry: '<S189>/Trigonometric Function4'
  rtb_Integrator_b = std::tan(rtb_Integrator_b);

  // Sum: '<S189>/Sum' incorporates:
  //   Product: '<S189>/Product'
  //   Product: '<S189>/Product1'
  //   Product: '<S189>/Product2'
  //   Product: '<S189>/Product3'

  rtb_rollrate = (rtb_rollrate * rtb_Integrator_b * rtb_r[1] + rtb_r[0]) +
    rtb_Converttometers * rtb_Integrator_b * rtb_r[2];

  // Gain: '<S1>/On=1//Off=0 for roll' incorporates:
  //   Constant: '<S4>/roll equilibrium'
  //   DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  //   Gain: '<S4>/Changing of Jxx'
  //   Gain: '<S9>/kd_rol'
  //   Gain: '<S9>/ki_rol'
  //   Gain: '<S9>/kp_rol'
  //   Sum: '<S4>/Sum2'
  //   Sum: '<S9>/Sum'
  //   Sum: '<S9>/Sum3'

  rtb_On1Off0forroll = (((FCS_model_P.ki_rol *
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_p + FCS_model_P.kp_rol *
    rtb_Sum1_e) - FCS_model_P.kd_rol * rtb_rollrate) *
                        FCS_model_P.ChangingofJxx_Gain +
                        FCS_model_P.rollequilibrium_Value) *
    FCS_model_P.On1Off0forroll_Gain;
  for (k = 0; k < 4; k++) {
    // Saturate: '<S28>/Saturation' incorporates:
    //   Bias: '<S29>/Bias'
    //   Constant: '<S27>/TorqueTotalThrustToThrustPerMotor'
    //   Gain: '<S29>/thrustToMotor'
    //   Inport: '<Root>/in_dashboard'
    //   Product: '<S27>/Product'
    //   Product: '<S28>/Product'
    //   SignalConversion generated from: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<S27>/Product'

    rtb_Converttometers = ((((FCS_model_P.TorqueTotalThrustToThrustPerMot[k + 4]
      * rtb_On1Off0foryaw + FCS_model_P.TorqueTotalThrustToThrustPerMot[k] *
      rtb_On1Off0forthrust) + FCS_model_P.TorqueTotalThrustToThrustPerMot[k + 8]
      * rtb_On1Off0forpitch) + FCS_model_P.TorqueTotalThrustToThrustPerMot[k +
      12] * rtb_On1Off0forroll) * FCS_model_P.Vehicle.Motor.thrustToMotorCommand
      + (FCS_model_P.Vehicle.Motor.commandToW2Offset + 0.2)) *
      arg_in_dashboard->power;
    if (rtb_Converttometers > FCS_model_P.Vehicle.Motor.maxLimit) {
      rtb_Converttometers = FCS_model_P.Vehicle.Motor.maxLimit;
    } else if (rtb_Converttometers < FCS_model_P.Vehicle.Motor.minLimit) {
      rtb_Converttometers = FCS_model_P.Vehicle.Motor.minLimit;
    }

    // Product: '<S28>/Product1' incorporates:
    //   Gain: '<S29>/thrustToMotor'
    //   Inport: '<Root>/in_dashboard'
    //   Saturate: '<S28>/Saturation'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Product1_i[k] = rtb_Converttometers * static_cast<real_T>
      (arg_in_dashboard->master_switch);
  }

  // Delay: '<S41>/MemoryX' incorporates:
  //   Constant: '<S41>/X0'

  if (FCS_model_DW.icLoad) {
    FCS_model_DW.MemoryX_DSTATE[0] = FCS_model_P.X0_Value[0];
    FCS_model_DW.MemoryX_DSTATE[1] = FCS_model_P.X0_Value[1];
  }

  for (k = 0; k < 2; k++) {
    // DiscreteFilter: '<S40>/IIRgyroz'
    memIdx_tmp = k * 5;
    rtb_Converttometers = rtb_r[k];
    for (j = 0; j < 5; j++) {
      rtb_Converttometers -= FCS_model_P.IIRgyroz_DenCoef[j + 1] *
        FCS_model_DW.IIRgyroz_states[memIdx_tmp + j];
    }

    rtb_Converttometers /= FCS_model_P.IIRgyroz_DenCoef[0];
    IIRgyroz_tmp[k] = rtb_Converttometers;
    rtb_Converttometers *= FCS_model_P.IIRgyroz_NumCoef[0];
    for (j = 0; j < 5; j++) {
      rtb_Converttometers += FCS_model_P.IIRgyroz_NumCoef[j + 1] *
        FCS_model_DW.IIRgyroz_states[memIdx_tmp + j];
    }

    // SampleTimeMath: '<S48>/TSamp' incorporates:
    //   DiscreteFilter: '<S40>/IIRgyroz'
    //
    //  About '<S48>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_Converttometers *= FCS_model_P.TSamp_WtEt;
    rtb_TSamp[k] = rtb_Converttometers;

    // Sum: '<S48>/Diff' incorporates:
    //   UnitDelay: '<S48>/UD'
    //
    //  Block description for '<S48>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S48>/UD':
    //
    //   Store in Global RAM

    rtb_Add_c[k] = rtb_Converttometers - FCS_model_DW.UD_DSTATE[k];
  }

  // Abs: '<S40>/Abs' incorporates:
  //   Abs: '<S40>/Abs4'

  rtb_Integrator_b = std::abs(rtb_r[0]);

  // Abs: '<S40>/Abs1' incorporates:
  //   Abs: '<S40>/Abs5'

  rtb_K_i = std::abs(rtb_r[1]);

  // Logic: '<S40>/Logical Operator' incorporates:
  //   Abs: '<S40>/Abs'
  //   Abs: '<S40>/Abs1'
  //   Abs: '<S40>/Abs3'
  //   Abs: '<S40>/Abs6'
  //   Abs: '<S40>/Abs7'
  //   Constant: '<S49>/Constant'
  //   Constant: '<S50>/Constant'
  //   Constant: '<S51>/Constant'
  //   Constant: '<S53>/Constant'
  //   Constant: '<S55>/Constant'
  //   Constant: '<S56>/Constant'
  //   DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn'
  //   RelationalOperator: '<S49>/Compare'
  //   RelationalOperator: '<S50>/Compare'
  //   RelationalOperator: '<S51>/Compare'
  //   RelationalOperator: '<S53>/Compare'
  //   RelationalOperator: '<S55>/Compare'
  //   RelationalOperator: '<S56>/Compare'

  rtb_AND = ((rtb_Saturation <= FCS_model_P.maxp_const) && (std::abs
              (rtb_AvoidDividebyZero) <= FCS_model_P.maxq_const) &&
             (rtb_Integrator_b <= FCS_model_P.maxw1_const) && (rtb_K_i <=
              FCS_model_P.maxw2_const) && (std::abs(rtb_Add_c[0]) <=
              FCS_model_P.maxdw1_const) && (std::abs(rtb_Add_c[1]) <=
              FCS_model_P.maxdw2_const));

  // Delay: '<S131>/MemoryX' incorporates:
  //   Constant: '<S131>/X0'

  if (FCS_model_DW.icLoad_m) {
    FCS_model_DW.MemoryX_DSTATE_f[0] = FCS_model_P.X0_Value_n[0];
    FCS_model_DW.MemoryX_DSTATE_f[1] = FCS_model_P.X0_Value_n[1];
  }

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Constant: '<S3>/Constant2'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S3>/Sum3'

  rtb_Converttometers = (arg_in_parameters->rangefinder_distance -
    FCS_model_P.Constant2_Value) * FCS_model_P.Converttometers_Gain;

  // SignalConversion generated from: '<S130>/Product2' incorporates:
  //   Constant: '<S130>/Constant'

  acc1 = FCS_model_P.Constant_Value_h[0];
  tmp_3 = FCS_model_P.Constant_Value_h[1];

  // Product: '<S130>/Product2' incorporates:
  //   Math: '<S130>/Math Function'
  //   SignalConversion generated from: '<S130>/Product2'

  for (k = 0; k < 3; k++) {
    rtb_sincos_o1_n[k] = (rtb_MathFunction[k + 3] * tmp_3 + rtb_MathFunction[k] *
                          acc1) + rtb_MathFunction[k + 6] * rtb_Converttometers;
  }

  // End of Product: '<S130>/Product2'

  // Outputs for Enabled SubSystem: '<S159>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S184>/Enable'

  // Constant: '<S131>/Enable'
  if (FCS_model_P.Enable_Value) {
    FCS_model_DW.EnabledSubsystem_MODE = true;

    // Sum: '<S184>/Add1' incorporates:
    //   Constant: '<S131>/C'
    //   Delay: '<S131>/MemoryX'
    //   Product: '<S184>/Product'

    rtb_DiscreteTimeIntegrator_j = rtb_sincos_o1_n[2] - (FCS_model_P.C_Value_f[0]
      * FCS_model_DW.MemoryX_DSTATE_f[0] + FCS_model_P.C_Value_f[1] *
      FCS_model_DW.MemoryX_DSTATE_f[1]);

    // Product: '<S184>/Product2' incorporates:
    //   Constant: '<S133>/KalmanGainM'

    FCS_model_B.Product2[0] = FCS_model_P.KalmanGainM_Value_b[0] *
      rtb_DiscreteTimeIntegrator_j;
    FCS_model_B.Product2[1] = FCS_model_P.KalmanGainM_Value_b[1] *
      rtb_DiscreteTimeIntegrator_j;
  } else if (FCS_model_DW.EnabledSubsystem_MODE) {
    // Disable for Product: '<S184>/Product2' incorporates:
    //   Outport: '<S184>/deltax'

    FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;
    FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;
    FCS_model_DW.EnabledSubsystem_MODE = false;
  }

  // End of Outputs for SubSystem: '<S159>/Enabled Subsystem'

  // Sum: '<S159>/Add' incorporates:
  //   Delay: '<S131>/MemoryX'

  rtb_Add_c[0] = FCS_model_B.Product2[0] + FCS_model_DW.MemoryX_DSTATE_f[0];

  // Logic: '<S40>/Logical Operator3' incorporates:
  //   Abs: '<S40>/Abs8'
  //   Abs: '<S40>/Abs9'
  //   Constant: '<S52>/Constant'
  //   Constant: '<S54>/Constant'
  //   Constant: '<S57>/Constant'
  //   Constant: '<S58>/Constant'
  //   Constant: '<S59>/Constant'
  //   Delay: '<S35>/Delay'
  //   Inport: '<Root>/in_parameters'
  //   Logic: '<S40>/Logical Operator1'
  //   Logic: '<S40>/Logical Operator2'
  //   RelationalOperator: '<S52>/Compare'
  //   RelationalOperator: '<S54>/Compare'
  //   RelationalOperator: '<S57>/Compare'
  //   RelationalOperator: '<S58>/Compare'
  //   RelationalOperator: '<S59>/Compare'
  //   Sum: '<S40>/Add'

  rtb_LogicalOperator3 = ((rtb_AND || ((rtb_Integrator_b <=
    FCS_model_P.maxp2_const) && (rtb_K_i <= FCS_model_P.maxq2_const))) && (std::
    abs(arg_in_parameters->opticalflow_x - FCS_model_DW.Delay_DSTATE[0]) <=
    FCS_model_P.maxw3_const) && (std::abs(arg_in_parameters->opticalflow_y -
    FCS_model_DW.Delay_DSTATE[1]) <= FCS_model_P.maxw4_const) && (rtb_Add_c[0] <=
    FCS_model_P.minHeightforOF_const));

  // Logic: '<S122>/Logical Operator' incorporates:
  //   Constant: '<S122>/Constant'
  //   Constant: '<S122>/Time constant'
  //   Constant: '<S125>/Constant'
  //   Constant: '<S126>/Constant'
  //   RelationalOperator: '<S125>/Compare'
  //   RelationalOperator: '<S126>/Compare'
  //   Sum: '<S122>/Sum1'

  rtb_AND = ((FCS_model_P.LowPassFilterDiscreteorContin_l - FCS_model_B.Probe[0]
              <= FCS_model_P.Constant_Value_o) &&
             (FCS_model_P.LowPassFilterDiscreteorContin_i <
              FCS_model_P.CompareToConstant_const_m));

  // Gain: '<S114>/K' incorporates:
  //   Inport: '<Root>/in_parameters'

  rtb_Integrator_b = FCS_model_P.LowPassFilterDiscreteorContinuo *
    arg_in_parameters->opticalflow_x;

  // DiscreteIntegrator: '<S128>/Integrator'
  if (FCS_model_DW.Integrator_IC_LOADING != 0) {
    FCS_model_DW.Integrator_DSTATE = rtb_Integrator_b;
    if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  if (rtb_AND || (FCS_model_DW.Integrator_PrevResetState != 0)) {
    FCS_model_DW.Integrator_DSTATE = rtb_Integrator_b;
    if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  // End of DiscreteIntegrator: '<S128>/Integrator'

  // Saturate: '<S128>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Saturation_UpperSat) {
    rtb_Saturation = FCS_model_P.Saturation_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Saturation_LowerSat) {
    rtb_Saturation = FCS_model_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = FCS_model_DW.Integrator_DSTATE;
  }

  // End of Saturate: '<S128>/Saturation'

  // Logic: '<S115>/Logical Operator' incorporates:
  //   Constant: '<S115>/Constant'
  //   Constant: '<S115>/Time constant'
  //   Constant: '<S118>/Constant'
  //   Constant: '<S119>/Constant'
  //   RelationalOperator: '<S118>/Compare'
  //   RelationalOperator: '<S119>/Compare'
  //   Sum: '<S115>/Sum1'

  rtb_LogicalOperator_e3 = ((FCS_model_P.LowPassFilterDiscreteorContin_a -
    FCS_model_B.Probe_c[0] <= FCS_model_P.Constant_Value_l) &&
    (FCS_model_P.LowPassFilterDiscreteorConti_d0 <
     FCS_model_P.CompareToConstant_const_p));

  // Gain: '<S113>/K' incorporates:
  //   Inport: '<Root>/in_parameters'

  rtb_K_i = FCS_model_P.LowPassFilterDiscreteorContin_d *
    arg_in_parameters->opticalflow_y;

  // DiscreteIntegrator: '<S121>/Integrator'
  if (FCS_model_DW.Integrator_IC_LOADING_g != 0) {
    FCS_model_DW.Integrator_DSTATE_e = rtb_K_i;
    if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Integrator_UpperSat_i) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
    } else if (FCS_model_DW.Integrator_DSTATE_e <
               FCS_model_P.Integrator_LowerSat_l) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
    }
  }

  if (rtb_LogicalOperator_e3 || (FCS_model_DW.Integrator_PrevResetState_e != 0))
  {
    FCS_model_DW.Integrator_DSTATE_e = rtb_K_i;
    if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Integrator_UpperSat_i) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
    } else if (FCS_model_DW.Integrator_DSTATE_e <
               FCS_model_P.Integrator_LowerSat_l) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
    }
  }

  // End of DiscreteIntegrator: '<S121>/Integrator'

  // Saturate: '<S121>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Saturation_UpperSat_k) {
    rtb_Saturation_l = FCS_model_P.Saturation_UpperSat_k;
  } else if (FCS_model_DW.Integrator_DSTATE_e <
             FCS_model_P.Saturation_LowerSat_h) {
    rtb_Saturation_l = FCS_model_P.Saturation_LowerSat_h;
  } else {
    rtb_Saturation_l = FCS_model_DW.Integrator_DSTATE_e;
  }

  // End of Saturate: '<S121>/Saturation'

  // Reshape: '<S41>/Reshapey' incorporates:
  //   Bias: '<S42>/Bias2'
  //   Bias: '<S42>/Bias3'
  //   Delay: '<S42>/Delay1'
  //   Delay: '<S42>/Delay2'
  //   Gain: '<S42>/Gain4'
  //   Gain: '<S42>/Gain5'
  //   Product: '<S42>/Product2'
  //   Product: '<S42>/Product3'
  //   Sum: '<S42>/Subtract2'
  //   Sum: '<S42>/Subtract3'

  rtb_DiscreteTimeIntegrator_j = (rtb_Converttometers + FCS_model_P.Bias3_Bias) *
    FCS_model_P.Gain5_Gain * (rtb_Saturation - FCS_model_DW.Delay2_DSTATE[0U]);
  rtb_Reshapey_idx_1 = (rtb_Converttometers + FCS_model_P.Bias2_Bias) *
    FCS_model_P.Gain4_Gain * (rtb_Saturation_l - FCS_model_DW.Delay1_DSTATE[0U]);

  // Outputs for Enabled SubSystem: '<S86>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S112>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.EnabledSubsystem_MODE_g = true;

    // Sum: '<S112>/Add1' incorporates:
    //   Constant: '<S41>/C'
    //   Delay: '<S41>/MemoryX'
    //   Product: '<S112>/Product'

    acc1 = rtb_DiscreteTimeIntegrator_j - (FCS_model_P.C_Value[0] *
      FCS_model_DW.MemoryX_DSTATE[0] + FCS_model_DW.MemoryX_DSTATE[1] *
      FCS_model_P.C_Value[2]);
    tmp_3 = rtb_Reshapey_idx_1 - (FCS_model_DW.MemoryX_DSTATE[0] *
      FCS_model_P.C_Value[1] + FCS_model_DW.MemoryX_DSTATE[1] *
      FCS_model_P.C_Value[3]);

    // Product: '<S112>/Product2' incorporates:
    //   Constant: '<S60>/KalmanGainM'

    FCS_model_B.Product2_c[0] = FCS_model_P.KalmanGainM_Value[0] * acc1 +
      FCS_model_P.KalmanGainM_Value[2] * tmp_3;
    FCS_model_B.Product2_c[1] = FCS_model_P.KalmanGainM_Value[1] * acc1 +
      FCS_model_P.KalmanGainM_Value[3] * tmp_3;
  } else if (FCS_model_DW.EnabledSubsystem_MODE_g) {
    // Disable for Product: '<S112>/Product2' incorporates:
    //   Outport: '<S112>/deltax'

    FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;
    FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;
    FCS_model_DW.EnabledSubsystem_MODE_g = false;
  }

  // End of Outputs for SubSystem: '<S86>/Enabled Subsystem'

  // Sum: '<S86>/Add' incorporates:
  //   Delay: '<S35>/Delay'
  //   Delay: '<S41>/MemoryX'

  FCS_model_DW.Delay_DSTATE[0] = FCS_model_B.Product2_c[0] +
    FCS_model_DW.MemoryX_DSTATE[0];

  // SignalConversion generated from: '<S130>/Product1' incorporates:
  //   Constant: '<S31>/Constant'

  acc1 = FCS_model_P.Constant_Value_c1[0];

  // Sum: '<S86>/Add' incorporates:
  //   Delay: '<S35>/Delay'
  //   Delay: '<S41>/MemoryX'

  FCS_model_DW.Delay_DSTATE[1] = FCS_model_B.Product2_c[1] +
    FCS_model_DW.MemoryX_DSTATE[1];

  // SignalConversion generated from: '<S130>/Product1' incorporates:
  //   Constant: '<S31>/Constant'
  //   Delay: '<S131>/MemoryX'
  //   Sum: '<S159>/Add'

  tmp_3 = FCS_model_P.Constant_Value_c1[1];
  tmp_2 = FCS_model_B.Product2[1] + FCS_model_DW.MemoryX_DSTATE_f[1];

  // Product: '<S130>/Product1' incorporates:
  //   Concatenate: '<S185>/Vector Concatenate'

  for (k = 0; k < 3; k++) {
    rtb_sincos_o1[k] = (rtb_VectorConcatenate[k + 3] * tmp_3 +
                        rtb_VectorConcatenate[k] * acc1) +
      rtb_VectorConcatenate[k + 6] * tmp_2;
  }

  // End of Product: '<S130>/Product1'

  // Product: '<S34>/Product' incorporates:
  //   Concatenate: '<S47>/Vector Concatenate'
  //   Delay: '<S35>/Delay'
  //   Math: '<S34>/Math Function'
  //   SignalConversion generated from: '<S34>/Product'

  tmp_3 = FCS_model_DW.Delay_DSTATE[1];
  tmp_2 = FCS_model_DW.Delay_DSTATE[0];
  acc1 = rtb_sincos_o1[2];
  for (k = 0; k < 3; k++) {
    rtb_Product[k] = (rtb_VectorConcatenate_k[3 * k + 1] * tmp_3 +
                      rtb_VectorConcatenate_k[3 * k] * tmp_2) +
      rtb_VectorConcatenate_k[3 * k + 2] * acc1;
  }

  // End of Product: '<S34>/Product'

  // DiscreteFir: '<S130>/FIR_IMUaccel'
  acc1 = FIR_IMUaccel[0] * FCS_model_P.FIR_IMUaccel_Coefficients_a[0];
  cff = 1;
  for (j = FCS_model_DW.FIR_IMUaccel_circBuf_b; j < 5; j++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states_i[j] *
      FCS_model_P.FIR_IMUaccel_Coefficients_a[cff];
    cff++;
  }

  for (j = 0; j < FCS_model_DW.FIR_IMUaccel_circBuf_b; j++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states_i[j] *
      FCS_model_P.FIR_IMUaccel_Coefficients_a[cff];
    cff++;
  }

  rtb_Product_l[0] = acc1;
  acc1 = FCS_model_P.FIR_IMUaccel_Coefficients_a[0] * FIR_IMUaccel[1];
  cff = 1;
  for (j = FCS_model_DW.FIR_IMUaccel_circBuf_b; j < 5; j++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states_i[j + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients_a[cff];
    cff++;
  }

  for (j = 0; j < FCS_model_DW.FIR_IMUaccel_circBuf_b; j++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states_i[j + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients_a[cff];
    cff++;
  }

  rtb_Product_l[1] = acc1;
  acc1 = FCS_model_P.FIR_IMUaccel_Coefficients_a[0] * FIR_IMUaccel[2];
  cff = 1;
  for (j = FCS_model_DW.FIR_IMUaccel_circBuf_b; j < 5; j++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states_i[j + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients_a[cff];
    cff++;
  }

  for (j = 0; j < FCS_model_DW.FIR_IMUaccel_circBuf_b; j++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states_i[j + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients_a[cff];
    cff++;
  }

  // Product: '<S130>/Product'
  tmp_3 = rtb_Product_l[1];
  tmp_2 = rtb_Product_l[0];

  // Fcn: '<S44>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_Product_g_idx_1;

  // Fcn: '<S44>/Fcn21'
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_tmp_0;

  // Fcn: '<S44>/Fcn31'
  rtb_VectorConcatenate_k[2] = rtb_VectorConcatenate_tmp_1;

  // Fcn: '<S44>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_VectorConcatenate_tmp_2;

  // Fcn: '<S44>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_clock;

  // Fcn: '<S44>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_VectorConcatenate_tmp;

  // Fcn: '<S44>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_Product_g_idx_0;

  // Fcn: '<S44>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_sincos_o2_tmp;

  // Fcn: '<S44>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_VectorConcatenate_tmp_3;

  // RelationalOperator: '<S43>/Compare' incorporates:
  //   Constant: '<S43>/Constant'

  rtb_Compare_jy = (rtb_Add_c[0] <= FCS_model_P.DeactivateAccelerationIfOFisnot);

  // Logic: '<S39>/Logical Operator' incorporates:
  //   Constant: '<S45>/Constant'
  //   Constant: '<S46>/Constant'
  //   Inport: '<Root>/in_parameters'
  //   RelationalOperator: '<S45>/Compare'
  //   RelationalOperator: '<S46>/Compare'

  rtb_LogicalOperator_f0 = ((arg_in_parameters->opticalflow_x !=
    FCS_model_P.donotuseaccifopticalflowneverav) ||
    (arg_in_parameters->opticalflow_y !=
     FCS_model_P.donotuseaccifopticalflownever_c));

  // Product: '<S39>/Product1' incorporates:
  //   Constant: '<S39>/gravity'

  rtb_Product_g_idx_0 = FCS_model_P.gravity_Value_a[1];
  rtb_Product_g_idx_1 = FCS_model_P.gravity_Value_a[0];
  rtb_clock = FCS_model_P.gravity_Value_a[2];
  for (k = 0; k < 3; k++) {
    // Sum: '<S130>/Sum' incorporates:
    //   Constant: '<S130>/gravity'
    //   DiscreteFir: '<S130>/FIR_IMUaccel'
    //   Math: '<S130>/Math Function'
    //   Product: '<S130>/Product'

    rtb_Product_l[k] = ((rtb_MathFunction[k + 3] * tmp_3 + rtb_MathFunction[k] *
                         tmp_2) + rtb_MathFunction[k + 6] * acc1) +
      FCS_model_P.gravity_Value[k];

    // Sum: '<S39>/Add' incorporates:
    //   Concatenate: '<S47>/Vector Concatenate'
    //   Constant: '<S39>/gravity'
    //   Product: '<S39>/Product1'

    tmp[k] = FIR_IMUaccel[k] - ((rtb_VectorConcatenate_k[k + 3] *
      rtb_Product_g_idx_0 + rtb_VectorConcatenate_k[k] * rtb_Product_g_idx_1) +
      rtb_VectorConcatenate_k[k + 6] * rtb_clock);
  }

  // Product: '<S39>/Product' incorporates:
  //   Gain: '<S39>/gainaccinput'

  rtb_Product_g_idx_0 = FCS_model_P.gainaccinput_Gain * tmp[0] *
    static_cast<real_T>(rtb_LogicalOperator_f0) * static_cast<real_T>
    (rtb_Compare_jy);
  rtb_Product_g_idx_1 = FCS_model_P.gainaccinput_Gain * tmp[1] *
    static_cast<real_T>(rtb_LogicalOperator_f0) * static_cast<real_T>
    (rtb_Compare_jy);

  // Outputs for Enabled SubSystem: '<S79>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S110>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.MeasurementUpdate_MODE_h = true;

    // Sum: '<S110>/Sum' incorporates:
    //   Constant: '<S41>/C'
    //   Constant: '<S41>/D'
    //   Delay: '<S41>/MemoryX'
    //   Product: '<S110>/C[k]*xhat[k|k-1]'
    //   Product: '<S110>/D[k]*u[k]'
    //   Sum: '<S110>/Add1'

    rtb_DiscreteTimeIntegrator_j -= (FCS_model_P.C_Value[0] *
      FCS_model_DW.MemoryX_DSTATE[0] + FCS_model_DW.MemoryX_DSTATE[1] *
      FCS_model_P.C_Value[2]) + (FCS_model_P.D_Value[0] * rtb_Product_g_idx_0 +
      FCS_model_P.D_Value[2] * rtb_Product_g_idx_1);
    rtb_Reshapey_idx_1 -= (FCS_model_DW.MemoryX_DSTATE[0] * FCS_model_P.C_Value
      [1] + FCS_model_DW.MemoryX_DSTATE[1] * FCS_model_P.C_Value[3]) +
      (FCS_model_P.D_Value[1] * rtb_Product_g_idx_0 + FCS_model_P.D_Value[3] *
       rtb_Product_g_idx_1);

    // Product: '<S110>/Product3' incorporates:
    //   Constant: '<S60>/KalmanGainL'

    FCS_model_B.Product3_d[0] = FCS_model_P.KalmanGainL_Value[0] *
      rtb_DiscreteTimeIntegrator_j + FCS_model_P.KalmanGainL_Value[2] *
      rtb_Reshapey_idx_1;
    FCS_model_B.Product3_d[1] = FCS_model_P.KalmanGainL_Value[1] *
      rtb_DiscreteTimeIntegrator_j + FCS_model_P.KalmanGainL_Value[3] *
      rtb_Reshapey_idx_1;
  } else if (FCS_model_DW.MeasurementUpdate_MODE_h) {
    // Disable for Product: '<S110>/Product3' incorporates:
    //   Outport: '<S110>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_DW.MeasurementUpdate_MODE_h = false;
  }

  // End of Outputs for SubSystem: '<S79>/MeasurementUpdate'

  // Outputs for Enabled SubSystem: '<S153>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S182>/Enable'

  // Constant: '<S131>/Enable'
  if (FCS_model_P.Enable_Value) {
    FCS_model_DW.MeasurementUpdate_MODE = true;

    // Sum: '<S182>/Sum' incorporates:
    //   Constant: '<S131>/C'
    //   Constant: '<S131>/D'
    //   Delay: '<S131>/MemoryX'
    //   Product: '<S182>/C[k]*xhat[k|k-1]'
    //   Product: '<S182>/D[k]*u[k]'
    //   Sum: '<S182>/Add1'

    rtb_DiscreteTimeIntegrator_j = rtb_sincos_o1_n[2] - ((FCS_model_P.C_Value_f
      [0] * FCS_model_DW.MemoryX_DSTATE_f[0] + FCS_model_P.C_Value_f[1] *
      FCS_model_DW.MemoryX_DSTATE_f[1]) + FCS_model_P.D_Value_k * rtb_Product_l
      [2]);

    // Product: '<S182>/Product3' incorporates:
    //   Constant: '<S133>/KalmanGainL'

    FCS_model_B.Product3[0] = FCS_model_P.KalmanGainL_Value_m[0] *
      rtb_DiscreteTimeIntegrator_j;
    FCS_model_B.Product3[1] = FCS_model_P.KalmanGainL_Value_m[1] *
      rtb_DiscreteTimeIntegrator_j;
  } else if (FCS_model_DW.MeasurementUpdate_MODE) {
    // Disable for Product: '<S182>/Product3' incorporates:
    //   Outport: '<S182>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_h;
    FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_h;
    FCS_model_DW.MeasurementUpdate_MODE = false;
  }

  // End of Outputs for SubSystem: '<S153>/MeasurementUpdate'

  // Gain: '<S22>/Gain1' incorporates:
  //   Delay: '<S35>/Delay'
  //   DiscreteIntegrator: '<S34>/SimplyIntegrateVelocity'
  //   Gain: '<S22>/Gain3'
  //   Gain: '<S22>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S22>/Subtract'
  //   Sum: '<S22>/Sum1'

  rtb_clock = ((arg_in_dashboard->ref_x -
                FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0]) *
               FCS_model_P.Gain3_Gain_g - FCS_model_P.Gain4_Gain_m *
               FCS_model_DW.Delay_DSTATE[0]) * FCS_model_P.Gain1_Gain_b;

  // Saturate: '<S22>/Saturation'
  if (rtb_clock > FCS_model_P.Saturation_UpperSat_d) {
    rtb_clock = FCS_model_P.Saturation_UpperSat_d;
  } else if (rtb_clock < FCS_model_P.Saturation_LowerSat_a) {
    rtb_clock = FCS_model_P.Saturation_LowerSat_a;
  }

  // End of Saturate: '<S22>/Saturation'

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch1_Threshold) {
    // Switch: '<S4>/Switch1'
    rtb_Switch1 = rtb_clock;
  } else {
    // Switch: '<S4>/Switch1' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Switch1 = arg_in_dashboard->ref_pitch;
  }

  // End of Switch: '<S4>/Switch1'

  // Gain: '<S23>/Gain1' incorporates:
  //   Delay: '<S35>/Delay'
  //   DiscreteIntegrator: '<S34>/SimplyIntegrateVelocity'
  //   Gain: '<S23>/Gain3'
  //   Gain: '<S23>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S23>/Subtract'
  //   Sum: '<S23>/Sum1'

  rtb_DiscreteTimeIntegrator_j = ((arg_in_dashboard->ref_y -
    FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1]) * FCS_model_P.Gain3_Gain_i -
    FCS_model_P.Gain4_Gain_h * FCS_model_DW.Delay_DSTATE[1]) *
    FCS_model_P.Gain1_Gain_i;

  // Saturate: '<S23>/Saturation'
  if (rtb_DiscreteTimeIntegrator_j > FCS_model_P.Saturation_UpperSat_ku) {
    rtb_DiscreteTimeIntegrator_j = FCS_model_P.Saturation_UpperSat_ku;
  } else if (rtb_DiscreteTimeIntegrator_j < FCS_model_P.Saturation_LowerSat_j) {
    rtb_DiscreteTimeIntegrator_j = FCS_model_P.Saturation_LowerSat_j;
  }

  // End of Saturate: '<S23>/Saturation'

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch2_Threshold) {
    // Switch: '<S4>/Switch2'
    rtb_Switch2 = rtb_DiscreteTimeIntegrator_j;
  } else {
    // Switch: '<S4>/Switch2' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Switch2 = arg_in_dashboard->ref_roll;
  }

  // End of Switch: '<S4>/Switch2'

  // Outport: '<Root>/out_controllers' incorporates:
  //   BusCreator generated from: '<Root>/out_controllers'
  //   Constant: '<S6>/Constant'

  arg_out_controllers->motor1 = rtb_Product1_i[0];
  arg_out_controllers->motor2 = rtb_Product1_i[1];
  arg_out_controllers->motor3 = rtb_Product1_i[2];
  arg_out_controllers->motor4 = rtb_Product1_i[3];
  arg_out_controllers->cmd_thrust = rtb_On1Off0forthrust;
  arg_out_controllers->cmd_tau_roll = rtb_On1Off0foryaw;
  arg_out_controllers->cmd_tau_pitch = rtb_On1Off0forpitch;
  arg_out_controllers->cmd_tau_yaw = rtb_On1Off0forroll;
  arg_out_controllers->cmd_roll = rtb_clock;
  arg_out_controllers->cmd_pitch = rtb_DiscreteTimeIntegrator_j;
  arg_out_controllers->cmd_yaw = FCS_model_P.Constant_Value_e;

  // Outport: '<Root>/out_estimators' incorporates:
  //   BusCreator generated from: '<Root>/out_estimators'
  //   Delay: '<S35>/Delay'
  //   DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S34>/SimplyIntegrateVelocity'
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn'
  //   Gain: '<S30>/Gain'

  arg_out_estimators->orient_roll = rtb_AvoidDividebyZero;
  arg_out_estimators->orient_pitch = DiscreteFilter2_tmp;
  arg_out_estimators->orient_yaw = FCS_model_DW.Memory_PreviousInput;
  arg_out_estimators->orient_rate_roll = rtb_rollrate;
  arg_out_estimators->orient_rate_pitch = rtb_pitchrate;
  arg_out_estimators->orient_rate_yaw = rtb_yawrate;
  arg_out_estimators->pos_x = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0];
  arg_out_estimators->pos_y = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1];
  arg_out_estimators->pos_z = rtb_Add_c[0];
  arg_out_estimators->pos_dx = FCS_model_DW.Delay_DSTATE[0];
  arg_out_estimators->pos_dy = FCS_model_DW.Delay_DSTATE[1];
  arg_out_estimators->pos_dz = rtb_sincos_o1[2];
  arg_out_estimators->battery_SOC = FCS_model_P.Gain_Gain_h *
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o;

  // MinMax: '<S115>/Max' incorporates:
  //   Constant: '<S115>/Time constant'

  if ((FCS_model_B.Probe_c[0] >= FCS_model_P.LowPassFilterDiscreteorContin_a) ||
      rtIsNaN(FCS_model_P.LowPassFilterDiscreteorContin_a)) {
    rtb_clock = FCS_model_B.Probe_c[0];
  } else {
    rtb_clock = FCS_model_P.LowPassFilterDiscreteorContin_a;
  }

  // End of MinMax: '<S115>/Max'

  // Fcn: '<S115>/Avoid Divide by Zero'
  rtb_AvoidDividebyZero = static_cast<real_T>(rtb_clock == 0.0) *
    2.2204460492503131e-16 + rtb_clock;

  // MinMax: '<S122>/Max' incorporates:
  //   Constant: '<S122>/Time constant'

  if ((FCS_model_B.Probe[0] >= FCS_model_P.LowPassFilterDiscreteorContin_l) ||
      rtIsNaN(FCS_model_P.LowPassFilterDiscreteorContin_l)) {
    rtb_clock = FCS_model_B.Probe[0];
  } else {
    rtb_clock = FCS_model_P.LowPassFilterDiscreteorContin_l;
  }

  // End of MinMax: '<S122>/Max'

  // DiscreteFilter: '<S3>/Discrete Filter2' incorporates:
  //   Constant: '<S3>/Constant2'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S3>/Sum2'

  DiscreteFilter2_tmp = ((((arg_in_parameters->barometer_pressure -
    FCS_model_P.Constant2_Value) - FCS_model_DW.DiscreteFilter2_states[0] *
    FCS_model_P.DiscreteFilter2_DenCoef[1]) -
    FCS_model_DW.DiscreteFilter2_states[1] *
    FCS_model_P.DiscreteFilter2_DenCoef[2]) -
    FCS_model_DW.DiscreteFilter2_states[2] *
    FCS_model_P.DiscreteFilter2_DenCoef[3]) /
    FCS_model_P.DiscreteFilter2_DenCoef[0];

  // Outport: '<Root>/out_sensors' incorporates:
  //   BusCreator generated from: '<Root>/out_sensors'
  //   DigitalClock: '<S3>/Digital Clock'
  //   DiscreteFilter: '<S3>/Discrete Filter2'

  arg_out_sensors->clock = (((&FCS_model_M)->Timing.clockTick0) * 0.0025);
  arg_out_sensors->accelerometer_x = FIR_IMUaccel[0];
  arg_out_sensors->accelerometer_y = FIR_IMUaccel[1];
  arg_out_sensors->accelerometer_z = FIR_IMUaccel[2];
  arg_out_sensors->gyroscope_x = rtb_r[0];
  arg_out_sensors->gyroscope_y = rtb_r[1];
  arg_out_sensors->gyroscope_z = rtb_r[2];
  arg_out_sensors->barometer_pressure = ((FCS_model_P.DiscreteFilter2_NumCoef[0]
    * DiscreteFilter2_tmp + FCS_model_DW.DiscreteFilter2_states[0] *
    FCS_model_P.DiscreteFilter2_NumCoef[1]) +
    FCS_model_DW.DiscreteFilter2_states[1] *
    FCS_model_P.DiscreteFilter2_NumCoef[2]) +
    FCS_model_DW.DiscreteFilter2_states[2] *
    FCS_model_P.DiscreteFilter2_NumCoef[3];
  arg_out_sensors->rangefinder_distance = rtb_Converttometers;

  // MATLAB Function: '<S108>/SqrtUsedFcn' incorporates:
  //   Constant: '<S108>/isSqrtUsed'
  //   Constant: '<S60>/CovarianceZ'

  FCS_model_SqrtUsedFcn(FCS_model_P.CovarianceZ_Value,
                        FCS_model_P.isSqrtUsed_Value, rtb_Product1_i);

  // MATLAB Function: '<S180>/SqrtUsedFcn' incorporates:
  //   Constant: '<S133>/CovarianceZ'
  //   Constant: '<S180>/isSqrtUsed'

  FCS_model_SqrtUsedFcn(FCS_model_P.CovarianceZ_Value_g,
                        FCS_model_P.isSqrtUsed_Value_a, rtb_Product1_i);

  // SignalConversion generated from: '<Root>/in_dashboard' incorporates:
  //   Inport: '<Root>/in_dashboard'

  rtb_ref_yaw = arg_in_dashboard->ref_yaw;

  // Update for DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn' incorporates:
  //   Gain: '<S187>/Gain'
  //   Sum: '<S187>/Sum'

  FCS_model_DW.DiscreteTransferFcn_states = ((FCS_model_P.w_c_roll * rtb_roll +
    rtb_rollrate) - FCS_model_P.DiscreteTransferFcn_DenCoef_p[1] *
    FCS_model_DW.DiscreteTransferFcn_states) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_p[0];

  // Update for DiscreteFir: '<S3>/FIR_IMUaccel'
  // Update circular buffer index
  FCS_model_DW.FIR_IMUaccel_circBuf--;
  if (FCS_model_DW.FIR_IMUaccel_circBuf < 0) {
    FCS_model_DW.FIR_IMUaccel_circBuf = 4;
  }

  // Update circular buffer
  for (k = 0; k < 3; k++) {
    FCS_model_DW.FIR_IMUaccel_states[FCS_model_DW.FIR_IMUaccel_circBuf + k * 5] =
      inverseIMU_gain[k];

    // Update for DiscreteFilter: '<S3>/IIR_IMUgyro_r'
    memIdx_tmp = k * 5;
    FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp + 4] =
      FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp + 3];
    FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp + 3] =
      FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp + 2];
    FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp + 2] =
      FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp + 1];
    FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp + 1] =
      FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp];
    FCS_model_DW.IIR_IMUgyro_r_states[memIdx_tmp] = IIR_IMUgyro_r_tmp[k];
  }

  // End of Update for DiscreteFir: '<S3>/FIR_IMUaccel'

  // Update for DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states_a = DiscreteTransferFcn_tmp;

  // Update for DiscreteStateSpace: '<S18>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_A[1])*FCS_model_DW.Internal_DSTATE[1];
    xnew[0] += FCS_model_P.Internal_B*rtb_ref_yaw;
    xnew[1] = (FCS_model_P.Internal_A[2])*FCS_model_DW.Internal_DSTATE[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteStateSpace: '<S12>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_e[0])*FCS_model_DW.Internal_DSTATE_l[0]
      + (FCS_model_P.Internal_A_e[1])*FCS_model_DW.Internal_DSTATE_l[1];
    xnew[0] += FCS_model_P.Internal_B_j*rtb_Switch1;
    xnew[1] = (FCS_model_P.Internal_A_e[2])*FCS_model_DW.Internal_DSTATE_l[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_l[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S8>/Ki'

  FCS_model_DW.DiscreteTimeIntegrator_DSTATE += FCS_model_P.Ki_Gain * rtb_Sum1 *
    FCS_model_P.DiscreteTimeIntegrator_gainval;

  // Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  FCS_model_DW.DiscreteTimeIntegrator_DSTATE_p +=
    FCS_model_P.DiscreteTimeIntegrator_gainva_k * rtb_Sum1_e;

  // Update for DiscreteStateSpace: '<S15>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_d[0])*FCS_model_DW.Internal_DSTATE_k[0]
      + (FCS_model_P.Internal_A_d[1])*FCS_model_DW.Internal_DSTATE_k[1];
    xnew[0] += FCS_model_P.Internal_B_g*rtb_Switch2;
    xnew[1] = (FCS_model_P.Internal_A_d[2])*FCS_model_DW.Internal_DSTATE_k[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_k[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for Delay: '<S41>/MemoryX'
  FCS_model_DW.icLoad = false;

  // Product: '<S79>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S41>/A'
  //   Delay: '<S41>/MemoryX'

  tmp_0[0] = FCS_model_P.A_Value[0] * FCS_model_DW.MemoryX_DSTATE[0] +
    FCS_model_DW.MemoryX_DSTATE[1] * FCS_model_P.A_Value[2];

  // Product: '<S79>/B[k]*u[k]' incorporates:
  //   Constant: '<S41>/B'

  rtb_Add_c[0] = FCS_model_P.B_Value[0] * rtb_Product_g_idx_0 +
    FCS_model_P.B_Value[2] * rtb_Product_g_idx_1;

  // Product: '<S79>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S41>/A'
  //   Delay: '<S41>/MemoryX'

  tmp_0[1] = FCS_model_DW.MemoryX_DSTATE[0] * FCS_model_P.A_Value[1] +
    FCS_model_DW.MemoryX_DSTATE[1] * FCS_model_P.A_Value[3];

  // Product: '<S79>/B[k]*u[k]' incorporates:
  //   Constant: '<S41>/B'

  rtb_Add_c[1] = FCS_model_P.B_Value[1] * rtb_Product_g_idx_0 +
    FCS_model_P.B_Value[3] * rtb_Product_g_idx_1;

  // Update for Delay: '<S131>/MemoryX'
  FCS_model_DW.icLoad_m = false;

  // Delay: '<S131>/MemoryX' incorporates:
  //   Constant: '<S131>/A'
  //   Product: '<S153>/A[k]*xhat[k|k-1]'

  rtb_roll = FCS_model_DW.MemoryX_DSTATE_f[1];
  rtb_rollrate = FCS_model_DW.MemoryX_DSTATE_f[0];
  for (k = 0; k < 2; k++) {
    // Update for Delay: '<S41>/MemoryX' incorporates:
    //   Sum: '<S79>/Add'

    FCS_model_DW.MemoryX_DSTATE[k] = (rtb_Add_c[k] + tmp_0[k]) +
      FCS_model_B.Product3_d[k];

    // Update for DiscreteFilter: '<S40>/IIRgyroz'
    memIdx_tmp = k * 5;
    FCS_model_DW.IIRgyroz_states[memIdx_tmp + 4] =
      FCS_model_DW.IIRgyroz_states[memIdx_tmp + 3];
    FCS_model_DW.IIRgyroz_states[memIdx_tmp + 3] =
      FCS_model_DW.IIRgyroz_states[memIdx_tmp + 2];
    FCS_model_DW.IIRgyroz_states[memIdx_tmp + 2] =
      FCS_model_DW.IIRgyroz_states[memIdx_tmp + 1];
    FCS_model_DW.IIRgyroz_states[memIdx_tmp + 1] =
      FCS_model_DW.IIRgyroz_states[memIdx_tmp];
    FCS_model_DW.IIRgyroz_states[memIdx_tmp] = IIRgyroz_tmp[k];

    // Update for UnitDelay: '<S48>/UD'
    //
    //  Block description for '<S48>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[k] = rtb_TSamp[k];

    // Product: '<S153>/A[k]*xhat[k|k-1]' incorporates:
    //   Constant: '<S131>/A'
    //   Delay: '<S131>/MemoryX'

    tmp_1[k] = FCS_model_P.A_Value_p[k + 2] * rtb_roll + FCS_model_P.A_Value_p[k]
      * rtb_rollrate;
  }

  // Update for Delay: '<S131>/MemoryX' incorporates:
  //   Constant: '<S131>/B'
  //   Product: '<S153>/B[k]*u[k]'
  //   Product: '<S182>/Product3'
  //   Sum: '<S153>/Add'

  FCS_model_DW.MemoryX_DSTATE_f[0] = (FCS_model_P.B_Value_o[0] * rtb_Product_l[2]
    + tmp_1[0]) + FCS_model_B.Product3[0];
  FCS_model_DW.MemoryX_DSTATE_f[1] = (FCS_model_P.B_Value_o[1] * rtb_Product_l[2]
    + tmp_1[1]) + FCS_model_B.Product3[1];

  // Update for DiscreteIntegrator: '<S128>/Integrator' incorporates:
  //   Fcn: '<S122>/Avoid Divide by Zero'
  //   Product: '<S114>/1//T'
  //   Sum: '<S114>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING = 0U;
  FCS_model_DW.Integrator_DSTATE += 1.0 / (static_cast<real_T>(rtb_clock == 0.0)
    * 2.2204460492503131e-16 + rtb_clock) * (rtb_Integrator_b - rtb_Saturation) *
    FCS_model_P.Integrator_gainval;
  if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Integrator_UpperSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Integrator_LowerSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
  }

  FCS_model_DW.Integrator_PrevResetState = static_cast<int8_T>(rtb_AND);

  // End of Update for DiscreteIntegrator: '<S128>/Integrator'

  // Update for Delay: '<S42>/Delay2'
  for (k = 0; k < 39; k++) {
    FCS_model_DW.Delay2_DSTATE[k] = FCS_model_DW.Delay2_DSTATE[k + 1];
  }

  FCS_model_DW.Delay2_DSTATE[39] = rtb_r[0];

  // End of Update for Delay: '<S42>/Delay2'

  // Update for DiscreteIntegrator: '<S121>/Integrator' incorporates:
  //   Product: '<S113>/1//T'
  //   Sum: '<S113>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING_g = 0U;
  FCS_model_DW.Integrator_DSTATE_e += 1.0 / rtb_AvoidDividebyZero * (rtb_K_i -
    rtb_Saturation_l) * FCS_model_P.Integrator_gainval_g;
  if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Integrator_UpperSat_i) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
  } else if (FCS_model_DW.Integrator_DSTATE_e <
             FCS_model_P.Integrator_LowerSat_l) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
  }

  FCS_model_DW.Integrator_PrevResetState_e = static_cast<int8_T>
    (rtb_LogicalOperator_e3);

  // End of Update for DiscreteIntegrator: '<S121>/Integrator'

  // Update for Delay: '<S42>/Delay1'
  for (k = 0; k < 39; k++) {
    FCS_model_DW.Delay1_DSTATE[k] = FCS_model_DW.Delay1_DSTATE[k + 1];
  }

  FCS_model_DW.Delay1_DSTATE[39] = rtb_r[1];

  // End of Update for Delay: '<S42>/Delay1'

  // Update for DiscreteFir: '<S130>/FIR_IMUaccel'
  // Update circular buffer index
  FCS_model_DW.FIR_IMUaccel_circBuf_b--;
  if (FCS_model_DW.FIR_IMUaccel_circBuf_b < 0) {
    FCS_model_DW.FIR_IMUaccel_circBuf_b = 4;
  }

  // Update circular buffer
  FCS_model_DW.FIR_IMUaccel_states_i[FCS_model_DW.FIR_IMUaccel_circBuf_b] =
    FIR_IMUaccel[0];
  FCS_model_DW.FIR_IMUaccel_states_i[FCS_model_DW.FIR_IMUaccel_circBuf_b + 5] =
    FIR_IMUaccel[1];
  FCS_model_DW.FIR_IMUaccel_states_i[FCS_model_DW.FIR_IMUaccel_circBuf_b + 10] =
    FIR_IMUaccel[2];

  // End of Update for DiscreteFir: '<S130>/FIR_IMUaccel'

  // Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/in_parameters'

  FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o +=
    FCS_model_P.DiscreteTimeIntegrator_gainva_i *
    arg_in_parameters->battery_current;

  // Update for DiscreteIntegrator: '<S34>/SimplyIntegrateVelocity'
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval * rtb_Product[0];

  // Update for DiscreteFilter: '<S3>/Discrete Filter2'
  FCS_model_DW.DiscreteFilter2_states[2] = FCS_model_DW.DiscreteFilter2_states[1];

  // Update for DiscreteIntegrator: '<S34>/SimplyIntegrateVelocity'
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval * rtb_Product[1];

  // Update for DiscreteFilter: '<S3>/Discrete Filter2'
  FCS_model_DW.DiscreteFilter2_states[1] = FCS_model_DW.DiscreteFilter2_states[0];
  FCS_model_DW.DiscreteFilter2_states[0] = DiscreteFilter2_tmp;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.0025, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  (&FCS_model_M)->Timing.clockTick0++;
}

// Model initialize function
void FCS_model::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  FCS_model_P.Integrator_UpperSat = rtInf;
  FCS_model_P.Integrator_LowerSat = rtMinusInf;
  FCS_model_P.Saturation_UpperSat = rtInf;
  FCS_model_P.Saturation_LowerSat = rtMinusInf;
  FCS_model_P.Integrator_UpperSat_i = rtInf;
  FCS_model_P.Integrator_LowerSat_l = rtMinusInf;
  FCS_model_P.Saturation_UpperSat_k = rtInf;
  FCS_model_P.Saturation_LowerSat_h = rtMinusInf;

  {
    int32_T i;

    // Start for Probe: '<S122>/Probe'
    FCS_model_B.Probe[0] = 0.0025;
    FCS_model_B.Probe[1] = 0.0;

    // Start for Probe: '<S115>/Probe'
    FCS_model_B.Probe_c[0] = 0.0025;
    FCS_model_B.Probe_c[1] = 0.0;

    // InitializeConditions for DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_states =
      FCS_model_P.DiscreteTransferFcn_InitialSt_b;
    for (i = 0; i < 15; i++) {
      // InitializeConditions for DiscreteFir: '<S3>/FIR_IMUaccel'
      FCS_model_DW.FIR_IMUaccel_states[i] =
        FCS_model_P.FIR_IMUaccel_InitialStates;

      // InitializeConditions for DiscreteFilter: '<S3>/IIR_IMUgyro_r'
      FCS_model_DW.IIR_IMUgyro_r_states[i] =
        FCS_model_P.IIR_IMUgyro_r_InitialStates;
    }

    // InitializeConditions for DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_states_a =
      FCS_model_P.DiscreteTransferFcn_InitialSt_e;

    // InitializeConditions for Merge: '<S190>/Merge1' incorporates:
    //   Memory: '<S32>/Memory'

    FCS_model_DW.Memory_PreviousInput = FCS_model_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S18>/Internal'
    FCS_model_DW.Internal_DSTATE[0] = FCS_model_P.Internal_InitialCondition;
    FCS_model_DW.Internal_DSTATE[1] = FCS_model_P.Internal_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S12>/Internal'
    FCS_model_DW.Internal_DSTATE_l[0] = FCS_model_P.Internal_InitialCondition_l;
    FCS_model_DW.Internal_DSTATE_l[1] = FCS_model_P.Internal_InitialCondition_l;

    // InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' 
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE =
      FCS_model_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' 
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_p =
      FCS_model_P.DiscreteTimeIntegrator_IC_f;

    // InitializeConditions for DiscreteStateSpace: '<S15>/Internal'
    FCS_model_DW.Internal_DSTATE_k[0] = FCS_model_P.Internal_InitialCondition_h;
    FCS_model_DW.Internal_DSTATE_k[1] = FCS_model_P.Internal_InitialCondition_h;

    // InitializeConditions for Delay: '<S41>/MemoryX'
    FCS_model_DW.icLoad = true;

    // InitializeConditions for DiscreteFilter: '<S40>/IIRgyroz'
    for (i = 0; i < 10; i++) {
      FCS_model_DW.IIRgyroz_states[i] = FCS_model_P.IIRgyroz_InitialStates;
    }

    // End of InitializeConditions for DiscreteFilter: '<S40>/IIRgyroz'

    // InitializeConditions for UnitDelay: '<S48>/UD'
    //
    //  Block description for '<S48>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[0] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for Delay: '<S35>/Delay'
    FCS_model_DW.Delay_DSTATE[0] = FCS_model_P.Delay_InitialCondition;

    // InitializeConditions for UnitDelay: '<S48>/UD'
    //
    //  Block description for '<S48>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[1] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for Delay: '<S35>/Delay'
    FCS_model_DW.Delay_DSTATE[1] = FCS_model_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S131>/MemoryX'
    FCS_model_DW.icLoad_m = true;

    // InitializeConditions for DiscreteIntegrator: '<S128>/Integrator'
    FCS_model_DW.Integrator_IC_LOADING = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S121>/Integrator'
    FCS_model_DW.Integrator_IC_LOADING_g = 1U;
    for (i = 0; i < 40; i++) {
      // InitializeConditions for Delay: '<S42>/Delay2'
      FCS_model_DW.Delay2_DSTATE[i] = FCS_model_P.Delay2_InitialCondition;

      // InitializeConditions for Delay: '<S42>/Delay1'
      FCS_model_DW.Delay1_DSTATE[i] = FCS_model_P.Delay1_InitialCondition;
    }

    // InitializeConditions for DiscreteFir: '<S130>/FIR_IMUaccel'
    for (i = 0; i < 15; i++) {
      FCS_model_DW.FIR_IMUaccel_states_i[i] =
        FCS_model_P.FIR_IMUaccel_InitialStates_b;
    }

    // End of InitializeConditions for DiscreteFir: '<S130>/FIR_IMUaccel'

    // InitializeConditions for DiscreteIntegrator: '<S34>/SimplyIntegrateVelocity' 
    FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0] =
      FCS_model_P.SimplyIntegrateVelocity_IC;
    FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1] =
      FCS_model_P.SimplyIntegrateVelocity_IC;

    // InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' 
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o =
      FCS_model_P.DiscreteTimeIntegrator_IC_p;

    // InitializeConditions for DiscreteFilter: '<S3>/Discrete Filter2'
    FCS_model_DW.DiscreteFilter2_states[0] =
      FCS_model_P.DiscreteFilter2_InitialStates;
    FCS_model_DW.DiscreteFilter2_states[1] =
      FCS_model_P.DiscreteFilter2_InitialStates;
    FCS_model_DW.DiscreteFilter2_states[2] =
      FCS_model_P.DiscreteFilter2_InitialStates;

    // SystemInitialize for IfAction SubSystem: '<S190>/If Action Subsystem'
    // InitializeConditions for DiscreteTransferFcn: '<S193>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_states_p =
      FCS_model_P.DiscreteTransferFcn_InitialStat;

    // End of SystemInitialize for SubSystem: '<S190>/If Action Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S159>/Enabled Subsystem'
    // SystemInitialize for Product: '<S184>/Product2' incorporates:
    //   Outport: '<S184>/deltax'

    FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;

    // End of SystemInitialize for SubSystem: '<S159>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S86>/Enabled Subsystem'
    // SystemInitialize for Product: '<S112>/Product2' incorporates:
    //   Outport: '<S112>/deltax'

    FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;

    // End of SystemInitialize for SubSystem: '<S86>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S79>/MeasurementUpdate'
    // SystemInitialize for Product: '<S110>/Product3' incorporates:
    //   Outport: '<S110>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;

    // End of SystemInitialize for SubSystem: '<S79>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S153>/MeasurementUpdate'
    // SystemInitialize for Product: '<S182>/Product3' incorporates:
    //   Outport: '<S182>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S153>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S159>/Enabled Subsystem'
    // SystemInitialize for Product: '<S184>/Product2' incorporates:
    //   Outport: '<S184>/deltax'

    FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;

    // End of SystemInitialize for SubSystem: '<S159>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S86>/Enabled Subsystem'
    // SystemInitialize for Product: '<S112>/Product2' incorporates:
    //   Outport: '<S112>/deltax'

    FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;

    // End of SystemInitialize for SubSystem: '<S86>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S79>/MeasurementUpdate'
    // SystemInitialize for Product: '<S110>/Product3' incorporates:
    //   Outport: '<S110>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;

    // End of SystemInitialize for SubSystem: '<S79>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S153>/MeasurementUpdate'
    // SystemInitialize for Product: '<S182>/Product3' incorporates:
    //   Outport: '<S182>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S153>/MeasurementUpdate'
  }
}

// Model terminate function
void FCS_model::terminate()
{
  // (no terminate code required)
}

const char_T* FCS_model::RT_MODEL_FCS_model_T::getErrorStatus() const
{
  return (errorStatus);
}

void FCS_model::RT_MODEL_FCS_model_T::setErrorStatus(const char_T* const
  volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
FCS_model::FCS_model() :
  FCS_model_B(),
  FCS_model_DW(),
  FCS_model_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
FCS_model::~FCS_model()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
FCS_model::RT_MODEL_FCS_model_T * FCS_model::getRTM()
{
  return (&FCS_model_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
