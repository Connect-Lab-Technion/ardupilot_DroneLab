//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.39
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Jul 31 08:29:29 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FCS_model.h"
#include "rtwtypes.h"
#include <cmath>
#include "FCS_model_private.h"
#include "rt_defines.h"
#include "zero_crossing_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T yL_0d0;
  uint32_T iLeft;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'wrapping'

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaNF);
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real32_T>(tmp), static_cast<real32_T>(tmp_0));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

// Model step function
void FCS_model::step(uint8_T *arg_switch, real32_T *arg_gain, real32_T
                     arg_accel[3], real32_T arg_gyro[3], real32_T *arg_bat_V,
                     real32_T arg_flowRate[2], real32_T *arg_baro, real32_T
                     *arg_rangefinder, real32_T arg_pos_est[3], real32_T
                     arg_vel_est[3], real32_T *arg_yaw, real32_T arg_pos_ref[3],
                     real32_T arg_orient_ref[3], real32_T arg_motors_refout[4],
                     real32_T arg_logging_refout[40])
{
  // local block i/o variables
  real32_T rtb_Sum1_j;
  real32_T rtb_Sum1_jt;
  real32_T rtb_roll;
  real_T rtb_MathFunction[9];
  real_T rtb_VectorConcatenate[9];
  real_T tmp[4];
  real_T rtb_MathFunction_0[3];
  real_T rtb_Sum[3];
  real_T rtb_sincos_o2[3];
  real_T rtb_Akxhatkk1_idx_0;
  real_T rtb_Akxhatkk1_idx_1;
  real_T rtb_Sum_f;
  real_T rtb_VectorConcatenate_tmp;
  real_T rtb_VectorConcatenate_tmp_0;
  real32_T rtb_DataTypeConversion1_o;
  real32_T rtb_DataTypeConversion2;
  real32_T rtb_DataTypeConversion6;
  real32_T rtb_On1Off0forthrust;
  real32_T rtb_Product4;
  real32_T rtb_TrigonometricFunction4;
  real32_T rtb_rollrate;

  // If: '<S97>/If1' incorporates:
  //   Constant: '<S37>/Constant'
  //   DataTypeConversion: '<S97>/Data Type Conversion'

  if (static_cast<real32_T>(FCS_model_P.Constant_Value_a) > 0.0F) {
    // Outputs for IfAction SubSystem: '<S97>/If Action Subsystem' incorporates:
    //   ActionPort: '<S99>/Action Port'

    // Merge: '<S97>/Merge1' incorporates:
    //   DiscreteTransferFcn: '<S100>/Discrete Transfer Fcn'

    FCS_model_DW.Memory_PreviousInput = FCS_model_P.DiscreteTransferFcn_NumCoef
      [1] * FCS_model_DW.DiscreteTransferFcn_states_n;

    // Update for DiscreteTransferFcn: '<S100>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S100>/Gain'
    //   Inport: '<Root>/gyro'
    //   Inport: '<Root>/yaw_est'
    //   Sum: '<S100>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_n = ((FCS_model_P.w_c_yaw * *arg_yaw
      + arg_gyro[2]) - FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_n) /
      FCS_model_P.DiscreteTransferFcn_DenCoef[0];

    // End of Outputs for SubSystem: '<S97>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S97>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S98>/Action Port'

    // Merge: '<S97>/Merge1' incorporates:
    //   Gain: '<S98>/Gain'
    //   Inport: '<Root>/gyro'
    //   Memory: '<S37>/Memory'
    //   Sum: '<S98>/Sum'

    FCS_model_DW.Memory_PreviousInput += FCS_model_P.Ts * arg_gyro[2];

    // End of Outputs for SubSystem: '<S97>/If Action Subsystem3'
  }

  // End of If: '<S97>/If1'

  // DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn'
  rtb_TrigonometricFunction4 = FCS_model_P.DiscreteTransferFcn_NumCoef_n[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S94>/Discrete Transfer Fcn'
  rtb_rollrate = FCS_model_P.DiscreteTransferFcn_NumCoef_a[1] *
    FCS_model_DW.DiscreteTransferFcn_states_e;

  // Trigonometry: '<S40>/sincos' incorporates:
  //   DataTypeConversion: '<S36>/Data Type Conversion4'
  //   DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S94>/Discrete Transfer Fcn'

  rtb_sincos_o2[0] = std::cos(static_cast<real_T>
    (FCS_model_DW.Memory_PreviousInput));
  rtb_Akxhatkk1_idx_0 = std::sin(static_cast<real_T>
    (FCS_model_DW.Memory_PreviousInput));
  rtb_sincos_o2[1] = std::cos(static_cast<real_T>(rtb_TrigonometricFunction4));
  rtb_Akxhatkk1_idx_1 = std::sin(static_cast<real_T>(rtb_TrigonometricFunction4));
  rtb_sincos_o2[2] = std::cos(static_cast<real_T>(rtb_rollrate));
  rtb_Sum_f = std::sin(static_cast<real_T>(rtb_rollrate));

  // Fcn: '<S40>/Fcn11'
  rtb_VectorConcatenate[0] = rtb_sincos_o2[0] * rtb_sincos_o2[1];

  // Fcn: '<S40>/Fcn21' incorporates:
  //   Fcn: '<S40>/Fcn22'

  rtb_VectorConcatenate_tmp = rtb_Akxhatkk1_idx_1 * rtb_Sum_f;
  rtb_VectorConcatenate[1] = rtb_VectorConcatenate_tmp * rtb_sincos_o2[0] -
    rtb_Akxhatkk1_idx_0 * rtb_sincos_o2[2];

  // Fcn: '<S40>/Fcn31' incorporates:
  //   Fcn: '<S40>/Fcn32'

  rtb_VectorConcatenate_tmp_0 = rtb_Akxhatkk1_idx_1 * rtb_sincos_o2[2];
  rtb_VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 * rtb_sincos_o2[0] +
    rtb_Akxhatkk1_idx_0 * rtb_Sum_f;

  // Fcn: '<S40>/Fcn12'
  rtb_VectorConcatenate[3] = rtb_Akxhatkk1_idx_0 * rtb_sincos_o2[1];

  // Fcn: '<S40>/Fcn22'
  rtb_VectorConcatenate[4] = rtb_VectorConcatenate_tmp * rtb_Akxhatkk1_idx_0 +
    rtb_sincos_o2[0] * rtb_sincos_o2[2];

  // Fcn: '<S40>/Fcn32'
  rtb_VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 * rtb_Akxhatkk1_idx_0 -
    rtb_sincos_o2[0] * rtb_Sum_f;

  // Fcn: '<S40>/Fcn13'
  rtb_VectorConcatenate[6] = -rtb_Akxhatkk1_idx_1;

  // Fcn: '<S40>/Fcn23'
  rtb_VectorConcatenate[7] = rtb_sincos_o2[1] * rtb_Sum_f;

  // Fcn: '<S40>/Fcn33'
  rtb_VectorConcatenate[8] = rtb_sincos_o2[1] * rtb_sincos_o2[2];

  // Math: '<S38>/Math Function' incorporates:
  //   Concatenate: '<S92>/Vector Concatenate'

  for (int32_T iU{0}; iU < 3; iU++) {
    rtb_MathFunction[3 * iU] = rtb_VectorConcatenate[iU];
    rtb_MathFunction[3 * iU + 1] = rtb_VectorConcatenate[iU + 3];
    rtb_MathFunction[3 * iU + 2] = rtb_VectorConcatenate[iU + 6];
  }

  // End of Math: '<S38>/Math Function'

  // Outputs for Triggered SubSystem: '<S101>/Triggered Subsystem' incorporates:
  //   TriggerPort: '<S103>/Trigger'

  // Inport: '<Root>/master_switch'
  if ((*arg_switch > 0) && (FCS_model_PrevZCX.TriggeredSubsystem_Trig_ZCE_d !=
       POS_ZCSIG)) {
    // SignalConversion generated from: '<S103>/1' incorporates:
    //   Inport: '<Root>/baro'

    FCS_model_B.u = *arg_baro;
  }

  FCS_model_PrevZCX.TriggeredSubsystem_Trig_ZCE_d = (*arg_switch > 0);

  // End of Outputs for SubSystem: '<S101>/Triggered Subsystem'

  // Sum: '<S101>/Subtract' incorporates:
  //   Inport: '<Root>/baro'

  rtb_Product4 = *arg_baro - FCS_model_B.u;

  // Delay: '<S39>/MemoryX' incorporates:
  //   Constant: '<S39>/X0'

  if (FCS_model_DW.icLoad) {
    FCS_model_DW.MemoryX_DSTATE[0] = FCS_model_P.X0_Value[0];
    FCS_model_DW.MemoryX_DSTATE[1] = FCS_model_P.X0_Value[1];
    FCS_model_DW.MemoryX_DSTATE[2] = FCS_model_P.X0_Value[2];
    FCS_model_DW.MemoryX_DSTATE[3] = FCS_model_P.X0_Value[3];
  }

  // SignalConversion generated from: '<S38>/Product2' incorporates:
  //   DataTypeConversion: '<S36>/Data Type Conversion1'
  //   Gain: '<S38>/RangfinderScaleGain1'
  //   Inport: '<Root>/rangefinder'

  rtb_Akxhatkk1_idx_0 = static_cast<real_T>
    (FCS_model_P.RangfinderScaleGain1_Gain) * *arg_rangefinder;
  for (int32_T iU{0}; iU < 3; iU++) {
    // Product: '<S38>/Product2' incorporates:
    //   Math: '<S38>/Math Function'

    rtb_Akxhatkk1_idx_1 = rtb_MathFunction[iU];

    // Sum: '<S38>/Sum' incorporates:
    //   DataTypeConversion: '<S36>/Data Type Conversion'
    //   Inport: '<Root>/accel'
    //   Product: '<S38>/Product'

    rtb_Sum_f = rtb_Akxhatkk1_idx_1 * arg_accel[0];

    // Product: '<S38>/Product2' incorporates:
    //   Constant: '<S38>/Constant'
    //   Math: '<S38>/Math Function'

    rtb_VectorConcatenate_tmp = rtb_Akxhatkk1_idx_1 *
      FCS_model_P.Constant_Value_n;
    rtb_Akxhatkk1_idx_1 = rtb_MathFunction[iU + 3];

    // Sum: '<S38>/Sum' incorporates:
    //   DataTypeConversion: '<S36>/Data Type Conversion'
    //   Inport: '<Root>/accel'
    //   Product: '<S38>/Product'

    rtb_Sum_f += rtb_Akxhatkk1_idx_1 * arg_accel[1];

    // Product: '<S38>/Product2' incorporates:
    //   Constant: '<S38>/Constant'
    //   Math: '<S38>/Math Function'

    rtb_VectorConcatenate_tmp += rtb_Akxhatkk1_idx_1 *
      FCS_model_P.Constant_Value_n;
    rtb_Akxhatkk1_idx_1 = rtb_MathFunction[iU + 6];

    // Sum: '<S38>/Sum' incorporates:
    //   Constant: '<S38>/gravity'
    //   DataTypeConversion: '<S36>/Data Type Conversion'
    //   Inport: '<Root>/accel'
    //   Product: '<S38>/Product'

    rtb_MathFunction_0[iU] = (rtb_Akxhatkk1_idx_1 * arg_accel[2] + rtb_Sum_f) +
      FCS_model_P.gravity_Value[iU];

    // Product: '<S38>/Product2'
    rtb_Sum[iU] = rtb_Akxhatkk1_idx_1 * rtb_Akxhatkk1_idx_0 +
      rtb_VectorConcatenate_tmp;
  }

  // Reshape: '<S39>/Reshapey' incorporates:
  //   DataTypeConversion: '<S36>/Data Type Conversion2'
  //   Gain: '<S38>/prsToAltGain'

  rtb_sincos_o2[0] = 1.0 / FCS_model_P.Sensors.altToPrsGain * rtb_Product4;
  rtb_sincos_o2[1] = rtb_Sum[2];
  rtb_sincos_o2[2] = rtb_MathFunction_0[2];

  // Outputs for Enabled SubSystem: '<S66>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S91>/Enable'

  // DataTypeConversion: '<S39>/DataTypeConversionEnable' incorporates:
  //   Inport: '<Root>/master_switch'

  if (*arg_switch != 0) {
    FCS_model_DW.EnabledSubsystem_MODE = true;

    // Sum: '<S91>/Add1' incorporates:
    //   Constant: '<S39>/C'
    //   Delay: '<S39>/MemoryX'
    //   Product: '<S91>/Product'

    for (int32_T iU{0}; iU < 3; iU++) {
      rtb_Sum[iU] = rtb_sincos_o2[iU] - (((FCS_model_P.C_Value[iU + 3] *
        FCS_model_DW.MemoryX_DSTATE[1] + FCS_model_P.C_Value[iU] *
        FCS_model_DW.MemoryX_DSTATE[0]) + FCS_model_P.C_Value[iU + 6] *
        FCS_model_DW.MemoryX_DSTATE[2]) + FCS_model_P.C_Value[iU + 9] *
        FCS_model_DW.MemoryX_DSTATE[3]);
    }

    // End of Sum: '<S91>/Add1'
    for (int32_T iU{0}; iU < 4; iU++) {
      // Product: '<S91>/Product2' incorporates:
      //   Constant: '<S41>/KalmanGainM'

      FCS_model_B.Product2[iU] = 0.0;
      FCS_model_B.Product2[iU] += FCS_model_P.KalmanGainM_Value[iU] * rtb_Sum[0];
      FCS_model_B.Product2[iU] += FCS_model_P.KalmanGainM_Value[iU + 4] *
        rtb_Sum[1];
      FCS_model_B.Product2[iU] += FCS_model_P.KalmanGainM_Value[iU + 8] *
        rtb_Sum[2];
    }
  } else if (FCS_model_DW.EnabledSubsystem_MODE) {
    // Disable for Product: '<S91>/Product2' incorporates:
    //   Outport: '<S91>/deltax'

    FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0;
    FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0;
    FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0;
    FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0;
    FCS_model_DW.EnabledSubsystem_MODE = false;
  }

  // End of Outputs for SubSystem: '<S66>/Enabled Subsystem'

  // Sum: '<S66>/Add' incorporates:
  //   Delay: '<S39>/MemoryX'

  rtb_Akxhatkk1_idx_0 = FCS_model_B.Product2[0] + FCS_model_DW.MemoryX_DSTATE[0];
  rtb_Akxhatkk1_idx_1 = FCS_model_B.Product2[1] + FCS_model_DW.MemoryX_DSTATE[1];

  // Product: '<S38>/Product1' incorporates:
  //   Concatenate: '<S92>/Vector Concatenate'
  //   SignalConversion generated from: '<S38>/Product1'

  for (int32_T iU{0}; iU < 3; iU++) {
    rtb_Sum[iU] = (rtb_VectorConcatenate[iU + 3] * 0.0 +
                   rtb_VectorConcatenate[iU] * 0.0) + rtb_VectorConcatenate[iU +
      6] * rtb_Akxhatkk1_idx_1;
  }

  // End of Product: '<S38>/Product1'

  // DiscreteStateSpace: '<S12>/Internal' incorporates:
  //   Inport: '<Root>/pos_ref'

  {
    rtb_roll = (FCS_model_P.Internal_C[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_C[1])*FCS_model_DW.Internal_DSTATE[1];
  }

  // Sum: '<S5>/Sum2' incorporates:
  //   Constant: '<S5>/Constant1'
  //   DataTypeConversion: '<S38>/Data Type Conversion'
  //   DataTypeConversion: '<S38>/Data Type Conversion2'
  //   Gain: '<S5>/Gain'
  //   Gain: '<S5>/KDz'
  //   Gain: '<S5>/WithControl=1 WithoutControl=0'
  //   Gain: '<S5>/zDz'
  //   Sum: '<S5>/Sum1'
  //   Sum: '<S5>/Sum3'

  rtb_Akxhatkk1_idx_1 = ((rtb_roll - FCS_model_P.Gain_Gain *
    static_cast<real32_T>(rtb_Akxhatkk1_idx_0)) * FCS_model_P.zDz -
    static_cast<real32_T>(rtb_Sum[2])) * FCS_model_P.KDz *
    FCS_model_P.WithControl1WithoutControl0_Gai + FCS_model_P.Constant1_Value;

  // Saturate: '<S5>/SaturationThrust'
  if (rtb_Akxhatkk1_idx_1 > FCS_model_P.SaturationThrust_UpperSat) {
    // Trigonometry: '<S95>/Trigonometric Function'
    rtb_roll = FCS_model_P.SaturationThrust_UpperSat;
  } else if (rtb_Akxhatkk1_idx_1 < FCS_model_P.SaturationThrust_LowerSat) {
    // Trigonometry: '<S95>/Trigonometric Function'
    rtb_roll = FCS_model_P.SaturationThrust_LowerSat;
  } else {
    // Trigonometry: '<S95>/Trigonometric Function'
    rtb_roll = static_cast<real32_T>(rtb_Akxhatkk1_idx_1);
  }

  // End of Saturate: '<S5>/SaturationThrust'

  // Gain: '<S1>/On=1//Off=0 for thrust'
  rtb_On1Off0forthrust = FCS_model_P.On1Off0forthrust_Gain * rtb_roll;

  // DiscreteStateSpace: '<S32>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    rtb_roll = (FCS_model_P.Internal_C_a[0])*FCS_model_DW.Internal_DSTATE_h[0]
      + (FCS_model_P.Internal_C_a[1])*FCS_model_DW.Internal_DSTATE_h[1];
  }

  // Trigonometry: '<S95>/Trigonometric Function' incorporates:
  //   Gain: '<S10>/zDpsi'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S10>/Sum1'
  //   Sum: '<S10>/Sum3'

  rtb_roll = (rtb_roll - FCS_model_DW.Memory_PreviousInput) *
    FCS_model_P.zDpsi_Gain;
  rtb_roll -= arg_gyro[2];

  // DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
  //   Constant: '<S1>/yaw equilibrium'
  //   Gain: '<S10>/KDpsi'
  //   Gain: '<S1>/Changing of Jzz'
  //   Gain: '<S1>/On=1//Off=1 for yaw'
  //   Sum: '<S1>/Sum3'

  rtb_DataTypeConversion2 = static_cast<real32_T>((FCS_model_P.KDpsi_Gain *
    rtb_roll * FCS_model_P.ChangingofJzz_Gain + FCS_model_P.yawequilibrium_Value)
    * FCS_model_P.On1Off1foryaw_Gain);

  // DiscreteStateSpace: '<S16>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    rtb_roll = (FCS_model_P.Internal_C_i[0])*FCS_model_DW.Internal_DSTATE_a[0]
      + (FCS_model_P.Internal_C_i[1])*FCS_model_DW.Internal_DSTATE_a[1];
  }

  // Sum: '<S7>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn'

  rtb_Sum1_j = rtb_roll - rtb_TrigonometricFunction4;

  // DiscreteStateSpace: '<S17>/Internal'
  {
    rtb_roll = FCS_model_P.Internal_C_ai*FCS_model_DW.Internal_DSTATE_g;
    rtb_roll += FCS_model_P.Internal_D_e*rtb_Sum1_j;
  }

  // Trigonometry: '<S95>/Trigonometric Function' incorporates:
  //   Gain: '<S7>/zDtheta'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S7>/Sum3'

  rtb_roll *= FCS_model_P.zDtheta_Gain;
  rtb_roll -= arg_gyro[1];

  // DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
  //   Constant: '<S1>/pitch equilibrium'
  //   Gain: '<S1>/Changing of Jyy'
  //   Gain: '<S1>/On=1//Off=2 for pitch'
  //   Gain: '<S7>/KDtheta'
  //   Sum: '<S1>/Sum1'

  rtb_DataTypeConversion6 = static_cast<real32_T>((FCS_model_P.KDtheta_Gain *
    rtb_roll * FCS_model_P.ChangingofJyy_Gain +
    FCS_model_P.pitchequilibrium_Value) * FCS_model_P.On1Off2forpitch_Gain);

  // DiscreteStateSpace: '<S24>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    rtb_roll = (FCS_model_P.Internal_C_c[0])*FCS_model_DW.Internal_DSTATE_l[0]
      + (FCS_model_P.Internal_C_c[1])*FCS_model_DW.Internal_DSTATE_l[1];
  }

  // Sum: '<S8>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S94>/Discrete Transfer Fcn'

  rtb_Sum1_jt = rtb_roll - rtb_rollrate;

  // DiscreteStateSpace: '<S25>/Internal'
  {
    rtb_roll = FCS_model_P.Internal_C_g*FCS_model_DW.Internal_DSTATE_gs;
    rtb_roll += FCS_model_P.Internal_D_h*rtb_Sum1_jt;
  }

  // Trigonometry: '<S95>/Trigonometric Function' incorporates:
  //   Gain: '<S8>/zDphi'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S8>/Sum3'

  rtb_roll *= FCS_model_P.zDphi_Gain;
  rtb_roll -= arg_gyro[0];

  // DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
  //   Constant: '<S1>/roll equilibrium'
  //   Gain: '<S1>/Changing of Jxx'
  //   Gain: '<S1>/On=1//Off=1 for roll'
  //   Gain: '<S8>/KDphi'
  //   Sum: '<S1>/Sum2'

  rtb_DataTypeConversion1_o = static_cast<real32_T>((FCS_model_P.KDphi_Gain *
    rtb_roll * FCS_model_P.ChangingofJxx_Gain +
    FCS_model_P.rollequilibrium_Value) * FCS_model_P.On1Off1forroll_Gain);

  // Switch: '<S9>/Switch' incorporates:
  //   Constant: '<S9>/Constant'
  //   Inport: '<Root>/master_switch'
  //   Lookup_n-D: '<S11>/1-D Lookup Table2'
  //   Product: '<S9>/Product'

  if (*arg_switch > FCS_model_P.Switch_Threshold) {
    real32_T rtb_Saturation;

    // Saturate: '<S9>/Saturation' incorporates:
    //   Inport: '<Root>/power gain'

    if (*arg_gain > FCS_model_P.Saturation_UpperSat) {
      rtb_Saturation = FCS_model_P.Saturation_UpperSat;
    } else if (*arg_gain < FCS_model_P.Saturation_LowerSat) {
      rtb_Saturation = FCS_model_P.Saturation_LowerSat;
    } else {
      rtb_Saturation = *arg_gain;
    }

    // End of Saturate: '<S9>/Saturation'
    for (int32_T iU{0}; iU < 4; iU++) {
      // Product: '<S6>/Product' incorporates:
      //   Constant: '<S6>/TorqueTotalThrustToThrustPerMotor'
      //   Lookup_n-D: '<S11>/1-D Lookup Table2'
      //   SignalConversion generated from: '<S6>/Product'

      arg_motors_refout[iU] = 0.0F;
      arg_motors_refout[iU] += FCS_model_P.TorqueTotalThrustToThrustPerMot[iU] *
        rtb_On1Off0forthrust;
      arg_motors_refout[iU] += FCS_model_P.TorqueTotalThrustToThrustPerMot[iU +
        4] * rtb_DataTypeConversion2;
      arg_motors_refout[iU] += FCS_model_P.TorqueTotalThrustToThrustPerMot[iU +
        8] * rtb_DataTypeConversion6;
      arg_motors_refout[iU] += FCS_model_P.TorqueTotalThrustToThrustPerMot[iU +
        12] * rtb_DataTypeConversion1_o;

      // Lookup_n-D: '<S11>/1-D Lookup Table2'
      arg_motors_refout[iU] = look1_iflf_binlx(arg_motors_refout[iU],
        FCS_model_P.uDLookupTable2_bp01Data,
        FCS_model_P.uDLookupTable2_tableData, 9U);
      arg_motors_refout[iU] *= rtb_Saturation;
    }
  } else {
    arg_motors_refout[0] = static_cast<real32_T>(FCS_model_P.Constant_Value[0]);
    arg_motors_refout[1] = static_cast<real32_T>(FCS_model_P.Constant_Value[1]);
    arg_motors_refout[2] = static_cast<real32_T>(FCS_model_P.Constant_Value[2]);
    arg_motors_refout[3] = static_cast<real32_T>(FCS_model_P.Constant_Value[3]);
  }

  // End of Switch: '<S9>/Switch'

  // Trigonometry: '<S95>/Trigonometric Function' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion14'
  //   DigitalClock: '<S3>/Digital Clock'

  rtb_roll = static_cast<real32_T>((((&FCS_model_M)->Timing.clockTick0) * 0.0025));

  // Outputs for Triggered SubSystem: '<S102>/Triggered Subsystem' incorporates:
  //   TriggerPort: '<S104>/Trigger'

  // Inport: '<Root>/master_switch'
  if ((*arg_switch > 0) && (FCS_model_PrevZCX.TriggeredSubsystem_Trig_ZCE !=
       POS_ZCSIG)) {
    // SignalConversion generated from: '<S104>/position' incorporates:
    //   Inport: '<Root>/pos_est'

    FCS_model_B.position[0] = arg_pos_est[0];
    FCS_model_B.position[1] = arg_pos_est[1];
    FCS_model_B.position[2] = arg_pos_est[2];
  }

  FCS_model_PrevZCX.TriggeredSubsystem_Trig_ZCE = (*arg_switch > 0);

  // End of Outputs for SubSystem: '<S102>/Triggered Subsystem'

  // Outport: '<Root>/logging_out' incorporates:
  //   DataTypeConversion: '<S38>/Data Type Conversion'
  //   DataTypeConversion: '<S38>/Data Type Conversion2'
  //   DataTypeConversion: '<S3>/Data Type Conversion'
  //   DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S94>/Discrete Transfer Fcn'
  //   Inport: '<Root>/accel'
  //   Inport: '<Root>/bat_V'
  //   Inport: '<Root>/flowRate'
  //   Inport: '<Root>/gyro'
  //   Inport: '<Root>/master_switch'
  //   Inport: '<Root>/orient_ref'
  //   Inport: '<Root>/pos_est'
  //   Inport: '<Root>/pos_ref'
  //   Inport: '<Root>/power gain'
  //   Inport: '<Root>/rangefinder'
  //   Inport: '<Root>/vel_est'
  //   Inport: '<Root>/yaw_est'
  //   Sum: '<S102>/Subtract'

  arg_logging_refout[0] = rtb_roll;
  arg_logging_refout[1] = FCS_model_DW.Memory_PreviousInput;
  arg_logging_refout[2] = rtb_TrigonometricFunction4;
  arg_logging_refout[3] = rtb_rollrate;
  arg_logging_refout[4] = arg_accel[0];
  arg_logging_refout[7] = arg_gyro[0];
  arg_logging_refout[5] = arg_accel[1];
  arg_logging_refout[8] = arg_gyro[1];
  arg_logging_refout[6] = arg_accel[2];
  arg_logging_refout[9] = arg_gyro[2];
  arg_logging_refout[10] = *arg_bat_V;
  arg_logging_refout[11] = arg_flowRate[0];
  arg_logging_refout[12] = arg_flowRate[1];
  arg_logging_refout[13] = rtb_Product4;
  arg_logging_refout[14] = *arg_rangefinder;
  arg_logging_refout[15] = arg_pos_est[0] - FCS_model_B.position[0];
  arg_logging_refout[18] = arg_vel_est[0];
  arg_logging_refout[16] = arg_pos_est[1] - FCS_model_B.position[1];
  arg_logging_refout[19] = arg_vel_est[1];
  arg_logging_refout[17] = arg_pos_est[2] - FCS_model_B.position[2];
  arg_logging_refout[20] = arg_vel_est[2];
  arg_logging_refout[21] = *arg_yaw;
  arg_logging_refout[22] = arg_motors_refout[0];
  arg_logging_refout[23] = arg_motors_refout[1];
  arg_logging_refout[24] = arg_motors_refout[2];
  arg_logging_refout[25] = arg_motors_refout[3];
  arg_logging_refout[26] = *arg_switch;
  arg_logging_refout[27] = *arg_gain;
  arg_logging_refout[28] = arg_pos_ref[0];
  arg_logging_refout[31] = arg_orient_ref[0];
  arg_logging_refout[29] = arg_pos_ref[1];
  arg_logging_refout[32] = arg_orient_ref[1];
  arg_logging_refout[30] = arg_pos_ref[2];
  arg_logging_refout[33] = arg_orient_ref[2];
  arg_logging_refout[34] = static_cast<real32_T>(rtb_Akxhatkk1_idx_0);
  arg_logging_refout[35] = static_cast<real32_T>(rtb_Sum[2]);
  arg_logging_refout[36] = rtb_On1Off0forthrust;
  arg_logging_refout[37] = rtb_DataTypeConversion2;
  arg_logging_refout[38] = rtb_DataTypeConversion6;
  arg_logging_refout[39] = rtb_DataTypeConversion1_o;

  // Outputs for Enabled SubSystem: '<S60>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S89>/Enable'

  // DataTypeConversion: '<S39>/DataTypeConversionEnable' incorporates:
  //   Inport: '<Root>/master_switch'

  if (*arg_switch != 0) {
    FCS_model_DW.MeasurementUpdate_MODE = true;
    for (int32_T iU{0}; iU < 3; iU++) {
      // Sum: '<S89>/Sum' incorporates:
      //   Constant: '<S39>/C'
      //   Constant: '<S39>/D'
      //   Constant: '<S39>/u'
      //   Delay: '<S39>/MemoryX'
      //   Product: '<S89>/C[k]*xhat[k|k-1]'
      //   Product: '<S89>/D[k]*u[k]'
      //   Sum: '<S89>/Add1'

      rtb_Sum[iU] = rtb_sincos_o2[iU] - ((((FCS_model_P.C_Value[iU + 3] *
        FCS_model_DW.MemoryX_DSTATE[1] + FCS_model_P.C_Value[iU] *
        FCS_model_DW.MemoryX_DSTATE[0]) + FCS_model_P.C_Value[iU + 6] *
        FCS_model_DW.MemoryX_DSTATE[2]) + FCS_model_P.C_Value[iU + 9] *
        FCS_model_DW.MemoryX_DSTATE[3]) + FCS_model_P.D_Value[iU] *
        FCS_model_P.u_Value);
    }

    for (int32_T iU{0}; iU < 4; iU++) {
      // Product: '<S89>/Product3' incorporates:
      //   Constant: '<S41>/KalmanGainL'

      FCS_model_B.Product3[iU] = 0.0;
      FCS_model_B.Product3[iU] += FCS_model_P.KalmanGainL_Value[iU] * rtb_Sum[0];
      FCS_model_B.Product3[iU] += FCS_model_P.KalmanGainL_Value[iU + 4] *
        rtb_Sum[1];
      FCS_model_B.Product3[iU] += FCS_model_P.KalmanGainL_Value[iU + 8] *
        rtb_Sum[2];
    }
  } else if (FCS_model_DW.MeasurementUpdate_MODE) {
    // Disable for Product: '<S89>/Product3' incorporates:
    //   Outport: '<S89>/L*(y[k]-yhat[k|k-1])'

    FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0;
    FCS_model_DW.MeasurementUpdate_MODE = false;
  }

  // End of Outputs for SubSystem: '<S60>/MeasurementUpdate'

  // Product: '<S95>/Divide' incorporates:
  //   Constant: '<S95>/Constant'
  //   Gain: '<S95>/Gain1'
  //   Inport: '<Root>/accel'

  rtb_TrigonometricFunction4 = FCS_model_P.Gain1_Gain * arg_accel[0] /
    FCS_model_P.Constant_Value_o;

  // Trigonometry: '<S95>/Trigonometric Function1'
  if (rtb_TrigonometricFunction4 > 1.0F) {
    rtb_TrigonometricFunction4 = 1.0F;
  } else if (rtb_TrigonometricFunction4 < -1.0F) {
    rtb_TrigonometricFunction4 = -1.0F;
  }

  rtb_TrigonometricFunction4 = std::asin(rtb_TrigonometricFunction4);

  // End of Trigonometry: '<S95>/Trigonometric Function1'

  // Trigonometry: '<S95>/Trigonometric Function' incorporates:
  //   Gain: '<S95>/Gain2'
  //   Gain: '<S95>/Gain3'
  //   Inport: '<Root>/accel'

  rtb_roll = FCS_model_P.Gain2_Gain * arg_accel[1];
  rtb_roll = rt_atan2f_snf(rtb_roll, FCS_model_P.Gain3_Gain * arg_accel[2]);

  // Trigonometry: '<S96>/Trigonometric Function2'
  rtb_rollrate = std::sin(rtb_roll);
  rtb_Product4 = std::cos(rtb_roll);

  // Sum: '<S93>/Sum' incorporates:
  //   Gain: '<S93>/Gain'
  //   Gain: '<S96>/Gain'
  //   Inport: '<Root>/gyro'
  //   Product: '<S96>/Product4'
  //   Product: '<S96>/Product5'
  //   Sum: '<S96>/Sum1'

  rtb_On1Off0forthrust = (FCS_model_P.Gain_Gain_i * rtb_rollrate * arg_gyro[2] +
    rtb_Product4 * arg_gyro[1]) + FCS_model_P.w_c_pitch *
    rtb_TrigonometricFunction4;

  // Trigonometry: '<S96>/Trigonometric Function4'
  rtb_TrigonometricFunction4 = std::tan(rtb_TrigonometricFunction4);

  // Update for DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states = (rtb_On1Off0forthrust -
    FCS_model_P.DiscreteTransferFcn_DenCoef_n[1] *
    FCS_model_DW.DiscreteTransferFcn_states) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_n[0];

  // Update for DiscreteTransferFcn: '<S94>/Discrete Transfer Fcn' incorporates:
  //   Gain: '<S94>/Gain'
  //   Inport: '<Root>/gyro'
  //   Product: '<S96>/Product'
  //   Product: '<S96>/Product1'
  //   Product: '<S96>/Product2'
  //   Product: '<S96>/Product3'
  //   Sum: '<S94>/Sum'
  //   Sum: '<S96>/Sum'

  FCS_model_DW.DiscreteTransferFcn_states_e = ((((rtb_rollrate *
    rtb_TrigonometricFunction4 * arg_gyro[1] + arg_gyro[0]) + rtb_Product4 *
    rtb_TrigonometricFunction4 * arg_gyro[2]) + FCS_model_P.w_c_roll * rtb_roll)
    - FCS_model_P.DiscreteTransferFcn_DenCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states_e) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_o[0];

  // Update for Delay: '<S39>/MemoryX'
  FCS_model_DW.icLoad = false;

  // Product: '<S60>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S39>/A'
  //   Delay: '<S39>/MemoryX'

  for (int32_T iU{0}; iU < 4; iU++) {
    tmp[iU] = ((FCS_model_P.A_Value[iU + 4] * FCS_model_DW.MemoryX_DSTATE[1] +
                FCS_model_P.A_Value[iU] * FCS_model_DW.MemoryX_DSTATE[0]) +
               FCS_model_P.A_Value[iU + 8] * FCS_model_DW.MemoryX_DSTATE[2]) +
      FCS_model_P.A_Value[iU + 12] * FCS_model_DW.MemoryX_DSTATE[3];
  }

  // End of Product: '<S60>/A[k]*xhat[k|k-1]'

  // Update for Delay: '<S39>/MemoryX' incorporates:
  //   Constant: '<S39>/B'
  //   Constant: '<S39>/u'
  //   Product: '<S60>/B[k]*u[k]'
  //   Product: '<S89>/Product3'
  //   Sum: '<S60>/Add'

  FCS_model_DW.MemoryX_DSTATE[0] = (FCS_model_P.B_Value[0] * FCS_model_P.u_Value
    + tmp[0]) + FCS_model_B.Product3[0];
  FCS_model_DW.MemoryX_DSTATE[1] = (FCS_model_P.B_Value[1] * FCS_model_P.u_Value
    + tmp[1]) + FCS_model_B.Product3[1];
  FCS_model_DW.MemoryX_DSTATE[2] = (FCS_model_P.B_Value[2] * FCS_model_P.u_Value
    + tmp[2]) + FCS_model_B.Product3[2];
  FCS_model_DW.MemoryX_DSTATE[3] = (FCS_model_P.B_Value[3] * FCS_model_P.u_Value
    + tmp[3]) + FCS_model_B.Product3[3];

  // Update for DiscreteStateSpace: '<S12>/Internal' incorporates:
  //   Inport: '<Root>/pos_ref'

  {
    real32_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_A[1])*FCS_model_DW.Internal_DSTATE[1];
    xnew[0] += FCS_model_P.Internal_B*arg_pos_ref[2];
    xnew[1] = (FCS_model_P.Internal_A[2])*FCS_model_DW.Internal_DSTATE[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE[0], xnew,
                       sizeof(real32_T)*2);
  }

  // Update for DiscreteStateSpace: '<S32>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    real32_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_d[0])*FCS_model_DW.Internal_DSTATE_h[0]
      + (FCS_model_P.Internal_A_d[1])*FCS_model_DW.Internal_DSTATE_h[1];
    xnew[0] += FCS_model_P.Internal_B_f*arg_orient_ref[0];
    xnew[1] = (FCS_model_P.Internal_A_d[2])*FCS_model_DW.Internal_DSTATE_h[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_h[0], xnew,
                       sizeof(real32_T)*2);
  }

  // Update for DiscreteStateSpace: '<S16>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    real32_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_j[0])*FCS_model_DW.Internal_DSTATE_a[0]
      + (FCS_model_P.Internal_A_j[1])*FCS_model_DW.Internal_DSTATE_a[1];
    xnew[0] += FCS_model_P.Internal_B_k*arg_orient_ref[1];
    xnew[1] = (FCS_model_P.Internal_A_j[2])*FCS_model_DW.Internal_DSTATE_a[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_a[0], xnew,
                       sizeof(real32_T)*2);
  }

  // Update for DiscreteStateSpace: '<S17>/Internal'
  {
    real32_T xnew[1];
    xnew[0] = FCS_model_P.Internal_A_f*FCS_model_DW.Internal_DSTATE_g;
    xnew[0] += FCS_model_P.Internal_B_b*rtb_Sum1_j;
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_g, xnew,
                       sizeof(real32_T)*1);
  }

  // Update for DiscreteStateSpace: '<S24>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    real32_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_a[0])*FCS_model_DW.Internal_DSTATE_l[0]
      + (FCS_model_P.Internal_A_a[1])*FCS_model_DW.Internal_DSTATE_l[1];
    xnew[0] += FCS_model_P.Internal_B_h*arg_orient_ref[2];
    xnew[1] = (FCS_model_P.Internal_A_a[2])*FCS_model_DW.Internal_DSTATE_l[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_l[0], xnew,
                       sizeof(real32_T)*2);
  }

  // Update for DiscreteStateSpace: '<S25>/Internal'
  {
    real32_T xnew[1];
    xnew[0] = FCS_model_P.Internal_A_l*FCS_model_DW.Internal_DSTATE_gs;
    xnew[0] += FCS_model_P.Internal_B_e*rtb_Sum1_jt;
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_gs, xnew,
                       sizeof(real32_T)*1);
  }

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
  FCS_model_PrevZCX.TriggeredSubsystem_Trig_ZCE_d = POS_ZCSIG;
  FCS_model_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  // InitializeConditions for Merge: '<S97>/Merge1' incorporates:
  //   Memory: '<S37>/Memory'

  FCS_model_DW.Memory_PreviousInput = FCS_model_P.Memory_InitialCondition;

  // InitializeConditions for DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states =
    FCS_model_P.DiscreteTransferFcn_InitialSt_c;

  // InitializeConditions for DiscreteTransferFcn: '<S94>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_e =
    FCS_model_P.DiscreteTransferFcn_InitialSt_g;

  // InitializeConditions for Delay: '<S39>/MemoryX'
  FCS_model_DW.icLoad = true;

  // SystemInitialize for IfAction SubSystem: '<S97>/If Action Subsystem'
  // InitializeConditions for DiscreteTransferFcn: '<S100>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_n =
    FCS_model_P.DiscreteTransferFcn_InitialStat;

  // End of SystemInitialize for SubSystem: '<S97>/If Action Subsystem'

  // SystemInitialize for Triggered SubSystem: '<S101>/Triggered Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S103>/1' incorporates:
  //   Outport: '<S103>/baro_0'

  FCS_model_B.u = FCS_model_P.baro_0_Y0;

  // End of SystemInitialize for SubSystem: '<S101>/Triggered Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S66>/Enabled Subsystem'
  // SystemInitialize for Product: '<S91>/Product2' incorporates:
  //   Outport: '<S91>/deltax'

  FCS_model_B.Product2[0] = FCS_model_P.deltax_Y0;
  FCS_model_B.Product2[1] = FCS_model_P.deltax_Y0;
  FCS_model_B.Product2[2] = FCS_model_P.deltax_Y0;
  FCS_model_B.Product2[3] = FCS_model_P.deltax_Y0;

  // End of SystemInitialize for SubSystem: '<S66>/Enabled Subsystem'

  // SystemInitialize for Triggered SubSystem: '<S102>/Triggered Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S104>/position' incorporates:
  //   Outport: '<S104>/Out1'

  FCS_model_B.position[0] = FCS_model_P.Out1_Y0[0];
  FCS_model_B.position[1] = FCS_model_P.Out1_Y0[1];
  FCS_model_B.position[2] = FCS_model_P.Out1_Y0[2];

  // End of SystemInitialize for SubSystem: '<S102>/Triggered Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S60>/MeasurementUpdate'
  // SystemInitialize for Product: '<S89>/Product3' incorporates:
  //   Outport: '<S89>/L*(y[k]-yhat[k|k-1])'

  FCS_model_B.Product3[0] = FCS_model_P.Lykyhatkk1_Y0;
  FCS_model_B.Product3[1] = FCS_model_P.Lykyhatkk1_Y0;
  FCS_model_B.Product3[2] = FCS_model_P.Lykyhatkk1_Y0;
  FCS_model_B.Product3[3] = FCS_model_P.Lykyhatkk1_Y0;

  // End of SystemInitialize for SubSystem: '<S60>/MeasurementUpdate'
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
