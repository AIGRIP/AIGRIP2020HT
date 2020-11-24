//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: InverseKinematicsPreshape.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Nov-2020 08:43:39
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
// Arguments    : const double linkLengths[5]
//                const double desiredPosition[2]
//                const double normalStableLine[2]
//                double fingerNum
//                unsigned short motorAngles[3]
// Return Type  : void
//
void InverseKinematicsPreshape(const double linkLengths[5], const double
  desiredPosition[2], const double normalStableLine[2], double fingerNum,
  unsigned short motorAngles[3])
{
  double directionPosition[2];
  double absxk;
  double motorAngles_idx_0;
  double motorAngles_idx_1;
  double motorAnglet2FirHalf;
  double motorPositionM0_idx_1;
  double motorPositionM1_idx_0;
  double motorPositionM1_idx_1;
  double normBM2;
  double scale;
  double t;
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
  // Output:
  // motorAngles = 1X3 array with three motor angles one for each motro in a
  // finger. The order of the motors in the array is M0,M1,M2.
  if (fingerNum != 0.0) {
    int k;
    bool exitg1;
    bool y;

    // Set the posistion of motor M0 relative to the center of the palm
    if (fingerNum == 1.0) {
      motorPositionM0_idx_1 = 36.0;
    } else {
      motorPositionM0_idx_1 = -36.0;
    }

    // Make the direction relate to M0 position instead of palm center
    directionPosition[0] = normalStableLine[0] - -20.0;
    directionPosition[1] = normalStableLine[1] - motorPositionM0_idx_1;

    // If the directionPosition is the same as motorPositionM0 move the direction 
    // in the normal direction
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(directionPosition[k] == 0.0)) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (y) {
      directionPosition[0] = (normalStableLine[0] + desiredPosition[0]) - -20.0;
      directionPosition[1] = (normalStableLine[1] + desiredPosition[1]) -
        motorPositionM0_idx_1;
    }

    // Calculate the angle that motor M0 should move to
    motorAngles_idx_0 = rt_atan2d_snf(directionPosition[1], directionPosition[0]);

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
      motorPositionM1_idx_0 = -20.0 + std::sin(motorAngles_idx_0) * 30.0;
      motorPositionM1_idx_1 = motorPositionM0_idx_1 + std::cos(motorAngles_idx_0)
        * 30.0;
    } else {
      motorPositionM1_idx_0 = -20.0 - std::sin(motorAngles_idx_0) * 30.0;
      motorPositionM1_idx_1 = motorPositionM0_idx_1 - std::cos(motorAngles_idx_0)
        * 30.0;
    }
  } else {
    motorAngles_idx_0 = 0.0;
    motorPositionM1_idx_0 = 64.0;
    motorPositionM1_idx_1 = 0.0;
  }

  // Turn all negative values to positive
  motorAngles_idx_0 = std::abs(motorAngles_idx_0);

  // Calculate the distance from motor M1 to the desired position
  motorPositionM0_idx_1 = desiredPosition[0] - motorPositionM1_idx_0;
  motorAnglet2FirHalf = desiredPosition[1] - motorPositionM1_idx_1;

  // Calculate the angle of motor M1 to reach the desired position
  motorAngles_idx_1 = std::acos(std::sqrt(motorPositionM0_idx_1 *
    motorPositionM0_idx_1 + motorAnglet2FirHalf * motorAnglet2FirHalf) /
    linkLengths[2]);

  // Check if the desired point is closer to the center than the motor M0
  // position
  scale = 3.3121686421112381E-170;
  motorPositionM0_idx_1 = 3.3121686421112381E-170;
  absxk = std::abs(0.0 - desiredPosition[0]);
  if (absxk > 3.3121686421112381E-170) {
    motorAnglet2FirHalf = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    motorAnglet2FirHalf = t * t;
  }

  absxk = std::abs(0.0 - motorPositionM1_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    motorPositionM0_idx_1 = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    normBM2 = t * t;
  }

  absxk = std::abs(0.0 - desiredPosition[1]);
  if (absxk > scale) {
    t = scale / absxk;
    motorAnglet2FirHalf = motorAnglet2FirHalf * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    motorAnglet2FirHalf += t * t;
  }

  absxk = std::abs(0.0 - motorPositionM1_idx_1);
  if (absxk > motorPositionM0_idx_1) {
    t = motorPositionM0_idx_1 / absxk;
    normBM2 = normBM2 * t * t + 1.0;
    motorPositionM0_idx_1 = absxk;
  } else {
    t = absxk / motorPositionM0_idx_1;
    normBM2 += t * t;
  }

  motorAnglet2FirHalf = scale * std::sqrt(motorAnglet2FirHalf);
  normBM2 = motorPositionM0_idx_1 * std::sqrt(normBM2);
  if (motorAnglet2FirHalf > normBM2) {
    motorAngles_idx_1 = (1.5707963267948966 - motorAngles_idx_1) +
      1.5707963267948966;
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
  motorPositionM1_idx_1 = (motorPositionM1_idx_0 + linkLengths[2] * std::cos
    (motorAngles_idx_1)) - linkLengths[3];
  scale = 3.3121686421112381E-170;
  absxk = std::abs(motorPositionM1_idx_1 - (motorPositionM1_idx_0 - 29.0));
  if (absxk > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    normBM2 = t * t;
  }

  motorPositionM0_idx_1 = std::abs(linkLengths[2] * std::sin(motorAngles_idx_1)
    - -38.0);
  if (motorPositionM0_idx_1 > scale) {
    t = scale / motorPositionM0_idx_1;
    normBM2 = normBM2 * t * t + 1.0;
    scale = motorPositionM0_idx_1;
  } else {
    t = motorPositionM0_idx_1 / scale;
    normBM2 += t * t;
  }

  normBM2 = scale * std::sqrt(normBM2);
  motorAnglet2FirHalf = std::acos(((linkLengths[0] * linkLengths[0] + normBM2 *
    normBM2) - linkLengths[1] * linkLengths[1]) / (2.0 * linkLengths[0] *
    normBM2));
  motorPositionM0_idx_1 = std::acos(motorPositionM0_idx_1 / normBM2);
  if (motorPositionM1_idx_1 > motorPositionM1_idx_0 - 29.0) {
    motorAnglet2FirHalf -= motorPositionM0_idx_1;
  } else {
    motorAnglet2FirHalf += motorPositionM0_idx_1;
  }

  // Add offset for the motors and change radians to degree
  if (fingerNum == 0.0) {
    motorAngles_idx_0 *= 57.295779513082323;
    motorAngles_idx_1 = 150.0 + 57.295779513082323 * motorAngles_idx_1;
    motorAnglet2FirHalf = 60.0 + 57.295779513082323 * motorAnglet2FirHalf;
  } else if (fingerNum == 1.0) {
    motorAngles_idx_0 *= 57.295779513082323;
    motorAngles_idx_1 = 150.0 + 57.295779513082323 * motorAngles_idx_1;
    motorAnglet2FirHalf = 60.0 + 57.295779513082323 * motorAnglet2FirHalf;
    motorAngles_idx_0 = (90.0 - motorAngles_idx_0) + 60.0;
  } else {
    motorAngles_idx_0 = 150.0 + 57.295779513082323 * motorAngles_idx_0;
    motorAngles_idx_1 = 150.0 + 57.295779513082323 * motorAngles_idx_1;
    motorAnglet2FirHalf = 60.0 + 57.295779513082323 * motorAnglet2FirHalf;
  }

  // Convert the motor angles to an int16 and remap the angles from 0-300 to 0-65535 
  motorPositionM0_idx_1 = rt_roundd_snf(motorAngles_idx_0 * 218.45);
  if (motorPositionM0_idx_1 < 65536.0) {
    if (motorPositionM0_idx_1 >= 0.0) {
      u = static_cast<unsigned short>(motorPositionM0_idx_1);
    } else {
      u = 0U;
    }
  } else if (motorPositionM0_idx_1 >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[0] = u;
  motorPositionM0_idx_1 = rt_roundd_snf(motorAngles_idx_1 * 218.45);
  if (motorPositionM0_idx_1 < 65536.0) {
    if (motorPositionM0_idx_1 >= 0.0) {
      u = static_cast<unsigned short>(motorPositionM0_idx_1);
    } else {
      u = 0U;
    }
  } else if (motorPositionM0_idx_1 >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[1] = u;
  motorPositionM0_idx_1 = rt_roundd_snf(motorAnglet2FirHalf * 218.45);
  if (motorPositionM0_idx_1 < 65536.0) {
    if (motorPositionM0_idx_1 >= 0.0) {
      u = static_cast<unsigned short>(motorPositionM0_idx_1);
    } else {
      u = 0U;
    }
  } else if (motorPositionM0_idx_1 >= 65536.0) {
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
