//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unique.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//

// Include Files
#include "unique.h"
#include "StableLine.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include <cmath>
#include <cstring>
#include <math.h>

// Function Definitions

//
// Arguments    : const double a[720]
//                double b_data[]
//                int b_size[2]
// Return Type  : void
//
void unique_rows(const double a[720], double b_data[], int b_size[2])
{
  double b[720];
  double unusedExpr[360];
  int nb;
  int k;
  int i;
  int exponent;
  std::memcpy(&b[0], &a[0], 720U * sizeof(double));
  sortrows(b, unusedExpr);
  std::memcpy(&b_data[0], &b[0], 720U * sizeof(double));
  nb = -1;
  k = 0;
  while (k + 1 <= 360) {
    int k0;
    k0 = k;
    int exitg1;
    do {
      exitg1 = 0;
      k++;
      if (k + 1 > 360) {
        exitg1 = 1;
      } else {
        bool p;
        int j;
        bool exitg2;
        p = false;
        j = 0;
        exitg2 = false;
        while ((!exitg2) && (j < 2)) {
          int absx_tmp;
          double absx;
          absx_tmp = k + 360 * j;
          absx = std::abs(b_data[absx_tmp] / 2.0);
          if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
            if (absx <= 2.2250738585072014E-308) {
              absx = 4.94065645841247E-324;
            } else {
              frexp(absx, &exponent);
              absx = std::ldexp(1.0, exponent - 53);
            }
          } else {
            absx = rtNaN;
          }

          i = k0 + 360 * j;
          if ((std::abs(b_data[absx_tmp] - b_data[i]) < absx) || (rtIsInf
               (b_data[i]) && rtIsInf(b_data[absx_tmp]) && ((b_data[i] > 0.0) ==
                (b_data[absx_tmp] > 0.0)))) {
            j++;
          } else {
            p = true;
            exitg2 = true;
          }
        }

        if (p) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    nb++;
    b_data[nb] = b_data[k0];
    b_data[nb + 360] = b_data[k0 + 360];
  }

  if (1 > nb + 1) {
    nb = -1;
  }

  k = nb + 1;
  if (0 <= nb) {
    std::memcpy(&b[0], &b_data[0], (nb + 1) * sizeof(double));
  }

  for (i = 0; i <= nb; i++) {
    b[i + k] = b_data[i + 360];
  }

  b_size[0] = k;
  b_size[1] = 2;
  nb = k * 2;
  if (0 <= nb - 1) {
    std::memcpy(&b_data[0], &b[0], nb * sizeof(double));
  }
}

//
// File trailer for unique.cpp
//
// [EOF]
//
