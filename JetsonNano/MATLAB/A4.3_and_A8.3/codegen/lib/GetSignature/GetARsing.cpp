//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: GetARsing.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:36:28
//

// Include Files
#include "GetARsing.h"
#include "GetSignature.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions

//
// GetARsing returns the radius for the angles in "degreesToMeasure".
//    angles              - Is the degrees of the points represented by "Y" and "X".
//    Y                   - Is the Y-coordinates for the points.
//    X                   - Is the X-coordinates for the points.
//    degreesToMeasure    - Is the angles for where the radius should be calculated.
//    singature           - Returns the radius of the angles to the closest point.
//    YCoordToStore       - Returns the Y-coordinates of the signature.
//    XCoordToStore       - Returns the X-coordinates of the signature.
// Arguments    : const coder::array<double, 1U> *angles
//                const coder::array<double, 1U> *Y
//                const coder::array<double, 1U> *X
//                const double degreesToMeasure[360]
//                double signature[360]
//                double YCoordToStore[360]
//                double XCoordToStore[360]
// Return Type  : void
//
void GetARsing(const coder::array<double, 1U> &angles, const coder::array<double,
               1U> &Y, const coder::array<double, 1U> &X, const double
               degreesToMeasure[360], double signature[360], double
               YCoordToStore[360], double XCoordToStore[360])
{
  int loop_ub;
  coder::array<double, 1U> x;
  coder::array<double, 1U> varargin_1;

  //  Allocate space for the signature and the coordinates to return.
  loop_ub = angles.size(0);
  for (int jj = 0; jj < 360; jj++) {
    int nx;
    int k;
    int n;
    int iindx;

    //  Get the closest point to the angle to measure.
    x.set_size(angles.size(0));
    for (nx = 0; nx < loop_ub; nx++) {
      x[nx] = degreesToMeasure[jj] - angles[nx];
    }

    nx = x.size(0);
    varargin_1.set_size(x.size(0));
    for (k = 0; k < nx; k++) {
      varargin_1[k] = std::abs(x[k]);
    }

    n = varargin_1.size(0);
    if (varargin_1.size(0) <= 2) {
      if (varargin_1.size(0) == 1) {
        iindx = 0;
      } else if ((varargin_1[0] > varargin_1[1]) || (rtIsNaN(varargin_1[0]) && (
                   !rtIsNaN(varargin_1[1])))) {
        iindx = 1;
      } else {
        iindx = 0;
      }
    } else {
      if (!rtIsNaN(varargin_1[0])) {
        nx = 1;
      } else {
        bool exitg1;
        nx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= varargin_1.size(0))) {
          if (!rtIsNaN(varargin_1[k - 1])) {
            nx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (nx == 0) {
        iindx = 0;
      } else {
        double ex;
        ex = varargin_1[nx - 1];
        iindx = nx - 1;
        nx++;
        for (k = nx; k <= n; k++) {
          double d;
          d = varargin_1[k - 1];
          if (ex > d) {
            ex = d;
            iindx = k - 1;
          }
        }
      }
    }

    //  Get the radius.
    signature[jj] = std::sqrt(X[iindx] * X[iindx] + Y[iindx] * Y[iindx]);

    //  Store the cartesean coordinates.
    XCoordToStore[jj] = X[iindx];
    YCoordToStore[jj] = Y[iindx];
  }
}

//
// File trailer for GetARsing.cpp
//
// [EOF]
//
