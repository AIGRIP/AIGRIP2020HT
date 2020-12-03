//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MorphologicalFilters_initialize.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 02-Dec-2020 13:31:29
//

// Include Files
#include "MorphologicalFilters_initialize.h"
#include "MorphologicalFilters_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void MorphologicalFilters_initialize()
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_MorphologicalFilters = true;
}

//
// File trailer for MorphologicalFilters_initialize.cpp
//
// [EOF]
//