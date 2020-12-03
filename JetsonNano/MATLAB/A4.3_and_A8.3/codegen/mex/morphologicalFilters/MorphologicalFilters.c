/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MorphologicalFilters.c
 *
 * Code generation for function 'MorphologicalFilters'
 *
 */

/* Include files */
#include "MorphologicalFilters.h"
#include "MorphologicalEdgeFilter.h"
#include "MorphologicalFilters_data.h"
#include "MorphologicalFilters_emxutil.h"
#include "MorphologicalFilters_types.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "horzcatStructList.h"
#include "imdilate.h"
#include "imerode.h"
#include "imfill.h"
#include "regionprops.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 16,    /* lineNo */
  "MorphologicalFilters",              /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 20,  /* lineNo */
  "MorphologicalFilters",              /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 23,  /* lineNo */
  "MorphologicalFilters",              /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 25,  /* lineNo */
  "MorphologicalFilters",              /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 33,  /* lineNo */
  "MorphologicalFilters",              /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 34,  /* lineNo */
  "MorphologicalFilters",              /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 41,  /* lineNo */
  "MorphologicalFilters",              /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 42,  /* lineNo */
  "MorphologicalFilters",              /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 45,  /* lineNo */
  "MorphologicalFilters",              /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 934, /* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 926, /* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 977, /* lineNo */
  "findFirst",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 994, /* lineNo */
  "minOrMaxRealVectorKernel",          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 70, /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 79, /* lineNo */
  "fltpower",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 66, /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 188,/* lineNo */
  "flatIter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 27, /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 18, /* lineNo */
  "reshapeSizeChecks",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 16, /* lineNo */
  "sqrt",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 33, /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 16, /* lineNo */
  "min",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 40, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 90, /* lineNo */
  "minimum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 133,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 13,  /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 97,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 59,/* lineNo */
  23,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 52,/* lineNo */
  13,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  29,                                  /* lineNo */
  1,                                   /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  29,                                  /* lineNo */
  17,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  28,                                  /* lineNo */
  1,                                   /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  28,                                  /* lineNo */
  17,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  1,                                   /* colNo */
  "centroid",                          /* aName */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  18,                                  /* colNo */
  "stats",                             /* aName */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  728160,                              /* iLast */
  38,                                  /* lineNo */
  18,                                  /* colNo */
  "segmentationMask",                  /* aName */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo l_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 28,/* lineNo */
  35,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 28,/* lineNo */
  17,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 29,/* lineNo */
  35,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 29,/* lineNo */
  17,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 1, /* lineNo */
  30,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 60,/* lineNo */
  20,                                  /* colNo */
  "bsxfun",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 46,/* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 38,/* lineNo */
  18,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 20,/* lineNo */
  1,                                   /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 30,/* lineNo */
  10,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 23,/* lineNo */
  9,                                   /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 33,/* lineNo */
  22,                                  /* colNo */
  "MorphologicalFilters",              /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m"/* pName */
};

/* Function Definitions */
void MorphologicalFilters(MorphologicalFiltersStackData *SD, const emlrtStack
  *sp, const boolean_T colourSegmentationMask[728160], real_T centerOfObjectX,
  real_T centerOfObjectY, boolean_T segmentationMask[728160])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *area;
  emxArray_real_T *c;
  emxArray_real_T *centroid;
  emxArray_real_T *distances;
  emxArray_real_T *varargin_1;
  emxArray_struct_T *stats;
  real_T b_varargin_1[2];
  real_T d;
  real_T ex;
  int32_T idx;
  int32_T input_sizes_idx_1;
  int32_T maxdimlen;
  int32_T n;
  boolean_T exitg1;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_struct_T(sp, &stats, 1, &v_emlrtRTEI, true);
  emxInit_real_T(sp, &varargin_1, 2, &y_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /* The function takes in a binary image where the colours have been segmentated  */
  /* and a rough postion of the object in the image that should be segmented.  */
  /* and it outputs a a bitmask of the the object. */
  /* Input: */
  /* colourBalancedImage = Binary map 984x740 */
  /* centerOfObjectX = Objects center postion in the x-axis */
  /* centerOfObjectY = Objects center postion in the y-axis */
  /* Output: */
  /* SegmentationMask = Binary map 984x740 of the object */
  /* Fill up the hole in the binary image. */
  st.site = &emlrtRSI;
  imfill(SD, &st, colourSegmentationMask, SD->f1.maskFill);

  /* Get the data about the different blobs in the image */
  st.site = &b_emlrtRSI;
  regionprops(&st, SD->f1.maskFill, stats);

  /* Transform the Area and Centroid struct fields into arrays */
  st.site = &c_emlrtRSI;
  b_st.site = &c_emlrtRSI;
  horzcatStructList(&b_st, stats, varargin_1);
  b_st.site = &oc_emlrtRSI;
  c_st.site = &ec_emlrtRSI;
  if (varargin_1->size[1] != 0) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  emxInit_real_T(&b_st, &area, 2, &l_emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  b_st.site = &c_emlrtRSI;
  horzcatStructList(&b_st, stats, varargin_1);
  b_st.site = &oc_emlrtRSI;
  c_st.site = &ec_emlrtRSI;
  n = area->size[0] * area->size[1];
  area->size[0] = input_sizes_idx_1;
  area->size[1] = 1;
  emxEnsureCapacity_real_T(sp, area, n, &l_emlrtRTEI);
  for (n = 0; n < input_sizes_idx_1; n++) {
    area->data[n] = varargin_1->data[n];
  }

  st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  b_horzcatStructList(&b_st, stats, varargin_1);
  b_st.site = &oc_emlrtRSI;
  c_st.site = &ec_emlrtRSI;
  if (varargin_1->size[1] != 0) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  st.site = &d_emlrtRSI;
  b_varargin_1[0] = 2.0;
  b_varargin_1[1] = area->size[0];
  b_st.site = &pc_emlrtRSI;
  b_assertValidSizeArg(&b_st, b_varargin_1);
  n = 1;
  if (input_sizes_idx_1 > 1) {
    n = input_sizes_idx_1;
  }

  maxdimlen = muIntScalarMax_sint32(input_sizes_idx_1, n);
  if (2 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (area->size[0] > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (area->size[0] << 1 != input_sizes_idx_1) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emxInit_real_T(&st, &centroid, 2, &m_emlrtRTEI, true);
  n = centroid->size[0] * centroid->size[1];
  centroid->size[0] = area->size[0];
  centroid->size[1] = 2;
  emxEnsureCapacity_real_T(sp, centroid, n, &m_emlrtRTEI);
  input_sizes_idx_1 = area->size[0];
  for (n = 0; n < input_sizes_idx_1; n++) {
    centroid->data[n] = varargin_1->data[2 * n];
  }

  for (n = 0; n < input_sizes_idx_1; n++) {
    centroid->data[n + centroid->size[0]] = varargin_1->data[2 * n + 1];
  }

  emxFree_real_T(&varargin_1);
  emxInit_boolean_T(sp, &r, 2, &r_emlrtRTEI, true);

  /*  Set all blobs that are samller then 250 pixels to NaN */
  n = r->size[0] * r->size[1];
  r->size[0] = area->size[0];
  r->size[1] = 1;
  emxEnsureCapacity_boolean_T(sp, r, n, &n_emlrtRTEI);
  input_sizes_idx_1 = area->size[0] * area->size[1];
  for (n = 0; n < input_sizes_idx_1; n++) {
    r->data[n] = (area->data[n] > 250.0);
  }

  if (centroid->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(centroid->size[0], r->size[0], &d_emlrtECI, sp);
  }

  emxInit_real_T(sp, &distances, 1, &w_emlrtRTEI, true);
  input_sizes_idx_1 = centroid->size[0];
  n = distances->size[0];
  distances->size[0] = centroid->size[0];
  emxEnsureCapacity_real_T(sp, distances, n, &o_emlrtRTEI);
  for (n = 0; n < input_sizes_idx_1; n++) {
    distances->data[n] = centroid->data[n] * (real_T)r->data[n];
  }

  emlrtSubAssignSizeCheckR2012b(&centroid->size[0], 1, &distances->size[0], 1,
    &c_emlrtECI, sp);
  input_sizes_idx_1 = distances->size[0];
  for (n = 0; n < input_sizes_idx_1; n++) {
    centroid->data[n] = distances->data[n];
  }

  n = r->size[0] * r->size[1];
  r->size[0] = area->size[0];
  r->size[1] = 1;
  emxEnsureCapacity_boolean_T(sp, r, n, &p_emlrtRTEI);
  input_sizes_idx_1 = area->size[0] * area->size[1];
  for (n = 0; n < input_sizes_idx_1; n++) {
    r->data[n] = (area->data[n] > 250.0);
  }

  emxFree_real_T(&area);
  if (centroid->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(centroid->size[0], r->size[0], &b_emlrtECI, sp);
  }

  input_sizes_idx_1 = centroid->size[0];
  n = distances->size[0];
  distances->size[0] = centroid->size[0];
  emxEnsureCapacity_real_T(sp, distances, n, &q_emlrtRTEI);
  for (n = 0; n < input_sizes_idx_1; n++) {
    distances->data[n] = centroid->data[n + centroid->size[0]] * (real_T)r->
      data[n];
  }

  emxFree_boolean_T(&r);
  emlrtSubAssignSizeCheckR2012b(&centroid->size[0], 1, &distances->size[0], 1,
    &emlrtECI, sp);
  input_sizes_idx_1 = distances->size[0];
  for (n = 0; n < input_sizes_idx_1; n++) {
    centroid->data[n + centroid->size[0]] = distances->data[n];
  }

  input_sizes_idx_1 = (centroid->size[0] << 1) - 1;
  maxdimlen = 0;
  for (n = 0; n <= input_sizes_idx_1; n++) {
    if (centroid->data[n] == 0.0) {
      maxdimlen++;
    }
  }

  emxInit_int32_T(sp, &r1, 1, &x_emlrtRTEI, true);
  n = r1->size[0];
  r1->size[0] = maxdimlen;
  emxEnsureCapacity_int32_T(sp, r1, n, &r_emlrtRTEI);
  maxdimlen = 0;
  for (n = 0; n <= input_sizes_idx_1; n++) {
    if (centroid->data[n] == 0.0) {
      r1->data[maxdimlen] = n + 1;
      maxdimlen++;
    }
  }

  input_sizes_idx_1 = r1->size[0] - 1;
  maxdimlen = centroid->size[0] << 1;
  for (n = 0; n <= input_sizes_idx_1; n++) {
    if ((r1->data[n] < 1) || (r1->data[n] > maxdimlen)) {
      emlrtDynamicBoundsCheckR2012b(r1->data[n], 1, maxdimlen, &emlrtBCI, sp);
    }

    centroid->data[r1->data[n] - 1] = rtNaN;
  }

  emxInit_real_T(sp, &c, 2, &ab_emlrtRTEI, true);

  /* Calculate which centroid is closest to the object */
  st.site = &e_emlrtRSI;
  n = c->size[0] * c->size[1];
  c->size[0] = centroid->size[0];
  c->size[1] = 2;
  emxEnsureCapacity_real_T(&st, c, n, &s_emlrtRTEI);
  if (centroid->size[0] != 0) {
    maxdimlen = (centroid->size[0] != 1);
    n = centroid->size[0] - 1;
    for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= n; input_sizes_idx_1++) {
      c->data[input_sizes_idx_1] = centroid->data[maxdimlen * input_sizes_idx_1]
        - centerOfObjectY;
    }

    n = c->size[0] - 1;
    for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= n; input_sizes_idx_1++) {
      c->data[input_sizes_idx_1 + c->size[0]] = centroid->data[maxdimlen *
        input_sizes_idx_1 + centroid->size[0]] - centerOfObjectX;
    }
  }

  st.site = &e_emlrtRSI;
  b_st.site = &ic_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  n = centroid->size[0] * centroid->size[1];
  centroid->size[0] = c->size[0];
  centroid->size[1] = 2;
  emxEnsureCapacity_real_T(&c_st, centroid, n, &t_emlrtRTEI);
  d_st.site = &kc_emlrtRSI;
  maxdimlen = c->size[0] << 1;
  e_st.site = &lc_emlrtRSI;
  overflow = ((1 <= maxdimlen) && (maxdimlen > 2147483646));
  if (overflow) {
    f_st.site = &n_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < maxdimlen; input_sizes_idx_1++)
  {
    centroid->data[input_sizes_idx_1] = c->data[input_sizes_idx_1] * c->
      data[input_sizes_idx_1];
  }

  emxFree_real_T(&c);
  st.site = &e_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  sum(&b_st, centroid, distances);
  overflow = false;
  n = distances->size[0];
  emxFree_real_T(&centroid);
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < n; input_sizes_idx_1++) {
    if (overflow || (distances->data[input_sizes_idx_1] < 0.0)) {
      overflow = true;
    }
  }

  if (overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  b_st.site = &sc_emlrtRSI;
  maxdimlen = distances->size[0];
  c_st.site = &tc_emlrtRSI;
  if (1 > distances->size[0]) {
    overflow = false;
  } else {
    overflow = (distances->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &n_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < maxdimlen; input_sizes_idx_1++)
  {
    distances->data[input_sizes_idx_1] = muDoubleScalarSqrt(distances->
      data[input_sizes_idx_1]);
  }

  st.site = &f_emlrtRSI;
  b_st.site = &uc_emlrtRSI;
  c_st.site = &vc_emlrtRSI;
  d_st.site = &wc_emlrtRSI;
  if (distances->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &xc_emlrtRSI;
  n = distances->size[0];
  if (distances->size[0] <= 2) {
    if (distances->size[0] == 1) {
      idx = 1;
    } else if ((distances->data[0] > distances->data[1]) || (muDoubleScalarIsNaN
                (distances->data[0]) && (!muDoubleScalarIsNaN(distances->data[1]))))
    {
      idx = 2;
    } else {
      idx = 1;
    }
  } else {
    f_st.site = &l_emlrtRSI;
    if (!muDoubleScalarIsNaN(distances->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      g_st.site = &m_emlrtRSI;
      if (distances->size[0] > 2147483646) {
        h_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      input_sizes_idx_1 = 2;
      exitg1 = false;
      while ((!exitg1) && (input_sizes_idx_1 <= distances->size[0])) {
        if (!muDoubleScalarIsNaN(distances->data[input_sizes_idx_1 - 1])) {
          idx = input_sizes_idx_1;
          exitg1 = true;
        } else {
          input_sizes_idx_1++;
        }
      }
    }

    if (idx == 0) {
      idx = 1;
    } else {
      f_st.site = &k_emlrtRSI;
      ex = distances->data[idx - 1];
      maxdimlen = idx + 1;
      g_st.site = &o_emlrtRSI;
      if (idx + 1 > distances->size[0]) {
        overflow = false;
      } else {
        overflow = (distances->size[0] > 2147483646);
      }

      if (overflow) {
        h_st.site = &n_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      for (input_sizes_idx_1 = maxdimlen; input_sizes_idx_1 <= n;
           input_sizes_idx_1++) {
        d = distances->data[input_sizes_idx_1 - 1];
        if (ex > d) {
          ex = d;
          idx = input_sizes_idx_1;
        }
      }
    }
  }

  emxFree_real_T(&distances);

  /* Do an new binary map with only the choosen blob */
  memset(&segmentationMask[0], 0, 728160U * sizeof(boolean_T));
  if ((idx < 1) || (idx > stats->size[0])) {
    emlrtDynamicBoundsCheckR2012b(idx, 1, stats->size[0], &b_emlrtBCI, sp);
  }

  n = r1->size[0];
  r1->size[0] = stats->data[idx - 1].PixelIdxList->size[0];
  emxEnsureCapacity_int32_T(sp, r1, n, &u_emlrtRTEI);
  if (idx > stats->size[0]) {
    emlrtDynamicBoundsCheckR2012b(idx, 1, stats->size[0], &b_emlrtBCI, sp);
  }

  input_sizes_idx_1 = stats->data[idx - 1].PixelIdxList->size[0];
  for (n = 0; n < input_sizes_idx_1; n++) {
    if (idx > stats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, stats->size[0], &b_emlrtBCI, sp);
    }

    maxdimlen = (int32_T)stats->data[idx - 1].PixelIdxList->data[n];
    if ((maxdimlen < 1) || (maxdimlen > 728160)) {
      emlrtDynamicBoundsCheckR2012b(maxdimlen, 1, 728160, &c_emlrtBCI, sp);
    }

    r1->data[n] = maxdimlen;
  }

  emxFree_struct_T(&stats);
  input_sizes_idx_1 = r1->size[0];
  for (n = 0; n < input_sizes_idx_1; n++) {
    segmentationMask[r1->data[n] - 1] = true;
  }

  emxFree_int32_T(&r1);

  /*  Make smother edges in the image. */
  memcpy(&SD->f1.maskFill[0], &segmentationMask[0], 728160U * sizeof(boolean_T));
  st.site = &g_emlrtRSI;
  imerode(SD->f1.maskFill, segmentationMask);
  memcpy(&SD->f1.maskFill[0], &segmentationMask[0], 728160U * sizeof(boolean_T));
  st.site = &h_emlrtRSI;
  imdilate(SD->f1.maskFill, segmentationMask);

  /*  Edge filter, display only the edges of the filter. */
  memcpy(&SD->f1.maskFill[0], &segmentationMask[0], 728160U * sizeof(boolean_T));
  st.site = &i_emlrtRSI;
  MorphologicalEdgeFilter(SD->f1.maskFill, segmentationMask);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (MorphologicalFilters.c) */
