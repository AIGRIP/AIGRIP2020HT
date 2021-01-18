//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: StableLine_initialize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
//

// Include Files
#include "StableLine_initialize.h"
#include "StableLine.h"
#include "StableLine_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void StableLine_initialize()
{
  rt_InitInfAndNaN();
  isInitialized_StableLine = true;
}

//
// File trailer for StableLine_initialize.cpp
//
// [EOF]
//
