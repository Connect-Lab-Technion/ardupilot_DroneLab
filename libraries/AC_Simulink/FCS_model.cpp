//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 11.147
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Tue Nov 10 18:31:25 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FCS_model.h"
#include "rtwtypes.h"
#include "FCS_model_types.h"
#include "FCS_model_private.h"
#include <cmath>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "zero_crossing_types.h"
#include "rt_defines.h"

//
// Output and update for atomic system:
//    '<S109>/SqrtUsedFcn'
//    '<S181>/SqrtUsedFcn'
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
  real_T rtb_Switch2;
  real_T rtb_Switch1;
  real_T rtb_ref_yaw;
  real_T rtb_Sum1_di;
  real_T rtb_Sum1_a;
  real_T rtb_Converttometers;
  real_T rtb_MathFunction[9];
  real_T rtb_VectorConcatenate[9];
  real_T rtb_VectorConcatenate_k[9];
  real_T rtb_inverseIMU_gain[6];
  real_T rtb_Product1_i[4];
  real_T IIR_IMUgyro_r_tmp[3];
  real_T rtb_Add_k[3];
  real_T rtb_DiscreteTransferFcn[3];
  real_T rtb_Product[3];
  real_T rtb_Sum_k[3];
  real_T rtb_r[3];
  real_T rtb_sincos_o1[3];
  real_T rtb_sincos_o2[3];
  real_T rtb_sincos_o2_h[3];
  real_T IIRgyroz_tmp[2];
  real_T rtb_SimplyIntegrateVelocity[2];
  real_T rtb_TSamp[2];
  real_T tmp[2];
  real_T tmp_0[2];
  real_T tmp_1[2];
  real_T DiscreteTransferFcn_tmp_k;
  real_T IIR_IMUgyro_r_tmp_0;
  real_T rtb_AvoidDividebyZero;
  real_T rtb_DiscreteFilter2;
  real_T rtb_DiscreteTimeIntegrator_j;
  real_T rtb_Gain;
  real_T rtb_K_i;
  real_T rtb_Ki;
  real_T rtb_On1Off0forpitch;
  real_T rtb_On1Off0forroll;
  real_T rtb_On1Off0forthrust;
  real_T rtb_Product8;
  real_T rtb_Product_g_idx_0;
  real_T rtb_Product_g_idx_1;
  real_T rtb_Reshapey_idx_0;
  real_T rtb_Reshapey_idx_1;
  real_T rtb_Saturation;
  real_T rtb_Saturation_l;
  real_T rtb_Subtract;
  real_T rtb_Sum1;
  real_T rtb_TrigonometricFunction3;
  real_T rtb_inverseIMU_gain_0;
  real_T rtb_inverseIMU_gain_1;
  real_T rtb_inverseIMU_gain_2;
  real_T rtb_pitchrate;
  real_T tmp_2;
  real_T tmp_3;
  int32_T j;
  int32_T k;
  int32_T memOffset;
  boolean_T rtb_Compare_jy;
  boolean_T rtb_Compare_kg;
  boolean_T rtb_Compare_kk;
  boolean_T rtb_Compare_l;
  boolean_T rtb_Compare_lv;
  boolean_T rtb_LogicalOperator_g;

  // Gain: '<S3>/inverseIMU_gain' incorporates:
  //   Constant: '<S3>/Constant2'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S3>/Sum1'

  rtb_inverseIMU_gain[0] = (arg_in_parameters->accelerometer_x -
    FCS_model_P.Constant2_Value) * FCS_model_P.inverseIMU_gain_Gain[0];
  rtb_inverseIMU_gain[1] = (arg_in_parameters->accelerometer_y -
    FCS_model_P.Constant2_Value) * FCS_model_P.inverseIMU_gain_Gain[1];
  rtb_inverseIMU_gain[2] = (arg_in_parameters->accelerometer_z -
    FCS_model_P.Constant2_Value) * FCS_model_P.inverseIMU_gain_Gain[2];
  rtb_inverseIMU_gain[3] = (arg_in_parameters->gyroscope_x -
    FCS_model_P.Constant2_Value) * FCS_model_P.inverseIMU_gain_Gain[3];
  rtb_inverseIMU_gain[4] = (arg_in_parameters->gyroscope_y -
    FCS_model_P.Constant2_Value) * FCS_model_P.inverseIMU_gain_Gain[4];
  rtb_inverseIMU_gain[5] = (arg_in_parameters->gyroscope_z -
    FCS_model_P.Constant2_Value) * FCS_model_P.inverseIMU_gain_Gain[5];

  // Trigonometry: '<S191>/Trigonometric Function' incorporates:
  //   Gain: '<S191>/Gain2'
  //   Gain: '<S191>/Gain3'

  rtb_Product8 = rt_atan2d_snf(FCS_model_P.Gain2_Gain * rtb_inverseIMU_gain[1],
    FCS_model_P.Gain3_Gain * rtb_inverseIMU_gain[2]);

  // Gain: '<S190>/Gain'
  rtb_Gain = FCS_model_P.w_c_roll * rtb_Product8;

  // DiscreteFilter: '<S3>/IIR_IMUgyro_r'
  for (k = 0; k < 3; k++) {
    memOffset = k * 5;
    rtb_Sum1 = rtb_inverseIMU_gain[k + 3];
    for (j = 0; j < 5; j++) {
      rtb_Sum1 -= FCS_model_P.IIR_IMUgyro_r_DenCoef[j + 1] *
        FCS_model_DW.IIR_IMUgyro_r_states[memOffset + j];
    }

    IIR_IMUgyro_r_tmp_0 = rtb_Sum1 / FCS_model_P.IIR_IMUgyro_r_DenCoef[0];
    IIR_IMUgyro_r_tmp[k] = IIR_IMUgyro_r_tmp_0;
    rtb_AvoidDividebyZero = FCS_model_P.IIR_IMUgyro_r_NumCoef[0] *
      IIR_IMUgyro_r_tmp_0;
    for (j = 0; j < 5; j++) {
      rtb_AvoidDividebyZero += FCS_model_P.IIR_IMUgyro_r_NumCoef[j + 1] *
        FCS_model_DW.IIR_IMUgyro_r_states[memOffset + j];
    }

    rtb_r[k] = rtb_AvoidDividebyZero;
  }

  // End of DiscreteFilter: '<S3>/IIR_IMUgyro_r'

  // Trigonometry: '<S192>/Trigonometric Function2'
  IIR_IMUgyro_r_tmp_0 = std::cos(rtb_Product8);
  rtb_Product8 = std::sin(rtb_Product8);

  // Product: '<S191>/Divide' incorporates:
  //   Constant: '<S191>/Constant'
  //   Gain: '<S191>/Gain1'

  rtb_Sum1 = FCS_model_P.Gain1_Gain * rtb_inverseIMU_gain[0] / FCS_model_P.g;

  // Trigonometry: '<S191>/Trigonometric Function1'
  if (rtb_Sum1 > 1.0) {
    rtb_Sum1 = 1.0;
  } else if (rtb_Sum1 < -1.0) {
    rtb_Sum1 = -1.0;
  }

  // Gain: '<S191>/Gain' incorporates:
  //   Trigonometry: '<S191>/Trigonometric Function1'

  rtb_TrigonometricFunction3 = FCS_model_P.Gain_Gain * std::asin(rtb_Sum1);

  // Trigonometry: '<S192>/Trigonometric Function4'
  rtb_pitchrate = std::tan(rtb_TrigonometricFunction3);

  // Sum: '<S192>/Sum' incorporates:
  //   Product: '<S192>/Product'
  //   Product: '<S192>/Product1'
  //   Product: '<S192>/Product2'
  //   Product: '<S192>/Product3'
  //   Trigonometry: '<S192>/Trigonometric Function2'

  rtb_Subtract = (rtb_Product8 * rtb_pitchrate * rtb_r[1] + rtb_r[0]) +
    IIR_IMUgyro_r_tmp_0 * rtb_pitchrate * rtb_r[2];

  // DiscreteTransferFcn: '<S190>/Discrete Transfer Fcn' incorporates:
  //   Delay: '<S190>/Delay One Step'
  //   Memory: '<S190>/Memory'
  //   Sum: '<S190>/Sum'

  if ((((FCS_model_PrevZCX.DiscreteTransferFcn_Reset_ZCE == POS_ZCSIG) !=
        FCS_model_DW.DelayOneStep_DSTATE_f) &&
       (FCS_model_PrevZCX.DiscreteTransferFcn_Reset_ZCE != UNINITIALIZED_ZCSIG))
      || FCS_model_DW.DelayOneStep_DSTATE_f) {
    FCS_model_DW.DiscreteTransferFcn_icLoad = 1U;
  }

  FCS_model_PrevZCX.DiscreteTransferFcn_Reset_ZCE =
    FCS_model_DW.DelayOneStep_DSTATE_f;
  if (FCS_model_DW.DiscreteTransferFcn_icLoad != 0) {
    FCS_model_DW.DiscreteTransferFcn_states = FCS_model_DW.Memory_PreviousInput;
    FCS_model_DW.DiscreteTransferFcn_icLoad = 0U;
  }

  rtb_Gain = ((rtb_Gain + rtb_Subtract) -
              FCS_model_P.DiscreteTransferFcn_DenCoef_p[1] *
              FCS_model_DW.DiscreteTransferFcn_states) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_p[0];
  rtb_AvoidDividebyZero = FCS_model_P.DiscreteTransferFcn_NumCoef_f[0] *
    rtb_Gain + FCS_model_P.DiscreteTransferFcn_NumCoef_f[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // MATLAB Function: '<S190>/MATLAB Function' incorporates:
  //   Delay: '<S190>/Delay One Step'
  //   DiscreteTransferFcn: '<S190>/Discrete Transfer Fcn'

  if (std::abs(rtb_AvoidDividebyZero) <= 3.1415926535897931) {
    FCS_model_DW.Memory_PreviousInput = rtb_AvoidDividebyZero;
    FCS_model_DW.DelayOneStep_DSTATE_f = false;
  } else {
    FCS_model_DW.DelayOneStep_DSTATE_f = true;
  }

  // End of MATLAB Function: '<S190>/MATLAB Function'

  // Sum: '<S192>/Sum1' incorporates:
  //   Gain: '<S192>/Gain'
  //   Product: '<S192>/Product4'
  //   Product: '<S192>/Product5'
  //   Trigonometry: '<S192>/Trigonometric Function2'

  rtb_pitchrate = FCS_model_P.Gain_Gain_p * rtb_Product8 * rtb_r[2] +
    IIR_IMUgyro_r_tmp_0 * rtb_r[1];

  // DiscreteTransferFcn: '<S189>/Discrete Transfer Fcn' incorporates:
  //   Gain: '<S189>/Gain'
  //   Sum: '<S189>/Sum'

  DiscreteTransferFcn_tmp_k = ((FCS_model_P.w_c_pitch *
    rtb_TrigonometricFunction3 + rtb_pitchrate) -
    FCS_model_P.DiscreteTransferFcn_DenCoef_b[1] *
    FCS_model_DW.DiscreteTransferFcn_states_a) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_b[0];
  rtb_AvoidDividebyZero = FCS_model_P.DiscreteTransferFcn_NumCoef_o[0] *
    DiscreteTransferFcn_tmp_k + FCS_model_P.DiscreteTransferFcn_NumCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states_a;

  // If: '<S193>/If1' incorporates:
  //   Constant: '<S33>/Constant'
  //   DataTypeConversion: '<S193>/Data Type Conversion'

  if (static_cast<real32_T>(FCS_model_P.Constant_Value_c) > 0.0F) {
    // Outputs for IfAction SubSystem: '<S193>/If Action Subsystem' incorporates:
    //   ActionPort: '<S196>/Action Port'

    // Merge: '<S193>/Merge1' incorporates:
    //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'

    FCS_model_DW.Memory_PreviousInput_g =
      FCS_model_P.DiscreteTransferFcn_NumCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_p;

    // Update for DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S197>/Gain'
    //   Inport: '<Root>/in_parameters'
    //   Sum: '<S197>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_p = ((FCS_model_P.w_c_yaw *
      arg_in_parameters->yaw + rtb_r[2]) -
      FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_p) /
      FCS_model_P.DiscreteTransferFcn_DenCoef[0];

    // End of Outputs for SubSystem: '<S193>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S193>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S195>/Action Port'

    // Merge: '<S193>/Merge1' incorporates:
    //   Gain: '<S195>/Gain'
    //   Memory: '<S33>/Memory'
    //   Sum: '<S195>/Sum'

    FCS_model_DW.Memory_PreviousInput_g += FCS_model_P.Ts * rtb_r[2];

    // End of Outputs for SubSystem: '<S193>/If Action Subsystem3'
  }

  // End of If: '<S193>/If1'

  // SignalConversion generated from: '<S38>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S189>/Discrete Transfer Fcn'

  rtb_sincos_o1[0] = FCS_model_DW.Memory_PreviousInput_g;
  rtb_sincos_o1[1] = rtb_AvoidDividebyZero;
  rtb_sincos_o1[2] = FCS_model_DW.Memory_PreviousInput;

  // Trigonometry: '<S134>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S189>/Discrete Transfer Fcn'
  //   SignalConversion generated from: '<S38>/sincos'

  rtb_DiscreteTransferFcn[0] = std::sin(FCS_model_DW.Memory_PreviousInput_g);
  rtb_sincos_o2[0] = std::cos(FCS_model_DW.Memory_PreviousInput_g);
  rtb_DiscreteTransferFcn[1] = std::sin(rtb_AvoidDividebyZero);
  rtb_sincos_o2[1] = std::cos(rtb_AvoidDividebyZero);
  rtb_DiscreteTransferFcn[2] = std::sin(FCS_model_DW.Memory_PreviousInput);
  rtb_sincos_o2[2] = std::cos(FCS_model_DW.Memory_PreviousInput);

  // Fcn: '<S134>/Fcn11'
  rtb_VectorConcatenate[0] = rtb_sincos_o2[0] * rtb_sincos_o2[1];

  // Fcn: '<S134>/Fcn21' incorporates:
  //   Fcn: '<S134>/Fcn22'

  rtb_On1Off0forthrust = rtb_DiscreteTransferFcn[1] * rtb_DiscreteTransferFcn[2];
  rtb_VectorConcatenate[1] = rtb_On1Off0forthrust * rtb_sincos_o2[0] -
    rtb_DiscreteTransferFcn[0] * rtb_sincos_o2[2];

  // Fcn: '<S134>/Fcn31' incorporates:
  //   Fcn: '<S134>/Fcn32'

  rtb_Ki = rtb_DiscreteTransferFcn[1] * rtb_sincos_o2[2];
  rtb_VectorConcatenate[2] = rtb_Ki * rtb_sincos_o2[0] +
    rtb_DiscreteTransferFcn[0] * rtb_DiscreteTransferFcn[2];

  // Fcn: '<S134>/Fcn12'
  rtb_VectorConcatenate[3] = rtb_DiscreteTransferFcn[0] * rtb_sincos_o2[1];

  // Fcn: '<S134>/Fcn22'
  rtb_VectorConcatenate[4] = rtb_On1Off0forthrust * rtb_DiscreteTransferFcn[0] +
    rtb_sincos_o2[0] * rtb_sincos_o2[2];

  // Fcn: '<S134>/Fcn32'
  rtb_VectorConcatenate[5] = rtb_Ki * rtb_DiscreteTransferFcn[0] -
    rtb_sincos_o2[0] * rtb_DiscreteTransferFcn[2];

  // Fcn: '<S134>/Fcn13'
  rtb_VectorConcatenate[6] = -rtb_DiscreteTransferFcn[1];

  // Fcn: '<S134>/Fcn23'
  rtb_VectorConcatenate[7] = rtb_sincos_o2[1] * rtb_DiscreteTransferFcn[2];

  // Fcn: '<S134>/Fcn33'
  rtb_VectorConcatenate[8] = rtb_sincos_o2[1] * rtb_sincos_o2[2];
  for (k = 0; k < 3; k++) {
    // Math: '<S131>/Math Function' incorporates:
    //   Concatenate: '<S188>/Vector Concatenate'

    rtb_MathFunction[3 * k] = rtb_VectorConcatenate[k];
    rtb_MathFunction[3 * k + 1] = rtb_VectorConcatenate[k + 3];
    rtb_MathFunction[3 * k + 2] = rtb_VectorConcatenate[k + 6];

    // Trigonometry: '<S38>/sincos'
    rtb_Product_g_idx_0 = rtb_sincos_o1[k];
    rtb_DiscreteTransferFcn[k] = std::sin(rtb_Product_g_idx_0);
    rtb_sincos_o2_h[k] = std::cos(rtb_Product_g_idx_0);
  }

  // Fcn: '<S38>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_sincos_o2_h[0] * rtb_sincos_o2_h[1];

  // Fcn: '<S38>/Fcn21' incorporates:
  //   Fcn: '<S38>/Fcn22'

  rtb_Product_g_idx_0 = rtb_DiscreteTransferFcn[1] * rtb_DiscreteTransferFcn[2];
  rtb_VectorConcatenate_k[1] = rtb_Product_g_idx_0 * rtb_sincos_o2_h[0] -
    rtb_DiscreteTransferFcn[0] * rtb_sincos_o2_h[2];

  // Fcn: '<S38>/Fcn31' incorporates:
  //   Fcn: '<S38>/Fcn32'

  rtb_Product_g_idx_1 = rtb_DiscreteTransferFcn[1] * rtb_sincos_o2_h[2];
  rtb_VectorConcatenate_k[2] = rtb_Product_g_idx_1 * rtb_sincos_o2_h[0] +
    rtb_DiscreteTransferFcn[0] * rtb_DiscreteTransferFcn[2];

  // Fcn: '<S38>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_DiscreteTransferFcn[0] * rtb_sincos_o2_h[1];

  // Fcn: '<S38>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_Product_g_idx_0 * rtb_DiscreteTransferFcn[0]
    + rtb_sincos_o2_h[0] * rtb_sincos_o2_h[2];

  // Fcn: '<S38>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_Product_g_idx_1 * rtb_DiscreteTransferFcn[0]
    - rtb_sincos_o2_h[0] * rtb_DiscreteTransferFcn[2];

  // Fcn: '<S38>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_DiscreteTransferFcn[1];

  // Fcn: '<S38>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_sincos_o2_h[1] * rtb_DiscreteTransferFcn[2];

  // Fcn: '<S38>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_sincos_o2_h[1] * rtb_sincos_o2_h[2];

  // Gain: '<S1>/On=1//Off=0 for thrust' incorporates:
  //   Constant: '<S21>/g-feedforward'
  //   Gain: '<S21>/Gain'

  rtb_On1Off0forthrust = -FCS_model_P.Veh.Af.mass * FCS_model_P.Env.g *
    FCS_model_P.Gain_Gain_j * FCS_model_P.On1Off0forthrust_Gain;

  // Logic: '<S4>/AND' incorporates:
  //   Constant: '<S8>/Constant'
  //   Inport: '<Root>/in_dashboard'
  //   RelationalOperator: '<S8>/Compare'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  rtb_Compare_jy = (arg_in_dashboard->master_switch && (arg_in_dashboard->ref_z <
    FCS_model_P.CompareToConstant_const));

  // Logic: '<S10>/NOT' incorporates:
  //   Logic: '<S9>/NOT'

  rtb_Compare_l = !rtb_Compare_jy;

  // DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
  //   Logic: '<S10>/NOT'

  if (rtb_Compare_l) {
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE =
      FCS_model_P.DiscreteTimeIntegrator_IC;
  }

  // DiscreteStateSpace: '<S15>/Internal'
  {
    rtb_Sum1_di = (FCS_model_P.Internal_C[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_C[1])*FCS_model_DW.Internal_DSTATE[1];
  }

  // Sum: '<S10>/Sum1'
  rtb_Sum1_di -= FCS_model_DW.Memory_PreviousInput;

  // DiscreteTransferFcn: '<S33>/Discrete Transfer Fcn'
  rtb_DiscreteTransferFcn[0] = FCS_model_DW.DiscreteTransferFcn_states_l[0] *
    FCS_model_P.DiscreteTransferFcn_NumCoef_c[1];
  rtb_DiscreteTransferFcn[1] = FCS_model_P.DiscreteTransferFcn_NumCoef_c[1] *
    FCS_model_DW.DiscreteTransferFcn_states_l[1];
  rtb_Ki = FCS_model_P.DiscreteTransferFcn_NumCoef_c[1] *
    FCS_model_DW.DiscreteTransferFcn_states_l[2];

  // Sum: '<S9>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
  //   Gain: '<S10>/kd_rol'
  //   Gain: '<S10>/kp_rol'
  //   Sum: '<S10>/Sum'
  //   Sum: '<S10>/Sum3'

  rtb_Sum1_a = FCS_model_P.kd_rol * rtb_DiscreteTransferFcn[0];
  rtb_Sum1_a = (FCS_model_P.kp_rol * rtb_Sum1_di +
                FCS_model_DW.DiscreteTimeIntegrator_DSTATE) - rtb_Sum1_a;

  // Saturate: '<S10>/Saturation'
  if (rtb_Sum1_a > FCS_model_P.Veh.Cont.MaxTau) {
    // Sum: '<S9>/Sum1'
    rtb_Sum1_a = FCS_model_P.Veh.Cont.MaxTau;
  } else if (rtb_Sum1_a < -FCS_model_P.Veh.Cont.MaxTau) {
    // Sum: '<S9>/Sum1'
    rtb_Sum1_a = -FCS_model_P.Veh.Cont.MaxTau;
  }

  // End of Saturate: '<S10>/Saturation'

  // Sum: '<S9>/Sum1' incorporates:
  //   Constant: '<S4>/roll equilibrium'
  //   Gain: '<S4>/Changing of Jxx'
  //   Sum: '<S4>/Sum2'

  rtb_Sum1_a = FCS_model_P.ChangingofJxx_Gain * rtb_Sum1_a +
    FCS_model_P.rollequilibrium_Value;

  // Gain: '<S1>/On=-1//Off=0 for roll' incorporates:
  //   Product: '<S4>/Product'

  rtb_On1Off0forroll = rtb_Sum1_a * static_cast<real_T>(rtb_Compare_jy) *
    FCS_model_P.On1Off0forroll_Gain;

  // DiscreteStateSpace: '<S12>/Internal'
  {
    rtb_Sum1_a = (FCS_model_P.Internal_C_n[0])*FCS_model_DW.Internal_DSTATE_l[0]
      + (FCS_model_P.Internal_C_n[1])*FCS_model_DW.Internal_DSTATE_l[1];
  }

  // Sum: '<S9>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S189>/Discrete Transfer Fcn'

  rtb_Sum1_a -= rtb_AvoidDividebyZero;

  // DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  if (rtb_Compare_l) {
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_e =
      FCS_model_P.DiscreteTimeIntegrator_IC_k;
  }

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Constant: '<S9>/imbalance feed forward'
  //   DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  //   Gain: '<S9>/Kd'
  //   Gain: '<S9>/Kp'
  //   Sum: '<S9>/Sum'
  //   Sum: '<S9>/Sum2'
  //   Sum: '<S9>/Sum3'

  rtb_Converttometers = FCS_model_P.kd_pit * rtb_DiscreteTransferFcn[1];
  rtb_Converttometers = ((FCS_model_P.kp_pit * rtb_Sum1_a +
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_e) - rtb_Converttometers) +
    FCS_model_P.imbalancefeedforward_Value;

  // Saturate: '<S9>/Saturation'
  if (rtb_Converttometers > FCS_model_P.Veh.Cont.MaxTau) {
    // Gain: '<S3>/Convert to meters'
    rtb_Converttometers = FCS_model_P.Veh.Cont.MaxTau;
  } else if (rtb_Converttometers < -FCS_model_P.Veh.Cont.MaxTau) {
    // Gain: '<S3>/Convert to meters'
    rtb_Converttometers = -FCS_model_P.Veh.Cont.MaxTau;
  }

  // End of Saturate: '<S9>/Saturation'

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Constant: '<S4>/pitch equilibrium'
  //   Gain: '<S4>/Changing of Jyy'
  //   Sum: '<S4>/Sum1'

  rtb_Converttometers = FCS_model_P.ChangingofJyy_Gain * rtb_Converttometers +
    FCS_model_P.pitchequilibrium_Value;

  // Gain: '<S1>/On=-1//Off=0 for pitch' incorporates:
  //   Product: '<S4>/Product1'

  rtb_On1Off0forpitch = rtb_Converttometers * static_cast<real_T>(rtb_Compare_jy)
    * FCS_model_P.On1Off0forpitch_Gain;

  // DiscreteStateSpace: '<S18>/Internal'
  {
    rtb_Converttometers = (FCS_model_P.Internal_C_j[0])*
      FCS_model_DW.Internal_DSTATE_f[0]
      + (FCS_model_P.Internal_C_j[1])*FCS_model_DW.Internal_DSTATE_f[1];
  }

  // Sum: '<S11>/Sum1'
  rtb_Sum1 = rtb_Converttometers - FCS_model_DW.Memory_PreviousInput_g;

  // Gain: '<S3>/Convert to meters' incorporates:
  //   DiscreteTransferFcn: '<S33>/Discrete Transfer Fcn'
  //   Gain: '<S11>/Kd'
  //   Gain: '<S11>/Kp'
  //   Sum: '<S11>/Sum3'

  rtb_Converttometers = FCS_model_P.kd_yaw * rtb_Ki;
  rtb_Converttometers = FCS_model_P.kp_yaw * rtb_Sum1 - rtb_Converttometers;

  // Saturate: '<S11>/Saturation'
  if (rtb_Converttometers > FCS_model_P.Saturation_UpperSat) {
    // Gain: '<S3>/Convert to meters'
    rtb_Converttometers = FCS_model_P.Saturation_UpperSat;
  } else if (rtb_Converttometers < FCS_model_P.Saturation_LowerSat) {
    // Gain: '<S3>/Convert to meters'
    rtb_Converttometers = FCS_model_P.Saturation_LowerSat;
  }

  // End of Saturate: '<S11>/Saturation'

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Constant: '<S4>/yaw equilibrium'
  //   Gain: '<S4>/Changing of Jzz'
  //   Sum: '<S4>/Sum3'

  rtb_Converttometers = FCS_model_P.ChangingofJzz_Gain * rtb_Converttometers +
    FCS_model_P.yawequilibrium_Value;

  // Gain: '<S1>/On=-1//Off=0 for yaw' incorporates:
  //   Product: '<S4>/Product2'

  rtb_DiscreteFilter2 = static_cast<real_T>(rtb_Compare_jy) *
    rtb_Converttometers * FCS_model_P.On1Off0foryaw_Gain;

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  rtb_Converttometers = arg_in_dashboard->power;
  for (k = 0; k < 4; k++) {
    // Saturate: '<S29>/Saturation' incorporates:
    //   Constant: '<S28>/TorqueTotalThrustToThrustPerMotor'
    //   Gain: '<S30>/thrustToMotor'
    //   Product: '<S28>/Product'
    //   Product: '<S29>/Product'
    //   SignalConversion generated from: '<S28>/Product'

    rtb_Sum1 = (((FCS_model_P.TorqueTotalThrustToThrustPerMot[k + 4] *
                  rtb_On1Off0forroll +
                  FCS_model_P.TorqueTotalThrustToThrustPerMot[k] *
                  rtb_On1Off0forthrust) +
                 FCS_model_P.TorqueTotalThrustToThrustPerMot[k + 8] *
                 rtb_On1Off0forpitch) +
                FCS_model_P.TorqueTotalThrustToThrustPerMot[k + 12] *
                rtb_DiscreteFilter2) *
      -FCS_model_P.Vehicle.Motor.thrustToMotorCommand * rtb_Converttometers;
    if (rtb_Sum1 > FCS_model_P.Vehicle.Motor.maxLimit) {
      rtb_Sum1 = FCS_model_P.Vehicle.Motor.maxLimit;
    } else if (rtb_Sum1 < FCS_model_P.Vehicle.Motor.minLimit) {
      rtb_Sum1 = FCS_model_P.Vehicle.Motor.minLimit;
    }

    // Product: '<S29>/Product1' incorporates:
    //   Gain: '<S30>/thrustToMotor'
    //   Inport: '<Root>/in_dashboard'
    //   Saturate: '<S29>/Saturation'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Product1_i[k] = rtb_Sum1 * static_cast<real_T>
      (arg_in_dashboard->master_switch);
  }

  // Delay: '<S42>/MemoryX' incorporates:
  //   Constant: '<S42>/X0'

  if (FCS_model_DW.icLoad) {
    FCS_model_DW.MemoryX_DSTATE[0] = FCS_model_P.X0_Value[0];
    FCS_model_DW.MemoryX_DSTATE[1] = FCS_model_P.X0_Value[1];
  }

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs2'
  //   DiscreteTransferFcn: '<S189>/Discrete Transfer Fcn'

  rtb_Converttometers = std::abs(rtb_AvoidDividebyZero);

  // RelationalOperator: '<S52>/Compare' incorporates:
  //   Constant: '<S52>/Constant'

  rtb_Compare_l = (rtb_Converttometers <= FCS_model_P.maxp_const);

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs3'

  rtb_Converttometers = std::abs(FCS_model_DW.Memory_PreviousInput);

  // RelationalOperator: '<S54>/Compare' incorporates:
  //   Constant: '<S54>/Constant'

  rtb_Compare_jy = (rtb_Converttometers <= FCS_model_P.maxq_const);

  // Abs: '<S41>/Abs' incorporates:
  //   Abs: '<S41>/Abs4'

  rtb_DiscreteTimeIntegrator_j = std::abs(rtb_r[0]);

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs'

  rtb_Converttometers = rtb_DiscreteTimeIntegrator_j;

  // RelationalOperator: '<S56>/Compare' incorporates:
  //   Constant: '<S56>/Constant'

  rtb_Compare_lv = (rtb_Converttometers <= FCS_model_P.maxw1_const);

  // Abs: '<S41>/Abs1' incorporates:
  //   Abs: '<S41>/Abs5'

  rtb_Saturation = std::abs(rtb_r[1]);

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs1'

  rtb_Converttometers = rtb_Saturation;

  // RelationalOperator: '<S57>/Compare' incorporates:
  //   Constant: '<S57>/Constant'

  rtb_Compare_kk = (rtb_Converttometers <= FCS_model_P.maxw2_const);
  for (k = 0; k < 2; k++) {
    // DiscreteFilter: '<S41>/IIRgyroz'
    memOffset = k * 5;
    rtb_Sum1 = rtb_r[k];
    for (j = 0; j < 5; j++) {
      rtb_Sum1 -= FCS_model_P.IIRgyroz_DenCoef[j + 1] *
        FCS_model_DW.IIRgyroz_states[memOffset + j];
    }

    rtb_Sum1 /= FCS_model_P.IIRgyroz_DenCoef[0];
    IIRgyroz_tmp[k] = rtb_Sum1;
    rtb_Sum1 *= FCS_model_P.IIRgyroz_NumCoef[0];
    for (j = 0; j < 5; j++) {
      rtb_Sum1 += FCS_model_P.IIRgyroz_NumCoef[j + 1] *
        FCS_model_DW.IIRgyroz_states[memOffset + j];
    }

    // SampleTimeMath: '<S49>/TSamp' incorporates:
    //   DiscreteFilter: '<S41>/IIRgyroz'
    //
    //  About '<S49>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_Sum1 *= FCS_model_P.TSamp_WtEt;
    rtb_TSamp[k] = rtb_Sum1;

    // Sum: '<S49>/Diff' incorporates:
    //   UnitDelay: '<S49>/UD'
    //
    //  Block description for '<S49>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S49>/UD':
    //
    //   Store in Global RAM

    rtb_SimplyIntegrateVelocity[k] = rtb_Sum1 - FCS_model_DW.UD_DSTATE[k];
  }

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs6'

  rtb_Converttometers = std::abs(rtb_SimplyIntegrateVelocity[0]);

  // RelationalOperator: '<S50>/Compare' incorporates:
  //   Constant: '<S50>/Constant'

  rtb_Compare_kg = (rtb_Converttometers <= FCS_model_P.maxdw1_const);

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs7'

  rtb_Converttometers = std::abs(rtb_SimplyIntegrateVelocity[1]);

  // Logic: '<S41>/Logical Operator' incorporates:
  //   Constant: '<S51>/Constant'
  //   RelationalOperator: '<S51>/Compare'

  rtb_Compare_jy = (rtb_Compare_l && rtb_Compare_jy && rtb_Compare_lv &&
                    rtb_Compare_kk && rtb_Compare_kg && (rtb_Converttometers <=
    FCS_model_P.maxdw2_const));

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs4'

  rtb_Converttometers = rtb_DiscreteTimeIntegrator_j;

  // RelationalOperator: '<S53>/Compare' incorporates:
  //   Constant: '<S53>/Constant'

  rtb_Compare_l = (rtb_Converttometers <= FCS_model_P.maxp2_const);

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs5'

  rtb_Converttometers = rtb_Saturation;

  // Logic: '<S41>/Logical Operator1' incorporates:
  //   Constant: '<S55>/Constant'
  //   RelationalOperator: '<S55>/Compare'

  rtb_Compare_lv = (rtb_Compare_l && (rtb_Converttometers <=
    FCS_model_P.maxq2_const));

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs8'
  //   Delay: '<S36>/Delay'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S41>/Add'

  rtb_Converttometers = std::abs(arg_in_parameters->opticalflow_x -
    FCS_model_DW.Delay_DSTATE[0]);

  // RelationalOperator: '<S58>/Compare' incorporates:
  //   Constant: '<S58>/Constant'

  rtb_Compare_kk = (rtb_Converttometers <= FCS_model_P.maxw3_const);

  // Gain: '<S3>/Convert to meters' incorporates:
  //   Abs: '<S41>/Abs9'
  //   Delay: '<S36>/Delay'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S41>/Add'

  rtb_Converttometers = std::abs(arg_in_parameters->opticalflow_y -
    FCS_model_DW.Delay_DSTATE[1]);

  // RelationalOperator: '<S59>/Compare' incorporates:
  //   Constant: '<S59>/Constant'

  rtb_Compare_kg = (rtb_Converttometers <= FCS_model_P.maxw4_const);

  // Delay: '<S132>/MemoryX' incorporates:
  //   Constant: '<S132>/X0'

  if (FCS_model_DW.icLoad_m) {
    FCS_model_DW.MemoryX_DSTATE_f[0] = FCS_model_P.X0_Value_n[0];
    FCS_model_DW.MemoryX_DSTATE_f[1] = FCS_model_P.X0_Value_n[1];
  }

  // DiscreteFilter: '<S3>/Discrete Filter1' incorporates:
  //   Constant: '<S3>/Constant2'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S3>/Sum3'

  rtb_Sum1 = ((((arg_in_parameters->rangefinder_distance -
                 FCS_model_P.Constant2_Value) -
                FCS_model_DW.DiscreteFilter1_states[0] *
                FCS_model_P.DiscreteFilter1_DenCoef[1]) -
               FCS_model_DW.DiscreteFilter1_states[1] *
               FCS_model_P.DiscreteFilter1_DenCoef[2]) -
              FCS_model_DW.DiscreteFilter1_states[2] *
              FCS_model_P.DiscreteFilter1_DenCoef[3]) /
    FCS_model_P.DiscreteFilter1_DenCoef[0];

  // Gain: '<S3>/Convert to meters' incorporates:
  //   DiscreteFilter: '<S3>/Discrete Filter1'

  rtb_Converttometers = ((FCS_model_P.DiscreteFilter1_NumCoef[0] * rtb_Sum1 +
    FCS_model_DW.DiscreteFilter1_states[0] *
    FCS_model_P.DiscreteFilter1_NumCoef[1]) +
    FCS_model_DW.DiscreteFilter1_states[1] *
    FCS_model_P.DiscreteFilter1_NumCoef[2]) +
    FCS_model_DW.DiscreteFilter1_states[2] *
    FCS_model_P.DiscreteFilter1_NumCoef[3];
  rtb_Converttometers *= FCS_model_P.Converttometers_Gain;

  // SignalConversion generated from: '<S131>/Product2' incorporates:
  //   Constant: '<S131>/Constant'

  rtb_Product_g_idx_1 = FCS_model_P.Constant_Value_h[0];
  tmp_3 = FCS_model_P.Constant_Value_h[1];

  // Product: '<S131>/Product2' incorporates:
  //   Math: '<S131>/Math Function'
  //   SignalConversion generated from: '<S131>/Product2'

  for (k = 0; k < 3; k++) {
    rtb_sincos_o2[k] = (rtb_MathFunction[k + 3] * tmp_3 + rtb_MathFunction[k] *
                        rtb_Product_g_idx_1) + rtb_MathFunction[k + 6] *
      rtb_Converttometers;
  }

  // End of Product: '<S131>/Product2'

  // RelationalOperator: '<S187>/Compare' incorporates:
  //   Abs: '<S133>/Abs'
  //   Constant: '<S187>/Constant'
  //   Delay: '<S131>/Delay One Step'
  //   Sum: '<S133>/Minus'

  rtb_Compare_l = (std::abs(FCS_model_DW.DelayOneStep_DSTATE - rtb_sincos_o2[2])
                   <= FCS_model_P.rangefinderOutlier_const);

  // Outputs for Enabled SubSystem: '<S160>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S185>/Enable'

  if (rtb_Compare_l) {
    FCS_model_DW.EnabledSubsystem_MODE = true;

    // Sum: '<S185>/Add1' incorporates:
    //   Constant: '<S132>/C'
    //   Delay: '<S132>/MemoryX'
    //   Product: '<S185>/Product'

    rtb_DiscreteTimeIntegrator_j = rtb_sincos_o2[2] - (FCS_model_P.C_Value_f[0] *
      FCS_model_DW.MemoryX_DSTATE_f[0] + FCS_model_P.C_Value_f[1] *
      FCS_model_DW.MemoryX_DSTATE_f[1]);

    // Product: '<S185>/Product2' incorporates:
    //   Constant: '<S135>/KalmanGainM'

    FCS_model_B.Product2[0] = FCS_model_P.KalmanGainM_Value_b[0] *
      rtb_DiscreteTimeIntegrator_j;
    FCS_model_B.Product2[1] = FCS_model_P.KalmanGainM_Value_b[1] *
      rtb_DiscreteTimeIntegrator_j;
  } else if (FCS_model_DW.EnabledSubsystem_MODE) {
    // Disable for Product: '<S185>/Product2' incorporates:
    //   Outport: '<S185>/deltax'

    FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;
    FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;
    FCS_model_DW.EnabledSubsystem_MODE = false;
  }

  // End of Outputs for SubSystem: '<S160>/Enabled Subsystem'

  // Sum: '<S160>/Add' incorporates:
  //   Delay: '<S132>/MemoryX'

  rtb_SimplyIntegrateVelocity[0] = FCS_model_B.Product2[0] +
    FCS_model_DW.MemoryX_DSTATE_f[0];

  // Logic: '<S41>/Logical Operator3' incorporates:
  //   Constant: '<S60>/Constant'
  //   Logic: '<S41>/Logical Operator2'
  //   RelationalOperator: '<S60>/Compare'

  rtb_Compare_kg = ((rtb_Compare_jy || rtb_Compare_lv) && rtb_Compare_kk &&
                    rtb_Compare_kg && (rtb_SimplyIntegrateVelocity[0] <=
    FCS_model_P.minHeightforOF_const));

  // Logic: '<S123>/Logical Operator' incorporates:
  //   Constant: '<S123>/Constant'
  //   Constant: '<S123>/Time constant'
  //   Constant: '<S126>/Constant'
  //   Constant: '<S127>/Constant'
  //   RelationalOperator: '<S126>/Compare'
  //   RelationalOperator: '<S127>/Compare'
  //   Sum: '<S123>/Sum1'

  rtb_Compare_lv = ((FCS_model_P.LowPassFilterDiscreteorContin_l -
                     FCS_model_B.Probe[0] <= FCS_model_P.Constant_Value_o) &&
                    (FCS_model_P.LowPassFilterDiscreteorContin_i <
                     FCS_model_P.CompareToConstant_const_m));

  // Gain: '<S115>/K' incorporates:
  //   Inport: '<Root>/in_parameters'

  rtb_DiscreteTimeIntegrator_j = FCS_model_P.LowPassFilterDiscreteorContinuo *
    arg_in_parameters->opticalflow_x;

  // DiscreteIntegrator: '<S129>/Integrator'
  if (FCS_model_DW.Integrator_IC_LOADING != 0) {
    FCS_model_DW.Integrator_DSTATE = rtb_DiscreteTimeIntegrator_j;
    if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  if (rtb_Compare_lv || (FCS_model_DW.Integrator_PrevResetState != 0)) {
    FCS_model_DW.Integrator_DSTATE = rtb_DiscreteTimeIntegrator_j;
    if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  // End of DiscreteIntegrator: '<S129>/Integrator'

  // Saturate: '<S129>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Saturation_UpperSat_k) {
    rtb_Saturation = FCS_model_P.Saturation_UpperSat_k;
  } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Saturation_LowerSat_m)
  {
    rtb_Saturation = FCS_model_P.Saturation_LowerSat_m;
  } else {
    rtb_Saturation = FCS_model_DW.Integrator_DSTATE;
  }

  // End of Saturate: '<S129>/Saturation'

  // Logic: '<S116>/Logical Operator' incorporates:
  //   Constant: '<S116>/Constant'
  //   Constant: '<S116>/Time constant'
  //   Constant: '<S119>/Constant'
  //   Constant: '<S120>/Constant'
  //   RelationalOperator: '<S119>/Compare'
  //   RelationalOperator: '<S120>/Compare'
  //   Sum: '<S116>/Sum1'

  rtb_Compare_kk = ((FCS_model_P.LowPassFilterDiscreteorContin_a -
                     FCS_model_B.Probe_c[0] <= FCS_model_P.Constant_Value) &&
                    (FCS_model_P.LowPassFilterDiscreteorConti_d0 <
                     FCS_model_P.CompareToConstant_const_p));

  // Gain: '<S114>/K' incorporates:
  //   Inport: '<Root>/in_parameters'

  rtb_K_i = FCS_model_P.LowPassFilterDiscreteorContin_d *
    arg_in_parameters->opticalflow_y;

  // DiscreteIntegrator: '<S122>/Integrator'
  if (FCS_model_DW.Integrator_IC_LOADING_g != 0) {
    FCS_model_DW.Integrator_DSTATE_e = rtb_K_i;
    if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Integrator_UpperSat_i) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
    } else if (FCS_model_DW.Integrator_DSTATE_e <
               FCS_model_P.Integrator_LowerSat_l) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
    }
  }

  if (rtb_Compare_kk || (FCS_model_DW.Integrator_PrevResetState_e != 0)) {
    FCS_model_DW.Integrator_DSTATE_e = rtb_K_i;
    if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Integrator_UpperSat_i) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
    } else if (FCS_model_DW.Integrator_DSTATE_e <
               FCS_model_P.Integrator_LowerSat_l) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
    }
  }

  // End of DiscreteIntegrator: '<S122>/Integrator'

  // Saturate: '<S122>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Saturation_UpperSat_k1) {
    rtb_Saturation_l = FCS_model_P.Saturation_UpperSat_k1;
  } else if (FCS_model_DW.Integrator_DSTATE_e <
             FCS_model_P.Saturation_LowerSat_h) {
    rtb_Saturation_l = FCS_model_P.Saturation_LowerSat_h;
  } else {
    rtb_Saturation_l = FCS_model_DW.Integrator_DSTATE_e;
  }

  // End of Saturate: '<S122>/Saturation'

  // Reshape: '<S42>/Reshapey' incorporates:
  //   Bias: '<S43>/Bias2'
  //   Bias: '<S43>/Bias3'
  //   Delay: '<S43>/Delay1'
  //   Delay: '<S43>/Delay2'
  //   Gain: '<S43>/Gain4'
  //   Gain: '<S43>/Gain5'
  //   Product: '<S43>/Product2'
  //   Product: '<S43>/Product3'
  //   Sum: '<S43>/Subtract2'
  //   Sum: '<S43>/Subtract3'

  rtb_Reshapey_idx_0 = (rtb_Converttometers + FCS_model_P.Bias3_Bias) *
    FCS_model_P.Gain5_Gain * (rtb_Saturation - FCS_model_DW.Delay2_DSTATE[0U]);
  rtb_Reshapey_idx_1 = (rtb_Converttometers + FCS_model_P.Bias2_Bias) *
    FCS_model_P.Gain4_Gain * (rtb_Saturation_l - FCS_model_DW.Delay1_DSTATE[0U]);

  // Outputs for Enabled SubSystem: '<S87>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S113>/Enable'

  if (rtb_Compare_kg) {
    FCS_model_DW.EnabledSubsystem_MODE_g = true;

    // Sum: '<S113>/Add1' incorporates:
    //   Constant: '<S42>/C'
    //   Delay: '<S42>/MemoryX'
    //   Product: '<S113>/Product'

    rtb_Product_g_idx_0 = rtb_Reshapey_idx_0 - (FCS_model_P.C_Value[0] *
      FCS_model_DW.MemoryX_DSTATE[0] + FCS_model_DW.MemoryX_DSTATE[1] *
      FCS_model_P.C_Value[2]);
    rtb_Product_g_idx_1 = rtb_Reshapey_idx_1 - (FCS_model_DW.MemoryX_DSTATE[0] *
      FCS_model_P.C_Value[1] + FCS_model_DW.MemoryX_DSTATE[1] *
      FCS_model_P.C_Value[3]);

    // Product: '<S113>/Product2' incorporates:
    //   Constant: '<S61>/KalmanGainM'

    FCS_model_B.Product2_c[0] = FCS_model_P.KalmanGainM_Value[0] *
      rtb_Product_g_idx_0 + FCS_model_P.KalmanGainM_Value[2] *
      rtb_Product_g_idx_1;
    FCS_model_B.Product2_c[1] = FCS_model_P.KalmanGainM_Value[1] *
      rtb_Product_g_idx_0 + FCS_model_P.KalmanGainM_Value[3] *
      rtb_Product_g_idx_1;
  } else if (FCS_model_DW.EnabledSubsystem_MODE_g) {
    // Disable for Product: '<S113>/Product2' incorporates:
    //   Outport: '<S113>/deltax'

    FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;
    FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;
    FCS_model_DW.EnabledSubsystem_MODE_g = false;
  }

  // End of Outputs for SubSystem: '<S87>/Enabled Subsystem'

  // Sum: '<S87>/Add' incorporates:
  //   Delay: '<S36>/Delay'
  //   Delay: '<S42>/MemoryX'

  FCS_model_DW.Delay_DSTATE[0] = FCS_model_B.Product2_c[0] +
    FCS_model_DW.MemoryX_DSTATE[0];

  // SignalConversion generated from: '<S131>/Product1' incorporates:
  //   Constant: '<S32>/Constant'

  rtb_Product_g_idx_1 = FCS_model_P.Constant_Value_c1[0];

  // Sum: '<S87>/Add' incorporates:
  //   Delay: '<S36>/Delay'
  //   Delay: '<S42>/MemoryX'

  FCS_model_DW.Delay_DSTATE[1] = FCS_model_B.Product2_c[1] +
    FCS_model_DW.MemoryX_DSTATE[1];

  // SignalConversion generated from: '<S131>/Product1' incorporates:
  //   Constant: '<S32>/Constant'
  //   Delay: '<S132>/MemoryX'
  //   Sum: '<S160>/Add'

  tmp_3 = FCS_model_P.Constant_Value_c1[1];
  tmp_2 = FCS_model_B.Product2[1] + FCS_model_DW.MemoryX_DSTATE_f[1];

  // Product: '<S131>/Product1' incorporates:
  //   Concatenate: '<S188>/Vector Concatenate'

  for (k = 0; k < 3; k++) {
    rtb_sincos_o2_h[k] = (rtb_VectorConcatenate[k + 3] * tmp_3 +
                          rtb_VectorConcatenate[k] * rtb_Product_g_idx_1) +
      rtb_VectorConcatenate[k + 6] * tmp_2;
  }

  // End of Product: '<S131>/Product1'

  // SignalConversion generated from: '<S35>/Product' incorporates:
  //   Delay: '<S36>/Delay'

  rtb_Product_g_idx_1 = FCS_model_DW.Delay_DSTATE[0];
  tmp_3 = FCS_model_DW.Delay_DSTATE[1];
  tmp_2 = rtb_sincos_o2_h[2];

  // Product: '<S131>/Product'
  rtb_inverseIMU_gain_0 = rtb_inverseIMU_gain[1];
  rtb_inverseIMU_gain_1 = rtb_inverseIMU_gain[0];
  rtb_inverseIMU_gain_2 = rtb_inverseIMU_gain[2];
  for (k = 0; k < 3; k++) {
    // Product: '<S35>/Product' incorporates:
    //   Concatenate: '<S48>/Vector Concatenate'
    //   Math: '<S35>/Math Function'

    rtb_Product[k] = (rtb_VectorConcatenate_k[3 * k + 1] * tmp_3 +
                      rtb_VectorConcatenate_k[3 * k] * rtb_Product_g_idx_1) +
      rtb_VectorConcatenate_k[3 * k + 2] * tmp_2;

    // Sum: '<S131>/Sum' incorporates:
    //   Constant: '<S131>/gravity'
    //   Math: '<S131>/Math Function'
    //   Product: '<S131>/Product'

    rtb_Sum_k[k] = ((rtb_MathFunction[k + 3] * rtb_inverseIMU_gain_0 +
                     rtb_MathFunction[k] * rtb_inverseIMU_gain_1) +
                    rtb_MathFunction[k + 6] * rtb_inverseIMU_gain_2) +
      FCS_model_P.gravity_Value[k];

    // Trigonometry: '<S45>/sincos'
    rtb_Product_g_idx_0 = rtb_sincos_o1[k];
    rtb_Add_k[k] = std::cos(rtb_Product_g_idx_0);
    rtb_sincos_o1[k] = std::sin(rtb_Product_g_idx_0);
  }

  // Fcn: '<S45>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_Add_k[0] * rtb_Add_k[1];

  // Fcn: '<S45>/Fcn21' incorporates:
  //   Fcn: '<S45>/Fcn22'

  rtb_Product_g_idx_0 = rtb_sincos_o1[1] * rtb_sincos_o1[2];
  rtb_VectorConcatenate_k[1] = rtb_Product_g_idx_0 * rtb_Add_k[0] -
    rtb_sincos_o1[0] * rtb_Add_k[2];

  // Fcn: '<S45>/Fcn31' incorporates:
  //   Fcn: '<S45>/Fcn32'

  rtb_Product_g_idx_1 = rtb_sincos_o1[1] * rtb_Add_k[2];
  rtb_VectorConcatenate_k[2] = rtb_Product_g_idx_1 * rtb_Add_k[0] +
    rtb_sincos_o1[0] * rtb_sincos_o1[2];

  // Fcn: '<S45>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_sincos_o1[0] * rtb_Add_k[1];

  // Fcn: '<S45>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_Product_g_idx_0 * rtb_sincos_o1[0] +
    rtb_Add_k[0] * rtb_Add_k[2];

  // Fcn: '<S45>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_Product_g_idx_1 * rtb_sincos_o1[0] -
    rtb_Add_k[0] * rtb_sincos_o1[2];

  // Fcn: '<S45>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_sincos_o1[1];

  // Fcn: '<S45>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_Add_k[1] * rtb_sincos_o1[2];

  // Fcn: '<S45>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_Add_k[1] * rtb_Add_k[2];

  // Trigonometry: '<S192>/Trigonometric Function3'
  rtb_TrigonometricFunction3 = std::cos(rtb_TrigonometricFunction3);

  // RelationalOperator: '<S44>/Compare' incorporates:
  //   Constant: '<S44>/Constant'

  rtb_Compare_jy = (rtb_SimplyIntegrateVelocity[0] <=
                    FCS_model_P.DeactivateAccelerationIfOFisnot);

  // Logic: '<S40>/Logical Operator' incorporates:
  //   Constant: '<S46>/Constant'
  //   Constant: '<S47>/Constant'
  //   Inport: '<Root>/in_parameters'
  //   RelationalOperator: '<S46>/Compare'
  //   RelationalOperator: '<S47>/Compare'

  rtb_LogicalOperator_g = ((arg_in_parameters->opticalflow_x !=
    FCS_model_P.donotuseaccifopticalflowneverav) ||
    (arg_in_parameters->opticalflow_y !=
     FCS_model_P.donotuseaccifopticalflownever_c));

  // Product: '<S40>/Product1' incorporates:
  //   Constant: '<S40>/gravity'

  rtb_Product_g_idx_0 = FCS_model_P.gravity_Value_a[1];
  rtb_Product_g_idx_1 = FCS_model_P.gravity_Value_a[0];
  tmp_3 = FCS_model_P.gravity_Value_a[2];

  // Sum: '<S40>/Add' incorporates:
  //   Concatenate: '<S48>/Vector Concatenate'
  //   Constant: '<S40>/gravity'
  //   Product: '<S40>/Product1'

  for (k = 0; k < 3; k++) {
    rtb_sincos_o1[k] = rtb_inverseIMU_gain[k] - ((rtb_VectorConcatenate_k[k + 3]
      * rtb_Product_g_idx_0 + rtb_VectorConcatenate_k[k] * rtb_Product_g_idx_1)
      + rtb_VectorConcatenate_k[k + 6] * tmp_3);
  }

  // End of Sum: '<S40>/Add'

  // Product: '<S40>/Product' incorporates:
  //   Gain: '<S40>/gainaccinput'

  rtb_Product_g_idx_0 = FCS_model_P.gainaccinput_Gain * rtb_sincos_o1[0] *
    static_cast<real_T>(rtb_LogicalOperator_g) * static_cast<real_T>
    (rtb_Compare_jy);
  rtb_Product_g_idx_1 = FCS_model_P.gainaccinput_Gain * rtb_sincos_o1[1] *
    static_cast<real_T>(rtb_LogicalOperator_g) * static_cast<real_T>
    (rtb_Compare_jy);

  // Outputs for Enabled SubSystem: '<S80>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S111>/Enable'

  if (rtb_Compare_kg) {
    FCS_model_DW.MeasurementUpdate_MODE_h = true;

    // Sum: '<S111>/Sum' incorporates:
    //   Constant: '<S42>/C'
    //   Constant: '<S42>/D'
    //   Delay: '<S42>/MemoryX'
    //   Product: '<S111>/C[k]*xhat[k|k-1]'
    //   Product: '<S111>/D[k]*u[k]'
    //   Sum: '<S111>/Add1'

    rtb_Reshapey_idx_0 -= (FCS_model_P.C_Value[0] * FCS_model_DW.MemoryX_DSTATE
      [0] + FCS_model_DW.MemoryX_DSTATE[1] * FCS_model_P.C_Value[2]) +
      (FCS_model_P.D_Value[0] * rtb_Product_g_idx_0 + FCS_model_P.D_Value[2] *
       rtb_Product_g_idx_1);
    rtb_Reshapey_idx_1 -= (FCS_model_DW.MemoryX_DSTATE[0] * FCS_model_P.C_Value
      [1] + FCS_model_DW.MemoryX_DSTATE[1] * FCS_model_P.C_Value[3]) +
      (FCS_model_P.D_Value[1] * rtb_Product_g_idx_0 + FCS_model_P.D_Value[3] *
       rtb_Product_g_idx_1);

    // Product: '<S111>/Product3' incorporates:
    //   Constant: '<S61>/KalmanGainL'

    FCS_model_B.Product3_d[0] = FCS_model_P.KalmanGainL_Value[0] *
      rtb_Reshapey_idx_0 + FCS_model_P.KalmanGainL_Value[2] * rtb_Reshapey_idx_1;
    FCS_model_B.Product3_d[1] = FCS_model_P.KalmanGainL_Value[1] *
      rtb_Reshapey_idx_0 + FCS_model_P.KalmanGainL_Value[3] * rtb_Reshapey_idx_1;
  } else if (FCS_model_DW.MeasurementUpdate_MODE_h) {
    // Disable for Product: '<S111>/Product3' incorporates:
    //   Outport: '<S111>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_DW.MeasurementUpdate_MODE_h = false;
  }

  // End of Outputs for SubSystem: '<S80>/MeasurementUpdate'

  // Outputs for Enabled SubSystem: '<S154>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S183>/Enable'

  if (rtb_Compare_l) {
    FCS_model_DW.MeasurementUpdate_MODE = true;

    // DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S132>/C'
    //   Constant: '<S132>/D'
    //   Delay: '<S132>/MemoryX'
    //   Product: '<S183>/C[k]*xhat[k|k-1]'
    //   Product: '<S183>/D[k]*u[k]'
    //   Sum: '<S183>/Add1'
    //   Sum: '<S183>/Sum'

    rtb_Switch1 = rtb_sincos_o2[2] - ((FCS_model_P.C_Value_f[0] *
      FCS_model_DW.MemoryX_DSTATE_f[0] + FCS_model_P.C_Value_f[1] *
      FCS_model_DW.MemoryX_DSTATE_f[1]) + FCS_model_P.D_Value_k * rtb_Sum_k[2]);

    // Product: '<S183>/Product3' incorporates:
    //   Constant: '<S135>/KalmanGainL'

    FCS_model_B.Product3[0] = FCS_model_P.KalmanGainL_Value_m[0] * rtb_Switch1;
    FCS_model_B.Product3[1] = FCS_model_P.KalmanGainL_Value_m[1] * rtb_Switch1;
  } else if (FCS_model_DW.MeasurementUpdate_MODE) {
    // Disable for Product: '<S183>/Product3' incorporates:
    //   Outport: '<S183>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_h;
    FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_h;
    FCS_model_DW.MeasurementUpdate_MODE = false;
  }

  // End of Outputs for SubSystem: '<S154>/MeasurementUpdate'

  // DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
  //   Delay: '<S36>/Delay'
  //   DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity'
  //   Gain: '<S22>/Gain1'
  //   Gain: '<S22>/Gain3'
  //   Gain: '<S22>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S22>/Subtract'
  //   Sum: '<S22>/Sum1'

  rtb_Switch1 = ((arg_in_dashboard->ref_x -
                  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0]) *
                 FCS_model_P.Gain3_Gain_g - FCS_model_P.Gain4_Gain_m *
                 FCS_model_DW.Delay_DSTATE[0]) * FCS_model_P.Gain1_Gain_b;

  // Saturate: '<S22>/Saturation'
  if (rtb_Switch1 > FCS_model_P.Saturation_UpperSat_d) {
    // DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
    rtb_Switch1 = FCS_model_P.Saturation_UpperSat_d;
  } else if (rtb_Switch1 < FCS_model_P.Saturation_LowerSat_a) {
    // DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
    rtb_Switch1 = FCS_model_P.Saturation_LowerSat_a;
  }

  // End of Saturate: '<S22>/Saturation'

  // Gain: '<S23>/Gain1' incorporates:
  //   Delay: '<S36>/Delay'
  //   DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity'
  //   Gain: '<S23>/Gain3'
  //   Gain: '<S23>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S23>/Subtract'
  //   Sum: '<S23>/Sum1'

  rtb_Reshapey_idx_0 = ((arg_in_dashboard->ref_y -
    FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1]) * FCS_model_P.Gain3_Gain_i -
                        FCS_model_P.Gain4_Gain_h * FCS_model_DW.Delay_DSTATE[1])
    * FCS_model_P.Gain1_Gain_i;

  // Saturate: '<S23>/Saturation'
  if (rtb_Reshapey_idx_0 > FCS_model_P.Saturation_UpperSat_ku) {
    rtb_Reshapey_idx_0 = FCS_model_P.Saturation_UpperSat_ku;
  } else if (rtb_Reshapey_idx_0 < FCS_model_P.Saturation_LowerSat_j) {
    rtb_Reshapey_idx_0 = FCS_model_P.Saturation_LowerSat_j;
  }

  // End of Saturate: '<S23>/Saturation'

  // Outport: '<Root>/out_controllers' incorporates:
  //   BusCreator generated from: '<Root>/out_controllers'
  //   Constant: '<S6>/Constant'

  arg_out_controllers->motor1 = rtb_Product1_i[0];
  arg_out_controllers->motor2 = rtb_Product1_i[1];
  arg_out_controllers->motor3 = rtb_Product1_i[2];
  arg_out_controllers->motor4 = rtb_Product1_i[3];
  arg_out_controllers->cmd_thrust = rtb_On1Off0forthrust;
  arg_out_controllers->cmd_tau_roll = rtb_On1Off0forroll;
  arg_out_controllers->cmd_tau_pitch = rtb_On1Off0forpitch;
  arg_out_controllers->cmd_tau_yaw = rtb_DiscreteFilter2;
  arg_out_controllers->cmd_roll = rtb_Switch1;
  arg_out_controllers->cmd_pitch = rtb_Reshapey_idx_0;
  arg_out_controllers->cmd_yaw = FCS_model_P.Constant_Value_e;

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch2_Threshold) {
    // Switch: '<S4>/Switch2'
    rtb_Switch2 = rtb_Reshapey_idx_0;
  } else {
    // Switch: '<S4>/Switch2' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Switch2 = arg_in_dashboard->ref_roll;
  }

  // End of Switch: '<S4>/Switch2'

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (!(FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch1_Threshold)) {
    // DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'
    //   Switch: '<S4>/Switch1'

    rtb_Switch1 = arg_in_dashboard->ref_pitch;
  }

  // End of Switch: '<S4>/Switch1'

  // Outport: '<Root>/out_estimators' incorporates:
  //   BusCreator generated from: '<Root>/out_estimators'
  //   Delay: '<S36>/Delay'
  //   DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity'
  //   DiscreteTransferFcn: '<S189>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S33>/Discrete Transfer Fcn'
  //   Gain: '<S31>/Gain'

  arg_out_estimators->orient_roll = FCS_model_DW.Memory_PreviousInput;
  arg_out_estimators->orient_pitch = rtb_AvoidDividebyZero;
  arg_out_estimators->orient_yaw = FCS_model_DW.Memory_PreviousInput_g;
  arg_out_estimators->orient_rate_roll = rtb_DiscreteTransferFcn[0];
  arg_out_estimators->orient_rate_pitch = rtb_DiscreteTransferFcn[1];
  arg_out_estimators->orient_rate_yaw = rtb_Ki;
  arg_out_estimators->pos_x = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0];
  arg_out_estimators->pos_y = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1];
  arg_out_estimators->pos_z = rtb_SimplyIntegrateVelocity[0];
  arg_out_estimators->pos_dx = FCS_model_DW.Delay_DSTATE[0];
  arg_out_estimators->pos_dy = FCS_model_DW.Delay_DSTATE[1];
  arg_out_estimators->pos_dz = rtb_sincos_o2_h[2];
  arg_out_estimators->battery_SOC = FCS_model_P.Gain_Gain_h *
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o;

  // MinMax: '<S116>/Max' incorporates:
  //   Constant: '<S116>/Time constant'

  if ((FCS_model_B.Probe_c[0] >= FCS_model_P.LowPassFilterDiscreteorContin_a) ||
      rtIsNaN(FCS_model_P.LowPassFilterDiscreteorContin_a)) {
    rtb_Reshapey_idx_0 = FCS_model_B.Probe_c[0];
  } else {
    rtb_Reshapey_idx_0 = FCS_model_P.LowPassFilterDiscreteorContin_a;
  }

  // End of MinMax: '<S116>/Max'

  // Fcn: '<S116>/Avoid Divide by Zero'
  rtb_AvoidDividebyZero = static_cast<real_T>(rtb_Reshapey_idx_0 == 0.0) *
    2.2204460492503131e-16 + rtb_Reshapey_idx_0;

  // MinMax: '<S123>/Max' incorporates:
  //   Constant: '<S123>/Time constant'

  if ((FCS_model_B.Probe[0] >= FCS_model_P.LowPassFilterDiscreteorContin_l) ||
      rtIsNaN(FCS_model_P.LowPassFilterDiscreteorContin_l)) {
    rtb_Reshapey_idx_0 = FCS_model_B.Probe[0];
  } else {
    rtb_Reshapey_idx_0 = FCS_model_P.LowPassFilterDiscreteorContin_l;
  }

  // End of MinMax: '<S123>/Max'

  // DiscreteFilter: '<S3>/Discrete Filter2' incorporates:
  //   Constant: '<S3>/Constant2'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S3>/Sum2'

  rtb_On1Off0forthrust = ((((arg_in_parameters->barometer_pressure -
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
  arg_out_sensors->accelerometer_x = rtb_inverseIMU_gain[0];
  arg_out_sensors->accelerometer_y = rtb_inverseIMU_gain[1];
  arg_out_sensors->accelerometer_z = rtb_inverseIMU_gain[2];
  arg_out_sensors->gyroscope_x = rtb_r[0];
  arg_out_sensors->gyroscope_y = rtb_r[1];
  arg_out_sensors->gyroscope_z = rtb_r[2];
  arg_out_sensors->barometer_pressure = ((FCS_model_P.DiscreteFilter2_NumCoef[0]
    * rtb_On1Off0forthrust + FCS_model_DW.DiscreteFilter2_states[0] *
    FCS_model_P.DiscreteFilter2_NumCoef[1]) +
    FCS_model_DW.DiscreteFilter2_states[1] *
    FCS_model_P.DiscreteFilter2_NumCoef[2]) +
    FCS_model_DW.DiscreteFilter2_states[2] *
    FCS_model_P.DiscreteFilter2_NumCoef[3];
  arg_out_sensors->rangefinder_distance = rtb_Converttometers;

  // Gain: '<S9>/Ki'
  rtb_Ki = FCS_model_P.ki_pit * rtb_Sum1_a;

  // MATLAB Function: '<S109>/SqrtUsedFcn' incorporates:
  //   Constant: '<S109>/isSqrtUsed'
  //   Constant: '<S61>/CovarianceZ'

  FCS_model_SqrtUsedFcn(FCS_model_P.CovarianceZ_Value,
                        FCS_model_P.isSqrtUsed_Value, rtb_Product1_i);

  // MATLAB Function: '<S181>/SqrtUsedFcn' incorporates:
  //   Constant: '<S135>/CovarianceZ'
  //   Constant: '<S181>/isSqrtUsed'

  FCS_model_SqrtUsedFcn(FCS_model_P.CovarianceZ_Value_g,
                        FCS_model_P.isSqrtUsed_Value_a, rtb_Product1_i);

  // SignalConversion generated from: '<Root>/in_dashboard' incorporates:
  //   Inport: '<Root>/in_dashboard'

  rtb_ref_yaw = arg_in_dashboard->ref_yaw;

  // Update for DiscreteFilter: '<S3>/IIR_IMUgyro_r'
  for (k = 0; k < 3; k++) {
    memOffset = k * 5;
    FCS_model_DW.IIR_IMUgyro_r_states[memOffset + 4] =
      FCS_model_DW.IIR_IMUgyro_r_states[memOffset + 3];
    FCS_model_DW.IIR_IMUgyro_r_states[memOffset + 3] =
      FCS_model_DW.IIR_IMUgyro_r_states[memOffset + 2];
    FCS_model_DW.IIR_IMUgyro_r_states[memOffset + 2] =
      FCS_model_DW.IIR_IMUgyro_r_states[memOffset + 1];
    FCS_model_DW.IIR_IMUgyro_r_states[memOffset + 1] =
      FCS_model_DW.IIR_IMUgyro_r_states[memOffset];
    FCS_model_DW.IIR_IMUgyro_r_states[memOffset] = IIR_IMUgyro_r_tmp[k];
  }

  // End of Update for DiscreteFilter: '<S3>/IIR_IMUgyro_r'

  // Update for DiscreteTransferFcn: '<S190>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states = rtb_Gain;

  // Update for DiscreteTransferFcn: '<S189>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states_a = DiscreteTransferFcn_tmp_k;

  // Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S10>/ki_rol1'

  FCS_model_DW.DiscreteTimeIntegrator_DSTATE += FCS_model_P.ki_rol * rtb_Sum1_di
    * FCS_model_P.DiscreteTimeIntegrator_gainval;

  // Update for DiscreteStateSpace: '<S15>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_A[1])*FCS_model_DW.Internal_DSTATE[1];
    xnew[0] += FCS_model_P.Internal_B*rtb_Switch2;
    xnew[1] = (FCS_model_P.Internal_A[2])*FCS_model_DW.Internal_DSTATE[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteTransferFcn: '<S33>/Discrete Transfer Fcn' incorporates:
  //   Product: '<S192>/Divide1'
  //   Product: '<S192>/Divide2'
  //   Product: '<S192>/Product8'
  //   Product: '<S192>/Product9'
  //   SignalConversion generated from: '<S33>/Discrete Transfer Fcn'
  //   Sum: '<S192>/Sum2'
  //   Trigonometry: '<S192>/Trigonometric Function2'

  FCS_model_DW.DiscreteTransferFcn_states_l[0] = (rtb_Subtract -
    FCS_model_DW.DiscreteTransferFcn_states_l[0] *
    FCS_model_P.DiscreteTransferFcn_DenCoef_e[1]) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_e[0];
  FCS_model_DW.DiscreteTransferFcn_states_l[1] = (rtb_pitchrate -
    FCS_model_P.DiscreteTransferFcn_DenCoef_e[1] *
    FCS_model_DW.DiscreteTransferFcn_states_l[1]) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_e[0];
  FCS_model_DW.DiscreteTransferFcn_states_l[2] = ((rtb_Product8 /
    rtb_TrigonometricFunction3 * rtb_r[1] + IIR_IMUgyro_r_tmp_0 /
    rtb_TrigonometricFunction3 * rtb_r[2]) -
    FCS_model_P.DiscreteTransferFcn_DenCoef_e[1] *
    FCS_model_DW.DiscreteTransferFcn_states_l[2]) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_e[0];

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

  // Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  FCS_model_DW.DiscreteTimeIntegrator_DSTATE_e +=
    FCS_model_P.DiscreteTimeIntegrator_gainva_k * rtb_Ki;

  // Update for DiscreteStateSpace: '<S18>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_l[0])*FCS_model_DW.Internal_DSTATE_f[0]
      + (FCS_model_P.Internal_A_l[1])*FCS_model_DW.Internal_DSTATE_f[1];
    xnew[0] += FCS_model_P.Internal_B_e*rtb_ref_yaw;
    xnew[1] = (FCS_model_P.Internal_A_l[2])*FCS_model_DW.Internal_DSTATE_f[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_f[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for Delay: '<S42>/MemoryX'
  FCS_model_DW.icLoad = false;

  // Product: '<S80>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S42>/A'
  //   Delay: '<S42>/MemoryX'

  tmp_0[0] = FCS_model_P.A_Value[0] * FCS_model_DW.MemoryX_DSTATE[0] +
    FCS_model_DW.MemoryX_DSTATE[1] * FCS_model_P.A_Value[2];

  // Product: '<S80>/B[k]*u[k]' incorporates:
  //   Constant: '<S42>/B'

  tmp[0] = FCS_model_P.B_Value[0] * rtb_Product_g_idx_0 + FCS_model_P.B_Value[2]
    * rtb_Product_g_idx_1;

  // Product: '<S80>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S42>/A'
  //   Delay: '<S42>/MemoryX'

  tmp_0[1] = FCS_model_DW.MemoryX_DSTATE[0] * FCS_model_P.A_Value[1] +
    FCS_model_DW.MemoryX_DSTATE[1] * FCS_model_P.A_Value[3];

  // Product: '<S80>/B[k]*u[k]' incorporates:
  //   Constant: '<S42>/B'

  tmp[1] = FCS_model_P.B_Value[1] * rtb_Product_g_idx_0 + FCS_model_P.B_Value[3]
    * rtb_Product_g_idx_1;

  // Update for Delay: '<S132>/MemoryX'
  FCS_model_DW.icLoad_m = false;

  // Delay: '<S132>/MemoryX' incorporates:
  //   Constant: '<S132>/A'
  //   Product: '<S154>/A[k]*xhat[k|k-1]'

  rtb_Product8 = FCS_model_DW.MemoryX_DSTATE_f[1];
  IIR_IMUgyro_r_tmp_0 = FCS_model_DW.MemoryX_DSTATE_f[0];
  for (k = 0; k < 2; k++) {
    // Update for Delay: '<S42>/MemoryX' incorporates:
    //   Sum: '<S80>/Add'

    FCS_model_DW.MemoryX_DSTATE[k] = (tmp[k] + tmp_0[k]) +
      FCS_model_B.Product3_d[k];

    // Update for DiscreteFilter: '<S41>/IIRgyroz'
    memOffset = k * 5;
    FCS_model_DW.IIRgyroz_states[memOffset + 4] =
      FCS_model_DW.IIRgyroz_states[memOffset + 3];
    FCS_model_DW.IIRgyroz_states[memOffset + 3] =
      FCS_model_DW.IIRgyroz_states[memOffset + 2];
    FCS_model_DW.IIRgyroz_states[memOffset + 2] =
      FCS_model_DW.IIRgyroz_states[memOffset + 1];
    FCS_model_DW.IIRgyroz_states[memOffset + 1] =
      FCS_model_DW.IIRgyroz_states[memOffset];
    FCS_model_DW.IIRgyroz_states[memOffset] = IIRgyroz_tmp[k];

    // Update for UnitDelay: '<S49>/UD'
    //
    //  Block description for '<S49>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[k] = rtb_TSamp[k];

    // Product: '<S154>/A[k]*xhat[k|k-1]' incorporates:
    //   Constant: '<S132>/A'
    //   Delay: '<S132>/MemoryX'

    tmp_1[k] = FCS_model_P.A_Value_p[k + 2] * rtb_Product8 +
      FCS_model_P.A_Value_p[k] * IIR_IMUgyro_r_tmp_0;
  }

  // Update for Delay: '<S132>/MemoryX' incorporates:
  //   Constant: '<S132>/B'
  //   Product: '<S154>/B[k]*u[k]'
  //   Product: '<S183>/Product3'
  //   Sum: '<S154>/Add'

  FCS_model_DW.MemoryX_DSTATE_f[0] = (FCS_model_P.B_Value_o[0] * rtb_Sum_k[2] +
    tmp_1[0]) + FCS_model_B.Product3[0];

  // Update for DiscreteFilter: '<S3>/Discrete Filter1'
  FCS_model_DW.DiscreteFilter1_states[2] = FCS_model_DW.DiscreteFilter1_states[1];

  // Update for Delay: '<S132>/MemoryX' incorporates:
  //   Constant: '<S132>/B'
  //   Product: '<S154>/B[k]*u[k]'
  //   Product: '<S183>/Product3'
  //   Sum: '<S154>/Add'

  FCS_model_DW.MemoryX_DSTATE_f[1] = (FCS_model_P.B_Value_o[1] * rtb_Sum_k[2] +
    tmp_1[1]) + FCS_model_B.Product3[1];

  // Update for DiscreteFilter: '<S3>/Discrete Filter1'
  FCS_model_DW.DiscreteFilter1_states[1] = FCS_model_DW.DiscreteFilter1_states[0];
  FCS_model_DW.DiscreteFilter1_states[0] = rtb_Sum1;

  // Update for Delay: '<S131>/Delay One Step'
  FCS_model_DW.DelayOneStep_DSTATE = rtb_SimplyIntegrateVelocity[0];

  // Update for DiscreteIntegrator: '<S129>/Integrator' incorporates:
  //   Fcn: '<S123>/Avoid Divide by Zero'
  //   Product: '<S115>/1//T'
  //   Sum: '<S115>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING = 0U;
  FCS_model_DW.Integrator_DSTATE += 1.0 / (static_cast<real_T>
    (rtb_Reshapey_idx_0 == 0.0) * 2.2204460492503131e-16 + rtb_Reshapey_idx_0) *
    (rtb_DiscreteTimeIntegrator_j - rtb_Saturation) *
    FCS_model_P.Integrator_gainval;
  if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Integrator_UpperSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Integrator_LowerSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
  }

  FCS_model_DW.Integrator_PrevResetState = static_cast<int8_T>(rtb_Compare_lv);

  // End of Update for DiscreteIntegrator: '<S129>/Integrator'

  // Update for Delay: '<S43>/Delay2'
  for (k = 0; k < 39; k++) {
    FCS_model_DW.Delay2_DSTATE[k] = FCS_model_DW.Delay2_DSTATE[k + 1];
  }

  FCS_model_DW.Delay2_DSTATE[39] = rtb_r[0];

  // End of Update for Delay: '<S43>/Delay2'

  // Update for DiscreteIntegrator: '<S122>/Integrator' incorporates:
  //   Product: '<S114>/1//T'
  //   Sum: '<S114>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING_g = 0U;
  FCS_model_DW.Integrator_DSTATE_e += 1.0 / rtb_AvoidDividebyZero * (rtb_K_i -
    rtb_Saturation_l) * FCS_model_P.Integrator_gainval_g;
  if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Integrator_UpperSat_i) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
  } else if (FCS_model_DW.Integrator_DSTATE_e <
             FCS_model_P.Integrator_LowerSat_l) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
  }

  FCS_model_DW.Integrator_PrevResetState_e = static_cast<int8_T>(rtb_Compare_kk);

  // End of Update for DiscreteIntegrator: '<S122>/Integrator'

  // Update for Delay: '<S43>/Delay1'
  for (k = 0; k < 39; k++) {
    FCS_model_DW.Delay1_DSTATE[k] = FCS_model_DW.Delay1_DSTATE[k + 1];
  }

  FCS_model_DW.Delay1_DSTATE[39] = rtb_r[1];

  // End of Update for Delay: '<S43>/Delay1'

  // Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/in_parameters'

  FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o +=
    FCS_model_P.DiscreteTimeIntegrator_gainva_i *
    arg_in_parameters->battery_current;

  // Update for DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity'
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval * rtb_Product[0];

  // Update for DiscreteFilter: '<S3>/Discrete Filter2'
  FCS_model_DW.DiscreteFilter2_states[2] = FCS_model_DW.DiscreteFilter2_states[1];

  // Update for DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity'
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval * rtb_Product[1];

  // Update for DiscreteFilter: '<S3>/Discrete Filter2'
  FCS_model_DW.DiscreteFilter2_states[1] = FCS_model_DW.DiscreteFilter2_states[0];
  FCS_model_DW.DiscreteFilter2_states[0] = rtb_On1Off0forthrust;

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
  FCS_model_P.Saturation_UpperSat_k = rtInf;
  FCS_model_P.Saturation_LowerSat_m = rtMinusInf;
  FCS_model_P.Integrator_UpperSat_i = rtInf;
  FCS_model_P.Integrator_LowerSat_l = rtMinusInf;
  FCS_model_P.Saturation_UpperSat_k1 = rtInf;
  FCS_model_P.Saturation_LowerSat_h = rtMinusInf;

  {
    int32_T i;

    // Start for Probe: '<S123>/Probe'
    FCS_model_B.Probe[0] = 0.0025;
    FCS_model_B.Probe[1] = 0.0;

    // Start for Probe: '<S116>/Probe'
    FCS_model_B.Probe_c[0] = 0.0025;
    FCS_model_B.Probe_c[1] = 0.0;
    FCS_model_PrevZCX.DiscreteTransferFcn_Reset_ZCE = UNINITIALIZED_ZCSIG;

    // InitializeConditions for Memory: '<S190>/Memory'
    FCS_model_DW.Memory_PreviousInput = FCS_model_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteFilter: '<S3>/IIR_IMUgyro_r'
    for (i = 0; i < 15; i++) {
      FCS_model_DW.IIR_IMUgyro_r_states[i] =
        FCS_model_P.IIR_IMUgyro_r_InitialStates;
    }

    // End of InitializeConditions for DiscreteFilter: '<S3>/IIR_IMUgyro_r'

    // InitializeConditions for Delay: '<S190>/Delay One Step'
    FCS_model_DW.DelayOneStep_DSTATE_f =
      FCS_model_P.DelayOneStep_InitialCondition_k;

    // InitializeConditions for DiscreteTransferFcn: '<S190>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_icLoad = 1U;

    // InitializeConditions for DiscreteTransferFcn: '<S189>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_states_a =
      FCS_model_P.DiscreteTransferFcn_InitialSt_e;

    // InitializeConditions for Merge: '<S193>/Merge1' incorporates:
    //   Memory: '<S33>/Memory'

    FCS_model_DW.Memory_PreviousInput_g = FCS_model_P.Memory_InitialCondition_f;

    // InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' 
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE =
      FCS_model_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for DiscreteStateSpace: '<S15>/Internal'
    FCS_model_DW.Internal_DSTATE[0] = FCS_model_P.Internal_InitialCondition;
    FCS_model_DW.Internal_DSTATE[1] = FCS_model_P.Internal_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S33>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_states_l[0] =
      FCS_model_P.DiscreteTransferFcn_InitialSt_p;
    FCS_model_DW.DiscreteTransferFcn_states_l[1] =
      FCS_model_P.DiscreteTransferFcn_InitialSt_p;
    FCS_model_DW.DiscreteTransferFcn_states_l[2] =
      FCS_model_P.DiscreteTransferFcn_InitialSt_p;

    // InitializeConditions for DiscreteStateSpace: '<S12>/Internal'
    FCS_model_DW.Internal_DSTATE_l[0] = FCS_model_P.Internal_InitialCondition_l;
    FCS_model_DW.Internal_DSTATE_l[1] = FCS_model_P.Internal_InitialCondition_l;

    // InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' 
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_e =
      FCS_model_P.DiscreteTimeIntegrator_IC_k;

    // InitializeConditions for DiscreteStateSpace: '<S18>/Internal'
    FCS_model_DW.Internal_DSTATE_f[0] = FCS_model_P.Internal_InitialCondition_a;
    FCS_model_DW.Internal_DSTATE_f[1] = FCS_model_P.Internal_InitialCondition_a;

    // InitializeConditions for Delay: '<S42>/MemoryX'
    FCS_model_DW.icLoad = true;

    // InitializeConditions for DiscreteFilter: '<S41>/IIRgyroz'
    for (i = 0; i < 10; i++) {
      FCS_model_DW.IIRgyroz_states[i] = FCS_model_P.IIRgyroz_InitialStates;
    }

    // End of InitializeConditions for DiscreteFilter: '<S41>/IIRgyroz'

    // InitializeConditions for UnitDelay: '<S49>/UD'
    //
    //  Block description for '<S49>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[0] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for Delay: '<S36>/Delay'
    FCS_model_DW.Delay_DSTATE[0] = FCS_model_P.Delay_InitialCondition;

    // InitializeConditions for UnitDelay: '<S49>/UD'
    //
    //  Block description for '<S49>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[1] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for Delay: '<S36>/Delay'
    FCS_model_DW.Delay_DSTATE[1] = FCS_model_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S132>/MemoryX'
    FCS_model_DW.icLoad_m = true;

    // InitializeConditions for DiscreteFilter: '<S3>/Discrete Filter1'
    FCS_model_DW.DiscreteFilter1_states[0] =
      FCS_model_P.DiscreteFilter1_InitialStates;
    FCS_model_DW.DiscreteFilter1_states[1] =
      FCS_model_P.DiscreteFilter1_InitialStates;
    FCS_model_DW.DiscreteFilter1_states[2] =
      FCS_model_P.DiscreteFilter1_InitialStates;

    // InitializeConditions for Delay: '<S131>/Delay One Step'
    FCS_model_DW.DelayOneStep_DSTATE = FCS_model_P.DelayOneStep_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S129>/Integrator'
    FCS_model_DW.Integrator_IC_LOADING = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S122>/Integrator'
    FCS_model_DW.Integrator_IC_LOADING_g = 1U;
    for (i = 0; i < 40; i++) {
      // InitializeConditions for Delay: '<S43>/Delay2'
      FCS_model_DW.Delay2_DSTATE[i] = FCS_model_P.Delay2_InitialCondition;

      // InitializeConditions for Delay: '<S43>/Delay1'
      FCS_model_DW.Delay1_DSTATE[i] = FCS_model_P.Delay1_InitialCondition;
    }

    // InitializeConditions for DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity' 
    FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0] =
      FCS_model_P.SimplyIntegrateVelocity_IC;
    FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1] =
      FCS_model_P.SimplyIntegrateVelocity_IC;

    // InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' 
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o =
      FCS_model_P.DiscreteTimeIntegrator_IC_p;

    // InitializeConditions for DiscreteFilter: '<S3>/Discrete Filter2'
    FCS_model_DW.DiscreteFilter2_states[0] =
      FCS_model_P.DiscreteFilter2_InitialStates;
    FCS_model_DW.DiscreteFilter2_states[1] =
      FCS_model_P.DiscreteFilter2_InitialStates;
    FCS_model_DW.DiscreteFilter2_states[2] =
      FCS_model_P.DiscreteFilter2_InitialStates;

    // SystemInitialize for IfAction SubSystem: '<S193>/If Action Subsystem'
    // InitializeConditions for DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_states_p =
      FCS_model_P.DiscreteTransferFcn_InitialStat;

    // End of SystemInitialize for SubSystem: '<S193>/If Action Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S160>/Enabled Subsystem'
    // SystemInitialize for Product: '<S185>/Product2' incorporates:
    //   Outport: '<S185>/deltax'

    FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;

    // End of SystemInitialize for SubSystem: '<S160>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S87>/Enabled Subsystem'
    // SystemInitialize for Product: '<S113>/Product2' incorporates:
    //   Outport: '<S113>/deltax'

    FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;

    // End of SystemInitialize for SubSystem: '<S87>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S80>/MeasurementUpdate'
    // SystemInitialize for Product: '<S111>/Product3' incorporates:
    //   Outport: '<S111>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;

    // End of SystemInitialize for SubSystem: '<S80>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S154>/MeasurementUpdate'
    // SystemInitialize for Product: '<S183>/Product3' incorporates:
    //   Outport: '<S183>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S154>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S160>/Enabled Subsystem'
    // SystemInitialize for Product: '<S185>/Product2' incorporates:
    //   Outport: '<S185>/deltax'

    FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;

    // End of SystemInitialize for SubSystem: '<S160>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S87>/Enabled Subsystem'
    // SystemInitialize for Product: '<S113>/Product2' incorporates:
    //   Outport: '<S113>/deltax'

    FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;

    // End of SystemInitialize for SubSystem: '<S87>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S80>/MeasurementUpdate'
    // SystemInitialize for Product: '<S111>/Product3' incorporates:
    //   Outport: '<S111>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;

    // End of SystemInitialize for SubSystem: '<S80>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S154>/MeasurementUpdate'
    // SystemInitialize for Product: '<S183>/Product3' incorporates:
    //   Outport: '<S183>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S154>/MeasurementUpdate'
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
  FCS_model_PrevZCX(),
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
