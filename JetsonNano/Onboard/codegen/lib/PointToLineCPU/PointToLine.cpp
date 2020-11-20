//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PointToLine.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 20-Nov-2020 09:24:29
//

// Include Files
#include "PointToLine.h"
#include <cmath>

// Function Definitions
//
// This function takes a possible postion and angle for the gripper
// finger to move to. Then the function decides if the position is
// reachable or not.
// Arguments    : const double singularityPoint[2]
//                const double possiblePosition[2]
//                const double normalStableLine[2]
// Return Type  : double
//
double PointToLine(const double singularityPoint[2], const double
                   possiblePosition[2], const double normalStableLine[2])
{
  double positionReachable;
  double y;
  bool guard1 = false;

  // Input:
  // singularityPoint = 1x2 array with the x and y coordinates of the point
  // where the finger is rotating around. The coordinates are relative
  // to the palm center
  // possiblePosition =  1x2 array with the x and y coordinates of a
  // possible point for the gripper . The coordinates are
  // relative to the palm center
  // normalStableLine = 1x2 array with the x and y coordinates that together
  // with the possiblePosition creates the line which represents the
  // direction the finger should be facing. The coordinates are
  // relative to the palm center
  // Output:
  //  positionReachable = Zero if possiblePosition is not reachable.
  //  Non_zero if possiblePosition is reachable
  // Set value of error margin
  positionReachable = 0.0;

  // Check if the possiblePosition is in the right quadrant for the
  // function
  guard1 = false;
  if (singularityPoint[1] > 0.0) {
    if (((!(possiblePosition[0] > 0.0)) || (!(possiblePosition[1] > 0.0))) && ((
          !(possiblePosition[0] < 0.0)) || (!(possiblePosition[1] < 0.0)))) {
      guard1 = true;
    }
  } else {
    if (((!(possiblePosition[0] > 0.0)) || (!(possiblePosition[1] < 0.0))) && ((
          !(possiblePosition[0] < 0.0)) || (!(possiblePosition[1] > 0.0)))) {
      guard1 = true;
    }
  }

  if (guard1) {
    double absxk;
    double b_idx_0;
    double d;
    double scale;
    double t;

    // Calculate the distances from the normals to the singularity point.
    scale = 3.3121686421112381E-170;
    d = normalStableLine[0] - possiblePosition[0];
    b_idx_0 = d * singularityPoint[1];
    absxk = std::abs(d);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }

    d = normalStableLine[1] - possiblePosition[1];
    absxk = std::abs(d);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    y = scale * std::sqrt(y);

    // Pick the first distance in the list that is lower than the error margin
    if (std::abs(((d * singularityPoint[0] - b_idx_0) + normalStableLine[0] *
                  possiblePosition[1]) - normalStableLine[1] * possiblePosition
                 [0]) / y < 3.0) {
      positionReachable = 1.0;
    }
  }

  return positionReachable;
}

//
// File trailer for PointToLine.cpp
//
// [EOF]
//
