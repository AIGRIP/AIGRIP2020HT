//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: InverseKinematicsPreshape.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Nov-2020 10:29:43
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
//                double fingerNum
//                unsigned short motorAngles[3]
// Return Type  : void
//
void InverseKinematicsPreshape(const double linkLengths[5], const double
  desiredPosition[2], const double normalStableLine[2], double fingerNum,
  unsigned short motorAngles[3])
{
  double directionPosition[2];
  double absx;
  double b_absxk;
  double motorAngles_idx_0;
  double motorAngles_idx_1;
  double motorPositionM1_idx_0;
  double motorPositionM1_idx_1;
  double normBM2;
  double scale;
  double t;
  double x;
  int absxk;
  unsigned short u;
  signed char motorPositionM0_idx_0;
  signed char motorPositionM0_idx_1;

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
    bool exitg1;
    bool y;

    // Set the posistion of motor M0 relative to the center of the palm
    if (fingerNum == 1.0) {
      motorPositionM0_idx_0 = -20;
      motorPositionM0_idx_1 = 36;
    } else {
      motorPositionM0_idx_0 = -20;
      motorPositionM0_idx_1 = -36;
    }

    // Make the direction relate to M0 position instead of palm center
    directionPosition[0] = normalStableLine[0] - -20.0;
    directionPosition[1] = normalStableLine[1] - static_cast<double>
      (motorPositionM0_idx_1);

    // If the directionPosition is the same as motorPositionM0 move the direction 
    // in the normal direction
    y = true;
    absxk = 0;
    exitg1 = false;
    while ((!exitg1) && (absxk < 2)) {
      if (!(directionPosition[absxk] == 0.0)) {
        y = false;
        exitg1 = true;
      } else {
        absxk++;
      }
    }

    if (y) {
      directionPosition[0] = (normalStableLine[0] + desiredPosition[0]) - -20.0;
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
    if (rtIsInf(motorAngles_idx_0) || rtIsNaN(motorAngles_idx_0)) {
      x = rtNaN;
      normBM2 = rtNaN;
    } else {
      signed char n;
      normBM2 = rt_remd_snf(motorAngles_idx_0, 360.0);
      x = normBM2;
      absx = std::abs(normBM2);
      if (absx > 180.0) {
        if (normBM2 > 0.0) {
          x = normBM2 - 360.0;
        } else {
          x = normBM2 + 360.0;
        }

        absx = std::abs(x);
      }

      if (absx <= 45.0) {
        x *= 0.017453292519943295;
        n = 0;
      } else if (absx <= 135.0) {
        if (x > 0.0) {
          x = 0.017453292519943295 * (x - 90.0);
          n = 1;
        } else {
          x = 0.017453292519943295 * (x + 90.0);
          n = -1;
        }
      } else if (x > 0.0) {
        x = 0.017453292519943295 * (x - 180.0);
        n = 2;
      } else {
        x = 0.017453292519943295 * (x + 180.0);
        n = -2;
      }

      if (n == 0) {
        x = std::cos(x);
      } else if (n == 1) {
        x = -std::sin(x);
      } else if (n == -1) {
        x = std::sin(x);
      } else {
        x = -std::cos(x);
      }

      absx = std::abs(normBM2);
      if (absx > 180.0) {
        if (normBM2 > 0.0) {
          normBM2 -= 360.0;
        } else {
          normBM2 += 360.0;
        }

        absx = std::abs(normBM2);
      }

      if (absx <= 45.0) {
        normBM2 *= 0.017453292519943295;
        n = 0;
      } else if (absx <= 135.0) {
        if (normBM2 > 0.0) {
          normBM2 = 0.017453292519943295 * (normBM2 - 90.0);
          n = 1;
        } else {
          normBM2 = 0.017453292519943295 * (normBM2 + 90.0);
          n = -1;
        }
      } else if (normBM2 > 0.0) {
        normBM2 = 0.017453292519943295 * (normBM2 - 180.0);
        n = 2;
      } else {
        normBM2 = 0.017453292519943295 * (normBM2 + 180.0);
        n = -2;
      }

      if (n == 0) {
        normBM2 = std::sin(normBM2);
      } else if (n == 1) {
        normBM2 = std::cos(normBM2);
      } else if (n == -1) {
        normBM2 = -std::cos(normBM2);
      } else {
        normBM2 = -std::sin(normBM2);
      }
    }

    motorPositionM1_idx_0 = -20.0 + x * 30.0;
    motorPositionM1_idx_1 = static_cast<double>(motorPositionM0_idx_1) + normBM2
      * 30.0;
  } else {
    motorAngles_idx_0 = 0.0;
    motorPositionM0_idx_0 = 64;
    motorPositionM1_idx_0 = 64.0;
    motorPositionM0_idx_1 = 0;
    motorPositionM1_idx_1 = 0.0;
  }

  // Turn all negative values to positive
  motorAngles_idx_0 = std::abs(motorAngles_idx_0);

  // Calculate the distance from motor M1 to the desired position
  normBM2 = desiredPosition[0] - motorPositionM1_idx_0;
  absx = desiredPosition[1] - motorPositionM1_idx_1;

  // Calculate the angle of motor M1 to reach the desired position
  motorAngles_idx_1 = std::acos(std::sqrt(normBM2 * normBM2 + absx * absx) /
    linkLengths[2]);

  // Check if the desired point is closer to the center than the motor M0
  // position
  scale = 3.3121686421112381E-170;
  absx = 3.3121686421112381E-170;
  b_absxk = std::abs(0.0 - desiredPosition[0]);
  if (b_absxk > 3.3121686421112381E-170) {
    x = 1.0;
    scale = b_absxk;
  } else {
    t = b_absxk / 3.3121686421112381E-170;
    x = t * t;
  }

  absxk = static_cast<int>(std::abs(-static_cast<double>(motorPositionM0_idx_0)));
  if (absxk > 3.3121686421112381E-170) {
    t = 3.3121686421112381E-170 / static_cast<double>(absxk);
    normBM2 = 0.0 * t * t + 1.0;
    absx = absxk;
  } else {
    t = static_cast<double>(absxk) / 3.3121686421112381E-170;
    normBM2 = t * t;
  }

  b_absxk = std::abs(0.0 - desiredPosition[1]);
  if (b_absxk > scale) {
    t = scale / b_absxk;
    x = x * t * t + 1.0;
    scale = b_absxk;
  } else {
    t = b_absxk / scale;
    x += t * t;
  }

  absxk = static_cast<int>(std::abs(-static_cast<double>(motorPositionM0_idx_1)));
  if (absxk > absx) {
    t = absx / static_cast<double>(absxk);
    normBM2 = normBM2 * t * t + 1.0;
    absx = absxk;
  } else {
    t = static_cast<double>(absxk) / absx;
    normBM2 += t * t;
  }

  x = scale * std::sqrt(x);
  normBM2 = absx * std::sqrt(normBM2);
  if (x > normBM2) {
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
  directionPosition[0] = (motorPositionM1_idx_0 + linkLengths[2] * std::cos
    (motorAngles_idx_1)) - linkLengths[3];
  scale = 3.3121686421112381E-170;
  b_absxk = std::abs(directionPosition[0] - (motorPositionM1_idx_0 + -29.0));
  if (b_absxk > 3.3121686421112381E-170) {
    normBM2 = 1.0;
    scale = b_absxk;
  } else {
    t = b_absxk / 3.3121686421112381E-170;
    normBM2 = t * t;
  }

  x = std::abs((motorPositionM1_idx_1 + linkLengths[2] * std::sin
                (motorAngles_idx_1)) - (motorPositionM1_idx_1 + -38.0));
  if (x > scale) {
    t = scale / x;
    normBM2 = normBM2 * t * t + 1.0;
    scale = x;
  } else {
    t = x / scale;
    normBM2 += t * t;
  }

  normBM2 = scale * std::sqrt(normBM2);
  absx = std::acos(((linkLengths[0] * linkLengths[0] + normBM2 * normBM2) -
                    linkLengths[1] * linkLengths[1]) / (2.0 * linkLengths[0] *
    normBM2));
  normBM2 = std::acos(x / normBM2);
  if (directionPosition[0] > motorPositionM1_idx_0 + -29.0) {
    absx -= normBM2;
  } else {
    absx += normBM2;
  }

  // Add offset for the motors and change radians to degree
  if (fingerNum == 0.0) {
    motorAngles_idx_0 *= 57.295779513082323;
    motorAngles_idx_1 = 150.0 + 57.295779513082323 * motorAngles_idx_1;
    absx = 48.0 + 57.295779513082323 * absx;
  } else if (fingerNum == 1.0) {
    motorAngles_idx_0 = -150.0 + 57.295779513082323 * motorAngles_idx_0;
    motorAngles_idx_1 = 150.0 + 57.295779513082323 * motorAngles_idx_1;
    absx = 48.0 + 57.295779513082323 * absx;
  } else {
    motorAngles_idx_0 = 150.0 + 57.295779513082323 * motorAngles_idx_0;
    motorAngles_idx_1 = 150.0 + 57.295779513082323 * motorAngles_idx_1;
    absx = 48.0 + 57.295779513082323 * absx;
  }

  // Convert the motor angles to an int16 and remap the angles from 0-300 to 0-65535 
  normBM2 = rt_roundd_snf(57.295779513082323 * motorAngles_idx_0 * 65535.0 /
    300.0);
  if (normBM2 < 65536.0) {
    if (normBM2 >= 0.0) {
      u = static_cast<unsigned short>(normBM2);
    } else {
      u = 0U;
    }
  } else if (normBM2 >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[0] = u;
  normBM2 = rt_roundd_snf((57.295779513082323 * motorAngles_idx_1 + 150.0) *
    65535.0 / 300.0);
  if (normBM2 < 65536.0) {
    if (normBM2 >= 0.0) {
      u = static_cast<unsigned short>(normBM2);
    } else {
      u = 0U;
    }
  } else if (normBM2 >= 65536.0) {
    u = MAX_uint16_T;
  } else {
    u = 0U;
  }

  motorAngles[1] = u;
  normBM2 = rt_roundd_snf((57.295779513082323 * absx + 48.0) * 65535.0 / 300.0);
  if (normBM2 < 65536.0) {
    if (normBM2 >= 0.0) {
      u = static_cast<unsigned short>(normBM2);
    } else {
      u = 0U;
    }
  } else if (normBM2 >= 65536.0) {
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
