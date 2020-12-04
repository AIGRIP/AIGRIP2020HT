//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: GetValidGripPoints.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 03-Dec-2020 12:39:31
//
#ifndef GETVALIDGRIPPOINTS_H
#define GETVALIDGRIPPOINTS_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void GetValidGripPoints(const double targetPointYPixel_data[], const int
  targetPointYPixel_size[1], const double targetPointXPixel_data[], const int
  targetPointXPixel_size[1], const double normalPointYPixel_data[], const int
  normalPointYPixel_size[1], const double normalPointXPixel_data[], const int
  normalPointXPixel_size[1], double distanceToObject, double fingerNumber,
  double offset, unsigned short motorSteps[3], double *bestTargetPointY, double *
  bestTargetPointX, double *bestNormalPointY, double *bestNormalPointX);

#endif

//
// File trailer for GetValidGripPoints.h
//
// [EOF]
//
