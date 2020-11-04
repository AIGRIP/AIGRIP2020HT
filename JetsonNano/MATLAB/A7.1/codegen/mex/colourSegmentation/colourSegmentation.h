//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  colourSegmentation.h
//
//  Code generation for function 'colourSegmentation'
//


#pragma once

// Include files
#include "colourSegmentation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void colourSegmentation(colourSegmentationStackData *SD, const emlrtStack *sp,
  const uint8_T colourBalancedImage[2184480], real_T centerOfObjectX, real_T
  centerOfObjectY, boolean_T SegmentationMask[728160]);

// End of code generation (colourSegmentation.h)
