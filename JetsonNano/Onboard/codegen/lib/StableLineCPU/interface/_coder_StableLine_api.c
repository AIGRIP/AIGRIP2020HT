/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_StableLine_api.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 02-Dec-2020 17:30:04
 */

/* Include Files */
#include "_coder_StableLine_api.h"
#include "_coder_StableLine_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131594U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "StableLine",                        /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[360];
static const mxArray *b_emlrt_marshallOut(const real_T u);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *YCoordinates, const char_T *identifier))[360];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[360];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[360];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *degreesMeasured, const char_T *identifier))[360];
static const mxArray *emlrt_marshallOut(const real_T u[11]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[360];

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[360]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[360]
{
  real_T (*y)[360];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
  static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *YCoordinates
 *                const char_T *identifier
 * Return Type  : real_T (*)[360]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *YCoordinates, const char_T *identifier))[360]
{
  real_T (*y)[360];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(YCoordinates), &thisId);
  emlrtDestroyArray(&YCoordinates);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[360]
 */
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[360]
{
  real_T (*y)[360];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[360]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[360]
{
  real_T (*ret)[360];
  static const int32_T dims[2] = { 1, 360 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[360])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *degreesMeasured
 *                const char_T *identifier
 * Return Type  : real_T (*)[360]
 */
  static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *degreesMeasured, const char_T *identifier))[360]
{
  real_T (*y)[360];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(degreesMeasured), &thisId);
  emlrtDestroyArray(&degreesMeasured);
  return y;
}

/*
 * Arguments    : const real_T u[11]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[11])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 11 };

  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, *(int32_T (*)[1])&iv1[0], 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[360]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[360]
{
  real_T (*ret)[360];
  static const int32_T dims[1] = { 360 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[360])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray * const prhs[4]
 *                int32_T nlhs
 *                const mxArray *plhs[14]
 * Return Type  : void
 */
  void StableLine_api(const mxArray * const prhs[4], int32_T nlhs, const mxArray
                      *plhs[14])
{
  real_T (*targetPointF1Y)[11];
  real_T (*targetPointF1X)[11];
  real_T (*normalPointF1Y)[11];
  real_T (*normalPointF1X)[11];
  real_T (*targetPointF2Y)[11];
  real_T (*targetPointF2X)[11];
  real_T (*normalPointF2Y)[11];
  real_T (*normalPointF2X)[11];
  real_T (*signatureRadiusTargetF1)[11];
  real_T (*signatureRadiusTargetF2)[11];
  real_T (*degreesMeasured)[360];
  real_T (*YCoordinates)[360];
  real_T (*XCoordinates)[360];
  real_T (*signatureRadius)[360];
  real_T targetPointF0Y;
  real_T targetPointF0X;
  real_T normalPointF0Y;
  real_T normalPointF0X;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  targetPointF1Y = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));
  targetPointF1X = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));
  normalPointF1Y = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));
  normalPointF1X = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));
  targetPointF2Y = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));
  targetPointF2X = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));
  normalPointF2Y = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));
  normalPointF2X = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));
  signatureRadiusTargetF1 = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));
  signatureRadiusTargetF2 = (real_T (*)[11])mxMalloc(sizeof(real_T [11]));

  /* Marshall function inputs */
  degreesMeasured = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "degreesMeasured");
  YCoordinates = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "YCoordinates");
  XCoordinates = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "XCoordinates");
  signatureRadius = c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]),
    "signatureRadius");

  /* Invoke the target function */
  StableLine(*degreesMeasured, *YCoordinates, *XCoordinates, *signatureRadius,
             *targetPointF1Y, *targetPointF1X, *normalPointF1Y, *normalPointF1X,
             *targetPointF2Y, *targetPointF2X, *normalPointF2Y, *normalPointF2X,
             &targetPointF0Y, &targetPointF0X, &normalPointF0Y, &normalPointF0X,
             *signatureRadiusTargetF1, *signatureRadiusTargetF2);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*targetPointF1Y);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*targetPointF1X);
  }

  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(*normalPointF1Y);
  }

  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(*normalPointF1X);
  }

  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(*targetPointF2Y);
  }

  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(*targetPointF2X);
  }

  if (nlhs > 6) {
    plhs[6] = emlrt_marshallOut(*normalPointF2Y);
  }

  if (nlhs > 7) {
    plhs[7] = emlrt_marshallOut(*normalPointF2X);
  }

  if (nlhs > 8) {
    plhs[8] = b_emlrt_marshallOut(targetPointF0Y);
  }

  if (nlhs > 9) {
    plhs[9] = b_emlrt_marshallOut(targetPointF0X);
  }

  if (nlhs > 10) {
    plhs[10] = b_emlrt_marshallOut(normalPointF0Y);
  }

  if (nlhs > 11) {
    plhs[11] = b_emlrt_marshallOut(normalPointF0X);
  }

  if (nlhs > 12) {
    plhs[12] = emlrt_marshallOut(*signatureRadiusTargetF1);
  }

  if (nlhs > 13) {
    plhs[13] = emlrt_marshallOut(*signatureRadiusTargetF2);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void StableLine_atexit(void)
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
  StableLine_xil_terminate();
  StableLine_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void StableLine_initialize(void)
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
void StableLine_terminate(void)
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
 * File trailer for _coder_StableLine_api.c
 *
 * [EOF]
 */
