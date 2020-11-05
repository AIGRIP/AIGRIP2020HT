/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * horzcatStructList.c
 *
 * Code generation for function 'horzcatStructList'
 *
 */

/* Include files */
#include "horzcatStructList.h"
#include "eml_int_forloop_overflow_check.h"
#include "morphologicalFilters_data.h"
#include "morphologicalFilters_emxutil.h"
#include "morphologicalFilters_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = { 67, /* lineNo */
  "horzcatStructList",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\horzcatStructList.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 23, /* lineNo */
  "horzcatStructList",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\horzcatStructList.m"/* pathName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 65,/* lineNo */
  10,                                  /* colNo */
  "horzcatStructList",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\horzcatStructList.m"/* pName */
};

/* Function Definitions */
void b_horzcatStructList(const emlrtStack *sp, const emxArray_struct_T
  *structure, emxArray_real_T *result)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T n;
  int32_T resultSize_idx_1;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = structure->size[0];
  if (structure->size[0] == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure->size[0] << 1;
    st.site = &kc_emlrtRSI;
    if (2 > structure->size[0]) {
      overflow = false;
    } else {
      overflow = (structure->size[0] > 2147483646);
    }

    if (overflow) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }

  i = result->size[0] * result->size[1];
  result->size[0] = 1;
  result->size[1] = resultSize_idx_1;
  emxEnsureCapacity_real_T(sp, result, i, &ec_emlrtRTEI);
  resultSize_idx_1 = 0;
  st.site = &jc_emlrtRSI;
  if (1 > structure->size[0]) {
    overflow = false;
  } else {
    overflow = (structure->size[0] > 2147483646);
  }

  if (overflow) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (i = 0; i < n; i++) {
    result->data[resultSize_idx_1] = structure->data[i].Centroid[0];
    result->data[resultSize_idx_1 + 1] = structure->data[i].Centroid[1];
    resultSize_idx_1 += 2;
  }
}

void horzcatStructList(const emlrtStack *sp, const emxArray_struct_T *structure,
  emxArray_real_T *result)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T n;
  int32_T resultSize_idx_1;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = structure->size[0];
  if (structure->size[0] == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure->size[0];
    st.site = &kc_emlrtRSI;
    if (2 > structure->size[0]) {
      overflow = false;
    } else {
      overflow = (structure->size[0] > 2147483646);
    }

    if (overflow) {
      b_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }

  i = result->size[0] * result->size[1];
  result->size[0] = 1;
  result->size[1] = resultSize_idx_1;
  emxEnsureCapacity_real_T(sp, result, i, &ec_emlrtRTEI);
  resultSize_idx_1 = 0;
  st.site = &jc_emlrtRSI;
  if (1 > structure->size[0]) {
    overflow = false;
  } else {
    overflow = (structure->size[0] > 2147483646);
  }

  if (overflow) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (i = 0; i < n; i++) {
    result->data[resultSize_idx_1] = structure->data[i].Area;
    resultSize_idx_1++;
  }
}

/* End of code generation (horzcatStructList.c) */
