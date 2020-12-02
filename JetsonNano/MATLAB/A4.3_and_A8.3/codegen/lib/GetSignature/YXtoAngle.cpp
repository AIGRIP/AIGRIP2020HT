//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: YXtoAngle.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:36:28
//

// Include Files
#include "YXtoAngle.h"
#include "GetARsing.h"
#include "GetSignature.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <math.h>

// Function Declarations
static double rt_atan2d_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int b_u0;
    int b_u1;
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(static_cast<double>(b_u0), static_cast<double>(b_u1));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

//
// Convert length vectors to angles.
//    x - Is the vector in x-direction.
//    x - Is the vector in x-direction.
//    angleRadian - Returns the angle in radian for all the vectors.
// Arguments    : const coder::array<double, 1U> *y
//                const coder::array<double, 1U> *x
//                coder::array<double, 1U> *angleRadian
// Return Type  : void
//
void YXtoAngle(const coder::array<double, 1U> &y, const coder::array<double, 1U>
               &x, coder::array<double, 1U> &angleRadian)
{
  int nx;
  int end;
  coder::array<bool, 1U> r;
  coder::array<bool, 1U> r1;
  int i;
  coder::array<int, 1U> r2;
  coder::array<double, 1U> b_x;
  coder::array<double, 1U> b_y;
  coder::array<double, 1U> b;
  coder::array<int, 1U> r3;
  coder::array<int, 1U> r4;
  coder::array<int, 1U> r5;

  //  Allocates the angles to return in radians.
  angleRadian.set_size(y.size(0));
  nx = y.size(0);
  for (end = 0; end < nx; end++) {
    angleRadian[end] = 0.0;
  }

  //  Convert angles in the first quadrant. RH+
  r.set_size(x.size(0));
  nx = x.size(0);
  for (end = 0; end < nx; end++) {
    r[end] = (x[end] >= 0.0);
  }

  r1.set_size(y.size(0));
  nx = y.size(0);
  for (end = 0; end < nx; end++) {
    r1[end] = (y[end] >= 0.0);
  }

  end = r.size(0) - 1;
  nx = 0;
  for (i = 0; i <= end; i++) {
    if (r[i] && r1[i]) {
      nx++;
    }
  }

  r2.set_size(nx);
  nx = 0;
  for (i = 0; i <= end; i++) {
    if (r[i] && r1[i]) {
      r2[nx] = i + 1;
      nx++;
    }
  }

  b_x.set_size(r2.size(0));
  nx = r2.size(0);
  for (end = 0; end < nx; end++) {
    b_x[end] = x[r2[end] - 1];
  }

  b_y.set_size(r2.size(0));
  nx = r2.size(0);
  for (end = 0; end < nx; end++) {
    b_y[end] = y[r2[end] - 1];
  }

  if (b_x.size(0) <= b_y.size(0)) {
    nx = b_x.size(0);
  } else {
    nx = b_y.size(0);
  }

  b.set_size(nx);
  if (b_x.size(0) <= b_y.size(0)) {
    nx = b_x.size(0);
  } else {
    nx = b_y.size(0);
  }

  for (end = 0; end < nx; end++) {
    b[end] = rt_atan2d_snf(b_x[end], b_y[end]);
  }

  nx = b.size(0);
  for (end = 0; end < nx; end++) {
    b[end] = -b[end];
  }

  end = r.size(0);
  nx = 0;
  for (i = 0; i < end; i++) {
    if (r[i] && r1[i]) {
      angleRadian[i] = b[nx] + 3.1415926535897931;
      nx++;
    }
  }

  //  Convert angles in the third quadrant. LH-
  r.set_size(x.size(0));
  nx = x.size(0);
  for (end = 0; end < nx; end++) {
    r[end] = (x[end] <= 0.0);
  }

  r1.set_size(y.size(0));
  nx = y.size(0);
  for (end = 0; end < nx; end++) {
    r1[end] = (y[end] <= 0.0);
  }

  end = r.size(0) - 1;
  nx = 0;
  for (i = 0; i <= end; i++) {
    if (r[i] && r1[i]) {
      nx++;
    }
  }

  r3.set_size(nx);
  nx = 0;
  for (i = 0; i <= end; i++) {
    if (r[i] && r1[i]) {
      r3[nx] = i + 1;
      nx++;
    }
  }

  nx = r3.size(0);
  b.set_size(r3.size(0));
  for (end = 0; end < nx; end++) {
    b[end] = std::abs(x[r3[end] - 1]);
  }

  nx = r3.size(0);
  b_y.set_size(r3.size(0));
  for (end = 0; end < nx; end++) {
    b_y[end] = std::abs(y[r3[end] - 1]);
  }

  if (b.size(0) <= b_y.size(0)) {
    nx = b.size(0);
  } else {
    nx = b_y.size(0);
  }

  b_x.set_size(nx);
  if (b.size(0) <= b_y.size(0)) {
    nx = b.size(0);
  } else {
    nx = b_y.size(0);
  }

  for (end = 0; end < nx; end++) {
    b_x[end] = rt_atan2d_snf(b[end], b_y[end]);
  }

  end = r.size(0);
  nx = 0;
  for (i = 0; i < end; i++) {
    if (r[i] && r1[i]) {
      angleRadian[i] = 6.2831853071795862 - b_x[nx];
      nx++;
    }
  }

  //  Convert angles in the second quadrant. LH+
  r.set_size(x.size(0));
  nx = x.size(0);
  for (end = 0; end < nx; end++) {
    r[end] = (x[end] >= 0.0);
  }

  r1.set_size(y.size(0));
  nx = y.size(0);
  for (end = 0; end < nx; end++) {
    r1[end] = (y[end] <= 0.0);
  }

  end = r.size(0) - 1;
  nx = 0;
  for (i = 0; i <= end; i++) {
    if (r[i] && r1[i]) {
      nx++;
    }
  }

  r4.set_size(nx);
  nx = 0;
  for (i = 0; i <= end; i++) {
    if (r[i] && r1[i]) {
      r4[nx] = i + 1;
      nx++;
    }
  }

  nx = r4.size(0);
  b.set_size(r4.size(0));
  for (end = 0; end < nx; end++) {
    b[end] = std::abs(x[r4[end] - 1]);
  }

  nx = r4.size(0);
  b_y.set_size(r4.size(0));
  for (end = 0; end < nx; end++) {
    b_y[end] = std::abs(y[r4[end] - 1]);
  }

  if (b.size(0) <= b_y.size(0)) {
    nx = b.size(0);
  } else {
    nx = b_y.size(0);
  }

  b_x.set_size(nx);
  if (b.size(0) <= b_y.size(0)) {
    nx = b.size(0);
  } else {
    nx = b_y.size(0);
  }

  for (end = 0; end < nx; end++) {
    b_x[end] = rt_atan2d_snf(b[end], b_y[end]);
  }

  end = r.size(0);
  nx = 0;
  for (i = 0; i < end; i++) {
    if (r[i] && r1[i]) {
      angleRadian[i] = b_x[nx];
      nx++;
    }
  }

  //  Convert angles in the fourth quadrant. RH-
  r.set_size(x.size(0));
  nx = x.size(0);
  for (end = 0; end < nx; end++) {
    r[end] = (x[end] <= 0.0);
  }

  r1.set_size(y.size(0));
  nx = y.size(0);
  for (end = 0; end < nx; end++) {
    r1[end] = (y[end] >= 0.0);
  }

  end = r.size(0) - 1;
  nx = 0;
  for (i = 0; i <= end; i++) {
    if (r[i] && r1[i]) {
      nx++;
    }
  }

  r5.set_size(nx);
  nx = 0;
  for (i = 0; i <= end; i++) {
    if (r[i] && r1[i]) {
      r5[nx] = i + 1;
      nx++;
    }
  }

  nx = r5.size(0);
  b.set_size(r5.size(0));
  for (end = 0; end < nx; end++) {
    b[end] = std::abs(x[r5[end] - 1]);
  }

  nx = r5.size(0);
  b_y.set_size(r5.size(0));
  for (end = 0; end < nx; end++) {
    b_y[end] = std::abs(y[r5[end] - 1]);
  }

  if (b.size(0) <= b_y.size(0)) {
    nx = b.size(0);
  } else {
    nx = b_y.size(0);
  }

  b_x.set_size(nx);
  if (b.size(0) <= b_y.size(0)) {
    nx = b.size(0);
  } else {
    nx = b_y.size(0);
  }

  for (end = 0; end < nx; end++) {
    b_x[end] = rt_atan2d_snf(b[end], b_y[end]);
  }

  end = r.size(0);
  nx = 0;
  for (i = 0; i < end; i++) {
    if (r[i] && r1[i]) {
      angleRadian[i] = b_x[nx] + 3.1415926535897931;
      nx++;
    }
  }
}

//
// File trailer for YXtoAngle.cpp
//
// [EOF]
//
