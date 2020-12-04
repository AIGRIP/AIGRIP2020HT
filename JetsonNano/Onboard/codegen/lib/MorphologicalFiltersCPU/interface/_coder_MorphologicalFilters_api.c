/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_MorphologicalFilters_api.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 03-Dec-2020 08:29:52
 */

/* Include Files */
#include "_coder_MorphologicalFilters_api.h"
#include "_coder_MorphologicalFilters_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131595U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "MorphologicalFilters",              /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

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
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : boolean_T (*)[728160]
 */
static boolean_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[728160]
{
  boolean_T (*y)[728160];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *centerOfObjectX
 *                const char_T *identifier
 * Return Type  : real_T
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : boolean_T (*)[728160]
 */
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
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *colourSegmentationMask
 *                const char_T *identifier
 * Return Type  : boolean_T (*)[728160]
 */
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

/*
 * Arguments    : const boolean_T u[728160]
 * Return Type  : const mxArray *
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
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

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void MorphologicalFilters_api(const mxArray * const prhs[3], const mxArray *
  plhs[1])
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
  MorphologicalFilters(*colourSegmentationMask, centerOfObjectX, centerOfObjectY,
                       *segmentationMask);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*segmentationMask);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void MorphologicalFilters_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  MorphologicalFilters_xil_terminate();
  MorphologicalFilters_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void MorphologicalFilters_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void MorphologicalFilters_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_MorphologicalFilters_api.c
 *
 * [EOF]
 */
