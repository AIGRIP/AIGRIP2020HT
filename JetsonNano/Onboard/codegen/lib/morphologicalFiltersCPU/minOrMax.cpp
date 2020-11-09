//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 05-Nov-2020 08:33:11
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const unsigned char x_data[]
//                const int x_size[1]
// Return Type  : unsigned char
//
namespace coder
{
  namespace internal
  {
    unsigned char maximum(const unsigned char x_data[], const int x_size[1])
    {
      int istop;
      unsigned char ex;
      istop = x_size[0];
      ex = x_data[0];
      for (int k = 2; k <= istop; k++) {
        unsigned char u;
        u = x_data[k - 1];
        if (ex < u) {
          ex = u;
        }
      }

      return ex;
    }
  }
}

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
