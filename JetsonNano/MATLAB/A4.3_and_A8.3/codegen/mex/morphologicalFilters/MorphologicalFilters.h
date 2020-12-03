/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MorphologicalFilters.h
 *
 * Code generation for function 'MorphologicalFilters'
 *
 */

#pragma once

/* Include files */
#include "MorphologicalFilters_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void MorphologicalFilters(MorphologicalFiltersStackData *SD, const emlrtStack
  *sp, const boolean_T colourSegmentationMask[728160], real_T centerOfObjectX,
  real_T centerOfObjectY, boolean_T segmentationMask[728160]);

/* End of code generation (MorphologicalFilters.h) */
