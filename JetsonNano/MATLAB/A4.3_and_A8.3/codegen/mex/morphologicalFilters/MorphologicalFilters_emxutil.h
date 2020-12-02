/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MorphologicalFilters_emxutil.h
 *
 * Code generation for function 'MorphologicalFilters_emxutil'
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
void emxCopyMatrix_real_T(real_T dst[2], const real_T src[2]);
void emxCopyMatrix_real_T1(real_T dst[4], const real_T src[4]);
void emxCopyMatrix_real_T2(real_T dst[16], const real_T src[16]);
void emxCopyStruct_struct_T(const emlrtStack *sp, b_struct_T *dst, const
  b_struct_T *src, const emlrtRTEInfo *srcLocation);
void emxCopyStruct_struct_T1(const emlrtStack *sp, c_struct_T *dst, const
  c_struct_T *src, const emlrtRTEInfo *srcLocation);
void emxCopy_boolean_T(const emlrtStack *sp, emxArray_boolean_T **dst,
  emxArray_boolean_T * const *src, const emlrtRTEInfo *srcLocation);
void emxCopy_real_T(const emlrtStack *sp, emxArray_real_T **dst, emxArray_real_T
                    * const *src, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_int16_T(const emlrtStack *sp, emxArray_int16_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_struct_T(const emlrtStack *sp, emxArray_struct_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_struct_T1(const emlrtStack *sp, b_emxArray_struct_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxExpand_struct_T(const emlrtStack *sp, emxArray_struct_T *emxArray,
  int32_T fromIndex, int32_T toIndex, const emlrtRTEInfo *srcLocation);
void emxExpand_struct_T1(const emlrtStack *sp, b_emxArray_struct_T *emxArray,
  int32_T fromIndex, int32_T toIndex, const emlrtRTEInfo *srcLocation);
void emxFreeStruct_struct_T(b_struct_T *pStruct);
void emxFreeStruct_struct_T1(c_struct_T *pStruct);
void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
void emxFree_int16_T(emxArray_int16_T **pEmxArray);
void emxFree_int32_T(emxArray_int32_T **pEmxArray);
void emxFree_real_T(emxArray_real_T **pEmxArray);
void emxFree_struct_T(emxArray_struct_T **pEmxArray);
void emxFree_struct_T1(b_emxArray_struct_T **pEmxArray);
void emxInitStruct_struct_T(const emlrtStack *sp, b_struct_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_struct_T1(const emlrtStack *sp, c_struct_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_int16_T(const emlrtStack *sp, emxArray_int16_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush);
void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush);
void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray, int32_T
                    numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                    doPush);
void emxInit_struct_T(const emlrtStack *sp, emxArray_struct_T **pEmxArray,
                      int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                      boolean_T doPush);
void emxInit_struct_T1(const emlrtStack *sp, b_emxArray_struct_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxTrim_struct_T(emxArray_struct_T *emxArray, int32_T fromIndex, int32_T
                      toIndex);
void emxTrim_struct_T1(b_emxArray_struct_T *emxArray, int32_T fromIndex, int32_T
  toIndex);

/* End of code generation (MorphologicalFilters_emxutil.h) */
