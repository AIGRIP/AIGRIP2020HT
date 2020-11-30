//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ForwardKinematics.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Nov-2020 08:51:49
//

// Include Files
#include "ForwardKinematics.h"
#include <cmath>

// Function Definitions
//
// This function Caluclates the forward kinematics of the gripper.
// Arguments    : const double linkLengths[5]
//                const double motorPositionM1[2]
//                double motorAnglet1
//                double motorAnglet2
//                double jointPostions[8]
//                double opticalSensorPosition[2]
// Return Type  : void
//
void ForwardKinematics(const double linkLengths[5], const double
  motorPositionM1[2], double motorAnglet1, double motorAnglet2, double
  jointPostions[8], double opticalSensorPosition[2])
{
  double absxk;
  double jointPositionA_idx_0;
  double jointPositionA_idx_1;
  double jointPositionC_idx_0;
  double jointPositionC_idx_1;
  double motorPositionM2_idx_1;
  double normAC;
  double scale;
  double t;

  // Input:
  // linkLengths = 1x5 array with the lengths of all five links in the order
  // a,b,c,d,e. The lengths are in mm;
  // motorPositionM1 =  1x2 array with the x and y coordinates of motor M1.
  // The coordinates are relative to the palm center
  // motorAnglet1 = Angle of motor M1 in rad
  // motorAnglet2 = Angle of motor M1 in rad
  // Output:
  // jointPostions =  1x8 array with the postions of all four joints in the order 
  // Ax,Ay,Bx,By,Cx,Cy,Ex,Ey
  // opticalSensorPosition = 1x2 array with the x and y coordinates of
  // optical sensor. The coordinates are relative to the palm center
  // Calculate the postion of motor M2 relative to motor M1
  motorAnglet2 += 1.5707963267948966;

  // Calculate the postions of joint A and C
  jointPositionA_idx_0 = (motorPositionM1[0] + -29.0) + linkLengths[0] * std::
    cos(motorAnglet2);
  jointPositionA_idx_1 = (motorPositionM1[1] + -38.0) + linkLengths[0] * std::
    sin(motorAnglet2);
  jointPositionC_idx_0 = motorPositionM1[0] + linkLengths[2] * std::sin
    (motorAnglet1);
  jointPositionC_idx_1 = motorPositionM1[1] + linkLengths[2] * std::cos
    (motorAnglet1);

  // Calculate the norm for joint A to joint C
  scale = 3.3121686421112381E-170;
  motorPositionM2_idx_1 = std::abs(jointPositionA_idx_0 - jointPositionC_idx_0);
  if (motorPositionM2_idx_1 > 3.3121686421112381E-170) {
    normAC = 1.0;
    scale = motorPositionM2_idx_1;
  } else {
    t = motorPositionM2_idx_1 / 3.3121686421112381E-170;
    normAC = t * t;
  }

  absxk = std::abs(jointPositionA_idx_1 - jointPositionC_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    normAC = normAC * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    normAC += t * t;
  }

  normAC = scale * std::sqrt(normAC);

  // Calculate the postions of joint B
  absxk = linkLengths[3] * linkLengths[3];
  scale = std::acos(motorPositionM2_idx_1 / normAC) + std::acos(((normAC *
    normAC + linkLengths[1] * linkLengths[1]) - absxk) / (2.0 * normAC *
    linkLengths[1]));
  normAC = jointPositionA_idx_0 + linkLengths[1] * std::cos(scale);
  motorPositionM2_idx_1 = jointPositionA_idx_1 + linkLengths[1] * std::sin(scale);

  // Calculate the postions of joint E and optical sensor postion
  t = std::atan(linkLengths[4] / linkLengths[3]);
  scale = std::sqrt(linkLengths[4] * linkLengths[4] + absxk);
  absxk = normAC + scale * std::cos(t);
  scale = motorPositionM2_idx_1 + scale * std::sin(t);

  // jointPostions = [jointPositionA jointPositionB jointPositionC jointPositionE]; 
  opticalSensorPosition[0] = (absxk + jointPositionC_idx_0) / 2.0;
  jointPostions[0] = jointPositionA_idx_0;
  jointPostions[2] = normAC;
  jointPostions[4] = jointPositionC_idx_0;
  jointPostions[6] = absxk;
  opticalSensorPosition[1] = (scale + jointPositionC_idx_1) / 2.0;
  jointPostions[1] = jointPositionA_idx_1;
  jointPostions[3] = motorPositionM2_idx_1;
  jointPostions[5] = jointPositionC_idx_1;
  jointPostions[7] = scale;
}

//
// File trailer for ForwardKinematics.cpp
//
// [EOF]
//
