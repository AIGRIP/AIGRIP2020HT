//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortedInsertion.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//

// Include Files
#include "sortedInsertion.h"
#include "StableLine.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : double x
//                int ix
//                double b_data[]
//                int *nb
//                int blen
//                int idx_data[]
// Return Type  : void
//
void sortedInsertion(double x, int ix, double b_data[], int *nb, int blen, int
                     idx_data[])
{
  if (*nb == 0) {
    *nb = 1;
    idx_data[0] = ix;
    b_data[0] = x;
  } else if ((x >= b_data[0]) || rtIsNaN(x)) {
    if ((*nb > 1) && (!(x >= b_data[*nb - 1])) && (!rtIsNaN(x))) {
      int ja;
      int jc;
      int jb;
      ja = 1;
      jb = *nb;
      while (ja < jb) {
        jc = ja + ((jb - ja) >> 1);
        if (jc == ja) {
          ja = jb;
        } else if ((x >= b_data[jc - 1]) || rtIsNaN(x)) {
          ja = jc;
        } else {
          jb = jc;
        }
      }

      if (*nb < blen) {
        (*nb)++;
      }

      jb = ja + 1;
      for (jc = *nb; jc >= jb; jc--) {
        b_data[jc - 1] = b_data[jc - 2];
        idx_data[jc - 1] = idx_data[jc - 2];
      }

      b_data[ja - 1] = x;
      idx_data[ja - 1] = ix;
    } else {
      if (*nb < blen) {
        (*nb)++;
        b_data[*nb - 1] = x;
        idx_data[*nb - 1] = ix;
      }
    }
  } else {
    if (*nb < blen) {
      (*nb)++;
    }

    for (int jc = *nb; jc >= 2; jc--) {
      idx_data[jc - 1] = idx_data[jc - 2];
      b_data[jc - 1] = b_data[jc - 2];
    }

    b_data[0] = x;
    idx_data[0] = ix;
  }
}

//
// File trailer for sortedInsertion.cpp
//
// [EOF]
//
