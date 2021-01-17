//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: GetSignature_initialize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:36:28
//

// Include Files
#include "GetSignature_initialize.h"
#include "GetSignature.h"
#include "GetSignature_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void GetSignature_initialize()
{
  rt_InitInfAndNaN();
  isInitialized_GetSignature = true;
}

//
// File trailer for GetSignature_initialize.cpp
//
// [EOF]
//
