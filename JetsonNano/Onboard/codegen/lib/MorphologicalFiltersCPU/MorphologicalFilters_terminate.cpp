//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  MorphologicalFilters_terminate.cpp
//
//  Code generation for function 'MorphologicalFilters_terminate'
//


// Include files
#include "MorphologicalFilters_terminate.h"
#include "MorphologicalFilters_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void MorphologicalFilters_terminate()
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_MorphologicalFilters = false;
}

// End of code generation (MorphologicalFilters_terminate.cpp)
