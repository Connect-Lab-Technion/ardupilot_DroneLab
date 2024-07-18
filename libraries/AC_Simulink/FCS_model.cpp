//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 7.24
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Jul 17 11:32:30 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FCS_model.h"
#include "rtwtypes.h"
#include "FCS_model_private.h"
#include <cmath>
#include "rt_defines.h"

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
                     real32_T arg_pos_est[3], real32_T arg_vel_est[3], real32_T *
                     arg_yaw, real32_T arg_pos_ref[3], real32_T arg_orient_ref[3],
                     real32_T arg_motors_refout[4], real32_T arg_logging_refout
                     [36])
{
  // local block i/o variables
  real32_T rtb_Sum1_j;
  real32_T rtb_Sum1_jt;
  real32_T rtb_DataTypeConversion14;
  real_T u0;
  real32_T numAccum;
  real32_T numAccum_0;
  real32_T rtb_DataTypeConversion1;
  real32_T rtb_DataTypeConversion2;
  real32_T rtb_DataTypeConversion6;
  real32_T rtb_On1Off0forthrust;
  real32_T rtb_Product3;
  real32_T rtb_Saturation;
  real32_T rtb_TrigonometricFunction4;
  real32_T rtb_pitchrate;
  real32_T rtb_rollrate;

  // DiscreteStateSpace: '<S12>/Internal' incorporates:
  //   Inport: '<Root>/pos_ref'

  {
    rtb_DataTypeConversion14 = (FCS_model_P.Internal_C[0])*
      FCS_model_DW.Internal_DSTATE[0]
      + (FCS_model_P.Internal_C[1])*FCS_model_DW.Internal_DSTATE[1];
  }

  // DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
  //   Gain: '<S5>/zDz'
  //   Inport: '<Root>/pos_est'
  //   Inport: '<Root>/vel_est'
  //   Sum: '<S5>/Sum1'
  //   Sum: '<S5>/Sum3'

  rtb_DataTypeConversion14 -= arg_pos_est[2];
  rtb_DataTypeConversion14 *= FCS_model_P.zDz;
  rtb_DataTypeConversion14 -= arg_vel_est[2];

  // Sum: '<S5>/Sum2' incorporates:
  //   Constant: '<S5>/Constant1'
  //   Gain: '<S5>/Gain'
  //   Gain: '<S5>/KDz'

  u0 = FCS_model_P.KDz * rtb_DataTypeConversion14 * FCS_model_P.Gain_Gain +
    FCS_model_P.Constant1_Value;

  // Saturate: '<S5>/SaturationThrust'
  if (u0 > FCS_model_P.SaturationThrust_UpperSat) {
    // DataTypeConversion: '<S3>/Data Type Conversion14'
    rtb_DataTypeConversion14 = FCS_model_P.SaturationThrust_UpperSat;
  } else if (u0 < FCS_model_P.SaturationThrust_LowerSat) {
    // DataTypeConversion: '<S3>/Data Type Conversion14'
    rtb_DataTypeConversion14 = FCS_model_P.SaturationThrust_LowerSat;
  } else {
    // DataTypeConversion: '<S3>/Data Type Conversion14'
    rtb_DataTypeConversion14 = static_cast<real32_T>(u0);
  }

  // End of Saturate: '<S5>/SaturationThrust'

  // Gain: '<S1>/On=1//Off=0 for thrust'
  rtb_On1Off0forthrust = FCS_model_P.On1Off0forthrust_Gain *
    rtb_DataTypeConversion14;

  // DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
  //   Constant: '<S2>/Constant'
  //   DataTypeConversion: '<S40>/Data Type Conversion'

  rtb_DataTypeConversion14 = static_cast<real32_T>(FCS_model_P.Constant_Value_a);

  // If: '<S40>/If1'
  if (rtb_DataTypeConversion14 > 0.0F) {
    // Outputs for IfAction SubSystem: '<S40>/If Action Subsystem' incorporates:
    //   ActionPort: '<S42>/Action Port'

    // Merge: '<S40>/Merge1' incorporates:
    //   DiscreteTransferFcn: '<S43>/Discrete Transfer Fcn'

    FCS_model_DW.Memory_PreviousInput = FCS_model_P.DiscreteTransferFcn_NumCoef
      [1] * FCS_model_DW.DiscreteTransferFcn_states_n;

    // Update for DiscreteTransferFcn: '<S43>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S43>/Gain'
    //   Inport: '<Root>/gyro'
    //   Inport: '<Root>/yaw_est'
    //   Sum: '<S43>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_n = ((FCS_model_P.w_c_yaw * *arg_yaw
      + arg_gyro[2]) - FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
      FCS_model_DW.DiscreteTransferFcn_states_n) /
      FCS_model_P.DiscreteTransferFcn_DenCoef[0];

    // End of Outputs for SubSystem: '<S40>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S40>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S41>/Action Port'

    // Merge: '<S40>/Merge1' incorporates:
    //   Gain: '<S41>/Gain'
    //   Inport: '<Root>/gyro'
    //   Memory: '<S2>/Memory'
    //   Sum: '<S41>/Sum'

    FCS_model_DW.Memory_PreviousInput += FCS_model_P.Ts * arg_gyro[2];

    // End of Outputs for SubSystem: '<S40>/If Action Subsystem3'
  }

  // End of If: '<S40>/If1'

  // DiscreteStateSpace: '<S32>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    rtb_DataTypeConversion14 = (FCS_model_P.Internal_C_a[0])*
      FCS_model_DW.Internal_DSTATE_h[0]
      + (FCS_model_P.Internal_C_a[1])*FCS_model_DW.Internal_DSTATE_h[1];
  }

  // DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
  //   Gain: '<S10>/zDpsi'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S10>/Sum1'
  //   Sum: '<S10>/Sum3'

  rtb_DataTypeConversion14 = (rtb_DataTypeConversion14 -
    FCS_model_DW.Memory_PreviousInput) * FCS_model_P.zDpsi_Gain;
  rtb_DataTypeConversion14 -= arg_gyro[2];

  // DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
  //   Constant: '<S1>/yaw equilibrium'
  //   Gain: '<S10>/KDpsi'
  //   Gain: '<S1>/Changing of Jzz'
  //   Gain: '<S1>/On=1//Off=1 for yaw'
  //   Sum: '<S1>/Sum3'

  rtb_DataTypeConversion2 = static_cast<real32_T>((FCS_model_P.KDpsi_Gain *
    rtb_DataTypeConversion14 * FCS_model_P.ChangingofJzz_Gain +
    FCS_model_P.yawequilibrium_Value) * FCS_model_P.On1Off1foryaw_Gain);

  // DiscreteStateSpace: '<S16>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    rtb_DataTypeConversion14 = (FCS_model_P.Internal_C_i[0])*
      FCS_model_DW.Internal_DSTATE_a[0]
      + (FCS_model_P.Internal_C_i[1])*FCS_model_DW.Internal_DSTATE_a[1];
  }

  // DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  numAccum = FCS_model_P.DiscreteTransferFcn_NumCoef_n[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // Sum: '<S7>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'

  rtb_Sum1_j = rtb_DataTypeConversion14 - numAccum;

  // DiscreteStateSpace: '<S17>/Internal'
  {
    rtb_DataTypeConversion14 = FCS_model_P.Internal_C_ai*
      FCS_model_DW.Internal_DSTATE_g;
    rtb_DataTypeConversion14 += FCS_model_P.Internal_D_e*rtb_Sum1_j;
  }

  // DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
  //   Gain: '<S7>/zDtheta'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S7>/Sum3'

  rtb_DataTypeConversion14 *= FCS_model_P.zDtheta_Gain;
  rtb_DataTypeConversion14 -= arg_gyro[1];

  // DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
  //   Constant: '<S1>/pitch equilibrium'
  //   Gain: '<S1>/Changing of Jyy'
  //   Gain: '<S1>/On=1//Off=2 for pitch'
  //   Gain: '<S7>/KDtheta'
  //   Sum: '<S1>/Sum1'

  rtb_DataTypeConversion6 = static_cast<real32_T>((FCS_model_P.KDtheta_Gain *
    rtb_DataTypeConversion14 * FCS_model_P.ChangingofJyy_Gain +
    FCS_model_P.pitchequilibrium_Value) * FCS_model_P.On1Off2forpitch_Gain);

  // DiscreteStateSpace: '<S24>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    rtb_DataTypeConversion14 = (FCS_model_P.Internal_C_c[0])*
      FCS_model_DW.Internal_DSTATE_l[0]
      + (FCS_model_P.Internal_C_c[1])*FCS_model_DW.Internal_DSTATE_l[1];
  }

  // DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn'
  numAccum_0 = FCS_model_P.DiscreteTransferFcn_NumCoef_a[1] *
    FCS_model_DW.DiscreteTransferFcn_states_e;

  // Sum: '<S8>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn'

  rtb_Sum1_jt = rtb_DataTypeConversion14 - numAccum_0;

  // DiscreteStateSpace: '<S25>/Internal'
  {
    rtb_DataTypeConversion14 = FCS_model_P.Internal_C_g*
      FCS_model_DW.Internal_DSTATE_gs;
    rtb_DataTypeConversion14 += FCS_model_P.Internal_D_h*rtb_Sum1_jt;
  }

  // DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
  //   Gain: '<S8>/zDphi'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S8>/Sum3'

  rtb_DataTypeConversion14 *= FCS_model_P.zDphi_Gain;
  rtb_DataTypeConversion14 -= arg_gyro[0];

  // DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
  //   Constant: '<S1>/roll equilibrium'
  //   Gain: '<S1>/Changing of Jxx'
  //   Gain: '<S1>/On=1//Off=1 for roll'
  //   Gain: '<S8>/KDphi'
  //   Sum: '<S1>/Sum2'

  rtb_DataTypeConversion1 = static_cast<real32_T>((FCS_model_P.KDphi_Gain *
    rtb_DataTypeConversion14 * FCS_model_P.ChangingofJxx_Gain +
    FCS_model_P.rollequilibrium_Value) * FCS_model_P.On1Off1forroll_Gain);

  // Switch: '<S9>/Switch' incorporates:
  //   Constant: '<S9>/Constant'
  //   Inport: '<Root>/master_switch'
  //   Product: '<S9>/Product'
  //   Saturate: '<S11>/Saturation'

  if (*arg_switch > FCS_model_P.Switch_Threshold) {
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
      // Lookup_n-D: '<S11>/1-D Lookup Table' incorporates:
      //   Constant: '<S6>/TorqueTotalThrustToThrustPerMotor'
      //   Product: '<S6>/Product'
      //   SignalConversion generated from: '<S6>/Product'

      rtb_rollrate = look1_iflf_binlx
        (((FCS_model_P.TorqueTotalThrustToThrustPerMot[iU + 4] *
           rtb_DataTypeConversion2 +
           FCS_model_P.TorqueTotalThrustToThrustPerMot[iU] *
           rtb_On1Off0forthrust) +
          FCS_model_P.TorqueTotalThrustToThrustPerMot[iU + 8] *
          rtb_DataTypeConversion6) +
         FCS_model_P.TorqueTotalThrustToThrustPerMot[iU + 12] *
         rtb_DataTypeConversion1, FCS_model_P.uDLookupTable_bp01Data,
         FCS_model_P.uDLookupTable_tableData, 9U);

      // Saturate: '<S11>/Saturation'
      if (rtb_rollrate > FCS_model_P.Saturation_UpperSat_e) {
        rtb_rollrate = FCS_model_P.Saturation_UpperSat_e;
      } else if (rtb_rollrate < FCS_model_P.Saturation_LowerSat_j) {
        rtb_rollrate = FCS_model_P.Saturation_LowerSat_j;
      }

      arg_motors_refout[iU] = rtb_Saturation * rtb_rollrate;
    }
  } else {
    arg_motors_refout[0] = static_cast<real32_T>(FCS_model_P.Constant_Value[0]);
    arg_motors_refout[1] = static_cast<real32_T>(FCS_model_P.Constant_Value[1]);
    arg_motors_refout[2] = static_cast<real32_T>(FCS_model_P.Constant_Value[2]);
    arg_motors_refout[3] = static_cast<real32_T>(FCS_model_P.Constant_Value[3]);
  }

  // End of Switch: '<S9>/Switch'

  // DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
  //   DigitalClock: '<S3>/Digital Clock'

  rtb_DataTypeConversion14 = static_cast<real32_T>((((&FCS_model_M)
    ->Timing.clockTick0) * 0.0025));

  // Trigonometry: '<S38>/Trigonometric Function' incorporates:
  //   Gain: '<S38>/Gain2'
  //   Gain: '<S38>/Gain3'
  //   Inport: '<Root>/accel'

  rtb_Saturation = rt_atan2f_snf(FCS_model_P.Gain2_Gain * arg_accel[1],
    FCS_model_P.Gain3_Gain * arg_accel[2]);

  // Trigonometry: '<S39>/Trigonometric Function2'
  rtb_rollrate = std::sin(rtb_Saturation);
  rtb_Product3 = std::cos(rtb_Saturation);

  // Sum: '<S39>/Sum1' incorporates:
  //   Gain: '<S39>/Gain'
  //   Inport: '<Root>/gyro'
  //   Product: '<S39>/Product4'
  //   Product: '<S39>/Product5'

  rtb_pitchrate = FCS_model_P.Gain_Gain_i * rtb_rollrate * arg_gyro[2] +
    rtb_Product3 * arg_gyro[1];

  // Product: '<S38>/Divide' incorporates:
  //   Constant: '<S38>/Constant'
  //   Gain: '<S38>/Gain1'
  //   Inport: '<Root>/accel'

  rtb_TrigonometricFunction4 = FCS_model_P.Gain1_Gain * arg_accel[0] /
    FCS_model_P.Constant_Value_o;

  // Trigonometry: '<S38>/Trigonometric Function1'
  if (rtb_TrigonometricFunction4 > 1.0F) {
    rtb_TrigonometricFunction4 = 1.0F;
  } else if (rtb_TrigonometricFunction4 < -1.0F) {
    rtb_TrigonometricFunction4 = -1.0F;
  }

  rtb_TrigonometricFunction4 = std::asin(rtb_TrigonometricFunction4);

  // End of Trigonometry: '<S38>/Trigonometric Function1'

  // Outport: '<Root>/logging_out' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion'
  //   DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn'
  //   Inport: '<Root>/accel'
  //   Inport: '<Root>/bat_V'
  //   Inport: '<Root>/gyro'
  //   Inport: '<Root>/master_switch'
  //   Inport: '<Root>/orient_ref'
  //   Inport: '<Root>/pos_est'
  //   Inport: '<Root>/pos_ref'
  //   Inport: '<Root>/power gain'
  //   Inport: '<Root>/vel_est'
  //   Inport: '<Root>/yaw_est'

  arg_logging_refout[0] = rtb_DataTypeConversion14;
  arg_logging_refout[1] = FCS_model_DW.Memory_PreviousInput;
  arg_logging_refout[2] = numAccum;
  arg_logging_refout[3] = numAccum_0;
  arg_logging_refout[10] = *arg_bat_V;
  arg_logging_refout[4] = arg_accel[0];
  arg_logging_refout[7] = arg_gyro[0];
  arg_logging_refout[11] = arg_pos_est[0];
  arg_logging_refout[14] = arg_vel_est[0];
  arg_logging_refout[5] = arg_accel[1];
  arg_logging_refout[8] = arg_gyro[1];
  arg_logging_refout[12] = arg_pos_est[1];
  arg_logging_refout[15] = arg_vel_est[1];
  arg_logging_refout[6] = arg_accel[2];
  arg_logging_refout[9] = arg_gyro[2];
  arg_logging_refout[13] = arg_pos_est[2];
  arg_logging_refout[16] = arg_vel_est[2];
  arg_logging_refout[17] = *arg_yaw;
  arg_logging_refout[18] = arg_motors_refout[0];
  arg_logging_refout[19] = arg_motors_refout[1];
  arg_logging_refout[20] = arg_motors_refout[2];
  arg_logging_refout[21] = arg_motors_refout[3];
  arg_logging_refout[22] = *arg_switch;
  arg_logging_refout[23] = *arg_gain;
  arg_logging_refout[24] = arg_pos_ref[0];
  arg_logging_refout[27] = arg_orient_ref[0];
  arg_logging_refout[25] = arg_pos_ref[1];
  arg_logging_refout[28] = arg_orient_ref[1];
  arg_logging_refout[26] = arg_pos_ref[2];
  arg_logging_refout[29] = arg_orient_ref[2];
  arg_logging_refout[30] = rtb_pitchrate;
  arg_logging_refout[31] = rtb_TrigonometricFunction4;
  arg_logging_refout[32] = rtb_DataTypeConversion6;
  arg_logging_refout[33] = rtb_DataTypeConversion1;
  arg_logging_refout[34] = rtb_DataTypeConversion2;
  arg_logging_refout[35] = rtb_On1Off0forthrust;

  // Sum: '<S36>/Sum' incorporates:
  //   Gain: '<S36>/Gain'

  rtb_On1Off0forthrust = FCS_model_P.w_c_pitch * rtb_TrigonometricFunction4 +
    rtb_pitchrate;

  // Trigonometry: '<S39>/Trigonometric Function4'
  rtb_TrigonometricFunction4 = std::tan(rtb_TrigonometricFunction4);

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

  // Update for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states = (rtb_On1Off0forthrust -
    FCS_model_P.DiscreteTransferFcn_DenCoef_n[1] *
    FCS_model_DW.DiscreteTransferFcn_states) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_n[0];

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

  // Update for DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' incorporates:
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
    rtb_TrigonometricFunction4 * arg_gyro[2]) + FCS_model_P.w_c_roll *
    rtb_Saturation) - FCS_model_P.DiscreteTransferFcn_DenCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states_e) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_o[0];

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

  // InitializeConditions for Merge: '<S40>/Merge1' incorporates:
  //   Memory: '<S2>/Memory'

  FCS_model_DW.Memory_PreviousInput = FCS_model_P.Memory_InitialCondition;

  // InitializeConditions for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states =
    FCS_model_P.DiscreteTransferFcn_InitialSt_c;

  // InitializeConditions for DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_e =
    FCS_model_P.DiscreteTransferFcn_InitialSt_g;

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
