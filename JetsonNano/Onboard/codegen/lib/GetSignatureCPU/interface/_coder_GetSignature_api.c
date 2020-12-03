/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_GetSignature_api.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 02-Dec-2020 17:36:28
 */

/* Include Files */
#include "_coder_GetSignature_api.h"
#include "_coder_GetSignature_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131594U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "GetSignature",                      /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static boolean_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[728160];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *degreesToMeasure, const char_T *identifier))[360];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[360];
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *numberOfRows, const char_T *identifier);
static boolean_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *binaryEdgeImage, const char_T *identifier))[728160];
static const mxArray *emlrt_marshallOut(const real_T u[360]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static boolean_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[728160];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[360];
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *degreesToMeasure
 *                const char_T *identifier
 * Return Type  : real_T (*)[360]
 */
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *degreesToMeasure, const char_T *identifier))[360]
{
  real_T (*y)[360];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(degreesToMeasure), &thisId);
  emlrtDestroyArray(&degreesToMeasure);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[360]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[360]
{
  real_T (*y)[360];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *numberOfRows
 *                const char_T *identifier
 * Return Type  : real_T
 */
  static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *numberOfRows, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(numberOfRows), &thisId);
  emlrtDestroyArray(&numberOfRows);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *binaryEdgeImage
 *                const char_T *identifier
 * Return Type  : boolean_T (*)[728160]
 */
static boolean_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *binaryEdgeImage, const char_T *identifier))[728160]
{
  boolean_T (*y)[728160];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(binaryEdgeImage), &thisId);
  emlrtDestroyArray(&binaryEdgeImage);
  return y;
}
/*
 * Arguments    : const real_T u[360]
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const real_T u[360])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 360 };

  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, *(int32_T (*)[1])&iv1[0], 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : boolean_T (*)[728160]
 */
static boolean_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[728160]
{
  boolean_T (*ret)[728160];
  static const int32_T dims[2] = { 984, 740 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 2U, dims);
  ret = (boolean_T (*)[728160])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[360]
 */
  static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void GetSignature_api(const mxArray * const prhs[4], int32_T nlhs, const mxArray
                      *plhs[3])
{
  real_T (*signature)[360];
  real_T (*YCoordToStore)[360];
  real_T (*XCoordToStore)[360];
  boolean_T (*binaryEdgeImage)[728160];
  real_T (*degreesToMeasure)[360];
  real_T numberOfRows;
  real_T numberOfColumns;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  signature = (real_T (*)[360])mxMalloc(sizeof(real_T [360]));
  YCoordToStore = (real_T (*)[360])mxMalloc(sizeof(real_T [360]));
  XCoordToStore = (real_T (*)[360])mxMalloc(sizeof(real_T [360]));

  /* Marshall function inputs */
  binaryEdgeImage = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "binaryEdgeImage");
  degreesToMeasure = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]),
    "degreesToMeasure");
  numberOfRows = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "numberOfRows");
  numberOfColumns = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]),
    "numberOfColumns");

  /* Invoke the target function */
  GetSignature(*binaryEdgeImage, *degreesToMeasure, numberOfRows,
               numberOfColumns, *signature, *YCoordToStore, *XCoordToStore);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*signature);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*YCoordToStore);
  }

  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(*XCoordToStore);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void GetSignature_atexit(void)
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
  GetSignature_xil_terminate();
  GetSignature_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void GetSignature_initialize(void)
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
void GetSignature_terminate(void)
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
 * File trailer for _coder_GetSignature_api.c
 *
 * [EOF]
 */
