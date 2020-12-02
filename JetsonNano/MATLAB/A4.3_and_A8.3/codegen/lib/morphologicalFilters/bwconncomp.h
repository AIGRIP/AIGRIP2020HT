//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwconncomp.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 02-Dec-2020 13:31:29
//
#ifndef BWCONNCOMP_H
#define BWCONNCOMP_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder
{
  void bwconncomp(const bool varargin_1[728160], double *CC_Connectivity, double
                  CC_ImageSize[2], double *CC_NumObjects, ::coder::array<double,
                  1U> &CC_RegionIndices, ::coder::array<int, 1U>
                  &CC_RegionLengths);
}

#endif

//
// File trailer for bwconncomp.h
//
// [EOF]
//
