//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: morphologicalFilters_initialize.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 05-Nov-2020 08:33:11
//

// Include Files
#include "morphologicalFilters_initialize.h"
#include "morphologicalFilters_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void morphologicalFilters_initialize()
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_morphologicalFilters = true;
}

//
// File trailer for morphologicalFilters_initialize.cpp
//
// [EOF]
//
