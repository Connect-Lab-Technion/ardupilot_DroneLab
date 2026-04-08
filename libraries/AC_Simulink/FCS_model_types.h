//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_types.h
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
#ifndef FCS_model_types_h_
#define FCS_model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_in_dashboard_
#define DEFINED_TYPEDEF_FOR_in_dashboard_

struct in_dashboard
{
  real_T time_world;
  boolean_T master_switch;
  real_T power;
  boolean_T estimators_reset;
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

#ifndef DEFINED_TYPEDEF_FOR_out_sensors_
#define DEFINED_TYPEDEF_FOR_out_sensors_

struct out_sensors
{
  real_T clock;
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
#endif                                 // FCS_model_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
