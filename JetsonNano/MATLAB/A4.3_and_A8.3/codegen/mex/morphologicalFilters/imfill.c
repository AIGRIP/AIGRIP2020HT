/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfill.c
 *
 * Code generation for function 'imfill'
 *
 */

/* Include files */
#include "imfill.h"
#include "MorphologicalFilters_data.h"
#include "MorphologicalFilters_emxutil.h"
#include "MorphologicalFilters_types.h"
#include "rt_nonfinite.h"
#include "libmwippreconstruct.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  986,                                 /* iLast */
  209,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 209,   /* lineNo */
  27,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  984,                                 /* iLast */
  209,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  742,                                 /* iLast */
  209,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  984,                                 /* iLast */
  209,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  740,                                 /* iLast */
  209,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",/* pName */
  3                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  184,                                 /* lineNo */
  9,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 184,/* lineNo */
  22,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

/* Function Definitions */
void imfill(MorphologicalFiltersStackData *SD, const emlrtStack *sp, const
            boolean_T varargin_1[728160], boolean_T I2[728160])
{
  emxArray_real_T *y;
  real_T idx[1968];
  real_T imSizeT[2];
  real_T d;
  real_T d1;
  int32_T iv[1];
  int32_T b_nz;
  int32_T i;
  int32_T j;
  int32_T nz;
  boolean_T x[984];
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  memset(&idx[0], 0, 1968U * sizeof(real_T));
  emxInit_real_T(sp, &y, 2, &cb_emlrtRTEI, true);
  nz = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = 984;
  emxEnsureCapacity_real_T(sp, y, nz, &bb_emlrtRTEI);
  for (nz = 0; nz < 984; nz++) {
    y->data[nz] = (real_T)nz + 2.0;
  }

  iv[0] = 984;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 1, &y->size[0], 2, &e_emlrtECI, sp);
  for (nz = 0; nz < 984; nz++) {
    idx[nz] = y->data[nz];
  }

  nz = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = 740;
  emxEnsureCapacity_real_T(sp, y, nz, &bb_emlrtRTEI);
  for (nz = 0; nz < 740; nz++) {
    y->data[nz] = (real_T)nz + 2.0;
  }

  iv[0] = 740;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 1, &y->size[0], 2, &e_emlrtECI, sp);
  for (nz = 0; nz < 740; nz++) {
    idx[nz + 984] = y->data[nz];
  }

  emxFree_real_T(&y);
  for (i = 0; i < 986; i++) {
    SD->f0.I1[i] = 0U;
    SD->f0.I1[i + 730626] = 0U;
  }

  for (j = 0; j < 740; j++) {
    nz = 986 * (j + 1);
    SD->f0.I1[nz] = 0U;
    SD->f0.I1[nz + 985] = 0U;
    memset(&SD->f0.I1[nz + 1], 255, 984U * sizeof(uint8_T));
  }

  for (nz = 0; nz < 728160; nz++) {
    SD->f0.varargin_1[nz] = (int8_T)varargin_1[nz];
  }

  for (i = 0; i < 986; i++) {
    SD->f0.b[i] = 0U;
    SD->f0.b[i + 730626] = 0U;
  }

  for (j = 0; j < 740; j++) {
    nz = 986 * (j + 1);
    SD->f0.b[nz] = 0U;
    SD->f0.b[nz + 985] = 0U;
    for (i = 0; i < 984; i++) {
      SD->f0.b[(i + nz) + 1] = (uint8_T)SD->f0.varargin_1[i + 984 * j];
    }
  }

  for (nz = 0; nz < 731612; nz++) {
    SD->f0.I1[nz] = (uint8_T)(255U - SD->f0.I1[nz]);
    SD->f0.b[nz] = (uint8_T)(255U - SD->f0.b[nz]);
  }

  imSizeT[0] = 986.0;
  imSizeT[1] = 742.0;
  ippreconstruct_uint8(&SD->f0.I1[0], &SD->f0.b[0], &imSizeT[0], 1.0);
  for (nz = 0; nz < 731612; nz++) {
    SD->f0.I1[nz] = (uint8_T)(255U - SD->f0.I1[nz]);
  }

  for (nz = 0; nz < 984; nz++) {
    x[nz] = (idx[nz] != 0.0);
  }

  b_nz = x[0];
  for (i = 0; i < 983; i++) {
    b_nz += x[i + 1];
  }

  for (nz = 0; nz < 984; nz++) {
    x[nz] = (idx[nz + 984] != 0.0);
  }

  nz = x[0];
  for (i = 0; i < 983; i++) {
    nz += x[i + 1];
  }

  for (i = 0; i < b_nz; i++) {
    for (j = 0; j < nz; j++) {
      if (((int32_T)(i + 1U) < 1) || ((int32_T)(i + 1U) > 984)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(i + 1U), 1, 984, &e_emlrtBCI, sp);
      }

      d = idx[i];
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, sp);
      }

      if (((int32_T)d < 1) || ((int32_T)d > 986)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 986, &d_emlrtBCI, sp);
      }

      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > 984)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, 984, &e_emlrtBCI, sp);
      }

      d1 = idx[j + 984];
      if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
        emlrtIntegerCheckR2012b(d1, &emlrtDCI, sp);
      }

      if (((int32_T)d1 < 1) || ((int32_T)d1 > 742)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 742, &f_emlrtBCI, sp);
      }

      if (((int32_T)(i + 1U) < 1) || ((int32_T)(i + 1U) > 984)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(i + 1U), 1, 984, &g_emlrtBCI, sp);
      }

      if (((int32_T)(j + 1U) < 1) || ((int32_T)(j + 1U) > 740)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(j + 1U), 1, 740, &h_emlrtBCI, sp);
      }

      I2[i + 984 * j] = (SD->f0.I1[((int32_T)d + 986 * ((int32_T)d1 - 1)) - 1]
                         != 0);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (imfill.c) */
