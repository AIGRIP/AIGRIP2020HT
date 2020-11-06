//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: applyToMultipleDims.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 06-Nov-2020 12:01:09
//

// Include Files
#include "applyToMultipleDims.h"

// Function Definitions
//
// Arguments    : const bool x[23409]
//                double varargout_1[9]
// Return Type  : void
//
namespace coder
{
  namespace internal
  {
    void applyToMultipleDims(const bool x[23409], double varargout_1[9])
    {
      double d;
      for (int i = 0; i < 9; i++) {
        int xpageoffset;
        xpageoffset = i * 2601;
        d = x[xpageoffset];
        for (int k = 0; k < 2600; k++) {
          d += static_cast<double>(x[(xpageoffset + k) + 1]);
        }

        varargout_1[i] = d;
      }
    }
  }
}

//
// File trailer for applyToMultipleDims.cpp
//
// [EOF]
//
