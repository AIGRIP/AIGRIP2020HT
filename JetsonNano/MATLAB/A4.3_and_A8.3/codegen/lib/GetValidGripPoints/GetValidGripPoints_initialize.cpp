//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: GetValidGripPoints_initialize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 11:25:48
//

// Include Files
#include "GetValidGripPoints_initialize.h"
#include "GetValidGripPoints.h"
#include "GetValidGripPoints_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void GetValidGripPoints_initialize()
{
  rt_InitInfAndNaN();
  isInitialized_GetValidGripPoints = true;
}

//
// File trailer for GetValidGripPoints_initialize.cpp
//
// [EOF]
//
