//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MorphologicalFilters_internal_types.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 02-Dec-2020 13:31:29
//
#ifndef MORPHOLOGICALFILTERS_INTERNAL_TYPES_H
#define MORPHOLOGICALFILTERS_INTERNAL_TYPES_H

// Include Files
#include "MorphologicalFilters_types.h"
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct struct_T
{
  double Area;
  double Centroid[2];
  coder::array<double, 1U> PixelIdxList;
};

#endif

//
// File trailer for MorphologicalFilters_internal_types.h
//
// [EOF]
//
