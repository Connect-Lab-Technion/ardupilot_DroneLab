//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.207
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Jul  1 17:24:37 2025
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

// Named constants for Chart: '<S31>/takeoff_acceleration'
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
  real_T rtb_Sum1_di;
  real_T rtb_Switch2;
  real_T rtb_ref_z;
  real_T rtb_ref_yaw;
  real_T rtb_Product4;
  real_T rtb_roll;
  real_T rtb_Product5;
  real_T rtb_Product3;
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
  real_T DiscreteFilter1_tmp_tmp;
  real_T Sum;
  real_T rtb_Add_g_idx_0;
  real_T rtb_Add_g_idx_1;
  real_T rtb_Add_k_idx_0;
  real_T rtb_Add_k_idx_1;
  real_T rtb_Add_k_idx_2;
  real_T rtb_AvoidDividebyZero;
  real_T rtb_AvoidDividebyZero_h;
  real_T rtb_Divide;
  real_T rtb_K_i;
  real_T rtb_Product1_tmp;
  real_T rtb_Saturation_l;
  real_T rtb_TmpSignalConversionAtProd_0;
  real_T rtb_TmpSignalConversionAtProd_1;
  real_T rtb_TrigonometricFunction4;
  real_T rtb_VectorConcatenate_tmp;
  real_T rtb_VectorConcatenate_tmp_0;
  real_T rtb_VectorConcatenate_tmp_1;
  real_T rtb_VectorConcatenate_tmp_2;
  real_T rtb_VectorConcatenate_tmp_3;
  real_T rtb_VectorConcatenate_tmp_4;
  real_T rtb_VectorConcatenate_tmp_5;
  real_T rtb_VectorConcatenate_tmp_tmp;
  real_T rtb_rangefinder_distance;
  real_T rtb_rollrate;
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

  // If: '<S200>/If1' incorporates:
  //   Constant: '<S42>/Constant'
  //   DataTypeConversion: '<S200>/Data Type Conversion'

  if (static_cast<real32_T>(FCS_model_P.Constant_Value_c) > 0.0F) {
    // Outputs for IfAction SubSystem: '<S200>/If Action Subsystem' incorporates:
    //   ActionPort: '<S202>/Action Port'

    // Merge: '<S200>/Merge1' incorporates:
    //   DiscreteTransferFcn: '<S203>/Discrete Transfer Fcn'

    FCS_model_DW.Memory_PreviousInput = FCS_model_P.DiscreteTransferFcn_NumCoef
      [1] * FCS_model_DW.DiscreteTransferFcn_states_p;

    // Update for DiscreteTransferFcn: '<S203>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S203>/Gain'
    //   Inport: '<Root>/in_parameters'
    //   Sum: '<S203>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_p = ((FCS_model_P.w_c_yaw *
      arg_in_parameters->yaw + inverseIMU_gain[5]) -
      FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_p) /
      FCS_model_P.DiscreteTransferFcn_DenCoef[0];

    // End of Outputs for SubSystem: '<S200>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S200>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S201>/Action Port'

    // Merge: '<S200>/Merge1' incorporates:
    //   Gain: '<S201>/Gain'
    //   Memory: '<S42>/Memory'
    //   Sum: '<S201>/Sum'

    FCS_model_DW.Memory_PreviousInput += FCS_model_P.Ts * inverseIMU_gain[5];

    // End of Outputs for SubSystem: '<S200>/If Action Subsystem3'
  }

  // End of If: '<S200>/If1'

  // DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  rtb_AvoidDividebyZero = FCS_model_P.DiscreteTransferFcn_NumCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'
  rtb_AvoidDividebyZero_h = FCS_model_P.DiscreteTransferFcn_NumCoef_f[1] *
    FCS_model_DW.DiscreteTransferFcn_states_j;

  // SignalConversion generated from: '<S46>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'

  rtb_sincos_o1[0] = FCS_model_DW.Memory_PreviousInput;
  rtb_sincos_o1[1] = rtb_AvoidDividebyZero;
  rtb_sincos_o1[2] = rtb_AvoidDividebyZero_h;

  // Trigonometry: '<S141>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'
  //   SignalConversion generated from: '<S46>/sincos'
  //   Trigonometry: '<S53>/sincos'

  rtb_TrigonometricFunction4 = std::sin(FCS_model_DW.Memory_PreviousInput);
  Sum = std::cos(FCS_model_DW.Memory_PreviousInput);
  rtb_TmpSignalConversionAtProd_0 = std::sin(rtb_AvoidDividebyZero);
  rtb_Product1_tmp = std::cos(rtb_AvoidDividebyZero);
  rtb_TmpSignalConversionAtProd_1 = std::sin(rtb_AvoidDividebyZero_h);
  DiscreteFilter1_tmp = std::cos(rtb_AvoidDividebyZero_h);

  // Fcn: '<S141>/Fcn11' incorporates:
  //   Fcn: '<S53>/Fcn11'
  //   Trigonometry: '<S141>/sincos'

  rtb_VectorConcatenate_tmp_0 = Sum * rtb_Product1_tmp;
  rtb_VectorConcatenate[0] = rtb_VectorConcatenate_tmp_0;

  // Fcn: '<S141>/Fcn21' incorporates:
  //   Fcn: '<S53>/Fcn21'
  //   Trigonometry: '<S141>/sincos'

  DiscreteFilter1_tmp_tmp = rtb_TmpSignalConversionAtProd_0 *
    rtb_TmpSignalConversionAtProd_1;
  rtb_VectorConcatenate_tmp_1 = rtb_TrigonometricFunction4 * DiscreteFilter1_tmp;
  rtb_VectorConcatenate[1] = DiscreteFilter1_tmp_tmp * Sum -
    rtb_VectorConcatenate_tmp_1;

  // Fcn: '<S141>/Fcn31' incorporates:
  //   Fcn: '<S53>/Fcn31'
  //   Trigonometry: '<S141>/sincos'

  rtb_VectorConcatenate_tmp_tmp = rtb_TmpSignalConversionAtProd_0 *
    DiscreteFilter1_tmp;
  rtb_VectorConcatenate_tmp_2 = rtb_TrigonometricFunction4 *
    rtb_TmpSignalConversionAtProd_1;
  rtb_VectorConcatenate[2] = rtb_VectorConcatenate_tmp_tmp * Sum +
    rtb_VectorConcatenate_tmp_2;

  // Fcn: '<S141>/Fcn12' incorporates:
  //   Fcn: '<S53>/Fcn12'
  //   Trigonometry: '<S141>/sincos'

  rtb_VectorConcatenate_tmp_3 = rtb_TrigonometricFunction4 * rtb_Product1_tmp;
  rtb_VectorConcatenate[3] = rtb_VectorConcatenate_tmp_3;

  // Fcn: '<S141>/Fcn22' incorporates:
  //   Fcn: '<S141>/Fcn21'
  //   Fcn: '<S53>/Fcn22'
  //   Trigonometry: '<S141>/sincos'

  rtb_VectorConcatenate_tmp_4 = Sum * DiscreteFilter1_tmp;
  rtb_VectorConcatenate[4] = DiscreteFilter1_tmp_tmp *
    rtb_TrigonometricFunction4 + rtb_VectorConcatenate_tmp_4;

  // Fcn: '<S141>/Fcn32' incorporates:
  //   Fcn: '<S141>/Fcn31'
  //   Fcn: '<S53>/Fcn32'
  //   Trigonometry: '<S141>/sincos'

  rtb_VectorConcatenate_tmp_5 = Sum * rtb_TmpSignalConversionAtProd_1;
  rtb_VectorConcatenate[5] = rtb_VectorConcatenate_tmp_tmp *
    rtb_TrigonometricFunction4 - rtb_VectorConcatenate_tmp_5;

  // Fcn: '<S141>/Fcn13' incorporates:
  //   Trigonometry: '<S141>/sincos'

  rtb_VectorConcatenate[6] = -rtb_TmpSignalConversionAtProd_0;

  // Fcn: '<S141>/Fcn23' incorporates:
  //   Fcn: '<S53>/Fcn23'
  //   Trigonometry: '<S141>/sincos'

  rtb_TmpSignalConversionAtProd_1 *= rtb_Product1_tmp;
  rtb_VectorConcatenate[7] = rtb_TmpSignalConversionAtProd_1;

  // Fcn: '<S141>/Fcn33' incorporates:
  //   Fcn: '<S53>/Fcn33'
  //   Trigonometry: '<S141>/sincos'

  rtb_Product1_tmp *= DiscreteFilter1_tmp;
  rtb_VectorConcatenate[8] = rtb_Product1_tmp;
  for (int32_T i{0}; i < 3; i++) {
    // Trigonometry: '<S46>/sincos'
    DiscreteFilter1_tmp = rtb_sincos_o1[i];

    // Math: '<S139>/Math Function' incorporates:
    //   Concatenate: '<S194>/Vector Concatenate'

    rtb_MathFunction[3 * i] = rtb_VectorConcatenate[i];
    rtb_MathFunction[3 * i + 1] = rtb_VectorConcatenate[i + 3];
    rtb_MathFunction[3 * i + 2] = rtb_VectorConcatenate[i + 6];

    // Trigonometry: '<S46>/sincos'
    rtb_TmpSignalConversionAtProduc[i] = std::sin(DiscreteFilter1_tmp);
    rtb_FIR_IMUaccel[i] = std::cos(DiscreteFilter1_tmp);
  }

  // Fcn: '<S46>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_FIR_IMUaccel[0] * rtb_FIR_IMUaccel[1];

  // Fcn: '<S46>/Fcn21' incorporates:
  //   Fcn: '<S46>/Fcn22'

  rtb_Add_k_idx_0 = rtb_TmpSignalConversionAtProduc[1] *
    rtb_TmpSignalConversionAtProduc[2];
  rtb_VectorConcatenate_k[1] = rtb_Add_k_idx_0 * rtb_FIR_IMUaccel[0] -
    rtb_TmpSignalConversionAtProduc[0] * rtb_FIR_IMUaccel[2];

  // Fcn: '<S46>/Fcn31' incorporates:
  //   Fcn: '<S46>/Fcn32'

  rtb_Add_k_idx_1 = rtb_TmpSignalConversionAtProduc[1] * rtb_FIR_IMUaccel[2];
  rtb_VectorConcatenate_k[2] = rtb_Add_k_idx_1 * rtb_FIR_IMUaccel[0] +
    rtb_TmpSignalConversionAtProduc[0] * rtb_TmpSignalConversionAtProduc[2];

  // Fcn: '<S46>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_TmpSignalConversionAtProduc[0] *
    rtb_FIR_IMUaccel[1];

  // Fcn: '<S46>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_Add_k_idx_0 *
    rtb_TmpSignalConversionAtProduc[0] + rtb_FIR_IMUaccel[0] * rtb_FIR_IMUaccel
    [2];

  // Fcn: '<S46>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_Add_k_idx_1 *
    rtb_TmpSignalConversionAtProduc[0] - rtb_FIR_IMUaccel[0] *
    rtb_TmpSignalConversionAtProduc[2];

  // Fcn: '<S46>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_TmpSignalConversionAtProduc[1];

  // Fcn: '<S46>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_FIR_IMUaccel[1] *
    rtb_TmpSignalConversionAtProduc[2];

  // Fcn: '<S46>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_FIR_IMUaccel[1] * rtb_FIR_IMUaccel[2];

  // Math: '<S43>/Math Function' incorporates:
  //   Concatenate: '<S56>/Vector Concatenate'

  for (int32_T i{0}; i < 3; i++) {
    rtb_VectorConcatenate_g[3 * i] = rtb_VectorConcatenate_k[i];
    rtb_VectorConcatenate_g[3 * i + 1] = rtb_VectorConcatenate_k[i + 3];
    rtb_VectorConcatenate_g[3 * i + 2] = rtb_VectorConcatenate_k[i + 6];
  }

  std::memcpy(&rtb_VectorConcatenate_k[0], &rtb_VectorConcatenate_g[0], 9U *
              sizeof(real_T));

  // End of Math: '<S43>/Math Function'

  // DiscreteFir: '<S3>/FIR_IMUaccel'
  rtb_VectorConcatenate_tmp = inverseIMU_gain[0] *
    FCS_model_P.FIR_IMUaccel_Coefficients[0];
  cff = 1;
  for (int32_T i{FCS_model_DW.FIR_IMUaccel_circBuf}; i < 5; i++) {
    rtb_VectorConcatenate_tmp += FCS_model_DW.FIR_IMUaccel_states[i] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (int32_T i{0}; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_VectorConcatenate_tmp += FCS_model_DW.FIR_IMUaccel_states[i] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[0] = rtb_VectorConcatenate_tmp;
  rtb_VectorConcatenate_tmp = FCS_model_P.FIR_IMUaccel_Coefficients[0] *
    inverseIMU_gain[1];
  cff = 1;
  for (int32_T i{FCS_model_DW.FIR_IMUaccel_circBuf}; i < 5; i++) {
    rtb_VectorConcatenate_tmp += FCS_model_DW.FIR_IMUaccel_states[i + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (int32_T i{0}; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_VectorConcatenate_tmp += FCS_model_DW.FIR_IMUaccel_states[i + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[1] = rtb_VectorConcatenate_tmp;
  rtb_VectorConcatenate_tmp = FCS_model_P.FIR_IMUaccel_Coefficients[0] *
    inverseIMU_gain[2];
  cff = 1;
  for (int32_T i{FCS_model_DW.FIR_IMUaccel_circBuf}; i < 5; i++) {
    rtb_VectorConcatenate_tmp += FCS_model_DW.FIR_IMUaccel_states[i + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (int32_T i{0}; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_VectorConcatenate_tmp += FCS_model_DW.FIR_IMUaccel_states[i + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[2] = rtb_VectorConcatenate_tmp;

  // Sum: '<S3>/Sum3' incorporates:
  //   Constant: '<Root>/Constant'
  //   Inport: '<Root>/in_parameters'

  rtb_rangefinder_distance = arg_in_parameters->rangefinder_distance -
    FCS_model_P.sensorCalibrationData[7];

  // DiscreteFilter: '<S139>/Discrete Filter1'
  rtb_Add_g_idx_1 = rtb_rangefinder_distance;
  denIdx = 1;
  for (int32_T i{0}; i < 3; i++) {
    // Sum: '<S139>/Sum' incorporates:
    //   Constant: '<S139>/gravity'
    //   DiscreteFir: '<S3>/FIR_IMUaccel'
    //   Math: '<S139>/Math Function'
    //   Product: '<S139>/Product'

    rtb_TmpSignalConversionAtProduc[i] = ((rtb_MathFunction[i + 3] *
      rtb_FIR_IMUaccel[1] + rtb_MathFunction[i] * rtb_FIR_IMUaccel[0]) +
      rtb_MathFunction[i + 6] * rtb_VectorConcatenate_tmp) +
      FCS_model_P.gravity_Value[i];

    // DiscreteFilter: '<S139>/Discrete Filter1'
    rtb_Add_g_idx_1 -= FCS_model_P.DiscreteFilter1_DenCoef[denIdx] *
      FCS_model_DW.DiscreteFilter1_states[i];
    denIdx++;
  }

  // DiscreteFilter: '<S139>/Discrete Filter1'
  DiscreteFilter1_tmp = rtb_Add_g_idx_1 / FCS_model_P.DiscreteFilter1_DenCoef[0];

  // Product: '<S199>/Product5' incorporates:
  //   DiscreteFilter: '<S139>/Discrete Filter1'

  rtb_Product5 = ((FCS_model_P.DiscreteFilter1_NumCoef[0] * DiscreteFilter1_tmp
                   + FCS_model_DW.DiscreteFilter1_states[0] *
                   FCS_model_P.DiscreteFilter1_NumCoef[1]) +
                  FCS_model_DW.DiscreteFilter1_states[1] *
                  FCS_model_P.DiscreteFilter1_NumCoef[2]) +
    FCS_model_DW.DiscreteFilter1_states[2] *
    FCS_model_P.DiscreteFilter1_NumCoef[3];

  // Product: '<S199>/Product4' incorporates:
  //   Gain: '<S139>/RangfinderScaleGain1'

  rtb_Product4 = FCS_model_P.RangfinderScaleGain1_Gain * rtb_Product5;

  // Product: '<S139>/Product2' incorporates:
  //   Constant: '<S139>/Constant'
  //   Math: '<S139>/Math Function'
  //   SignalConversion generated from: '<S139>/Product2'

  for (int32_T i{0}; i < 3; i++) {
    rtb_sincos_o1[i] = (rtb_MathFunction[i + 3] * FCS_model_P.Constant_Value_e +
                        rtb_MathFunction[i] * FCS_model_P.Constant_Value_e) +
      rtb_MathFunction[i + 6] * rtb_Product4;
  }

  // End of Product: '<S139>/Product2'

  // Reshape: '<S140>/Reshapey'
  rtb_Reshapey[0] = rtb_sincos_o1[2];
  rtb_Reshapey[1] = rtb_TmpSignalConversionAtProduc[2];

  // Delay: '<S140>/MemoryX' incorporates:
  //   Constant: '<S140>/X0'

  if (FCS_model_DW.icLoad) {
    FCS_model_DW.MemoryX_DSTATE[0] = FCS_model_P.X0_Value[0];
    FCS_model_DW.MemoryX_DSTATE[1] = FCS_model_P.X0_Value[1];
    FCS_model_DW.MemoryX_DSTATE[2] = FCS_model_P.X0_Value[2];
    FCS_model_DW.MemoryX_DSTATE[3] = FCS_model_P.X0_Value[3];
  }

  // Outputs for Enabled SubSystem: '<S168>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S193>/Enable'

  // Outputs for Enabled SubSystem: '<S162>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S191>/Enable'

  // Constant: '<S140>/Enable'
  if (FCS_model_P.Enable_Value) {
    FCS_model_DW.MeasurementUpdate_MODE = true;

    // Product: '<S191>/D[k]*u[k]'
    rtb_Add_g_idx_0 = rtb_TmpSignalConversionAtProduc[2];
    for (int32_T i{0}; i < 2; i++) {
      // Product: '<S191>/C[k]*xhat[k|k-1]' incorporates:
      //   Constant: '<S140>/C'
      //   Delay: '<S140>/MemoryX'

      rtb_Add_g_idx_1 = ((FCS_model_P.C_Value[i + 2] *
                          FCS_model_DW.MemoryX_DSTATE[1] + FCS_model_P.C_Value[i]
                          * FCS_model_DW.MemoryX_DSTATE[0]) +
                         FCS_model_P.C_Value[i + 4] *
                         FCS_model_DW.MemoryX_DSTATE[2]) + FCS_model_P.C_Value[i
        + 6] * FCS_model_DW.MemoryX_DSTATE[3];

      // Sum: '<S191>/Sum' incorporates:
      //   Constant: '<S140>/D'
      //   Product: '<S191>/D[k]*u[k]'
      //   Sum: '<S191>/Add1'

      IIRgyroz_tmp[i] = rtb_Reshapey[i] - (FCS_model_P.D_Value[i] *
        rtb_Add_g_idx_0 + rtb_Add_g_idx_1);

      // Product: '<S191>/C[k]*xhat[k|k-1]' incorporates:
      //   Constant: '<S140>/C'
      //   Product: '<S193>/Product'

      rtb_Product_f[i] = rtb_Add_g_idx_1;
    }

    FCS_model_DW.EnabledSubsystem_MODE = true;

    // Sum: '<S193>/Add1' incorporates:
    //   Product: '<S193>/Product'
    //   Reshape: '<S140>/Reshapey'

    rtb_Add_g_idx_0 = rtb_sincos_o1[2] - rtb_Product_f[0];
    rtb_Add_g_idx_1 = rtb_TmpSignalConversionAtProduc[2] - rtb_Product_f[1];
    for (int32_T i{0}; i < 4; i++) {
      // Product: '<S191>/Product3' incorporates:
      //   Constant: '<S142>/KalmanGainL'

      FCS_model_B.Product3[i] = 0.0;
      FCS_model_B.Product3[i] += FCS_model_P.KalmanGainL_Value[i] *
        IIRgyroz_tmp[0];
      FCS_model_B.Product3[i] += FCS_model_P.KalmanGainL_Value[i + 4] *
        IIRgyroz_tmp[1];

      // Product: '<S193>/Product2' incorporates:
      //   Constant: '<S142>/KalmanGainM'

      FCS_model_B.Product2[i] = 0.0;
      FCS_model_B.Product2[i] += FCS_model_P.KalmanGainM_Value[i] *
        rtb_Add_g_idx_0;
      FCS_model_B.Product2[i] += FCS_model_P.KalmanGainM_Value[i + 4] *
        rtb_Add_g_idx_1;
    }
  } else {
    if (FCS_model_DW.MeasurementUpdate_MODE) {
      // Disable for Product: '<S191>/Product3' incorporates:
      //   Outport: '<S191>/L*(y[k]-yhat[k|k-1])'

      FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_DW.MeasurementUpdate_MODE = false;
    }

    if (FCS_model_DW.EnabledSubsystem_MODE) {
      // Disable for Product: '<S193>/Product2' incorporates:
      //   Outport: '<S193>/deltax'

      FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0_k;
      FCS_model_DW.EnabledSubsystem_MODE = false;
    }
  }

  // End of Constant: '<S140>/Enable'
  // End of Outputs for SubSystem: '<S162>/MeasurementUpdate'
  // End of Outputs for SubSystem: '<S168>/Enabled Subsystem'

  // Sum: '<S168>/Add' incorporates:
  //   Delay: '<S140>/MemoryX'

  rtb_Add_g_idx_0 = FCS_model_B.Product2[0] + FCS_model_DW.MemoryX_DSTATE[0];
  rtb_Add_g_idx_1 = FCS_model_B.Product2[1] + FCS_model_DW.MemoryX_DSTATE[1];

  // Logic: '<S31>/OR' incorporates:
  //   Constant: '<S27>/Constant'
  //   Inport: '<Root>/in_dashboard'
  //   Memory: '<S31>/Memory'
  //   RelationalOperator: '<S27>/GreaterThan'
  //   SignalConversion generated from: '<Root>/in_dashboard'

  FCS_model_DW.Memory_PreviousInput_j = ((static_cast<real_T>
    (arg_in_dashboard->master_switch) >= FCS_model_P.Constant_Value_i) ||
    FCS_model_DW.Memory_PreviousInput_j);

  // Product: '<S31>/Divide' incorporates:
  //   Constant: '<S31>/cycle_time'
  //   Constant: '<S31>/signal_max'
  //   Gain: '<S31>/Gain'

  rtb_Divide = FCS_model_P.signal_max_Value / (FCS_model_P.Gain_Gain *
    FCS_model_P.cycle_time_Value);

  // Chart: '<S31>/takeoff_acceleration' incorporates:
  //   Constant: '<S31>/Ts'
  //   Constant: '<S31>/signal_max'

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

  // End of Chart: '<S31>/takeoff_acceleration'

  // DiscreteStateSpace: '<S30>/Internal'
  {
    rtb_Product4 = (FCS_model_P.Internal_C[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_C[1])*FCS_model_DW.Internal_DSTATE[1];
  }

  // Product: '<S199>/Product5' incorporates:
  //   Gain: '<S27>/Gain'

  rtb_Product5 = FCS_model_P.Gain_Gain_f * rtb_Add_g_idx_0;

  // Sum: '<S27>/Sum1'
  rtb_Divide = rtb_Product4 - rtb_Product5;

  // SignalConversion generated from: '<S139>/Product1' incorporates:
  //   Constant: '<S40>/Constant'

  rtb_K_i = FCS_model_P.Constant_Value_c1[0];
  rtb_Saturation_l = FCS_model_P.Constant_Value_c1[1];

  // Product: '<S139>/Product1' incorporates:
  //   Concatenate: '<S194>/Vector Concatenate'
  //   SignalConversion generated from: '<S139>/Product1'

  for (int32_T i{0}; i < 3; i++) {
    rtb_sincos_o1[i] = (rtb_VectorConcatenate[i + 3] * rtb_Saturation_l +
                        rtb_VectorConcatenate[i] * rtb_K_i) +
      rtb_VectorConcatenate[i + 6] * rtb_Add_g_idx_1;
  }

  // End of Product: '<S139>/Product1'

  // Product: '<S199>/Product4' incorporates:
  //   Constant: '<S27>/Constant1'
  //   Constant: '<S31>/Constant'
  //   Gain: '<S27>/Gain1'
  //   Gain: '<S27>/KDz'
  //   Gain: '<S27>/WithControl=1 WithoutControl=0'
  //   Gain: '<S27>/WithTakeoff=1 WithoutTakeoff=0'
  //   Gain: '<S27>/zDz'
  //   Product: '<S31>/Product'
  //   Sum: '<S27>/Sum2'
  //   Sum: '<S27>/Sum3'
  //   Sum: '<S27>/Sum4'

  rtb_Product4 = FCS_model_P.Gain1_Gain * rtb_sincos_o1[2];
  rtb_Product4 = ((FCS_model_P.zDz * rtb_Divide - rtb_Product4) *
                  (FCS_model_P.KDz * 10.0) *
                  FCS_model_P.WithControl1WithoutControl0_Gai +
                  FCS_model_P.Vehicle.Airframe.mass * FCS_model_P.g) +
    FCS_model_P.Vehicle.Airframe.mass * FCS_model_B.signal_out *
    FCS_model_P.WithTakeoff1WithoutTakeoff0_Gai;

  // Saturate: '<S27>/SaturationThrust'
  rtb_Add_g_idx_1 = -4.0 * FCS_model_P.Controller.totalThrustMaxRelative *
    FCS_model_P.Controller.motorsThrustPerMotorMax;
  rtb_Divide = 4.0 * FCS_model_P.Controller.totalThrustMaxRelative *
    FCS_model_P.Controller.motorsThrustPerMotorMax;
  if (rtb_Product4 > rtb_Divide) {
    // Product: '<S199>/Product4'
    rtb_Product4 = rtb_Divide;
  } else if (rtb_Product4 < rtb_Add_g_idx_1) {
    // Product: '<S199>/Product4'
    rtb_Product4 = rtb_Add_g_idx_1;
  }

  // End of Saturate: '<S27>/SaturationThrust'

  // Product: '<S199>/Product4' incorporates:
  //   Gain: '<S1>/On=1//Off=0 for thrust'

  rtb_Product4 *= FCS_model_P.On1Off0forthrust_Gain;

  // DiscreteStateSpace: '<S23>/Internal'
  {
    rtb_Product5 = (FCS_model_P.Internal_C_j[0])*FCS_model_DW.Internal_DSTATE_f
      [0]
      + (FCS_model_P.Internal_C_j[1])*FCS_model_DW.Internal_DSTATE_f[1];
  }

  // Product: '<S199>/Product5' incorporates:
  //   Constant: '<S4>/yaw equilibrium'
  //   DiscreteFir: '<S3>/FIR_IMUaccel'
  //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'
  //   Gain: '<S10>/KDpsi'
  //   Gain: '<S10>/zDpsi'
  //   Gain: '<S1>/On=1//Off=1 for yaw'
  //   Gain: '<S4>/Changing of Jzz'
  //   Sum: '<S10>/Sum1'
  //   Sum: '<S10>/Sum3'
  //   Sum: '<S4>/Sum3'

  rtb_Product5 = FCS_model_P.zDpsi * 2.0 * (rtb_Product5 -
    rtb_AvoidDividebyZero_h);
  rtb_Product5 -= rtb_VectorConcatenate_tmp;
  rtb_Product5 = (FCS_model_P.KDpsi * 1.3 * rtb_Product5 *
                  FCS_model_P.ChangingofJzz_Gain +
                  FCS_model_P.yawequilibrium_Value) *
    FCS_model_P.On1Off1foryaw_Gain;

  // Delay: '<S50>/MemoryX' incorporates:
  //   Constant: '<S50>/X0'

  if (FCS_model_DW.icLoad_n) {
    FCS_model_DW.MemoryX_DSTATE_o[0] = FCS_model_P.X0_Value_h[0];
    FCS_model_DW.MemoryX_DSTATE_o[1] = FCS_model_P.X0_Value_h[1];
  }

  for (cff = 0; cff < 2; cff++) {
    // DiscreteFilter: '<S49>/IIRgyroz'
    memOffset = cff * 5;
    rtb_Add_g_idx_1 = inverseIMU_gain[cff + 3];
    denIdx = 1;
    for (int32_T i{0}; i < 5; i++) {
      rtb_Add_g_idx_1 -= FCS_model_DW.IIRgyroz_states[memOffset + i] *
        FCS_model_P.IIRgyroz_DenCoef[denIdx];
      denIdx++;
    }

    rtb_Add_g_idx_1 /= FCS_model_P.IIRgyroz_DenCoef[0];
    rtb_Divide = FCS_model_P.IIRgyroz_NumCoef[0] * rtb_Add_g_idx_1;
    denIdx = 1;
    for (int32_T i{0}; i < 5; i++) {
      rtb_Divide += FCS_model_DW.IIRgyroz_states[memOffset + i] *
        FCS_model_P.IIRgyroz_NumCoef[denIdx];
      denIdx++;
    }

    // SampleTimeMath: '<S57>/TSamp' incorporates:
    //   DiscreteFilter: '<S49>/IIRgyroz'
    //
    //  About '<S57>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )

    rtb_Divide *= FCS_model_P.TSamp_WtEt;

    // DiscreteFilter: '<S49>/IIRgyroz' incorporates:
    //   Sum: '<S57>/Diff'
    //   UnitDelay: '<S57>/UD'
    //
    //  Block description for '<S57>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S57>/UD':
    //
    //   Store in Global RAM

    IIRgyroz_tmp[cff] = rtb_Add_g_idx_1;
    rtb_SimplyIntegrateVelocity[cff] = rtb_Divide - FCS_model_DW.UD_DSTATE[cff];

    // SampleTimeMath: '<S57>/TSamp'
    //
    //  About '<S57>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )

    rtb_Reshapey[cff] = rtb_Divide;
  }

  // Abs: '<S49>/Abs' incorporates:
  //   Abs: '<S49>/Abs4'

  rtb_Add_g_idx_1 = std::abs(inverseIMU_gain[3]);

  // Abs: '<S49>/Abs1' incorporates:
  //   Abs: '<S49>/Abs5'

  rtb_Divide = std::abs(inverseIMU_gain[4]);

  // Logic: '<S49>/Logical Operator3' incorporates:
  //   Abs: '<S49>/Abs'
  //   Abs: '<S49>/Abs1'
  //   Abs: '<S49>/Abs2'
  //   Abs: '<S49>/Abs3'
  //   Abs: '<S49>/Abs6'
  //   Abs: '<S49>/Abs7'
  //   Abs: '<S49>/Abs8'
  //   Abs: '<S49>/Abs9'
  //   Constant: '<S58>/Constant'
  //   Constant: '<S59>/Constant'
  //   Constant: '<S60>/Constant'
  //   Constant: '<S61>/Constant'
  //   Constant: '<S62>/Constant'
  //   Constant: '<S63>/Constant'
  //   Constant: '<S64>/Constant'
  //   Constant: '<S65>/Constant'
  //   Constant: '<S66>/Constant'
  //   Constant: '<S67>/Constant'
  //   Constant: '<S68>/Constant'
  //   Delay: '<S44>/Delay'
  //   DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'
  //   Inport: '<Root>/in_parameters'
  //   Logic: '<S49>/Logical Operator'
  //   Logic: '<S49>/Logical Operator1'
  //   Logic: '<S49>/Logical Operator2'
  //   RelationalOperator: '<S58>/Compare'
  //   RelationalOperator: '<S59>/Compare'
  //   RelationalOperator: '<S60>/Compare'
  //   RelationalOperator: '<S61>/Compare'
  //   RelationalOperator: '<S62>/Compare'
  //   RelationalOperator: '<S63>/Compare'
  //   RelationalOperator: '<S64>/Compare'
  //   RelationalOperator: '<S65>/Compare'
  //   RelationalOperator: '<S66>/Compare'
  //   RelationalOperator: '<S67>/Compare'
  //   RelationalOperator: '<S68>/Compare'
  //   Sum: '<S49>/Add'

  rtb_LogicalOperator3 = ((((std::abs(rtb_AvoidDividebyZero) <=
    FCS_model_P.maxp_const) && (std::abs(rtb_AvoidDividebyZero_h) <=
    FCS_model_P.maxq_const) && (rtb_Add_g_idx_1 <= FCS_model_P.maxw1_const) &&
    (rtb_Divide <= FCS_model_P.maxw2_const) && (std::abs
    (rtb_SimplyIntegrateVelocity[0]) <= FCS_model_P.maxdw1_const) && (std::abs
    (rtb_SimplyIntegrateVelocity[1]) <= FCS_model_P.maxdw2_const)) ||
    ((rtb_Add_g_idx_1 <= FCS_model_P.maxp2_const) && (rtb_Divide <=
    FCS_model_P.maxq2_const))) && (std::abs(arg_in_parameters->opticalflow_x -
    FCS_model_DW.Delay_DSTATE[0]) <= FCS_model_P.maxw3_const) && (std::abs
    (arg_in_parameters->opticalflow_y - FCS_model_DW.Delay_DSTATE[1]) <=
    FCS_model_P.maxw4_const) && (rtb_Add_g_idx_0 <=
    FCS_model_P.minHeightforOF_const));

  // Logic: '<S131>/Logical Operator' incorporates:
  //   Constant: '<S131>/Constant'
  //   Constant: '<S131>/Time constant'
  //   Constant: '<S134>/Constant'
  //   Constant: '<S135>/Constant'
  //   RelationalOperator: '<S134>/Compare'
  //   RelationalOperator: '<S135>/Compare'
  //   Sum: '<S131>/Sum1'

  rtb_LogicalOperator_b = ((FCS_model_P.LowPassFilterDiscreteorContin_l -
    FCS_model_B.Probe[0] <= FCS_model_P.Constant_Value_o) &&
    (FCS_model_P.LowPassFilterDiscreteorContin_i <
     FCS_model_P.CompareToConstant_const));

  // Gain: '<S123>/K' incorporates:
  //   Inport: '<Root>/in_parameters'

  rtb_Add_g_idx_1 = FCS_model_P.LowPassFilterDiscreteorContinuo *
    arg_in_parameters->opticalflow_x;

  // DiscreteIntegrator: '<S137>/Integrator'
  if (FCS_model_DW.Integrator_IC_LOADING != 0) {
    FCS_model_DW.Integrator_DSTATE = rtb_Add_g_idx_1;
    if (FCS_model_DW.Integrator_DSTATE >= FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE <= FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  if (rtb_LogicalOperator_b || (FCS_model_DW.Integrator_PrevResetState != 0)) {
    FCS_model_DW.Integrator_DSTATE = rtb_Add_g_idx_1;
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

  // End of DiscreteIntegrator: '<S137>/Integrator'

  // Saturate: '<S137>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Saturation_UpperSat) {
    rtb_Divide = FCS_model_P.Saturation_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Saturation_LowerSat) {
    rtb_Divide = FCS_model_P.Saturation_LowerSat;
  } else {
    rtb_Divide = FCS_model_DW.Integrator_DSTATE;
  }

  // End of Saturate: '<S137>/Saturation'

  // Product: '<S199>/Product3' incorporates:
  //   Bias: '<S51>/Bias3'
  //   Delay: '<S51>/Delay2'
  //   Gain: '<S51>/Gain5'
  //   Product: '<S51>/Product3'
  //   Sum: '<S51>/Subtract3'

  rtb_Product3 = FCS_model_DW.Delay2_DSTATE[0];
  rtb_Product3 = (rtb_rangefinder_distance + FCS_model_P.Bias3_Bias) *
    FCS_model_P.Gain5_Gain * (rtb_Divide - rtb_Product3);

  // Logic: '<S124>/Logical Operator' incorporates:
  //   Constant: '<S124>/Constant'
  //   Constant: '<S124>/Time constant'
  //   Constant: '<S127>/Constant'
  //   Constant: '<S128>/Constant'
  //   RelationalOperator: '<S127>/Compare'
  //   RelationalOperator: '<S128>/Compare'
  //   Sum: '<S124>/Sum1'

  rtb_LogicalOperator_j = ((FCS_model_P.LowPassFilterDiscreteorContin_a -
    FCS_model_B.Probe_c[0] <= FCS_model_P.Constant_Value) &&
    (FCS_model_P.LowPassFilterDiscreteorConti_d0 <
     FCS_model_P.CompareToConstant_const_p));

  // Gain: '<S122>/K' incorporates:
  //   Inport: '<Root>/in_parameters'

  rtb_K_i = FCS_model_P.LowPassFilterDiscreteorContin_d *
    arg_in_parameters->opticalflow_y;

  // DiscreteIntegrator: '<S130>/Integrator'
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

  // End of DiscreteIntegrator: '<S130>/Integrator'

  // Saturate: '<S130>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Saturation_UpperSat_k) {
    rtb_Saturation_l = FCS_model_P.Saturation_UpperSat_k;
  } else if (FCS_model_DW.Integrator_DSTATE_e <
             FCS_model_P.Saturation_LowerSat_h) {
    rtb_Saturation_l = FCS_model_P.Saturation_LowerSat_h;
  } else {
    rtb_Saturation_l = FCS_model_DW.Integrator_DSTATE_e;
  }

  // End of Saturate: '<S130>/Saturation'

  // Reshape: '<S50>/Reshapey' incorporates:
  //   Bias: '<S51>/Bias2'
  //   Delay: '<S51>/Delay1'
  //   Gain: '<S51>/Gain4'
  //   Product: '<S51>/Product2'
  //   Sum: '<S51>/Subtract2'

  rtb_SimplyIntegrateVelocity[0] = rtb_Product3;
  rtb_SimplyIntegrateVelocity[1] = (rtb_rangefinder_distance +
    FCS_model_P.Bias2_Bias) * FCS_model_P.Gain4_Gain * (rtb_Saturation_l -
    FCS_model_DW.Delay1_DSTATE[0U]);

  // Outputs for Enabled SubSystem: '<S95>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S121>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.EnabledSubsystem_MODE_g = true;

    // Sum: '<S121>/Add1' incorporates:
    //   Constant: '<S50>/C'
    //   Delay: '<S50>/MemoryX'
    //   Product: '<S121>/Product'
    //   Reshape: '<S50>/Reshapey'

    rtb_Add_k_idx_0 = rtb_Product3 - (FCS_model_P.C_Value_h[0] *
      FCS_model_DW.MemoryX_DSTATE_o[0] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[2]);
    rtb_Add_k_idx_1 = rtb_SimplyIntegrateVelocity[1] -
      (FCS_model_DW.MemoryX_DSTATE_o[0] * FCS_model_P.C_Value_h[1] +
       FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.C_Value_h[3]);

    // Product: '<S121>/Product2' incorporates:
    //   Constant: '<S69>/KalmanGainM'

    FCS_model_B.Product2_c[0] = FCS_model_P.KalmanGainM_Value_e[0] *
      rtb_Add_k_idx_0;
    FCS_model_B.Product2_c[0] += FCS_model_P.KalmanGainM_Value_e[2] *
      rtb_Add_k_idx_1;
    FCS_model_B.Product2_c[1] = FCS_model_P.KalmanGainM_Value_e[1] *
      rtb_Add_k_idx_0;
    FCS_model_B.Product2_c[1] += FCS_model_P.KalmanGainM_Value_e[3] *
      rtb_Add_k_idx_1;
  } else if (FCS_model_DW.EnabledSubsystem_MODE_g) {
    // Disable for Product: '<S121>/Product2' incorporates:
    //   Outport: '<S121>/deltax'

    FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;
    FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;
    FCS_model_DW.EnabledSubsystem_MODE_g = false;
  }

  // End of Outputs for SubSystem: '<S95>/Enabled Subsystem'

  // Sum: '<S95>/Add' incorporates:
  //   Delay: '<S44>/Delay'
  //   Delay: '<S50>/MemoryX'

  FCS_model_DW.Delay_DSTATE[0] = FCS_model_B.Product2_c[0] +
    FCS_model_DW.MemoryX_DSTATE_o[0];
  FCS_model_DW.Delay_DSTATE[1] = FCS_model_B.Product2_c[1] +
    FCS_model_DW.MemoryX_DSTATE_o[1];

  // Product: '<S199>/Product3' incorporates:
  //   DiscreteIntegrator: '<S43>/SimplyIntegrateVelocity'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S28>/Subtract'

  rtb_Product3 = arg_in_dashboard->ref_x;
  rtb_Product3 -= FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0];

  // Gain: '<S28>/Gain1' incorporates:
  //   Delay: '<S44>/Delay'
  //   Gain: '<S28>/Gain3'
  //   Gain: '<S28>/Gain4'
  //   Sum: '<S28>/Sum1'

  rtb_rollrate = (FCS_model_P.Gain3_Gain * rtb_Product3 -
                  FCS_model_P.Gain4_Gain_m * FCS_model_DW.Delay_DSTATE[0]) *
    FCS_model_P.Gain1_Gain_b;

  // Saturate: '<S28>/Saturation'
  if (rtb_rollrate > FCS_model_P.Saturation_UpperSat_d) {
    rtb_rollrate = FCS_model_P.Saturation_UpperSat_d;
  } else if (rtb_rollrate < FCS_model_P.Saturation_LowerSat_a) {
    rtb_rollrate = FCS_model_P.Saturation_LowerSat_a;
  }

  // End of Saturate: '<S28>/Saturation'

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch1_Threshold) {
    // Product: '<S199>/Product3'
    rtb_Product3 = rtb_rollrate;
  } else {
    // Product: '<S199>/Product3' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Product3 = arg_in_dashboard->ref_pitch;
  }

  // End of Switch: '<S4>/Switch1'

  // Sum: '<S8>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'

  rtb_Sum1_a = rtb_Product3 - rtb_AvoidDividebyZero;

  // DiscreteStateSpace: '<S11>/Internal'
  {
    rtb_Product3 = FCS_model_P.Internal_C_p*FCS_model_DW.Internal_DSTATE_d;
    rtb_Product3 += FCS_model_P.Internal_D_b*rtb_Sum1_a;
  }

  // Product: '<S199>/Product3' incorporates:
  //   Constant: '<S4>/pitch equilibrium'
  //   Gain: '<S1>/On=1//Off=2 for pitch'
  //   Gain: '<S4>/Changing of Jyy'
  //   Gain: '<S8>/KDtheta'
  //   Gain: '<S8>/zDtheta'
  //   Sum: '<S4>/Sum1'
  //   Sum: '<S8>/Sum3'

  rtb_Product3 *= FCS_model_P.zDtheta * 7.0;
  rtb_Product3 -= inverseIMU_gain[4];
  rtb_Product3 = (FCS_model_P.KDtheta * 1.4 * rtb_Product3 *
                  FCS_model_P.ChangingofJyy_Gain +
                  FCS_model_P.pitchequilibrium_Value) *
    FCS_model_P.On1Off2forpitch_Gain;

  // DiscreteStateSpace: '<S15>/Internal'
  {
    rtb_roll = (FCS_model_P.Internal_C_n[0])*FCS_model_DW.Internal_DSTATE_k[0]
      + (FCS_model_P.Internal_C_n[1])*FCS_model_DW.Internal_DSTATE_k[1];
  }

  // Sum: '<S9>/Sum1'
  rtb_Sum1_di = rtb_roll - FCS_model_DW.Memory_PreviousInput;

  // DiscreteStateSpace: '<S16>/Internal'
  {
    rtb_roll = FCS_model_P.Internal_C_a*FCS_model_DW.Internal_DSTATE_kj;
    rtb_roll += FCS_model_P.Internal_D_jy*rtb_Sum1_di;
  }

  // Trigonometry: '<S198>/Trigonometric Function' incorporates:
  //   Constant: '<S4>/roll equilibrium'
  //   Gain: '<S1>/On=1//Off=1 for roll'
  //   Gain: '<S4>/Changing of Jxx'
  //   Gain: '<S9>/KDphi'
  //   Gain: '<S9>/zDphi'
  //   Sum: '<S4>/Sum2'
  //   Sum: '<S9>/Sum3'

  rtb_roll *= FCS_model_P.zDphi * 7.0;
  rtb_roll -= inverseIMU_gain[3];
  rtb_roll = (FCS_model_P.KDphi * 1.4 * rtb_roll *
              FCS_model_P.ChangingofJxx_Gain + FCS_model_P.rollequilibrium_Value)
    * FCS_model_P.On1Off1forroll_Gain;
  for (int32_T i{0}; i < 4; i++) {
    // Saturate: '<S37>/Saturation' incorporates:
    //   Bias: '<S38>/Bias'
    //   Constant: '<S36>/TorqueTotalThrustToThrustPerMotor'
    //   Gain: '<S38>/thrustToMotor'
    //   Inport: '<Root>/in_dashboard'
    //   Product: '<S36>/Product'
    //   Product: '<S37>/Product'
    //   SignalConversion generated from: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<S36>/Product'

    rtb_Add_k_idx_0 = ((((FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 4] *
                          rtb_Product5 +
                          FCS_model_P.TorqueTotalThrustToThrustPerMot[i] *
                          rtb_Product4) +
                         FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 8] *
                         rtb_Product3) +
                        FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 12] *
                        rtb_roll) *
                       FCS_model_P.Vehicle.Motor.thrustToMotorCommand +
                       FCS_model_P.Vehicle.Motor.commandToW2Offset) *
      arg_in_dashboard->power;
    if (rtb_Add_k_idx_0 > FCS_model_P.Vehicle.Motor.maxLimit) {
      rtb_Add_k_idx_0 = FCS_model_P.Vehicle.Motor.maxLimit;
    } else if (rtb_Add_k_idx_0 < FCS_model_P.Vehicle.Motor.minLimit) {
      rtb_Add_k_idx_0 = FCS_model_P.Vehicle.Motor.minLimit;
    }

    // Product: '<S37>/Product1' incorporates:
    //   Gain: '<S38>/thrustToMotor'
    //   Inport: '<Root>/in_dashboard'
    //   Saturate: '<S37>/Saturation'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Product1_i[i] = rtb_Add_k_idx_0 * static_cast<real_T>
      (arg_in_dashboard->master_switch);
  }

  // SignalConversion generated from: '<S43>/Product' incorporates:
  //   Delay: '<S44>/Delay'

  rtb_Add_k_idx_0 = FCS_model_DW.Delay_DSTATE[0];
  rtb_Add_k_idx_1 = FCS_model_DW.Delay_DSTATE[1];
  rtb_Add_k_idx_2 = rtb_sincos_o1[2];

  // Product: '<S43>/Product' incorporates:
  //   Concatenate: '<S56>/Vector Concatenate'

  for (int32_T i{0}; i < 3; i++) {
    rtb_Product_k[i] = (rtb_VectorConcatenate_k[i + 3] * rtb_Add_k_idx_1 +
                        rtb_VectorConcatenate_k[i] * rtb_Add_k_idx_0) +
      rtb_VectorConcatenate_k[i + 6] * rtb_Add_k_idx_2;
  }

  // End of Product: '<S43>/Product'

  // Fcn: '<S53>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_tmp_0;

  // Fcn: '<S53>/Fcn21'
  rtb_VectorConcatenate_k[1] = DiscreteFilter1_tmp_tmp * Sum -
    rtb_VectorConcatenate_tmp_1;

  // Fcn: '<S53>/Fcn31'
  rtb_VectorConcatenate_k[2] = rtb_VectorConcatenate_tmp_tmp * Sum +
    rtb_VectorConcatenate_tmp_2;

  // Fcn: '<S53>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_VectorConcatenate_tmp_3;

  // Fcn: '<S53>/Fcn22'
  rtb_VectorConcatenate_k[4] = DiscreteFilter1_tmp_tmp *
    rtb_TrigonometricFunction4 + rtb_VectorConcatenate_tmp_4;

  // Fcn: '<S53>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_VectorConcatenate_tmp_tmp *
    rtb_TrigonometricFunction4 - rtb_VectorConcatenate_tmp_5;

  // Fcn: '<S53>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_TmpSignalConversionAtProd_0;

  // Fcn: '<S53>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_TmpSignalConversionAtProd_1;

  // Fcn: '<S53>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_Product1_tmp;

  // RelationalOperator: '<S52>/Compare' incorporates:
  //   Constant: '<S52>/Constant'

  rtb_Compare_jy = (rtb_Add_g_idx_0 <=
                    FCS_model_P.DeactivateAccelerationIfOFisnot);

  // Logic: '<S48>/Logical Operator' incorporates:
  //   Constant: '<S54>/Constant'
  //   Constant: '<S55>/Constant'
  //   Inport: '<Root>/in_parameters'
  //   RelationalOperator: '<S54>/Compare'
  //   RelationalOperator: '<S55>/Compare'

  rtb_LogicalOperator_c = ((arg_in_parameters->opticalflow_x !=
    FCS_model_P.donotuseaccifopticalflowneverav) ||
    (arg_in_parameters->opticalflow_y !=
     FCS_model_P.donotuseaccifopticalflownever_c));

  // Sum: '<S48>/Add' incorporates:
  //   Concatenate: '<S56>/Vector Concatenate'
  //   Constant: '<S48>/gravity'
  //   Product: '<S48>/Product1'

  for (int32_T i{0}; i < 3; i++) {
    rtb_FIR_IMUaccel_0[i] = rtb_FIR_IMUaccel[i] - ((rtb_VectorConcatenate_k[i +
      3] * FCS_model_P.gravity_Value_a[1] + rtb_VectorConcatenate_k[i] *
      FCS_model_P.gravity_Value_a[0]) + rtb_VectorConcatenate_k[i + 6] *
      FCS_model_P.gravity_Value_a[2]);
  }

  // End of Sum: '<S48>/Add'

  // Product: '<S48>/Product' incorporates:
  //   Gain: '<S48>/gainaccinput'

  rtb_Product_f[0] = FCS_model_P.gainaccinput_Gain * rtb_FIR_IMUaccel_0[0] *
    static_cast<real_T>(rtb_LogicalOperator_c) * static_cast<real_T>
    (rtb_Compare_jy);
  rtb_Product_f[1] = FCS_model_P.gainaccinput_Gain * rtb_FIR_IMUaccel_0[1] *
    static_cast<real_T>(rtb_LogicalOperator_c) * static_cast<real_T>
    (rtb_Compare_jy);

  // Outputs for Enabled SubSystem: '<S88>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S119>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.MeasurementUpdate_MODE_h = true;

    // Sum: '<S119>/Sum' incorporates:
    //   Constant: '<S50>/C'
    //   Constant: '<S50>/D'
    //   Delay: '<S50>/MemoryX'
    //   Product: '<S119>/C[k]*xhat[k|k-1]'
    //   Product: '<S119>/D[k]*u[k]'
    //   Sum: '<S119>/Add1'

    rtb_Add_k_idx_0 = rtb_SimplyIntegrateVelocity[0] - ((FCS_model_P.C_Value_h[0]
      * FCS_model_DW.MemoryX_DSTATE_o[0] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[2]) + (FCS_model_P.D_Value_b[0] * rtb_Product_f[0] +
      rtb_Product_f[1] * FCS_model_P.D_Value_b[2]));
    rtb_Add_k_idx_1 = rtb_SimplyIntegrateVelocity[1] -
      ((FCS_model_DW.MemoryX_DSTATE_o[0] * FCS_model_P.C_Value_h[1] +
        FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.C_Value_h[3]) +
       (rtb_Product_f[0] * FCS_model_P.D_Value_b[1] + rtb_Product_f[1] *
        FCS_model_P.D_Value_b[3]));

    // Product: '<S119>/Product3' incorporates:
    //   Constant: '<S69>/KalmanGainL'

    FCS_model_B.Product3_d[0] = FCS_model_P.KalmanGainL_Value_f[0] *
      rtb_Add_k_idx_0;
    FCS_model_B.Product3_d[0] += FCS_model_P.KalmanGainL_Value_f[2] *
      rtb_Add_k_idx_1;
    FCS_model_B.Product3_d[1] = FCS_model_P.KalmanGainL_Value_f[1] *
      rtb_Add_k_idx_0;
    FCS_model_B.Product3_d[1] += FCS_model_P.KalmanGainL_Value_f[3] *
      rtb_Add_k_idx_1;
  } else if (FCS_model_DW.MeasurementUpdate_MODE_h) {
    // Disable for Product: '<S119>/Product3' incorporates:
    //   Outport: '<S119>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_DW.MeasurementUpdate_MODE_h = false;
  }

  // End of Outputs for SubSystem: '<S88>/MeasurementUpdate'

  // DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
  //   Delay: '<S44>/Delay'
  //   DiscreteIntegrator: '<S43>/SimplyIntegrateVelocity'
  //   Gain: '<S29>/Gain1'
  //   Gain: '<S29>/Gain3'
  //   Gain: '<S29>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S29>/Subtract'
  //   Sum: '<S29>/Sum1'

  rtb_Switch2 = ((arg_in_dashboard->ref_y -
                  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1]) *
                 FCS_model_P.Gain3_Gain_i - FCS_model_P.Gain4_Gain_h *
                 FCS_model_DW.Delay_DSTATE[1]) * FCS_model_P.Gain1_Gain_i;

  // Saturate: '<S29>/Saturation'
  if (rtb_Switch2 > FCS_model_P.Saturation_UpperSat_ku) {
    // DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
    rtb_Switch2 = FCS_model_P.Saturation_UpperSat_ku;
  } else if (rtb_Switch2 < FCS_model_P.Saturation_LowerSat_j) {
    // DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
    rtb_Switch2 = FCS_model_P.Saturation_LowerSat_j;
  }

  // End of Saturate: '<S29>/Saturation'

  // Outport: '<Root>/out_controllers' incorporates:
  //   BusCreator generated from: '<Root>/out_controllers'
  //   Constant: '<S6>/Constant'

  arg_out_controllers->motor1 = rtb_Product1_i[0];
  arg_out_controllers->motor2 = rtb_Product1_i[1];
  arg_out_controllers->motor3 = rtb_Product1_i[2];
  arg_out_controllers->motor4 = rtb_Product1_i[3];
  arg_out_controllers->cmd_thrust = rtb_Product4;
  arg_out_controllers->cmd_tau_roll = rtb_Product5;
  arg_out_controllers->cmd_tau_pitch = rtb_Product3;
  arg_out_controllers->cmd_tau_yaw = rtb_roll;
  arg_out_controllers->cmd_roll = rtb_rollrate;
  arg_out_controllers->cmd_pitch = rtb_Switch2;
  arg_out_controllers->cmd_yaw = FCS_model_P.Constant_Value_e2;

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (!(FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch2_Threshold)) {
    // DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'
    //   Switch: '<S4>/Switch2'

    rtb_Switch2 = arg_in_dashboard->ref_roll;
  }

  // End of Switch: '<S4>/Switch2'

  // Outport: '<Root>/out_estimators' incorporates:
  //   BusCreator generated from: '<Root>/out_estimators'
  //   Delay: '<S44>/Delay'
  //   DiscreteFir: '<S3>/FIR_IMUaccel'
  //   DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S43>/SimplyIntegrateVelocity'
  //   DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'
  //   Gain: '<S39>/Gain'

  arg_out_estimators->orient_roll = FCS_model_DW.Memory_PreviousInput;
  arg_out_estimators->orient_pitch = rtb_AvoidDividebyZero;
  arg_out_estimators->orient_yaw = rtb_AvoidDividebyZero_h;
  arg_out_estimators->orient_rate_roll = inverseIMU_gain[3];
  arg_out_estimators->orient_rate_pitch = inverseIMU_gain[4];
  arg_out_estimators->orient_rate_yaw = rtb_VectorConcatenate_tmp;
  arg_out_estimators->pos_x = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0];
  arg_out_estimators->pos_y = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1];
  arg_out_estimators->pos_z = rtb_Add_g_idx_0;
  arg_out_estimators->pos_dx = FCS_model_DW.Delay_DSTATE[0];
  arg_out_estimators->pos_dy = FCS_model_DW.Delay_DSTATE[1];
  arg_out_estimators->pos_dz = rtb_sincos_o1[2];
  arg_out_estimators->battery_SOC = FCS_model_P.Gain_Gain_h *
    FCS_model_DW.DiscreteTimeIntegrator_DSTATE;

  // MinMax: '<S124>/Max' incorporates:
  //   Constant: '<S124>/Time constant'

  rtb_TrigonometricFunction4 = std::fmax(FCS_model_B.Probe_c[0],
    FCS_model_P.LowPassFilterDiscreteorContin_a);

  // Fcn: '<S124>/Avoid Divide by Zero'
  rtb_AvoidDividebyZero = static_cast<real_T>(rtb_TrigonometricFunction4 == 0.0)
    * 2.2204460492503131e-16 + rtb_TrigonometricFunction4;

  // MinMax: '<S131>/Max' incorporates:
  //   Constant: '<S131>/Time constant'

  rtb_TrigonometricFunction4 = std::fmax(FCS_model_B.Probe[0],
    FCS_model_P.LowPassFilterDiscreteorContin_l);

  // Fcn: '<S131>/Avoid Divide by Zero'
  rtb_AvoidDividebyZero_h = static_cast<real_T>(rtb_TrigonometricFunction4 ==
    0.0) * 2.2204460492503131e-16 + rtb_TrigonometricFunction4;

  // Outport: '<Root>/out_sensors' incorporates:
  //   BusCreator generated from: '<Root>/out_sensors'
  //   Constant: '<Root>/Constant'
  //   DiscreteFir: '<S3>/FIR_IMUaccel'
  //   Inport: '<Root>/in_parameters'
  //   Sum: '<S3>/Sum2'

  arg_out_sensors->accelerometer_x = rtb_FIR_IMUaccel[0];
  arg_out_sensors->accelerometer_y = rtb_FIR_IMUaccel[1];
  arg_out_sensors->accelerometer_z = rtb_VectorConcatenate_tmp;
  arg_out_sensors->gyroscope_x = inverseIMU_gain[3];
  arg_out_sensors->gyroscope_y = inverseIMU_gain[4];
  arg_out_sensors->gyroscope_z = inverseIMU_gain[5];
  arg_out_sensors->barometer_pressure = arg_in_parameters->barometer_pressure -
    FCS_model_P.sensorCalibrationData[6];
  arg_out_sensors->rangefinder_distance = rtb_rangefinder_distance;

  // Product: '<S198>/Divide' incorporates:
  //   Constant: '<S198>/Constant'
  //   Gain: '<S198>/Gain1'

  rtb_Add_k_idx_0 = FCS_model_P.Gain1_Gain_e * rtb_FIR_IMUaccel[0] /
    FCS_model_P.g;

  // Trigonometry: '<S198>/Trigonometric Function1'
  if (rtb_Add_k_idx_0 > 1.0) {
    rtb_Add_k_idx_0 = 1.0;
  } else if (rtb_Add_k_idx_0 < -1.0) {
    rtb_Add_k_idx_0 = -1.0;
  }

  // Gain: '<S198>/Gain' incorporates:
  //   Trigonometry: '<S198>/Trigonometric Function1'

  rtb_TrigonometricFunction4 = FCS_model_P.Gain_Gain_e * std::asin
    (rtb_Add_k_idx_0);

  // Trigonometry: '<S198>/Trigonometric Function' incorporates:
  //   DiscreteFir: '<S3>/FIR_IMUaccel'
  //   Gain: '<S198>/Gain2'
  //   Gain: '<S198>/Gain3'

  rtb_roll = FCS_model_P.Gain2_Gain * rtb_FIR_IMUaccel[1];
  rtb_roll = rt_atan2d_snf(rtb_roll, FCS_model_P.Gain3_Gain_h *
    rtb_VectorConcatenate_tmp);

  // Trigonometry: '<S199>/Trigonometric Function2'
  rtb_rollrate = std::sin(rtb_roll);

  // Product: '<S199>/Product3' incorporates:
  //   Trigonometry: '<S199>/Trigonometric Function2'

  rtb_Product3 = std::cos(rtb_roll);

  // Product: '<S199>/Product4'
  rtb_Product4 = rtb_Product3 * inverseIMU_gain[4];

  // Product: '<S199>/Product5' incorporates:
  //   Gain: '<S199>/Gain'

  rtb_Product5 = FCS_model_P.Gain_Gain_p * rtb_rollrate;
  rtb_Product5 *= inverseIMU_gain[5];

  // Sum: '<S196>/Sum' incorporates:
  //   Gain: '<S196>/Gain'
  //   Sum: '<S199>/Sum1'

  Sum = FCS_model_P.w_c_pitch * rtb_TrigonometricFunction4 + (rtb_Product4 +
    rtb_Product5);

  // Trigonometry: '<S199>/Trigonometric Function4'
  rtb_TrigonometricFunction4 = std::tan(rtb_TrigonometricFunction4);

  // Product: '<S199>/Product3' incorporates:
  //   Product: '<S199>/Product1'

  rtb_Product3 *= rtb_TrigonometricFunction4;
  rtb_Product3 *= inverseIMU_gain[5];

  // SignalConversion generated from: '<Root>/in_dashboard' incorporates:
  //   Inport: '<Root>/in_dashboard'

  rtb_ref_z = arg_in_dashboard->ref_z;

  // SignalConversion generated from: '<Root>/in_dashboard' incorporates:
  //   Inport: '<Root>/in_dashboard'

  rtb_ref_yaw = arg_in_dashboard->ref_yaw;

  // Update for DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states = (Sum -
    FCS_model_P.DiscreteTransferFcn_DenCoef_b[1] *
    FCS_model_DW.DiscreteTransferFcn_states) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_b[0];

  // Update for DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn' incorporates:
  //   Gain: '<S197>/Gain'
  //   Product: '<S199>/Product'
  //   Product: '<S199>/Product2'
  //   Sum: '<S197>/Sum'
  //   Sum: '<S199>/Sum'

  FCS_model_DW.DiscreteTransferFcn_states_j = ((((rtb_rollrate *
    rtb_TrigonometricFunction4 * inverseIMU_gain[4] + inverseIMU_gain[3]) +
    rtb_Product3) + FCS_model_P.w_c_roll * rtb_roll) -
    FCS_model_P.DiscreteTransferFcn_DenCoef_p[1] *
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

  // Update for DiscreteFilter: '<S139>/Discrete Filter1'
  FCS_model_DW.DiscreteFilter1_states[2] = FCS_model_DW.DiscreteFilter1_states[1];
  FCS_model_DW.DiscreteFilter1_states[1] = FCS_model_DW.DiscreteFilter1_states[0];
  FCS_model_DW.DiscreteFilter1_states[0] = DiscreteFilter1_tmp;

  // Update for Delay: '<S140>/MemoryX'
  FCS_model_DW.icLoad = false;

  // Product: '<S162>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S140>/A'
  //   Delay: '<S140>/MemoryX'

  for (int32_T i{0}; i < 4; i++) {
    rtb_Product1_i[i] = ((FCS_model_P.A_Value[i + 4] *
                          FCS_model_DW.MemoryX_DSTATE[1] + FCS_model_P.A_Value[i]
                          * FCS_model_DW.MemoryX_DSTATE[0]) +
                         FCS_model_P.A_Value[i + 8] *
                         FCS_model_DW.MemoryX_DSTATE[2]) + FCS_model_P.A_Value[i
      + 12] * FCS_model_DW.MemoryX_DSTATE[3];
  }

  // End of Product: '<S162>/A[k]*xhat[k|k-1]'

  // Update for Delay: '<S140>/MemoryX' incorporates:
  //   Constant: '<S140>/B'
  //   Product: '<S162>/B[k]*u[k]'
  //   Product: '<S191>/Product3'
  //   Sum: '<S162>/Add'

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

  // Update for DiscreteStateSpace: '<S30>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_A[1])*FCS_model_DW.Internal_DSTATE[1];
    xnew[0] += FCS_model_P.Internal_B*rtb_ref_z;
    xnew[1] = (FCS_model_P.Internal_A[2])*FCS_model_DW.Internal_DSTATE[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteStateSpace: '<S23>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_l[0])*FCS_model_DW.Internal_DSTATE_f[0]
      + (FCS_model_P.Internal_A_l[1])*FCS_model_DW.Internal_DSTATE_f[1];
    xnew[0] += FCS_model_P.Internal_B_e*rtb_ref_yaw;
    xnew[1] = (FCS_model_P.Internal_A_l[2])*FCS_model_DW.Internal_DSTATE_f[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_f[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for Delay: '<S50>/MemoryX'
  FCS_model_DW.icLoad_n = false;

  // Product: '<S88>/B[k]*u[k]' incorporates:
  //   Constant: '<S50>/B'

  rtb_SimplyIntegrateVelocity[0] = FCS_model_P.B_Value_p[0] * rtb_Product_f[0] +
    rtb_Product_f[1] * FCS_model_P.B_Value_p[2];

  // Product: '<S88>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S50>/A'
  //   Delay: '<S50>/MemoryX'

  tmp[0] = FCS_model_P.A_Value_p[0] * FCS_model_DW.MemoryX_DSTATE_o[0] +
    FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.A_Value_p[2];

  // Product: '<S88>/B[k]*u[k]' incorporates:
  //   Constant: '<S50>/B'

  rtb_SimplyIntegrateVelocity[1] = rtb_Product_f[0] * FCS_model_P.B_Value_p[1] +
    rtb_Product_f[1] * FCS_model_P.B_Value_p[3];

  // Product: '<S88>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S50>/A'
  //   Delay: '<S50>/MemoryX'

  tmp[1] = FCS_model_DW.MemoryX_DSTATE_o[0] * FCS_model_P.A_Value_p[1] +
    FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.A_Value_p[3];
  for (cff = 0; cff < 2; cff++) {
    // Update for Delay: '<S50>/MemoryX' incorporates:
    //   Sum: '<S88>/Add'

    FCS_model_DW.MemoryX_DSTATE_o[cff] = (rtb_SimplyIntegrateVelocity[cff] +
      tmp[cff]) + FCS_model_B.Product3_d[cff];

    // Update for DiscreteFilter: '<S49>/IIRgyroz'
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

    // Update for UnitDelay: '<S57>/UD'
    //
    //  Block description for '<S57>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[cff] = rtb_Reshapey[cff];
  }

  // Update for DiscreteIntegrator: '<S137>/Integrator' incorporates:
  //   Product: '<S123>/1//T'
  //   Sum: '<S123>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING = 0U;
  FCS_model_DW.Integrator_DSTATE += 1.0 / rtb_AvoidDividebyZero_h *
    (rtb_Add_g_idx_1 - rtb_Divide) * FCS_model_P.Integrator_gainval;
  if (FCS_model_DW.Integrator_DSTATE >= FCS_model_P.Integrator_UpperSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE <= FCS_model_P.Integrator_LowerSat)
  {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
  }

  FCS_model_DW.Integrator_PrevResetState = static_cast<int8_T>
    (rtb_LogicalOperator_b);

  // End of Update for DiscreteIntegrator: '<S137>/Integrator'

  // Update for Delay: '<S51>/Delay2'
  for (int32_T i{0}; i < 39; i++) {
    FCS_model_DW.Delay2_DSTATE[i] = FCS_model_DW.Delay2_DSTATE[i + 1];
  }

  FCS_model_DW.Delay2_DSTATE[39] = inverseIMU_gain[3];

  // End of Update for Delay: '<S51>/Delay2'

  // Update for DiscreteIntegrator: '<S130>/Integrator' incorporates:
  //   Product: '<S122>/1//T'
  //   Sum: '<S122>/Sum1'

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

  // End of Update for DiscreteIntegrator: '<S130>/Integrator'

  // Update for Delay: '<S51>/Delay1'
  for (int32_T i{0}; i < 39; i++) {
    FCS_model_DW.Delay1_DSTATE[i] = FCS_model_DW.Delay1_DSTATE[i + 1];
  }

  FCS_model_DW.Delay1_DSTATE[39] = inverseIMU_gain[4];

  // End of Update for Delay: '<S51>/Delay1'

  // Update for DiscreteIntegrator: '<S43>/SimplyIntegrateVelocity'
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

  // Update for DiscreteStateSpace: '<S16>/Internal'
  {
    real_T xnew[1];
    xnew[0] = FCS_model_P.Internal_A_n*FCS_model_DW.Internal_DSTATE_kj;
    xnew[0] += FCS_model_P.Internal_B_j*rtb_Sum1_di;
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_kj, xnew,
                       sizeof(real_T)*1);
  }

  // Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/in_parameters'

  FCS_model_DW.DiscreteTimeIntegrator_DSTATE +=
    FCS_model_P.DiscreteTimeIntegrator_gainval *
    arg_in_parameters->battery_current;
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

  // Start for Probe: '<S131>/Probe'
  FCS_model_B.Probe[0] = 0.0025;
  FCS_model_B.Probe[1] = 0.0;

  // Start for Probe: '<S124>/Probe'
  FCS_model_B.Probe_c[0] = 0.0025;
  FCS_model_B.Probe_c[1] = 0.0;

  // InitializeConditions for Merge: '<S200>/Merge1' incorporates:
  //   Memory: '<S42>/Memory'

  FCS_model_DW.Memory_PreviousInput = FCS_model_P.Memory_InitialCondition;

  // InitializeConditions for DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states =
    FCS_model_P.DiscreteTransferFcn_InitialSt_e;

  // InitializeConditions for DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_j =
    FCS_model_P.DiscreteTransferFcn_InitialSt_b;

  // InitializeConditions for DiscreteFir: '<S3>/FIR_IMUaccel'
  for (int32_T i{0}; i < 15; i++) {
    FCS_model_DW.FIR_IMUaccel_states[i] = FCS_model_P.FIR_IMUaccel_InitialStates;
  }

  // End of InitializeConditions for DiscreteFir: '<S3>/FIR_IMUaccel'

  // InitializeConditions for DiscreteFilter: '<S139>/Discrete Filter1'
  FCS_model_DW.DiscreteFilter1_states[0] =
    FCS_model_P.DiscreteFilter1_InitialStates;
  FCS_model_DW.DiscreteFilter1_states[1] =
    FCS_model_P.DiscreteFilter1_InitialStates;
  FCS_model_DW.DiscreteFilter1_states[2] =
    FCS_model_P.DiscreteFilter1_InitialStates;

  // InitializeConditions for Delay: '<S140>/MemoryX'
  FCS_model_DW.icLoad = true;

  // InitializeConditions for Logic: '<S31>/OR' incorporates:
  //   Memory: '<S31>/Memory'

  FCS_model_DW.Memory_PreviousInput_j = FCS_model_P.Memory_InitialCondition_h;

  // InitializeConditions for DiscreteStateSpace: '<S30>/Internal'
  FCS_model_DW.Internal_DSTATE[0] = FCS_model_P.Internal_InitialCondition;
  FCS_model_DW.Internal_DSTATE[1] = FCS_model_P.Internal_InitialCondition;

  // InitializeConditions for DiscreteStateSpace: '<S23>/Internal'
  FCS_model_DW.Internal_DSTATE_f[0] = FCS_model_P.Internal_InitialCondition_a;
  FCS_model_DW.Internal_DSTATE_f[1] = FCS_model_P.Internal_InitialCondition_a;

  // InitializeConditions for Delay: '<S50>/MemoryX'
  FCS_model_DW.icLoad_n = true;

  // InitializeConditions for DiscreteFilter: '<S49>/IIRgyroz'
  for (int32_T i{0}; i < 10; i++) {
    FCS_model_DW.IIRgyroz_states[i] = FCS_model_P.IIRgyroz_InitialStates;
  }

  // End of InitializeConditions for DiscreteFilter: '<S49>/IIRgyroz'

  // InitializeConditions for UnitDelay: '<S57>/UD'
  //
  //  Block description for '<S57>/UD':
  //
  //   Store in Global RAM

  FCS_model_DW.UD_DSTATE[0] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for Delay: '<S44>/Delay'
  FCS_model_DW.Delay_DSTATE[0] = FCS_model_P.Delay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S57>/UD'
  //
  //  Block description for '<S57>/UD':
  //
  //   Store in Global RAM

  FCS_model_DW.UD_DSTATE[1] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for Delay: '<S44>/Delay'
  FCS_model_DW.Delay_DSTATE[1] = FCS_model_P.Delay_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<S137>/Integrator'
  FCS_model_DW.Integrator_IC_LOADING = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S130>/Integrator'
  FCS_model_DW.Integrator_IC_LOADING_g = 1U;
  for (int32_T i{0}; i < 40; i++) {
    // InitializeConditions for Delay: '<S51>/Delay2'
    FCS_model_DW.Delay2_DSTATE[i] = FCS_model_P.Delay2_InitialCondition;

    // InitializeConditions for Delay: '<S51>/Delay1'
    FCS_model_DW.Delay1_DSTATE[i] = FCS_model_P.Delay1_InitialCondition;
  }

  // InitializeConditions for DiscreteIntegrator: '<S43>/SimplyIntegrateVelocity' 
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0] =
    FCS_model_P.SimplyIntegrateVelocity_IC;
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1] =
    FCS_model_P.SimplyIntegrateVelocity_IC;

  // InitializeConditions for DiscreteStateSpace: '<S11>/Internal'
  FCS_model_DW.Internal_DSTATE_d = FCS_model_P.Internal_InitialCondition_p;

  // InitializeConditions for DiscreteStateSpace: '<S15>/Internal'
  FCS_model_DW.Internal_DSTATE_k[0] = FCS_model_P.Internal_InitialCondition_h;
  FCS_model_DW.Internal_DSTATE_k[1] = FCS_model_P.Internal_InitialCondition_h;

  // InitializeConditions for DiscreteStateSpace: '<S16>/Internal'
  FCS_model_DW.Internal_DSTATE_kj = FCS_model_P.Internal_InitialCondition_pv;

  // InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' 
  FCS_model_DW.DiscreteTimeIntegrator_DSTATE =
    FCS_model_P.DiscreteTimeIntegrator_IC;

  // SystemInitialize for IfAction SubSystem: '<S200>/If Action Subsystem'
  // InitializeConditions for DiscreteTransferFcn: '<S203>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_p =
    FCS_model_P.DiscreteTransferFcn_InitialStat;

  // End of SystemInitialize for SubSystem: '<S200>/If Action Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S162>/MeasurementUpdate'
  // SystemInitialize for Product: '<S191>/Product3' incorporates:
  //   Outport: '<S191>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S162>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S168>/Enabled Subsystem'
  // SystemInitialize for Product: '<S193>/Product2' incorporates:
  //   Outport: '<S193>/deltax'

  FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S168>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S162>/MeasurementUpdate'
  // SystemInitialize for Product: '<S191>/Product3' incorporates:
  //   Outport: '<S191>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S162>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S168>/Enabled Subsystem'
  // SystemInitialize for Product: '<S193>/Product2' incorporates:
  //   Outport: '<S193>/deltax'

  FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S168>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S162>/MeasurementUpdate'
  // SystemInitialize for Product: '<S191>/Product3' incorporates:
  //   Outport: '<S191>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S162>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S168>/Enabled Subsystem'
  // SystemInitialize for Product: '<S193>/Product2' incorporates:
  //   Outport: '<S193>/deltax'

  FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S168>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S162>/MeasurementUpdate'
  // SystemInitialize for Product: '<S191>/Product3' incorporates:
  //   Outport: '<S191>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S162>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S168>/Enabled Subsystem'
  // SystemInitialize for Product: '<S193>/Product2' incorporates:
  //   Outport: '<S193>/deltax'

  FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S168>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S95>/Enabled Subsystem'
  // SystemInitialize for Product: '<S121>/Product2' incorporates:
  //   Outport: '<S121>/deltax'

  FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;

  // End of SystemInitialize for SubSystem: '<S95>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S88>/MeasurementUpdate'
  // SystemInitialize for Product: '<S119>/Product3' incorporates:
  //   Outport: '<S119>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;

  // End of SystemInitialize for SubSystem: '<S88>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S95>/Enabled Subsystem'
  // SystemInitialize for Product: '<S121>/Product2' incorporates:
  //   Outport: '<S121>/deltax'

  FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;

  // End of SystemInitialize for SubSystem: '<S95>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S88>/MeasurementUpdate'
  // SystemInitialize for Product: '<S119>/Product3' incorporates:
  //   Outport: '<S119>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;

  // End of SystemInitialize for SubSystem: '<S88>/MeasurementUpdate'
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
