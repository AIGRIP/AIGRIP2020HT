//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: InverseKinematicsPreshape.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 18-Nov-2020 08:59:29
//

// Include Files
#include "InverseKinematicsPreshape.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <cfloat>
#include <cmath>

// Function Declarations
static double rt_atan2d_snf(double u0, double u1);
static double rt_remd_snf(double u0, double u1);
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
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_remd_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = rtNaN;
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    double b_u1;
    if (u1 < 0.0) {
      b_u1 = std::ceil(u1);
    } else {
      b_u1 = std::floor(u1);
    }

    if ((u1 != 0.0) && (u1 != b_u1)) {
      b_u1 = std::abs(u0 / u1);
      if (!(std::abs(b_u1 - std::floor(b_u1 + 0.5)) > DBL_EPSILON * b_u1)) {
        y = 0.0 * u0;
      } else {
        y = std::fmod(u0, u1);
      }
    } else {
      y = std::fmod(u0, u1);
    }
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
//                short motorAngles[3]
// Return Type  : void
//
void InverseKinematicsPreshape(const double linkLengths[5], const double
  desiredPosition[2], const double normalStableLine[2], short motorAngles[3])
{
  double directionPosition[2];
  double absx;
  double b_x;
  double jointPositionB_idx_0;
  double motorAngles_idx_0;
  double motorAngles_idx_1;
  double normBM2;
  double scale;
  double t;
  double x;
  double x_tmp;
  int k;
  short i;
  bool exitg1;
  bool y;

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
  // Output:
  // motorAngles = 1X3 array with three motor angles one for each motro in a
  // finger. The order of the motors in the array is M0,M1,M2. The angles are
  // remaped from 0-359 to 0-65535 this is to fill out a short as much as
  // possible.
  // Set the posistion of motor M0 relative to the center of the palm
  // Make the direction relate to M0 position instead of palm center
  directionPosition[0] = normalStableLine[0] - 10.0;
  directionPosition[1] = normalStableLine[1] - 10.0;

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
    directionPosition[0] = (normalStableLine[0] + desiredPosition[0]) - 10.0;
    directionPosition[1] = (normalStableLine[1] + desiredPosition[1]) - 10.0;
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
  if (rtIsInf(motorAngles_idx_0) || rtIsNaN(motorAngles_idx_0)) {
    scale = rtNaN;
    x = rtNaN;
  } else {
    signed char n;
    x_tmp = rt_remd_snf(motorAngles_idx_0, 360.0);
    scale = x_tmp;
    absx = std::abs(x_tmp);
    if (absx > 180.0) {
      if (x_tmp > 0.0) {
        scale = x_tmp - 360.0;
      } else {
        scale = x_tmp + 360.0;
      }

      absx = std::abs(scale);
    }

    if (absx <= 45.0) {
      scale *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (scale > 0.0) {
        scale = 0.017453292519943295 * (scale - 90.0);
        n = 1;
      } else {
        scale = 0.017453292519943295 * (scale + 90.0);
        n = -1;
      }
    } else if (scale > 0.0) {
      scale = 0.017453292519943295 * (scale - 180.0);
      n = 2;
    } else {
      scale = 0.017453292519943295 * (scale + 180.0);
      n = -2;
    }

    if (n == 0) {
      scale = std::cos(scale);
    } else if (n == 1) {
      scale = -std::sin(scale);
    } else if (n == -1) {
      scale = std::sin(scale);
    } else {
      scale = -std::cos(scale);
    }

    absx = std::abs(x_tmp);
    if (absx > 180.0) {
      if (x_tmp > 0.0) {
        x_tmp -= 360.0;
      } else {
        x_tmp += 360.0;
      }

      absx = std::abs(x_tmp);
    }

    if (absx <= 45.0) {
      x_tmp *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (x_tmp > 0.0) {
        x_tmp = 0.017453292519943295 * (x_tmp - 90.0);
        n = 1;
      } else {
        x_tmp = 0.017453292519943295 * (x_tmp + 90.0);
        n = -1;
      }
    } else if (x_tmp > 0.0) {
      x_tmp = 0.017453292519943295 * (x_tmp - 180.0);
      n = 2;
    } else {
      x_tmp = 0.017453292519943295 * (x_tmp + 180.0);
      n = -2;
    }

    if (n == 0) {
      x = std::sin(x_tmp);
    } else if (n == 1) {
      x = std::cos(x_tmp);
    } else if (n == -1) {
      x = -std::cos(x_tmp);
    } else {
      x = -std::sin(x_tmp);
    }
  }

  normBM2 = scale * 10.0;
  b_x = x * 10.0;
  directionPosition[0] = scale * 10.0 + 10.0;

  // Turn all negative values to positive
  motorAngles_idx_0 = std::abs(motorAngles_idx_0);

  // Calculate the distance from motor M1 to the desired position
  x_tmp = desiredPosition[0] - (normBM2 + 10.0);
  absx = desiredPosition[1] - (b_x + 10.0);

  // Calculate the angle of motor M1 to reach the desired position
  motorAngles_idx_1 = std::acos(std::sqrt(x_tmp * x_tmp + absx * absx) /
    linkLengths[2]);

  // Check if the desired point is closer to the center than the motor M0
  // position
  scale = 3.3121686421112381E-170;
  absx = std::abs(0.0 - desiredPosition[0]);
  if (absx > 3.3121686421112381E-170) {
    x_tmp = 1.0;
    scale = absx;
  } else {
    t = absx / 3.3121686421112381E-170;
    x_tmp = t * t;
  }

  absx = std::abs(0.0 - desiredPosition[1]);
  if (absx > scale) {
    t = scale / absx;
    x_tmp = x_tmp * t * t + 1.0;
    scale = absx;
  } else {
    t = absx / scale;
    x_tmp += t * t;
  }

  x_tmp = scale * std::sqrt(x_tmp);
  if (x_tmp > 14.142135623730951) {
    motorAngles_idx_1 = (1.5707963267948966 - motorAngles_idx_1) +
      1.5707963267948966;
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
  jointPositionB_idx_0 = ((normBM2 + 10.0) + linkLengths[2] * std::cos
    (motorAngles_idx_1)) - linkLengths[3];
  scale = 3.3121686421112381E-170;
  absx = std::abs(jointPositionB_idx_0 - (directionPosition[0] + -29.0));
  if (absx > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    scale = absx;
  } else {
    t = absx / 3.3121686421112381E-170;
    normBM2 = t * t;
  }

  x_tmp = std::abs(((b_x + 10.0) + linkLengths[2] * std::sin(motorAngles_idx_1))
                   - ((x * 10.0 + 10.0) + -38.0));
  if (x_tmp > scale) {
    t = scale / x_tmp;
    normBM2 = normBM2 * t * t + 1.0;
    scale = x_tmp;
  } else {
    t = x_tmp / scale;
    normBM2 += t * t;
  }

  normBM2 = scale * std::sqrt(normBM2);
  scale = std::acos(((linkLengths[0] * linkLengths[0] + normBM2 * normBM2) -
                     linkLengths[1] * linkLengths[1]) / (2.0 * linkLengths[0] *
    normBM2));
  absx = std::acos(x_tmp / normBM2);

  // Add offset for the motors and change radians to degree
  // Convert the motor angles to an int16 and remap the angles from 0-359 to 0-65535 
  x_tmp = rt_roundd_snf(57.295779513082323 * motorAngles_idx_0 * 65535.0 / 300.0);
  if (x_tmp < 32768.0) {
    i = static_cast<short>(x_tmp);
  } else if (x_tmp >= 32768.0) {
    i = MAX_int16_T;
  } else {
    i = 0;
  }

  motorAngles[0] = i;
  x_tmp = rt_roundd_snf((57.295779513082323 * motorAngles_idx_1 + 150.0) *
                        65535.0 / 300.0);
  if (x_tmp < 32768.0) {
    if (x_tmp >= -32768.0) {
      i = static_cast<short>(x_tmp);
    } else {
      i = MIN_int16_T;
    }
  } else if (x_tmp >= 32768.0) {
    i = MAX_int16_T;
  } else {
    i = 0;
  }

  motorAngles[1] = i;
  if (jointPositionB_idx_0 > directionPosition[0] + -29.0) {
    jointPositionB_idx_0 = scale - absx;
  } else {
    jointPositionB_idx_0 = scale + absx;
  }

  x_tmp = rt_roundd_snf((57.295779513082323 * jointPositionB_idx_0 + 48.0) *
                        65535.0 / 300.0);
  if (x_tmp < 32768.0) {
    if (x_tmp >= -32768.0) {
      i = static_cast<short>(x_tmp);
    } else {
      i = MIN_int16_T;
    }
  } else if (x_tmp >= 32768.0) {
    i = MAX_int16_T;
  } else {
    i = 0;
  }

  motorAngles[2] = i;
}

//
// File trailer for InverseKinematicsPreshape.cpp
//
// [EOF]
//
