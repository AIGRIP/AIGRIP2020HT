/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * regionprops.c
 *
 * Code generation for function 'regionprops'
 *
 */

/* Include files */
#include "regionprops.h"
#include "assertValidSizeArg.h"
#include "bwconncomp.h"
#include "eml_int_forloop_overflow_check.h"
#include "morphologicalFilters_data.h"
#include "morphologicalFilters_emxutil.h"
#include "morphologicalFilters_types.h"
#include "rt_nonfinite.h"
#include "useConstantDim.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  boolean_T Area;
  boolean_T Centroid;
  boolean_T BoundingBox;
  boolean_T MajorAxisLength;
  boolean_T MinorAxisLength;
  boolean_T Eccentricity;
  boolean_T Orientation;
  boolean_T Image;
  boolean_T FilledImage;
  boolean_T FilledArea;
  boolean_T EulerNumber;
  boolean_T Extrema;
  boolean_T EquivDiameter;
  boolean_T Extent;
  boolean_T PixelIdxList;
  boolean_T PixelList;
  boolean_T Perimeter;
  boolean_T Circularity;
  boolean_T PixelValues;
  boolean_T WeightedCentroid;
  boolean_T MeanIntensity;
  boolean_T MinIntensity;
  boolean_T MaxIntensity;
  boolean_T SubarrayIdx;
} struct_T;

#endif                                 /*typedef_struct_T*/

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 197, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 99,  /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 87,  /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 78,  /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 75,  /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 73,  /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 32,  /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 1293,/* lineNo */
  "parseInputsAndInitializeOutStruct", /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 1468,/* lineNo */
  "getPropsFromInputAndInitializeOutStruct",/* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 28, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 1840,/* lineNo */
  "initializeStatsStruct",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 295,/* lineNo */
  "ComputePixelIdxList",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 770,/* lineNo */
  "ComputePixelList",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 772,/* lineNo */
  "ComputePixelList",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 19, /* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 22, /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 420,/* lineNo */
  "ComputeCentroid",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 424,/* lineNo */
  "ComputeCentroid",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 49, /* lineNo */
  "mean",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pathName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "ComputeArea",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1896,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1898,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1896,                                /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "ComputeArea",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1896,                                /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  424,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "ComputeCentroid",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  769,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelList",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  770,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelList",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = { 283,/* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 38,/* lineNo */
  15,                                  /* colNo */
  "ind2sub_indexClass",                /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  774,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelList",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  772,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelList",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  424,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "ComputeCentroid",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo db_emlrtRTEI = { 1468,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 1840,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 295,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 298,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 1896,/* lineNo */
  50,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 1,/* lineNo */
  23,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 1380,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 1719,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 220,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 234,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 774,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 772,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

/* Function Declarations */
static void ComputeCentroid(const emlrtStack *sp, b_emxArray_struct_T *stats,
  struct_T *statsAlreadyComputed);

/* Function Definitions */
static void ComputeCentroid(const emlrtStack *sp, b_emxArray_struct_T *stats,
  struct_T *statsAlreadyComputed)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_int32_T *idx;
  emxArray_int32_T *vk;
  real_T y_idx_0;
  real_T y_idx_1;
  int32_T b_k;
  int32_T i;
  int32_T k;
  int32_T vlen;
  int32_T xpageoffset;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (!statsAlreadyComputed->Centroid) {
    statsAlreadyComputed->Centroid = true;
    st.site = &cc_emlrtRSI;
    if (!statsAlreadyComputed->PixelList) {
      statsAlreadyComputed->PixelList = true;
      i = stats->size[0];
      emxInit_int32_T(&st, &idx, 1, &gc_emlrtRTEI, true);
      emxInit_int32_T(&st, &vk, 1, &ic_emlrtRTEI, true);
      for (k = 0; k < i; k++) {
        b_k = stats->size[0];
        vlen = k + 1;
        if ((vlen < 1) || (vlen > b_k)) {
          emlrtDynamicBoundsCheckR2012b(vlen, 1, b_k, &pc_emlrtBCI, &st);
        }

        if (stats->data[k].PixelIdxList->size[0] != 0) {
          b_st.site = &wb_emlrtRSI;
          b_k = stats->size[0];
          if (vlen > b_k) {
            emlrtDynamicBoundsCheckR2012b(vlen, 1, b_k, &qc_emlrtBCI, &b_st);
          }

          c_st.site = &yb_emlrtRSI;
          b_k = idx->size[0];
          idx->size[0] = stats->data[k].PixelIdxList->size[0];
          emxEnsureCapacity_int32_T(&c_st, idx, b_k, &gc_emlrtRTEI);
          vlen = stats->data[k].PixelIdxList->size[0];
          for (b_k = 0; b_k < vlen; b_k++) {
            idx->data[b_k] = (int32_T)stats->data[k].PixelIdxList->data[b_k];
          }

          b_k = 0;
          exitg1 = false;
          while ((!exitg1) && (b_k <= idx->size[0] - 1)) {
            if (idx->data[b_k] <= 728160) {
              b_k++;
            } else {
              emlrtErrorWithMessageIdR2018a(&c_st, &k_emlrtRTEI,
                "Coder:MATLAB:ind2sub_IndexOutOfRange",
                "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
            }
          }

          vlen = idx->size[0];
          for (b_k = 0; b_k < vlen; b_k++) {
            idx->data[b_k]--;
          }

          b_k = vk->size[0];
          vk->size[0] = idx->size[0];
          emxEnsureCapacity_int32_T(&c_st, vk, b_k, &ic_emlrtRTEI);
          vlen = idx->size[0];
          for (b_k = 0; b_k < vlen; b_k++) {
            vk->data[b_k] = idx->data[b_k] / 984;
          }

          vlen = idx->size[0];
          for (b_k = 0; b_k < vlen; b_k++) {
            idx->data[b_k] -= vk->data[b_k] * 984;
          }

          vlen = idx->size[0];
          for (b_k = 0; b_k < vlen; b_k++) {
            idx->data[b_k]++;
          }

          vlen = vk->size[0];
          for (b_k = 0; b_k < vlen; b_k++) {
            vk->data[b_k]++;
          }

          b_st.site = &xb_emlrtRSI;
          c_st.site = &ac_emlrtRSI;
          d_st.site = &bc_emlrtRSI;
          if (idx->size[0] != vk->size[0]) {
            emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI,
              "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
          }

          xpageoffset = stats->size[0];
          if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > xpageoffset)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, xpageoffset,
              &sc_emlrtBCI, &c_st);
          }

          b_k = stats->data[k].PixelList->size[0] * stats->data[k]
            .PixelList->size[1];
          stats->data[k].PixelList->size[0] = vk->size[0];
          emxEnsureCapacity_real_T(&c_st, stats->data[k].PixelList, b_k,
            &jc_emlrtRTEI);
          if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > xpageoffset)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, xpageoffset,
              &sc_emlrtBCI, &c_st);
          }

          b_k = stats->data[k].PixelList->size[0] * stats->data[k]
            .PixelList->size[1];
          stats->data[k].PixelList->size[1] = 2;
          emxEnsureCapacity_real_T(&c_st, stats->data[k].PixelList, b_k,
            &jc_emlrtRTEI);
          vlen = vk->size[0];
          for (b_k = 0; b_k < vlen; b_k++) {
            if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > xpageoffset)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, xpageoffset,
                &sc_emlrtBCI, &c_st);
            }

            stats->data[k].PixelList->data[b_k] = vk->data[b_k];
          }

          vlen = idx->size[0];
          for (b_k = 0; b_k < vlen; b_k++) {
            if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > xpageoffset)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, xpageoffset,
                &sc_emlrtBCI, &c_st);
            }

            stats->data[k].PixelList->data[b_k + stats->data[k].PixelList->size
              [0]] = idx->data[b_k];
          }
        } else {
          b_k = stats->size[0];
          if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > b_k)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, b_k,
              &rc_emlrtBCI, &st);
          }

          stats->data[k].PixelList->size[0] = 0;
          b_k = stats->size[0];
          if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > b_k)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, b_k,
              &rc_emlrtBCI, &st);
          }

          b_k = stats->data[k].PixelList->size[0] * stats->data[k]
            .PixelList->size[1];
          stats->data[k].PixelList->size[1] = 2;
          emxEnsureCapacity_real_T(&st, stats->data[k].PixelList, b_k,
            &hc_emlrtRTEI);
          b_k = stats->size[0];
          if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > b_k)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, b_k,
              &rc_emlrtBCI, &st);
          }

          b_k = stats->size[0];
          if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > b_k)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, b_k,
              &rc_emlrtBCI, &st);
          }
        }
      }

      emxFree_int32_T(&vk);
      emxFree_int32_T(&idx);
    }

    i = stats->size[0];
    for (k = 0; k < i; k++) {
      st.site = &dc_emlrtRSI;
      b_k = stats->size[0];
      vlen = k + 1;
      if ((vlen < 1) || (vlen > b_k)) {
        emlrtDynamicBoundsCheckR2012b(vlen, 1, b_k, &oc_emlrtBCI, &st);
      }

      b_st.site = &ec_emlrtRSI;
      vlen = stats->data[k].PixelList->size[0];
      if (stats->data[k].PixelList->size[0] == 0) {
        y_idx_0 = 0.0;
        y_idx_1 = 0.0;
      } else {
        c_st.site = &jb_emlrtRSI;
        overflow = ((2 <= vlen) && (vlen > 2147483646));
        y_idx_0 = stats->data[k].PixelList->data[0];
        d_st.site = &kb_emlrtRSI;
        if (overflow) {
          e_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (b_k = 2; b_k <= vlen; b_k++) {
          y_idx_0 += stats->data[k].PixelList->data[b_k - 1];
        }

        xpageoffset = stats->data[k].PixelList->size[0];
        y_idx_1 = stats->data[k].PixelList->data[xpageoffset];
        d_st.site = &kb_emlrtRSI;
        for (b_k = 2; b_k <= vlen; b_k++) {
          y_idx_1 += stats->data[k].PixelList->data[(xpageoffset + b_k) - 1];
        }
      }

      xpageoffset = stats->data[k].PixelList->size[0];
      vlen = stats->size[0];
      if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > vlen)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, vlen, &tc_emlrtBCI,
          &st);
      }

      stats->data[k].Centroid[0] = y_idx_0 / (real_T)xpageoffset;
      if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > vlen)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, vlen, &tc_emlrtBCI,
          &st);
      }

      stats->data[k].Centroid[1] = y_idx_1 / (real_T)xpageoffset;
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void regionprops(const emlrtStack *sp, const boolean_T varargin_1[728160],
                 emxArray_struct_T *outstats)
{
  b_emxArray_struct_T *stats;
  b_struct_T statsOneObj;
  c_struct_T b_statsOneObj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *idxCount;
  emxArray_int32_T *regionLengths;
  emxArray_real_T *CC_RegionIndices;
  struct_T statsAlreadyComputed;
  real_T CC_ImageSize[2];
  real_T CC_NumObjects;
  real_T expl_temp;
  int32_T b_stats;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &CC_RegionIndices, 1, &ib_emlrtRTEI, true);
  emxInitStruct_struct_T(sp, &statsOneObj, &kb_emlrtRTEI, true);
  emxInit_int32_T(sp, &regionLengths, 1, &mb_emlrtRTEI, true);
  st.site = &t_emlrtRSI;
  bwconncomp(&st, varargin_1, &expl_temp, CC_ImageSize, &CC_NumObjects,
             CC_RegionIndices, regionLengths);
  st.site = &s_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  statsOneObj.Area = 0.0;
  statsOneObj.Centroid[0] = 0.0;
  statsOneObj.Centroid[1] = 0.0;
  statsOneObj.PixelIdxList->size[0] = 0;
  c_st.site = &sb_emlrtRSI;
  d_st.site = &tb_emlrtRSI;
  assertValidSizeArg(&d_st, CC_NumObjects);
  i = outstats->size[0];
  outstats->size[0] = (int32_T)CC_NumObjects;
  emxEnsureCapacity_struct_T(&c_st, outstats, i, &db_emlrtRTEI);
  loop_ub = (int32_T)CC_NumObjects;
  for (i = 0; i < loop_ub; i++) {
    emxCopyStruct_struct_T(&c_st, &outstats->data[i], &statsOneObj,
      &db_emlrtRTEI);
  }

  emxFreeStruct_struct_T(&statsOneObj);
  emxInitStruct_struct_T1(&c_st, &b_statsOneObj, &lb_emlrtRTEI, true);
  st.site = &r_emlrtRSI;
  b_statsOneObj.Area = 0.0;
  statsAlreadyComputed.Centroid = false;
  b_statsOneObj.Centroid[0] = 0.0;
  b_statsOneObj.Centroid[1] = 0.0;
  statsAlreadyComputed.BoundingBox = false;
  b_statsOneObj.BoundingBox[0] = 0.0;
  b_statsOneObj.BoundingBox[1] = 0.0;
  b_statsOneObj.BoundingBox[2] = 0.0;
  b_statsOneObj.BoundingBox[3] = 0.0;
  statsAlreadyComputed.MajorAxisLength = false;
  b_statsOneObj.MajorAxisLength = 0.0;
  statsAlreadyComputed.MinorAxisLength = false;
  b_statsOneObj.MinorAxisLength = 0.0;
  statsAlreadyComputed.Eccentricity = false;
  b_statsOneObj.Eccentricity = 0.0;
  statsAlreadyComputed.Orientation = false;
  b_statsOneObj.Orientation = 0.0;
  statsAlreadyComputed.Image = false;
  b_statsOneObj.Image->size[0] = 0;
  b_statsOneObj.Image->size[1] = 0;
  statsAlreadyComputed.FilledImage = false;
  b_statsOneObj.FilledImage->size[0] = 0;
  b_statsOneObj.FilledImage->size[1] = 0;
  statsAlreadyComputed.FilledArea = false;
  b_statsOneObj.FilledArea = 0.0;
  statsAlreadyComputed.EulerNumber = false;
  b_statsOneObj.EulerNumber = 0.0;
  statsAlreadyComputed.Extrema = false;
  memset(&b_statsOneObj.Extrema[0], 0, 16U * sizeof(real_T));
  emxInit_struct_T1(&st, &stats, 1, &jb_emlrtRTEI, true);
  statsAlreadyComputed.EquivDiameter = false;
  b_statsOneObj.EquivDiameter = 0.0;
  statsAlreadyComputed.Extent = false;
  b_statsOneObj.Extent = 0.0;
  b_statsOneObj.PixelIdxList->size[0] = 0;
  statsAlreadyComputed.PixelList = false;
  b_statsOneObj.PixelList->size[0] = 0;
  b_statsOneObj.PixelList->size[1] = 2;
  statsAlreadyComputed.Perimeter = false;
  b_statsOneObj.Perimeter = 0.0;
  statsAlreadyComputed.Circularity = false;
  b_statsOneObj.Circularity = 0.0;
  statsAlreadyComputed.PixelValues = false;
  b_statsOneObj.PixelValues->size[0] = 0;
  statsAlreadyComputed.WeightedCentroid = false;
  statsAlreadyComputed.MeanIntensity = false;
  b_statsOneObj.MeanIntensity = 0.0;
  statsAlreadyComputed.MinIntensity = false;
  b_statsOneObj.MinIntensity = 0.0;
  statsAlreadyComputed.MaxIntensity = false;
  b_statsOneObj.MaxIntensity = 0.0;
  statsAlreadyComputed.SubarrayIdx = false;
  b_statsOneObj.SubarrayIdx->size[0] = 1;
  b_statsOneObj.SubarrayIdx->size[1] = 0;
  b_statsOneObj.WeightedCentroid[0] = 0.0;
  b_statsOneObj.SubarrayIdxLengths[0] = 0.0;
  b_statsOneObj.WeightedCentroid[1] = 0.0;
  b_statsOneObj.SubarrayIdxLengths[1] = 0.0;
  b_st.site = &ub_emlrtRSI;
  c_st.site = &tb_emlrtRSI;
  assertValidSizeArg(&c_st, CC_NumObjects);
  i = stats->size[0];
  stats->size[0] = (int32_T)CC_NumObjects;
  emxEnsureCapacity_struct_T1(&b_st, stats, i, &eb_emlrtRTEI);
  loop_ub = (int32_T)CC_NumObjects;
  for (i = 0; i < loop_ub; i++) {
    emxCopyStruct_struct_T1(&b_st, &stats->data[i], &b_statsOneObj,
      &eb_emlrtRTEI);
  }

  emxFreeStruct_struct_T1(&b_statsOneObj);
  st.site = &q_emlrtRSI;
  statsAlreadyComputed.PixelIdxList = true;
  if (CC_NumObjects != 0.0) {
    b_st.site = &vb_emlrtRSI;
    c_st.site = &lb_emlrtRSI;
    loop_ub = 2;
    if (regionLengths->size[0] != 1) {
      loop_ub = 1;
    }

    emxInit_int32_T(&c_st, &idxCount, 1, &nb_emlrtRTEI, true);
    d_st.site = &mb_emlrtRSI;
    useConstantDim(&d_st, regionLengths, loop_ub);
    i = idxCount->size[0];
    idxCount->size[0] = regionLengths->size[0] + 1;
    emxEnsureCapacity_int32_T(&st, idxCount, i, &fb_emlrtRTEI);
    idxCount->data[0] = 0;
    loop_ub = regionLengths->size[0];
    for (i = 0; i < loop_ub; i++) {
      idxCount->data[i + 1] = regionLengths->data[i];
    }

    i = (int32_T)CC_NumObjects;
    for (k = 0; k < i; k++) {
      i1 = k + 1;
      if ((i1 < 1) || (i1 > idxCount->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, idxCount->size[0], &i_emlrtBCI, &st);
      }

      if (((int32_T)(((real_T)k + 1.0) + 1.0) < 1) || ((int32_T)(((real_T)k +
             1.0) + 1.0) > idxCount->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(((real_T)k + 1.0) + 1.0), 1,
          idxCount->size[0], &j_emlrtBCI, &st);
      }

      i1 = idxCount->data[k + 1];
      if (idxCount->data[k] + 1 > i1) {
        i2 = 0;
        i1 = 0;
      } else {
        i2 = idxCount->data[k] + 1;
        if ((i2 < 1) || (i2 > CC_RegionIndices->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, CC_RegionIndices->size[0],
            &k_emlrtBCI, &st);
        }

        i2--;
        if ((i1 < 1) || (i1 > CC_RegionIndices->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, CC_RegionIndices->size[0],
            &l_emlrtBCI, &st);
        }
      }

      b_stats = stats->size[0];
      if ((k + 1 < 1) || (k + 1 > stats->size[0])) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, stats->size[0], &v_emlrtBCI, &st);
      }

      loop_ub = i1 - i2;
      i1 = stats->data[k].PixelIdxList->size[0];
      stats->data[k].PixelIdxList->size[0] = loop_ub;
      emxEnsureCapacity_real_T(&st, stats->data[k].PixelIdxList, i1,
        &gb_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        if ((k + 1 < 1) || (k + 1 > b_stats)) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_stats, &v_emlrtBCI, &st);
        }

        stats->data[k].PixelIdxList->data[i1] = CC_RegionIndices->data[i2 + i1];
      }
    }

    emxFree_int32_T(&idxCount);
  }

  emxFree_int32_T(&regionLengths);
  emxFree_real_T(&CC_RegionIndices);
  st.site = &p_emlrtRSI;
  statsAlreadyComputed.Area = true;
  i = stats->size[0];
  for (k = 0; k < i; k++) {
    i1 = k + 1;
    if ((i1 < 1) || (i1 > stats->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, stats->size[0], &m_emlrtBCI, &st);
    }

    if ((k + 1 < 1) || (k + 1 > stats->size[0])) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, stats->size[0], &s_emlrtBCI, &st);
    }

    stats->data[k].Area = stats->data[k].PixelIdxList->size[0];
  }

  st.site = &o_emlrtRSI;
  ComputeCentroid(&st, stats, &statsAlreadyComputed);
  st.site = &n_emlrtRSI;
  i = stats->size[0];
  for (k = 0; k < i; k++) {
    i1 = k + 1;
    if ((i1 < 1) || (i1 > stats->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, stats->size[0], &n_emlrtBCI, &st);
    }

    if (i1 > outstats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, outstats->size[0], &o_emlrtBCI, &st);
    }

    if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > stats->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, stats->size[0],
        &t_emlrtBCI, &st);
    }

    if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > outstats->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, outstats->size[0],
        &u_emlrtBCI, &st);
    }

    outstats->data[k].Area = stats->data[k].Area;
    if (i1 > stats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, stats->size[0], &n_emlrtBCI, &st);
    }

    if (i1 > outstats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, outstats->size[0], &o_emlrtBCI, &st);
    }

    if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > stats->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, stats->size[0],
        &q_emlrtBCI, &st);
    }

    if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > outstats->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, outstats->size[0],
        &r_emlrtBCI, &st);
    }

    outstats->data[k].Centroid[0] = stats->data[k].Centroid[0];
    if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > stats->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, stats->size[0],
        &q_emlrtBCI, &st);
    }

    if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > outstats->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, outstats->size[0],
        &r_emlrtBCI, &st);
    }

    outstats->data[k].Centroid[1] = stats->data[k].Centroid[1];
    if (i1 > outstats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, outstats->size[0], &p_emlrtBCI, &st);
    }

    if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > stats->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, stats->size[0],
        &w_emlrtBCI, &st);
    }

    i2 = outstats->data[k].PixelIdxList->size[0];
    outstats->data[k].PixelIdxList->size[0] = stats->data[k].PixelIdxList->size
      [0];
    emxEnsureCapacity_real_T(&st, outstats->data[k].PixelIdxList, i2,
      &hb_emlrtRTEI);
    if (i1 > outstats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, outstats->size[0], &o_emlrtBCI, &st);
    }

    i2 = outstats->data[k].PixelIdxList->size[0];
    for (b_stats = 0; b_stats < i2; b_stats++) {
      if (i1 > stats->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, stats->size[0], &q_emlrtBCI, &st);
      }

      if (i1 > outstats->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, outstats->size[0], &r_emlrtBCI, &st);
      }

      loop_ub = stats->data[k].PixelIdxList->size[0];
      if ((b_stats + 1 < 1) || (b_stats + 1 > loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(b_stats + 1, 1, loop_ub, &t_emlrtBCI, &st);
      }

      loop_ub = outstats->data[k].PixelIdxList->size[0];
      if ((b_stats + 1 < 1) || (b_stats + 1 > loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(b_stats + 1, 1, loop_ub, &u_emlrtBCI, &st);
      }

      outstats->data[k].PixelIdxList->data[b_stats] = stats->data[k].
        PixelIdxList->data[b_stats];
    }
  }

  emxFree_struct_T1(&stats);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (regionprops.c) */
