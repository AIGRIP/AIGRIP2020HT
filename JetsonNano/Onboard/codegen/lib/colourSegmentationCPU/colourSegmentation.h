//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colourSegmentation.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 06-Nov-2020 12:01:09
//
#ifndef COLOURSEGMENTATION_H
#define COLOURSEGMENTATION_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void colourSegmentation(const unsigned char colourBalancedImage[2184480],
  double centerOfObjectX, double centerOfObjectY, bool colourSegmentationMask
  [728160]);

#endif

//
// File trailer for colourSegmentation.h
//
// [EOF]
//
