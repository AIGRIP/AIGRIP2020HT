//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MorphologicalFilters_terminate.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 03-Dec-2020 08:29:52
//

// Include Files
#include "MorphologicalFilters_terminate.h"
#include "MorphologicalFilters_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void MorphologicalFilters_terminate()
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_MorphologicalFilters = false;
}

//
// File trailer for MorphologicalFilters_terminate.cpp
//
// [EOF]
//
