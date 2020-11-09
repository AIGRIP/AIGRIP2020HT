//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colourSegmentation_initialize.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 06-Nov-2020 12:01:09
//

// Include Files
#include "colourSegmentation_initialize.h"
#include "colourSegmentation_data.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void colourSegmentation_initialize()
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_colourSegmentation = true;
}

//
// File trailer for colourSegmentation_initialize.cpp
//
// [EOF]
//
