//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ForwardKinematics.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Nov-2020 13:53:46
//
#ifndef FORWARDKINEMATICS_H
#define FORWARDKINEMATICS_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void ForwardKinematics(const double linkLengths[5], const double
  motorPositionM1[2], double motorAnglet1, double motorAnglet2, double
  jointPostions[8], double opticalSensorPosition[2]);

#endif

//
// File trailer for ForwardKinematics.h
//
// [EOF]
//
