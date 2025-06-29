//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.203
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sun Jun 29 13:35:16 2025
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
void FCS_model::step(in_dashboard *arg_in_dashboard, in_sensors *arg_in_sensors,
                     in_states *arg_in_states, out_controllers
                     *arg_out_controllers, out_estimators *arg_out_estimators,
                     out_sensors *arg_out_sensors)
{
  // local block i/o variables
  real_T rtb_Sum1_a;
  real_T rtb_Sum1_di;
  real_T rtb_Switch2;
  real_T rtb_ref_z;
  real_T rtb_ref_yaw;
  real_T rtb_orient_rate_yaw;
  real_T rtb_pos_dz;
  real_T rtb_orient_rate_pitch;
  real_T rtb_Product5;
  real_T rtb_MathFunction[9];
  real_T rtb_VectorConcatenate[9];
  real_T rtb_VectorConcatenate_g[9];
  real_T rtb_VectorConcatenate_k[9];
  real_T inverseIMU_gain[6];
  real_T rtb_Sum1_eu[6];
  real_T rtb_Product1[4];
  real_T rtb_Add_k[3];
  real_T rtb_FIR_IMUaccel[3];
  real_T rtb_TmpSignalConversionAtProd_i[3];
  real_T rtb_TmpSignalConversionAtProduc[3];
  real_T rtb_sincos_o1[3];
  real_T IIRgyroz_tmp[2];
  real_T rtb_Product_c[2];
  real_T rtb_Reshapey[2];
  real_T rtb_SimplyIntegrateVelocity[2];
  real_T tmp[2];
  real_T DiscreteFilter1_tmp;
  real_T Sum;
  real_T rtb_Add_g_idx_0;
  real_T rtb_Add_g_idx_1;
  real_T rtb_Divide;
  real_T rtb_K;
  real_T rtb_K_i;
  real_T rtb_On1Off2forpitch;
  real_T rtb_Product4;
  real_T rtb_Saturation;
  real_T rtb_Saturation_jg;
  real_T rtb_Saturation_l;
  real_T rtb_Sum1;
  real_T rtb_Sum1_l;
  real_T rtb_TrigonometricFunction4;
  real_T rtb_orient_pitch;
  real_T rtb_pos_dx;
  real_T rtb_pos_x;
  real_T rtb_rangefinder_distance;
  real_T rtb_roll;
  real_T rtb_sincos_o1_p;
  real_T rtb_zDtheta;
  real_T tmp_0;
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
  //   Inport: '<Root>/in_sensors'
  //   Sum: '<S3>/Sum1'

  inverseIMU_gain[0] = (arg_in_sensors->accelerometer_x - rtb_Sum1_eu[0]) *
    FCS_model_P.inverseIMU_gain_Gain[0];
  inverseIMU_gain[1] = (arg_in_sensors->accelerometer_y - rtb_Sum1_eu[1]) *
    FCS_model_P.inverseIMU_gain_Gain[1];
  inverseIMU_gain[2] = (arg_in_sensors->accelerometer_z - rtb_Sum1_eu[2]) *
    FCS_model_P.inverseIMU_gain_Gain[2];
  inverseIMU_gain[3] = (arg_in_sensors->gyroscope_x - rtb_Sum1_eu[3]) *
    FCS_model_P.inverseIMU_gain_Gain[3];
  inverseIMU_gain[4] = (arg_in_sensors->gyroscope_y - rtb_Sum1_eu[4]) *
    FCS_model_P.inverseIMU_gain_Gain[4];
  inverseIMU_gain[5] = (arg_in_sensors->gyroscope_z - rtb_Sum1_eu[5]) *
    FCS_model_P.inverseIMU_gain_Gain[5];

  // If: '<S200>/If1' incorporates:
  //   Constant: '<S41>/Constant'
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
    //   Inport: '<Root>/in_states'
    //   Sum: '<S203>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_p = ((FCS_model_P.w_c_yaw *
      arg_in_states->yaw + inverseIMU_gain[5]) -
      FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_p) /
      FCS_model_P.DiscreteTransferFcn_DenCoef[0];

    // End of Outputs for SubSystem: '<S200>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S200>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S201>/Action Port'

    // Merge: '<S200>/Merge1' incorporates:
    //   Gain: '<S201>/Gain'
    //   Memory: '<S41>/Memory'
    //   Sum: '<S201>/Sum'

    FCS_model_DW.Memory_PreviousInput += FCS_model_P.Ts * inverseIMU_gain[5];

    // End of Outputs for SubSystem: '<S200>/If Action Subsystem3'
  }

  // End of If: '<S200>/If1'

  // DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  rtb_orient_pitch = FCS_model_P.DiscreteTransferFcn_NumCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'
  rtb_K = FCS_model_P.DiscreteTransferFcn_NumCoef_f[1] *
    FCS_model_DW.DiscreteTransferFcn_states_j;

  // SignalConversion generated from: '<S47>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'

  rtb_sincos_o1[0] = FCS_model_DW.Memory_PreviousInput;
  rtb_sincos_o1[1] = rtb_orient_pitch;
  rtb_sincos_o1[2] = rtb_K;

  // Trigonometry: '<S142>/sincos' incorporates:
  //   DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'
  //   SignalConversion generated from: '<S47>/sincos'

  rtb_TmpSignalConversionAtProd_i[0] = std::sin
    (FCS_model_DW.Memory_PreviousInput);
  rtb_TmpSignalConversionAtProduc[0] = std::cos
    (FCS_model_DW.Memory_PreviousInput);
  rtb_TmpSignalConversionAtProd_i[1] = std::sin(rtb_orient_pitch);
  rtb_TmpSignalConversionAtProduc[1] = std::cos(rtb_orient_pitch);
  rtb_TmpSignalConversionAtProd_i[2] = std::sin(rtb_K);
  rtb_TmpSignalConversionAtProduc[2] = std::cos(rtb_K);

  // Fcn: '<S142>/Fcn11'
  rtb_VectorConcatenate[0] = rtb_TmpSignalConversionAtProduc[0] *
    rtb_TmpSignalConversionAtProduc[1];

  // Fcn: '<S142>/Fcn21' incorporates:
  //   Fcn: '<S142>/Fcn22'

  DiscreteFilter1_tmp = rtb_TmpSignalConversionAtProd_i[1] *
    rtb_TmpSignalConversionAtProd_i[2];
  rtb_VectorConcatenate[1] = DiscreteFilter1_tmp *
    rtb_TmpSignalConversionAtProduc[0] - rtb_TmpSignalConversionAtProd_i[0] *
    rtb_TmpSignalConversionAtProduc[2];

  // Fcn: '<S142>/Fcn31' incorporates:
  //   Fcn: '<S142>/Fcn32'

  Sum = rtb_TmpSignalConversionAtProd_i[1] * rtb_TmpSignalConversionAtProduc[2];
  rtb_VectorConcatenate[2] = Sum * rtb_TmpSignalConversionAtProduc[0] +
    rtb_TmpSignalConversionAtProd_i[0] * rtb_TmpSignalConversionAtProd_i[2];

  // Fcn: '<S142>/Fcn12'
  rtb_VectorConcatenate[3] = rtb_TmpSignalConversionAtProd_i[0] *
    rtb_TmpSignalConversionAtProduc[1];

  // Fcn: '<S142>/Fcn22'
  rtb_VectorConcatenate[4] = DiscreteFilter1_tmp *
    rtb_TmpSignalConversionAtProd_i[0] + rtb_TmpSignalConversionAtProduc[0] *
    rtb_TmpSignalConversionAtProduc[2];

  // Fcn: '<S142>/Fcn32'
  rtb_VectorConcatenate[5] = Sum * rtb_TmpSignalConversionAtProd_i[0] -
    rtb_TmpSignalConversionAtProduc[0] * rtb_TmpSignalConversionAtProd_i[2];

  // Fcn: '<S142>/Fcn13'
  rtb_VectorConcatenate[6] = -rtb_TmpSignalConversionAtProd_i[1];

  // Fcn: '<S142>/Fcn23'
  rtb_VectorConcatenate[7] = rtb_TmpSignalConversionAtProduc[1] *
    rtb_TmpSignalConversionAtProd_i[2];

  // Fcn: '<S142>/Fcn33'
  rtb_VectorConcatenate[8] = rtb_TmpSignalConversionAtProduc[1] *
    rtb_TmpSignalConversionAtProduc[2];
  for (int32_T i{0}; i < 3; i++) {
    // Trigonometry: '<S47>/sincos'
    rtb_sincos_o1_p = rtb_sincos_o1[i];

    // Math: '<S140>/Math Function' incorporates:
    //   Concatenate: '<S195>/Vector Concatenate'

    rtb_MathFunction[3 * i] = rtb_VectorConcatenate[i];
    rtb_MathFunction[3 * i + 1] = rtb_VectorConcatenate[i + 3];
    rtb_MathFunction[3 * i + 2] = rtb_VectorConcatenate[i + 6];

    // Trigonometry: '<S47>/sincos'
    rtb_TmpSignalConversionAtProd_i[i] = std::sin(rtb_sincos_o1_p);
    rtb_FIR_IMUaccel[i] = std::cos(rtb_sincos_o1_p);
  }

  // Fcn: '<S47>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_FIR_IMUaccel[0] * rtb_FIR_IMUaccel[1];

  // Fcn: '<S47>/Fcn21' incorporates:
  //   Fcn: '<S47>/Fcn22'

  rtb_TrigonometricFunction4 = rtb_TmpSignalConversionAtProd_i[1] *
    rtb_TmpSignalConversionAtProd_i[2];
  rtb_VectorConcatenate_k[1] = rtb_TrigonometricFunction4 * rtb_FIR_IMUaccel[0]
    - rtb_TmpSignalConversionAtProd_i[0] * rtb_FIR_IMUaccel[2];

  // Fcn: '<S47>/Fcn31' incorporates:
  //   Fcn: '<S47>/Fcn32'

  rtb_roll = rtb_TmpSignalConversionAtProd_i[1] * rtb_FIR_IMUaccel[2];
  rtb_VectorConcatenate_k[2] = rtb_roll * rtb_FIR_IMUaccel[0] +
    rtb_TmpSignalConversionAtProd_i[0] * rtb_TmpSignalConversionAtProd_i[2];

  // Fcn: '<S47>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_TmpSignalConversionAtProd_i[0] *
    rtb_FIR_IMUaccel[1];

  // Fcn: '<S47>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_TrigonometricFunction4 *
    rtb_TmpSignalConversionAtProd_i[0] + rtb_FIR_IMUaccel[0] * rtb_FIR_IMUaccel
    [2];

  // Fcn: '<S47>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_roll * rtb_TmpSignalConversionAtProd_i[0] -
    rtb_FIR_IMUaccel[0] * rtb_TmpSignalConversionAtProd_i[2];

  // Fcn: '<S47>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_TmpSignalConversionAtProd_i[1];

  // Fcn: '<S47>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_FIR_IMUaccel[1] *
    rtb_TmpSignalConversionAtProd_i[2];

  // Fcn: '<S47>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_FIR_IMUaccel[1] * rtb_FIR_IMUaccel[2];

  // Math: '<S44>/Math Function' incorporates:
  //   Concatenate: '<S57>/Vector Concatenate'

  for (int32_T i{0}; i < 3; i++) {
    rtb_VectorConcatenate_g[3 * i] = rtb_VectorConcatenate_k[i];
    rtb_VectorConcatenate_g[3 * i + 1] = rtb_VectorConcatenate_k[i + 3];
    rtb_VectorConcatenate_g[3 * i + 2] = rtb_VectorConcatenate_k[i + 6];
  }

  std::memcpy(&rtb_VectorConcatenate_k[0], &rtb_VectorConcatenate_g[0], 9U *
              sizeof(real_T));

  // End of Math: '<S44>/Math Function'

  // DiscreteFir: '<S3>/FIR_IMUaccel'
  Sum = inverseIMU_gain[0] * FCS_model_P.FIR_IMUaccel_Coefficients[0];
  cff = 1;
  for (int32_T i{FCS_model_DW.FIR_IMUaccel_circBuf}; i < 5; i++) {
    Sum += FCS_model_DW.FIR_IMUaccel_states[i] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (int32_T i{0}; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    Sum += FCS_model_DW.FIR_IMUaccel_states[i] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[0] = Sum;
  Sum = FCS_model_P.FIR_IMUaccel_Coefficients[0] * inverseIMU_gain[1];
  cff = 1;
  for (int32_T i{FCS_model_DW.FIR_IMUaccel_circBuf}; i < 5; i++) {
    Sum += FCS_model_DW.FIR_IMUaccel_states[i + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (int32_T i{0}; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    Sum += FCS_model_DW.FIR_IMUaccel_states[i + 5] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[1] = Sum;
  Sum = FCS_model_P.FIR_IMUaccel_Coefficients[0] * inverseIMU_gain[2];
  cff = 1;
  for (int32_T i{FCS_model_DW.FIR_IMUaccel_circBuf}; i < 5; i++) {
    Sum += FCS_model_DW.FIR_IMUaccel_states[i + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (int32_T i{0}; i < FCS_model_DW.FIR_IMUaccel_circBuf; i++) {
    Sum += FCS_model_DW.FIR_IMUaccel_states[i + 10] *
      FCS_model_P.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[2] = Sum;

  // Sum: '<S3>/Sum3' incorporates:
  //   Constant: '<Root>/Constant'
  //   Inport: '<Root>/in_sensors'

  rtb_rangefinder_distance = arg_in_sensors->rangefinder_distance -
    FCS_model_P.sensorCalibrationData[7];

  // DiscreteFilter: '<S140>/Discrete Filter1'
  rtb_Saturation = rtb_rangefinder_distance;
  denIdx = 1;
  for (int32_T i{0}; i < 3; i++) {
    // Sum: '<S140>/Sum' incorporates:
    //   Constant: '<S140>/gravity'
    //   DiscreteFir: '<S3>/FIR_IMUaccel'
    //   Math: '<S140>/Math Function'
    //   Product: '<S140>/Product'

    rtb_TmpSignalConversionAtProd_i[i] = ((rtb_MathFunction[i + 3] *
      rtb_FIR_IMUaccel[1] + rtb_MathFunction[i] * rtb_FIR_IMUaccel[0]) +
      rtb_MathFunction[i + 6] * Sum) + FCS_model_P.gravity_Value[i];

    // DiscreteFilter: '<S140>/Discrete Filter1'
    rtb_Saturation -= FCS_model_P.DiscreteFilter1_DenCoef[denIdx] *
      FCS_model_DW.DiscreteFilter1_states[i];
    denIdx++;
  }

  // DiscreteFilter: '<S140>/Discrete Filter1'
  DiscreteFilter1_tmp = rtb_Saturation / FCS_model_P.DiscreteFilter1_DenCoef[0];

  // Switch generated from: '<S2>/Switch' incorporates:
  //   DiscreteFilter: '<S140>/Discrete Filter1'
  //   Gain: '<S140>/RangfinderScaleGain1'

  rtb_pos_dz = (((FCS_model_P.DiscreteFilter1_NumCoef[0] * DiscreteFilter1_tmp +
                  FCS_model_DW.DiscreteFilter1_states[0] *
                  FCS_model_P.DiscreteFilter1_NumCoef[1]) +
                 FCS_model_DW.DiscreteFilter1_states[1] *
                 FCS_model_P.DiscreteFilter1_NumCoef[2]) +
                FCS_model_DW.DiscreteFilter1_states[2] *
                FCS_model_P.DiscreteFilter1_NumCoef[3]) *
    FCS_model_P.RangfinderScaleGain1_Gain;

  // Product: '<S140>/Product2' incorporates:
  //   Constant: '<S140>/Constant'
  //   Math: '<S140>/Math Function'
  //   SignalConversion generated from: '<S140>/Product2'

  for (int32_T i{0}; i < 3; i++) {
    rtb_TmpSignalConversionAtProduc[i] = (rtb_MathFunction[i + 3] *
      FCS_model_P.Constant_Value_e + rtb_MathFunction[i] *
      FCS_model_P.Constant_Value_e) + rtb_MathFunction[i + 6] * rtb_pos_dz;
  }

  // End of Product: '<S140>/Product2'

  // Reshape: '<S141>/Reshapey'
  rtb_Reshapey[0] = rtb_TmpSignalConversionAtProduc[2];
  rtb_Reshapey[1] = rtb_TmpSignalConversionAtProd_i[2];

  // Delay: '<S141>/MemoryX' incorporates:
  //   Constant: '<S141>/X0'

  if (FCS_model_DW.icLoad) {
    FCS_model_DW.MemoryX_DSTATE[0] = FCS_model_P.X0_Value[0];
    FCS_model_DW.MemoryX_DSTATE[1] = FCS_model_P.X0_Value[1];
    FCS_model_DW.MemoryX_DSTATE[2] = FCS_model_P.X0_Value[2];
    FCS_model_DW.MemoryX_DSTATE[3] = FCS_model_P.X0_Value[3];
  }

  // Outputs for Enabled SubSystem: '<S169>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S194>/Enable'

  // Outputs for Enabled SubSystem: '<S163>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S192>/Enable'

  // Constant: '<S141>/Enable'
  if (FCS_model_P.Enable_Value) {
    FCS_model_DW.MeasurementUpdate_MODE = true;

    // Product: '<S192>/D[k]*u[k]'
    rtb_Divide = rtb_TmpSignalConversionAtProd_i[2];
    for (int32_T i{0}; i < 2; i++) {
      // Product: '<S192>/C[k]*xhat[k|k-1]' incorporates:
      //   Constant: '<S141>/C'
      //   Delay: '<S141>/MemoryX'

      rtb_Add_g_idx_0 = ((FCS_model_P.C_Value[i + 2] *
                          FCS_model_DW.MemoryX_DSTATE[1] + FCS_model_P.C_Value[i]
                          * FCS_model_DW.MemoryX_DSTATE[0]) +
                         FCS_model_P.C_Value[i + 4] *
                         FCS_model_DW.MemoryX_DSTATE[2]) + FCS_model_P.C_Value[i
        + 6] * FCS_model_DW.MemoryX_DSTATE[3];

      // Sum: '<S192>/Sum' incorporates:
      //   Constant: '<S141>/D'
      //   Product: '<S192>/D[k]*u[k]'
      //   Sum: '<S192>/Add1'

      IIRgyroz_tmp[i] = rtb_Reshapey[i] - (FCS_model_P.D_Value[i] * rtb_Divide +
        rtb_Add_g_idx_0);

      // Product: '<S192>/C[k]*xhat[k|k-1]' incorporates:
      //   Constant: '<S141>/C'
      //   Product: '<S194>/Product'

      rtb_Product_c[i] = rtb_Add_g_idx_0;
    }

    FCS_model_DW.EnabledSubsystem_MODE = true;

    // Sum: '<S194>/Add1' incorporates:
    //   Product: '<S194>/Product'
    //   Reshape: '<S141>/Reshapey'

    rtb_Divide = rtb_TmpSignalConversionAtProduc[2] - rtb_Product_c[0];
    rtb_Add_g_idx_0 = rtb_TmpSignalConversionAtProd_i[2] - rtb_Product_c[1];
    for (int32_T i{0}; i < 4; i++) {
      // Product: '<S192>/Product3' incorporates:
      //   Constant: '<S143>/KalmanGainL'

      FCS_model_B.Product3[i] = 0.0;
      FCS_model_B.Product3[i] += FCS_model_P.KalmanGainL_Value[i] *
        IIRgyroz_tmp[0];
      FCS_model_B.Product3[i] += FCS_model_P.KalmanGainL_Value[i + 4] *
        IIRgyroz_tmp[1];

      // Product: '<S194>/Product2' incorporates:
      //   Constant: '<S143>/KalmanGainM'

      FCS_model_B.Product2[i] = 0.0;
      FCS_model_B.Product2[i] += FCS_model_P.KalmanGainM_Value[i] * rtb_Divide;
      FCS_model_B.Product2[i] += FCS_model_P.KalmanGainM_Value[i + 4] *
        rtb_Add_g_idx_0;
    }
  } else {
    if (FCS_model_DW.MeasurementUpdate_MODE) {
      // Disable for Product: '<S192>/Product3' incorporates:
      //   Outport: '<S192>/L*(y[k]-yhat[k|k-1])'

      FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0_c;
      FCS_model_DW.MeasurementUpdate_MODE = false;
    }

    if (FCS_model_DW.EnabledSubsystem_MODE) {
      // Disable for Product: '<S194>/Product2' incorporates:
      //   Outport: '<S194>/deltax'

      FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0_k;
      FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0_k;
      FCS_model_DW.EnabledSubsystem_MODE = false;
    }
  }

  // End of Constant: '<S141>/Enable'
  // End of Outputs for SubSystem: '<S163>/MeasurementUpdate'
  // End of Outputs for SubSystem: '<S169>/Enabled Subsystem'

  // Sum: '<S169>/Add' incorporates:
  //   Delay: '<S141>/MemoryX'

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

  rtb_Divide = FCS_model_P.signal_max_Value / (FCS_model_P.Gain_Gain_n *
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
    rtb_pos_dz = (FCS_model_P.Internal_C[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_C[1])*FCS_model_DW.Internal_DSTATE[1];
  }

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'
  //   Inport: '<Root>/in_states'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_9_Threshold)
  {
    rtb_Divide = rtb_Add_g_idx_0;
  } else {
    rtb_Divide = arg_in_states->z;
  }

  // Sum: '<S27>/Sum1' incorporates:
  //   Gain: '<S27>/Gain'

  rtb_Sum1 = rtb_pos_dz - FCS_model_P.Gain_Gain_f * rtb_Divide;

  // SignalConversion generated from: '<S140>/Product1' incorporates:
  //   Constant: '<S40>/Constant'

  rtb_TrigonometricFunction4 = FCS_model_P.Constant_Value_c1[0];
  rtb_roll = FCS_model_P.Constant_Value_c1[1];

  // Product: '<S140>/Product1' incorporates:
  //   Concatenate: '<S195>/Vector Concatenate'
  //   SignalConversion generated from: '<S140>/Product1'

  for (int32_T i{0}; i < 3; i++) {
    rtb_TmpSignalConversionAtProduc[i] = (rtb_VectorConcatenate[i + 3] *
      rtb_roll + rtb_VectorConcatenate[i] * rtb_TrigonometricFunction4) +
      rtb_VectorConcatenate[i + 6] * rtb_Add_g_idx_1;
  }

  // End of Product: '<S140>/Product1'

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_12_Threshold)
  {
    // Switch generated from: '<S2>/Switch'
    rtb_pos_dz = rtb_TmpSignalConversionAtProduc[2];
  } else {
    // Switch generated from: '<S2>/Switch' incorporates:
    //   Inport: '<Root>/in_states'

    rtb_pos_dz = arg_in_states->dz;
  }

  // Sum: '<S27>/Sum4' incorporates:
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

  rtb_TrigonometricFunction4 = ((FCS_model_P.zDz * rtb_Sum1 -
    FCS_model_P.Gain1_Gain * rtb_pos_dz) * (FCS_model_P.KDz * 10.0) *
    FCS_model_P.WithControl1WithoutControl0_Gai +
    FCS_model_P.Vehicle.Airframe.mass * FCS_model_P.g) +
    FCS_model_P.Vehicle.Airframe.mass * FCS_model_B.signal_out *
    FCS_model_P.WithTakeoff1WithoutTakeoff0_Gai;

  // Saturate: '<S27>/SaturationThrust'
  rtb_Add_g_idx_1 = -4.0 * FCS_model_P.Controller.totalThrustMaxRelative *
    FCS_model_P.Controller.motorsThrustPerMotorMax;
  rtb_Sum1 = 4.0 * FCS_model_P.Controller.totalThrustMaxRelative *
    FCS_model_P.Controller.motorsThrustPerMotorMax;
  if (rtb_TrigonometricFunction4 > rtb_Sum1) {
    rtb_TrigonometricFunction4 = rtb_Sum1;
  } else if (rtb_TrigonometricFunction4 < rtb_Add_g_idx_1) {
    rtb_TrigonometricFunction4 = rtb_Add_g_idx_1;
  }

  // Gain: '<S1>/On=1//Off=0 for thrust' incorporates:
  //   Saturate: '<S27>/SaturationThrust'

  rtb_Add_g_idx_1 = FCS_model_P.On1Off0forthrust_Gain *
    rtb_TrigonometricFunction4;

  // DiscreteStateSpace: '<S23>/Internal'
  {
    rtb_orient_rate_yaw = (FCS_model_P.Internal_C_j[0])*
      FCS_model_DW.Internal_DSTATE_f[0]
      + (FCS_model_P.Internal_C_j[1])*FCS_model_DW.Internal_DSTATE_f[1];
  }

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'
  //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'
  //   Inport: '<Root>/in_states'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_3_Threshold)
  {
    rtb_Sum1 = rtb_K;
  } else {
    rtb_Sum1 = arg_in_states->roll;
  }

  // Sum: '<S10>/Sum1'
  rtb_Sum1_l = rtb_orient_rate_yaw - rtb_Sum1;

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_6_Threshold)
  {
    // Switch generated from: '<S2>/Switch' incorporates:
    //   DiscreteFir: '<S3>/FIR_IMUaccel'

    rtb_orient_rate_yaw = Sum;
  } else {
    // Switch generated from: '<S2>/Switch'
    rtb_orient_rate_yaw = inverseIMU_gain[5];
  }

  // Gain: '<S1>/On=1//Off=1 for yaw' incorporates:
  //   Constant: '<S4>/yaw equilibrium'
  //   Gain: '<S10>/KDpsi'
  //   Gain: '<S10>/zDpsi'
  //   Gain: '<S4>/Changing of Jzz'
  //   Sum: '<S10>/Sum3'
  //   Sum: '<S4>/Sum3'

  rtb_Sum1_l = ((FCS_model_P.zDpsi * 2.0 * rtb_Sum1_l - rtb_orient_rate_yaw) *
                (FCS_model_P.KDpsi * 1.3) * FCS_model_P.ChangingofJzz_Gain +
                FCS_model_P.yawequilibrium_Value) *
    FCS_model_P.On1Off1foryaw_Gain;

  // Delay: '<S51>/MemoryX' incorporates:
  //   Constant: '<S51>/X0'

  if (FCS_model_DW.icLoad_n) {
    FCS_model_DW.MemoryX_DSTATE_o[0] = FCS_model_P.X0_Value_h[0];
    FCS_model_DW.MemoryX_DSTATE_o[1] = FCS_model_P.X0_Value_h[1];
  }

  for (cff = 0; cff < 2; cff++) {
    // DiscreteFilter: '<S50>/IIRgyroz'
    memOffset = cff * 5;
    rtb_Saturation = inverseIMU_gain[cff + 3];
    denIdx = 1;
    for (int32_T i{0}; i < 5; i++) {
      rtb_Saturation -= FCS_model_DW.IIRgyroz_states[memOffset + i] *
        FCS_model_P.IIRgyroz_DenCoef[denIdx];
      denIdx++;
    }

    rtb_Saturation /= FCS_model_P.IIRgyroz_DenCoef[0];
    rtb_K_i = FCS_model_P.IIRgyroz_NumCoef[0] * rtb_Saturation;
    denIdx = 1;
    for (int32_T i{0}; i < 5; i++) {
      rtb_K_i += FCS_model_DW.IIRgyroz_states[memOffset + i] *
        FCS_model_P.IIRgyroz_NumCoef[denIdx];
      denIdx++;
    }

    // SampleTimeMath: '<S58>/TSamp' incorporates:
    //   DiscreteFilter: '<S50>/IIRgyroz'
    //
    //  About '<S58>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )

    rtb_K_i *= FCS_model_P.TSamp_WtEt;

    // DiscreteFilter: '<S50>/IIRgyroz' incorporates:
    //   Sum: '<S58>/Diff'
    //   UnitDelay: '<S58>/UD'
    //
    //  Block description for '<S58>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S58>/UD':
    //
    //   Store in Global RAM

    IIRgyroz_tmp[cff] = rtb_Saturation;
    rtb_SimplyIntegrateVelocity[cff] = rtb_K_i - FCS_model_DW.UD_DSTATE[cff];

    // SampleTimeMath: '<S58>/TSamp'
    //
    //  About '<S58>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )

    rtb_Reshapey[cff] = rtb_K_i;
  }

  // Abs: '<S50>/Abs' incorporates:
  //   Abs: '<S50>/Abs4'

  rtb_Saturation = std::abs(inverseIMU_gain[3]);

  // Abs: '<S50>/Abs1' incorporates:
  //   Abs: '<S50>/Abs5'

  rtb_K_i = std::abs(inverseIMU_gain[4]);

  // Logic: '<S50>/Logical Operator3' incorporates:
  //   Abs: '<S50>/Abs'
  //   Abs: '<S50>/Abs1'
  //   Abs: '<S50>/Abs2'
  //   Abs: '<S50>/Abs3'
  //   Abs: '<S50>/Abs6'
  //   Abs: '<S50>/Abs7'
  //   Abs: '<S50>/Abs8'
  //   Abs: '<S50>/Abs9'
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
  //   Constant: '<S69>/Constant'
  //   Delay: '<S45>/Delay'
  //   DiscreteTransferFcn: '<S196>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S197>/Discrete Transfer Fcn'
  //   Inport: '<Root>/in_sensors'
  //   Logic: '<S50>/Logical Operator'
  //   Logic: '<S50>/Logical Operator1'
  //   Logic: '<S50>/Logical Operator2'
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
  //   RelationalOperator: '<S69>/Compare'
  //   Sum: '<S50>/Add'

  rtb_LogicalOperator3 = ((((std::abs(rtb_orient_pitch) <=
    FCS_model_P.maxp_const) && (std::abs(rtb_K) <= FCS_model_P.maxq_const) &&
    (rtb_Saturation <= FCS_model_P.maxw1_const) && (rtb_K_i <=
    FCS_model_P.maxw2_const) && (std::abs(rtb_SimplyIntegrateVelocity[0]) <=
    FCS_model_P.maxdw1_const) && (std::abs(rtb_SimplyIntegrateVelocity[1]) <=
    FCS_model_P.maxdw2_const)) || ((rtb_Saturation <= FCS_model_P.maxp2_const) &&
    (rtb_K_i <= FCS_model_P.maxq2_const))) && (std::abs
    (arg_in_sensors->opticalflow_x - FCS_model_DW.Delay_DSTATE[0]) <=
    FCS_model_P.maxw3_const) && (std::abs(arg_in_sensors->opticalflow_y -
    FCS_model_DW.Delay_DSTATE[1]) <= FCS_model_P.maxw4_const) &&
    (rtb_Add_g_idx_0 <= FCS_model_P.minHeightforOF_const));

  // Logic: '<S132>/Logical Operator' incorporates:
  //   Constant: '<S132>/Constant'
  //   Constant: '<S132>/Time constant'
  //   Constant: '<S135>/Constant'
  //   Constant: '<S136>/Constant'
  //   RelationalOperator: '<S135>/Compare'
  //   RelationalOperator: '<S136>/Compare'
  //   Sum: '<S132>/Sum1'

  rtb_LogicalOperator_b = ((FCS_model_P.LowPassFilterDiscreteorContin_l -
    FCS_model_B.Probe[0] <= FCS_model_P.Constant_Value_o) &&
    (FCS_model_P.LowPassFilterDiscreteorContin_i <
     FCS_model_P.CompareToConstant_const));

  // Gain: '<S124>/K' incorporates:
  //   Inport: '<Root>/in_sensors'

  rtb_K = FCS_model_P.LowPassFilterDiscreteorContinuo *
    arg_in_sensors->opticalflow_x;

  // DiscreteIntegrator: '<S138>/Integrator'
  if (FCS_model_DW.Integrator_IC_LOADING != 0) {
    FCS_model_DW.Integrator_DSTATE = rtb_K;
    if (FCS_model_DW.Integrator_DSTATE >= FCS_model_P.Integrator_UpperSat) {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
    } else if (FCS_model_DW.Integrator_DSTATE <= FCS_model_P.Integrator_LowerSat)
    {
      FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
    }
  }

  if (rtb_LogicalOperator_b || (FCS_model_DW.Integrator_PrevResetState != 0)) {
    FCS_model_DW.Integrator_DSTATE = rtb_K;
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

  // End of DiscreteIntegrator: '<S138>/Integrator'

  // Saturate: '<S138>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE > FCS_model_P.Saturation_UpperSat) {
    rtb_Saturation = FCS_model_P.Saturation_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE < FCS_model_P.Saturation_LowerSat) {
    rtb_Saturation = FCS_model_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = FCS_model_DW.Integrator_DSTATE;
  }

  // End of Saturate: '<S138>/Saturation'

  // Logic: '<S125>/Logical Operator' incorporates:
  //   Constant: '<S125>/Constant'
  //   Constant: '<S125>/Time constant'
  //   Constant: '<S128>/Constant'
  //   Constant: '<S129>/Constant'
  //   RelationalOperator: '<S128>/Compare'
  //   RelationalOperator: '<S129>/Compare'
  //   Sum: '<S125>/Sum1'

  rtb_LogicalOperator_j = ((FCS_model_P.LowPassFilterDiscreteorContin_a -
    FCS_model_B.Probe_c[0] <= FCS_model_P.Constant_Value_l) &&
    (FCS_model_P.LowPassFilterDiscreteorConti_d0 <
     FCS_model_P.CompareToConstant_const_p));

  // Gain: '<S123>/K' incorporates:
  //   Inport: '<Root>/in_sensors'

  rtb_K_i = FCS_model_P.LowPassFilterDiscreteorContin_d *
    arg_in_sensors->opticalflow_y;

  // DiscreteIntegrator: '<S131>/Integrator'
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

  // End of DiscreteIntegrator: '<S131>/Integrator'

  // Saturate: '<S131>/Saturation'
  if (FCS_model_DW.Integrator_DSTATE_e > FCS_model_P.Saturation_UpperSat_k) {
    rtb_Saturation_jg = FCS_model_P.Saturation_UpperSat_k;
  } else if (FCS_model_DW.Integrator_DSTATE_e <
             FCS_model_P.Saturation_LowerSat_h) {
    rtb_Saturation_jg = FCS_model_P.Saturation_LowerSat_h;
  } else {
    rtb_Saturation_jg = FCS_model_DW.Integrator_DSTATE_e;
  }

  // End of Saturate: '<S131>/Saturation'

  // Reshape: '<S51>/Reshapey' incorporates:
  //   Bias: '<S52>/Bias2'
  //   Bias: '<S52>/Bias3'
  //   Delay: '<S52>/Delay1'
  //   Delay: '<S52>/Delay2'
  //   Gain: '<S52>/Gain4'
  //   Gain: '<S52>/Gain5'
  //   Product: '<S52>/Product2'
  //   Product: '<S52>/Product3'
  //   Sum: '<S52>/Subtract2'
  //   Sum: '<S52>/Subtract3'

  rtb_SimplyIntegrateVelocity[0] = (rtb_rangefinder_distance +
    FCS_model_P.Bias3_Bias) * FCS_model_P.Gain5_Gain * (rtb_Saturation -
    FCS_model_DW.Delay2_DSTATE[0U]);
  rtb_SimplyIntegrateVelocity[1] = (rtb_rangefinder_distance +
    FCS_model_P.Bias2_Bias) * FCS_model_P.Gain4_Gain * (rtb_Saturation_jg -
    FCS_model_DW.Delay1_DSTATE[0U]);

  // Outputs for Enabled SubSystem: '<S96>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S122>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.EnabledSubsystem_MODE_g = true;

    // Sum: '<S122>/Add1' incorporates:
    //   Constant: '<S51>/C'
    //   Delay: '<S51>/MemoryX'
    //   Product: '<S122>/Product'

    rtb_TrigonometricFunction4 = rtb_SimplyIntegrateVelocity[0] -
      (FCS_model_P.C_Value_h[0] * FCS_model_DW.MemoryX_DSTATE_o[0] +
       FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.C_Value_h[2]);
    rtb_roll = rtb_SimplyIntegrateVelocity[1] - (FCS_model_DW.MemoryX_DSTATE_o[0]
      * FCS_model_P.C_Value_h[1] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[3]);

    // Product: '<S122>/Product2' incorporates:
    //   Constant: '<S70>/KalmanGainM'

    FCS_model_B.Product2_c[0] = FCS_model_P.KalmanGainM_Value_e[0] *
      rtb_TrigonometricFunction4;
    FCS_model_B.Product2_c[0] += FCS_model_P.KalmanGainM_Value_e[2] * rtb_roll;
    FCS_model_B.Product2_c[1] = FCS_model_P.KalmanGainM_Value_e[1] *
      rtb_TrigonometricFunction4;
    FCS_model_B.Product2_c[1] += FCS_model_P.KalmanGainM_Value_e[3] * rtb_roll;
  } else if (FCS_model_DW.EnabledSubsystem_MODE_g) {
    // Disable for Product: '<S122>/Product2' incorporates:
    //   Outport: '<S122>/deltax'

    FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;
    FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;
    FCS_model_DW.EnabledSubsystem_MODE_g = false;
  }

  // End of Outputs for SubSystem: '<S96>/Enabled Subsystem'

  // Sum: '<S96>/Add' incorporates:
  //   Delay: '<S45>/Delay'
  //   Delay: '<S51>/MemoryX'

  FCS_model_DW.Delay_DSTATE[0] = FCS_model_B.Product2_c[0] +
    FCS_model_DW.MemoryX_DSTATE_o[0];
  FCS_model_DW.Delay_DSTATE[1] = FCS_model_B.Product2_c[1] +
    FCS_model_DW.MemoryX_DSTATE_o[1];

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'
  //   Delay: '<S45>/Delay'
  //   Inport: '<Root>/in_states'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_10_Threshold)
  {
    rtb_pos_dx = FCS_model_DW.Delay_DSTATE[0];
  } else {
    rtb_pos_dx = arg_in_states->dx;
  }

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'
  //   DiscreteIntegrator: '<S44>/SimplyIntegrateVelocity'
  //   Inport: '<Root>/in_states'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_7_Threshold)
  {
    rtb_pos_x = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0];
  } else {
    rtb_pos_x = arg_in_states->x;
  }

  // Gain: '<S28>/Gain1' incorporates:
  //   Gain: '<S28>/Gain3'
  //   Gain: '<S28>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S28>/Subtract'
  //   Sum: '<S28>/Sum1'

  rtb_Saturation_l = ((arg_in_dashboard->ref_x - rtb_pos_x) *
                      FCS_model_P.Gain3_Gain - FCS_model_P.Gain4_Gain_m *
                      rtb_pos_dx) * FCS_model_P.Gain1_Gain_b;

  // Saturate: '<S28>/Saturation'
  if (rtb_Saturation_l > FCS_model_P.Saturation_UpperSat_d) {
    rtb_Saturation_l = FCS_model_P.Saturation_UpperSat_d;
  } else if (rtb_Saturation_l < FCS_model_P.Saturation_LowerSat_a) {
    rtb_Saturation_l = FCS_model_P.Saturation_LowerSat_a;
  }

  // End of Saturate: '<S28>/Saturation'

  // Switch: '<S4>/Switch1' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch1_Threshold) {
    // Switch generated from: '<S2>/Switch'
    rtb_orient_rate_pitch = rtb_Saturation_l;
  } else {
    // Switch generated from: '<S2>/Switch' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_orient_rate_pitch = arg_in_dashboard->ref_pitch;
  }

  // End of Switch: '<S4>/Switch1'

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'
  //   Inport: '<Root>/in_states'

  if (!(FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_2_Threshold))
  {
    rtb_orient_pitch = arg_in_states->pitch;
  }

  // Sum: '<S8>/Sum1'
  rtb_Sum1_a = rtb_orient_rate_pitch - rtb_orient_pitch;

  // DiscreteStateSpace: '<S11>/Internal'
  {
    rtb_orient_rate_pitch = FCS_model_P.Internal_C_p*
      FCS_model_DW.Internal_DSTATE_d;
    rtb_orient_rate_pitch += FCS_model_P.Internal_D_b*rtb_Sum1_a;
  }

  // Gain: '<S8>/zDtheta'
  rtb_zDtheta = FCS_model_P.zDtheta * 7.0 * rtb_orient_rate_pitch;

  // Switch generated from: '<S2>/Switch'
  rtb_orient_rate_pitch = inverseIMU_gain[4];

  // Gain: '<S1>/On=1//Off=2 for pitch' incorporates:
  //   Constant: '<S4>/pitch equilibrium'
  //   Gain: '<S4>/Changing of Jyy'
  //   Gain: '<S8>/KDtheta'
  //   Sum: '<S4>/Sum1'
  //   Sum: '<S8>/Sum3'

  rtb_On1Off2forpitch = (FCS_model_P.KDtheta * 1.4 * (rtb_zDtheta -
    rtb_orient_rate_pitch) * FCS_model_P.ChangingofJyy_Gain +
    FCS_model_P.pitchequilibrium_Value) * FCS_model_P.On1Off2forpitch_Gain;

  // DiscreteStateSpace: '<S15>/Internal'
  {
    rtb_Product5 = (FCS_model_P.Internal_C_n[0])*FCS_model_DW.Internal_DSTATE_k
      [0]
      + (FCS_model_P.Internal_C_n[1])*FCS_model_DW.Internal_DSTATE_k[1];
  }

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'
  //   Inport: '<Root>/in_states'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_1_Threshold)
  {
    rtb_Product4 = FCS_model_DW.Memory_PreviousInput;
  } else {
    rtb_Product4 = arg_in_states->yaw;
  }

  // Sum: '<S9>/Sum1'
  rtb_Sum1_di = rtb_Product5 - rtb_Product4;

  // DiscreteStateSpace: '<S16>/Internal'
  {
    rtb_Product5 = FCS_model_P.Internal_C_a*FCS_model_DW.Internal_DSTATE_kj;
    rtb_Product5 += FCS_model_P.Internal_D_jy*rtb_Sum1_di;
  }

  // Gain: '<S9>/zDphi'
  rtb_zDtheta = FCS_model_P.zDphi * 7.0 * rtb_Product5;

  // Product: '<S199>/Product5' incorporates:
  //   Switch generated from: '<S2>/Switch'

  rtb_Product5 = inverseIMU_gain[3];

  // Gain: '<S1>/On=1//Off=1 for roll' incorporates:
  //   Constant: '<S4>/roll equilibrium'
  //   Gain: '<S4>/Changing of Jxx'
  //   Gain: '<S9>/KDphi'
  //   Sum: '<S4>/Sum2'
  //   Sum: '<S9>/Sum3'

  rtb_zDtheta = (FCS_model_P.KDphi * 1.4 * (rtb_zDtheta - rtb_Product5) *
                 FCS_model_P.ChangingofJxx_Gain +
                 FCS_model_P.rollequilibrium_Value) *
    FCS_model_P.On1Off1forroll_Gain;
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

    rtb_TrigonometricFunction4 =
      ((((FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 4] * rtb_Sum1_l +
          FCS_model_P.TorqueTotalThrustToThrustPerMot[i] * rtb_Add_g_idx_1) +
         FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 8] *
         rtb_On1Off2forpitch) + FCS_model_P.TorqueTotalThrustToThrustPerMot[i +
        12] * rtb_zDtheta) * FCS_model_P.Vehicle.Motor.thrustToMotorCommand +
       FCS_model_P.Vehicle.Motor.commandToW2Offset) * arg_in_dashboard->power;
    if (rtb_TrigonometricFunction4 > FCS_model_P.Vehicle.Motor.maxLimit) {
      rtb_TrigonometricFunction4 = FCS_model_P.Vehicle.Motor.maxLimit;
    } else if (rtb_TrigonometricFunction4 < FCS_model_P.Vehicle.Motor.minLimit)
    {
      rtb_TrigonometricFunction4 = FCS_model_P.Vehicle.Motor.minLimit;
    }

    // Product: '<S37>/Product1' incorporates:
    //   Gain: '<S38>/thrustToMotor'
    //   Inport: '<Root>/in_dashboard'
    //   Saturate: '<S37>/Saturation'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Product1[i] = rtb_TrigonometricFunction4 * static_cast<real_T>
      (arg_in_dashboard->master_switch);
  }

  // SignalConversion generated from: '<S44>/Product' incorporates:
  //   Delay: '<S45>/Delay'

  rtb_TrigonometricFunction4 = FCS_model_DW.Delay_DSTATE[0];
  rtb_roll = FCS_model_DW.Delay_DSTATE[1];
  tmp_0 = rtb_TmpSignalConversionAtProduc[2];
  for (int32_T i{0}; i < 3; i++) {
    // Trigonometry: '<S54>/sincos'
    rtb_sincos_o1_p = rtb_sincos_o1[i];
    rtb_Add_k[i] = std::cos(rtb_sincos_o1_p);
    rtb_sincos_o1[i] = std::sin(rtb_sincos_o1_p);

    // Product: '<S44>/Product' incorporates:
    //   Concatenate: '<S57>/Vector Concatenate'

    rtb_TmpSignalConversionAtProduc[i] = (rtb_VectorConcatenate_k[i + 3] *
      rtb_roll + rtb_VectorConcatenate_k[i] * rtb_TrigonometricFunction4) +
      rtb_VectorConcatenate_k[i + 6] * tmp_0;
  }

  // Fcn: '<S54>/Fcn11'
  rtb_VectorConcatenate_k[0] = rtb_Add_k[0] * rtb_Add_k[1];

  // Fcn: '<S54>/Fcn21' incorporates:
  //   Fcn: '<S54>/Fcn22'

  rtb_TrigonometricFunction4 = rtb_sincos_o1[1] * rtb_sincos_o1[2];
  rtb_VectorConcatenate_k[1] = rtb_TrigonometricFunction4 * rtb_Add_k[0] -
    rtb_sincos_o1[0] * rtb_Add_k[2];

  // Fcn: '<S54>/Fcn31' incorporates:
  //   Fcn: '<S54>/Fcn32'

  rtb_roll = rtb_sincos_o1[1] * rtb_Add_k[2];
  rtb_VectorConcatenate_k[2] = rtb_roll * rtb_Add_k[0] + rtb_sincos_o1[0] *
    rtb_sincos_o1[2];

  // Fcn: '<S54>/Fcn12'
  rtb_VectorConcatenate_k[3] = rtb_sincos_o1[0] * rtb_Add_k[1];

  // Fcn: '<S54>/Fcn22'
  rtb_VectorConcatenate_k[4] = rtb_TrigonometricFunction4 * rtb_sincos_o1[0] +
    rtb_Add_k[0] * rtb_Add_k[2];

  // Fcn: '<S54>/Fcn32'
  rtb_VectorConcatenate_k[5] = rtb_roll * rtb_sincos_o1[0] - rtb_Add_k[0] *
    rtb_sincos_o1[2];

  // Fcn: '<S54>/Fcn13'
  rtb_VectorConcatenate_k[6] = -rtb_sincos_o1[1];

  // Fcn: '<S54>/Fcn23'
  rtb_VectorConcatenate_k[7] = rtb_Add_k[1] * rtb_sincos_o1[2];

  // Fcn: '<S54>/Fcn33'
  rtb_VectorConcatenate_k[8] = rtb_Add_k[1] * rtb_Add_k[2];

  // RelationalOperator: '<S53>/Compare' incorporates:
  //   Constant: '<S53>/Constant'

  rtb_Compare_jy = (rtb_Add_g_idx_0 <=
                    FCS_model_P.DeactivateAccelerationIfOFisnot);

  // Logic: '<S49>/Logical Operator' incorporates:
  //   Constant: '<S55>/Constant'
  //   Constant: '<S56>/Constant'
  //   Inport: '<Root>/in_sensors'
  //   RelationalOperator: '<S55>/Compare'
  //   RelationalOperator: '<S56>/Compare'

  rtb_LogicalOperator_c = ((arg_in_sensors->opticalflow_x !=
    FCS_model_P.donotuseaccifopticalflowneverav) ||
    (arg_in_sensors->opticalflow_y !=
     FCS_model_P.donotuseaccifopticalflownever_c));

  // Sum: '<S49>/Add' incorporates:
  //   Concatenate: '<S57>/Vector Concatenate'
  //   Constant: '<S49>/gravity'
  //   Product: '<S49>/Product1'

  for (int32_T i{0}; i < 3; i++) {
    rtb_sincos_o1[i] = rtb_FIR_IMUaccel[i] - ((rtb_VectorConcatenate_k[i + 3] *
      FCS_model_P.gravity_Value_a[1] + rtb_VectorConcatenate_k[i] *
      FCS_model_P.gravity_Value_a[0]) + rtb_VectorConcatenate_k[i + 6] *
      FCS_model_P.gravity_Value_a[2]);
  }

  // End of Sum: '<S49>/Add'

  // Product: '<S49>/Product' incorporates:
  //   Gain: '<S49>/gainaccinput'

  rtb_Product_c[0] = FCS_model_P.gainaccinput_Gain * rtb_sincos_o1[0] *
    static_cast<real_T>(rtb_LogicalOperator_c) * static_cast<real_T>
    (rtb_Compare_jy);
  rtb_Product_c[1] = FCS_model_P.gainaccinput_Gain * rtb_sincos_o1[1] *
    static_cast<real_T>(rtb_LogicalOperator_c) * static_cast<real_T>
    (rtb_Compare_jy);

  // Outputs for Enabled SubSystem: '<S89>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S120>/Enable'

  if (rtb_LogicalOperator3) {
    FCS_model_DW.MeasurementUpdate_MODE_h = true;

    // Sum: '<S120>/Sum' incorporates:
    //   Constant: '<S51>/C'
    //   Constant: '<S51>/D'
    //   Delay: '<S51>/MemoryX'
    //   Product: '<S120>/C[k]*xhat[k|k-1]'
    //   Product: '<S120>/D[k]*u[k]'
    //   Sum: '<S120>/Add1'

    rtb_TrigonometricFunction4 = rtb_SimplyIntegrateVelocity[0] -
      ((FCS_model_P.C_Value_h[0] * FCS_model_DW.MemoryX_DSTATE_o[0] +
        FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.C_Value_h[2]) +
       (FCS_model_P.D_Value_b[0] * rtb_Product_c[0] + rtb_Product_c[1] *
        FCS_model_P.D_Value_b[2]));
    rtb_roll = rtb_SimplyIntegrateVelocity[1] - ((FCS_model_DW.MemoryX_DSTATE_o
      [0] * FCS_model_P.C_Value_h[1] + FCS_model_DW.MemoryX_DSTATE_o[1] *
      FCS_model_P.C_Value_h[3]) + (rtb_Product_c[0] * FCS_model_P.D_Value_b[1] +
      rtb_Product_c[1] * FCS_model_P.D_Value_b[3]));

    // Product: '<S120>/Product3' incorporates:
    //   Constant: '<S70>/KalmanGainL'

    FCS_model_B.Product3_d[0] = FCS_model_P.KalmanGainL_Value_f[0] *
      rtb_TrigonometricFunction4;
    FCS_model_B.Product3_d[0] += FCS_model_P.KalmanGainL_Value_f[2] * rtb_roll;
    FCS_model_B.Product3_d[1] = FCS_model_P.KalmanGainL_Value_f[1] *
      rtb_TrigonometricFunction4;
    FCS_model_B.Product3_d[1] += FCS_model_P.KalmanGainL_Value_f[3] * rtb_roll;
  } else if (FCS_model_DW.MeasurementUpdate_MODE_h) {
    // Disable for Product: '<S120>/Product3' incorporates:
    //   Outport: '<S120>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_DW.MeasurementUpdate_MODE_h = false;
  }

  // End of Outputs for SubSystem: '<S89>/MeasurementUpdate'

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'
  //   Delay: '<S45>/Delay'
  //   Inport: '<Root>/in_states'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_11_Threshold)
  {
    rtb_Add_g_idx_0 = FCS_model_DW.Delay_DSTATE[1];
  } else {
    rtb_Add_g_idx_0 = arg_in_states->dy;
  }

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'
  //   DiscreteIntegrator: '<S44>/SimplyIntegrateVelocity'
  //   Inport: '<Root>/in_states'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_8_Threshold)
  {
    rtb_TrigonometricFunction4 = FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1];
  } else {
    rtb_TrigonometricFunction4 = arg_in_states->y;
  }

  // Gain: '<S29>/Gain1' incorporates:
  //   Gain: '<S29>/Gain3'
  //   Gain: '<S29>/Gain4'
  //   Inport: '<Root>/in_dashboard'
  //   SignalConversion generated from: '<Root>/in_dashboard'
  //   Sum: '<S29>/Subtract'
  //   Sum: '<S29>/Sum1'

  rtb_roll = ((arg_in_dashboard->ref_y - rtb_TrigonometricFunction4) *
              FCS_model_P.Gain3_Gain_i - FCS_model_P.Gain4_Gain_h *
              rtb_Add_g_idx_0) * FCS_model_P.Gain1_Gain_i;

  // Saturate: '<S29>/Saturation'
  if (rtb_roll > FCS_model_P.Saturation_UpperSat_ku) {
    rtb_roll = FCS_model_P.Saturation_UpperSat_ku;
  } else if (rtb_roll < FCS_model_P.Saturation_LowerSat_j) {
    rtb_roll = FCS_model_P.Saturation_LowerSat_j;
  }

  // End of Saturate: '<S29>/Saturation'

  // Outport: '<Root>/out_controllers' incorporates:
  //   BusCreator generated from: '<Root>/out_controllers'
  //   Constant: '<S6>/Constant'

  arg_out_controllers->motor1 = rtb_Product1[0];
  arg_out_controllers->motor2 = rtb_Product1[1];
  arg_out_controllers->motor3 = rtb_Product1[2];
  arg_out_controllers->motor4 = rtb_Product1[3];
  arg_out_controllers->cmd_thrust = rtb_Add_g_idx_1;
  arg_out_controllers->cmd_tau_roll = rtb_Sum1_l;
  arg_out_controllers->cmd_tau_pitch = rtb_On1Off2forpitch;
  arg_out_controllers->cmd_tau_yaw = rtb_zDtheta;
  arg_out_controllers->cmd_roll = rtb_Saturation_l;
  arg_out_controllers->cmd_pitch = rtb_roll;
  arg_out_controllers->cmd_yaw = FCS_model_P.Constant_Value_e2;

  // Switch: '<S4>/Switch2' incorporates:
  //   Constant: '<S1>/Pos=1//Dashboard=0'

  if (FCS_model_P.Pos1Dashboard0_Value > FCS_model_P.Switch2_Threshold) {
    // Switch: '<S4>/Switch2'
    rtb_Switch2 = rtb_roll;
  } else {
    // Switch: '<S4>/Switch2' incorporates:
    //   Inport: '<Root>/in_dashboard'
    //   SignalConversion generated from: '<Root>/in_dashboard'

    rtb_Switch2 = arg_in_dashboard->ref_roll;
  }

  // End of Switch: '<S4>/Switch2'

  // Switch generated from: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/sw_states_passthrough'

  if (FCS_model_P.sw_states_passthrough_Value > FCS_model_P.Switch_13_Threshold)
  {
    // Outport: '<Root>/out_estimators' incorporates:
    //   DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
    //   Gain: '<S39>/Gain'

    arg_out_estimators->battery_SOC = FCS_model_P.Gain_Gain *
      FCS_model_DW.DiscreteTimeIntegrator_DSTATE;
  } else {
    // Outport: '<Root>/out_estimators' incorporates:
    //   Constant: '<S43>/Constant'

    arg_out_estimators->battery_SOC = FCS_model_P.Constant_Value;
  }

  // Outport: '<Root>/out_estimators' incorporates:
  //   BusCreator generated from: '<Root>/out_estimators'

  arg_out_estimators->orient_roll = rtb_Product4;
  arg_out_estimators->orient_pitch = rtb_orient_pitch;
  arg_out_estimators->orient_yaw = rtb_Sum1;
  arg_out_estimators->orient_rate_roll = rtb_Product5;
  arg_out_estimators->orient_rate_pitch = rtb_orient_rate_pitch;
  arg_out_estimators->orient_rate_yaw = rtb_orient_rate_yaw;
  arg_out_estimators->pos_x = rtb_pos_x;
  arg_out_estimators->pos_y = rtb_TrigonometricFunction4;
  arg_out_estimators->pos_z = rtb_Divide;
  arg_out_estimators->pos_dx = rtb_pos_dx;
  arg_out_estimators->pos_dy = rtb_Add_g_idx_0;
  arg_out_estimators->pos_dz = rtb_pos_dz;

  // MinMax: '<S125>/Max' incorporates:
  //   Constant: '<S125>/Time constant'

  rtb_TrigonometricFunction4 = std::fmax(FCS_model_B.Probe_c[0],
    FCS_model_P.LowPassFilterDiscreteorContin_a);

  // Fcn: '<S125>/Avoid Divide by Zero'
  rtb_orient_pitch = static_cast<real_T>(rtb_TrigonometricFunction4 == 0.0) *
    2.2204460492503131e-16 + rtb_TrigonometricFunction4;

  // MinMax: '<S132>/Max' incorporates:
  //   Constant: '<S132>/Time constant'

  rtb_TrigonometricFunction4 = std::fmax(FCS_model_B.Probe[0],
    FCS_model_P.LowPassFilterDiscreteorContin_l);

  // Fcn: '<S132>/Avoid Divide by Zero'
  rtb_Divide = static_cast<real_T>(rtb_TrigonometricFunction4 == 0.0) *
    2.2204460492503131e-16 + rtb_TrigonometricFunction4;

  // Outport: '<Root>/out_sensors' incorporates:
  //   BusCreator generated from: '<Root>/out_sensors'
  //   Constant: '<Root>/Constant'
  //   DiscreteFir: '<S3>/FIR_IMUaccel'
  //   Inport: '<Root>/in_sensors'
  //   Sum: '<S3>/Sum2'

  arg_out_sensors->accelerometer_x = rtb_FIR_IMUaccel[0];
  arg_out_sensors->accelerometer_y = rtb_FIR_IMUaccel[1];
  arg_out_sensors->accelerometer_z = Sum;
  arg_out_sensors->gyroscope_x = inverseIMU_gain[3];
  arg_out_sensors->gyroscope_y = inverseIMU_gain[4];
  arg_out_sensors->gyroscope_z = inverseIMU_gain[5];
  arg_out_sensors->barometer_pressure = arg_in_sensors->barometer_pressure -
    FCS_model_P.sensorCalibrationData[6];
  arg_out_sensors->rangefinder_distance = rtb_rangefinder_distance;

  // Product: '<S198>/Divide' incorporates:
  //   Constant: '<S198>/Constant'
  //   Gain: '<S198>/Gain1'

  rtb_TrigonometricFunction4 = FCS_model_P.Gain1_Gain_e * rtb_FIR_IMUaccel[0] /
    FCS_model_P.g;

  // Trigonometry: '<S198>/Trigonometric Function1'
  if (rtb_TrigonometricFunction4 > 1.0) {
    rtb_TrigonometricFunction4 = 1.0;
  } else if (rtb_TrigonometricFunction4 < -1.0) {
    rtb_TrigonometricFunction4 = -1.0;
  }

  // Gain: '<S198>/Gain' incorporates:
  //   Trigonometry: '<S198>/Trigonometric Function1'

  rtb_TrigonometricFunction4 = FCS_model_P.Gain_Gain_e * std::asin
    (rtb_TrigonometricFunction4);

  // Trigonometry: '<S198>/Trigonometric Function' incorporates:
  //   DiscreteFir: '<S3>/FIR_IMUaccel'
  //   Gain: '<S198>/Gain2'
  //   Gain: '<S198>/Gain3'

  rtb_roll = rt_atan2d_snf(FCS_model_P.Gain2_Gain * rtb_FIR_IMUaccel[1],
    FCS_model_P.Gain3_Gain_h * Sum);

  // Trigonometry: '<S199>/Trigonometric Function2'
  rtb_Add_g_idx_0 = std::sin(rtb_roll);
  rtb_zDtheta = std::cos(rtb_roll);

  // Product: '<S199>/Product5' incorporates:
  //   Gain: '<S199>/Gain'

  rtb_Product5 = FCS_model_P.Gain_Gain_p * rtb_Add_g_idx_0;
  rtb_Product5 *= inverseIMU_gain[5];

  // Sum: '<S196>/Sum' incorporates:
  //   Gain: '<S196>/Gain'
  //   Product: '<S199>/Product4'
  //   Sum: '<S199>/Sum1'

  Sum = (rtb_zDtheta * inverseIMU_gain[4] + rtb_Product5) +
    FCS_model_P.w_c_pitch * rtb_TrigonometricFunction4;

  // Trigonometry: '<S199>/Trigonometric Function4'
  rtb_TrigonometricFunction4 = std::tan(rtb_TrigonometricFunction4);

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
  //   Product: '<S199>/Product1'
  //   Product: '<S199>/Product2'
  //   Product: '<S199>/Product3'
  //   Sum: '<S197>/Sum'
  //   Sum: '<S199>/Sum'

  FCS_model_DW.DiscreteTransferFcn_states_j = ((((rtb_Add_g_idx_0 *
    rtb_TrigonometricFunction4 * inverseIMU_gain[4] + inverseIMU_gain[3]) +
    rtb_zDtheta * rtb_TrigonometricFunction4 * inverseIMU_gain[5]) +
    FCS_model_P.w_c_roll * rtb_roll) -
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

  // Update for DiscreteFilter: '<S140>/Discrete Filter1'
  FCS_model_DW.DiscreteFilter1_states[2] = FCS_model_DW.DiscreteFilter1_states[1];
  FCS_model_DW.DiscreteFilter1_states[1] = FCS_model_DW.DiscreteFilter1_states[0];
  FCS_model_DW.DiscreteFilter1_states[0] = DiscreteFilter1_tmp;

  // Update for Delay: '<S141>/MemoryX'
  FCS_model_DW.icLoad = false;

  // Product: '<S163>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S141>/A'
  //   Delay: '<S141>/MemoryX'

  for (int32_T i{0}; i < 4; i++) {
    rtb_Product1[i] = ((FCS_model_P.A_Value[i + 4] *
                        FCS_model_DW.MemoryX_DSTATE[1] + FCS_model_P.A_Value[i] *
                        FCS_model_DW.MemoryX_DSTATE[0]) + FCS_model_P.A_Value[i
                       + 8] * FCS_model_DW.MemoryX_DSTATE[2]) +
      FCS_model_P.A_Value[i + 12] * FCS_model_DW.MemoryX_DSTATE[3];
  }

  // End of Product: '<S163>/A[k]*xhat[k|k-1]'

  // Update for Delay: '<S141>/MemoryX' incorporates:
  //   Constant: '<S141>/B'
  //   Product: '<S163>/B[k]*u[k]'
  //   Product: '<S192>/Product3'
  //   Sum: '<S163>/Add'

  FCS_model_DW.MemoryX_DSTATE[0] = (FCS_model_P.B_Value[0] *
    rtb_TmpSignalConversionAtProd_i[2] + rtb_Product1[0]) +
    FCS_model_B.Product3[0];
  FCS_model_DW.MemoryX_DSTATE[1] = (FCS_model_P.B_Value[1] *
    rtb_TmpSignalConversionAtProd_i[2] + rtb_Product1[1]) +
    FCS_model_B.Product3[1];
  FCS_model_DW.MemoryX_DSTATE[2] = (FCS_model_P.B_Value[2] *
    rtb_TmpSignalConversionAtProd_i[2] + rtb_Product1[2]) +
    FCS_model_B.Product3[2];
  FCS_model_DW.MemoryX_DSTATE[3] = (rtb_TmpSignalConversionAtProd_i[2] *
    FCS_model_P.B_Value[3] + rtb_Product1[3]) + FCS_model_B.Product3[3];

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

  // Update for Delay: '<S51>/MemoryX'
  FCS_model_DW.icLoad_n = false;

  // Product: '<S89>/B[k]*u[k]' incorporates:
  //   Constant: '<S51>/B'

  rtb_SimplyIntegrateVelocity[0] = FCS_model_P.B_Value_p[0] * rtb_Product_c[0] +
    rtb_Product_c[1] * FCS_model_P.B_Value_p[2];

  // Product: '<S89>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S51>/A'
  //   Delay: '<S51>/MemoryX'

  tmp[0] = FCS_model_P.A_Value_p[0] * FCS_model_DW.MemoryX_DSTATE_o[0] +
    FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.A_Value_p[2];

  // Product: '<S89>/B[k]*u[k]' incorporates:
  //   Constant: '<S51>/B'

  rtb_SimplyIntegrateVelocity[1] = rtb_Product_c[0] * FCS_model_P.B_Value_p[1] +
    rtb_Product_c[1] * FCS_model_P.B_Value_p[3];

  // Product: '<S89>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S51>/A'
  //   Delay: '<S51>/MemoryX'

  tmp[1] = FCS_model_DW.MemoryX_DSTATE_o[0] * FCS_model_P.A_Value_p[1] +
    FCS_model_DW.MemoryX_DSTATE_o[1] * FCS_model_P.A_Value_p[3];
  for (cff = 0; cff < 2; cff++) {
    // Update for Delay: '<S51>/MemoryX' incorporates:
    //   Sum: '<S89>/Add'

    FCS_model_DW.MemoryX_DSTATE_o[cff] = (rtb_SimplyIntegrateVelocity[cff] +
      tmp[cff]) + FCS_model_B.Product3_d[cff];

    // Update for DiscreteFilter: '<S50>/IIRgyroz'
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

    // Update for UnitDelay: '<S58>/UD'
    //
    //  Block description for '<S58>/UD':
    //
    //   Store in Global RAM

    FCS_model_DW.UD_DSTATE[cff] = rtb_Reshapey[cff];
  }

  // Update for DiscreteIntegrator: '<S138>/Integrator' incorporates:
  //   Product: '<S124>/1//T'
  //   Sum: '<S124>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING = 0U;
  FCS_model_DW.Integrator_DSTATE += 1.0 / rtb_Divide * (rtb_K - rtb_Saturation) *
    FCS_model_P.Integrator_gainval;
  if (FCS_model_DW.Integrator_DSTATE >= FCS_model_P.Integrator_UpperSat) {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_UpperSat;
  } else if (FCS_model_DW.Integrator_DSTATE <= FCS_model_P.Integrator_LowerSat)
  {
    FCS_model_DW.Integrator_DSTATE = FCS_model_P.Integrator_LowerSat;
  }

  FCS_model_DW.Integrator_PrevResetState = static_cast<int8_T>
    (rtb_LogicalOperator_b);

  // End of Update for DiscreteIntegrator: '<S138>/Integrator'

  // Update for Delay: '<S52>/Delay2'
  for (int32_T i{0}; i < 39; i++) {
    FCS_model_DW.Delay2_DSTATE[i] = FCS_model_DW.Delay2_DSTATE[i + 1];
  }

  FCS_model_DW.Delay2_DSTATE[39] = inverseIMU_gain[3];

  // End of Update for Delay: '<S52>/Delay2'

  // Update for DiscreteIntegrator: '<S131>/Integrator' incorporates:
  //   Product: '<S123>/1//T'
  //   Sum: '<S123>/Sum1'

  FCS_model_DW.Integrator_IC_LOADING_g = 0U;
  FCS_model_DW.Integrator_DSTATE_e += 1.0 / rtb_orient_pitch * (rtb_K_i -
    rtb_Saturation_jg) * FCS_model_P.Integrator_gainval_g;
  if (FCS_model_DW.Integrator_DSTATE_e >= FCS_model_P.Integrator_UpperSat_i) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_UpperSat_i;
  } else if (FCS_model_DW.Integrator_DSTATE_e <=
             FCS_model_P.Integrator_LowerSat_l) {
    FCS_model_DW.Integrator_DSTATE_e = FCS_model_P.Integrator_LowerSat_l;
  }

  FCS_model_DW.Integrator_PrevResetState_e = static_cast<int8_T>
    (rtb_LogicalOperator_j);

  // End of Update for DiscreteIntegrator: '<S131>/Integrator'

  // Update for Delay: '<S52>/Delay1'
  for (int32_T i{0}; i < 39; i++) {
    FCS_model_DW.Delay1_DSTATE[i] = FCS_model_DW.Delay1_DSTATE[i + 1];
  }

  FCS_model_DW.Delay1_DSTATE[39] = inverseIMU_gain[4];

  // End of Update for Delay: '<S52>/Delay1'

  // Update for DiscreteIntegrator: '<S44>/SimplyIntegrateVelocity'
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[0] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval *
    rtb_TmpSignalConversionAtProduc[0];
  FCS_model_DW.SimplyIntegrateVelocity_DSTATE[1] +=
    FCS_model_P.SimplyIntegrateVelocity_gainval *
    rtb_TmpSignalConversionAtProduc[1];

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
  //   Inport: '<Root>/in_sensors'

  FCS_model_DW.DiscreteTimeIntegrator_DSTATE +=
    FCS_model_P.DiscreteTimeIntegrator_gainval * arg_in_sensors->battery_current;
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

  // Start for Probe: '<S132>/Probe'
  FCS_model_B.Probe[0] = 0.0025;
  FCS_model_B.Probe[1] = 0.0;

  // Start for Probe: '<S125>/Probe'
  FCS_model_B.Probe_c[0] = 0.0025;
  FCS_model_B.Probe_c[1] = 0.0;

  // InitializeConditions for Merge: '<S200>/Merge1' incorporates:
  //   Memory: '<S41>/Memory'

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

  // InitializeConditions for DiscreteFilter: '<S140>/Discrete Filter1'
  FCS_model_DW.DiscreteFilter1_states[0] =
    FCS_model_P.DiscreteFilter1_InitialStates;
  FCS_model_DW.DiscreteFilter1_states[1] =
    FCS_model_P.DiscreteFilter1_InitialStates;
  FCS_model_DW.DiscreteFilter1_states[2] =
    FCS_model_P.DiscreteFilter1_InitialStates;

  // InitializeConditions for Delay: '<S141>/MemoryX'
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

  // InitializeConditions for Delay: '<S51>/MemoryX'
  FCS_model_DW.icLoad_n = true;

  // InitializeConditions for DiscreteFilter: '<S50>/IIRgyroz'
  for (int32_T i{0}; i < 10; i++) {
    FCS_model_DW.IIRgyroz_states[i] = FCS_model_P.IIRgyroz_InitialStates;
  }

  // End of InitializeConditions for DiscreteFilter: '<S50>/IIRgyroz'

  // InitializeConditions for UnitDelay: '<S58>/UD'
  //
  //  Block description for '<S58>/UD':
  //
  //   Store in Global RAM

  FCS_model_DW.UD_DSTATE[0] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for Delay: '<S45>/Delay'
  FCS_model_DW.Delay_DSTATE[0] = FCS_model_P.Delay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S58>/UD'
  //
  //  Block description for '<S58>/UD':
  //
  //   Store in Global RAM

  FCS_model_DW.UD_DSTATE[1] = FCS_model_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for Delay: '<S45>/Delay'
  FCS_model_DW.Delay_DSTATE[1] = FCS_model_P.Delay_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<S138>/Integrator'
  FCS_model_DW.Integrator_IC_LOADING = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S131>/Integrator'
  FCS_model_DW.Integrator_IC_LOADING_g = 1U;
  for (int32_T i{0}; i < 40; i++) {
    // InitializeConditions for Delay: '<S52>/Delay2'
    FCS_model_DW.Delay2_DSTATE[i] = FCS_model_P.Delay2_InitialCondition;

    // InitializeConditions for Delay: '<S52>/Delay1'
    FCS_model_DW.Delay1_DSTATE[i] = FCS_model_P.Delay1_InitialCondition;
  }

  // InitializeConditions for DiscreteIntegrator: '<S44>/SimplyIntegrateVelocity' 
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

  // SystemInitialize for Enabled SubSystem: '<S163>/MeasurementUpdate'
  // SystemInitialize for Product: '<S192>/Product3' incorporates:
  //   Outport: '<S192>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S163>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S169>/Enabled Subsystem'
  // SystemInitialize for Product: '<S194>/Product2' incorporates:
  //   Outport: '<S194>/deltax'

  FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S169>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S163>/MeasurementUpdate'
  // SystemInitialize for Product: '<S192>/Product3' incorporates:
  //   Outport: '<S192>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S163>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S169>/Enabled Subsystem'
  // SystemInitialize for Product: '<S194>/Product2' incorporates:
  //   Outport: '<S194>/deltax'

  FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S169>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S163>/MeasurementUpdate'
  // SystemInitialize for Product: '<S192>/Product3' incorporates:
  //   Outport: '<S192>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S163>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S169>/Enabled Subsystem'
  // SystemInitialize for Product: '<S194>/Product2' incorporates:
  //   Outport: '<S194>/deltax'

  FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S169>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S163>/MeasurementUpdate'
  // SystemInitialize for Product: '<S192>/Product3' incorporates:
  //   Outport: '<S192>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S163>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S169>/Enabled Subsystem'
  // SystemInitialize for Product: '<S194>/Product2' incorporates:
  //   Outport: '<S194>/deltax'

  FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0_k;

  // End of SystemInitialize for SubSystem: '<S169>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S96>/Enabled Subsystem'
  // SystemInitialize for Product: '<S122>/Product2' incorporates:
  //   Outport: '<S122>/deltax'

  FCS_model_B.Product2_c[0] = FCS_model_P.deltax_Y0;

  // End of SystemInitialize for SubSystem: '<S96>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S89>/MeasurementUpdate'
  // SystemInitialize for Product: '<S120>/Product3' incorporates:
  //   Outport: '<S120>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3_d[0] = FCS_model_P.Lykyhatkk1_Y0;

  // End of SystemInitialize for SubSystem: '<S89>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S96>/Enabled Subsystem'
  // SystemInitialize for Product: '<S122>/Product2' incorporates:
  //   Outport: '<S122>/deltax'

  FCS_model_B.Product2_c[1] = FCS_model_P.deltax_Y0;

  // End of SystemInitialize for SubSystem: '<S96>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S89>/MeasurementUpdate'
  // SystemInitialize for Product: '<S120>/Product3' incorporates:
  //   Outport: '<S120>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3_d[1] = FCS_model_P.Lykyhatkk1_Y0;

  // End of SystemInitialize for SubSystem: '<S89>/MeasurementUpdate'
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
