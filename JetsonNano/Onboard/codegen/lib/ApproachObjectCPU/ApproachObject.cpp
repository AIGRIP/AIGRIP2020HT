//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ApproachObject.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Nov-2020 11:38:04
//

// Include Files
#include "ApproachObject.h"
#include <cmath>

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions
//
// Arguments    : double u
// Return Type  : double
//
static double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// This function calculates how every motor in a finger should be rotated for
// it to reach a certain point with a certain angle and with the last link
// being parallel to the palm of the gripper
// Arguments    : const double linkLengths[5]
//                double currentMotorM0Steps
//                double currentMotorM1Steps
//                double distanceToObject
//                unsigned short motorAngles[3]
// Return Type  : void
//
void ApproachObject(const double linkLengths[5], double currentMotorM0Steps,
                    double currentMotorM1Steps, double distanceToObject,
                    unsigned short motorAngles[3])
{
  double absxk_tmp;
  double currentmotorAnglet1;
  double jointPositionB_idx_0;
  double motorAngles_idx_1;
  double motorAnglet2FirHalf;
  double normBM2;
  double scale;
  unsigned short u;

  // Input:
  // linkLengths = 1x5 array with the lengths of all five links in the order
  // a,b,c,d,e
  // currentmotorM1Steps =  Current postion of the motor angle. This angle
  // is measured in steps of the motor.
  // distanceToObject = Distance from the finger to the object. distance is
  // in mm.
  // Output:
  // motorAngles = 1X3 array with three motor angles one for each motro in a
  // finger. The order of the motors in the array is M0,M1,M2.
  // Convert the steps into radians
  currentmotorAnglet1 = 0.017453292519943295 * (currentMotorM1Steps *
    0.0045777065690089267 - 150.0);

  // Calculate the new angle of motor M1
  if (currentmotorAnglet1 > 1.5707963267948966) {
    // Calculate current distance from the joint position c to
    // position of motor M1
    currentmotorAnglet1 = std::sin(currentmotorAnglet1 - 1.5707963267948966) *
      linkLengths[2] - distanceToObject;

    // Check if the new angle goes over pi/2 radians
    motorAngles_idx_1 = std::acos(std::abs(currentmotorAnglet1) / linkLengths[2]);
    if (currentmotorAnglet1 > 0.0) {
      motorAngles_idx_1 = (1.5707963267948966 - motorAngles_idx_1) +
        1.5707963267948966;
    }
  } else {
    // Calculate current distance from the joint position c to
    // position of motor M1
    motorAngles_idx_1 = std::acos((std::sin(1.5707963267948966 -
      currentmotorAnglet1) * linkLengths[2] + distanceToObject) / linkLengths[2]);
  }

  // Calculate the angle of motor M2 so that link e is parallel
  // This function Caluclates what the angle motor M2 should have to make
  // link e parallel
  // Input:
  // motorAnglet1 = Angle of motor M1 in rad
  // motorPositionM1 =  1x2 array with the x and y coordinates of motor M1.
  // The coordinates are relative to the palm center
  // motorPositionM2 =  1x2 array with the x and y coordinates of motor M2.
  // The coordinates are relative to the palm center
  // linkLengths = 1x5 array with the lengths of all five links in the order
  // a,b,c,d,e
  // Output:
  // motorAnglet2 = Angle of motor M1 in rad
  // Set the appropriate lengths for the links
  // Calculate the position of joint B when link d lies
  // perpendicular to link e
  jointPositionB_idx_0 = linkLengths[2] * std::cos(motorAngles_idx_1) -
    linkLengths[3];
  scale = 3.3121686421112381E-170;
  currentmotorAnglet1 = std::abs(jointPositionB_idx_0 - -29.0);
  if (currentmotorAnglet1 > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    scale = currentmotorAnglet1;
  } else {
    currentmotorAnglet1 /= 3.3121686421112381E-170;
    normBM2 = currentmotorAnglet1 * currentmotorAnglet1;
  }

  absxk_tmp = std::abs(linkLengths[2] * std::sin(motorAngles_idx_1) - -38.0);
  if (absxk_tmp > scale) {
    currentmotorAnglet1 = scale / absxk_tmp;
    normBM2 = normBM2 * currentmotorAnglet1 * currentmotorAnglet1 + 1.0;
    scale = absxk_tmp;
  } else {
    currentmotorAnglet1 = absxk_tmp / scale;
    normBM2 += currentmotorAnglet1 * currentmotorAnglet1;
  }

  normBM2 = scale * std::sqrt(normBM2);
  motorAnglet2FirHalf = std::acos(((linkLengths[0] * linkLengths[0] + normBM2 *
    normBM2) - linkLengths[1] * linkLengths[1]) / (2.0 * linkLengths[0] *
    normBM2));
  currentmotorAnglet1 = std::acos(absxk_tmp / normBM2);

  // Add offset for the motors and change radians to degree
  // Convert the motor angles to an int16 and remap the angles from 0-300 to 0-65535 
  scale = rt_roundd_snf((57.295779513082323 * (0.017453292519943295 *
    (currentMotorM0Steps * 0.0045777065690089267 - 150.0)) + 150.0) * 65535.0 /
                        300.0);
  if (scale < 65536.0) {
    if (scale >= 0.0) {
      u = static_cast<unsigned short>(scale);
    } else {
      u = 0U;
    }
  } else if (scale >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[0] = u;
  scale = rt_roundd_snf((57.295779513082323 * motorAngles_idx_1 + 150.0) *
                        65535.0 / 300.0);
  if (scale < 65536.0) {
    if (scale >= 0.0) {
      u = static_cast<unsigned short>(scale);
    } else {
      u = 0U;
    }
  } else if (scale >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[1] = u;
  if (jointPositionB_idx_0 > -29.0) {
    jointPositionB_idx_0 = motorAnglet2FirHalf - currentmotorAnglet1;
  } else {
    jointPositionB_idx_0 = motorAnglet2FirHalf + currentmotorAnglet1;
  }

  scale = rt_roundd_snf((57.295779513082323 * jointPositionB_idx_0 + 48.0) *
                        65535.0 / 300.0);
  if (scale < 65536.0) {
    if (scale >= 0.0) {
      u = static_cast<unsigned short>(scale);
    } else {
      u = 0U;
    }
  } else if (scale >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[2] = u;
}

//
// File trailer for ApproachObject.cpp
//
// [EOF]
//
