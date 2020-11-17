//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ForwardKinematics.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Nov-2020 14:54:02
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
//                double jointPositionC[2]
// Return Type  : void
//
void ForwardKinematics(const double linkLengths[5], const double
  motorPositionM1[2], double motorAnglet1, double, double jointPositionC[2])
{
  // Input:
  // linkLengths = 1x5 array with the lengths of all five links in the order
  // a,b,c,d,e. The lengths are in mm;
  // motorPositionM1 =  1x2 array with the x and y coordinates of motor M1.
  // The coordinates are relative to the palm center
  // motorAnglet1 = Angle of motor M1 in rad
  // motorAnglet2 = Angle of motor M1 in rad
  // Output:
  // jointPostions =  2x4 array with the postions of all four joints in the order 
  // A,B,C,E
  // opticalSensorPosition = 1x2 array with the x and y coordinates of
  // optical sensor. The coordinates are relative to the palm center
  // Calculate the postion of motor M2 relative to motor M1
  motorAnglet1 -= 1.5707963267948966;

  // Calculate the postions of joint A and C
  jointPositionC[0] = motorPositionM1[0] - linkLengths[2] * std::sin
    (motorAnglet1);
  jointPositionC[1] = motorPositionM1[1] + linkLengths[2] * std::cos
    (motorAnglet1);

  //  Calculate the norm for joint A to joint C
  // Calculate the postions of joint B
  // Calculate the postions of joint E and optical sensor postion
  // jointPostions = [jointPositionA jointPositionB jointPositionC jointPositionE]; 
  //      scatter(jointPostions(:,1),jointPostions(:,2))
  //      hold on
  //      scatter(0,0)
  //      hold on
  //      scatter(-29,-38)
}

//
// File trailer for ForwardKinematics.cpp
//
// [EOF]
//
