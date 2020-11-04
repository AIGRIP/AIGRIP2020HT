//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colourSegmentation.h
//
// GPU Coder version                    : 2.0
// CUDA/C/C++ source code generated on  : 04-Nov-2020 15:12:57
//
#ifndef COLOURSEGMENTATION_H
#define COLOURSEGMENTATION_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void colourSegmentation(const unsigned char colourBalancedImage[2184480],
  double centerOfObjectX, double centerOfObjectY, bool SegmentationMask[728160]);

#endif

//
// File trailer for colourSegmentation.h
//
// [EOF]
//
