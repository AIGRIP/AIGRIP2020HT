/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "morphologicalFilters_data.h"
#include "morphologicalFilters_emxutil.h"
#include "morphologicalFilters_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo nc_emlrtRSI = { 178,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 196,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 166,/* lineNo */
  24,                                  /* colNo */
  "combineVectorElements",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pName */
};

/* Function Definitions */
void sum(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T j;
  int32_T vstride;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &ib_emlrtRSI;
  if (x->size[0] == 0) {
    y->size[0] = 0;
  } else {
    c_st.site = &jb_emlrtRSI;
    vstride = x->size[0];
    j = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&c_st, y, j, &fc_emlrtRTEI);
    d_st.site = &nc_emlrtRSI;
    if (x->size[0] > 2147483646) {
      e_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (j = 0; j < vstride; j++) {
      y->data[j] = x->data[j];
    }

    d_st.site = &oc_emlrtRSI;
    if (x->size[0] > 2147483646) {
      e_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (j = 0; j < vstride; j++) {
      y->data[j] += x->data[vstride + j];
    }
  }
}

/* End of code generation (sum.c) */
