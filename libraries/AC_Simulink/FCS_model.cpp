//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.216
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Aug 13 18:22:23 2025
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
#include <cstring>
#include "FCS_model_private.h"
#include "rt_defines.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Named constants for Chart: '<S27>/takeoff_acceleration'
const uint8_T FCS_model_IN_decreasing{ 1U };

const uint8_T FCS_model_IN_done{ 2U };

const uint8_T FCS_model_IN_increasing{ 3U };

const uint8_T FCS_model_IN_waiting4trigger{ 4U };

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else if (std::isinf(u0) && std::isinf(u1)) {
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
  real_T rtb_ref_z;
  real_T rtb_ref_yaw;
  real_T rtb_roll;
  real_T rtb_On1Off0forthrust;
  real_T rtb_clock;
  real_T rtb_pitchrate;
  real_T rtb_MathFunction[9];
  real_T rtb_VectorConcatenate[9];
  real_T rtb_VectorConcatenate_g[9];
  real_T rtb_VectorConcatenate_k[9];
  real_T inverseIMU_gain[6];
  real_T rtb_Sum1_eu[6];
  real_T rtb_Product1_i[4];
  real_T rtb_FIR_IMUaccel[3];
  real_T rtb_FIR_IMUaccel_0[3];
  real_T rtb_Product_k[3];
  real_T rtb_TmpSignalConversionAtProduc[3];
  real_T rtb_sincos_o1[3];
  real_T IIRgyroz_tmp[2];
  real_T rtb_Product_f[2];
  real_T rtb_Reshapey[2];
  real_T rtb_SimplyIntegrateVelocity[2];
  real_T tmp[2];
  real_T DiscreteFilter1_tmp;
  real_T rtb_Add_g_idx_0;
  real_T rtb_Add_g_idx_1;
  real_T rtb_Add_k_idx_1;
  real_T rtb_Add_k_idx_2;
  real_T rtb_AvoidDividebyZero;
  real_T rtb_AvoidDividebyZero_h;
  real_T rtb_Divide;
  real_T rtb_Gain4_l;
  real_T rtb_K_i;
  real_T rtb_On1Off1foryaw;
  real_T rtb_Product1_tmp;
  real_T rtb_Product1_tmp_0;
  real_T rtb_Product1_tmp_1;
  real_T rtb_Saturation;
  real_T rtb_Saturation_a;
  real_T rtb_Saturation_l;
  real_T rtb_Sum1_le;
  real_T rtb_TmpSignalConversionAtProd_0;
  real_T rtb_TmpSignalConversionAtProd_1;
  real_T rtb_TmpSignalConversionAtProd_2;
  real_T rtb_VectorConcatenate_tmp;
  real_T rtb_VectorConcatenate_tmp_0;
  real_T rtb_VectorConcatenate_tmp_1;
  real_T rtb_VectorConcatenate_tmp_2;
  real_T rtb_VectorConcatenate_tmp_3;
  real_T rtb_VectorConcatenate_tmp_4;
  real_T rtb_VectorConcatenate_tmp_tmp;
  real_T rtb_barometer_pressure;
  real_T rtb_rangefinder_distance;
  real_T rtb_rangefinder_distance_tmp;
  real_T rtb_yawrate;
  real_T rtb_zDtheta;
  int32_T cff;
  int32_T denIdx;
  int32_T memOffset;
  boolean_T rtb_Compare_jy;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator_b;
  boolean_T rtb_LogicalOperator_c;
  boolean_T rtb_LogicalOperator_j;

  // Bias: '<S3>/Assuming that calib was done level!' incorporates:
  //   Constant: '<Root>/Constant'

  for (int32_T i{0}; i < 6; i++) {
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

  // If: '<S195>/If1' incorporates:
  //   Constant: '<S37>/Constant'
  //   DataTypeConversion: '<S195>/Data Type Conversion'

  if (static_cast<real32_T>(FCS_model_P.Constant_Value_c) > 0.0F) {
    // Outputs for IfAction SubSystem: '<S195>/If Action Subsystem' incorporates:
    //   ActionPort: '<S197>/Action Port'

    // Merge: '<S195>/Merge1' incorporates:
    //   DiscreteTransferFcn: '<S198>/Discrete Transfer Fcn'

    FCS_model_DW.Memory_PreviousInput = FCS_model_P.DiscreteTransferFcn_NumCoef
      [1] * FCS_model_DW.DiscreteTransferFcn_states_p;

    // Update for DiscreteTransferFcn: '<S198>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S198>/Gain'
    //   Inport: '<Root>/in_parameters'
    //   Sum: '<S198>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_p = ((FCS_model_P.w_c_yaw *
      arg_in_parameters->yaw + inverseIMU_gain[5]) -
      FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_p) /
      FCS_model_P.DiscreteTransferFcn_DenCoef[0];

    // End of Outputs for SubSystem: '<S195>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S195>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S196>/Action Port'

    // Merge: '<S195>/Merge1' incorporates:
    //   Gain: '<S196>/Gain'
    //   Memory: '<S37>/Memory'
    //   Sum: '<S196>/Sum'

    FCS_model_DW.Memory_PreviousInput += FCS_model_P.Ts * inverseIMU_gain[5];

    // End of Outputs for SubSystem: '<S195>/If Action Subsystem3'
  }

  // End of If: '<S195>/If1'

  // DiscreteTransferFcn: '<S191>/Discrete Transfer Fcn'
  rtb_AvoidDividebyZero = FCS_model_P.DiscreteTransferFcn_NumCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn'
  rtb_AvoidDividebyZero_h = FCS_model_P.DiscreteTransferFcn_NumCoef_f[1] *
    FCS_model_DW.DiscreteTransferFcn_states_j;

  // SignalConversion generated from: '<S42>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S191>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn'

  rtb_sincos_o1[0] = FCS_model_DW.Memory_PreviousInput;
  rtb_sincos_o1[1] = rtb_AvoidDividebyZero;
  rtb_sincos_o1[2] = rtb_AvoidDividebyZero_h;

  // Trigonometry: '<S137>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S191>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn'
  //   SignalConversion generated from: '<S42>/sincos'
  //   Trigonometry: '<S49>/sincos'

  rtb_TmpSignalConversionAtProd_0 = std::sin(FCS_model_DW.Memory_PreviousInput);
  rtb_Product1_tmp = std::cos(FCS_model_DW.Memory_PreviousInput);
  rtb_TmpSignalConversionAtProd_1 = std::sin(rtb_AvoidDividebyZero);
  rtb_Product1_tmp_0 = std::cos(rtb_AvoidDividebyZero);
  rtb_TmpSignalConversionAtProd_2 = std::sin(rtb_AvoidDividebyZero_h);
  rtb_Product1_tmp_1 = std::cos(rtb_AvoidDividebyZero_h);

  // Fcn: '<S137>/Fcn11' incorporates:
  //   Fcn: '<S49>/Fcn11'
  //   Trigonometry: '<S137>/sincos'

  rtb_VectorConcatenate_tmp = rtb_Product1_tmp * rtb_Product1_tmp_0;
  rtb_VectorConcatenate[0] = rtb_VectorConcatenate_tmp;

  // Fcn: '<S137>/Fcn21' incorporates:
  //   Fcn: '<S49>/Fcn21'
  //   Trigonometry: '<S137>/sincos'

  rtb_VectorConcatenate_tmp_tmp = rtb_TmpSignalConversionAtProd_1 *
    rtb_TmpSignalConversionAtProd_2;
  rtb_VectorConcatenate_tmp_0 = rtb_TmpSignalConversionAtProd_0 *
    rtb_Product1_tmp_1;
  rtb_VectorConcatenate[1] = rtb_VectorConcatenate_tmp_tmp * rtb_Product1_tmp -
    rtb_VectorConcatenate_tmp_0;

  // Fcn: '<S137>/Fcn31' incorporates:
  //   Fcn: '<S49>/Fcn31'
  //   Trigonometry: '<S137>/sincos'

  rtb_rangefinder_distance_tmp = rtb_TmpSignalConversionAtProd_1 *
    rtb_Product1_tmp_1;
  rtb_VectorConcatenate_tmp_1 = rtb_TmpSignalConversionAtProd_0 *
    rtb_TmpSignalConversionAtProd_2;
  rtb_VectorConcatenate[2] = rtb_rangefinder_distance_tmp * rtb_Product1_tmp +
    rtb_VectorConcatenate_tmp_1;

  // Fcn: '<S137>/Fcn12' incorporates:
  //   Fcn: '<S49>/Fcn12'
  //   Trigonometry: '<S137>/sincos'

  rtb_VectorConcatenate_tmp_2 = rtb_TmpSignalConversionAtProd_0 *
    rtb_Product1_tmp_0;
  rtb_VectorConcatenate[3] = rtb_VectorConcatenate_tmp_2;

  // Fcn: '<S137>/Fcn22' incorporates:
  //   Fcn: '<S137>/Fcn21'
  //   Fcn: '<S49>/Fcn22'
  //   Trigonometry: '<S137>/sincos'

  rtb_VectorConcatenate_tmp_3 = rtb_Product1_tmp * rtb_Product1_tmp_1;
  rtb_VectorConcatenate[4] = rtb_VectorConcatenate_tmp_tmp *
    rtb_TmpSignalConversionAtProd_0 + rtb_VectorConcatenate_tmp_3;

  // Fcn: '<S137>/Fcn32' incorporates:
  //   Fcn: '<S137>/Fcn31'
  //   Fcn: '<S49>/Fcn32'
  //   Trigonometry: '<S137>/sincos'

  rtb_VectorConcatenate_tmp_4 = rtb_Product1_tmp *
    rtb_TmpSignalConversionAtProd_2;
  rtb_VectorConcatenate[5] = rtb_rangefinder_distance_tmp *
    rtb_TmpSignalConversionAtProd_0 - rtb_VectorConcatenate_tmp_4;

  // Fcn: '<S137>/Fcn13' incorporates:
  //   Trigonometry: '<S137>/sincos'

  rtb_VectorConcatenate[6] = -rtb_TmpSignalConversionAtProd_1;

  // Fcn: '<S137>/Fcn23' incorporates:
  //   Fcn: '<S49>/Fcn23'
  //   Trigonometry: '<S137>/sincos'

  rtb_TmpSignalConversionAtProd_2 *= rtb_Product1_tmp_0;
  rtb_VectorConcatenate[7] = rtb_TmpSignalConversionAtProd_2;

  // Fcn: '<S137>/Fcn33' incorporates:
  //   Fcn: '<S49>/Fcn33'
  //   Trigonometry: '<S137>/sincos'

  rtb_Product1_tmp_0 *= rtb_Product1_tmp_1;
  rtb_VectorConcatenate[8] = rtb_Product1_tmp_0;
  for (int32_T i{0}; i < 3; i++) {
    // Trigonometry: '<S42>/sincos'
    rtb_Product1_tmp_1 = rtb_sincos_o1[i];

    // Math: '<S135>/Math Function' incorporates:
    //   Concatenate: '<S190>/Vector Concatenate'

    rtb_MathFunction[3 * i] = rtb_VectorConcatenate[i];
    rtb_MathFunction[3 * i + 1] = rtb_VectorConcatenate[i + 3];
    rtb_MathFunction[3 * i + 2] = rtb_VectorConcatenate[i + 6];

    // Trigonometry: '<S42>/sincos'
    rtb_TmpSignalConversionAtProduc[i] = std::sin(rtb_Product1_tmp_1);
    rtb_FIR_IMUaccel[i] = std::cos(rtb_Product1_tmp_1);
  }

  // Fcn: '<S42>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_FIR_IMUaccel[0] * rtb_FIR_IMUaccel[1];

  // Fcn: '<S42>/Fcn21' incorporates:
  //   Fcn: '<S42>/Fcn22'

  rtb_Gain4_l = rtb_TmpSignalConversionAtProduc[1] *
    rtb_TmpSignalConversionAtProduc[2];
  rtb_VectorConcatenate_k[1] = rtb_Gain4_l * rtb_FIR_IMUaccel[0] -
    rtb_TmpSignalConversionAtProduc[0] * rtb_FIR_IMUaccel[2];

  // Fcn: '<S42>/Fcn31' incorporates:
  //   Fcn: '<S42>/Fcn32'

  rtb_Add_k_idx_1 = rtb_TmpSignalConversionAtProduc[1] * rtb_FIR_IMUaccel[2];
  rtb_VectorConcatenate_k[2] = rtb_Add_k_idx_1 * rtb_FIR_IMUaccel[0] +
    rtb_TmpSignalConversionAtProduc[0] * rtb_TmpSignalConversionAtProduc[2];

  // Fcn: '<S42>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_TmpSignalConversionAtProduc[0] *
    rtb_FIR_IMUaccel[1];

  // Fcn: '<S42>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_Gain4_l * rtb_TmpSignalConversionAtProduc[0]
    + rtb_FIR_IMUaccel[0] * rtb_FIR_IMUaccel[2];

  // Fcn: '<S42>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_Add_k_idx_1 *
    rtb_TmpSignalConversionAtProduc[0] - rtb_FIR_IMUaccel[0] *
    rtb_TmpSignalConversionAtProduc[2];

  // Fcn: '<S42>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_TmpSignalConversionAtProduc[1];

  // Fcn: '<S42>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_FIR_IMUaccel[1] *
    rtb_TmpSignalConversionAtProduc[2];

  // Fcn: '<S42>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_FIR_IMUaccel[1] * rtb_FIR_IMUaccel[2];

  // Math: '<S39>/Math Function' incorporates:
  //   Concatenate: '<S52>/Vector Concatenate'

  for (int32_T i{0}; i < 3; i++) {
    rtb_VectorConcatenate_g[3 * i] = rtb_VectorConcatenate_k[i];
    rtb_VectorConcatenate_g[3 * i + 1] = rtb_VectorConcatenate_k[i + 3];
    rtb_VectorConcatenate_g[3 * i + 2] = rtb_VectorConcatenate_k[i + 6];
  }

  std::memcpy(&rtb_VectorConcatenate_k[0], &rtb_VectorConcatenate_g[0], 9U *
              sizeof(real_T));

  // End of Math: '<S39>/Math Function'

  // DiscreteFir: '<S3>/FIR_IMUaccel'
  rtb_Product1_tmp_1 = inverseIMU_gain[0] *
    FCS_model_P.FIR_IMUaccel_Coefficients[0];
  cff = 1;
  for (int32_T i{FCS_model_DW.FIR_IMUaccel_circBuf}; i < 5; i++) {
    rtb_Product1_tmp_1 += FCS_model_DW.FIR_IMUaccel_states[i] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (int32_T i{0}; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_Product1_tmp_1 += FCS_model_DW.FIR_IMUaccel_states[i] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[0] = rtb_Product1_tmp_1;
  rtb_Product1_tmp_1 = FCS_model_P.FIR_IMUaccel_Coefficients[0] *
    inverseIMU_gain[1];
  cff = 1;
  for (int32_T i{FCS_model_DW.FIR_IMUaccel_circBuf}; i < 5; i++) {
    rtb_Product1_tmp_1 += FCS_model_DW.FIR_IMUaccel_states[i + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (int32_T i{0}; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_Product1_tmp_1 += FCS_model_DW.FIR_IMUaccel_states[i + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[1] = rtb_Product1_tmp_1;
  rtb_Product1_tmp_1 = FCS_model_P.FIR_IMUaccel_Coefficients[0] *
    inverseIMU_gain[2];
  cff = 1;
  for (int32_T i{FCS_model_DW.FIR_IMUaccel_circBuf}; i < 5; i++) {
    rtb_Product1_tmp_1 += FCS_model_DW.FIR_IMUaccel_states[i + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (int32_T i{0}; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_Product1_tmp_1 += FCS_model_DW.FIR_IMUaccel_states[i + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[2] = rtb_Product1_tmp_1;

  // Sum: '<S3>/Sum3' incorporates:
  //   Constant: '<Root>/Constant'
  //   Inport: '<Root>/in_parameters'

  rtb_rangefinder_distance = arg_in_parameters->rangefinder_distance -
    FCS_model_P.sensorCalibrationData[7];

  // DiscreteFilter: '<S135>/Discrete Filter1'
  rtb_Sum1_le = rtb_rangefinder_distance;
  denIdx = 1;
  for (int32_T i{0}; i < 3; i++) {
    // Sum: '<S135>/Sum' incorporates:
    //   Constant: '<S135>/gravity'
    //   DiscreteFir: '<S3>/FIR_IMUaccel'
    //   Math: '<S135>/Math Function'
    //   Product: '<S135>/Product'

    rtb_TmpSignalConversionAtProduc[i] = ((rtb_MathFunction[i + 3] *
      rtb_FIR_IMUaccel[1] + rtb_MathFunction[i] * rtb_FIR_IMUaccel[0]) +
      rtb_MathFunction[i + 6] * rtb_Product1_tmp_1) +
      FCS_model_P.gravity_Value[i];

    // DiscreteFilter: '<S135>/Discrete Filter1'
    rtb_Sum1_le -= FCS_model_P.DiscreteFilter1_DenCoef[denIdx] *
      FCS_model_DW.DiscreteFilter1_states[i];
    denIdx++;
  }

  // DiscreteFilter: '<S135>/Discrete Filter1'
  DiscreteFilter1_tmp = rtb_Sum1_le / FCS_model_P.DiscreteFilter1_DenCoef[0];

  // Trigonometry: '<S193>/Trigonometric Function' incorporates:
  //   DiscreteFilter: '<S135>/Discrete Filter1'

  rtb_roll = ((FCS_model_P.DiscreteFilter1_NumCoef[0] * DiscreteFilter1_tmp +
               FCS_model_DW.DiscreteFilter1_states[0] *
               FCS_model_P.DiscreteFilter1_NumCoef[1]) +
              FCS_model_DW.DiscreteFilter1_states[1] *
              FCS_model_P.DiscreteFilter1_NumCoef[2]) +
    FCS_model_DW.DiscreteFilter1_states[2] *
    FCS_model_P.DiscreteFilter1_NumCoef[3];

  // Gain: '<S1>/On=1//Off=0 for thrust' incorporates:
  //   Gain: '<S135>/RangfinderScaleGain1'

  rtb_On1Off0forthrust = FCS_model_P.RangfinderScaleGain1_Gain * rtb_roll;

  // Product: '<S135>/Product2' incorporates:
  //   Constant: '<S135>/Constant'
  //   Math: '<S135>/Math Function'
  //   SignalConversion generated from: '<S135>/Product2'

  for (int32_T i{0}; i < 3; i++) {
    rtb_sincos_o1[i] = (rtb_MathFunction[i + 3] * FCS_model_P.Constant_Value_e +
                        rtb_MathFunction[i] * FCS_model_P.Constant_Value_e) +
      rtb_MathFunction[i + 6] * rtb_On1Off0forthrust;
  }

  // End of Product: '<S135>/Product2'

  // Reshape: '<S136>/Reshapey'
  rtb_Reshapey[0] = rtb_sincos_o1[2];
  rtb_Reshapey[1] = rtb_TmpSignalConversionAtProduc[2];

  // Delay: '<S136>/MemoryX' incorporates:
  //   Constant: '<S136>/X0'

  if (FCS_model_DW.icLoad) {
    FCS_model_DW.MemoryX_DSTATE[0] = FCS_model_P.X0_Value[0];
    FCS_model_DW.MemoryX_DSTATE[1] = FCS_model_P.X0_Value[1];
    FCS_model_DW.MemoryX_DSTATE[2] = FCS_model_P.X0_Value[2];
    FCS_model_DW.MemoryX_DSTATE[3] = FCS_model_P.X0_Value[3];
  }

  // Outputs for Enabled SubSystem: '<S164>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S189>/Enable'

  // Outputs for Enabled SubSystem: '<S158>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S187>/Enable'

  // Constant: '<S136>/Enable'
  if (FCS_model_P.Enable_Value) {
    FCS_model_DW.MeasurementUpdate_MODE = true;

    // Product: '<S187>/D[k]*u[k]'
    rtb_Add_g_idx_0 = rtb_TmpSignalConversionAtProduc[2];
    for (int32_T i{0}; i < 2; i++) {
      // Product: '<S187>/C[k]*xhat[k|k-1]' incorporates:
      //   Constant: '<S136>/C'
      //   Delay: '<S136>/MemoryX'

      rtb_Add_g_idx_1 = ((FCS_model_P.C_Value[i + 2] *
                          FCS_model_DW.MemoryX_DSTATE[1] + FCS_model_P.C_Value[i]
                          * FCS_model_DW.MemoryX_DSTATE[0]) +
                         FCS_model_P.C_Value[i + 4] *
                         FCS_model_DW.MemoryX_DSTATE[2]) + FCS_model_P.C_Value[i
        + 6] * FCS_model_DW.MemoryX_DSTATE[3];

      // Sum: '<S187>/Sum' incorporates:
      //   Constant: '<S136>/D'
      //   Product: '<S187>/D[k]*u[k]'
      //   Sum: '<S187>/Add1'

      IIRgyroz_tmp[i] = rtb_Reshapey[i] - (FCS_model_P.D_Value[i] *
        rtb_Add_g_idx_0 + rtb_Add_g_idx_1);

      // Product: '<S187>/C[k]*xhat[k|k-1]' incorporates:
      //   Constant: '<S136>/C'
      //   Product: '<S189>/Product'

      rtb_Product_f[i] = rtb_Add_g_idx_1;
    }

    FCS_model_DW.EnabledSubsystem_MODE = true;

    // Sum: '<S189>/Add1' incorporates:
    //   Product: '<S189>/Product'
    //   Reshape: '<S136>/Reshapey'

    rtb_Add_g_idx_0 = rtb_sincos_o1[2] - rtb_Product_f[0];
    rtb_Add_g_idx_1 = rtb_TmpSignalConversionAtProduc[2] - rtb_Product_f[1];
    for (int32_T i{0}; i < 4; i++) {
      // Product: '<S187>/Product3' incorporates:
      //   Constant: '<S138>/KalmanGainL'

      FCS_model_B.Product3[i] = 0.0;
      FCS_model_B.Product3[i] += FCS_model_P.KalmanGainL_Value[i] *
        IIRgyroz_tmp[0];
      FCS_model_B.Product3[i] += FCS_model_P.KalmanGainL_Value[i + 4] *
        IIRgyroz_tmp[1];

      // Product: '<S189>/Product2' incorporates:
      //   Constant: '<S138>/KalmanGainM'

      FCS_model_B.Product2[i] = 0.0;
      FCS_model_B.Product2[i] += FCS_model_P.KalmanGainM_Value[i] *
        rtb_Add_g_idx_0;
      FCS_model_B.Product2[i] += FCS_model_P.KalmanGainM_Value[i + 4] *
        rtb_Add_g_idx_1;
    }
  } else {
    if (FCS_model_DW.MeasurementUpdate_MODE) {
      // Disable for Product: '<S187>/Product3' incorporates:
      //   Outport: '<S187>/L*(y[k]-yhat[k|k-1])'

      FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_DW.MeasurementUpdate_MODE = false;
    }

    if (FCS_model_DW.EnabledSubsystem_MODE) {
      // Disable for Product: '<S189>/Product2' incorporates:
      //   Outport: '<S189>/deltax'

      FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0_k;
      FCS_model_DW.EnabledSubsystem_MODE = false;
    }
  }

  // End of Constant: '<S136>/Enable'
  // End of Outputs for SubSystem: '<S158>/MeasurementUpdate'
  // End of Outputs for SubSystem: '<S164>/Enabled Subsystem'

  // Sum: '<S164>/Add' incorporates:
  //   Delay: '<S136>/MemoryX'

  rtb_Add_g_idx_0 = FCS_model_B.Product2[0] + FCS_model_DW.MemoryX_DSTATE[0];
  rtb_Add_g_idx_1 = FCS_model_B.Product2[1] + FCS_model_DW.MemoryX_DSTATE[1];

  // Logic: '<S27>/OR' incorporates:
  //   Constant: '<S23>/Constant'
  //   Inport: '<Root>/in_dashboard'
  //   Memory: '<S27>/Memory'
  //   RelationalOperator: '<S23>/GreaterThan'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  FCS_model_DW.Memory_PreviousInput_j = ((static_cast<real_T>
    (arg_in_dashboard->master_switch) >= FCS_model_P.Constant_Value_i) ||
    FCS_model_DW.Memory_PreviousInput_j);

  // Product: '<S27>/Divide' incorporates:
  //   Constant: '<S27>/cycle_time'
  //   Constant: '<S27>/signal_max'
  //   Gain: '<S27>/Gain'

  rtb_Divide = FCS_model_P.signal_max_Value / (FCS_model_P.Gain_Gain *
    FCS_model_P.cycle_time_Value);

  // Chart: '<S27>/takeoff_acceleration' incorporates:
  //   Constant: '<S27>/Ts'
  //   Constant: '<S27>/signal_max'

  if (FCS_model_DW.is_active_c1_FCS_model == 0U) {
    FCS_model_DW.is_active_c1_FCS_model = 1U;
    FCS_model_DW.is_c1_FCS_model = FCS_model_IN_waiting4trigger;
    FCS_model_B.signal_out = 0.0;
  } else {
    switch (FCS_model_DW.is_c1_FCS_model) {
     case FCS_model_IN_decreasing:
      if (FCS_model_B.signal_out > 0.0) {
        FCS_model_DW.is_c1_FCS_model = FCS_model_IN_decreasing;
        FCS_model_B.signal_out -= FCS_model_P.Ts * rtb_Divide;
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
        FCS_model_B.signal_out += FCS_model_P.Ts * rtb_Divide;
      } else if (FCS_model_B.signal_out >= FCS_model_P.signal_max_Value) {
        FCS_model_DW.is_c1_FCS_model = FCS_model_IN_decreasing;
        FCS_model_B.signal_out -= FCS_model_P.Ts * rtb_Divide;
      } else {
        FCS_model_B.signal_out += FCS_model_P.Ts * rtb_Divide;
      }
      break;

     default:
      // case IN_waiting4trigger:
      if (FCS_model_DW.Memory_PreviousInput_j) {
        FCS_model_DW.is_c1_FCS_model = FCS_model_IN_increasing;
        FCS_model_B.signal_out += FCS_model_P.Ts * rtb_Divide;
      } else {
        FCS_model_B.signal_out = 0.0;
      }
      break;
    }
  }

  // End of Chart: '<S27>/takeoff_acceleration'

  // DiscreteStateSpace: '<S26>/Internal'
  {
    rtb_On1Off0forthrust = (FCS_model_P.Internal_C[0])*
      FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_C[1])*FCS_model_DW.Internal_DSTATE[1];
  }

  // Trigonometry: '<S193>/Trigonometric Function' incorporates:
  //   Gain: '<S23>/Gain'

  rtb_roll = FCS_model_P.Gain_Gain_f * rtb_Add_g_idx_0;

  // Gain: '<S23>/kp_alt' incorporates:
  //   Sum: '<S23>/Sum1'

  rtb_Divide = (rtb_On1Off0forthrust - rtb_roll) * FCS_model_P.kp_alt;

  // SignalConversion generated from: '<S135>/Product1' incorporates:
  //   Constant: '<S36>/Constant'

  rtb_On1Off1foryaw = FCS_model_P.Constant_Value_c1[0];
  rtb_yawrate = FCS_model_P.Constant_Value_c1[1];

  // Product: '<S135>/Product1' incorporates:
  //   Concatenate: '<S190>/Vector Concatenate'
  //   SignalConversion generated from: '<S135>/Product1'

  for (int32_T i{0}; i < 3; i++) {
    rtb_sincos_o1[i] = (rtb_VectorConcatenate[i + 3] * rtb_yawrate +
                        rtb_VectorConcatenate[i] * rtb_On1Off1foryaw) +
      rtb_VectorConcatenate[i + 6] * rtb_Add_g_idx_1;
  }

  // End of Product: '<S135>/Product1'

  // Gain: '<S1>/On=1//Off=0 for thrust' incorporates:
  //   Constant: '<S23>/Constant1'
  //   Constant: '<S27>/Constant'
  //   Gain: '<S23>/Gain1'
  //   Gain: '<S23>/WithControl=1 WithoutControl=0'
  //   Gain: '<S23>/WithTakeoff=1 WithoutTakeoff=0'
  //   Gain: '<S23>/kd_alt'
  //   Gain: '<S23>/rateFeedback ON//OFF'
  //   Product: '<S27>/Product'
  //   Sum: '<S23>/Sum2'
  //   Sum: '<S23>/Sum3'
  //   Sum: '<S23>/Sum4'

  rtb_On1Off0forthrust = FCS_model_P.Gain1_Gain * rtb_sincos_o1[2];
  rtb_On1Off0forthrust = ((rtb_Divide - FCS_model_P.rateFeedbackONOFF_Gain *
    rtb_On1Off0forthrust * FCS_model_P.kd_alt) *
    FCS_model_P.WithControl1WithoutControl0_Gai +
    FCS_model_P.Vehicle.Airframe.mass * FCS_model_P.g) +
    FCS_model_P.Vehicle.Airframe.mass * FCS_model_B.signal_out *
    FCS_model_P.WithTakeoff1WithoutTakeoff0_Gai;

  // Saturate: '<S23>/SaturationThrust'
  rtb_Add_g_idx_1 = -4.0 * FCS_model_P.Controller.totalThrustMaxRelative *
    FCS_model_P.Controller.motorsThrustPerMotorMax;
  rtb_Divide = 4.0 * FCS_model_P.Controller.totalThrustMaxRelative *
    FCS_model_P.Controller.motorsThrustPerMotorMax;
  if (rtb_On1Off0forthrust > rtb_Divide) {
    // Gain: '<S1>/On=1//Off=0 for thrust'
    rtb_On1Off0forthrust = rtb_Divide;
  } else if (rtb_On1Off0forthrust < rtb_Add_g_idx_1) {
    // Gain: '<S1>/On=1//Off=0 for thrust'
    rtb_On1Off0forthrust = rtb_Add_g_idx_1;
  }

  // End of Saturate: '<S23>/SaturationThrust'

  // Gain: '<S1>/On=1//Off=0 for thrust'
  rtb_On1Off0forthrust *= FCS_model_P.On1Off0forthrust_Gain;

  // DiscreteStateSpace: '<S19>/Internal'
  {
    rtb_roll = (FCS_model_P.Internal_C_j[0])*FCS_model_DW.Internal_DSTATE_f[0]
      + (FCS_model_P.Internal_C_j[1])*FCS_model_DW.Internal_DSTATE_f[1];
  }

  // Sum: '<S10>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn'

  rtb_Sum1_le = rtb_roll - rtb_AvoidDividebyZero_h;

  // Trigonometry: '<S193>/Trigonometric Function' incorporates:
  //   DiscreteFir: '<S3>/FIR_IMUaccel'
  //   Gain: '<S193>/Gain2'
  //   Gain: '<S193>/Gain3'

  rtb_roll = FCS_model_P.Gain2_Gain * rtb_FIR_IMUaccel[1];
  rtb_roll = rt_atan2d_snf(rtb_roll, FCS_model_P.Gain3_Gain * rtb_Product1_tmp_1);

  // Trigonometry: '<S194>/Trigonometric Function2'
  rtb_Add_g_idx_1 = std::sin(rtb_roll);
  rtb_Gain4_l = std::cos(rtb_roll);

  // Product: '<S193>/Divide' incorporates:
  //   Constant: '<S193>/Constant'
  //   Gain: '<S193>/Gain1'

  rtb_Add_k_idx_1 = FCS_model_P.Gain1_Gain_e * rtb_FIR_IMUaccel[0] /
    FCS_model_P.g;

  // Trigonometry: '<S193>/Trigonometric Function1'
  if (rtb_Add_k_idx_1 > 1.0) {
    rtb_Add_k_idx_1 = 1.0;
  } else if (rtb_Add_k_idx_1 < -1.0) {
    rtb_Add_k_idx_1 = -1.0;
  }

  // Gain: '<S193>/Gain' incorporates:
  //   Trigonometry: '<S193>/Trigonometric Function1'

  rtb_Divide = FCS_model_P.Gain_Gain_e * std::asin(rtb_Add_k_idx_1);

  // Trigonometry: '<S194>/Trigonometric Function3'
  rtb_On1Off1foryaw = std::cos(rtb_Divide);

  // Sum: '<S194>/Sum2' incorporates:
  //   Product: '<S194>/Divide1'
  //   Product: '<S194>/Divide2'
  //   Product: '<S194>/Product8'
  //   Product: '<S194>/Product9'

  rtb_yawrate = rtb_Add_g_idx_1 / rtb_On1Off1foryaw * inverseIMU_gain[4] +
    rtb_Gain4_l / rtb_On1Off1foryaw * inverseIMU_gain[5];

  // Gain: '<S1>/On=1//Off=1 for yaw' incorporates:
  //   Constant: '<S4>/yaw equilibrium'
  //   Gain: '<S10>/KDpsi'
  //   Gain: '<S10>/zDpsi'
  //   Gain: '<S4>/Changing of Jzz'
  //   Sum: '<S10>/Sum3'
  //   Sum: '<S4>/Sum3'

  rtb_On1Off1foryaw = ((FCS_model_P.zDpsi * 2.0 * rtb_Sum1_le - rtb_yawrate) *
                       (FCS_model_P.KDpsi * 1.3) *
                       FCS_model_P.ChangingofJzz_Gain +
                       FCS_model_P.yawequilibrium_Value) *
    FCS_model_P.On1Off1foryaw_Gain;

  // Delay: '<S46>/MemoryX' incorporates:
  //   Constant: '<S46>/X0'

  if (FCS_model_DW.icLoad_n) {
    FCS_model_DW.MemoryX_DSTATE_o[0] = FCS_model_P.X0_Value_h[0];
    FCS_model_DW.MemoryX_DSTATE_o[1] = FCS_model_P.X0_Value_h[1];
  }

  for (cff = 0; cff < 2; cff++) {
    // DiscreteFilter: '<S45>/IIRgyroz'
    memOffset = cff * 5;
    rtb_Sum1_le = inverseIMU_gain[cff + 3];
    denIdx = 1;
    for (int32_T i{0}; i < 5; i++) {
      rtb_Sum1_le -= FCS_model_DW.IIRgyroz_states[memOffset + i] *
        FCS_model_P.IIRgyroz_DenCoef[denIdx];
      denIdx++;
    }

    rtb_Sum1_le /= FCS_model_P.IIRgyroz_DenCoef[0];
    rtb_Saturation = FCS_model_P.IIRgyroz_NumCoef[0] * rtb_Sum1_le;
    denIdx = 1;
    for (int32_T i{0}; i < 5; i++) {
      rtb_Saturation += FCS_model_DW.IIRgyroz_states[memOffset + i] *
        FCS_model_P.IIRgyroz_NumCoef[denIdx];
      denIdx++;
    }

    // SampleTimeMath: '<S53>/TSamp' incorporates:
    //   DiscreteFilter: '<S45>/IIRgyroz'
    //
    //  About '<S53>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )

    rtb_Saturation *= FCS_model_P.TSamp_WtEt;

    // DiscreteFilter: '<S45>/IIRgyroz' incorporates:
    //   Sum: '<S53>/Diff'
    //   UnitDelay: '<S53>/UD'
    //
    //  Block description for '<S53>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S53>/UD':
    //
    //   Store in Global RAM

    IIRgyroz_tmp[cff] = rtb_Sum1_le;
    rtb_SimplyIntegrateVelocity[cff] = rtb_Saturation -
      FCS_model_DW.UD_DSTATE[cff];

    // SampleTimeMath: '<S53>/TSamp'
    //
    //  About '<S53>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )

    rtb_Reshapey[cff] = rtb_Saturation;
  }

  // Abs: '<S45>/Abs' incorporates:
  //   Abs: '<S45>/Abs4'

  rtb_Sum1_le = std::abs(inverseIMU_gain[3]);

  // Abs: '<S45>/Abs1' incorporates:
  //   Abs: '<S45>/Abs5'

  rtb_Saturation = std::abs(inverseIMU_gain[4]);

  // Logic: '<S45>/Logical Operator3' incorporates:
  //   Abs: '<S45>/Abs'
  //   Abs: '<S45>/Abs1'
  //   Abs: '<S45>/Abs2'
  //   Abs: '<S45>/Abs3'
  //   Abs: '<S45>/Abs6'
  //   Abs: '<S45>/Abs7'
  //   Abs: '<S45>/Abs8'
  //   Abs: '<S45>/Abs9'
  //   Constant: '<S54>/Constant'
  //   Constant: '<S55>/Constant'
  //   Constant: '<S56>/Constant'
  //   Constant: '<S57>/Constant'
  //   Constant: '<S58>/Constant'
  //   Constant: '<S59>/Constant'
  //   Constant: '<S60>/Constant'
  //   Constant: '<S61>/Constant'
  //   Constant: '<S62>/Constant'
  //   Constant: '<S63>/Constant'
  //   Constant: '<S64>/Constant'
  //   Delay: '<S40>/Delay'
  //   DiscreteTransferFcn: '<S191>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn'
  //   Inport: '<Root>/in_parameters'
  //   Logic: '<S45>/Logical Operator'
  //   Logic: '<S45>/Logical Operator1'
  //   Logic: '<S45>/Logical Operator2'
  //   RelationalOperator: '<S54>/Compare'
  //   RelationalOperator: '<S55>/Compare'
  //   RelationalOperator: '<S56>/Compare'
  //   RelationalOperator: '<S57>/Compare'
  //   RelationalOperator: '<S58>/Compare'
  //   RelationalOperator: '<S59>/Compare'
  //   RelationalOperator: '<S60>/Compare'
  //   RelationalOperator: '<S61>/Compare'
  //   RelationalOperator: '<S62>/Compare'
  //   RelationalOperator: '<S63>/Compare'
  //   RelationalOperator: '<S64>/Compare'
  //   Sum: '<S45>/Add'

  rtb_LogicalOperator3 = ((((std::abs(rtb_AvoidDividebyZero) <=
    FCS_model_P.maxp_const) && (std::abs(rtb_AvoidDividebyZero_h) <=
    FCS_model_P.maxq_const) && (rtb_Sum1_le <= FCS_model_P.maxw1_const) &&
    (rtb_Saturation <= FCS_model_P.maxw2_const) && (std::abs
    (rtb_SimplyIntegrateVelocity[0]) <= FCS_model_P.maxdw1_const) && (std::abs
    (rtb_SimplyIntegrateVelocity[1]) <= FCS_model_P.maxdw2_const)) ||
    ((rtb_Sum1_le <= FCS_model_P.maxp2_const) && (rtb_Saturation <=
    FCS_model_P.maxq2_const))) && (std::abs(arg_in_parameters->opticalflow_x -
    FCS_model_DW.Delay_DSTATE[0]) <= FCS_model_P.maxw3_const) && (std::abs
    (arg_in_parameters->opticalflow_y - FCS_model_DW.Delay_DSTATE[1]) <=
    FCS_model_P.maxw4_const) && (rtb_Add_g_idx_0 <=
    FCS_model_P.minHeightforOF_const));

  // Logic: '<S127>/Logical Operator' incorporates:
  //   Constant: '<S127>/Constant'
  //   Constant: '<S127>/Time constant'
  //   Constant: '<S130>/Constant'
  //   Constant: '<S131>/Constant'
  //   RelationalOperator: '<S130>/Compare'
  //   RelationalOperator: '<S131>/Compare'
  //   Sum: '<S127>/Sum1'

  rtb_LogicalOperator_b = ((FCS_model_P.LowPassFilterDiscreteorContin_l -
    FCS_model_B.Probe[0] <= FCS_model_P.Constant_Value_o) &&
    (FCS_model_P.LowPassFilterDiscreteorContin_i <
     FCS_model_P.CompareToConstant_const));

  // Gain: '<S119>/K' incorporates:
  //   Inport: '<Root>/in_parameters'

  rtb_Sum1_le = FCS_model_P.LowPassFilterDiscreteorContinuo *
    arg_in_parameters->opticalflow_x;

  // DiscreteIntegrator: '<S133>/Integrator'
  if (FCS_model_DW.Integrator_IC_LOADING != 0) {
    FCS_model_DW.Integrator_DSTATE = rtb_Sum1_le;
    if (FCS_model_DW.Integrator_DSTATE >= FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE <= FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  if (rtb_LogicalOperator_b || (FCS_model_DW.Integrator_PrevResetState != 0)) {
    FCS_model_DW.Integrator_DSTATE = rtb_Sum1_le;
    if (FCS_model_DW.Integrator_DSTATE >= FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE <= FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  if (FCS_model_DW.Integrator_DSTATE >= FCS_model_P.Integrator_UpperSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE <= FCS_model_P.Integrator_LowerSat)
  {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
  }

  // End of DiscreteIntegrator: '<S133>/Integrator'

  // Saturate: '<S133>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Saturation_UpperSat) {
    rtb_Saturation = FCS_model_P.Saturation_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Saturation_LowerSat) {
    rtb_Saturation = FCS_model_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = FCS_model_DW.Integrator_DSTATE;
  }

  // End of Saturate: '<S133>/Saturation'

  // Sum: '<S194>/Sum1' incorporates:
  //   Bias: '<S47>/Bias3'
  //   Delay: '<S47>/Delay2'
  //   Gain: '<S47>/Gain5'
  //   Product: '<S47>/Product3'
  //   Sum: '<S47>/Subtract3'

  rtb_pitchrate = FCS_model_DW.Delay2_DSTATE[0];
  rtb_pitchrate = (rtb_rangefinder_distance + FCS_model_P.Bias3_Bias) *
    FCS_model_P.Gain5_Gain * (rtb_Saturation - rtb_pitchrate);

  // Logic: '<S120>/Logical Operator' incorporates:
  //   Constant: '<S120>/Constant'
  //   Constant: '<S120>/Time constant'
  //   Constant: '<S123>/Constant'
  //   Constant: '<S124>/Constant'
  //   RelationalOperator: '<S123>/Compare'
  //   RelationalOperator: '<S124>/Compare'
  //   Sum: '<S120>/Sum1'

  rtb_LogicalOperator_j = ((FCS_model_P.LowPassFilterDiscreteorContin_a -
    FCS_model_B.Probe_c[0] <= FCS_model_P.Constant_Value) &&
    (FCS_model_P.LowPassFilterDiscreteorConti_d0 <
     FCS_model_P.CompareToConstant_const_p));

  // Gain: '<S118>/K' incorporates:
  //   Inport: '<Root>/in_parameters'

  rtb_K_i = FCS_model_P.LowPassFilterDiscreteorContin_d *
    arg_in_parameters->opticalflow_y;

  // DiscreteIntegrator: '<S126>/Integrator'
  if (FCS_model_DW.Integrator_IC_LOADING_g != 0) {
    FCS_model_DW.Integrator_DSTATE_e = rtb_K_i;
    if (FCS_model_DW.Integrator_DSTATE_e >= FCS_model_P.Integrator_UpperSat_i) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
    } else if (FCS_model_DW.Integrator_DSTATE_e <=
               FCS_model_P.Integrator_LowerSat_l) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
    }
  }

  if (rtb_LogicalOperator_j || (FCS_model_DW.Integrator_PrevResetState_e != 0))
  {
    FCS_model_DW.Integrator_DSTATE_e = rtb_K_i;
    if (FCS_model_DW.Integrator_DSTATE_e >= FCS_model_P.Integrator_UpperSat_i) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
    } else if (FCS_model_DW.Integrator_DSTATE_e <=
               FCS_model_P.Integrator_LowerSat_l) {
      FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
    }
  }

  if (FCS_model_DW.Integrator_DSTATE_e >= FCS_model_P.Integrator_UpperSat_i) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
  } else if (FCS_model_DW.Integrator_DSTATE_e <=
             FCS_model_P.Integrator_LowerSat_l) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
  }

  // End of DiscreteIntegrator: '<S126>/Integrator'

  // Saturate: '<S126>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Saturation_UpperSat_k) {
    rtb_Saturation_l = FCS_model_P.Saturation_UpperSat_k;
  } else if (FCS_model_DW.Integrator_DSTATE_e <
             FCS_model_P.Saturation_LowerSat_h) {
    rtb_Saturation_l = FCS_model_P.Saturation_LowerSat_h;
  } else {
    rtb_Saturation_l = FCS_model_DW.Integrator_DSTATE_e;
  }

  // End of Saturate: '<S126>/Saturation'

  // Reshape: '<S46>/Reshapey' incorporates:
  //   Bias: '<S47>/Bias2'
  //   Delay: '<S47>/Delay1'
  //   Gain: '<S47>/Gain4'
  //   Product: '<S47>/Product2'
  //   Sum: '<S47>/Subtract2'

  rtb_SimplyIntegrateVelocity[0] = rtb_pitchrate;
  rtb_SimplyIntegrateVelocity[1] = (rtb_rangefinder_distance +
    FCS_model_P.Bias2_Bias) * FCS_model_P.Gain4_Gain * (rtb_Saturation_l -
    FCS_model_DW.Delay1_DSTATE[0U]);

  // Outputs for Enabled SubSystem: '<S91>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S117>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.EnabledSubsystem_MODE_g = true;

    // Sum: '<S117>/Add1' incorporates:
    //   Constant: '<S46>/C'
    //   Delay: '<S46>/MemoryX'
    //   Product: '<S117>/Product'
    //   Reshape: '<S46>/Reshapey'

    rtb_Add_k_idx_1 = rtb_pitchrate - (FCS_model_P.C_Value_h[0] *
      FCS_model_DW.MemoryX_DSTATE_o[0] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[2]);
    rtb_Add_k_idx_2 = rtb_SimplyIntegrateVelocity[1] -
      (FCS_model_DW.MemoryX_DSTATE_o[0] * FCS_model_P.C_Value_h[1] +
       FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.C_Value_h[3]);

    // Product: '<S117>/Product2' incorporates:
    //   Constant: '<S65>/KalmanGainM'

    FCS_model_B.Product2_c[0] = FCS_model_P.KalmanGainM_Value_e[0] *
      rtb_Add_k_idx_1;
    FCS_model_B.Product2_c[0] += FCS_model_P.KalmanGainM_Value_e[2] *
      rtb_Add_k_idx_2;
    FCS_model_B.Product2_c[1] = FCS_model_P.KalmanGainM_Value_e[1] *
      rtb_Add_k_idx_1;
    FCS_model_B.Product2_c[1] += FCS_model_P.KalmanGainM_Value_e[3] *
      rtb_Add_k_idx_2;
  } else if (FCS_model_DW.EnabledSubsystem_MODE_g) {
    // Disable for Product: '<S117>/Product2' incorporates:
    //   Outport: '<S117>/deltax'

    FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;
    FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;
    FCS_model_DW.EnabledSubsystem_MODE_g = false;
  }

  // End of Outputs for SubSystem: '<S91>/Enabled Subsystem'

  // Sum: '<S91>/Add' incorporates:
  //   Delay: '<S40>/Delay'
  //   Delay: '<S46>/MemoryX'

  FCS_model_DW.Delay_DSTATE[0] = FCS_model_B.Product2_c[0] +
    FCS_model_DW.MemoryX_DSTATE_o[0];
  FCS_model_DW.Delay_DSTATE[1] = FCS_model_B.Product2_c[1] +
    FCS_model_DW.MemoryX_DSTATE_o[1];

  // Sum: '<S194>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S39>/SimplyIntegrateVelocity'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S24>/Subtract'

  rtb_pitchrate = arg_in_dashboard->ref_x;
  rtb_pitchrate -= FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0];

  // Gain: '<S24>/Gain1' incorporates:
  //   Delay: '<S40>/Delay'
  //   Gain: '<S24>/Gain3'
  //   Gain: '<S24>/Gain4'
  //   Sum: '<S24>/Sum1'

  rtb_Saturation_a = (FCS_model_P.Gain3_Gain_g * rtb_pitchrate -
                      FCS_model_P.Gain4_Gain_m * FCS_model_DW.Delay_DSTATE[0]) *
    FCS_model_P.Gain1_Gain_b;

  // Saturate: '<S24>/Saturation'
  if (rtb_Saturation_a > FCS_model_P.Saturation_UpperSat_d) {
    rtb_Saturation_a = FCS_model_P.Saturation_UpperSat_d;
  } else if (rtb_Saturation_a < FCS_model_P.Saturation_LowerSat_a) {
    rtb_Saturation_a = FCS_model_P.Saturation_LowerSat_a;
  }

  // End of Saturate: '<S24>/Saturation'

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch1_Threshold) {
    // Sum: '<S194>/Sum1'
    rtb_pitchrate = rtb_Saturation_a;
  } else {
    // Sum: '<S194>/Sum1' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_pitchrate = arg_in_dashboard->ref_pitch;
  }

  // End of Switch: '<S4>/Switch1'

  // Sum: '<S8>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S191>/Discrete Transfer Fcn'

  rtb_Sum1_a = rtb_pitchrate - rtb_AvoidDividebyZero;

  // DiscreteStateSpace: '<S11>/Internal'
  {
    rtb_pitchrate = FCS_model_P.Internal_C_p*FCS_model_DW.Internal_DSTATE_d;
    rtb_pitchrate += FCS_model_P.Internal_D_b*rtb_Sum1_a;
  }

  // Gain: '<S8>/zDtheta'
  rtb_zDtheta = FCS_model_P.zDtheta * 7.0 * rtb_pitchrate;

  // Sum: '<S194>/Sum1' incorporates:
  //   Gain: '<S194>/Gain'
  //   Product: '<S194>/Product4'
  //   Product: '<S194>/Product5'

  rtb_pitchrate = rtb_Gain4_l * inverseIMU_gain[4];
  rtb_pitchrate += FCS_model_P.Gain_Gain_p * rtb_Add_g_idx_1 * inverseIMU_gain[5];

  // Gain: '<S1>/On=1//Off=2 for pitch' incorporates:
  //   Constant: '<S4>/pitch equilibrium'
  //   Gain: '<S4>/Changing of Jyy'
  //   Gain: '<S8>/KDtheta'
  //   Sum: '<S4>/Sum1'
  //   Sum: '<S8>/Sum3'

  rtb_barometer_pressure = (FCS_model_P.KDtheta * 1.4 * (rtb_zDtheta -
    rtb_pitchrate) * FCS_model_P.ChangingofJyy_Gain +
    FCS_model_P.pitchequilibrium_Value) * FCS_model_P.On1Off2forpitch_Gain;

  // DiscreteStateSpace: '<S15>/Internal'
  {
    rtb_clock = (FCS_model_P.Internal_C_n[0])*FCS_model_DW.Internal_DSTATE_k[0]
      + (FCS_model_P.Internal_C_n[1])*FCS_model_DW.Internal_DSTATE_k[1];
  }

  // Sum: '<S9>/Sum1'
  rtb_zDtheta = rtb_clock - FCS_model_DW.Memory_PreviousInput;

  // DigitalClock: '<S3>/Digital Clock' incorporates:
  //   Trigonometry: '<S194>/Trigonometric Function4'

  rtb_clock = std::tan(rtb_Divide);

  // Sum: '<S194>/Sum' incorporates:
  //   Product: '<S194>/Product'
  //   Product: '<S194>/Product1'
  //   Product: '<S194>/Product2'
  //   Product: '<S194>/Product3'

  rtb_Add_g_idx_1 = (rtb_Add_g_idx_1 * rtb_clock * inverseIMU_gain[4] +
                     inverseIMU_gain[3]) + rtb_Gain4_l * rtb_clock *
    inverseIMU_gain[5];

  // DigitalClock: '<S3>/Digital Clock' incorporates:
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

  rtb_clock = (((FCS_model_P.ki_rol * FCS_model_DW.DiscreteTimeIntegrator_DSTATE
                 + FCS_model_P.kp_rol * rtb_zDtheta) - FCS_model_P.kd_rol *
                rtb_Add_g_idx_1) * FCS_model_P.ChangingofJxx_Gain +
               FCS_model_P.rollequilibrium_Value) *
    FCS_model_P.On1Off1forroll_Gain;
  for (int32_T i{0}; i < 4; i++) {
    // Saturate: '<S33>/Saturation' incorporates:
    //   Bias: '<S34>/Bias'
    //   Constant: '<S32>/TorqueTotalThrustToThrustPerMotor'
    //   Gain: '<S34>/thrustToMotor'
    //   Inport: '<Root>/in_dashboard'
    //   Product: '<S32>/Product'
    //   Product: '<S33>/Product'
    //   SignalConversion generated from: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<S32>/Product'

    rtb_Add_k_idx_1 = ((((FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 4] *
                          rtb_On1Off1foryaw +
                          FCS_model_P.TorqueTotalThrustToThrustPerMot[i] *
                          rtb_On1Off0forthrust) +
                         FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 8] *
                         rtb_barometer_pressure) +
                        FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 12] *
                        rtb_clock) *
                       FCS_model_P.Vehicle.Motor.thrustToMotorCommand +
                       FCS_model_P.Vehicle.Motor.commandToW2Offset) *
      arg_in_dashboard->power;
    if (rtb_Add_k_idx_1 > FCS_model_P.Vehicle.Motor.maxLimit) {
      rtb_Add_k_idx_1 = FCS_model_P.Vehicle.Motor.maxLimit;
    } else if (rtb_Add_k_idx_1 < FCS_model_P.Vehicle.Motor.minLimit) {
      rtb_Add_k_idx_1 = FCS_model_P.Vehicle.Motor.minLimit;
    }

    // Product: '<S33>/Product1' incorporates:
    //   Gain: '<S34>/thrustToMotor'
    //   Inport: '<Root>/in_dashboard'
    //   Saturate: '<S33>/Saturation'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Product1_i[i] = rtb_Add_k_idx_1 * static_cast<real_T>
      (arg_in_dashboard->master_switch);
  }

  // SignalConversion generated from: '<S39>/Product' incorporates:
  //   Delay: '<S40>/Delay'

  rtb_Gain4_l = FCS_model_DW.Delay_DSTATE[0];
  rtb_Add_k_idx_1 = FCS_model_DW.Delay_DSTATE[1];
  rtb_Add_k_idx_2 = rtb_sincos_o1[2];

  // Product: '<S39>/Product' incorporates:
  //   Concatenate: '<S52>/Vector Concatenate'

  for (int32_T i{0}; i < 3; i++) {
    rtb_Product_k[i] = (rtb_VectorConcatenate_k[i + 3] * rtb_Add_k_idx_1 +
                        rtb_VectorConcatenate_k[i] * rtb_Gain4_l) +
      rtb_VectorConcatenate_k[i + 6] * rtb_Add_k_idx_2;
  }

  // End of Product: '<S39>/Product'

  // Fcn: '<S49>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_tmp;

  // Fcn: '<S49>/Fcn21'
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_tmp_tmp * rtb_Product1_tmp
    - rtb_VectorConcatenate_tmp_0;

  // Fcn: '<S49>/Fcn31'
  rtb_VectorConcatenate_k[2] = rtb_rangefinder_distance_tmp * rtb_Product1_tmp +
    rtb_VectorConcatenate_tmp_1;

  // Fcn: '<S49>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_VectorConcatenate_tmp_2;

  // Fcn: '<S49>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_tmp_tmp *
    rtb_TmpSignalConversionAtProd_0 + rtb_VectorConcatenate_tmp_3;

  // Fcn: '<S49>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_rangefinder_distance_tmp *
    rtb_TmpSignalConversionAtProd_0 - rtb_VectorConcatenate_tmp_4;

  // Fcn: '<S49>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_TmpSignalConversionAtProd_1;

  // Fcn: '<S49>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_TmpSignalConversionAtProd_2;

  // Fcn: '<S49>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_Product1_tmp_0;

  // RelationalOperator: '<S48>/Compare' incorporates:
  //   Constant: '<S48>/Constant'

  rtb_Compare_jy = (rtb_Add_g_idx_0 <=
                    FCS_model_P.DeactivateAccelerationIfOFisnot);

  // Logic: '<S44>/Logical Operator' incorporates:
  //   Constant: '<S50>/Constant'
  //   Constant: '<S51>/Constant'
  //   Inport: '<Root>/in_parameters'
  //   RelationalOperator: '<S50>/Compare'
  //   RelationalOperator: '<S51>/Compare'

  rtb_LogicalOperator_c = ((arg_in_parameters->opticalflow_x !=
    FCS_model_P.donotuseaccifopticalflowneverav) ||
    (arg_in_parameters->opticalflow_y !=
     FCS_model_P.donotuseaccifopticalflownever_c));

  // Sum: '<S44>/Add' incorporates:
  //   Concatenate: '<S52>/Vector Concatenate'
  //   Constant: '<S44>/gravity'
  //   Product: '<S44>/Product1'

  for (int32_T i{0}; i < 3; i++) {
    rtb_FIR_IMUaccel_0[i] = rtb_FIR_IMUaccel[i] - ((rtb_VectorConcatenate_k[i +
      3] * FCS_model_P.gravity_Value_a[1] + rtb_VectorConcatenate_k[i] *
      FCS_model_P.gravity_Value_a[0]) + rtb_VectorConcatenate_k[i + 6] *
      FCS_model_P.gravity_Value_a[2]);
  }

  // End of Sum: '<S44>/Add'

  // Product: '<S44>/Product' incorporates:
  //   Gain: '<S44>/gainaccinput'

  rtb_Product_f[0] = FCS_model_P.gainaccinput_Gain * rtb_FIR_IMUaccel_0[0] *
    static_cast<real_T>(rtb_LogicalOperator_c) * static_cast<real_T>
    (rtb_Compare_jy);
  rtb_Product_f[1] = FCS_model_P.gainaccinput_Gain * rtb_FIR_IMUaccel_0[1] *
    static_cast<real_T>(rtb_LogicalOperator_c) * static_cast<real_T>
    (rtb_Compare_jy);

  // Outputs for Enabled SubSystem: '<S84>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S115>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.MeasurementUpdate_MODE_h = true;

    // Sum: '<S115>/Sum' incorporates:
    //   Constant: '<S46>/C'
    //   Constant: '<S46>/D'
    //   Delay: '<S46>/MemoryX'
    //   Product: '<S115>/C[k]*xhat[k|k-1]'
    //   Product: '<S115>/D[k]*u[k]'
    //   Sum: '<S115>/Add1'

    rtb_Add_k_idx_1 = rtb_SimplyIntegrateVelocity[0] - ((FCS_model_P.C_Value_h[0]
      * FCS_model_DW.MemoryX_DSTATE_o[0] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[2]) + (FCS_model_P.D_Value_b[0] * rtb_Product_f[0] +
      rtb_Product_f[1] * FCS_model_P.D_Value_b[2]));
    rtb_Add_k_idx_2 = rtb_SimplyIntegrateVelocity[1] -
      ((FCS_model_DW.MemoryX_DSTATE_o[0] * FCS_model_P.C_Value_h[1] +
        FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.C_Value_h[3]) +
       (rtb_Product_f[0] * FCS_model_P.D_Value_b[1] + rtb_Product_f[1] *
        FCS_model_P.D_Value_b[3]));

    // Product: '<S115>/Product3' incorporates:
    //   Constant: '<S65>/KalmanGainL'

    FCS_model_B.Product3_d[0] = FCS_model_P.KalmanGainL_Value_f[0] *
      rtb_Add_k_idx_1;
    FCS_model_B.Product3_d[0] += FCS_model_P.KalmanGainL_Value_f[2] *
      rtb_Add_k_idx_2;
    FCS_model_B.Product3_d[1] = FCS_model_P.KalmanGainL_Value_f[1] *
      rtb_Add_k_idx_1;
    FCS_model_B.Product3_d[1] += FCS_model_P.KalmanGainL_Value_f[3] *
      rtb_Add_k_idx_2;
  } else if (FCS_model_DW.MeasurementUpdate_MODE_h) {
    // Disable for Product: '<S115>/Product3' incorporates:
    //   Outport: '<S115>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_DW.MeasurementUpdate_MODE_h = false;
  }

  // End of Outputs for SubSystem: '<S84>/MeasurementUpdate'

  // DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
  //   Delay: '<S40>/Delay'
  //   DiscreteIntegrator: '<S39>/SimplyIntegrateVelocity'
  //   Gain: '<S25>/Gain1'
  //   Gain: '<S25>/Gain3'
  //   Gain: '<S25>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S25>/Subtract'
  //   Sum: '<S25>/Sum1'

  rtb_Switch2 = ((arg_in_dashboard->ref_y -
                  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1]) *
                 FCS_model_P.Gain3_Gain_i - FCS_model_P.Gain4_Gain_h *
                 FCS_model_DW.Delay_DSTATE[1]) * FCS_model_P.Gain1_Gain_i;

  // Saturate: '<S25>/Saturation'
  if (rtb_Switch2 > FCS_model_P.Saturation_UpperSat_ku) {
    // DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
    rtb_Switch2 = FCS_model_P.Saturation_UpperSat_ku;
  } else if (rtb_Switch2 < FCS_model_P.Saturation_LowerSat_j) {
    // DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
    rtb_Switch2 = FCS_model_P.Saturation_LowerSat_j;
  }

  // End of Saturate: '<S25>/Saturation'

  // Outport: '<Root>/out_controllers' incorporates:
  //   BusCreator generated from: '<Root>/out_controllers'
  //   Constant: '<S6>/Constant'

  arg_out_controllers->motor1 = rtb_Product1_i[0];
  arg_out_controllers->motor2 = rtb_Product1_i[1];
  arg_out_controllers->motor3 = rtb_Product1_i[2];
  arg_out_controllers->motor4 = rtb_Product1_i[3];
  arg_out_controllers->cmd_thrust = rtb_On1Off0forthrust;
  arg_out_controllers->cmd_tau_roll = rtb_On1Off1foryaw;
  arg_out_controllers->cmd_tau_pitch = rtb_barometer_pressure;
  arg_out_controllers->cmd_tau_yaw = rtb_clock;
  arg_out_controllers->cmd_roll = rtb_Saturation_a;
  arg_out_controllers->cmd_pitch = rtb_Switch2;
  arg_out_controllers->cmd_yaw = FCS_model_P.Constant_Value_e2;

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (!(FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch2_Threshold)) {
    // DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'
    //   Switch: '<S4>/Switch2'

    rtb_Switch2 = arg_in_dashboard->ref_roll;
  }

  // End of Switch: '<S4>/Switch2'

  // DigitalClock: '<S3>/Digital Clock' incorporates:
  //   DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
  //   Gain: '<S35>/Gain'

  rtb_clock = FCS_model_P.Gain_Gain_h *
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o;

  // Outport: '<Root>/out_estimators' incorporates:
  //   BusCreator generated from: '<Root>/out_estimators'
  //   Delay: '<S40>/Delay'
  //   DiscreteIntegrator: '<S39>/SimplyIntegrateVelocity'
  //   DiscreteTransferFcn: '<S191>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn'

  arg_out_estimators->orient_roll = FCS_model_DW.Memory_PreviousInput;
  arg_out_estimators->orient_pitch = rtb_AvoidDividebyZero;
  arg_out_estimators->orient_yaw = rtb_AvoidDividebyZero_h;
  arg_out_estimators->orient_rate_roll = rtb_Add_g_idx_1;
  arg_out_estimators->orient_rate_pitch = rtb_pitchrate;
  arg_out_estimators->orient_rate_yaw = rtb_yawrate;
  arg_out_estimators->pos_x = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0];
  arg_out_estimators->pos_y = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1];
  arg_out_estimators->pos_z = rtb_Add_g_idx_0;
  arg_out_estimators->pos_dx = FCS_model_DW.Delay_DSTATE[0];
  arg_out_estimators->pos_dy = FCS_model_DW.Delay_DSTATE[1];
  arg_out_estimators->pos_dz = rtb_sincos_o1[2];
  arg_out_estimators->battery_SOC = rtb_clock;

  // DigitalClock: '<S3>/Digital Clock' incorporates:
  //   Constant: '<S120>/Time constant'
  //   MinMax: '<S120>/Max'

  rtb_clock = std::fmax(FCS_model_B.Probe_c[0],
                        FCS_model_P.LowPassFilterDiscreteorContin_a);

  // Fcn: '<S120>/Avoid Divide by Zero'
  rtb_AvoidDividebyZero = static_cast<real_T>(rtb_clock == 0.0) *
    2.2204460492503131e-16 + rtb_clock;

  // DigitalClock: '<S3>/Digital Clock' incorporates:
  //   Constant: '<S127>/Time constant'
  //   MinMax: '<S127>/Max'

  rtb_clock = std::fmax(FCS_model_B.Probe[0],
                        FCS_model_P.LowPassFilterDiscreteorContin_l);

  // Fcn: '<S127>/Avoid Divide by Zero'
  rtb_AvoidDividebyZero_h = static_cast<real_T>(rtb_clock == 0.0) *
    2.2204460492503131e-16 + rtb_clock;

  // DigitalClock: '<S3>/Digital Clock'
  rtb_clock = (((&FCS_model_M)->Timing.clockTick0) * 0.0025);

  // Outport: '<Root>/out_sensors' incorporates:
  //   BusCreator generated from: '<Root>/out_sensors'
  //   Constant: '<Root>/Constant'
  //   DiscreteFir: '<S3>/FIR_IMUaccel'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S3>/Sum2'

  arg_out_sensors->clock = rtb_clock;
  arg_out_sensors->accelerometer_x = rtb_FIR_IMUaccel[0];
  arg_out_sensors->accelerometer_y = rtb_FIR_IMUaccel[1];
  arg_out_sensors->accelerometer_z = rtb_Product1_tmp_1;
  arg_out_sensors->gyroscope_x = inverseIMU_gain[3];
  arg_out_sensors->gyroscope_y = inverseIMU_gain[4];
  arg_out_sensors->gyroscope_z = inverseIMU_gain[5];
  arg_out_sensors->barometer_pressure = arg_in_parameters->barometer_pressure -
    FCS_model_P.sensorCalibrationData[6];
  arg_out_sensors->rangefinder_distance = rtb_rangefinder_distance;

  // SignalConversion generated from: '<Root>/in_dashboard' incorporates:
  //   Inport: '<Root>/in_dashboard'

  rtb_ref_z = arg_in_dashboard->ref_z;

  // SignalConversion generated from: '<Root>/in_dashboard' incorporates:
  //   Inport: '<Root>/in_dashboard'

  rtb_ref_yaw = arg_in_dashboard->ref_yaw;

  // Update for DiscreteTransferFcn: '<S191>/Discrete Transfer Fcn' incorporates:
  //   Gain: '<S191>/Gain'
  //   Sum: '<S191>/Sum'

  FCS_model_DW.DiscreteTransferFcn_states = ((FCS_model_P.w_c_pitch * rtb_Divide
    + rtb_pitchrate) - FCS_model_P.DiscreteTransferFcn_DenCoef_b[1] *
    FCS_model_DW.DiscreteTransferFcn_states) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_b[0];

  // Update for DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn' incorporates:
  //   Gain: '<S192>/Gain'
  //   Sum: '<S192>/Sum'

  FCS_model_DW.DiscreteTransferFcn_states_j = ((FCS_model_P.w_c_roll * rtb_roll
    + rtb_Add_g_idx_1) - FCS_model_P.DiscreteTransferFcn_DenCoef_p[1] *
    FCS_model_DW.DiscreteTransferFcn_states_j) /
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

  // Update for DiscreteFilter: '<S135>/Discrete Filter1'
  FCS_model_DW.DiscreteFilter1_states[2] = FCS_model_DW.DiscreteFilter1_states[1];
  FCS_model_DW.DiscreteFilter1_states[1] = FCS_model_DW.DiscreteFilter1_states[0];
  FCS_model_DW.DiscreteFilter1_states[0] = DiscreteFilter1_tmp;

  // Update for Delay: '<S136>/MemoryX'
  FCS_model_DW.icLoad = false;

  // Product: '<S158>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S136>/A'
  //   Delay: '<S136>/MemoryX'

  for (int32_T i{0}; i < 4; i++) {
    rtb_Product1_i[i] = ((FCS_model_P.A_Value[i + 4] *
                          FCS_model_DW.MemoryX_DSTATE[1] + FCS_model_P.A_Value[i]
                          * FCS_model_DW.MemoryX_DSTATE[0]) +
                         FCS_model_P.A_Value[i + 8] *
                         FCS_model_DW.MemoryX_DSTATE[2]) + FCS_model_P.A_Value[i
      + 12] * FCS_model_DW.MemoryX_DSTATE[3];
  }

  // End of Product: '<S158>/A[k]*xhat[k|k-1]'

  // Update for Delay: '<S136>/MemoryX' incorporates:
  //   Constant: '<S136>/B'
  //   Product: '<S158>/B[k]*u[k]'
  //   Product: '<S187>/Product3'
  //   Sum: '<S158>/Add'

  FCS_model_DW.MemoryX_DSTATE[0] = (FCS_model_P.B_Value[0] *
    rtb_TmpSignalConversionAtProduc[2] + rtb_Product1_i[0]) +
    FCS_model_B.Product3[0];
  FCS_model_DW.MemoryX_DSTATE[1] = (FCS_model_P.B_Value[1] *
    rtb_TmpSignalConversionAtProduc[2] + rtb_Product1_i[1]) +
    FCS_model_B.Product3[1];
  FCS_model_DW.MemoryX_DSTATE[2] = (FCS_model_P.B_Value[2] *
    rtb_TmpSignalConversionAtProduc[2] + rtb_Product1_i[2]) +
    FCS_model_B.Product3[2];
  FCS_model_DW.MemoryX_DSTATE[3] = (rtb_TmpSignalConversionAtProduc[2] *
    FCS_model_P.B_Value[3] + rtb_Product1_i[3]) + FCS_model_B.Product3[3];

  // Update for DiscreteStateSpace: '<S26>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_A[1])*FCS_model_DW.Internal_DSTATE[1];
    xnew[0] += FCS_model_P.Internal_B*rtb_ref_z;
    xnew[1] = (FCS_model_P.Internal_A[2])*FCS_model_DW.Internal_DSTATE[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteStateSpace: '<S19>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_l[0])*FCS_model_DW.Internal_DSTATE_f[0]
      + (FCS_model_P.Internal_A_l[1])*FCS_model_DW.Internal_DSTATE_f[1];
    xnew[0] += FCS_model_P.Internal_B_e*rtb_ref_yaw;
    xnew[1] = (FCS_model_P.Internal_A_l[2])*FCS_model_DW.Internal_DSTATE_f[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_f[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for Delay: '<S46>/MemoryX'
  FCS_model_DW.icLoad_n = false;

  // Product: '<S84>/B[k]*u[k]' incorporates:
  //   Constant: '<S46>/B'

  rtb_SimplyIntegrateVelocity[0] = FCS_model_P.B_Value_p[0] * rtb_Product_f[0] +
    rtb_Product_f[1] * FCS_model_P.B_Value_p[2];

  // Product: '<S84>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S46>/A'
  //   Delay: '<S46>/MemoryX'

  tmp[0] = FCS_model_P.A_Value_p[0] * FCS_model_DW.MemoryX_DSTATE_o[0] +
    FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.A_Value_p[2];

  // Product: '<S84>/B[k]*u[k]' incorporates:
  //   Constant: '<S46>/B'

  rtb_SimplyIntegrateVelocity[1] = rtb_Product_f[0] * FCS_model_P.B_Value_p[1] +
    rtb_Product_f[1] * FCS_model_P.B_Value_p[3];

  // Product: '<S84>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S46>/A'
  //   Delay: '<S46>/MemoryX'

  tmp[1] = FCS_model_DW.MemoryX_DSTATE_o[0] * FCS_model_P.A_Value_p[1] +
    FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.A_Value_p[3];
  for (cff = 0; cff < 2; cff++) {
    // Update for Delay: '<S46>/MemoryX' incorporates:
    //   Sum: '<S84>/Add'

    FCS_model_DW.MemoryX_DSTATE_o[cff] = (rtb_SimplyIntegrateVelocity[cff] +
      tmp[cff]) + FCS_model_B.Product3_d[cff];

    // Update for DiscreteFilter: '<S45>/IIRgyroz'
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

    // Update for UnitDelay: '<S53>/UD'
    //
    //  Block description for '<S53>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[cff] = rtb_Reshapey[cff];
  }

  // Update for DiscreteIntegrator: '<S133>/Integrator' incorporates:
  //   Product: '<S119>/1//T'
  //   Sum: '<S119>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING = 0U;
  FCS_model_DW.Integrator_DSTATE += 1.0 / rtb_AvoidDividebyZero_h * (rtb_Sum1_le
    - rtb_Saturation) * FCS_model_P.Integrator_gainval;
  if (FCS_model_DW.Integrator_DSTATE >= FCS_model_P.Integrator_UpperSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE <= FCS_model_P.Integrator_LowerSat)
  {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
  }

  FCS_model_DW.Integrator_PrevResetState = static_cast<int8_T>
    (rtb_LogicalOperator_b);

  // End of Update for DiscreteIntegrator: '<S133>/Integrator'

  // Update for Delay: '<S47>/Delay2'
  for (int32_T i{0}; i < 39; i++) {
    FCS_model_DW.Delay2_DSTATE[i] = FCS_model_DW.Delay2_DSTATE[i + 1];
  }

  FCS_model_DW.Delay2_DSTATE[39] = inverseIMU_gain[3];

  // End of Update for Delay: '<S47>/Delay2'

  // Update for DiscreteIntegrator: '<S126>/Integrator' incorporates:
  //   Product: '<S118>/1//T'
  //   Sum: '<S118>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING_g = 0U;
  FCS_model_DW.Integrator_DSTATE_e += 1.0 / rtb_AvoidDividebyZero * (rtb_K_i -
    rtb_Saturation_l) * FCS_model_P.Integrator_gainval_g;
  if (FCS_model_DW.Integrator_DSTATE_e >= FCS_model_P.Integrator_UpperSat_i) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
  } else if (FCS_model_DW.Integrator_DSTATE_e <=
             FCS_model_P.Integrator_LowerSat_l) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
  }

  FCS_model_DW.Integrator_PrevResetState_e = static_cast<int8_T>
    (rtb_LogicalOperator_j);

  // End of Update for DiscreteIntegrator: '<S126>/Integrator'

  // Update for Delay: '<S47>/Delay1'
  for (int32_T i{0}; i < 39; i++) {
    FCS_model_DW.Delay1_DSTATE[i] = FCS_model_DW.Delay1_DSTATE[i + 1];
  }

  FCS_model_DW.Delay1_DSTATE[39] = inverseIMU_gain[4];

  // End of Update for Delay: '<S47>/Delay1'

  // Update for DiscreteIntegrator: '<S39>/SimplyIntegrateVelocity'
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval * rtb_Product_k[0];
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval * rtb_Product_k[1];

  // Update for DiscreteStateSpace: '<S11>/Internal'
  {
    real_T xnew[1];
    xnew[0] = FCS_model_P.Internal_A_o*FCS_model_DW.Internal_DSTATE_d;
    xnew[0] += FCS_model_P.Internal_B_b*rtb_Sum1_a;
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_d, xnew,
                       sizeof(real_T)*1);
  }

  // Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
  FCS_model_DW.DiscreteTimeIntegrator_DSTATE +=
    FCS_model_P.DiscreteTimeIntegrator_gainval * rtb_zDtheta;

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

  // Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
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

  // Start for Probe: '<S127>/Probe'
  FCS_model_B.Probe[0] = 0.0025;
  FCS_model_B.Probe[1] = 0.0;

  // Start for Probe: '<S120>/Probe'
  FCS_model_B.Probe_c[0] = 0.0025;
  FCS_model_B.Probe_c[1] = 0.0;

  // InitializeConditions for Merge: '<S195>/Merge1' incorporates:
  //   Memory: '<S37>/Memory'

  FCS_model_DW.Memory_PreviousInput = FCS_model_P.Memory_InitialCondition;

  // InitializeConditions for DiscreteTransferFcn: '<S191>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states =
    FCS_model_P.DiscreteTransferFcn_InitialSt_e;

  // InitializeConditions for DiscreteTransferFcn: '<S192>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_j =
    FCS_model_P.DiscreteTransferFcn_InitialSt_b;

  // InitializeConditions for DiscreteFir: '<S3>/FIR_IMUaccel'
  for (int32_T i{0}; i < 15; i++) {
    FCS_model_DW.FIR_IMUaccel_states[i] = FCS_model_P.FIR_IMUaccel_InitialStates;
  }

  // End of InitializeConditions for DiscreteFir: '<S3>/FIR_IMUaccel'

  // InitializeConditions for DiscreteFilter: '<S135>/Discrete Filter1'
  FCS_model_DW.DiscreteFilter1_states[0] =
    FCS_model_P.DiscreteFilter1_InitialStates;
  FCS_model_DW.DiscreteFilter1_states[1] =
    FCS_model_P.DiscreteFilter1_InitialStates;
  FCS_model_DW.DiscreteFilter1_states[2] =
    FCS_model_P.DiscreteFilter1_InitialStates;

  // InitializeConditions for Delay: '<S136>/MemoryX'
  FCS_model_DW.icLoad = true;

  // InitializeConditions for Logic: '<S27>/OR' incorporates:
  //   Memory: '<S27>/Memory'

  FCS_model_DW.Memory_PreviousInput_j = FCS_model_P.Memory_InitialCondition_h;

  // InitializeConditions for DiscreteStateSpace: '<S26>/Internal'
  FCS_model_DW.Internal_DSTATE[0] = FCS_model_P.Internal_InitialCondition;
  FCS_model_DW.Internal_DSTATE[1] = FCS_model_P.Internal_InitialCondition;

  // InitializeConditions for DiscreteStateSpace: '<S19>/Internal'
  FCS_model_DW.Internal_DSTATE_f[0] = FCS_model_P.Internal_InitialCondition_a;
  FCS_model_DW.Internal_DSTATE_f[1] = FCS_model_P.Internal_InitialCondition_a;

  // InitializeConditions for Delay: '<S46>/MemoryX'
  FCS_model_DW.icLoad_n = true;

  // InitializeConditions for DiscreteFilter: '<S45>/IIRgyroz'
  for (int32_T i{0}; i < 10; i++) {
    FCS_model_DW.IIRgyroz_states[i] = FCS_model_P.IIRgyroz_InitialStates;
  }

  // End of InitializeConditions for DiscreteFilter: '<S45>/IIRgyroz'

  // InitializeConditions for UnitDelay: '<S53>/UD'
  //
  //  Block description for '<S53>/UD':
  //
  //   Store in Global RAM

  FCS_model_DW.UD_DSTATE[0] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for Delay: '<S40>/Delay'
  FCS_model_DW.Delay_DSTATE[0] = FCS_model_P.Delay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S53>/UD'
  //
  //  Block description for '<S53>/UD':
  //
  //   Store in Global RAM

  FCS_model_DW.UD_DSTATE[1] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for Delay: '<S40>/Delay'
  FCS_model_DW.Delay_DSTATE[1] = FCS_model_P.Delay_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<S133>/Integrator'
  FCS_model_DW.Integrator_IC_LOADING = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S126>/Integrator'
  FCS_model_DW.Integrator_IC_LOADING_g = 1U;
  for (int32_T i{0}; i < 40; i++) {
    // InitializeConditions for Delay: '<S47>/Delay2'
    FCS_model_DW.Delay2_DSTATE[i] = FCS_model_P.Delay2_InitialCondition;

    // InitializeConditions for Delay: '<S47>/Delay1'
    FCS_model_DW.Delay1_DSTATE[i] = FCS_model_P.Delay1_InitialCondition;
  }

  // InitializeConditions for DiscreteIntegrator: '<S39>/SimplyIntegrateVelocity' 
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0] =
    FCS_model_P.SimplyIntegrateVelocity_IC;
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1] =
    FCS_model_P.SimplyIntegrateVelocity_IC;

  // InitializeConditions for DiscreteStateSpace: '<S11>/Internal'
  FCS_model_DW.Internal_DSTATE_d = FCS_model_P.Internal_InitialCondition_p;

  // InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' 
  FCS_model_DW.DiscreteTimeIntegrator_DSTATE =
    FCS_model_P.DiscreteTimeIntegrator_IC;

  // InitializeConditions for DiscreteStateSpace: '<S15>/Internal'
  FCS_model_DW.Internal_DSTATE_k[0] = FCS_model_P.Internal_InitialCondition_h;
  FCS_model_DW.Internal_DSTATE_k[1] = FCS_model_P.Internal_InitialCondition_h;

  // InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' 
  FCS_model_DW.DiscreteTimeIntegrator_DSTATE_o =
    FCS_model_P.DiscreteTimeIntegrator_IC_p;

  // SystemInitialize for IfAction SubSystem: '<S195>/If Action Subsystem'
  // InitializeConditions for DiscreteTransferFcn: '<S198>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_p =
    FCS_model_P.DiscreteTransferFcn_InitialStat;

  // End of SystemInitialize for SubSystem: '<S195>/If Action Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S158>/MeasurementUpdate'
  // SystemInitialize for Product: '<S187>/Product3' incorporates:
  //   Outport: '<S187>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S158>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S164>/Enabled Subsystem'
  // SystemInitialize for Product: '<S189>/Product2' incorporates:
  //   Outport: '<S189>/deltax'

  FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S164>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S158>/MeasurementUpdate'
  // SystemInitialize for Product: '<S187>/Product3' incorporates:
  //   Outport: '<S187>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S158>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S164>/Enabled Subsystem'
  // SystemInitialize for Product: '<S189>/Product2' incorporates:
  //   Outport: '<S189>/deltax'

  FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S164>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S158>/MeasurementUpdate'
  // SystemInitialize for Product: '<S187>/Product3' incorporates:
  //   Outport: '<S187>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S158>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S164>/Enabled Subsystem'
  // SystemInitialize for Product: '<S189>/Product2' incorporates:
  //   Outport: '<S189>/deltax'

  FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S164>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S158>/MeasurementUpdate'
  // SystemInitialize for Product: '<S187>/Product3' incorporates:
  //   Outport: '<S187>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S158>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S164>/Enabled Subsystem'
  // SystemInitialize for Product: '<S189>/Product2' incorporates:
  //   Outport: '<S189>/deltax'

  FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S164>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S91>/Enabled Subsystem'
  // SystemInitialize for Product: '<S117>/Product2' incorporates:
  //   Outport: '<S117>/deltax'

  FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;

  // End of SystemInitialize for SubSystem: '<S91>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S84>/MeasurementUpdate'
  // SystemInitialize for Product: '<S115>/Product3' incorporates:
  //   Outport: '<S115>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;

  // End of SystemInitialize for SubSystem: '<S84>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S91>/Enabled Subsystem'
  // SystemInitialize for Product: '<S117>/Product2' incorporates:
  //   Outport: '<S117>/deltax'

  FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;

  // End of SystemInitialize for SubSystem: '<S91>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S84>/MeasurementUpdate'
  // SystemInitialize for Product: '<S115>/Product3' incorporates:
  //   Outport: '<S115>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;

  // End of SystemInitialize for SubSystem: '<S84>/MeasurementUpdate'
}

// Model terminate function
void FCS_model::terminate()
{
  // (no terminate code required)
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
