//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rgb2hsv.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 06-Nov-2020 12:01:09
//

// Include Files
#include "rgb2hsv.h"

// Function Definitions
//
// Arguments    : const double Xin[2184480]
//                double hsv[2184480]
// Return Type  : void
//
namespace coder
{
  void rgb2hsv_portable(const double Xin[2184480], double hsv[2184480])
  {
    double b_ex;
    double d;
    double d1;
    double delta;
    double ex;
    double h;
    double s;
    double tmp;
    int i;
    int iy;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,h,iy,i,ex,d,d1,b_ex,tmp,delta)

    for (int ix = 0; ix < 740; ix++) {
      for (iy = 0; iy < 984; iy++) {
        i = iy + 984 * ix;
        ex = Xin[i];
        d = Xin[i + 728160];
        d1 = Xin[i + 1456320];
        b_ex = ex;
        tmp = ex;
        if (ex < d) {
          b_ex = d;
        }

        if (ex > d) {
          tmp = d;
        }

        if (b_ex < d1) {
          b_ex = d1;
        }

        if (tmp > d1) {
          tmp = d1;
        }

        delta = b_ex - tmp;
        s = delta;
        if (delta == 0.0) {
          s = 1.0;
        }

        h = 0.0;
        if (ex == b_ex) {
          h = (d - d1) / s;
        }

        if (d == b_ex) {
          h = (d1 - ex) / s + 2.0;
        }

        if (d1 == b_ex) {
          h = (ex - d) / s + 4.0;
        }

        h /= 6.0;
        if (h < 0.0) {
          h++;
        }

        tmp = s / b_ex;
        if (delta == 0.0) {
          h = 0.0;
          tmp = 0.0;
        }

        if (b_ex != 0.0) {
          s = tmp;
        }

        if (b_ex == 0.0) {
          s = 0.0;
        }

        hsv[i] = h;
        hsv[i + 728160] = s;
        hsv[i + 1456320] = b_ex;
      }
    }
  }
}

//
// File trailer for rgb2hsv.cpp
//
// [EOF]
//
