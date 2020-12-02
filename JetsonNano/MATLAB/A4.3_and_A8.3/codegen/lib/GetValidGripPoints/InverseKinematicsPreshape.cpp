//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: InverseKinematicsPreshape.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 11:25:48
//

// Include Files
#include "InverseKinematicsPreshape.h"
#include "GetValidGripPoints.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <math.h>

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
//                unsigned short motorAngles[3]
// Return Type  : void
//
void InverseKinematicsPreshape(const double desiredPosition[2], const double
  normalStableLine[2], double fingerNum, unsigned short motorAngles[3])
{
  double motorAngles_idx_0;
  double motorPositionM1_idx_0;
  double motorPositionM1_idx_1;
  double directionPosition[2];
  double motorAnglet2FirHalf;
  double scale;
  double motorAngles_idx_1;
  double b_scale;
  double absxk;
  double t;
  double normBM2;
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
  // motorAngles = 1X3 array with three motor angles one for each motor in a
  // finger. The order of the motors in the array is M0,M1,M2.
  if (fingerNum != 0.0) {
    int motorPositionM0_idx_1;
    bool y;
    int k;
    bool exitg1;

    // Set the posistion of motor M0 relative to the center of the palm
    if (fingerNum == 1.0) {
      motorPositionM0_idx_1 = 36;
    } else {
      motorPositionM0_idx_1 = -36;
    }

    // Make the direction relate to M0 position instead of palm center
    directionPosition[0] = normalStableLine[0] - -23.0;
    directionPosition[1] = normalStableLine[1] - static_cast<double>
      (motorPositionM0_idx_1);

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
      directionPosition[0] = (normalStableLine[0] + desiredPosition[0]) - -23.0;
      directionPosition[1] = (normalStableLine[1] + desiredPosition[1]) -
        static_cast<double>(motorPositionM0_idx_1);
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
      motorPositionM1_idx_0 = -23.0 - std::cos(motorAngles_idx_0) * 38.0;
      motorPositionM1_idx_1 = static_cast<double>(motorPositionM0_idx_1) - std::
        sin(motorAngles_idx_0) * 38.0;
    } else {
      motorPositionM1_idx_0 = -23.0 - std::cos(motorAngles_idx_0) * 38.0;
      motorPositionM1_idx_1 = static_cast<double>(motorPositionM0_idx_1) - -std::
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
  motorAnglet2FirHalf = desiredPosition[0] - motorPositionM1_idx_0;
  scale = desiredPosition[1] - motorPositionM1_idx_1;

  // Calculate the angle of motor M1 to reach the desired position
  motorAngles_idx_1 = std::acos(std::sqrt(motorAnglet2FirHalf *
    motorAnglet2FirHalf + scale * scale) / 60.0);

  // Check if the desired point is closer to the center than the motor M0
  // position
  b_scale = 3.3121686421112381E-170;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(0.0 - desiredPosition[0]);
  if (absxk > 3.3121686421112381E-170) {
    motorAnglet2FirHalf = 1.0;
    b_scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    motorAnglet2FirHalf = t * t;
  }

  absxk = std::abs(0.0 - motorPositionM1_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    normBM2 = t * t;
  }

  absxk = std::abs(0.0 - desiredPosition[1]);
  if (absxk > b_scale) {
    t = b_scale / absxk;
    motorAnglet2FirHalf = motorAnglet2FirHalf * t * t + 1.0;
    b_scale = absxk;
  } else {
    t = absxk / b_scale;
    motorAnglet2FirHalf += t * t;
  }

  absxk = std::abs(0.0 - motorPositionM1_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    normBM2 = normBM2 * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    normBM2 += t * t;
  }

  motorAnglet2FirHalf = b_scale * std::sqrt(motorAnglet2FirHalf);
  normBM2 = scale * std::sqrt(normBM2);
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
  motorPositionM1_idx_1 = (motorPositionM1_idx_0 + 60.0 * std::cos
    (motorAngles_idx_1)) - 35.0;
  b_scale = 3.3121686421112381E-170;
  absxk = std::abs(motorPositionM1_idx_1 - (motorPositionM1_idx_0 - 29.0));
  if (absxk > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    b_scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    normBM2 = t * t;
  }

  scale = std::abs(60.0 * std::sin(motorAngles_idx_1) - -38.0);
  if (scale > b_scale) {
    t = b_scale / scale;
    normBM2 = normBM2 * t * t + 1.0;
    b_scale = scale;
  } else {
    t = scale / b_scale;
    normBM2 += t * t;
  }

  normBM2 = b_scale * std::sqrt(normBM2);
  motorAnglet2FirHalf = std::acos(((normBM2 * normBM2 + 625.0) - 9025.0) / (50.0
    * normBM2));
  scale = std::acos(scale / normBM2);
  if (motorPositionM1_idx_1 > motorPositionM1_idx_0 - 29.0) {
    scale = motorAnglet2FirHalf - scale;
  } else {
    scale += motorAnglet2FirHalf;
  }

  // Add offset for the motors and change radians to degree
  if (fingerNum == 0.0) {
    motorAngles_idx_0 *= 57.295779513082323;
    motorAngles_idx_1 = 150.0 + 57.295779513082323 * motorAngles_idx_1;
    scale = 60.0 + 57.295779513082323 * scale;
  } else if (fingerNum == 1.0) {
    motorAngles_idx_0 = 150.0 + 57.295779513082323 * motorAngles_idx_0;
    motorAngles_idx_1 = 150.0 + 57.295779513082323 * motorAngles_idx_1;
    scale = 60.0 + 57.295779513082323 * scale;
  } else {
    motorAngles_idx_0 *= 57.295779513082323;
    motorAngles_idx_1 = 150.0 + 57.295779513082323 * motorAngles_idx_1;
    scale = 60.0 + 57.295779513082323 * scale;
    motorAngles_idx_0 = (90.0 - motorAngles_idx_0) + 60.0;
  }

  // Convert the motor angles to an int16 and remap the angles from 0-300 to 0-65535 
  motorAnglet2FirHalf = rt_roundd_snf(motorAngles_idx_0 * 218.45);
  if (motorAnglet2FirHalf < 65536.0) {
    if (motorAnglet2FirHalf >= 0.0) {
      u = static_cast<unsigned short>(motorAnglet2FirHalf);
    } else {
      u = 0U;
    }
  } else if (motorAnglet2FirHalf >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[0] = u;
  motorAnglet2FirHalf = rt_roundd_snf(motorAngles_idx_1 * 218.45);
  if (motorAnglet2FirHalf < 65536.0) {
    if (motorAnglet2FirHalf >= 0.0) {
      u = static_cast<unsigned short>(motorAnglet2FirHalf);
    } else {
      u = 0U;
    }
  } else if (motorAnglet2FirHalf >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[1] = u;
  motorAnglet2FirHalf = rt_roundd_snf(scale * 218.45);
  if (motorAnglet2FirHalf < 65536.0) {
    if (motorAnglet2FirHalf >= 0.0) {
      u = static_cast<unsigned short>(motorAnglet2FirHalf);
    } else {
      u = 0U;
    }
  } else if (motorAnglet2FirHalf >= 65536.0) {
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
