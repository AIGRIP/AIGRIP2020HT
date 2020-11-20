//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  PointToLine.cpp
//
//  Code generation for function 'PointToLine'
//


// Include files
#include "PointToLine.h"
#include "PointToLine_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Function Definitions
real_T PointToLine(const emlrtStack *, const real_T singularityPoint[2], const
                   real_T possiblePosition[2], const real_T normalStableLine[2])
{
  real_T positionReachable;
  real_T y;
  boolean_T guard1 = false;
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);

  // This function takes a possible postion and angle for the gripper
  // finger to move to. Then the function decides if the position is
  // reachable or not.
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
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 0, singularityPoint[1] > 0.0)) {
    if ((covrtLogCond(&emlrtCoverageInstance, 0, 0, 0, possiblePosition[0] > 0.0)
         && covrtLogCond(&emlrtCoverageInstance, 0, 0, 1, possiblePosition[1] >
                         0.0)) || (covrtLogCond(&emlrtCoverageInstance, 0, 0, 2,
          possiblePosition[0] < 0.0) && covrtLogCond(&emlrtCoverageInstance, 0,
          0, 3, possiblePosition[1] < 0.0))) {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0, true);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 1, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 1, false);
      guard1 = true;
    }
  } else if ((covrtLogCond(&emlrtCoverageInstance, 0, 0, 4, possiblePosition[0] >
    0.0) && covrtLogCond(&emlrtCoverageInstance, 0, 0, 5, possiblePosition[1] <
                         0.0)) || (covrtLogCond(&emlrtCoverageInstance, 0, 0, 6,
    possiblePosition[0] < 0.0) && covrtLogCond(&emlrtCoverageInstance, 0, 0, 7,
               possiblePosition[1] > 0.0))) {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 1, true);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 2, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 1, false);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 2, false);
    guard1 = true;
  }

  if (guard1) {
    real_T absxk;
    real_T b_idx_0;
    real_T d;
    real_T scale;
    real_T t;
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);

    // Calculate the distances from the normals to the singularity point.
    scale = 3.3121686421112381E-170;
    d = normalStableLine[0] - possiblePosition[0];
    b_idx_0 = d * singularityPoint[1];
    absxk = muDoubleScalarAbs(d);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }

    d = normalStableLine[1] - possiblePosition[1];
    absxk = muDoubleScalarAbs(d);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    y = scale * muDoubleScalarSqrt(y);

    // Pick the first distance in the list that is lower than the error margin
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 3, muDoubleScalarAbs(((d *
            singularityPoint[0] - b_idx_0) + normalStableLine[0] *
           possiblePosition[1]) - normalStableLine[1] * possiblePosition[0]) / y
                   < 3.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 4);
      positionReachable = 1.0;
    }
  }

  return positionReachable;
}

// End of code generation (PointToLine.cpp)
