//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  MorphologicalFilters_initialize.cpp
//
//  Code generation for function 'MorphologicalFilters_initialize'
//


// Include files
#include "MorphologicalFilters_initialize.h"
#include "MorphologicalFilters_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void MorphologicalFilters_initialize()
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_MorphologicalFilters = true;
}

// End of code generation (MorphologicalFilters_initialize.cpp)
