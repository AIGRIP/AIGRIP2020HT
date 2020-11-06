/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * applyToMultipleDims.c
 *
 * Code generation for function 'applyToMultipleDims'
 *
 */

/* Include files */
#include "applyToMultipleDims.h"
#include "colourSegmentation_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void applyToMultipleDims(const boolean_T x[23409], real_T varargout_1[9])
{
  real_T d;
  int32_T i;
  int32_T k;
  int32_T xpageoffset;
  for (i = 0; i < 9; i++) {
    xpageoffset = i * 2601;
    d = x[xpageoffset];
    for (k = 0; k < 2600; k++) {
      d += (real_T)x[(xpageoffset + k) + 1];
    }

    varargout_1[i] = d;
  }
}

/* End of code generation (applyToMultipleDims.c) */
