//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  ApproachObject.cpp
//
//  Code generation for function 'ApproachObject'
//


// Include files
#include "ApproachObject.h"
#include <cmath>

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions
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

void ApproachObject(const double linkLengths[5], unsigned short
                    currentMotorM0Steps, unsigned short currentMotorM1Steps,
                    double distanceToObject, unsigned short motorAngles[3])
{
  int q0;
  unsigned int qY;
  double currentmotorAnglet1;
  double newMotorM1Rad;
  double jointPositionB_idx_0;
  double scale;
  double normBM2;
  double absxk_tmp;
  double motorAnglet2FirHalf;
  unsigned short u;

  // This function calculates how every motor in a finger should be rotated for
  // it to reach a certain point with a certain angle and with the last link
  // being parallel to the palm of the gripper
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
  q0 = static_cast<int>(rt_roundd_snf(static_cast<double>(currentMotorM1Steps) *
    0.0045777065690089267));
  qY = q0 - 150U;
  if (qY > static_cast<unsigned int>(q0)) {
    qY = 0U;
  }

  currentmotorAnglet1 = 0.017453292519943295 * static_cast<double>(static_cast<
    int>(qY));
  motorAngles[0] = currentMotorM0Steps;

  // Calculate the new angle of motor M1
  if (currentmotorAnglet1 > 1.5707963267948966) {
    // Calculate current distance from the joint position c to
    // position of motor M1
    currentmotorAnglet1 = std::sin(currentmotorAnglet1 - 1.5707963267948966) *
      linkLengths[2] - distanceToObject;

    // Check if the new angle goes over pi/2 radians
    newMotorM1Rad = std::acos(std::abs(currentmotorAnglet1) / linkLengths[2]);
    if (currentmotorAnglet1 > 0.0) {
      newMotorM1Rad = (1.5707963267948966 - newMotorM1Rad) + 1.5707963267948966;
    }
  } else {
    // Calculate current distance from the joint position c to
    // position of motor M1
    newMotorM1Rad = std::acos((std::sin(1.5707963267948966 - currentmotorAnglet1)
      * linkLengths[2] + distanceToObject) / linkLengths[2]);
  }

  // Calculate the angle of motor M2 so that link e is parallel
  // This function Caluclates what the angle motor M2 should have to make
  // link e parallel
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
  jointPositionB_idx_0 = linkLengths[2] * std::cos(newMotorM1Rad) - linkLengths
    [3];
  scale = 3.3121686421112381E-170;
  currentmotorAnglet1 = std::abs(jointPositionB_idx_0 - -29.0);
  if (currentmotorAnglet1 > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    scale = currentmotorAnglet1;
  } else {
    currentmotorAnglet1 /= 3.3121686421112381E-170;
    normBM2 = currentmotorAnglet1 * currentmotorAnglet1;
  }

  absxk_tmp = std::abs(linkLengths[2] * std::sin(newMotorM1Rad) - -38.0);
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
  scale = std::acos(absxk_tmp / normBM2);

  // Add offset for the motors and change radians to degree
  // Convert the motor angles to an uint16 and remap the angles from 0-300 to 0-65535 
  currentmotorAnglet1 = rt_roundd_snf((57.295779513082323 * newMotorM1Rad +
    150.0) * 65535.0 / 300.0);
  if (currentmotorAnglet1 < 65536.0) {
    if (currentmotorAnglet1 >= 0.0) {
      u = static_cast<unsigned short>(currentmotorAnglet1);
    } else {
      u = 0U;
    }
  } else if (currentmotorAnglet1 >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[1] = u;
  if (jointPositionB_idx_0 > -29.0) {
    jointPositionB_idx_0 = motorAnglet2FirHalf - scale;
  } else {
    jointPositionB_idx_0 = motorAnglet2FirHalf + scale;
  }

  currentmotorAnglet1 = rt_roundd_snf((57.295779513082323 * jointPositionB_idx_0
    + 60.0) * 65535.0 / 300.0);
  if (currentmotorAnglet1 < 65536.0) {
    if (currentmotorAnglet1 >= 0.0) {
      u = static_cast<unsigned short>(currentmotorAnglet1);
    } else {
      u = 0U;
    }
  } else if (currentmotorAnglet1 >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[2] = u;
}

// End of code generation (ApproachObject.cpp)
