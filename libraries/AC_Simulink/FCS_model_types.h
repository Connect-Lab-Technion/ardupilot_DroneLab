//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FCS_model_types.h
//
// Code generated for Simulink model 'FCS_model'.
//
// Model version                  : 1.12
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Feb 27 17:32:46 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_FCS_model_types_h_
#define RTW_HEADER_FCS_model_types_h_
#include "rtwtypes.h"
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

#ifndef DEFINED_TYPEDEF_FOR_struct_OMRgDnJcZuQneKEj9vdTyD_
#define DEFINED_TYPEDEF_FOR_struct_OMRgDnJcZuQneKEj9vdTyD_

struct struct_OMRgDnJcZuQneKEj9vdTyD
{
  real_T blades;
  real_T radius;
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
  real_T area;
  real_T lock;
  real_T b;
  real_T k;
  real_T w2ToThrustGain;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_p3FXZIgqtjF2uqDpmYjb6C_
#define DEFINED_TYPEDEF_FOR_struct_p3FXZIgqtjF2uqDpmYjb6C_

struct struct_p3FXZIgqtjF2uqDpmYjb6C
{
  real_T maxLimit;
  real_T minLimit;
  real_T commandToW2Gain;
  real_T thrustToMotorCommand;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_OSJpyIZcrpXqReVWwh9iuG_
#define DEFINED_TYPEDEF_FOR_struct_OSJpyIZcrpXqReVWwh9iuG_

struct struct_OSJpyIZcrpXqReVWwh9iuG
{
  struct_XRMsui9C07VjBvdq1msujB SixDOF;
  struct_IZWOW0zYvpphl7qLgSfN7E PositionOnEarth;
  struct_q6UUpnZ4gTjFvULFx6Rxa Airframe;
  struct_OMRgDnJcZuQneKEj9vdTyD Rotor;
  struct_p3FXZIgqtjF2uqDpmYjb6C Motor;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_eAf0NJvzCY9HYTXF7bLNgB_
#define DEFINED_TYPEDEF_FOR_struct_eAf0NJvzCY9HYTXF7bLNgB_

struct struct_eAf0NJvzCY9HYTXF7bLNgB
{
  real_T Ts2Q[16];
  real_T Q2Ts[16];
  real_T takeoffGain;
  real_T totalThrustMaxRelative;
  real_T motorsThrustPerMotorMax;
};

#endif
#endif                                 // RTW_HEADER_FCS_model_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
