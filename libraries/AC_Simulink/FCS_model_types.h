//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_types.h
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
#ifndef RTW_HEADER_FCS_model_types_h_
#define RTW_HEADER_FCS_model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_in_dashboard_
#define DEFINED_TYPEDEF_FOR_in_dashboard_

struct in_dashboard
{
  real_T time_world;
  boolean_T master_switch;
  real_T power;
  real_T ref_x;
  real_T ref_y;
  real_T ref_z;
  real_T ref_yaw;
  real_T ref_pitch;
  real_T ref_roll;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_in_parameters_
#define DEFINED_TYPEDEF_FOR_in_parameters_

struct in_parameters
{
  real_T accelerometer_x;
  real_T accelerometer_y;
  real_T accelerometer_z;
  real_T gyroscope_x;
  real_T gyroscope_y;
  real_T gyroscope_z;
  real_T opticalflow_x;
  real_T opticalflow_y;
  real_T barometer_pressure;
  real_T rangefinder_distance;
  real_T rpm_1;
  real_T rpm_2;
  real_T rpm_3;
  real_T rpm_4;
  real_T battery_voltage;
  real_T battery_current;
  real_T yaw;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_out_controllers_
#define DEFINED_TYPEDEF_FOR_out_controllers_

struct out_controllers
{
  real_T motor1;
  real_T motor2;
  real_T motor3;
  real_T motor4;
  real_T cmd_thrust;
  real_T cmd_tau_roll;
  real_T cmd_tau_pitch;
  real_T cmd_tau_yaw;
  real_T cmd_roll;
  real_T cmd_pitch;
  real_T cmd_yaw;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_out_estimators_
#define DEFINED_TYPEDEF_FOR_out_estimators_

struct out_estimators
{
  real_T orient_roll;
  real_T orient_pitch;
  real_T orient_yaw;
  real_T orient_rate_roll;
  real_T orient_rate_pitch;
  real_T orient_rate_yaw;
  real_T pos_x;
  real_T pos_y;
  real_T pos_z;
  real_T pos_dx;
  real_T pos_dy;
  real_T pos_dz;
  real_T battery_SOC;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_out_sensors_
#define DEFINED_TYPEDEF_FOR_out_sensors_

struct out_sensors
{
  real_T accelerometer_x;
  real_T accelerometer_y;
  real_T accelerometer_z;
  real_T gyroscope_x;
  real_T gyroscope_y;
  real_T gyroscope_z;
  real_T barometer_pressure;
  real_T rangefinder_distance;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_XRMsui9C07VjBvdq1msujB_
#define DEFINED_TYPEDEF_FOR_struct_XRMsui9C07VjBvdq1msujB_

struct struct_XRMsui9C07VjBvdq1msujB
{
  real_T initGreenwich;
  real_T quatGain;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_hxsmtt0xTZOLDNa2Rz7GAF_
#define DEFINED_TYPEDEF_FOR_struct_hxsmtt0xTZOLDNa2Rz7GAF_

struct struct_hxsmtt0xTZOLDNa2Rz7GAF
{
  real_T xAxis;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_IZWOW0zYvpphl7qLgSfN7E_
#define DEFINED_TYPEDEF_FOR_struct_IZWOW0zYvpphl7qLgSfN7E_

struct struct_IZWOW0zYvpphl7qLgSfN7E
{
  real_T href;
  struct_hxsmtt0xTZOLDNa2Rz7GAF FlatEarthToLLA;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_q6UUpnZ4gTjFvULFx6Rxa_
#define DEFINED_TYPEDEF_FOR_struct_q6UUpnZ4gTjFvULFx6Rxa_

struct struct_q6UUpnZ4gTjFvULFx6Rxa
{
  real_T mass;
  real_T inertia[9];
  real_T d;
  real_T xy;
  real_T h;
  real_T Cdx;
  real_T Cdy;
  real_T diameter;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ZLGUjpQoSaF3clY8kuu5dG_
#define DEFINED_TYPEDEF_FOR_struct_ZLGUjpQoSaF3clY8kuu5dG_

struct struct_ZLGUjpQoSaF3clY8kuu5dG
{
  real_T w2ToGramsGain;
  real_T w2ToThrustGain_data;
  real_T blades;
  real_T radius;
  real_T area;
  real_T chord;
  real_T flappingOffset;
  real_T bladeMass;
  real_T bladeInertia;
  real_T hubMass;
  real_T hubInertia;
  real_T inertia;
  real_T Ct;
  real_T Cq;
  real_T solidity;
  real_T theta0;
  real_T thetaTip;
  real_T theta1;
  real_T theta34;
  real_T a;
  real_T lock;
  real_T b;
  real_T k;
  real_T w2ToThrustGain;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_wXJeleBYpauyyNtqoXA8RF_
#define DEFINED_TYPEDEF_FOR_struct_wXJeleBYpauyyNtqoXA8RF_

struct struct_wXJeleBYpauyyNtqoXA8RF
{
  real_T maxLimit;
  real_T minLimit;
  real_T commandToW2Gain;
  real_T commandToW2Offset;
  real_T gramsToMotorCommand;
  real_T thrustToMotorCommand;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_UHvAqkoSM4a4grTGLmN7a_
#define DEFINED_TYPEDEF_FOR_struct_UHvAqkoSM4a4grTGLmN7a_

struct struct_UHvAqkoSM4a4grTGLmN7a
{
  struct_XRMsui9C07VjBvdq1msujB SixDOF;
  struct_IZWOW0zYvpphl7qLgSfN7E PositionOnEarth;
  struct_q6UUpnZ4gTjFvULFx6Rxa Airframe;
  struct_ZLGUjpQoSaF3clY8kuu5dG Rotor;
  struct_wXJeleBYpauyyNtqoXA8RF Motor;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_sfjjhK32Dt7MmV2O18UsO_
#define DEFINED_TYPEDEF_FOR_struct_sfjjhK32Dt7MmV2O18UsO_

struct struct_sfjjhK32Dt7MmV2O18UsO
{
  real_T Ts2Q[16];
  real_T Q2Ts[16];
  real_T totalThrustMaxRelative;
  real_T motorsThrustPerMotorMax;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_eF5OUT33sX0T9pzS8027m_
#define DEFINED_TYPEDEF_FOR_struct_eF5OUT33sX0T9pzS8027m_

struct struct_eF5OUT33sX0T9pzS8027m
{
  real_T cg[3];
  real_T location[3];
  real_T accNatFreq;
  real_T accDamping;
  real_T accScaleCross[9];
  real_T accBias[3];
  real_T accLimits[6];
  real_T gyroNatFreq;
  real_T gyroDamping;
  real_T gyroScaleCross[9];
  real_T gyroBias[3];
  real_T gyroGBias[3];
  real_T gyroLimits[6];
  real_T noiseSeeds[6];
  real_T noiseWeights[6];
  real_T noisePower[6];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_FIfaVnupBjYAxo1EdNiDlF_
#define DEFINED_TYPEDEF_FOR_struct_FIfaVnupBjYAxo1EdNiDlF_

struct struct_FIfaVnupBjYAxo1EdNiDlF
{
  real_T noisePower;
  real_T noiseSeeds;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_eFnp8sKFNJLN84XLbLzaFF_
#define DEFINED_TYPEDEF_FOR_struct_eFnp8sKFNJLN84XLbLzaFF_

struct struct_eFnp8sKFNJLN84XLbLzaFF
{
  real_T posVISNoVisionAvail[4];
  real_T usePosVISFlag;
  real_T batteryStatus[2];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_pAcs5k38eV6MpgiqrKAV4_
#define DEFINED_TYPEDEF_FOR_struct_pAcs5k38eV6MpgiqrKAV4_

struct struct_pAcs5k38eV6MpgiqrKAV4
{
  real_T IMUAccelGain[3];
  real_T IMUGyroGain[3];
  struct_eF5OUT33sX0T9pzS8027m IMU;
  struct_FIfaVnupBjYAxo1EdNiDlF Sonar;
  real_T NO_VIS_X;
  real_T NO_VIS_YAW;
  struct_eFnp8sKFNJLN84XLbLzaFF dummy;
  real_T sensorDelay;
  real_T airDensity;
  real_T altToPrsGain;
  real_T altToPrsBias;
  real_T inverseIMUGain[6];
  real_T altSensorMin;
  real_T velocityToOpticalFlowGain;
  real_T cameraResolution[2];
};

#endif
#endif                                 // RTW_HEADER_FCS_model_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
