//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sort.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//

// Include Files
#include "sort.h"
#include "StableLine.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include <cstring>

// Function Definitions

//
// Arguments    : double x[11]
//                int idx[11]
// Return Type  : void
//
void sort(double x[11], int idx[11])
{
  double x4[4];
  signed char idx4[4];
  double xwork[11];
  int i;
  int nNaNs;
  int k;
  signed char perm[4];
  int i3;
  int i2;
  int i4;
  int iwork[11];
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  std::memset(&xwork[0], 0, 11U * sizeof(double));
  for (i = 0; i < 11; i++) {
    idx[i] = 0;
  }

  nNaNs = 0;
  i = 0;
  for (k = 0; k < 11; k++) {
    if (rtIsNaN(x[k])) {
      idx[10 - nNaNs] = k + 1;
      xwork[10 - nNaNs] = x[k];
      nNaNs++;
    } else {
      i++;
      idx4[i - 1] = static_cast<signed char>(k + 1);
      x4[i - 1] = x[k];
      if (i == 4) {
        int quartetOffset;
        double d;
        double d1;
        quartetOffset = k - nNaNs;
        if (x4[0] <= x4[1]) {
          i = 1;
          i2 = 2;
        } else {
          i = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        d = x4[i - 1];
        d1 = x4[i3 - 1];
        if (d <= d1) {
          d = x4[i2 - 1];
          if (d <= d1) {
            perm[0] = static_cast<signed char>(i);
            perm[1] = static_cast<signed char>(i2);
            perm[2] = static_cast<signed char>(i3);
            perm[3] = static_cast<signed char>(i4);
          } else if (d <= x4[i4 - 1]) {
            perm[0] = static_cast<signed char>(i);
            perm[1] = static_cast<signed char>(i3);
            perm[2] = static_cast<signed char>(i2);
            perm[3] = static_cast<signed char>(i4);
          } else {
            perm[0] = static_cast<signed char>(i);
            perm[1] = static_cast<signed char>(i3);
            perm[2] = static_cast<signed char>(i4);
            perm[3] = static_cast<signed char>(i2);
          }
        } else {
          d1 = x4[i4 - 1];
          if (d <= d1) {
            if (x4[i2 - 1] <= d1) {
              perm[0] = static_cast<signed char>(i3);
              perm[1] = static_cast<signed char>(i);
              perm[2] = static_cast<signed char>(i2);
              perm[3] = static_cast<signed char>(i4);
            } else {
              perm[0] = static_cast<signed char>(i3);
              perm[1] = static_cast<signed char>(i);
              perm[2] = static_cast<signed char>(i4);
              perm[3] = static_cast<signed char>(i2);
            }
          } else {
            perm[0] = static_cast<signed char>(i3);
            perm[1] = static_cast<signed char>(i4);
            perm[2] = static_cast<signed char>(i);
            perm[3] = static_cast<signed char>(i2);
          }
        }

        i3 = perm[0] - 1;
        idx[quartetOffset - 3] = idx4[i3];
        i4 = perm[1] - 1;
        idx[quartetOffset - 2] = idx4[i4];
        i = perm[2] - 1;
        idx[quartetOffset - 1] = idx4[i];
        i2 = perm[3] - 1;
        idx[quartetOffset] = idx4[i2];
        x[quartetOffset - 3] = x4[i3];
        x[quartetOffset - 2] = x4[i4];
        x[quartetOffset - 1] = x4[i];
        x[quartetOffset] = x4[i2];
        i = 0;
      }
    }
  }

  if (i > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (i == 1) {
      perm[0] = 1;
    } else if (i == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (k = 0; k < i; k++) {
      i3 = perm[k] - 1;
      i4 = ((k - nNaNs) - i) + 11;
      idx[i4] = idx4[i3];
      x[i4] = x4[i3];
    }
  }

  i = (nNaNs >> 1) + 11;
  for (k = 0; k <= i - 12; k++) {
    i3 = (k - nNaNs) + 11;
    i2 = idx[i3];
    idx[i3] = idx[10 - k];
    idx[10 - k] = i2;
    x[i3] = xwork[10 - k];
    x[10 - k] = xwork[i3];
  }

  if ((nNaNs & 1) != 0) {
    i -= nNaNs;
    x[i] = xwork[i];
  }

  if (11 - nNaNs > 1) {
    for (i = 0; i < 11; i++) {
      iwork[i] = 0;
    }

    i4 = (11 - nNaNs) >> 2;
    i2 = 4;
    while (i4 > 1) {
      if ((i4 & 1) != 0) {
        i4--;
        i = i2 * i4;
        i3 = 11 - (nNaNs + i);
        if (i3 > i2) {
          merge(idx, x, i, i2, i3 - i2, iwork, xwork);
        }
      }

      i = i2 << 1;
      i4 >>= 1;
      for (k = 0; k < i4; k++) {
        merge(idx, x, k * i, i2, i2, iwork, xwork);
      }

      i2 = i;
    }

    if (11 - nNaNs > i2) {
      merge(idx, x, 0, i2, 11 - (nNaNs + i2), iwork, xwork);
    }
  }
}

//
// File trailer for sort.cpp
//
// [EOF]
//
