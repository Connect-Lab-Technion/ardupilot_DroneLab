#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"

//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model.cpp
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 1.13
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Feb 28 09:56:40 2024
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

extern "C"
{

#include "rt_nonfinite.h"

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
void FCS_model::step(real32_T arg_accel[3], real32_T arg_gyro[3], real32_T
                     *arg_bat_V, real32_T arg_pos_est[3], real32_T arg_vel_est[3],
                     real32_T *arg_yaw_opticalfow, real32_T arg_pos_ref[3],
                     real32_T arg_orient_ref[3], real32_T arg_Out1[4])
{
  // local block i/o variables
  real_T rtb_Sum1;
  real_T rtb_Sum1_j;
  real_T rtb_rollrate;
  real_T rtb_Product3;
  real32_T rtb_TrigonometricFunction2_o1;
  real32_T rtb_roll;
  real32_T rtb_TrigonometricFunction2_o2;
  real_T Sum;
  real_T rtb_Product2;
  real32_T rtb_uThrustoff;
  UNUSED_PARAMETER(arg_bat_V);

  // DiscreteStateSpace: '<S11>/Internal' incorporates:
  //   Inport: '<Root>/pos_ref'

  {
    rtb_TrigonometricFunction2_o2 = (FCS_model_P.Internal_C_n[0])*
      FCS_model_DW.Internal_DSTATE_m[0]
      + (FCS_model_P.Internal_C_n[1])*FCS_model_DW.Internal_DSTATE_m[1];
  }

  // Trigonometry: '<S38>/Trigonometric Function2' incorporates:
  //   Gain: '<S5>/zDz'
  //   Inport: '<Root>/pos_est'
  //   Inport: '<Root>/vel_est'
  //   Sum: '<S5>/Sum1'
  //   Sum: '<S5>/Sum3'

  rtb_TrigonometricFunction2_o2 -= arg_pos_est[2];
  rtb_TrigonometricFunction2_o2 *= FCS_model_P.zDz;
  rtb_TrigonometricFunction2_o2 -= arg_vel_est[2];

  // Sum: '<S38>/Sum' incorporates:
  //   Constant: '<S5>/Constant'
  //   Gain: '<S5>/KDz'
  //   Sum: '<S5>/Sum2'

  rtb_rollrate = -FCS_model_P.Vehicle.Airframe.mass * FCS_model_P.g +
    FCS_model_P.KDz * rtb_TrigonometricFunction2_o2;

  // Saturate: '<S5>/SaturationThrust'
  if (rtb_rollrate > FCS_model_P.SaturationThrust_UpperSat) {
    // Trigonometry: '<S38>/Trigonometric Function2'
    rtb_TrigonometricFunction2_o2 = FCS_model_P.SaturationThrust_UpperSat;
  } else if (rtb_rollrate < FCS_model_P.SaturationThrust_LowerSat) {
    // Trigonometry: '<S38>/Trigonometric Function2'
    rtb_TrigonometricFunction2_o2 = FCS_model_P.SaturationThrust_LowerSat;
  } else {
    // Trigonometry: '<S38>/Trigonometric Function2'
    rtb_TrigonometricFunction2_o2 = static_cast<real32_T>(rtb_rollrate);
  }

  // End of Saturate: '<S5>/SaturationThrust'

  // Gain: '<S4>/0 = Thrust off' incorporates:
  //   Gain: '<S4>/On=1//Off=0 for thrust'

  rtb_uThrustoff = FCS_model_P.On1Off0forthrust_Gain *
    rtb_TrigonometricFunction2_o2 * FCS_model_P.uThrustoff_Gain;

  // Trigonometry: '<S38>/Trigonometric Function2' incorporates:
  //   Constant: '<S2>/Constant'
  //   DataTypeConversion: '<S39>/Data Type Conversion'

  rtb_TrigonometricFunction2_o2 = static_cast<real32_T>
    (FCS_model_P.Constant_Value);

  // If: '<S39>/If1'
  if (rtb_TrigonometricFunction2_o2 > 0.0F) {
    // Outputs for IfAction SubSystem: '<S39>/If Action Subsystem' incorporates:
    //   ActionPort: '<S41>/Action Port'

    // Merge: '<S39>/Merge1' incorporates:
    //   DiscreteTransferFcn: '<S42>/Discrete Transfer Fcn'

    FCS_model_DW.Memory_PreviousInput =
      FCS_model_P.DiscreteTransferFcn_NumCoef_j[1] *
      FCS_model_DW.DiscreteTransferFcn_states_n;

    // Update for DiscreteTransferFcn: '<S42>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<S42>/Gain'
    //   Inport: '<Root>/gyro'
    //   Inport: '<Root>/yaw_opticalfow'
    //   Sum: '<S42>/Sum'

    FCS_model_DW.DiscreteTransferFcn_states_n = ((FCS_model_P.w_c_yaw *
      *arg_yaw_opticalfow + arg_gyro[2]) -
      FCS_model_P.DiscreteTransferFcn_DenCoef_a[1] *
      FCS_model_DW.DiscreteTransferFcn_states_n) /
      FCS_model_P.DiscreteTransferFcn_DenCoef_a[0];

    // End of Outputs for SubSystem: '<S39>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S39>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S40>/Action Port'

    // Merge: '<S39>/Merge1' incorporates:
    //   Gain: '<S40>/Gain'
    //   Inport: '<Root>/gyro'
    //   Memory: '<S2>/Memory'
    //   Sum: '<S40>/Sum'

    FCS_model_DW.Memory_PreviousInput += FCS_model_P.Ts * arg_gyro[2];

    // End of Outputs for SubSystem: '<S39>/If Action Subsystem3'
  }

  // End of If: '<S39>/If1'

  // DiscreteStateSpace: '<S31>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    rtb_TrigonometricFunction2_o2 = (FCS_model_P.Internal_C_a[0])*
      FCS_model_DW.Internal_DSTATE_h[0]
      + (FCS_model_P.Internal_C_a[1])*FCS_model_DW.Internal_DSTATE_h[1];
  }

  // Trigonometry: '<S38>/Trigonometric Function2' incorporates:
  //   Gain: '<S9>/zDpsi'
  //   Inport: '<Root>/gyro'
  //   Sum: '<S9>/Sum1'
  //   Sum: '<S9>/Sum3'

  rtb_TrigonometricFunction2_o2 = (rtb_TrigonometricFunction2_o2 -
    FCS_model_DW.Memory_PreviousInput) * FCS_model_P.zDpsi_Gain;
  rtb_TrigonometricFunction2_o2 -= arg_gyro[2];

  // Sum: '<S38>/Sum' incorporates:
  //   Constant: '<S4>/yaw equilibrium'
  //   Gain: '<S4>/Changing of Jzz'
  //   Gain: '<S4>/On=1//Off=1 for yaw'
  //   Gain: '<S9>/KDpsi'
  //   Sum: '<S4>/Sum3'

  rtb_rollrate = (FCS_model_P.KDpsi_Gain * rtb_TrigonometricFunction2_o2 *
                  FCS_model_P.ChangingofJzz_Gain +
                  FCS_model_P.yawequilibrium_Value) *
    FCS_model_P.On1Off1foryaw_Gain;

  // Trigonometry: '<S38>/Trigonometric Function2' incorporates:
  //   DataTypeConversion: '<S4>/Cast To Single3'

  rtb_TrigonometricFunction2_o2 = static_cast<real32_T>(rtb_rollrate);

  // DiscreteStateSpace: '<S15>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    rtb_TrigonometricFunction2_o1 = (FCS_model_P.Internal_C_i[0])*
      FCS_model_DW.Internal_DSTATE_a[0]
      + (FCS_model_P.Internal_C_i[1])*FCS_model_DW.Internal_DSTATE_a[1];
  }

  // Sum: '<S38>/Sum' incorporates:
  //   DiscreteTransferFcn: '<S35>/Discrete Transfer Fcn'

  rtb_rollrate = FCS_model_P.DiscreteTransferFcn_NumCoef[1] *
    FCS_model_DW.DiscreteTransferFcn_states;

  // Sum: '<S7>/Sum1'
  rtb_Sum1 = rtb_TrigonometricFunction2_o1 - rtb_rollrate;

  // DiscreteStateSpace: '<S16>/Internal'
  {
    rtb_rollrate = FCS_model_P.Internal_C*FCS_model_DW.Internal_DSTATE;
    rtb_rollrate += FCS_model_P.Internal_D*rtb_Sum1;
  }

  // Sum: '<S38>/Sum' incorporates:
  //   Gain: '<S7>/zDtheta'

  rtb_rollrate *= FCS_model_P.zDtheta * 7.0;

  // Trigonometry: '<S37>/Trigonometric Function1' incorporates:
  //   Constant: '<S4>/pitch equilibrium'
  //   Gain: '<S4>/Changing of Jyy'
  //   Gain: '<S4>/On=1//Off=2 for pitch'
  //   Gain: '<S7>/KDtheta'
  //   Inport: '<Root>/gyro'
  //   Product: '<S38>/Product3'
  //   Sum: '<S4>/Sum1'
  //   Sum: '<S7>/Sum3'

  rtb_Product3 = rtb_rollrate - arg_gyro[1];
  rtb_Product3 = (FCS_model_P.KDtheta * 1.4 * rtb_Product3 *
                  FCS_model_P.ChangingofJyy_Gain +
                  FCS_model_P.pitchequilibrium_Value) *
    FCS_model_P.On1Off2forpitch_Gain;

  // Trigonometry: '<S38>/Trigonometric Function2' incorporates:
  //   DataTypeConversion: '<S4>/Cast To Single4'

  rtb_TrigonometricFunction2_o1 = static_cast<real32_T>(rtb_Product3);

  // DiscreteStateSpace: '<S23>/Internal' incorporates:
  //   Inport: '<Root>/orient_ref'

  {
    rtb_roll = (FCS_model_P.Internal_C_c[0])*FCS_model_DW.Internal_DSTATE_l[0]
      + (FCS_model_P.Internal_C_c[1])*FCS_model_DW.Internal_DSTATE_l[1];
  }

  // Trigonometry: '<S37>/Trigonometric Function1' incorporates:
  //   DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  //   Product: '<S38>/Product3'

  rtb_Product3 = FCS_model_P.DiscreteTransferFcn_NumCoef_a[1] *
    FCS_model_DW.DiscreteTransferFcn_states_e;

  // Sum: '<S8>/Sum1'
  rtb_Sum1_j = rtb_roll - rtb_Product3;

  // DiscreteStateSpace: '<S24>/Internal'
  {
    rtb_Product3 = FCS_model_P.Internal_C_g*FCS_model_DW.Internal_DSTATE_g;
    rtb_Product3 += FCS_model_P.Internal_D_h*rtb_Sum1_j;
  }

  // Trigonometry: '<S37>/Trigonometric Function1' incorporates:
  //   Gain: '<S8>/zDphi'
  //   Product: '<S38>/Product3'

  rtb_Product3 *= FCS_model_P.zDphi * 7.0;

  // Sum: '<S38>/Sum' incorporates:
  //   Inport: '<Root>/gyro'
  //   Sum: '<S8>/Sum3'

  rtb_rollrate = rtb_Product3 - arg_gyro[0];

  // Trigonometry: '<S37>/Trigonometric Function1' incorporates:
  //   Constant: '<S4>/roll equilibrium'
  //   Gain: '<S4>/Changing of Jxx'
  //   Gain: '<S4>/On=1//Off=1 for roll'
  //   Gain: '<S8>/KDphi'
  //   Product: '<S38>/Product3'
  //   Sum: '<S4>/Sum2'

  rtb_Product3 = (FCS_model_P.KDphi * 1.4 * rtb_rollrate *
                  FCS_model_P.ChangingofJxx_Gain +
                  FCS_model_P.rollequilibrium_Value) *
    FCS_model_P.On1Off1forroll_Gain;

  // Trigonometry: '<S37>/Trigonometric Function' incorporates:
  //   DataTypeConversion: '<S4>/Cast To Single1'

  rtb_roll = static_cast<real32_T>(rtb_Product3);
  for (int32_T i{0}; i < 4; i++) {
    real32_T u0;

    // Saturate: '<S10>/Saturation5' incorporates:
    //   Constant: '<S6>/TorqueTotalThrustToThrustPerMotor'
    //   Gain: '<S10>/ThrustToMotorCommand'
    //   Product: '<S6>/Product'
    //   SignalConversion generated from: '<S6>/Product'

    u0 = (((FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 4] *
            rtb_TrigonometricFunction2_o2 +
            FCS_model_P.TorqueTotalThrustToThrustPerMot[i] * rtb_uThrustoff) +
           FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 8] *
           rtb_TrigonometricFunction2_o1) +
          FCS_model_P.TorqueTotalThrustToThrustPerMot[i + 12] * rtb_roll) *
      FCS_model_P.ThrustToMotorCommand_Gain;
    if (u0 > FCS_model_P.Saturation5_UpperSat) {
      u0 = FCS_model_P.Saturation5_UpperSat;
    } else if (u0 < FCS_model_P.Saturation5_LowerSat) {
      u0 = FCS_model_P.Saturation5_LowerSat;
    }

    // Outport: '<Root>/motors_refout' incorporates:
    //   Gain: '<S10>/MotorDirections'
    //   Saturate: '<S10>/Saturation5'

    arg_Out1[i] = FCS_model_P.MotorDirections_Gain[i] * u0;
  }

  // Trigonometry: '<S37>/Trigonometric Function' incorporates:
  //   Gain: '<S37>/Gain1'
  //   Inport: '<Root>/accel'

  rtb_roll = FCS_model_P.Gain1_Gain * arg_accel[0];

  // Trigonometry: '<S37>/Trigonometric Function1' incorporates:
  //   Constant: '<S37>/Constant'
  //   Gain: '<S37>/Gain'
  //   Product: '<S37>/Divide'
  //   Product: '<S38>/Product3'

  rtb_Product3 = rtb_roll / FCS_model_P.g;
  if (rtb_Product3 > 1.0) {
    rtb_Product3 = 1.0;
  } else if (rtb_Product3 < -1.0) {
    rtb_Product3 = -1.0;
  }

  rtb_Product3 = FCS_model_P.Gain_Gain * std::asin(rtb_Product3);

  // Trigonometry: '<S37>/Trigonometric Function' incorporates:
  //   Gain: '<S37>/Gain2'
  //   Inport: '<Root>/accel'

  rtb_roll = FCS_model_P.Gain2_Gain * arg_accel[1];

  // Trigonometry: '<S38>/Trigonometric Function2' incorporates:
  //   Gain: '<S37>/Gain3'
  //   Inport: '<Root>/accel'

  rtb_TrigonometricFunction2_o1 = FCS_model_P.Gain3_Gain * arg_accel[2];

  // Trigonometry: '<S37>/Trigonometric Function'
  rtb_roll = rt_atan2f_snf(rtb_roll, rtb_TrigonometricFunction2_o1);

  // Trigonometry: '<S38>/Trigonometric Function2'
  rtb_TrigonometricFunction2_o1 = std::sin(rtb_roll);

  // Trigonometry: '<S38>/Trigonometric Function2'
  rtb_TrigonometricFunction2_o2 = std::cos(rtb_roll);

  // Sum: '<S35>/Sum' incorporates:
  //   Gain: '<S35>/Gain'
  //   Gain: '<S38>/Gain'
  //   Inport: '<Root>/gyro'
  //   Product: '<S38>/Product4'
  //   Product: '<S38>/Product5'
  //   Sum: '<S38>/Sum1'

  Sum = (FCS_model_P.Gain_Gain_i * rtb_TrigonometricFunction2_o1 * arg_gyro[2] +
         rtb_TrigonometricFunction2_o2 * arg_gyro[1]) + FCS_model_P.w_c_pitch *
    rtb_Product3;

  // Trigonometry: '<S37>/Trigonometric Function1' incorporates:
  //   Product: '<S38>/Product3'
  //   Trigonometry: '<S38>/Trigonometric Function4'

  rtb_Product3 = std::tan(rtb_Product3);

  // Sum: '<S38>/Sum' incorporates:
  //   Product: '<S38>/Product'

  rtb_rollrate = rtb_TrigonometricFunction2_o1 * rtb_Product3;

  // Product: '<S38>/Product2' incorporates:
  //   Inport: '<Root>/gyro'

  rtb_Product2 = rtb_rollrate * arg_gyro[1];

  // Sum: '<S38>/Sum' incorporates:
  //   Product: '<S38>/Product1'

  rtb_rollrate = rtb_TrigonometricFunction2_o2 * rtb_Product3;

  // Trigonometry: '<S37>/Trigonometric Function1' incorporates:
  //   Inport: '<Root>/gyro'
  //   Product: '<S38>/Product3'

  rtb_Product3 = rtb_rollrate * arg_gyro[2];

  // Sum: '<S38>/Sum' incorporates:
  //   Inport: '<Root>/gyro'

  rtb_rollrate = (arg_gyro[0] + rtb_Product2) + rtb_Product3;

  // Sum: '<S36>/Sum' incorporates:
  //   Gain: '<S36>/Gain'

  rtb_Product2 = FCS_model_P.w_c_roll * rtb_roll + rtb_rollrate;

  // Update for DiscreteStateSpace: '<S11>/Internal' incorporates:
  //   Inport: '<Root>/pos_ref'

  {
    real32_T xnew[2];
    xnew[0] = (FCS_model_P.Internal_A_n[0])*FCS_model_DW.Internal_DSTATE_m[0]
      + (FCS_model_P.Internal_A_n[1])*FCS_model_DW.Internal_DSTATE_m[1];
    xnew[0] += FCS_model_P.Internal_B_c*arg_pos_ref[2];
    xnew[1] = (FCS_model_P.Internal_A_n[2])*FCS_model_DW.Internal_DSTATE_m[0];
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_m[0], xnew,
                       sizeof(real32_T)*2);
  }

  // Update for DiscreteStateSpace: '<S31>/Internal' incorporates:
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

  // Update for DiscreteStateSpace: '<S15>/Internal' incorporates:
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

  // Update for DiscreteTransferFcn: '<S35>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states = (Sum -
    FCS_model_P.DiscreteTransferFcn_DenCoef[1] *
    FCS_model_DW.DiscreteTransferFcn_states) /
    FCS_model_P.DiscreteTransferFcn_DenCoef[0];

  // Update for DiscreteStateSpace: '<S16>/Internal'
  {
    real_T xnew[1];
    xnew[0] = FCS_model_P.Internal_A*FCS_model_DW.Internal_DSTATE;
    xnew[0] += FCS_model_P.Internal_B*rtb_Sum1;
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE, xnew,
                       sizeof(real_T)*1);
  }

  // Update for DiscreteStateSpace: '<S23>/Internal' incorporates:
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

  // Update for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  FCS_model_DW.DiscreteTransferFcn_states_e = (rtb_Product2 -
    FCS_model_P.DiscreteTransferFcn_DenCoef_o[1] *
    FCS_model_DW.DiscreteTransferFcn_states_e) /
    FCS_model_P.DiscreteTransferFcn_DenCoef_o[0];

  // Update for DiscreteStateSpace: '<S24>/Internal'
  {
    real_T xnew[1];
    xnew[0] = FCS_model_P.Internal_A_l*FCS_model_DW.Internal_DSTATE_g;
    xnew[0] += FCS_model_P.Internal_B_e*rtb_Sum1_j;
    (void) std::memcpy(&FCS_model_DW.Internal_DSTATE_g, xnew,
                       sizeof(real_T)*1);
  }
}

// Model initialize function
void FCS_model::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // InitializeConditions for Merge: '<S39>/Merge1' incorporates:
  //   Memory: '<S2>/Memory'

  FCS_model_DW.Memory_PreviousInput = FCS_model_P.Memory_InitialCondition;

  // InitializeConditions for DiscreteTransferFcn: '<S35>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states =
    FCS_model_P.DiscreteTransferFcn_InitialStat;

  // InitializeConditions for DiscreteStateSpace: '<S16>/Internal'
  FCS_model_DW.Internal_DSTATE = FCS_model_P.Internal_InitialCondition;

  // InitializeConditions for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_e =
    FCS_model_P.DiscreteTransferFcn_InitialSt_g;

  // InitializeConditions for DiscreteStateSpace: '<S24>/Internal'
  FCS_model_DW.Internal_DSTATE_g = FCS_model_P.Internal_InitialCondition_n;

  // SystemInitialize for IfAction SubSystem: '<S39>/If Action Subsystem'
  // InitializeConditions for DiscreteTransferFcn: '<S42>/Discrete Transfer Fcn' 
  FCS_model_DW.DiscreteTransferFcn_states_n =
    FCS_model_P.DiscreteTransferFcn_InitialSt_a;

  // End of SystemInitialize for SubSystem: '<S39>/If Action Subsystem'
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
#pragma GCC diagnostic pop
