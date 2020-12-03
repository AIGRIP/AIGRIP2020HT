//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: InverseKinematicsPreshape.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 03-Dec-2020 12:39:31
//

// Include Files
#include "InverseKinematicsPreshape.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
static double rt_atan2d_snf(double u0, double u1);
static double rt_roundd_snf(double u);

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

    y = std::atan2(static_cast<double>(b_u0), static_cast<double>(b_u1));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

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
// Arguments    : const double desiredPosition[2]
//                const double normalStableLine[2]
//                double fingerNum
//                double offset
//                unsigned short motorAngles[3]
// Return Type  : void
//
void InverseKinematicsPreshape(const double desiredPosition[2], const double
  normalStableLine[2], double fingerNum, double offset, unsigned short
  motorAngles[3])
{
  double absxk;
  double directionPosition_idx_0;
  double directionPosition_idx_1;
  double jointPositionB_idx_0;
  double motorAngles_idx_0;
  double motorPositionM1_idx_0;
  double motorPositionM1_idx_1;
  double normBM2;
  double scale;
  double t;
  int motorPositionM0_idx_1;
  unsigned short u;

  // Input:
  // linkLengths = 1x5 array with the lengths of all five links in the order
  // a,b,c,d,e
  // desiredPosition =  1x2 array with the x and y coordinates of the point
  // that the gripper should reach. The coordinates are relative to the palm
  // center
  // normalStableLine = 1x2 array with the x and y coordinates that together
  // with the possiblePosition creates the line which represents the
  // direction the finger should be facing. The coordinates are
  // relative to the palm center
  // fingerNum = number to determine what finger is getting calculated.
  // The number is between 0-2. 0 is for the stationary finger and
  // then the sequense countines clockwise
  // offset = distance the motor should move back. offset is in mm
  // Output:
  // motorAngles = 1X3 array with three motor angles one for each motor in a
  // finger. The order of the motors in the array is M0,M1,M2.
  if (fingerNum != 0.0) {
    // Set the posistion of motor M0 relative to the center of the palm
    if (fingerNum == 1.0) {
      motorPositionM0_idx_1 = 36;
    } else {
      motorPositionM0_idx_1 = -36;
    }

    // Make the direction relate to M0 position instead of palm center
    // If the directionPosition is the same as motorPositionM0 move the direction 
    // in the normal direction
    directionPosition_idx_0 = desiredPosition[0] - -23.0;
    directionPosition_idx_1 = desiredPosition[1] - static_cast<double>
      (motorPositionM0_idx_1);
    if ((desiredPosition[0] - -23.0 != 0.0) + (directionPosition_idx_1 != 0.0) ==
        0) {
      // If the desired postion is in the singularity point use the
      // normal stable line instead
      directionPosition_idx_0 = normalStableLine[0] - -23.0;
      directionPosition_idx_1 = normalStableLine[1] - static_cast<double>
        (motorPositionM0_idx_1);
    }

    // Calculate the angle that motor M0 should move to
    motorAngles_idx_0 = rt_atan2d_snf(directionPosition_idx_1,
      directionPosition_idx_0);

    // Change the angles to be between 0-90 degree
    if (motorAngles_idx_0 < -1.5707963267948966) {
      motorAngles_idx_0 += 3.1415926535897931;
    } else {
      if (motorAngles_idx_0 > 1.5707963267948966) {
        motorAngles_idx_0 -= 3.1415926535897931;
      }
    }

    // Calculate the distance from the palm center to the poistions
    // of motor M1 and M2                                                                                                                                                                                                                                                                                                                  
    if (fingerNum == 1.0) {
      motorPositionM1_idx_0 = -23.0 - std::cos(motorAngles_idx_0) * 38.0;
      motorPositionM1_idx_1 = static_cast<double>(motorPositionM0_idx_1) - -std::
        sin(motorAngles_idx_0) * 38.0;
    } else {
      motorPositionM1_idx_0 = -23.0 - std::cos(motorAngles_idx_0) * 38.0;
      motorPositionM1_idx_1 = static_cast<double>(motorPositionM0_idx_1) - std::
        sin(motorAngles_idx_0) * 38.0;
    }
  } else {
    motorAngles_idx_0 = 0.0;
    motorPositionM1_idx_0 = 64.0;
    motorPositionM1_idx_1 = 0.0;
  }

  // Turn all negative values to positive
  motorAngles_idx_0 = std::abs(motorAngles_idx_0);

  // Calculate the distance from motor M1 to the desired position
  directionPosition_idx_0 = desiredPosition[0] - motorPositionM1_idx_0;
  directionPosition_idx_1 = desiredPosition[1] - motorPositionM1_idx_1;
  directionPosition_idx_0 = std::sqrt(directionPosition_idx_0 *
    directionPosition_idx_0 + directionPosition_idx_1 * directionPosition_idx_1);
  motorPositionM0_idx_1 = 1;
  scale = 3.3121686421112381E-170;
  directionPosition_idx_1 = 3.3121686421112381E-170;
  absxk = std::abs(0.0 - desiredPosition[0]);
  if (absxk > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    normBM2 = t * t;
  }

  absxk = std::abs(0.0 - motorPositionM1_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    jointPositionB_idx_0 = 1.0;
    directionPosition_idx_1 = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    jointPositionB_idx_0 = t * t;
  }

  absxk = std::abs(0.0 - desiredPosition[1]);
  if (absxk > scale) {
    t = scale / absxk;
    normBM2 = normBM2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    normBM2 += t * t;
  }

  absxk = std::abs(0.0 - motorPositionM1_idx_1);
  if (absxk > directionPosition_idx_1) {
    t = directionPosition_idx_1 / absxk;
    jointPositionB_idx_0 = jointPositionB_idx_0 * t * t + 1.0;
    directionPosition_idx_1 = absxk;
  } else {
    t = absxk / directionPosition_idx_1;
    jointPositionB_idx_0 += t * t;
  }

  normBM2 = scale * std::sqrt(normBM2);
  jointPositionB_idx_0 = directionPosition_idx_1 * std::sqrt
    (jointPositionB_idx_0);
  if (normBM2 > jointPositionB_idx_0) {
    motorPositionM0_idx_1 = 0;
    directionPosition_idx_0 += offset;
  } else {
    directionPosition_idx_0 -= offset;
    if (directionPosition_idx_0 < 0.0) {
      motorPositionM0_idx_1 = 0;
      directionPosition_idx_0 = std::abs(directionPosition_idx_0);
    }
  }

  // Calculate the angle of motor M1 to reach the desired position
  motorPositionM1_idx_1 = std::acos(directionPosition_idx_0 / 60.0);

  // Check if the desired point is closer to the center than the motor M0
  // position
  if (motorPositionM0_idx_1 == 0) {
    motorPositionM1_idx_1 = (1.5707963267948966 - motorPositionM1_idx_1) +
      1.5707963267948966;
  }

  if (motorPositionM1_idx_1 > 2.0943951023931953) {
    motorPositionM1_idx_1 = 2.0943951023931953;
  } else {
    if (motorPositionM1_idx_1 < 0.59341194567807209) {
      motorPositionM1_idx_1 = 0.59341194567807209;
    }
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
  jointPositionB_idx_0 = (motorPositionM1_idx_0 + 60.0 * std::cos
    (motorPositionM1_idx_1)) - 35.0;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(jointPositionB_idx_0 - (motorPositionM1_idx_0 - 29.0));
  if (absxk > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    normBM2 = t * t;
  }

  directionPosition_idx_0 = std::abs(60.0 * std::sin(motorPositionM1_idx_1) -
    -38.0);
  if (directionPosition_idx_0 > scale) {
    t = scale / directionPosition_idx_0;
    normBM2 = normBM2 * t * t + 1.0;
    scale = directionPosition_idx_0;
  } else {
    t = directionPosition_idx_0 / scale;
    normBM2 += t * t;
  }

  normBM2 = scale * std::sqrt(normBM2);
  directionPosition_idx_1 = std::acos(((normBM2 * normBM2 + 625.0) - 9025.0) /
    (50.0 * normBM2));
  directionPosition_idx_0 = std::acos(directionPosition_idx_0 / normBM2);
  if (jointPositionB_idx_0 > motorPositionM1_idx_0 - 29.0) {
    directionPosition_idx_1 -= directionPosition_idx_0;
  } else {
    directionPosition_idx_1 += directionPosition_idx_0;
  }

  // Add offset for the motors and change radians to degree
  if (fingerNum == 0.0) {
    motorAngles_idx_0 *= 57.295779513082323;
    motorPositionM1_idx_1 = 150.0 + 57.295779513082323 * motorPositionM1_idx_1;
    directionPosition_idx_1 = 60.0 + 57.295779513082323 *
      directionPosition_idx_1;
  } else if (fingerNum == 1.0) {
    motorAngles_idx_0 = 150.0 + 57.295779513082323 * motorAngles_idx_0;
    motorPositionM1_idx_1 = 150.0 + 57.295779513082323 * motorPositionM1_idx_1;
    directionPosition_idx_1 = 60.0 + 57.295779513082323 *
      directionPosition_idx_1;
  } else {
    motorAngles_idx_0 *= 57.295779513082323;
    motorPositionM1_idx_1 = 150.0 + 57.295779513082323 * motorPositionM1_idx_1;
    directionPosition_idx_1 = 60.0 + 57.295779513082323 *
      directionPosition_idx_1;
    motorAngles_idx_0 = (90.0 - motorAngles_idx_0) + 60.0;
  }

  // Convert the motor angles to an int16 and remap the angles from 0-300 to 0-65535 
  directionPosition_idx_0 = rt_roundd_snf(motorAngles_idx_0 * 218.45);
  if (directionPosition_idx_0 < 65536.0) {
    if (directionPosition_idx_0 >= 0.0) {
      u = static_cast<unsigned short>(directionPosition_idx_0);
    } else {
      u = 0U;
    }
  } else if (directionPosition_idx_0 >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[0] = u;
  directionPosition_idx_0 = rt_roundd_snf(motorPositionM1_idx_1 * 218.45);
  if (directionPosition_idx_0 < 65536.0) {
    u = static_cast<unsigned short>(directionPosition_idx_0);
  } else {
    u = 0U;
  }

  motorAngles[1] = u;
  directionPosition_idx_0 = rt_roundd_snf(directionPosition_idx_1 * 218.45);
  if (directionPosition_idx_0 < 65536.0) {
    if (directionPosition_idx_0 >= 0.0) {
      u = static_cast<unsigned short>(directionPosition_idx_0);
    } else {
      u = 0U;
    }
  } else if (directionPosition_idx_0 >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[2] = u;
}

//
// File trailer for InverseKinematicsPreshape.cpp
//
// [EOF]
//
