//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortLE.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//

// Include Files
#include "sortLE.h"
#include "StableLine.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const double v[720]
//                int idx1
//                int idx2
// Return Type  : bool
//
bool sortLE(const double v[720], int idx1, int idx2)
{
  bool p;
  int k;
  bool exitg1;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    int i;
    int i1;
    i = (idx1 + 360 * k) - 1;
    i1 = (idx2 + 360 * k) - 1;
    if ((v[i] == v[i1]) || (rtIsNaN(v[i]) && rtIsNaN(v[i1]))) {
      k++;
    } else {
      if ((!(v[i] <= v[i1])) && (!rtIsNaN(v[i1]))) {
        p = false;
      }

      exitg1 = true;
    }
  }

  return p;
}

//
// File trailer for sortLE.cpp
//
// [EOF]
//
