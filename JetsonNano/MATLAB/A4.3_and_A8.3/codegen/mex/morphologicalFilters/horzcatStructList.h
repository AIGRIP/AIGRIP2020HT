/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * horzcatStructList.h
 *
 * Code generation for function 'horzcatStructList'
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
void b_horzcatStructList(const emlrtStack *sp, const emxArray_struct_T
  *structure, emxArray_real_T *result);
void horzcatStructList(const emlrtStack *sp, const emxArray_struct_T *structure,
  emxArray_real_T *result);

/* End of code generation (horzcatStructList.h) */
