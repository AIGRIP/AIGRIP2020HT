//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: extremeKElements.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//

// Include Files
#include "extremeKElements.h"
#include "StableLine.h"
#include "rt_nonfinite.h"
#include "sortedInsertion.h"
#include <cstring>

// Function Definitions

//
// Arguments    : const double a_data[]
//                const int a_size[1]
//                int k
//                int idx_data[]
//                int idx_size[1]
//                double b_data[]
//                int b_size[1]
// Return Type  : void
//
void exkib(const double a_data[], const int a_size[1], int k, int idx_data[],
           int idx_size[1], double b_data[], int b_size[1])
{
  int n;
  int unusedU1;
  int unusedU2;
  n = a_size[0];
  idx_size[0] = k;
  b_size[0] = k;
  if (0 <= k - 1) {
    std::memset(&idx_data[0], 0, k * sizeof(int));
    std::memset(&b_data[0], 0, k * sizeof(double));
  }

  if (k != 0) {
    int j;
    for (j = 0; j < k; j++) {
      unusedU1 = j;
      sortedInsertion(a_data[j], j + 1, b_data, &unusedU1, k, idx_data);
    }

    unusedU1 = k + 1;
    for (j = unusedU1; j <= n; j++) {
      unusedU2 = k;
      sortedInsertion(a_data[j - 1], j, b_data, &unusedU2, k, idx_data);
    }
  }
}

//
// File trailer for extremeKElements.cpp
//
// [EOF]
//
