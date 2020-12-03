/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_MorphologicalFilters_api.c
 *
 * Code generation for function '_coder_MorphologicalFilters_api'
 *
 */

/* Include files */
#include "_coder_MorphologicalFilters_api.h"
#include "MorphologicalFilters.h"
#include "MorphologicalFilters_data.h"
#include "MorphologicalFilters_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static boolean_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[728160];
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *centerOfObjectX, const char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static boolean_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[728160];
static boolean_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *colourSegmentationMask, const char_T *identifier))[728160];
static const mxArray *emlrt_marshallOut(const boolean_T u[728160]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static boolean_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[728160]
{
  boolean_T (*y)[728160];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *centerOfObjectX, const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(centerOfObjectX), &thisId);
  emlrtDestroyArray(&centerOfObjectX);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[728160]
{
  static const int32_T dims[2] = { 984, 740 };

  boolean_T (*ret)[728160];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 2U, dims);
  ret = (boolean_T (*)[728160])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static boolean_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *colourSegmentationMask, const char_T *identifier))[728160]
{
  emlrtMsgIdentifier thisId;
  boolean_T (*y)[728160];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(colourSegmentationMask), &thisId);
  emlrtDestroyArray(&colourSegmentationMask);
  return y;
}

static const mxArray *emlrt_marshallOut(const boolean_T u[728160])
{
  static const int32_T iv[2] = { 0, 0 };

  static const int32_T iv1[2] = { 984, 740 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateLogicalArray(2, &iv[0]);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void MorphologicalFilters_api(MorphologicalFiltersStackData *SD, const mxArray *
  const prhs[3], const mxArray *plhs[1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T centerOfObjectX;
  real_T centerOfObjectY;
  boolean_T (*colourSegmentationMask)[728160];
  boolean_T (*segmentationMask)[728160];
  st.tls = emlrtRootTLSGlobal;
  segmentationMask = (boolean_T (*)[728160])mxMalloc(sizeof(boolean_T [728160]));

  /* Marshall function inputs */
  colourSegmentationMask = emlrt_marshallIn(&st, emlrtAlias(prhs[0]),
    "colourSegmentationMask");
  centerOfObjectX = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]),
    "centerOfObjectX");
  centerOfObjectY = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]),
    "centerOfObjectY");

  /* Invoke the target function */
  MorphologicalFilters(SD, &st, *colourSegmentationMask, centerOfObjectX,
                       centerOfObjectY, *segmentationMask);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*segmentationMask);
}

/* End of code generation (_coder_MorphologicalFilters_api.c) */
