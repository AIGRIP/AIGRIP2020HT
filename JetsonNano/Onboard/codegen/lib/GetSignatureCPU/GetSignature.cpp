//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: GetSignature.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:36:28
//

// Include Files
#include "GetSignature.h"
#include "GetARsing.h"
#include "GetSignature_data.h"
#include "GetSignature_initialize.h"
#include "YXtoAngle.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions

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
// GetSignature caclulates the radius dependent on the angle.
//    binaryEdgeImage     - Should be a binary &#xE9;dge image.
//    degreesToMeasure    - Is the degrees in radian that should store the
//                        pixel values and use it to find grip positions.
//    rowsOfImage         - Is the number rows of the image.
//    columnsOfImage      - Is the number columns of the image.
//    signature           - Returns the radius for each of the defined angle.
//    YCoordToStore       - Is the cartesean Y-cordinates of the signature.
//    XCoordToStore       - Is the cartesean X-cordinates of the signature.
// Arguments    : const bool binaryEdgeImage[728160]
//                const double degreesToMeasure[360]
//                double numberOfRows
//                double numberOfColumns
//                double signature[360]
//                double YCoordToStore[360]
//                double XCoordToStore[360]
// Return Type  : void
//
void GetSignature(const bool binaryEdgeImage[728160], const double
                  degreesToMeasure[360], double numberOfRows, double
                  numberOfColumns, double signature[360], double YCoordToStore
                  [360], double XCoordToStore[360])
{
  double rowFocusSignature;
  double columnFocusSignature;
  static bool x[728160];
  int idx;
  coder::array<int, 1U> ii;
  int b_ii;
  bool exitg1;
  coder::array<double, 1U> edgePointsIndex;
  coder::array<double, 1U> yPCoord;
  coder::array<double, 1U> dX;
  if (!isInitialized_GetSignature) {
    GetSignature_initialize();
  }

  //  Focus point is set to the middle of the image.
  rowFocusSignature = rt_roundd_snf(numberOfRows / 2.0);
  columnFocusSignature = rt_roundd_snf(numberOfColumns / 2.0);

  //  Get index of all high pixels.
  std::memcpy(&x[0], &binaryEdgeImage[0], 728160U * sizeof(bool));
  idx = 0;
  ii.set_size(728160);
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 728160)) {
    if (x[b_ii]) {
      idx++;
      ii[idx - 1] = b_ii + 1;
      if (idx >= 728160) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  ii.set_size(idx);
  edgePointsIndex.set_size(ii.size(0));
  idx = ii.size(0);
  for (b_ii = 0; b_ii < idx; b_ii++) {
    edgePointsIndex[b_ii] = ii[b_ii];
  }

  //  Get x and y cordinates.
  yPCoord.set_size(edgePointsIndex.size(0));
  idx = edgePointsIndex.size(0);
  for (b_ii = 0; b_ii < idx; b_ii++) {
    yPCoord[b_ii] = edgePointsIndex[b_ii] / numberOfRows;
  }

  idx = yPCoord.size(0);
  for (b_ii = 0; b_ii < idx; b_ii++) {
    yPCoord[b_ii] = std::floor(yPCoord[b_ii]);
  }

  //  Get the offset from the center of the image.
  idx = yPCoord.size(0);
  for (b_ii = 0; b_ii < idx; b_ii++) {
    yPCoord[b_ii] = columnFocusSignature - yPCoord[b_ii];
  }

  dX.set_size(edgePointsIndex.size(0));
  idx = edgePointsIndex.size(0);
  for (b_ii = 0; b_ii < idx; b_ii++) {
    columnFocusSignature = edgePointsIndex[b_ii];
    if (!(numberOfRows == 0.0)) {
      if (rtIsNaN(numberOfRows)) {
        columnFocusSignature = rtNaN;
      } else if (rtIsInf(numberOfRows)) {
        if (numberOfRows < 0.0) {
          columnFocusSignature = numberOfRows;
        }
      } else {
        bool rEQ0;
        columnFocusSignature = std::fmod(edgePointsIndex[b_ii], numberOfRows);
        rEQ0 = (columnFocusSignature == 0.0);
        if ((!rEQ0) && (numberOfRows > std::floor(numberOfRows))) {
          double q;
          q = std::abs(edgePointsIndex[b_ii] / numberOfRows);
          rEQ0 = !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 *
                   q);
        }

        if (rEQ0) {
          columnFocusSignature = numberOfRows * 0.0;
        } else {
          if (numberOfRows < 0.0) {
            columnFocusSignature += numberOfRows;
          }
        }
      }
    }

    dX[b_ii] = columnFocusSignature;
  }

  idx = dX.size(0);
  for (b_ii = 0; b_ii < idx; b_ii++) {
    dX[b_ii] = rowFocusSignature - dX[b_ii];
  }

  //  Convert the coordinates from the centroid to angular degree from
  //  0 to 2pi
  YXtoAngle(yPCoord, dX, edgePointsIndex);

  //  Get the signature with the right number of feature (Radius,Angle).
  GetARsing(edgePointsIndex, yPCoord, dX, degreesToMeasure, signature,
            YCoordToStore, XCoordToStore);
}

//
// File trailer for GetSignature.cpp
//
// [EOF]
//
