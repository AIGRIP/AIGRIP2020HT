//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PriorityOfGripPoints.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//

// Include Files
#include "PriorityOfGripPoints.h"
#include "StableLine.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include <cstring>

// Function Definitions

//
// priorityOfGripPoints makes a priority of sugested points based on
// signature. The suggested target with lowest radius get highest priority.
// Arguments    : const double signatureRadius[11]
//                double targetPointY[11]
//                double targetPointX[11]
//                double normalPointY[11]
//                double normalPointX[11]
// Return Type  : void
//
void PriorityOfGripPoints(const double signatureRadius[11], double targetPointY
  [11], double targetPointX[11], double normalPointY[11], double normalPointX[11])
{
  double x[11];
  int iidx[11];
  int i;
  double b_targetPointY[11];

  //  Set priority based on signature.
  std::memcpy(&x[0], &signatureRadius[0], 11U * sizeof(double));
  sort(x, iidx);

  //  Sort the target points in the priority order.
  for (i = 0; i < 11; i++) {
    x[i] = iidx[i];
    b_targetPointY[i] = targetPointY[static_cast<int>(x[i]) - 1];
  }

  for (i = 0; i < 11; i++) {
    targetPointY[i] = b_targetPointY[i];
    b_targetPointY[i] = targetPointX[static_cast<int>(x[i]) - 1];
  }

  for (i = 0; i < 11; i++) {
    targetPointX[i] = b_targetPointY[i];
    b_targetPointY[i] = normalPointY[static_cast<int>(x[i]) - 1];
  }

  for (i = 0; i < 11; i++) {
    normalPointY[i] = b_targetPointY[i];
    b_targetPointY[i] = normalPointX[static_cast<int>(x[i]) - 1];
  }

  std::memcpy(&normalPointX[0], &b_targetPointY[0], 11U * sizeof(double));
}

//
// File trailer for PriorityOfGripPoints.cpp
//
// [EOF]
//
