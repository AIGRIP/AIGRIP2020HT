//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ForwardKinematics.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 18-Nov-2020 07:15:07
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
  //      jointPostions = zeros(1,8);
  //
  //      motorPositionM2 = motorPositionM1 + [-29 -38];
  motorAnglet1 -= 1.5707963267948966;

  //      motorAnglet2 = motorAnglet2 + pi/2;
  //
  //      linkLengtha = linkLengths(1);
  //      linkLengthb = linkLengths(2);
  //      linkLengthd = linkLengths(4);
  //      linkLengthe = linkLengths(5);
  // Calculate the postions of joint A and C
  //      jointPositionA = [motorPositionM2(1)+linkLengtha*cos(motorAnglet2) motorPositionM2(2)+linkLengtha*sin(motorAnglet2)];    
  jointPositionC[0] = motorPositionM1[0] - linkLengths[2] * std::sin
    (motorAnglet1);
  jointPositionC[1] = motorPositionM1[1] + linkLengths[2] * std::cos
    (motorAnglet1);

  //      % Calculate the norm for joint A to joint C
  //      normAC = norm(jointPositionA - jointPositionC);
  //
  //      %Calculate the postions of joint B
  //      angleAlfa1 = acos(abs(jointPositionA(1)- jointPositionC(1))/normAC);
  //      angleAlfa2 = acos((normAC^2 + linkLengthb^2 - linkLengthd^2) / (2*normAC*linkLengthb)); 
  //      jointPositionB = jointPositionA + [linkLengthb*cos(angleAlfa1+angleAlfa2) linkLengthb*sin(angleAlfa1+angleAlfa2)]; 
  //
  //      %Calculate the postions of joint E and optical sensor postion
  //      angleBE = atan(linkLengthe/linkLengthd);
  //      normBE = sqrt(linkLengthe^2 + linkLengthd^2);
  //      jointPositionE = jointPositionB + [normBE*cos(angleBE) normBE*sin(angleBE)]; 
  //      opticalSensorPosition = (jointPositionE + jointPositionC)/2;
  //
  //      %jointPostions = [jointPositionA jointPositionB jointPositionC jointPositionE]; 
  //
  //      jointPostions(1) = jointPositionA(1);
  //      jointPostions(2) = jointPositionA(2);
  //      jointPostions(3) = jointPositionB(1);
  //      jointPostions(4) = jointPositionB(2);
  //      jointPostions(5) = jointPositionC(1);
  //      jointPostions(6) = jointPositionC(2);
  //      jointPostions(7) = jointPositionE(1);
  //      jointPostions(8) = jointPositionE(2);
  //
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
