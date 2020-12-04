//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: StableLine.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//

// Include Files
#include "StableLine.h"
#include "PriorityOfGripPoints.h"
#include "StableLine_data.h"
#include "StableLine_initialize.h"
#include "extremeKElements.h"
#include "rt_nonfinite.h"
#include "unique.h"
#include <cmath>
#include <cstring>

// Function Definitions

//
// stableLine finds the required orientaions for the gripper to grasp an object.
//    degreesMeasured - Containes the angles for each measurement point.
//    YCoordinates    - Containes the cartesean Y-coordinate for each angle.
//                    It has the same indexes as degreesMeasured.
//    XCoordinates    - Containes the cartesean X-coordinate for each angle.
//                    It has the same indexes as degreesMeasured.
//    targetPoint     - Returns the position of the all target points. The
//                    number after letter F indicates which finger the target
//                    points belong to. X and Y indicate which coordinate
//                    vector it is.
//    normalPoint     - Returns a normal point for each of the target points. The
//                    number after letter F indicates which finger the target
//                    points belong to. X and Y indicate which coordinate
//                    vector it is.
//    signatureRadiusTargetF - Is the signature for finger 1 and 2.
// Arguments    : const double degreesMeasured[360]
//                const double YCoordinates[360]
//                const double XCoordinates[360]
//                const double signatureRadius[360]
//                double targetPointF1Y[11]
//                double targetPointF1X[11]
//                double normalPointF1Y[11]
//                double normalPointF1X[11]
//                double targetPointF2Y[11]
//                double targetPointF2X[11]
//                double normalPointF2Y[11]
//                double normalPointF2X[11]
//                double *targetPointF0Y
//                double *targetPointF0X
//                double *normalPointF0Y
//                double *normalPointF0X
//                double signatureRadiusTargetF1[11]
//                double signatureRadiusTargetF2[11]
// Return Type  : void
//
void StableLine(const double [360], const double YCoordinates[360], const double
                XCoordinates[360], const double signatureRadius[360], double
                targetPointF1Y[11], double targetPointF1X[11], double
                normalPointF1Y[11], double normalPointF1X[11], double
                targetPointF2Y[11], double targetPointF2X[11], double
                normalPointF2Y[11], double normalPointF2X[11], double
                *targetPointF0Y, double *targetPointF0X, double *normalPointF0Y,
                double *normalPointF0X, double signatureRadiusTargetF1[11],
                double signatureRadiusTargetF2[11])
{
  int k;
  double b_XCoordinates[720];
  double uniquePoints_data[720];
  int uniquePoints_size[2];
  int loop_ub;
  int nx;
  int ii;
  double b_signatureRadius[11];
  int XCoordinates_tmp;
  double a_data[360];
  double y_data[360];
  double b_y_data[360];
  int a_size[1];
  int b_loop_ub;
  int idx_data[7];
  int idx_size[1];
  double b_data[7];
  int b_size[1];
  double angleDirection;
  if (!isInitialized_StableLine) {
    StableLine_initialize();
  }

  // Offset in radius for the normal points.
  //  Resolution of possible grip positions in degrees.
  //  Defines the workspace in angles from the center of the gripper for
  //  of each finger. The first finger has the workspace in angles:
  //  "90 - atand(36/(23+38+(60*cosd(60))-11))" to "180-atand(23/(36+38+(60*cosd(60))-11))" 
  //  And the second finger.
  //  "90 - atand(36/(23+38+(60*cosd(60))-11))" to "180-atand(23/(36+38+(60*cosd(60))-11))" 
  //  The finger 0 (thumb) only has one direction.
  //  The number of neighbours used to get the polynomal.
  for (k = 0; k < 360; k++) {
    b_XCoordinates[k] = XCoordinates[k];
    b_XCoordinates[k + 360] = YCoordinates[k];
  }

  unique_rows(b_XCoordinates, uniquePoints_data, uniquePoints_size);

  //  Indexes of angular points for finger 1.
  //  Size of index buffer.
  //  Allocate memory to select samples.
  //  Allocate memory for normal points.
  //  Allocate memory for normal points.
  //  Calculates the normal for all target points for finger 1.
  //  Signature for finger 1.
  //  Set the priority order of the target points.
  loop_ub = uniquePoints_size[0];
  nx = uniquePoints_size[0];
  for (ii = 0; ii < 11; ii++) {
    //  Calculates the euclodian distance to target.
    //  Get the closest unique indecies to the target point.
    XCoordinates_tmp = 5 * ii + 114;
    for (k = 0; k < loop_ub; k++) {
      a_data[k] = uniquePoints_data[k] - XCoordinates[XCoordinates_tmp];
    }

    for (k = 0; k < loop_ub; k++) {
      y_data[k] = a_data[k] * a_data[k];
    }

    for (k = 0; k < nx; k++) {
      a_data[k] = uniquePoints_data[k + uniquePoints_size[0]] -
        YCoordinates[XCoordinates_tmp];
    }

    for (k = 0; k < nx; k++) {
      b_y_data[k] = a_data[k] * a_data[k];
    }

    for (k = 0; k < loop_ub; k++) {
      y_data[k] += b_y_data[k];
    }

    if (loop_ub == 0) {
      a_size[0] = 0;
    } else {
      a_size[0] = loop_ub;
      if (0 <= loop_ub - 1) {
        std::memcpy(&a_data[0], &y_data[0], loop_ub * sizeof(double));
      }
    }

    if (7 <= a_size[0]) {
      b_loop_ub = 7;
    } else {
      b_loop_ub = a_size[0];
    }

    exkib(a_data, a_size, b_loop_ub, idx_data, idx_size, b_data, b_size);
    b_loop_ub = idx_size[0];
    for (k = 0; k < b_loop_ub; k++) {
      b_data[k] = idx_data[k];
    }

    //  Get the length vectors to neighbour
    //  Get the angle from target to neighbour.
    b_loop_ub = static_cast<int>(b_data[6]) - 1;
    angleDirection = std::atan((YCoordinates[XCoordinates_tmp] -
      uniquePoints_data[b_loop_ub + uniquePoints_size[0]]) /
      (XCoordinates[XCoordinates_tmp] - uniquePoints_data[b_loop_ub]));

    //  Get the normal point to the target point.
    normalPointF1X[ii] = XCoordinates[XCoordinates_tmp] + 50.0 * std::cos
      (angleDirection + 1.5707963267948966);
    normalPointF1Y[ii] = YCoordinates[XCoordinates_tmp] + 50.0 * std::sin
      (angleDirection + 1.5707963267948966);
    signatureRadiusTargetF1[ii] = signatureRadius[XCoordinates_tmp];
    targetPointF1Y[ii] = YCoordinates[XCoordinates_tmp];
    targetPointF1X[ii] = XCoordinates[XCoordinates_tmp];
    b_signatureRadius[ii] = signatureRadius[XCoordinates_tmp];
  }

  PriorityOfGripPoints(b_signatureRadius, targetPointF1Y, targetPointF1X,
                       normalPointF1Y, normalPointF1X);

  //  Indexes of angular points for finger 2.
  //  Allocate memory for normal points.
  //  Allocate memory for normal points.
  //  Calculates the normal for all target points for finger 1.
  //  Signature for finger 2.
  //  Set the priority order of the target points.
  loop_ub = uniquePoints_size[0];
  nx = uniquePoints_size[0];
  for (ii = 0; ii < 11; ii++) {
    //  Calculates the euclodian distance to target.
    //  Get the closest unique indecies to the target point.
    XCoordinates_tmp = 5 * ii + 204;
    for (k = 0; k < loop_ub; k++) {
      a_data[k] = uniquePoints_data[k] - XCoordinates[XCoordinates_tmp];
    }

    for (k = 0; k < loop_ub; k++) {
      y_data[k] = a_data[k] * a_data[k];
    }

    for (k = 0; k < nx; k++) {
      a_data[k] = uniquePoints_data[k + uniquePoints_size[0]] -
        YCoordinates[XCoordinates_tmp];
    }

    for (k = 0; k < nx; k++) {
      b_y_data[k] = a_data[k] * a_data[k];
    }

    for (k = 0; k < loop_ub; k++) {
      y_data[k] += b_y_data[k];
    }

    if (loop_ub == 0) {
      a_size[0] = 0;
    } else {
      a_size[0] = loop_ub;
      if (0 <= loop_ub - 1) {
        std::memcpy(&a_data[0], &y_data[0], loop_ub * sizeof(double));
      }
    }

    if (7 <= a_size[0]) {
      b_loop_ub = 7;
    } else {
      b_loop_ub = a_size[0];
    }

    exkib(a_data, a_size, b_loop_ub, idx_data, idx_size, b_data, b_size);
    b_loop_ub = idx_size[0];
    for (k = 0; k < b_loop_ub; k++) {
      b_data[k] = idx_data[k];
    }

    //  Get the length vectors to neighbour
    //  Get the angle from target to neighbour.
    b_loop_ub = static_cast<int>(b_data[6]) - 1;
    angleDirection = std::atan((YCoordinates[XCoordinates_tmp] -
      uniquePoints_data[b_loop_ub + uniquePoints_size[0]]) /
      (XCoordinates[XCoordinates_tmp] - uniquePoints_data[b_loop_ub]));

    //  Get the normal point to the target point.
    normalPointF2X[ii] = XCoordinates[XCoordinates_tmp] + 50.0 * std::cos
      (angleDirection + 1.5707963267948966);
    normalPointF2Y[ii] = YCoordinates[XCoordinates_tmp] + 50.0 * std::sin
      (angleDirection + 1.5707963267948966);
    signatureRadiusTargetF2[ii] = signatureRadius[XCoordinates_tmp];
    targetPointF2Y[ii] = YCoordinates[XCoordinates_tmp];
    targetPointF2X[ii] = XCoordinates[XCoordinates_tmp];
    b_signatureRadius[ii] = signatureRadius[XCoordinates_tmp];
  }

  PriorityOfGripPoints(b_signatureRadius, targetPointF2Y, targetPointF2X,
                       normalPointF2Y, normalPointF2X);

  //  Get normal for finger 0.
  *targetPointF0X = XCoordinates[0];
  *targetPointF0Y = YCoordinates[0];

  //  Calculates the euclodian distance to target.
  //  Get the closest unique indecies to the target point.
  loop_ub = uniquePoints_size[0];
  for (k = 0; k < loop_ub; k++) {
    a_data[k] = uniquePoints_data[k] - XCoordinates[0];
  }

  b_loop_ub = uniquePoints_size[0];
  nx = uniquePoints_size[0];
  for (k = 0; k < nx; k++) {
    y_data[k] = a_data[k] * a_data[k];
  }

  loop_ub = uniquePoints_size[0];
  for (k = 0; k < loop_ub; k++) {
    a_data[k] = uniquePoints_data[k + uniquePoints_size[0]] - YCoordinates[0];
  }

  nx = uniquePoints_size[0];
  for (k = 0; k < nx; k++) {
    b_y_data[k] = a_data[k] * a_data[k];
  }

  for (k = 0; k < b_loop_ub; k++) {
    y_data[k] += b_y_data[k];
  }

  if (uniquePoints_size[0] == 0) {
    a_size[0] = 0;
  } else {
    a_size[0] = uniquePoints_size[0];
    if (0 <= b_loop_ub - 1) {
      std::memcpy(&a_data[0], &y_data[0], b_loop_ub * sizeof(double));
    }
  }

  if (7 <= a_size[0]) {
    b_loop_ub = 7;
  } else {
    b_loop_ub = a_size[0];
  }

  exkib(a_data, a_size, b_loop_ub, idx_data, idx_size, b_data, b_size);
  loop_ub = idx_size[0];
  for (k = 0; k < loop_ub; k++) {
    b_data[k] = idx_data[k];
  }

  //  Get the length vectors to neighbour
  //  Get the angle from target to neighbour.
  b_loop_ub = static_cast<int>(b_data[6]) - 1;
  angleDirection = std::atan((YCoordinates[0] - uniquePoints_data[b_loop_ub +
    uniquePoints_size[0]]) / (XCoordinates[0] - uniquePoints_data[b_loop_ub]));

  //  Get the normal point to the target point.
  *normalPointF0X = XCoordinates[0] + 50.0 * std::cos(angleDirection +
    1.5707963267948966);
  *normalPointF0Y = YCoordinates[0] + 50.0 * std::sin(angleDirection +
    1.5707963267948966);
}

//
// File trailer for StableLine.cpp
//
// [EOF]
//
