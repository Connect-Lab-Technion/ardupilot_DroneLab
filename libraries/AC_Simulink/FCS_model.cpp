//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 5.13
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Apr 11 20:20:02 2024
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

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

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
void FCS_model::step(real32_T arg_accel[3], real32_T arg_gyro[3], real32_T
                     *arg_bat_V, real32_T arg_pos_est[3], real32_T arg_vel_est[3],
                     real32_T *arg_yaw_opticalfow, real32_T arg_pos_ref[3],
                     real32_T arg_orient_ref[3], real32_T arg_motors_refout[4],
                     real32_T arg_logging_refout[20])
{
  // local block i/o variables
  real_T rtb_Sum1_j;
  real_T rtb_Sum1_jt;
  real_T rtb_DataTypeConversion6[3];
  real_T rtb_DataTypeConversion7[3];
  real_T rtb_TrigonometricFunction4;
  real_T Sum;
  real_T rtb_Product3;
  real_T rtb_roll;
  real_T rtb_rollrate;
  int32_T iU;
  real32_T rtb_DataTypeConversion2_i;
  real32_T rtb_DataTypeConversion6_b;
  real32_T rtb_On1Off0forthrust;
  real32_T u0;
  UNUSED_PARAMETER(arg_bat_V);

  // If: '<S40>/If1' incorporates:
  //   Constant: '<S2>/Constant'
  //   DataTypeConversion: '<S40>/Data Type Conversion'

  if (static_cast<real32_T>(FCS_model_P.Constant_Value) > 0.0F) {
    // Outputs for IfAction SubSystem: '<S40>/If Action Subsystem' incorporates:
    //   ActionPort: '<S42>/Action Port'

    // Merge: '<S40>/Merge1' incorporates:
    //   DiscreteTransferFcn: '<S43>/Discrete Transfer Fcn'

    FCS_model_DW.Memory_PreviousInput = FCS_model_P.DiscreteTransferFcn_NumCoef
      [1] * FCS_model_DW.DiscreteTransferFcn_states_n;

    // Update for DiscreteTransferFcn: '<S43>/Discrete Transfer Fcn' incorporates:
    //   DataTypeConversion: '<S4>/Data Type Conversion1'
    //   DataTypeConversion: '<S4>/Data Type Conversion2'
    //   Gain: '<S43>/Gain'
    //   Inport: '<Root>/gyro'
    //   Inport: '<Root>/yaw_opticalfow'
    //   Sum: '<S43>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_n = ((FCS_model_P.w_c_yaw *
      *arg_yaw_opticalfow + arg_gyro[2]) -
      FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_n) /
      FCS_model_P.DiscreteTransferFcn_DenCoef[0];

    // End of Outputs for SubSystem: '<S40>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S40>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S41>/Action Port'

    // Merge: '<S40>/Merge1' incorporates:
    //   DataTypeConversion: '<S4>/Data Type Conversion1'
    //   Gain: '<S41>/Gain'
    //   Inport: '<Root>/gyro'
    //   Memory: '<S2>/Memory'
    //   Sum: '<S41>/Sum'

    FCS_model_DW.Memory_PreviousInput += FCS_model_P.Ts * arg_gyro[2];

    // End of Outputs for SubSystem: '<S40>/If Action Subsystem3'
  }

  // End of If: '<S40>/If1'

  // DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  rtb_roll = FCS_model_P.DiscreteTransferFcn_NumCoef_n[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn'
  rtb_rollrate = FCS_model_P.DiscreteTransferFcn_NumCoef_a[1] *
    FCS_model_DW.DiscreteTransferFcn_states_e;

  // DiscreteStateSpace: '<S12>/Internal'
  {
    rtb_TrigonometricFunction4 = (FCS_model_P.Internal_C[0])*
      FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_C[1])*FCS_model_DW.Internal_DSTATE[1];
  }

  // Trigonometry: '<S39>/Trigonometric Function4' incorporates:
  //   Constant: '<S6>/Constant1'
  //   DataTypeConversion: '<S4>/Data Type Conversion4'
  //   DataTypeConversion: '<S4>/Data Type Conversion5'
  //   Gain: '<S6>/KDz'
  //   Gain: '<S6>/zDz'
  //   Inport: '<Root>/pos_est'
  //   Inport: '<Root>/vel_est'
  //   Sum: '<S6>/Sum1'
  //   Sum: '<S6>/Sum2'
  //   Sum: '<S6>/Sum3'

  rtb_TrigonometricFunction4 -= arg_pos_est[2];
  rtb_TrigonometricFunction4 *= FCS_model_P.zDz;
  rtb_TrigonometricFunction4 -= arg_vel_est[2];
  rtb_TrigonometricFunction4 = -FCS_model_P.Vehicle.Airframe.mass *
    FCS_model_P.g + FCS_model_P.KDz * rtb_TrigonometricFunction4;

  // Saturate: '<S6>/SaturationThrust'
  if (rtb_TrigonometricFunction4 > FCS_model_P.SaturationThrust_UpperSat) {
    rtb_Product3 = FCS_model_P.SaturationThrust_UpperSat;
  } else if (rtb_TrigonometricFunction4 < FCS_model_P.SaturationThrust_LowerSat)
  {
    rtb_Product3 = FCS_model_P.SaturationThrust_LowerSat;
  } else {
    rtb_Product3 = rtb_TrigonometricFunction4;
  }

  // Gain: '<S5>/On=1//Off=0 for thrust' incorporates:
  //   Saturate: '<S6>/SaturationThrust'

  rtb_On1Off0forthrust = FCS_model_P.On1Off0forthrust_Gain *
    static_cast<real32_T>(rtb_Product3);

  // DiscreteStateSpace: '<S32>/Internal'
  {
    rtb_TrigonometricFunction4 = (FCS_model_P.Internal_C_a[0])*
      FCS_model_DW.Internal_DSTATE_h[0]
      + (FCS_model_P.Internal_C_a[1])*FCS_model_DW.Internal_DSTATE_h[1];
  }

  // Trigonometry: '<S39>/Trigonometric Function4' incorporates:
  //   Constant: '<S5>/yaw equilibrium'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   Gain: '<S10>/KDpsi'
  //   Gain: '<S10>/zDpsi'
  //   Gain: '<S5>/Changing of Jzz'
  //   Gain: '<S5>/On=1//Off=1 for yaw'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S10>/Sum1'
  //   Sum: '<S10>/Sum3'
  //   Sum: '<S5>/Sum3'

  rtb_TrigonometricFunction4 = FCS_model_P.zDpsi * 2.0 *
    (rtb_TrigonometricFunction4 - FCS_model_DW.Memory_PreviousInput);
  rtb_TrigonometricFunction4 -= arg_gyro[2];
  rtb_TrigonometricFunction4 = (FCS_model_P.KDpsi * 1.3 *
    rtb_TrigonometricFunction4 * FCS_model_P.ChangingofJzz_Gain +
    FCS_model_P.yawequilibrium_Value) * FCS_model_P.On1Off1foryaw_Gain;

  // DataTypeConversion: '<S5>/Data Type Conversion2'
  rtb_DataTypeConversion2_i = static_cast<real32_T>(rtb_TrigonometricFunction4);

  // DiscreteStateSpace: '<S16>/Internal'
  {
    rtb_TrigonometricFunction4 = (FCS_model_P.Internal_C_i[0])*
      FCS_model_DW.Internal_DSTATE_a[0]
      + (FCS_model_P.Internal_C_i[1])*FCS_model_DW.Internal_DSTATE_a[1];
  }

  // Sum: '<S8>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'

  rtb_Sum1_j = rtb_TrigonometricFunction4 - rtb_roll;

  // DiscreteStateSpace: '<S17>/Internal'
  {
    rtb_TrigonometricFunction4 = FCS_model_P.Internal_C_ai*
      FCS_model_DW.Internal_DSTATE_g;
    rtb_TrigonometricFunction4 += FCS_model_P.Internal_D_e*rtb_Sum1_j;
  }

  // Trigonometry: '<S39>/Trigonometric Function4' incorporates:
  //   Constant: '<S5>/pitch equilibrium'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   Gain: '<S5>/Changing of Jyy'
  //   Gain: '<S5>/On=1//Off=2 for pitch'
  //   Gain: '<S8>/KDtheta'
  //   Gain: '<S8>/zDtheta'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S5>/Sum1'
  //   Sum: '<S8>/Sum3'

  rtb_TrigonometricFunction4 *= FCS_model_P.zDtheta * 7.0;
  rtb_TrigonometricFunction4 -= arg_gyro[1];
  rtb_TrigonometricFunction4 = (FCS_model_P.KDtheta * 1.4 *
    rtb_TrigonometricFunction4 * FCS_model_P.ChangingofJyy_Gain +
    FCS_model_P.pitchequilibrium_Value) * FCS_model_P.On1Off2forpitch_Gain;

  // DataTypeConversion: '<S5>/Data Type Conversion6'
  rtb_DataTypeConversion6_b = static_cast<real32_T>(rtb_TrigonometricFunction4);

  // DiscreteStateSpace: '<S24>/Internal'
  {
    rtb_TrigonometricFunction4 = (FCS_model_P.Internal_C_c[0])*
      FCS_model_DW.Internal_DSTATE_l[0]
      + (FCS_model_P.Internal_C_c[1])*FCS_model_DW.Internal_DSTATE_l[1];
  }

  // Sum: '<S9>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn'

  rtb_Sum1_jt = rtb_TrigonometricFunction4 - rtb_rollrate;

  // DiscreteStateSpace: '<S25>/Internal'
  {
    rtb_TrigonometricFunction4 = FCS_model_P.Internal_C_g*
      FCS_model_DW.Internal_DSTATE_gs;
    rtb_TrigonometricFunction4 += FCS_model_P.Internal_D_h*rtb_Sum1_jt;
  }

  // Trigonometry: '<S39>/Trigonometric Function4' incorporates:
  //   Constant: '<S5>/roll equilibrium'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   Gain: '<S5>/Changing of Jxx'
  //   Gain: '<S5>/On=1//Off=1 for roll'
  //   Gain: '<S9>/KDphi'
  //   Gain: '<S9>/zDphi'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S5>/Sum2'
  //   Sum: '<S9>/Sum3'

  rtb_TrigonometricFunction4 *= FCS_model_P.zDphi * 7.0;
  rtb_TrigonometricFunction4 -= arg_gyro[0];
  rtb_TrigonometricFunction4 = (FCS_model_P.KDphi * 1.4 *
    rtb_TrigonometricFunction4 * FCS_model_P.ChangingofJxx_Gain +
    FCS_model_P.rollequilibrium_Value) * FCS_model_P.On1Off1forroll_Gain;
  for (iU = 0; iU < 4; iU++) {
    // Gain: '<S11>/Gain' incorporates:
    //   Constant: '<S7>/TorqueTotalThrustToThrustPerMotor'
    //   DataTypeConversion: '<S5>/Data Type Conversion1'
    //   Product: '<S7>/Product'
    //   SignalConversion generated from: '<S7>/Product'

    arg_motors_refout[iU] = (((FCS_model_P.TorqueTotalThrustToThrustPerMot[iU +
      4] * rtb_DataTypeConversion2_i +
      FCS_model_P.TorqueTotalThrustToThrustPerMot[iU] * rtb_On1Off0forthrust) +
      FCS_model_P.TorqueTotalThrustToThrustPerMot[iU + 8] *
      rtb_DataTypeConversion6_b) +
      FCS_model_P.TorqueTotalThrustToThrustPerMot[iU + 12] *
      static_cast<real32_T>(rtb_TrigonometricFunction4)) *
      FCS_model_P.Gain_Gain_n;

    // Lookup_n-D: '<S11>/1-D Lookup Table'
    arg_motors_refout[iU] = look1_iflf_binlx(arg_motors_refout[iU],
      FCS_model_P.uDLookupTable_bp01Data, FCS_model_P.uDLookupTable_tableData,
      8U);

    // Saturate: '<S11>/Saturation'
    u0 = arg_motors_refout[iU];
    if (u0 > FCS_model_P.Saturation_UpperSat) {
      arg_motors_refout[iU] = FCS_model_P.Saturation_UpperSat;
    } else if (u0 < FCS_model_P.Saturation_LowerSat) {
      arg_motors_refout[iU] = FCS_model_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S11>/Saturation'
  }

  // Outport: '<Root>/logging_out' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion13'
  //   DataTypeConversion: '<S3>/Data Type Conversion6'
  //   DataTypeConversion: '<S4>/Data Type Conversion'
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   DataTypeConversion: '<S4>/Data Type Conversion4'
  //   DataTypeConversion: '<S4>/Data Type Conversion5'
  //   DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn'
  //   Inport: '<Root>/accel'
  //   Inport: '<Root>/gyro'
  //   Inport: '<Root>/pos_est'
  //   Inport: '<Root>/vel_est'
  //   Inport: '<Root>/yaw_opticalfow'

  arg_logging_refout[0] = static_cast<real32_T>
    (FCS_model_DW.Memory_PreviousInput);
  arg_logging_refout[1] = static_cast<real32_T>(rtb_roll);
  arg_logging_refout[2] = static_cast<real32_T>(rtb_rollrate);
  arg_logging_refout[9] = *arg_yaw_opticalfow;
  arg_logging_refout[3] = arg_accel[0];
  arg_logging_refout[6] = arg_gyro[0];
  arg_logging_refout[10] = arg_pos_est[0];
  arg_logging_refout[13] = arg_vel_est[0];
  arg_logging_refout[4] = arg_accel[1];
  arg_logging_refout[7] = arg_gyro[1];
  arg_logging_refout[11] = arg_pos_est[1];
  arg_logging_refout[14] = arg_vel_est[1];
  arg_logging_refout[5] = arg_accel[2];
  arg_logging_refout[8] = arg_gyro[2];
  arg_logging_refout[12] = arg_pos_est[2];
  arg_logging_refout[15] = arg_vel_est[2];
  arg_logging_refout[16] = arg_motors_refout[0];
  arg_logging_refout[17] = arg_motors_refout[1];
  arg_logging_refout[18] = arg_motors_refout[2];
  arg_logging_refout[19] = arg_motors_refout[3];

  // Trigonometry: '<S39>/Trigonometric Function4' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion'
  //   Gain: '<S38>/Gain1'
  //   Inport: '<Root>/accel'

  rtb_TrigonometricFunction4 = FCS_model_P.Gain1_Gain * arg_accel[0];

  // Product: '<S38>/Divide' incorporates:
  //   Constant: '<S38>/Constant'

  rtb_roll = rtb_TrigonometricFunction4 / FCS_model_P.g;

  // Trigonometry: '<S38>/Trigonometric Function1'
  if (rtb_roll > 1.0) {
    rtb_roll = 1.0;
  } else if (rtb_roll < -1.0) {
    rtb_roll = -1.0;
  }

  // Trigonometry: '<S39>/Trigonometric Function4' incorporates:
  //   Gain: '<S38>/Gain'
  //   Trigonometry: '<S38>/Trigonometric Function1'

  rtb_TrigonometricFunction4 = FCS_model_P.Gain_Gain * std::asin(rtb_roll);

  // Trigonometry: '<S38>/Trigonometric Function' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion'
  //   Gain: '<S38>/Gain2'
  //   Gain: '<S38>/Gain3'
  //   Inport: '<Root>/accel'

  rtb_roll = rt_atan2d_snf(FCS_model_P.Gain2_Gain * arg_accel[1],
    FCS_model_P.Gain3_Gain * arg_accel[2]);

  // Trigonometry: '<S39>/Trigonometric Function2'
  rtb_rollrate = std::sin(rtb_roll);
  rtb_Product3 = std::cos(rtb_roll);

  // Sum: '<S36>/Sum' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   Gain: '<S36>/Gain'
  //   Gain: '<S39>/Gain'
  //   Inport: '<Root>/gyro'
  //   Product: '<S39>/Product4'
  //   Product: '<S39>/Product5'
  //   Sum: '<S39>/Sum1'

  Sum = (FCS_model_P.Gain_Gain_i * rtb_rollrate * arg_gyro[2] + rtb_Product3 *
         arg_gyro[1]) + FCS_model_P.w_c_pitch * rtb_TrigonometricFunction4;

  // Trigonometry: '<S39>/Trigonometric Function4'
  rtb_TrigonometricFunction4 = std::tan(rtb_TrigonometricFunction4);

  // DataTypeConversion: '<S4>/Data Type Conversion6' incorporates:
  //   Inport: '<Root>/pos_ref'

  rtb_DataTypeConversion6[0] = arg_pos_ref[0];

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Inport: '<Root>/orient_ref'

  rtb_DataTypeConversion7[0] = arg_orient_ref[0];

  // DataTypeConversion: '<S4>/Data Type Conversion6' incorporates:
  //   Inport: '<Root>/pos_ref'

  rtb_DataTypeConversion6[1] = arg_pos_ref[1];

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Inport: '<Root>/orient_ref'

  rtb_DataTypeConversion7[1] = arg_orient_ref[1];

  // DataTypeConversion: '<S4>/Data Type Conversion6' incorporates:
  //   Inport: '<Root>/pos_ref'

  rtb_DataTypeConversion6[2] = arg_pos_ref[2];

  // DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
  //   Inport: '<Root>/orient_ref'

  rtb_DataTypeConversion7[2] = arg_orient_ref[2];

  // Update for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states = (Sum -
    FCS_model_P.DiscreteTransferFcn_DenCoef_n[1] *
    FCS_model_DW.DiscreteTransferFcn_states) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_n[0];

  // Update for DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion1'
  //   Gain: '<S37>/Gain'
  //   Inport: '<Root>/gyro'
  //   Product: '<S39>/Product'
  //   Product: '<S39>/Product1'
  //   Product: '<S39>/Product2'
  //   Product: '<S39>/Product3'
  //   Sum: '<S37>/Sum'
  //   Sum: '<S39>/Sum'

  FCS_model_DW.DiscreteTransferFcn_states_e = ((((rtb_rollrate *
    rtb_TrigonometricFunction4 * arg_gyro[1] + arg_gyro[0]) + rtb_Product3 *
    rtb_TrigonometricFunction4 * arg_gyro[2]) + FCS_model_P.w_c_roll * rtb_roll)
    - FCS_model_P.DiscreteTransferFcn_DenCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states_e) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_o[0];

  // Update for DiscreteStateSpace: '<S12>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A[0])*FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_A[1])*FCS_model_DW.Internal_DSTATE[1];
    xnew[0] += FCS_model_P.Internal_B*rtb_DataTypeConversion6[2];
    xnew[1] = (FCS_model_P.Internal_A[2])*FCS_model_DW.Internal_DSTATE[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteStateSpace: '<S32>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_d[0])*FCS_model_DW.Internal_DSTATE_h[0]
      + (FCS_model_P.Internal_A_d[1])*FCS_model_DW.Internal_DSTATE_h[1];
    xnew[0] += FCS_model_P.Internal_B_f*rtb_DataTypeConversion7[0];
    xnew[1] = (FCS_model_P.Internal_A_d[2])*FCS_model_DW.Internal_DSTATE_h[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_h[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteStateSpace: '<S16>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_j[0])*FCS_model_DW.Internal_DSTATE_a[0]
      + (FCS_model_P.Internal_A_j[1])*FCS_model_DW.Internal_DSTATE_a[1];
    xnew[0] += FCS_model_P.Internal_B_k*rtb_DataTypeConversion7[1];
    xnew[1] = (FCS_model_P.Internal_A_j[2])*FCS_model_DW.Internal_DSTATE_a[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_a[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteStateSpace: '<S17>/Internal'
  {
    real_T xnew[1];
    xnew[0] = FCS_model_P.Internal_A_f*FCS_model_DW.Internal_DSTATE_g;
    xnew[0] += FCS_model_P.Internal_B_b*rtb_Sum1_j;
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_g, xnew,
                       sizeof(real_T)*1);
  }

  // Update for DiscreteStateSpace: '<S24>/Internal'
  {
    real_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_a[0])*FCS_model_DW.Internal_DSTATE_l[0]
      + (FCS_model_P.Internal_A_a[1])*FCS_model_DW.Internal_DSTATE_l[1];
    xnew[0] += FCS_model_P.Internal_B_h*rtb_DataTypeConversion7[2];
    xnew[1] = (FCS_model_P.Internal_A_a[2])*FCS_model_DW.Internal_DSTATE_l[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_l[0], xnew,
                       sizeof(real_T)*2);
  }

  // Update for DiscreteStateSpace: '<S25>/Internal'
  {
    real_T xnew[1];
    xnew[0] = FCS_model_P.Internal_A_l*FCS_model_DW.Internal_DSTATE_gs;
    xnew[0] += FCS_model_P.Internal_B_e*rtb_Sum1_jt;
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_gs, xnew,
                       sizeof(real_T)*1);
  }
}

// Model initialize function
void FCS_model::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // InitializeConditions for Merge: '<S40>/Merge1' incorporates:
  //   Memory: '<S2>/Memory'

  FCS_model_DW.Memory_PreviousInput = FCS_model_P.Memory_InitialCondition;

  // InitializeConditions for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states =
    FCS_model_P.DiscreteTransferFcn_InitialSt_c;

  // InitializeConditions for DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_e =
    FCS_model_P.DiscreteTransferFcn_InitialSt_g;

  // InitializeConditions for DiscreteStateSpace: '<S12>/Internal'
  FCS_model_DW.Internal_DSTATE[0] = FCS_model_P.Internal_InitialCondition;
  FCS_model_DW.Internal_DSTATE[1] = FCS_model_P.Internal_InitialCondition;

  // InitializeConditions for DiscreteStateSpace: '<S32>/Internal'
  FCS_model_DW.Internal_DSTATE_h[0] = FCS_model_P.Internal_InitialCondition_p;
  FCS_model_DW.Internal_DSTATE_h[1] = FCS_model_P.Internal_InitialCondition_p;

  // InitializeConditions for DiscreteStateSpace: '<S16>/Internal'
  FCS_model_DW.Internal_DSTATE_a[0] = FCS_model_P.Internal_InitialCondition_ps;
  FCS_model_DW.Internal_DSTATE_a[1] = FCS_model_P.Internal_InitialCondition_ps;

  // InitializeConditions for DiscreteStateSpace: '<S17>/Internal'
  FCS_model_DW.Internal_DSTATE_g = FCS_model_P.Internal_InitialCondition_l;

  // InitializeConditions for DiscreteStateSpace: '<S24>/Internal'
  FCS_model_DW.Internal_DSTATE_l[0] = FCS_model_P.Internal_InitialCondition_c;
  FCS_model_DW.Internal_DSTATE_l[1] = FCS_model_P.Internal_InitialCondition_c;

  // InitializeConditions for DiscreteStateSpace: '<S25>/Internal'
  FCS_model_DW.Internal_DSTATE_gs = FCS_model_P.Internal_InitialCondition_n;

  // SystemInitialize for IfAction SubSystem: '<S40>/If Action Subsystem'
  // InitializeConditions for DiscreteTransferFcn: '<S43>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_n =
    FCS_model_P.DiscreteTransferFcn_InitialStat;

  // End of SystemInitialize for SubSystem: '<S40>/If Action Subsystem'
}

// Model terminate function
void FCS_model::terminate()
{
  // (no terminate code required)
}

// Constructor
FCS_model::FCS_model() :
  FCS_model_DW(),
  FCS_model_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
FCS_model::~FCS_model() = default;

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
