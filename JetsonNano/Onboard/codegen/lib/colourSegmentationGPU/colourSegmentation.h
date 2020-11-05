//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colourSegmentation.h
//
// GPU Coder version                    : 2.0
// CUDA/C/C++ source code generated on  : 05-Nov-2020 08:36:44
//
#ifndef COLOURSEGMENTATION_H
#define COLOURSEGMENTATION_H

// Include Files
#include "rtwtypes.h"
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
