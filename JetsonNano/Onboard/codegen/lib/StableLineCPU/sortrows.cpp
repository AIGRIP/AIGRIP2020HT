//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortrows.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//

// Include Files
#include "sortrows.h"
#include "StableLine.h"
#include "rt_nonfinite.h"
#include "sortLE.h"
#include <cstring>

// Function Declarations
static void apply_row_permutation(double y[720], const int idx[360]);

// Function Definitions

//
// Arguments    : double y[720]
//                const int idx[360]
// Return Type  : void
//
static void apply_row_permutation(double y[720], const int idx[360])
{
  double ycol[360];
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 360; i++) {
      ycol[i] = y[(idx[i] + 360 * j) - 1];
    }

    std::memcpy(&y[j * 360], &ycol[0], 360U * sizeof(double));
  }
}

//
// Arguments    : double y[720]
//                double ndx[360]
// Return Type  : void
//
void sortrows(double y[720], double ndx[360])
{
  int k;
  int i;
  int idx[360];
  int qEnd;
  int iwork[360];
  for (k = 0; k <= 358; k += 2) {
    if (sortLE(y, k + 1, k + 2)) {
      idx[k] = k + 1;
      idx[k + 1] = k + 2;
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  i = 2;
  while (i < 360) {
    int i2;
    int j;
    i2 = i << 1;
    j = 1;
    for (int pEnd = i + 1; pEnd < 361; pEnd = qEnd + i) {
      int p;
      int q;
      int kEnd;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > 361) {
        qEnd = 361;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int b_i;
        int i1;
        b_i = idx[q - 1];
        i1 = idx[p - 1];
        if (sortLE(y, i1, b_i)) {
          iwork[k] = i1;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = b_i;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork[k] = idx[p - 1];
              p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k < kEnd; k++) {
        idx[(j + k) - 1] = iwork[k];
      }

      j = qEnd;
    }

    i = i2;
  }

  apply_row_permutation(y, idx);
  for (i = 0; i < 360; i++) {
    ndx[i] = idx[i];
  }
}

//
// File trailer for sortrows.cpp
//
// [EOF]
//
