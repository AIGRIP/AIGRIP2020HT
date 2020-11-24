//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ParallelMotorAnglet2.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Nov-2020 08:45:51
//

// Include Files
#include "ParallelMotorAnglet2.h"
#include <cmath>

// Function Definitions
//
// This function Caluclates what the angle motor M2 should have to make
// link e parallel
// Arguments    : double motorAnglet1
//                const double motorPositionM1[2]
//                const double motorPositionM2[2]
//                const double linkLengths[5]
// Return Type  : double
//
double ParallelMotorAnglet2(double motorAnglet1, const double motorPositionM1[2],
  const double motorPositionM2[2], const double linkLengths[5])
{
  double absxk;
  double absxk_tmp;
  double jointPositionB_idx_0;
  double motorAnglet2;
  double normBM2;
  double scale;

  // Input:
  // motorAnglet1 = Angle of motor M1 in rad
  // motorPositionM1 =  1x2 array with the x and -z coordinates of motor M1.
  // The coordinates are relative to the palm center
  // motorPositionM2 =  1x2 array with the x and -z coordinates of motor M2.
  // The coordinates are relative to the palm center
  // linkLengths = 1x5 array with the lengths of all five links in the order
  // a,b,c,d,e
  // Output:
  // motorAnglet2 = Angle of motor M1 in rad
  // Set the appropriate lengths for the links
  // Calculate the position of joint B when link d lies
  // perpendicular to link e
  jointPositionB_idx_0 = (motorPositionM1[0] + linkLengths[2] * std::cos
    (motorAnglet1)) - linkLengths[3];
  scale = 3.3121686421112381E-170;
  absxk = std::abs(jointPositionB_idx_0 - motorPositionM2[0]);
  if (absxk > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    scale = absxk;
  } else {
    absxk /= 3.3121686421112381E-170;
    normBM2 = absxk * absxk;
  }

  absxk_tmp = std::abs((motorPositionM1[1] + linkLengths[2] * std::sin
                        (motorAnglet1)) - motorPositionM2[1]);
  if (absxk_tmp > scale) {
    absxk = scale / absxk_tmp;
    normBM2 = normBM2 * absxk * absxk + 1.0;
    scale = absxk_tmp;
  } else {
    absxk = absxk_tmp / scale;
    normBM2 += absxk * absxk;
  }

  normBM2 = scale * std::sqrt(normBM2);
  scale = std::acos(((linkLengths[0] * linkLengths[0] + normBM2 * normBM2) -
                     linkLengths[1] * linkLengths[1]) / (2.0 * linkLengths[0] *
    normBM2));
  absxk = std::acos(absxk_tmp / normBM2);
  if (jointPositionB_idx_0 > motorPositionM2[0]) {
    motorAnglet2 = scale - absxk;
  } else {
    motorAnglet2 = scale + absxk;
  }

  return motorAnglet2;
}

//
// File trailer for ParallelMotorAnglet2.cpp
//
// [EOF]
//
