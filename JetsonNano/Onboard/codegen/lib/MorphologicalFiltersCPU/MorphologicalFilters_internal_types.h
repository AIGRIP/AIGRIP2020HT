//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  MorphologicalFilters_internal_types.h
//
//  Code generation for function 'MorphologicalFilters'
//


#ifndef MORPHOLOGICALFILTERS_INTERNAL_TYPES_H
#define MORPHOLOGICALFILTERS_INTERNAL_TYPES_H

// Include files
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

// End of code generation (MorphologicalFilters_internal_types.h)
