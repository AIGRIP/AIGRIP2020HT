//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: GetValidGripPoints.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 13:40:33
//

// Include Files
#include "GetValidGripPoints.h"
#include "GetValidGripPoints_data.h"
#include "GetValidGripPoints_initialize.h"
#include "InverseKinematicsPreshape.h"
#include "cosd.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Definitions

//
// getValidGripPoints checks if the target points is possible for the gripper
// to grasp correctly. Consider to the mouse sensor and the workspace of the
// gripper.
//    targetPointYPixel   - Is the desired point for the gripper to grasp in
//    y direction.
//    targetPointXPixel   - Is the desired point for the gripper to grasp in
//    x direction.
//    normalPointYPixel   - Is the y-coordinate normal point to the surface.
//    normalPointXPixel   - Is the x-coordinate normal point to the surface.
//    distanceToObject    - Is the current distance to the object.
//    fingerNumber        - Is the finger of the gripper. Finger 0 is the
//                            thumb. Finger 1 is the "first finger". Finger 2
//                            is the "long finger".
//    motorSteps          - Returns the position for the motors.
//    bestTargetPointY    - Returns the best point in Y-direction.
//    bestTargetPointX    - Returns the best point in X-direction.
//    bestNormalPointY    - Returns the normal of best point in Y-direction.
//    bestNormalPointX    - Returns the normal of best point in X-direction.
// Arguments    : const double targetPointYPixel_data[]
//                const int targetPointYPixel_size[1]
//                const double targetPointXPixel_data[]
//                const int targetPointXPixel_size[1]
//                const double normalPointYPixel_data[]
//                const int normalPointYPixel_size[1]
//                const double normalPointXPixel_data[]
//                const int normalPointXPixel_size[1]
//                double distanceToObject
//                double fingerNumber
//                unsigned short motorSteps[3]
//                double *bestTargetPointY
//                double *bestTargetPointX
//                double *bestNormalPointY
//                double *bestNormalPointX
// Return Type  : void
//
void GetValidGripPoints(const double targetPointYPixel_data[], const int
  targetPointYPixel_size[1], const double targetPointXPixel_data[], const int
  targetPointXPixel_size[1], const double normalPointYPixel_data[], const int
  normalPointYPixel_size[1], const double normalPointXPixel_data[], const int
  normalPointXPixel_size[1], double distanceToObject, double fingerNumber,
  unsigned short motorSteps[3], double *bestTargetPointY, double
  *bestTargetPointX, double *bestNormalPointY, double *bestNormalPointX)
{
  double b;
  int targetPointX_size_idx_0;
  int loop_ub;
  int i;
  double targetPointX_data[11];
  int targetPointY_size_idx_0;
  double targetPointY_data[11];
  double normalPointX_data[11];
  double normalPointY_data[11];
  bool guard1 = false;
  bool guard2 = false;
  int YdistanceTosingularity;
  int c_pointsInRightQuadrant_size_id;
  bool pointsInRightQuadrant_data[11];
  double b_b[2];
  double normalPointX[2];
  double pointsInRightRange_data[11];
  double c_distanceTargetPointToSignular[11];
  double y_data[11];
  bool tmp_data[11];
  bool x_data[11];
  int nz;
  int y;
  signed char b_tmp_data[11];
  signed char c_tmp_data[11];
  signed char d_tmp_data[11];
  signed char e_tmp_data[11];
  double b_y;
  if (!isInitialized_GetValidGripPoints) {
    GetValidGripPoints_initialize();
  }

  //  Define the links of the gripper fingers.
  //  Convert to pixelcoordinates to real cordinates.
  //  "Real coordinate X" = "-1*Pixel Coordinate Y"
  //  "Real coordinate Y" = "Pixel Coordinate X"
  // This function will calculate the length of one pixel of an object.
  // Then convert pixel postions into real world coordinates in mm.
  // Input:
  // centerPointPixel = Center of the pixel area. x and y postion.
  // Position is in pixels
  // edgePointsPixel = Points along the edge of the pixel area. array with
  // x and y postion. Positions is in pixels
  // distanceToObject = distance to object in mm.
  // Output:
  // edgePointsmm = edgePointsPixel converted to mm
  //  Focal length in pixels
  // Calculate the width of the object in pixels
  b = distanceToObject * 0.001358695652173913;

  // Convert the points from pixels to mm
  targetPointX_size_idx_0 = targetPointYPixel_size[0];
  loop_ub = targetPointYPixel_size[0];
  for (i = 0; i < loop_ub; i++) {
    targetPointX_data[i] = -(targetPointYPixel_data[i] * b);
  }

  // This function will calculate the length of one pixel of an object.
  // Then convert pixel postions into real world coordinates in mm.
  // Input:
  // centerPointPixel = Center of the pixel area. x and y postion.
  // Position is in pixels
  // edgePointsPixel = Points along the edge of the pixel area. array with
  // x and y postion. Positions is in pixels
  // distanceToObject = distance to object in mm.
  // Output:
  // edgePointsmm = edgePointsPixel converted to mm
  //  Focal length in pixels
  // Calculate the width of the object in pixels
  b = distanceToObject * 0.001358695652173913;

  // Convert the points from pixels to mm
  targetPointY_size_idx_0 = targetPointXPixel_size[0];
  loop_ub = targetPointXPixel_size[0];
  for (i = 0; i < loop_ub; i++) {
    targetPointY_data[i] = targetPointXPixel_data[i] * b;
  }

  // This function will calculate the length of one pixel of an object.
  // Then convert pixel postions into real world coordinates in mm.
  // Input:
  // centerPointPixel = Center of the pixel area. x and y postion.
  // Position is in pixels
  // edgePointsPixel = Points along the edge of the pixel area. array with
  // x and y postion. Positions is in pixels
  // distanceToObject = distance to object in mm.
  // Output:
  // edgePointsmm = edgePointsPixel converted to mm
  //  Focal length in pixels
  // Calculate the width of the object in pixels
  b = distanceToObject * 0.001358695652173913;

  // Convert the points from pixels to mm
  loop_ub = normalPointYPixel_size[0];
  for (i = 0; i < loop_ub; i++) {
    normalPointX_data[i] = -(normalPointYPixel_data[i] * b);
  }

  // This function will calculate the length of one pixel of an object.
  // Then convert pixel postions into real world coordinates in mm.
  // Input:
  // centerPointPixel = Center of the pixel area. x and y postion.
  // Position is in pixels
  // edgePointsPixel = Points along the edge of the pixel area. array with
  // x and y postion. Positions is in pixels
  // distanceToObject = distance to object in mm.
  // Output:
  // edgePointsmm = edgePointsPixel converted to mm
  //  Focal length in pixels
  // Calculate the width of the object in pixels
  b = distanceToObject * 0.001358695652173913;

  // Convert the points from pixels to mm
  loop_ub = normalPointXPixel_size[0];
  for (i = 0; i < loop_ub; i++) {
    normalPointY_data[i] = normalPointXPixel_data[i] * b;
  }

  //  Check if target points is reachable for grippers pre-shape.
  //  Offset from center to signularity point of finger.
  //  Set the default value dependent on which finger and check if finger
  //  is in workspace.
  guard1 = false;
  guard2 = false;
  if (fingerNumber == 1.0) {
    //  Singularity point Y coordinate for finger 1.
    YdistanceTosingularity = 36;

    //  Check if finger 1 is within its workspace.
    c_pointsInRightQuadrant_size_id = targetPointYPixel_size[0];
    for (i = 0; i < targetPointX_size_idx_0; i++) {
      pointsInRightQuadrant_data[i] = (((targetPointX_data[i] <= -23.0) &&
        (targetPointY_data[i] >= 36.0)) || ((targetPointX_data[i] >= -23.0) &&
        (targetPointY_data[i] <= 36.0)));
    }

    //  Set motor to default poistion if there is no valid target point.
    //  For finger 1.
    *bestTargetPointY = 36.0;
    *bestTargetPointX = -78.0;
    *bestNormalPointY = 36.0;
    *bestNormalPointX = -23.0;
    guard1 = true;
  } else if (fingerNumber == 2.0) {
    //  Singularity point Y coordinate for finger 2.
    YdistanceTosingularity = -36;

    //  Check if finger 2 is within its workspace.
    c_pointsInRightQuadrant_size_id = targetPointYPixel_size[0];
    for (i = 0; i < targetPointX_size_idx_0; i++) {
      pointsInRightQuadrant_data[i] = (((targetPointX_data[i] >= -23.0) &&
        (targetPointY_data[i] >= -36.0)) || ((targetPointX_data[i] <= -23.0) &&
        (targetPointY_data[i] <= -36.0)));
    }

    //  Set motor to default poistion if there is no valid target point.
    //  For finger 2.
    *bestTargetPointY = -36.0;
    *bestTargetPointX = -78.0;
    *bestNormalPointY = -36.0;
    *bestNormalPointX = 0.0;
    guard1 = true;
  } else {
    //  Check if the target point is reachable.
    b = 34.0;
    b_cosd(&b);
    if (64.0 - (60.0 * b + 11.0) < targetPointX_data[0]) {
      b = 60.0;
      b_cosd(&b);
      if ((targetPointX_data[0] < (60.0 * b - 11.0) + 64.0) &&
          (57.295779513082323 * std::atan(std::abs(normalPointY_data[0]) / std::
            abs(targetPointX_data[0] - normalPointX_data[0])) < 60.0)) {
        //  Check if the angle between surface and finger surface. If it
        //  is less then 60 degrees it is a valid point to grasp with
        //  finger 0.
        b_b[0] = targetPointX_data[0];
        b_b[1] = 0.0;
        normalPointX[0] = normalPointX_data[0];
        normalPointX[1] = normalPointY_data[0];
        InverseKinematicsPreshape(b_b, normalPointX, fingerNumber, motorSteps);

        //  Return the coordinate for the finger 0 to grip.
        *bestTargetPointY = targetPointY_data[0];
        *bestTargetPointX = targetPointX_data[0];
        *bestNormalPointY = normalPointY_data[0];
        *bestNormalPointX = normalPointX_data[0];
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }
  }

  if (guard2) {
    //  Set motor to default poistion if there is no valid target point.
    //  For finger 2.
    *bestTargetPointY = 0.0;
    *bestTargetPointX = 83.0;
    *bestNormalPointY = 0.0;
    *bestNormalPointX = 0.0;

    //  If there was no valid target point.
    b_b[0] = 83.0;
    normalPointX[0] = 0.0;
    b_b[1] = 0.0;
    normalPointX[1] = 0.0;
    InverseKinematicsPreshape(b_b, normalPointX, fingerNumber, motorSteps);
  }

  if (guard1) {
    //  Maximum radius of finger during parallell grasp. Offset from
    //  singularity point is 38 mm. The link C is 60 mm and the distance
    //  between the joint and finger nail surface is 11 mm.
    //  Get distance from singularity point to finger surface.
    for (i = 0; i < targetPointX_size_idx_0; i++) {
      pointsInRightRange_data[i] = targetPointX_data[i] - -23.0;
    }

    for (loop_ub = 0; loop_ub < targetPointX_size_idx_0; loop_ub++) {
      c_distanceTargetPointToSignular[loop_ub] = pointsInRightRange_data[loop_ub]
        * pointsInRightRange_data[loop_ub];
    }

    for (i = 0; i < targetPointY_size_idx_0; i++) {
      pointsInRightRange_data[i] = targetPointY_data[i] - static_cast<double>
        (YdistanceTosingularity);
    }

    for (loop_ub = 0; loop_ub < targetPointY_size_idx_0; loop_ub++) {
      y_data[loop_ub] = pointsInRightRange_data[loop_ub] *
        pointsInRightRange_data[loop_ub];
    }

    for (i = 0; i < targetPointX_size_idx_0; i++) {
      c_distanceTargetPointToSignular[i] += y_data[i];
    }

    for (loop_ub = 0; loop_ub < targetPointX_size_idx_0; loop_ub++) {
      c_distanceTargetPointToSignular[loop_ub] = std::sqrt
        (c_distanceTargetPointToSignular[loop_ub]);
    }

    //  Allocate space to indicate point within range.
    if (0 <= targetPointX_size_idx_0 - 1) {
      std::memset(&pointsInRightRange_data[0], 0, targetPointX_size_idx_0 *
                  sizeof(double));
    }

    //  Get the indexes that is within the range.
    for (i = 0; i < targetPointX_size_idx_0; i++) {
      //  Check witch side of the singluaraity the point is in.
      if (targetPointX_data[i] > -23.0) {
        pointsInRightRange_data[i] = (c_distanceTargetPointToSignular[i] <
          22.7422543533025);
      } else {
        pointsInRightRange_data[i] = (c_distanceTargetPointToSignular[i] < 57.0);
      }
    }

    //  Get the indexes that is reachable.
    for (i = 0; i < targetPointX_size_idx_0; i++) {
      tmp_data[i] = (pointsInRightRange_data[i] != 0.0);
    }

    //  Get the amount of valid positions.
    for (i = 0; i < c_pointsInRightQuadrant_size_id; i++) {
      x_data[i] = (pointsInRightQuadrant_data[i] && tmp_data[i]);
    }

    if (c_pointsInRightQuadrant_size_id == 0) {
      nz = -1;
      y = 0;
    } else {
      nz = x_data[0] - 1;
      for (loop_ub = 2; loop_ub <= c_pointsInRightQuadrant_size_id; loop_ub++) {
        nz += x_data[loop_ub - 1];
      }

      y = x_data[0];
      for (loop_ub = 2; loop_ub <= c_pointsInRightQuadrant_size_id; loop_ub++) {
        y += x_data[loop_ub - 1];
      }
    }

    //  Set the valid gripping point in priority order.
    if (1 > y) {
      loop_ub = 0;
    } else {
      loop_ub = nz + 1;
    }

    targetPointY_size_idx_0 = c_pointsInRightQuadrant_size_id - 1;
    targetPointX_size_idx_0 = 0;
    for (i = 0; i <= targetPointY_size_idx_0; i++) {
      if (pointsInRightQuadrant_data[i] && tmp_data[i]) {
        b_tmp_data[targetPointX_size_idx_0] = static_cast<signed char>(i + 1);
        targetPointX_size_idx_0++;
      }
    }

    for (i = 0; i < loop_ub; i++) {
      c_distanceTargetPointToSignular[i] = targetPointY_data[b_tmp_data[i] - 1];
    }

    if (0 <= loop_ub - 1) {
      std::memcpy(&targetPointY_data[0], &c_distanceTargetPointToSignular[0],
                  loop_ub * sizeof(double));
    }

    if (1 > y) {
      loop_ub = 0;
    } else {
      loop_ub = nz + 1;
    }

    targetPointY_size_idx_0 = c_pointsInRightQuadrant_size_id - 1;
    targetPointX_size_idx_0 = 0;
    for (i = 0; i <= targetPointY_size_idx_0; i++) {
      if (pointsInRightQuadrant_data[i] && tmp_data[i]) {
        c_tmp_data[targetPointX_size_idx_0] = static_cast<signed char>(i + 1);
        targetPointX_size_idx_0++;
      }
    }

    for (i = 0; i < loop_ub; i++) {
      c_distanceTargetPointToSignular[i] = targetPointX_data[c_tmp_data[i] - 1];
    }

    if (0 <= loop_ub - 1) {
      std::memcpy(&targetPointX_data[0], &c_distanceTargetPointToSignular[0],
                  loop_ub * sizeof(double));
    }

    if (1 > y) {
      loop_ub = 0;
    } else {
      loop_ub = nz + 1;
    }

    targetPointY_size_idx_0 = c_pointsInRightQuadrant_size_id - 1;
    targetPointX_size_idx_0 = 0;
    for (i = 0; i <= targetPointY_size_idx_0; i++) {
      if (pointsInRightQuadrant_data[i] && tmp_data[i]) {
        d_tmp_data[targetPointX_size_idx_0] = static_cast<signed char>(i + 1);
        targetPointX_size_idx_0++;
      }
    }

    for (i = 0; i < loop_ub; i++) {
      c_distanceTargetPointToSignular[i] = normalPointY_data[d_tmp_data[i] - 1];
    }

    if (0 <= loop_ub - 1) {
      std::memcpy(&normalPointY_data[0], &c_distanceTargetPointToSignular[0],
                  loop_ub * sizeof(double));
    }

    if (1 > y) {
      loop_ub = 0;
    } else {
      loop_ub = nz + 1;
    }

    targetPointY_size_idx_0 = c_pointsInRightQuadrant_size_id - 1;
    targetPointX_size_idx_0 = 0;
    for (i = 0; i <= targetPointY_size_idx_0; i++) {
      if (pointsInRightQuadrant_data[i] && tmp_data[i]) {
        e_tmp_data[targetPointX_size_idx_0] = static_cast<signed char>(i + 1);
        targetPointX_size_idx_0++;
      }
    }

    for (i = 0; i < loop_ub; i++) {
      c_distanceTargetPointToSignular[i] = normalPointX_data[e_tmp_data[i] - 1];
    }

    if (0 <= loop_ub - 1) {
      std::memcpy(&normalPointX_data[0], &c_distanceTargetPointToSignular[0],
                  loop_ub * sizeof(double));
    }

    if (0 < nz + 1) {
      bool exitg1;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i <= y - 1)) {
        bool b_guard1 = false;

        //  Check if the orientation is possible.
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
        // Check if the possiblePosition is in the right quadrant for the
        // function
        b_guard1 = false;
        if (YdistanceTosingularity > 0) {
          if (((targetPointX_data[i] > 0.0) && (targetPointY_data[i] > 0.0)) ||
              ((targetPointX_data[i] < 0.0) && (targetPointY_data[i] < 0.0))) {
            i++;
          } else {
            b_guard1 = true;
          }
        } else if (((targetPointX_data[i] > 0.0) && (targetPointY_data[i] < 0.0))
                   || ((targetPointX_data[i] < 0.0) && (targetPointY_data[i] >
                     0.0))) {
          i++;
        } else {
          b_guard1 = true;
        }

        if (b_guard1) {
          double scale;
          double absxk;
          double t;

          // Calculate the distances from the normals to the singularity point.
          // Pick the first distance in the list that is lower than the error margin 
          scale = 3.3121686421112381E-170;
          b = normalPointX_data[i] - targetPointX_data[i];
          b_b[0] = b * static_cast<double>(YdistanceTosingularity);
          absxk = std::abs(b);
          if (absxk > 3.3121686421112381E-170) {
            b_y = 1.0;
            scale = absxk;
          } else {
            t = absxk / 3.3121686421112381E-170;
            b_y = t * t;
          }

          b = normalPointY_data[i] - targetPointY_data[i];
          absxk = std::abs(b);
          if (absxk > scale) {
            t = scale / absxk;
            b_y = b_y * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            b_y += t * t;
          }

          b_y = scale * std::sqrt(b_y);
          if (std::abs(((b * -23.0 - b_b[0]) + normalPointX_data[i] *
                        targetPointY_data[i]) - normalPointY_data[i] *
                       targetPointX_data[i]) / b_y < 6.0) {
            //  Set the return value.
            *bestTargetPointY = targetPointY_data[i];
            *bestTargetPointX = targetPointX_data[i];
            *bestNormalPointY = normalPointY_data[i];
            *bestNormalPointX = normalPointX_data[i];
            exitg1 = true;
          } else {
            i++;
          }
        }
      }
    }

    //  Return the motor steps for the current.
    b_b[0] = *bestTargetPointX;
    b_b[1] = *bestTargetPointY;
    normalPointX[0] = *bestNormalPointX;
    normalPointX[1] = *bestNormalPointY;
    InverseKinematicsPreshape(b_b, normalPointX, fingerNumber, motorSteps);
  }
}

//
// File trailer for GetValidGripPoints.cpp
//
// [EOF]
//
