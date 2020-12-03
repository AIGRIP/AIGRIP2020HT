//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: StableLine.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//
#ifndef STABLELINE_H
#define STABLELINE_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "StableLine_types.h"

// Function Declarations
extern void StableLine(const double degreesMeasured[360], const double
  YCoordinates[360], const double XCoordinates[360], const double
  signatureRadius[360], double targetPointF1Y[11], double targetPointF1X[11],
  double normalPointF1Y[11], double normalPointF1X[11], double targetPointF2Y[11],
  double targetPointF2X[11], double normalPointF2Y[11], double normalPointF2X[11],
  double *targetPointF0Y, double *targetPointF0X, double *normalPointF0Y, double
  *normalPointF0X, double signatureRadiusTargetF1[11], double
  signatureRadiusTargetF2[11]);

#endif

//
// File trailer for StableLine.h
//
// [EOF]
//
