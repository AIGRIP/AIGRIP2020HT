/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * useConstantDim.c
 *
 * Code generation for function 'useConstantDim'
 *
 */

/* Include files */
#include "useConstantDim.h"
#include "eml_int_forloop_overflow_check.h"
#include "morphologicalFilters_data.h"
#include "morphologicalFilters_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = { 32, /* lineNo */
  "useConstantDim",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 99, /* lineNo */
  "ndlooper",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 125,/* lineNo */
  "looper",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 290,/* lineNo */
  "vcumop",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

/* Function Definitions */
void useConstantDim(const emlrtStack *sp, emxArray_int32_T *varargin_2, int32_T
                    varargin_3)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T b;
  int32_T k;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (1 == varargin_3) {
    st.site = &nb_emlrtRSI;
    b_st.site = &ob_emlrtRSI;
    if (varargin_2->size[0] != 0) {
      c_st.site = &pb_emlrtRSI;
      if (varargin_2->size[0] != 1) {
        b = varargin_2->size[0];
        d_st.site = &qb_emlrtRSI;
        if (1 > varargin_2->size[0] - 1) {
          overflow = false;
        } else {
          overflow = (varargin_2->size[0] - 1 > 2147483646);
        }

        if (overflow) {
          e_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (k = 0; k <= b - 2; k++) {
          varargin_2->data[k + 1] += varargin_2->data[k];
        }
      }
    }
  }
}

/* End of code generation (useConstantDim.c) */
