//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
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
#include "FCS_model_types.h"
#include "rtwtypes.h"
#include <cmath>
#include "FCS_model_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "zero_crossing_types.h"
#include "rt_defines.h"

// Named constants for Chart: '<S24>/takeoff_acceleration'
const uint8_T FCS_model_IN_decreasing = 1U;
const uint8_T FCS_model_IN_done = 2U;
const uint8_T FCS_model_IN_increasing = 3U;
const uint8_T FCS_model_IN_waiting4trigger = 4U;
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
  real_T rtb_Sum1_a;
  real_T rtb_Switch2;
  real_T rtb_ref_yaw;
  real_T rtb_DiscreteTimeIntegrator_j;
  real_T rtb_On1Off2forpitch;
  real_T rtb_barometer_pressure;
  real_T rtb_MathFunction[9];
  real_T rtb_VectorConcatenate[9];
  real_T rtb_VectorConcatenate_k[9];
  real_T inverseIMU_gain[6];
  real_T rtb_Sum1_eu[6];
  real_T tmp[4];
  real_T rtb_Add_k[3];
  real_T rtb_FIR_IMUaccel[3];
  real_T rtb_FIR_IMUaccel_0[3];
  real_T rtb_sincos_o2_m[3];
  real_T rtb_sincos_o2_po[3];
  real_T IIRgyroz_tmp[2];
  real_T rtb_Akxhatkk1[2];
  real_T rtb_Product_c[2];
  real_T rtb_Reshapey[2];
  real_T tmp_0[2];
  real_T DiscreteFilter1_tmp;
  real_T DiscreteTransferFcn_tmp;
  real_T MemoryX_DSTATE;
  real_T MemoryX_DSTATE_0;
  real_T acc1;
  real_T numAccum;
  real_T rtb_Add_g_idx_0;
  real_T rtb_Add_g_idx_1;
  real_T rtb_Akxhatkk1_idx_0;
  real_T rtb_Akxhatkk1_idx_1;
  real_T rtb_AvoidDividebyZero;
  real_T rtb_K_i;
  real_T rtb_Saturation;
  real_T rtb_Saturation_a;
  real_T rtb_Saturation_l;
  real_T rtb_Saturation_p;
  real_T rtb_Subtract;
  real_T rtb_Sum1_le;
  real_T rtb_VectorConcatenate_tmp;
  real_T rtb_VectorConcatenate_tmp_0;
  real_T rtb_VectorConcatenate_tmp_1;
  real_T rtb_VectorConcatenate_tmp_2;
  real_T rtb_clock;
  real_T rtb_pitchrate;
  real_T rtb_rangefinder_distance;
  real_T rtb_roll;
  real_T rtb_rollrate;
  real_T rtb_sincos_o2_3;
  real_T rtb_sincos_o2_m_0;
  real_T rtb_sincos_o2_m_tmp;
  real_T rtb_sincos_o2_tmp;
  real_T u0;
  int32_T cff;
  int32_T i;
  int32_T memOffset;
  boolean_T rtb_Compare_jy;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator_b;
  boolean_T rtb_LogicalOperator_j;
  boolean_T rtb_Memory_i;

  // DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'
  rtb_AvoidDividebyZero = FCS_model_P.DiscreteTransferFcn_NumCoef_f[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // Bias: '<S3>/Assuming that calib was done level!' incorporates:
  //   Constant: '<Root>/Constant'

  for (i = 0; i < 6; i++) {
    rtb_Sum1_eu[i] = FCS_model_P.sensorCalibrationData[i] +
      FCS_model_P.Assumingthatcalibwasdonelevel_B[i];
  }

  // End of Bias: '<S3>/Assuming that calib was done level!'

  // Gain: '<S3>/inverseIMU_gain' incorporates:
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S3>/Sum1'

  inverseIMU_gain[0] = (arg_in_parameters->accelerometer_x - rtb_Sum1_eu[0]) *
    FCS_model_P.inverseIMU_gain_Gain[0];
  inverseIMU_gain[1] = (arg_in_parameters->accelerometer_y - rtb_Sum1_eu[1]) *
    FCS_model_P.inverseIMU_gain_Gain[1];
  inverseIMU_gain[2] = (arg_in_parameters->accelerometer_z - rtb_Sum1_eu[2]) *
    FCS_model_P.inverseIMU_gain_Gain[2];
  inverseIMU_gain[3] = (arg_in_parameters->gyroscope_x - rtb_Sum1_eu[3]) *
    FCS_model_P.inverseIMU_gain_Gain[3];
  inverseIMU_gain[4] = (arg_in_parameters->gyroscope_y - rtb_Sum1_eu[4]) *
    FCS_model_P.inverseIMU_gain_Gain[4];
  inverseIMU_gain[5] = (arg_in_parameters->gyroscope_z - rtb_Sum1_eu[5]) *
    FCS_model_P.inverseIMU_gain_Gain[5];

  // DiscreteFir: '<S3>/FIR_IMUaccel'
  acc1 = inverseIMU_gain[0] * FCS_model_P.FIR_IMUaccel_Coefficients[0];
  cff = 1;
  for (i = FCS_model_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states[i] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (i = 0; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states[i] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[0] = acc1;
  acc1 = FCS_model_P.FIR_IMUaccel_Coefficients[0] * inverseIMU_gain[1];
  cff = 1;
  for (i = FCS_model_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states[i + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (i = 0; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states[i + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[1] = acc1;
  acc1 = FCS_model_P.FIR_IMUaccel_Coefficients[0] * inverseIMU_gain[2];
  cff = 1;
  for (i = FCS_model_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states[i + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (i = 0; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    acc1 += FCS_model_DW.FIR_IMUaccel_states[i + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[2] = acc1;

  // Product: '<S187>/Divide' incorporates:
  //   Constant: '<S187>/Constant'
  //   Gain: '<S187>/Gain1'

  u0 = FCS_model_P.Gain1_Gain * rtb_FIR_IMUaccel[0] / FCS_model_P.g;

  // Trigonometry: '<S187>/Trigonometric Function1'
  if (u0 > 1.0) {
    u0 = 1.0;
  } else if (u0 < -1.0) {
    u0 = -1.0;
  }

  // Gain: '<S187>/Gain' incorporates:
  //   Trigonometry: '<S187>/Trigonometric Function1'

  rtb_Subtract = FCS_model_P.Gain_Gain * std::asin(u0);

  // Trigonometry: '<S187>/Trigonometric Function' incorporates:
  //   DiscreteFir: '<S3>/FIR_IMUaccel'
  //   Gain: '<S187>/Gain2'
  //   Gain: '<S187>/Gain3'

  rtb_roll = rt_atan2d_snf(FCS_model_P.Gain2_Gain * rtb_FIR_IMUaccel[1],
    FCS_model_P.Gain3_Gain * acc1);

  // Trigonometry: '<S188>/Trigonometric Function2'
  rtb_rollrate = std::sin(rtb_roll);
  rtb_Saturation_p = std::cos(rtb_roll);

  // Sum: '<S188>/Sum1' incorporates:
  //   Gain: '<S188>/Gain'
  //   Product: '<S188>/Product4'
  //   Product: '<S188>/Product5'

  rtb_pitchrate = FCS_model_P.Gain_Gain_p * rtb_rollrate * inverseIMU_gain[5] +
    rtb_Saturation_p * inverseIMU_gain[4];

  // DiscreteTransferFcn: '<S185>/Discrete Transfer Fcn' incorporates:
  //   Gain: '<S185>/Gain'
  //   Sum: '<S185>/Sum'

  DiscreteTransferFcn_tmp = ((FCS_model_P.w_c_pitch * rtb_Subtract +
    rtb_pitchrate) - FCS_model_P.DiscreteTransferFcn_DenCoef_b[1] *
    FCS_model_DW.DiscreteTransferFcn_states_a) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_b[0];
  numAccum = FCS_model_P.DiscreteTransferFcn_NumCoef_o[0] *
    DiscreteTransferFcn_tmp + FCS_model_P.DiscreteTransferFcn_NumCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states_a;

  // If: '<S189>/If1' incorporates:
  //   Constant: '<S33>/Constant'
  //   DataTypeConversion: '<S189>/Data Type Conversion'

  if (static_cast<real32_T>(FCS_model_P.Constant_Value_c) > 0.0F) {
    // Outputs for IfAction SubSystem: '<S189>/If Action Subsystem' incorporates:
    //   ActionPort: '<S191>/Action Port'

    // Merge: '<S189>/Merge1' incorporates:
    //   DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn'

    FCS_model_DW.Memory_PreviousInput = FCS_model_P.DiscreteTransferFcn_NumCoef
      [1] * FCS_model_DW.DiscreteTransferFcn_states_p;

    // Update for DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S192>/Gain'
    //   Inport: '<Root>/in_parameters'
    //   Sum: '<S192>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_p = ((FCS_model_P.w_c_yaw *
      arg_in_parameters->yaw + inverseIMU_gain[5]) -
      FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_p) /
      FCS_model_P.DiscreteTransferFcn_DenCoef[0];

    // End of Outputs for SubSystem: '<S189>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S189>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S190>/Action Port'

    // Merge: '<S189>/Merge1' incorporates:
    //   Gain: '<S190>/Gain'
    //   Memory: '<S33>/Memory'
    //   Sum: '<S190>/Sum'

    FCS_model_DW.Memory_PreviousInput += FCS_model_P.Ts * inverseIMU_gain[5];

    // End of Outputs for SubSystem: '<S189>/If Action Subsystem3'
  }

  // End of If: '<S189>/If1'

  // SignalConversion generated from: '<S38>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S185>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'

  rtb_Add_k[0] = FCS_model_DW.Memory_PreviousInput;
  rtb_Add_k[1] = numAccum;
  rtb_Add_k[2] = rtb_AvoidDividebyZero;

  // Trigonometry: '<S133>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S185>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'
  //   SignalConversion generated from: '<S38>/sincos'
  //   Trigonometry: '<S45>/sincos'

  rtb_sincos_o2_m_tmp = std::sin(FCS_model_DW.Memory_PreviousInput);
  rtb_sincos_o2_tmp = std::cos(FCS_model_DW.Memory_PreviousInput);
  rtb_clock = std::sin(numAccum);
  rtb_rangefinder_distance = std::cos(numAccum);
  u0 = std::sin(rtb_AvoidDividebyZero);
  DiscreteFilter1_tmp = std::cos(rtb_AvoidDividebyZero);

  // Fcn: '<S133>/Fcn11' incorporates:
  //   Fcn: '<S45>/Fcn11'
  //   Trigonometry: '<S133>/sincos'

  rtb_Sum1_le = rtb_sincos_o2_tmp * rtb_rangefinder_distance;
  rtb_VectorConcatenate[0] = rtb_Sum1_le;

  // Fcn: '<S133>/Fcn21' incorporates:
  //   Fcn: '<S133>/Fcn22'
  //   Fcn: '<S45>/Fcn21'
  //   Trigonometry: '<S133>/sincos'

  rtb_Saturation_a = rtb_clock * u0;
  rtb_VectorConcatenate_tmp_0 = rtb_Saturation_a * rtb_sincos_o2_tmp -
    rtb_sincos_o2_m_tmp * DiscreteFilter1_tmp;
  rtb_VectorConcatenate[1] = rtb_VectorConcatenate_tmp_0;

  // Fcn: '<S133>/Fcn31' incorporates:
  //   Fcn: '<S133>/Fcn32'
  //   Fcn: '<S45>/Fcn31'
  //   Trigonometry: '<S133>/sincos'

  rtb_VectorConcatenate_tmp = rtb_clock * DiscreteFilter1_tmp;
  rtb_VectorConcatenate_tmp_1 = rtb_VectorConcatenate_tmp * rtb_sincos_o2_tmp +
    rtb_sincos_o2_m_tmp * u0;
  rtb_VectorConcatenate[2] = rtb_VectorConcatenate_tmp_1;

  // Fcn: '<S133>/Fcn12' incorporates:
  //   Fcn: '<S45>/Fcn12'
  //   Trigonometry: '<S133>/sincos'

  rtb_VectorConcatenate_tmp_2 = rtb_sincos_o2_m_tmp * rtb_rangefinder_distance;
  rtb_VectorConcatenate[3] = rtb_VectorConcatenate_tmp_2;

  // Fcn: '<S133>/Fcn22' incorporates:
  //   Fcn: '<S45>/Fcn22'
  //   Trigonometry: '<S133>/sincos'

  rtb_Saturation_a = rtb_Saturation_a * rtb_sincos_o2_m_tmp + rtb_sincos_o2_tmp *
    DiscreteFilter1_tmp;
  rtb_VectorConcatenate[4] = rtb_Saturation_a;

  // Fcn: '<S133>/Fcn32' incorporates:
  //   Fcn: '<S45>/Fcn32'
  //   Trigonometry: '<S133>/sincos'

  rtb_VectorConcatenate_tmp = rtb_VectorConcatenate_tmp * rtb_sincos_o2_m_tmp -
    rtb_sincos_o2_tmp * u0;
  rtb_VectorConcatenate[5] = rtb_VectorConcatenate_tmp;

  // Fcn: '<S133>/Fcn13' incorporates:
  //   Trigonometry: '<S133>/sincos'

  rtb_VectorConcatenate[6] = -rtb_clock;

  // Fcn: '<S133>/Fcn23' incorporates:
  //   Fcn: '<S45>/Fcn23'
  //   Trigonometry: '<S133>/sincos'

  rtb_sincos_o2_m_tmp = rtb_rangefinder_distance * u0;
  rtb_VectorConcatenate[7] = rtb_sincos_o2_m_tmp;

  // Fcn: '<S133>/Fcn33' incorporates:
  //   Fcn: '<S45>/Fcn33'
  //   Trigonometry: '<S133>/sincos'

  rtb_sincos_o2_tmp = rtb_rangefinder_distance * DiscreteFilter1_tmp;
  rtb_VectorConcatenate[8] = rtb_sincos_o2_tmp;
  for (i = 0; i < 3; i++) {
    // Math: '<S131>/Math Function' incorporates:
    //   Concatenate: '<S184>/Vector Concatenate'

    rtb_MathFunction[3 * i] = rtb_VectorConcatenate[i];
    rtb_MathFunction[3 * i + 1] = rtb_VectorConcatenate[i + 3];
    rtb_MathFunction[3 * i + 2] = rtb_VectorConcatenate[i + 6];

    // Trigonometry: '<S38>/sincos'
    rtb_rangefinder_distance = rtb_Add_k[i];
    rtb_sincos_o2_m[i] = std::sin(rtb_rangefinder_distance);
    rtb_sincos_o2_po[i] = std::cos(rtb_rangefinder_distance);
  }

  // Fcn: '<S38>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_sincos_o2_po[0] * rtb_sincos_o2_po[1];

  // Fcn: '<S38>/Fcn21' incorporates:
  //   Fcn: '<S38>/Fcn22'

  rtb_rangefinder_distance = rtb_sincos_o2_m[1] * rtb_sincos_o2_m[2];
  rtb_VectorConcatenate_k[1] = rtb_rangefinder_distance * rtb_sincos_o2_po[0] -
    rtb_sincos_o2_m[0] * rtb_sincos_o2_po[2];

  // Fcn: '<S38>/Fcn31' incorporates:
  //   Fcn: '<S38>/Fcn32'

  DiscreteFilter1_tmp = rtb_sincos_o2_m[1] * rtb_sincos_o2_po[2];
  rtb_VectorConcatenate_k[2] = DiscreteFilter1_tmp * rtb_sincos_o2_po[0] +
    rtb_sincos_o2_m[0] * rtb_sincos_o2_m[2];

  // Fcn: '<S38>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_sincos_o2_m[0] * rtb_sincos_o2_po[1];

  // Fcn: '<S38>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_rangefinder_distance * rtb_sincos_o2_m[0] +
    rtb_sincos_o2_po[0] * rtb_sincos_o2_po[2];

  // Fcn: '<S38>/Fcn32'
  rtb_VectorConcatenate_k[5] = DiscreteFilter1_tmp * rtb_sincos_o2_m[0] -
    rtb_sincos_o2_po[0] * rtb_sincos_o2_m[2];

  // Fcn: '<S38>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_sincos_o2_m[1];

  // Fcn: '<S38>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_sincos_o2_po[1] * rtb_sincos_o2_m[2];

  // Fcn: '<S38>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_sincos_o2_po[1] * rtb_sincos_o2_po[2];

  // Sum: '<S3>/Sum3' incorporates:
  //   Constant: '<Root>/Constant'
  //   Inport: '<Root>/in_parameters'

  rtb_rangefinder_distance = arg_in_parameters->rangefinder_distance -
    FCS_model_P.sensorCalibrationData[7];

  // DiscreteFilter: '<S131>/Discrete Filter1'
  rtb_Add_g_idx_1 = rtb_rangefinder_distance;

  // Product: '<S131>/Product'
  DiscreteFilter1_tmp = rtb_FIR_IMUaccel[1];
  u0 = rtb_FIR_IMUaccel[0];
  for (i = 0; i < 3; i++) {
    // Sum: '<S131>/Sum' incorporates:
    //   Constant: '<S131>/gravity'
    //   DiscreteFir: '<S3>/FIR_IMUaccel'
    //   Math: '<S131>/Math Function'
    //   Product: '<S131>/Product'

    rtb_Add_k[i] = ((rtb_MathFunction[i + 3] * DiscreteFilter1_tmp +
                     rtb_MathFunction[i] * u0) + rtb_MathFunction[i + 6] * acc1)
      + FCS_model_P.gravity_Value[i];

    // DiscreteFilter: '<S131>/Discrete Filter1'
    rtb_Add_g_idx_1 -= FCS_model_P.DiscreteFilter1_DenCoef[i + 1] *
      FCS_model_DW.DiscreteFilter1_states[i];
  }

  // DiscreteFilter: '<S131>/Discrete Filter1'
  DiscreteFilter1_tmp = rtb_Add_g_idx_1 / FCS_model_P.DiscreteFilter1_DenCoef[0];

  // Gain: '<S1>/On=1//Off=2 for pitch' incorporates:
  //   DiscreteFilter: '<S131>/Discrete Filter1'

  rtb_On1Off2forpitch = ((FCS_model_P.DiscreteFilter1_NumCoef[0] *
    DiscreteFilter1_tmp + FCS_model_DW.DiscreteFilter1_states[0] *
    FCS_model_P.DiscreteFilter1_NumCoef[1]) +
    FCS_model_DW.DiscreteFilter1_states[1] *
    FCS_model_P.DiscreteFilter1_NumCoef[2]) +
    FCS_model_DW.DiscreteFilter1_states[2] *
    FCS_model_P.DiscreteFilter1_NumCoef[3];

  // SignalConversion generated from: '<S131>/Product2' incorporates:
  //   Gain: '<S131>/RangfinderScaleGain1'

  u0 = FCS_model_P.RangfinderScaleGain1_Gain * rtb_On1Off2forpitch;

  // Product: '<S131>/Product2' incorporates:
  //   Constant: '<S131>/Constant'
  //   Math: '<S131>/Math Function'

  for (i = 0; i < 3; i++) {
    rtb_sincos_o2_po[i] = (rtb_MathFunction[i + 3] *
      FCS_model_P.Constant_Value_e + rtb_MathFunction[i] *
      FCS_model_P.Constant_Value_e) + rtb_MathFunction[i + 6] * u0;
  }

  // End of Product: '<S131>/Product2'

  // Reshape: '<S132>/Reshapey'
  rtb_Reshapey[0] = rtb_sincos_o2_po[2];
  rtb_Reshapey[1] = rtb_Add_k[2];

  // Delay: '<S132>/MemoryX' incorporates:
  //   Constant: '<S132>/X0'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  FCS_model_DW.icLoad = ((arg_in_dashboard->estimators_reset &&
    (FCS_model_PrevZCX.MemoryX_Reset_ZCE != POS_ZCSIG)) || FCS_model_DW.icLoad);
  FCS_model_PrevZCX.MemoryX_Reset_ZCE = arg_in_dashboard->estimators_reset;
  if (FCS_model_DW.icLoad) {
    FCS_model_DW.MemoryX_DSTATE[0] = FCS_model_P.X0_Value[0];
    FCS_model_DW.MemoryX_DSTATE[1] = FCS_model_P.X0_Value[1];
    FCS_model_DW.MemoryX_DSTATE[2] = FCS_model_P.X0_Value[2];
    FCS_model_DW.MemoryX_DSTATE[3] = FCS_model_P.X0_Value[3];
  }

  // Outputs for Enabled SubSystem: '<S158>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S183>/Enable'

  // Outputs for Enabled SubSystem: '<S153>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S181>/Enable'

  // Constant: '<S132>/Enable'
  if (FCS_model_P.Enable_Value) {
    FCS_model_DW.MeasurementUpdate_MODE = true;

    // Product: '<S181>/D[k]*u[k]'
    rtb_sincos_o2_3 = rtb_Add_k[2];

    // Delay: '<S132>/MemoryX' incorporates:
    //   Constant: '<S132>/C'
    //   Product: '<S181>/C[k]*xhat[k|k-1]'

    u0 = FCS_model_DW.MemoryX_DSTATE[1];
    rtb_Add_g_idx_0 = FCS_model_DW.MemoryX_DSTATE[0];
    MemoryX_DSTATE = FCS_model_DW.MemoryX_DSTATE[2];
    MemoryX_DSTATE_0 = FCS_model_DW.MemoryX_DSTATE[3];
    for (i = 0; i < 2; i++) {
      // Product: '<S181>/C[k]*xhat[k|k-1]' incorporates:
      //   Constant: '<S132>/C'
      //   Delay: '<S132>/MemoryX'
      //   Product: '<S183>/Product'

      rtb_Add_g_idx_1 = ((FCS_model_P.C_Value[i + 2] * u0 +
                          FCS_model_P.C_Value[i] * rtb_Add_g_idx_0) +
                         FCS_model_P.C_Value[i + 4] * MemoryX_DSTATE) +
        FCS_model_P.C_Value[i + 6] * MemoryX_DSTATE_0;
      rtb_Product_c[i] = rtb_Add_g_idx_1;

      // Sum: '<S181>/Sum' incorporates:
      //   Constant: '<S132>/D'
      //   Product: '<S181>/C[k]*xhat[k|k-1]'
      //   Product: '<S181>/D[k]*u[k]'
      //   Sum: '<S181>/Add1'

      IIRgyroz_tmp[i] = rtb_Reshapey[i] - (FCS_model_P.D_Value[i] *
        rtb_sincos_o2_3 + rtb_Add_g_idx_1);
    }

    FCS_model_DW.EnabledSubsystem_MODE = true;

    // Sum: '<S183>/Add1' incorporates:
    //   Product: '<S183>/Product'
    //   Reshape: '<S132>/Reshapey'

    u0 = rtb_sincos_o2_po[2] - rtb_Product_c[0];
    rtb_Add_g_idx_0 = rtb_Add_k[2] - rtb_Product_c[1];

    // Product: '<S181>/Product3' incorporates:
    //   Constant: '<S134>/KalmanGainL'

    rtb_Add_g_idx_1 = IIRgyroz_tmp[1];
    MemoryX_DSTATE = IIRgyroz_tmp[0];
    for (i = 0; i < 4; i++) {
      // Product: '<S181>/Product3' incorporates:
      //   Constant: '<S134>/KalmanGainL'

      FCS_model_B.Product3[i] = FCS_model_P.KalmanGainL_Value[i + 4] *
        rtb_Add_g_idx_1 + FCS_model_P.KalmanGainL_Value[i] * MemoryX_DSTATE;

      // Product: '<S183>/Product2' incorporates:
      //   Constant: '<S134>/KalmanGainM'

      FCS_model_B.Product2[i] = FCS_model_P.KalmanGainM_Value[i + 4] *
        rtb_Add_g_idx_0 + FCS_model_P.KalmanGainM_Value[i] * u0;
    }
  } else {
    if (FCS_model_DW.MeasurementUpdate_MODE) {
      // Disable for Product: '<S181>/Product3' incorporates:
      //   Outport: '<S181>/L*(y[k]-yhat[k|k-1])'

      FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_DW.MeasurementUpdate_MODE = false;
    }

    if (FCS_model_DW.EnabledSubsystem_MODE) {
      // Disable for Product: '<S183>/Product2' incorporates:
      //   Outport: '<S183>/deltax'

      FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0_k;
      FCS_model_DW.EnabledSubsystem_MODE = false;
    }
  }

  // End of Constant: '<S132>/Enable'
  // End of Outputs for SubSystem: '<S153>/MeasurementUpdate'
  // End of Outputs for SubSystem: '<S158>/Enabled Subsystem'

  // Sum: '<S158>/Add' incorporates:
  //   Delay: '<S132>/MemoryX'

  rtb_Add_g_idx_0 = FCS_model_B.Product2[0] + FCS_model_DW.MemoryX_DSTATE[0];

  // Product: '<S29>/Product' incorporates:
  //   Constant: '<S29>/Constant'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  u0 = arg_in_dashboard->power * FCS_model_P.Constant_Value_j[0];

  // Sum: '<S158>/Add' incorporates:
  //   Delay: '<S132>/MemoryX'

  rtb_Add_g_idx_1 = FCS_model_B.Product2[1] + FCS_model_DW.MemoryX_DSTATE[1];

  // Product: '<S29>/Product' incorporates:
  //   Constant: '<S29>/Constant'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  MemoryX_DSTATE = arg_in_dashboard->power * FCS_model_P.Constant_Value_j[1];
  MemoryX_DSTATE_0 = arg_in_dashboard->power * FCS_model_P.Constant_Value_j[2];
  rtb_sincos_o2_3 = arg_in_dashboard->power * FCS_model_P.Constant_Value_j[3];

  // SignalConversion generated from: '<S131>/Product1' incorporates:
  //   Constant: '<S32>/Constant'

  rtb_Saturation = FCS_model_P.Constant_Value_c1[0];
  rtb_K_i = FCS_model_P.Constant_Value_c1[1];

  // Product: '<S131>/Product1' incorporates:
  //   Concatenate: '<S184>/Vector Concatenate'
  //   SignalConversion generated from: '<S131>/Product1'

  for (i = 0; i < 3; i++) {
    rtb_sincos_o2_po[i] = (rtb_VectorConcatenate[i + 3] * rtb_K_i +
      rtb_VectorConcatenate[i] * rtb_Saturation) + rtb_VectorConcatenate[i + 6] *
      rtb_Add_g_idx_1;
  }

  // End of Product: '<S131>/Product1'

  // Delay: '<S42>/MemoryX' incorporates:
  //   Constant: '<S42>/X0'

  if (FCS_model_DW.icLoad_n) {
    FCS_model_DW.MemoryX_DSTATE_o[0] = FCS_model_P.X0_Value_h[0];
    FCS_model_DW.MemoryX_DSTATE_o[1] = FCS_model_P.X0_Value_h[1];
  }

  for (cff = 0; cff < 2; cff++) {
    // DiscreteFilter: '<S41>/IIRgyroz'
    memOffset = cff * 5;
    rtb_Add_g_idx_1 = inverseIMU_gain[cff + 3];
    for (i = 0; i < 5; i++) {
      rtb_Add_g_idx_1 -= FCS_model_P.IIRgyroz_DenCoef[i + 1] *
        FCS_model_DW.IIRgyroz_states[memOffset + i];
    }

    rtb_Add_g_idx_1 /= FCS_model_P.IIRgyroz_DenCoef[0];
    IIRgyroz_tmp[cff] = rtb_Add_g_idx_1;
    rtb_Add_g_idx_1 *= FCS_model_P.IIRgyroz_NumCoef[0];
    for (i = 0; i < 5; i++) {
      rtb_Add_g_idx_1 += FCS_model_P.IIRgyroz_NumCoef[i + 1] *
        FCS_model_DW.IIRgyroz_states[memOffset + i];
    }

    // SampleTimeMath: '<S49>/TSamp' incorporates:
    //   DiscreteFilter: '<S41>/IIRgyroz'
    //
    //  About '<S49>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )
    //
    rtb_Add_g_idx_1 *= FCS_model_P.TSamp_WtEt;
    rtb_Reshapey[cff] = rtb_Add_g_idx_1;

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

    rtb_Akxhatkk1[cff] = rtb_Add_g_idx_1 - FCS_model_DW.UD_DSTATE[cff];
  }

  // Abs: '<S41>/Abs' incorporates:
  //   Abs: '<S41>/Abs4'

  rtb_Add_g_idx_1 = std::abs(inverseIMU_gain[3]);

  // Abs: '<S41>/Abs1' incorporates:
  //   Abs: '<S41>/Abs5'

  rtb_Saturation = std::abs(inverseIMU_gain[4]);

  // Logic: '<S41>/Logical Operator3' incorporates:
  //   Abs: '<S41>/Abs'
  //   Abs: '<S41>/Abs1'
  //   Abs: '<S41>/Abs2'
  //   Abs: '<S41>/Abs3'
  //   Abs: '<S41>/Abs6'
  //   Abs: '<S41>/Abs7'
  //   Abs: '<S41>/Abs8'
  //   Abs: '<S41>/Abs9'
  //   Constant: '<S50>/Constant'
  //   Constant: '<S51>/Constant'
  //   Constant: '<S52>/Constant'
  //   Constant: '<S53>/Constant'
  //   Constant: '<S54>/Constant'
  //   Constant: '<S55>/Constant'
  //   Constant: '<S56>/Constant'
  //   Constant: '<S57>/Constant'
  //   Constant: '<S58>/Constant'
  //   Constant: '<S59>/Constant'
  //   Constant: '<S60>/Constant'
  //   Delay: '<S36>/Delay'
  //   DiscreteTransferFcn: '<S185>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'
  //   Inport: '<Root>/in_parameters'
  //   Logic: '<S41>/Logical Operator'
  //   Logic: '<S41>/Logical Operator1'
  //   Logic: '<S41>/Logical Operator2'
  //   RelationalOperator: '<S50>/Compare'
  //   RelationalOperator: '<S51>/Compare'
  //   RelationalOperator: '<S52>/Compare'
  //   RelationalOperator: '<S53>/Compare'
  //   RelationalOperator: '<S54>/Compare'
  //   RelationalOperator: '<S55>/Compare'
  //   RelationalOperator: '<S56>/Compare'
  //   RelationalOperator: '<S57>/Compare'
  //   RelationalOperator: '<S58>/Compare'
  //   RelationalOperator: '<S59>/Compare'
  //   RelationalOperator: '<S60>/Compare'
  //   Sum: '<S41>/Add'

  rtb_LogicalOperator3 = ((((std::abs(numAccum) <= FCS_model_P.maxp_const) &&
    (std::abs(rtb_AvoidDividebyZero) <= FCS_model_P.maxq_const) &&
    (rtb_Add_g_idx_1 <= FCS_model_P.maxw1_const) && (rtb_Saturation <=
    FCS_model_P.maxw2_const) && (std::abs(rtb_Akxhatkk1[0]) <=
    FCS_model_P.maxdw1_const) && (std::abs(rtb_Akxhatkk1[1]) <=
    FCS_model_P.maxdw2_const)) || ((rtb_Add_g_idx_1 <= FCS_model_P.maxp2_const) &&
    (rtb_Saturation <= FCS_model_P.maxq2_const))) && (std::abs
    (arg_in_parameters->opticalflow_x - FCS_model_DW.Delay_DSTATE[0]) <=
    FCS_model_P.maxw3_const) && (std::abs(arg_in_parameters->opticalflow_y -
    FCS_model_DW.Delay_DSTATE[1]) <= FCS_model_P.maxw4_const) &&
    (rtb_Add_g_idx_0 <= FCS_model_P.minHeightforOF_const));

  // Logic: '<S123>/Logical Operator' incorporates:
  //   Constant: '<S123>/Constant'
  //   Constant: '<S123>/Time constant'
  //   Constant: '<S126>/Constant'
  //   Constant: '<S127>/Constant'
  //   RelationalOperator: '<S126>/Compare'
  //   RelationalOperator: '<S127>/Compare'
  //   Sum: '<S123>/Sum1'

  rtb_LogicalOperator_b = ((FCS_model_P.LowPassFilterDiscreteorContin_l -
    FCS_model_B.Probe[0] <= FCS_model_P.Constant_Value_o) &&
    (FCS_model_P.LowPassFilterDiscreteorContin_i <
     FCS_model_P.CompareToConstant_const));

  // Gain: '<S115>/K' incorporates:
  //   Inport: '<Root>/in_parameters'

  rtb_Add_g_idx_1 = FCS_model_P.LowPassFilterDiscreteorContinuo *
    arg_in_parameters->opticalflow_x;

  // DiscreteIntegrator: '<S129>/Integrator'
  if (FCS_model_DW.Integrator_IC_LOADING != 0) {
    FCS_model_DW.Integrator_DSTATE = rtb_Add_g_idx_1;
    if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  if (rtb_LogicalOperator_b || (FCS_model_DW.Integrator_PrevResetState != 0)) {
    FCS_model_DW.Integrator_DSTATE = rtb_Add_g_idx_1;
    if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  // End of DiscreteIntegrator: '<S129>/Integrator'

  // Saturate: '<S129>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Saturation_UpperSat) {
    rtb_Saturation = FCS_model_P.Saturation_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Saturation_LowerSat) {
    rtb_Saturation = FCS_model_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = FCS_model_DW.Integrator_DSTATE;
  }

  // End of Saturate: '<S129>/Saturation'

  // Gain: '<S1>/On=1//Off=2 for pitch' incorporates:
  //   Bias: '<S43>/Bias3'
  //   Delay: '<S43>/Delay2'
  //   Gain: '<S43>/Gain5'
  //   Product: '<S43>/Product3'
  //   Sum: '<S43>/Subtract3'

  rtb_On1Off2forpitch = FCS_model_DW.Delay2_DSTATE[0];
  rtb_On1Off2forpitch = (rtb_rangefinder_distance + FCS_model_P.Bias3_Bias) *
    FCS_model_P.Gain5_Gain * (rtb_Saturation - rtb_On1Off2forpitch);

  // Logic: '<S116>/Logical Operator' incorporates:
  //   Constant: '<S116>/Constant'
  //   Constant: '<S116>/Time constant'
  //   Constant: '<S119>/Constant'
  //   Constant: '<S120>/Constant'
  //   RelationalOperator: '<S119>/Compare'
  //   RelationalOperator: '<S120>/Compare'
  //   Sum: '<S116>/Sum1'

  rtb_LogicalOperator_j = ((FCS_model_P.LowPassFilterDiscreteorContin_a -
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

  if (rtb_LogicalOperator_j || (FCS_model_DW.Integrator_PrevResetState_e != 0))
  {
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
  if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Saturation_UpperSat_k) {
    rtb_Saturation_l = FCS_model_P.Saturation_UpperSat_k;
  } else if (FCS_model_DW.Integrator_DSTATE_e <
             FCS_model_P.Saturation_LowerSat_h) {
    rtb_Saturation_l = FCS_model_P.Saturation_LowerSat_h;
  } else {
    rtb_Saturation_l = FCS_model_DW.Integrator_DSTATE_e;
  }

  // End of Saturate: '<S122>/Saturation'

  // Reshape: '<S42>/Reshapey' incorporates:
  //   Bias: '<S43>/Bias2'
  //   Delay: '<S43>/Delay1'
  //   Gain: '<S43>/Gain4'
  //   Product: '<S43>/Product2'
  //   Sum: '<S43>/Subtract2'

  rtb_Akxhatkk1[1] = (rtb_rangefinder_distance + FCS_model_P.Bias2_Bias) *
    FCS_model_P.Gain4_Gain * (rtb_Saturation_l - FCS_model_DW.Delay1_DSTATE[0U]);

  // Outputs for Enabled SubSystem: '<S87>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S113>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.EnabledSubsystem_MODE_g = true;

    // Sum: '<S113>/Add1' incorporates:
    //   Constant: '<S42>/C'
    //   Delay: '<S42>/MemoryX'
    //   Product: '<S113>/Product'
    //   Reshape: '<S42>/Reshapey'

    rtb_Akxhatkk1_idx_0 = rtb_On1Off2forpitch - (FCS_model_P.C_Value_h[0] *
      FCS_model_DW.MemoryX_DSTATE_o[0] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[2]);
    rtb_Akxhatkk1_idx_1 = rtb_Akxhatkk1[1] - (FCS_model_DW.MemoryX_DSTATE_o[0] *
      FCS_model_P.C_Value_h[1] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[3]);

    // Product: '<S113>/Product2' incorporates:
    //   Constant: '<S61>/KalmanGainM'

    FCS_model_B.Product2_c[0] = FCS_model_P.KalmanGainM_Value_e[0] *
      rtb_Akxhatkk1_idx_0 + FCS_model_P.KalmanGainM_Value_e[2] *
      rtb_Akxhatkk1_idx_1;
    FCS_model_B.Product2_c[1] = FCS_model_P.KalmanGainM_Value_e[1] *
      rtb_Akxhatkk1_idx_0 + FCS_model_P.KalmanGainM_Value_e[3] *
      rtb_Akxhatkk1_idx_1;
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

  rtb_Akxhatkk1_idx_0 = FCS_model_B.Product2_c[0] +
    FCS_model_DW.MemoryX_DSTATE_o[0];
  FCS_model_DW.Delay_DSTATE[0] = rtb_Akxhatkk1_idx_0;

  // SignalConversion generated from: '<S35>/Product'
  rtb_sincos_o2_m[0] = rtb_Akxhatkk1_idx_0;

  // Sum: '<S87>/Add' incorporates:
  //   Delay: '<S36>/Delay'
  //   Delay: '<S42>/MemoryX'

  rtb_Akxhatkk1_idx_0 = FCS_model_B.Product2_c[1] +
    FCS_model_DW.MemoryX_DSTATE_o[1];
  FCS_model_DW.Delay_DSTATE[1] = rtb_Akxhatkk1_idx_0;

  // Product: '<S35>/Product' incorporates:
  //   Concatenate: '<S48>/Vector Concatenate'
  //   Math: '<S35>/Math Function'
  //   SignalConversion generated from: '<S35>/Product'

  rtb_Akxhatkk1_idx_1 = rtb_sincos_o2_m[0];
  rtb_sincos_o2_m_0 = rtb_sincos_o2_po[2];
  for (i = 0; i < 3; i++) {
    rtb_sincos_o2_m[i] = (rtb_VectorConcatenate_k[3 * i + 1] *
                          rtb_Akxhatkk1_idx_0 + rtb_VectorConcatenate_k[3 * i] *
                          rtb_Akxhatkk1_idx_1) + rtb_VectorConcatenate_k[3 * i +
      2] * rtb_sincos_o2_m_0;
  }

  // End of Product: '<S35>/Product'

  // Fcn: '<S45>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_Sum1_le;

  // Fcn: '<S45>/Fcn21'
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_tmp_0;

  // Fcn: '<S45>/Fcn31'
  rtb_VectorConcatenate_k[2] = rtb_VectorConcatenate_tmp_1;

  // Fcn: '<S45>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_VectorConcatenate_tmp_2;

  // Fcn: '<S45>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_Saturation_a;

  // Fcn: '<S45>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_VectorConcatenate_tmp;

  // Fcn: '<S45>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_clock;

  // Fcn: '<S45>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_sincos_o2_m_tmp;

  // Fcn: '<S45>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_sincos_o2_tmp;

  // RelationalOperator: '<S44>/Compare' incorporates:
  //   Constant: '<S44>/Constant'

  rtb_Compare_jy = (rtb_Add_g_idx_0 <=
                    FCS_model_P.DeactivateAccelerationIfOFisnot);

  // Logic: '<S40>/Logical Operator' incorporates:
  //   Constant: '<S46>/Constant'
  //   Constant: '<S47>/Constant'
  //   Inport: '<Root>/in_parameters'
  //   RelationalOperator: '<S46>/Compare'
  //   RelationalOperator: '<S47>/Compare'

  rtb_Memory_i = ((arg_in_parameters->opticalflow_x !=
                   FCS_model_P.donotuseaccifopticalflowneverav) ||
                  (arg_in_parameters->opticalflow_y !=
                   FCS_model_P.donotuseaccifopticalflownever_c));

  // Product: '<S40>/Product1' incorporates:
  //   Constant: '<S40>/gravity'

  rtb_clock = FCS_model_P.gravity_Value_a[1];
  rtb_Sum1_le = FCS_model_P.gravity_Value_a[0];
  rtb_Saturation_a = FCS_model_P.gravity_Value_a[2];

  // Sum: '<S40>/Add' incorporates:
  //   Concatenate: '<S48>/Vector Concatenate'
  //   Constant: '<S40>/gravity'
  //   Product: '<S40>/Product1'

  for (i = 0; i < 3; i++) {
    rtb_FIR_IMUaccel_0[i] = rtb_FIR_IMUaccel[i] - ((rtb_VectorConcatenate_k[i +
      3] * rtb_clock + rtb_VectorConcatenate_k[i] * rtb_Sum1_le) +
      rtb_VectorConcatenate_k[i + 6] * rtb_Saturation_a);
  }

  // End of Sum: '<S40>/Add'

  // Product: '<S40>/Product' incorporates:
  //   Gain: '<S40>/gainaccinput'

  rtb_Product_c[0] = FCS_model_P.gainaccinput_Gain * rtb_FIR_IMUaccel_0[0] *
    static_cast<real_T>(rtb_Memory_i) * static_cast<real_T>(rtb_Compare_jy);
  rtb_Product_c[1] = FCS_model_P.gainaccinput_Gain * rtb_FIR_IMUaccel_0[1] *
    static_cast<real_T>(rtb_Memory_i) * static_cast<real_T>(rtb_Compare_jy);

  // Outputs for Enabled SubSystem: '<S80>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S111>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.MeasurementUpdate_MODE_h = true;

    // Sum: '<S111>/Sum' incorporates:
    //   Constant: '<S42>/C'
    //   Constant: '<S42>/D'
    //   Delay: '<S42>/MemoryX'
    //   Product: '<S111>/C[k]*xhat[k|k-1]'
    //   Product: '<S111>/D[k]*u[k]'
    //   Reshape: '<S42>/Reshapey'
    //   Sum: '<S111>/Add1'

    rtb_Akxhatkk1_idx_0 = rtb_On1Off2forpitch - ((FCS_model_P.C_Value_h[0] *
      FCS_model_DW.MemoryX_DSTATE_o[0] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[2]) + (FCS_model_P.D_Value_b[0] * rtb_Product_c[0] +
      rtb_Product_c[1] * FCS_model_P.D_Value_b[2]));
    rtb_Akxhatkk1_idx_1 = rtb_Akxhatkk1[1] - ((FCS_model_DW.MemoryX_DSTATE_o[0] *
      FCS_model_P.C_Value_h[1] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[3]) + (rtb_Product_c[0] * FCS_model_P.D_Value_b[1] +
      rtb_Product_c[1] * FCS_model_P.D_Value_b[3]));

    // Product: '<S111>/Product3' incorporates:
    //   Constant: '<S61>/KalmanGainL'

    FCS_model_B.Product3_d[0] = FCS_model_P.KalmanGainL_Value_f[0] *
      rtb_Akxhatkk1_idx_0 + FCS_model_P.KalmanGainL_Value_f[2] *
      rtb_Akxhatkk1_idx_1;
    FCS_model_B.Product3_d[1] = FCS_model_P.KalmanGainL_Value_f[1] *
      rtb_Akxhatkk1_idx_0 + FCS_model_P.KalmanGainL_Value_f[3] *
      rtb_Akxhatkk1_idx_1;
  } else if (FCS_model_DW.MeasurementUpdate_MODE_h) {
    // Disable for Product: '<S111>/Product3' incorporates:
    //   Outport: '<S111>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_DW.MeasurementUpdate_MODE_h = false;
  }

  // End of Outputs for SubSystem: '<S80>/MeasurementUpdate'

  // Gain: '<S21>/Gain1' incorporates:
  //   Delay: '<S36>/Delay'
  //   DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity'
  //   Gain: '<S21>/Gain3'
  //   Gain: '<S21>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S21>/Subtract'
  //   Sum: '<S21>/Sum1'

  rtb_Saturation_a = ((arg_in_dashboard->ref_x -
                       FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0]) *
                      FCS_model_P.Gain3_Gain_g - FCS_model_P.Gain4_Gain_m *
                      FCS_model_DW.Delay_DSTATE[0]) * FCS_model_P.Gain1_Gain_b;

  // Saturate: '<S21>/Saturation'
  if (rtb_Saturation_a > FCS_model_P.Saturation_UpperSat_d) {
    rtb_Saturation_a = FCS_model_P.Saturation_UpperSat_d;
  } else if (rtb_Saturation_a < FCS_model_P.Saturation_LowerSat_a) {
    rtb_Saturation_a = FCS_model_P.Saturation_LowerSat_a;
  }

  // End of Saturate: '<S21>/Saturation'

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch1_Threshold) {
    // Gain: '<S1>/On=1//Off=2 for pitch'
    rtb_On1Off2forpitch = rtb_Saturation_a;
  } else {
    // Gain: '<S1>/On=1//Off=2 for pitch' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_On1Off2forpitch = arg_in_dashboard->ref_pitch;
  }

  // End of Switch: '<S4>/Switch1'

  // Sum: '<S8>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S185>/Discrete Transfer Fcn'

  rtb_Sum1_a = rtb_On1Off2forpitch - numAccum;

  // DiscreteStateSpace: '<S11>/Internal'
  {
    rtb_On1Off2forpitch = FCS_model_P.Internal_C*FCS_model_DW.Internal_DSTATE;
    rtb_On1Off2forpitch += FCS_model_P.Internal_D*rtb_Sum1_a;
  }

  // Gain: '<S1>/On=1//Off=2 for pitch' incorporates:
  //   Constant: '<S4>/pitch equilibrium'
  //   Gain: '<S4>/Changing of Jyy'
  //   Gain: '<S8>/KDtheta'
  //   Gain: '<S8>/zDtheta'
  //   Sum: '<S4>/Sum1'
  //   Sum: '<S8>/Sum3'

  rtb_On1Off2forpitch = ((FCS_model_P.zDtheta * 7.0 * rtb_On1Off2forpitch -
    rtb_pitchrate) * (FCS_model_P.KDtheta * 1.4) *
    FCS_model_P.ChangingofJyy_Gain + FCS_model_P.pitchequilibrium_Value) *
    FCS_model_P.On1Off2forpitch_Gain;

  // DiscreteStateSpace: '<S17>/Internal'
  {
    rtb_barometer_pressure = (FCS_model_P.Internal_C_j[0])*
      FCS_model_DW.Internal_DSTATE_f[0]
      + (FCS_model_P.Internal_C_j[1])*FCS_model_DW.Internal_DSTATE_f[1];
  }

  // Sum: '<S10>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'

  rtb_Sum1_le = rtb_barometer_pressure - rtb_AvoidDividebyZero;

  // Sum: '<S3>/Sum2' incorporates:
  //   Trigonometry: '<S188>/Trigonometric Function3'

  rtb_barometer_pressure = std::cos(rtb_Subtract);

  // Product: '<S188>/Divide1'
  rtb_clock = rtb_rollrate / rtb_barometer_pressure;

  // Sum: '<S3>/Sum2' incorporates:
  //   Product: '<S188>/Divide2'
  //   Product: '<S188>/Product9'

  rtb_barometer_pressure = rtb_Saturation_p / rtb_barometer_pressure;
  rtb_barometer_pressure *= inverseIMU_gain[5];

  // Sum: '<S188>/Sum2' incorporates:
  //   Product: '<S188>/Product8'

  rtb_clock = rtb_clock * inverseIMU_gain[4] + rtb_barometer_pressure;

  // Sum: '<S3>/Sum2' incorporates:
  //   Constant: '<S4>/yaw equilibrium'
  //   Gain: '<S10>/KDpsi'
  //   Gain: '<S10>/zDpsi'
  //   Gain: '<S1>/On=1//Off=1 for yaw'
  //   Gain: '<S4>/Changing of Jzz'
  //   Sum: '<S10>/Sum3'
  //   Sum: '<S4>/Sum3'

  rtb_barometer_pressure = ((FCS_model_P.zDpsi * 2.0 * rtb_Sum1_le - rtb_clock) *
    (FCS_model_P.KDpsi * 1.3) * FCS_model_P.ChangingofJzz_Gain +
    FCS_model_P.yawequilibrium_Value) * FCS_model_P.On1Off1foryaw_Gain;

  // DiscreteStateSpace: '<S14>/Internal'
  {
    rtb_DiscreteTimeIntegrator_j = (FCS_model_P.Internal_C_n[0])*
      FCS_model_DW.Internal_DSTATE_k[0]
      + (FCS_model_P.Internal_C_n[1])*FCS_model_DW.Internal_DSTATE_k[1];
  }

  // Sum: '<S9>/Sum1'
  rtb_Sum1_le = rtb_DiscreteTimeIntegrator_j - FCS_model_DW.Memory_PreviousInput;

  // Trigonometry: '<S188>/Trigonometric Function4'
  rtb_Subtract = std::tan(rtb_Subtract);

  // Sum: '<S188>/Sum' incorporates:
  //   Product: '<S188>/Product'
  //   Product: '<S188>/Product1'
  //   Product: '<S188>/Product2'
  //   Product: '<S188>/Product3'

  rtb_rollrate = (rtb_rollrate * rtb_Subtract * inverseIMU_gain[4] +
                  inverseIMU_gain[3]) + rtb_Saturation_p * rtb_Subtract *
    inverseIMU_gain[5];

  // DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S4>/roll equilibrium'
  //   DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  //   Gain: '<S1>/On=1//Off=1 for roll'
  //   Gain: '<S4>/Changing of Jxx'
  //   Gain: '<S9>/kd_rol'
  //   Gain: '<S9>/ki_rol'
  //   Gain: '<S9>/kp_rol'
  //   Sum: '<S4>/Sum2'
  //   Sum: '<S9>/Sum'
  //   Sum: '<S9>/Sum3'

  rtb_DiscreteTimeIntegrator_j = (((FCS_model_P.ki_rol *
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE + FCS_model_P.kp_rol *
    rtb_Sum1_le) - FCS_model_P.kd_rol * rtb_rollrate) *
    FCS_model_P.ChangingofJxx_Gain + FCS_model_P.rollequilibrium_Value) *
    FCS_model_P.On1Off1forroll_Gain;

  // Gain: '<S22>/Gain1' incorporates:
  //   Delay: '<S36>/Delay'
  //   DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity'
  //   Gain: '<S22>/Gain3'
  //   Gain: '<S22>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S22>/Subtract'
  //   Sum: '<S22>/Sum1'

  rtb_Saturation_p = ((arg_in_dashboard->ref_y -
                       FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1]) *
                      FCS_model_P.Gain3_Gain_i - FCS_model_P.Gain4_Gain_h *
                      FCS_model_DW.Delay_DSTATE[1]) * FCS_model_P.Gain1_Gain_i;

  // Saturate: '<S22>/Saturation'
  if (rtb_Saturation_p > FCS_model_P.Saturation_UpperSat_ku) {
    rtb_Saturation_p = FCS_model_P.Saturation_UpperSat_ku;
  } else if (rtb_Saturation_p < FCS_model_P.Saturation_LowerSat_j) {
    rtb_Saturation_p = FCS_model_P.Saturation_LowerSat_j;
  }

  // End of Saturate: '<S22>/Saturation'

  // Saturate: '<S29>/Saturation'
  if (u0 > FCS_model_P.Vehicle.Motor.maxLimit) {
    u0 = FCS_model_P.Vehicle.Motor.maxLimit;
  } else if (u0 < FCS_model_P.Vehicle.Motor.minLimit) {
    u0 = FCS_model_P.Vehicle.Motor.minLimit;
  }

  // Outport: '<Root>/out_controllers' incorporates:
  //   Inport: '<Root>/in_dashboard'
  //   Product: '<S29>/Product1'
  //   Saturate: '<S29>/Saturation'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  arg_out_controllers->motor1 = u0 * static_cast<real_T>
    (arg_in_dashboard->master_switch);

  // Saturate: '<S29>/Saturation'
  if (MemoryX_DSTATE > FCS_model_P.Vehicle.Motor.maxLimit) {
    MemoryX_DSTATE = FCS_model_P.Vehicle.Motor.maxLimit;
  } else if (MemoryX_DSTATE < FCS_model_P.Vehicle.Motor.minLimit) {
    MemoryX_DSTATE = FCS_model_P.Vehicle.Motor.minLimit;
  }

  // Outport: '<Root>/out_controllers' incorporates:
  //   Inport: '<Root>/in_dashboard'
  //   Product: '<S29>/Product1'
  //   Saturate: '<S29>/Saturation'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  arg_out_controllers->motor2 = MemoryX_DSTATE * static_cast<real_T>
    (arg_in_dashboard->master_switch);

  // Saturate: '<S29>/Saturation'
  if (MemoryX_DSTATE_0 > FCS_model_P.Vehicle.Motor.maxLimit) {
    MemoryX_DSTATE_0 = FCS_model_P.Vehicle.Motor.maxLimit;
  } else if (MemoryX_DSTATE_0 < FCS_model_P.Vehicle.Motor.minLimit) {
    MemoryX_DSTATE_0 = FCS_model_P.Vehicle.Motor.minLimit;
  }

  // Outport: '<Root>/out_controllers' incorporates:
  //   Inport: '<Root>/in_dashboard'
  //   Product: '<S29>/Product1'
  //   Saturate: '<S29>/Saturation'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  arg_out_controllers->motor3 = MemoryX_DSTATE_0 * static_cast<real_T>
    (arg_in_dashboard->master_switch);

  // Saturate: '<S29>/Saturation'
  if (rtb_sincos_o2_3 > FCS_model_P.Vehicle.Motor.maxLimit) {
    rtb_sincos_o2_3 = FCS_model_P.Vehicle.Motor.maxLimit;
  } else if (rtb_sincos_o2_3 < FCS_model_P.Vehicle.Motor.minLimit) {
    rtb_sincos_o2_3 = FCS_model_P.Vehicle.Motor.minLimit;
  }

  // Outport: '<Root>/out_controllers' incorporates:
  //   BusCreator generated from: '<Root>/out_controllers'
  //   Constant: '<S1>/Constant'
  //   Constant: '<S6>/Constant'
  //   Gain: '<S1>/On=1//Off=0 for thrust'
  //   Inport: '<Root>/in_dashboard'
  //   Product: '<S29>/Product1'
  //   Saturate: '<S29>/Saturation'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  arg_out_controllers->motor4 = rtb_sincos_o2_3 * static_cast<real_T>
    (arg_in_dashboard->master_switch);
  arg_out_controllers->cmd_thrust = FCS_model_P.On1Off0forthrust_Gain *
    FCS_model_P.Constant_Value_f;
  arg_out_controllers->cmd_tau_roll = rtb_barometer_pressure;
  arg_out_controllers->cmd_tau_pitch = rtb_On1Off2forpitch;
  arg_out_controllers->cmd_tau_yaw = rtb_DiscreteTimeIntegrator_j;
  arg_out_controllers->cmd_roll = rtb_Saturation_a;
  arg_out_controllers->cmd_pitch = rtb_Saturation_p;
  arg_out_controllers->cmd_yaw = FCS_model_P.Constant_Value_e2;

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch2_Threshold) {
    // Switch: '<S4>/Switch2'
    rtb_Switch2 = rtb_Saturation_p;
  } else {
    // Switch: '<S4>/Switch2' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Switch2 = arg_in_dashboard->ref_roll;
  }

  // End of Switch: '<S4>/Switch2'

  // DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
  rtb_DiscreteTimeIntegrator_j = FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o;

  // Sum: '<S3>/Sum2' incorporates:
  //   Gain: '<S31>/Gain'

  rtb_barometer_pressure = FCS_model_P.Gain_Gain_h *
    rtb_DiscreteTimeIntegrator_j;

  // Outport: '<Root>/out_estimators' incorporates:
  //   BusCreator generated from: '<Root>/out_estimators'
  //   Delay: '<S36>/Delay'
  //   DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity'
  //   DiscreteTransferFcn: '<S185>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn'

  arg_out_estimators->orient_roll = FCS_model_DW.Memory_PreviousInput;
  arg_out_estimators->orient_pitch = numAccum;
  arg_out_estimators->orient_yaw = rtb_AvoidDividebyZero;
  arg_out_estimators->orient_rate_roll = rtb_rollrate;
  arg_out_estimators->orient_rate_pitch = rtb_pitchrate;
  arg_out_estimators->orient_rate_yaw = rtb_clock;
  arg_out_estimators->pos_x = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0];
  arg_out_estimators->pos_y = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1];
  arg_out_estimators->pos_z = rtb_Add_g_idx_0;
  arg_out_estimators->pos_dx = FCS_model_DW.Delay_DSTATE[0];
  arg_out_estimators->pos_dy = FCS_model_DW.Delay_DSTATE[1];
  arg_out_estimators->pos_dz = rtb_sincos_o2_po[2];
  arg_out_estimators->battery_SOC = rtb_barometer_pressure;

  // MinMax: '<S116>/Max' incorporates:
  //   Constant: '<S116>/Time constant'

  if ((FCS_model_B.Probe_c[0] >= FCS_model_P.LowPassFilterDiscreteorContin_a) ||
      rtIsNaN(FCS_model_P.LowPassFilterDiscreteorContin_a)) {
    rtb_clock = FCS_model_B.Probe_c[0];
  } else {
    rtb_clock = FCS_model_P.LowPassFilterDiscreteorContin_a;
  }

  // End of MinMax: '<S116>/Max'

  // Fcn: '<S116>/Avoid Divide by Zero'
  rtb_AvoidDividebyZero = static_cast<real_T>(rtb_clock == 0.0) *
    2.2204460492503131e-16 + rtb_clock;

  // MinMax: '<S123>/Max' incorporates:
  //   Constant: '<S123>/Time constant'

  if ((FCS_model_B.Probe[0] >= FCS_model_P.LowPassFilterDiscreteorContin_l) ||
      rtIsNaN(FCS_model_P.LowPassFilterDiscreteorContin_l)) {
    rtb_clock = FCS_model_B.Probe[0];
  } else {
    rtb_clock = FCS_model_P.LowPassFilterDiscreteorContin_l;
  }

  // End of MinMax: '<S123>/Max'

  // Logic: '<S24>/OR' incorporates:
  //   Constant: '<S20>/Constant'
  //   Inport: '<Root>/in_dashboard'
  //   Memory: '<S24>/Memory'
  //   RelationalOperator: '<S20>/GreaterThan'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  FCS_model_DW.Memory_PreviousInput_j = ((static_cast<real_T>
    (arg_in_dashboard->master_switch) >= FCS_model_P.Constant_Value_i) ||
    FCS_model_DW.Memory_PreviousInput_j);

  // Product: '<S24>/Divide' incorporates:
  //   Constant: '<S24>/cycle_time'
  //   Constant: '<S24>/signal_max'
  //   Gain: '<S24>/Gain'

  rtb_Subtract = FCS_model_P.signal_max_Value / (FCS_model_P.Gain_Gain_n *
    FCS_model_P.cycle_time_Value);

  // Chart: '<S24>/takeoff_acceleration' incorporates:
  //   Constant: '<S24>/Ts'
  //   Constant: '<S24>/signal_max'

  if (FCS_model_DW.is_active_c1_FCS_model == 0) {
    FCS_model_DW.is_active_c1_FCS_model = 1U;
    FCS_model_DW.is_c1_FCS_model = FCS_model_IN_waiting4trigger;
    FCS_model_B.signal_out = 0.0;
  } else {
    switch (FCS_model_DW.is_c1_FCS_model) {
     case FCS_model_IN_decreasing:
      if (FCS_model_B.signal_out > 0.0) {
        FCS_model_DW.is_c1_FCS_model = FCS_model_IN_decreasing;
        FCS_model_B.signal_out -= FCS_model_P.Ts * rtb_Subtract;
      } else if (FCS_model_B.signal_out <= 0.0) {
        FCS_model_DW.is_c1_FCS_model = FCS_model_IN_done;
        FCS_model_B.signal_out = 0.0;
      }
      break;

     case FCS_model_IN_done:
      FCS_model_B.signal_out = 0.0;
      break;

     case FCS_model_IN_increasing:
      if (FCS_model_B.signal_out < FCS_model_P.signal_max_Value) {
        FCS_model_DW.is_c1_FCS_model = FCS_model_IN_increasing;
        FCS_model_B.signal_out += FCS_model_P.Ts * rtb_Subtract;
      } else if (FCS_model_B.signal_out >= FCS_model_P.signal_max_Value) {
        FCS_model_DW.is_c1_FCS_model = FCS_model_IN_decreasing;
        FCS_model_B.signal_out -= FCS_model_P.Ts * rtb_Subtract;
      } else {
        FCS_model_B.signal_out += FCS_model_P.Ts * rtb_Subtract;
      }
      break;

     default:
      // case IN_waiting4trigger:
      if (FCS_model_DW.Memory_PreviousInput_j) {
        FCS_model_DW.is_c1_FCS_model = FCS_model_IN_increasing;
        FCS_model_B.signal_out += FCS_model_P.Ts * rtb_Subtract;
      } else {
        FCS_model_B.signal_out = 0.0;
      }
      break;
    }
  }

  // End of Chart: '<S24>/takeoff_acceleration'

  // Sum: '<S3>/Sum2' incorporates:
  //   Constant: '<Root>/Constant'
  //   Inport: '<Root>/in_parameters'

  rtb_barometer_pressure = arg_in_parameters->barometer_pressure -
    FCS_model_P.sensorCalibrationData[6];

  // Outport: '<Root>/out_sensors' incorporates:
  //   BusCreator generated from: '<Root>/out_sensors'
  //   DigitalClock: '<S3>/Digital Clock'
  //   DiscreteFir: '<S3>/FIR_IMUaccel'

  arg_out_sensors->clock = (((&FCS_model_M)->Timing.clockTick0) * 0.0025);
  arg_out_sensors->accelerometer_x = rtb_FIR_IMUaccel[0];
  arg_out_sensors->accelerometer_y = rtb_FIR_IMUaccel[1];
  arg_out_sensors->accelerometer_z = acc1;
  arg_out_sensors->gyroscope_x = inverseIMU_gain[3];
  arg_out_sensors->gyroscope_y = inverseIMU_gain[4];
  arg_out_sensors->gyroscope_z = inverseIMU_gain[5];
  arg_out_sensors->barometer_pressure = rtb_barometer_pressure;
  arg_out_sensors->rangefinder_distance = rtb_rangefinder_distance;

  // SignalConversion generated from: '<Root>/in_dashboard' incorporates:
  //   Inport: '<Root>/in_dashboard'

  rtb_ref_yaw = arg_in_dashboard->ref_yaw;

  // Update for DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn' incorporates:
  //   Gain: '<S186>/Gain'
  //   Sum: '<S186>/Sum'

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
  FCS_model_DW.FIR_IMUaccel_states[FCS_model_DW.FIR_IMUaccel_circBuf] =
    inverseIMU_gain[0];
  FCS_model_DW.FIR_IMUaccel_states[FCS_model_DW.FIR_IMUaccel_circBuf + 5] =
    inverseIMU_gain[1];
  FCS_model_DW.FIR_IMUaccel_states[FCS_model_DW.FIR_IMUaccel_circBuf + 10] =
    inverseIMU_gain[2];

  // End of Update for DiscreteFir: '<S3>/FIR_IMUaccel'

  // Update for DiscreteTransferFcn: '<S185>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states_a = DiscreteTransferFcn_tmp;

  // Update for DiscreteFilter: '<S131>/Discrete Filter1'
  FCS_model_DW.DiscreteFilter1_states[2] = FCS_model_DW.DiscreteFilter1_states[1];
  FCS_model_DW.DiscreteFilter1_states[1] = FCS_model_DW.DiscreteFilter1_states[0];
  FCS_model_DW.DiscreteFilter1_states[0] = DiscreteFilter1_tmp;

  // Update for Delay: '<S132>/MemoryX'
  FCS_model_DW.icLoad = false;

  // Delay: '<S132>/MemoryX' incorporates:
  //   Constant: '<S132>/A'
  //   Product: '<S153>/A[k]*xhat[k|k-1]'

  u0 = FCS_model_DW.MemoryX_DSTATE[1];
  rtb_Add_g_idx_0 = FCS_model_DW.MemoryX_DSTATE[0];
  MemoryX_DSTATE = FCS_model_DW.MemoryX_DSTATE[2];
  MemoryX_DSTATE_0 = FCS_model_DW.MemoryX_DSTATE[3];

  // Product: '<S153>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S132>/A'
  //   Delay: '<S132>/MemoryX'

  for (i = 0; i < 4; i++) {
    tmp[i] = ((FCS_model_P.A_Value[i + 4] * u0 + FCS_model_P.A_Value[i] *
               rtb_Add_g_idx_0) + FCS_model_P.A_Value[i + 8] * MemoryX_DSTATE) +
      FCS_model_P.A_Value[i + 12] * MemoryX_DSTATE_0;
  }

  // Update for Delay: '<S132>/MemoryX' incorporates:
  //   Constant: '<S132>/B'
  //   Product: '<S153>/B[k]*u[k]'
  //   Product: '<S181>/Product3'
  //   Sum: '<S153>/Add'

  FCS_model_DW.MemoryX_DSTATE[0] = (FCS_model_P.B_Value[0] * rtb_Add_k[2] + tmp
    [0]) + FCS_model_B.Product3[0];
  FCS_model_DW.MemoryX_DSTATE[1] = (FCS_model_P.B_Value[1] * rtb_Add_k[2] + tmp
    [1]) + FCS_model_B.Product3[1];
  FCS_model_DW.MemoryX_DSTATE[2] = (FCS_model_P.B_Value[2] * rtb_Add_k[2] + tmp
    [2]) + FCS_model_B.Product3[2];
  FCS_model_DW.MemoryX_DSTATE[3] = (rtb_Add_k[2] * FCS_model_P.B_Value[3] + tmp
    [3]) + FCS_model_B.Product3[3];

  // Update for Delay: '<S42>/MemoryX'
  FCS_model_DW.icLoad_n = false;

  // Product: '<S80>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S42>/A'
  //   Delay: '<S42>/MemoryX'

  tmp_0[0] = FCS_model_P.A_Value_p[0] * FCS_model_DW.MemoryX_DSTATE_o[0] +
    FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.A_Value_p[2];

  // Product: '<S80>/B[k]*u[k]' incorporates:
  //   Constant: '<S42>/B'

  rtb_Akxhatkk1[0] = FCS_model_P.B_Value_p[0] * rtb_Product_c[0] +
    rtb_Product_c[1] * FCS_model_P.B_Value_p[2];

  // Product: '<S80>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S42>/A'
  //   Delay: '<S42>/MemoryX'

  tmp_0[1] = FCS_model_DW.MemoryX_DSTATE_o[0] * FCS_model_P.A_Value_p[1] +
    FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.A_Value_p[3];

  // Product: '<S80>/B[k]*u[k]' incorporates:
  //   Constant: '<S42>/B'

  rtb_Akxhatkk1[1] = rtb_Product_c[0] * FCS_model_P.B_Value_p[1] +
    rtb_Product_c[1] * FCS_model_P.B_Value_p[3];
  for (cff = 0; cff < 2; cff++) {
    // Update for Delay: '<S42>/MemoryX' incorporates:
    //   Sum: '<S80>/Add'

    FCS_model_DW.MemoryX_DSTATE_o[cff] = (rtb_Akxhatkk1[cff] + tmp_0[cff]) +
      FCS_model_B.Product3_d[cff];

    // Update for DiscreteFilter: '<S41>/IIRgyroz'
    memOffset = cff * 5;
    FCS_model_DW.IIRgyroz_states[memOffset + 4] =
      FCS_model_DW.IIRgyroz_states[memOffset + 3];
    FCS_model_DW.IIRgyroz_states[memOffset + 3] =
      FCS_model_DW.IIRgyroz_states[memOffset + 2];
    FCS_model_DW.IIRgyroz_states[memOffset + 2] =
      FCS_model_DW.IIRgyroz_states[memOffset + 1];
    FCS_model_DW.IIRgyroz_states[memOffset + 1] =
      FCS_model_DW.IIRgyroz_states[memOffset];
    FCS_model_DW.IIRgyroz_states[memOffset] = IIRgyroz_tmp[cff];

    // Update for UnitDelay: '<S49>/UD'
    //
    //  Block description for '<S49>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[cff] = rtb_Reshapey[cff];
  }

  // Update for DiscreteIntegrator: '<S129>/Integrator' incorporates:
  //   Fcn: '<S123>/Avoid Divide by Zero'
  //   Product: '<S115>/1//T'
  //   Sum: '<S115>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING = 0U;
  FCS_model_DW.Integrator_DSTATE += 1.0 / (static_cast<real_T>(rtb_clock == 0.0)
    * 2.2204460492503131e-16 + rtb_clock) * (rtb_Add_g_idx_1 - rtb_Saturation) *
    FCS_model_P.Integrator_gainval;
  if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Integrator_UpperSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Integrator_LowerSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
  }

  FCS_model_DW.Integrator_PrevResetState = static_cast<int8_T>
    (rtb_LogicalOperator_b);

  // End of Update for DiscreteIntegrator: '<S129>/Integrator'

  // Update for Delay: '<S43>/Delay2'
  for (i = 0; i < 39; i++) {
    FCS_model_DW.Delay2_DSTATE[i] = FCS_model_DW.Delay2_DSTATE[i + 1];
  }

  FCS_model_DW.Delay2_DSTATE[39] = inverseIMU_gain[3];

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

  FCS_model_DW.Integrator_PrevResetState_e = static_cast<int8_T>
    (rtb_LogicalOperator_j);

  // End of Update for DiscreteIntegrator: '<S122>/Integrator'

  // Update for Delay: '<S43>/Delay1'
  for (i = 0; i < 39; i++) {
    FCS_model_DW.Delay1_DSTATE[i] = FCS_model_DW.Delay1_DSTATE[i + 1];
  }

  FCS_model_DW.Delay1_DSTATE[39] = inverseIMU_gain[4];

  // End of Update for Delay: '<S43>/Delay1'

  // Update for DiscreteIntegrator: '<S35>/SimplyIntegrateVelocity'
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval * rtb_sincos_o2_m[0];
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval * rtb_sincos_o2_m[1];

  // Update for DiscreteStateSpace: '<S11>/Internal'
  {
    real_T xnew[1];
    xnew[0] = FCS_model_P.Internal_A*FCS_model_DW.Internal_DSTATE;
    xnew[0] += FCS_model_P.Internal_B*rtb_Sum1_a;
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE, xnew,
                       sizeof(real_T)*1);
  }

  // Update for DiscreteStateSpace: '<S17>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_l[0])*FCS_model_DW.Internal_DSTATE_f[0]
      + (FCS_model_P.Internal_A_l[1])*FCS_model_DW.Internal_DSTATE_f[1];
    xnew[0] += FCS_model_P.Internal_B_e*rtb_ref_yaw;
    xnew[1] = (FCS_model_P.Internal_A_l[2])*FCS_model_DW.Internal_DSTATE_f[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_f[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  FCS_model_DW.DiscreteTimeIntegrator_DSTATE +=
    FCS_model_P.DiscreteTimeIntegrator_gainval * rtb_Sum1_le;

  // Update for DiscreteStateSpace: '<S14>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_d[0])*FCS_model_DW.Internal_DSTATE_k[0]
      + (FCS_model_P.Internal_A_d[1])*FCS_model_DW.Internal_DSTATE_k[1];
    xnew[0] += FCS_model_P.Internal_B_g*rtb_Switch2;
    xnew[1] = (FCS_model_P.Internal_A_d[2])*FCS_model_DW.Internal_DSTATE_k[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_k[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/in_parameters'

  FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o +=
    FCS_model_P.DiscreteTimeIntegrator_gainva_i *
    arg_in_parameters->battery_current;

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

    // Start for Probe: '<S123>/Probe'
    FCS_model_B.Probe[0] = 0.0025;
    FCS_model_B.Probe[1] = 0.0;

    // Start for Probe: '<S116>/Probe'
    FCS_model_B.Probe_c[0] = 0.0025;
    FCS_model_B.Probe_c[1] = 0.0;
    FCS_model_PrevZCX.MemoryX_Reset_ZCE = POS_ZCSIG;

    // InitializeConditions for DiscreteTransferFcn: '<S186>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_states =
      FCS_model_P.DiscreteTransferFcn_InitialSt_b;

    // InitializeConditions for DiscreteFir: '<S3>/FIR_IMUaccel'
    for (i = 0; i < 15; i++) {
      FCS_model_DW.FIR_IMUaccel_states[i] =
        FCS_model_P.FIR_IMUaccel_InitialStates;
    }

    // End of InitializeConditions for DiscreteFir: '<S3>/FIR_IMUaccel'

    // InitializeConditions for DiscreteTransferFcn: '<S185>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_states_a =
      FCS_model_P.DiscreteTransferFcn_InitialSt_e;

    // InitializeConditions for Merge: '<S189>/Merge1' incorporates:
    //   Memory: '<S33>/Memory'

    FCS_model_DW.Memory_PreviousInput = FCS_model_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteFilter: '<S131>/Discrete Filter1'
    FCS_model_DW.DiscreteFilter1_states[0] =
      FCS_model_P.DiscreteFilter1_InitialStates;
    FCS_model_DW.DiscreteFilter1_states[1] =
      FCS_model_P.DiscreteFilter1_InitialStates;
    FCS_model_DW.DiscreteFilter1_states[2] =
      FCS_model_P.DiscreteFilter1_InitialStates;

    // InitializeConditions for Delay: '<S132>/MemoryX'
    FCS_model_DW.icLoad = true;

    // InitializeConditions for Delay: '<S42>/MemoryX'
    FCS_model_DW.icLoad_n = true;

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

    // InitializeConditions for DiscreteStateSpace: '<S11>/Internal'
    FCS_model_DW.Internal_DSTATE = FCS_model_P.Internal_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S17>/Internal'
    FCS_model_DW.Internal_DSTATE_f[0] = FCS_model_P.Internal_InitialCondition_a;
    FCS_model_DW.Internal_DSTATE_f[1] = FCS_model_P.Internal_InitialCondition_a;

    // InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' 
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE =
      FCS_model_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for DiscreteStateSpace: '<S14>/Internal'
    FCS_model_DW.Internal_DSTATE_k[0] = FCS_model_P.Internal_InitialCondition_h;
    FCS_model_DW.Internal_DSTATE_k[1] = FCS_model_P.Internal_InitialCondition_h;

    // InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' 
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o =
      FCS_model_P.DiscreteTimeIntegrator_IC_p;

    // InitializeConditions for Logic: '<S24>/OR' incorporates:
    //   Memory: '<S24>/Memory'

    FCS_model_DW.Memory_PreviousInput_j = FCS_model_P.Memory_InitialCondition_h;

    // SystemInitialize for IfAction SubSystem: '<S189>/If Action Subsystem'
    // InitializeConditions for DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn' 
    FCS_model_DW.DiscreteTransferFcn_states_p =
      FCS_model_P.DiscreteTransferFcn_InitialStat;

    // End of SystemInitialize for SubSystem: '<S189>/If Action Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S153>/MeasurementUpdate'
    // SystemInitialize for Product: '<S181>/Product3' incorporates:
    //   Outport: '<S181>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S153>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S158>/Enabled Subsystem'
    // SystemInitialize for Product: '<S183>/Product2' incorporates:
    //   Outport: '<S183>/deltax'

    FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;

    // End of SystemInitialize for SubSystem: '<S158>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S153>/MeasurementUpdate'
    // SystemInitialize for Product: '<S181>/Product3' incorporates:
    //   Outport: '<S181>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S153>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S158>/Enabled Subsystem'
    // SystemInitialize for Product: '<S183>/Product2' incorporates:
    //   Outport: '<S183>/deltax'

    FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;

    // End of SystemInitialize for SubSystem: '<S158>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S153>/MeasurementUpdate'
    // SystemInitialize for Product: '<S181>/Product3' incorporates:
    //   Outport: '<S181>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S153>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S158>/Enabled Subsystem'
    // SystemInitialize for Product: '<S183>/Product2' incorporates:
    //   Outport: '<S183>/deltax'

    FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0_k;

    // End of SystemInitialize for SubSystem: '<S158>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S153>/MeasurementUpdate'
    // SystemInitialize for Product: '<S181>/Product3' incorporates:
    //   Outport: '<S181>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S153>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S158>/Enabled Subsystem'
    // SystemInitialize for Product: '<S183>/Product2' incorporates:
    //   Outport: '<S183>/deltax'

    FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0_k;

    // End of SystemInitialize for SubSystem: '<S158>/Enabled Subsystem'

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
