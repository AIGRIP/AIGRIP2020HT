//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsxfun.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 02-Dec-2020 13:31:29
//

// Include Files
#include "bsxfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &a
//                const double b[2]
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
namespace coder
{
  void bsxfun(const ::coder::array<double, 2U> &a, const double b[2], ::coder::
              array<double, 2U> &c)
  {
    c.set_size(a.size(0), 2);
    if (a.size(0) != 0) {
      int acoef;
      int i;
      int k;
      acoef = (a.size(0) != 1);
      i = a.size(0) - 1;
      for (k = 0; k <= i; k++) {
        c[k] = a[acoef * k] - b[0];
      }

      i = c.size(0) - 1;
      for (k = 0; k <= i; k++) {
        c[k + c.size(0)] = a[acoef * k + a.size(0)] - b[1];
      }
    }
  }
}

//
// File trailer for bsxfun.cpp
//
// [EOF]
//
