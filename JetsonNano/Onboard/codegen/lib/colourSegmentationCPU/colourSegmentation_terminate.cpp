//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colourSegmentation_terminate.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 06-Nov-2020 12:01:09
//

// Include Files
#include "colourSegmentation_terminate.h"
#include "colourSegmentation_data.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void colourSegmentation_terminate()
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_colourSegmentation = false;
}

//
// File trailer for colourSegmentation_terminate.cpp
//
// [EOF]
//
