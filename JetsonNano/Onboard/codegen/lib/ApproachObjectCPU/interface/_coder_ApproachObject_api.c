/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ApproachObject_api.c
 *
 * Code generation for function '_coder_ApproachObject_api'
 *
 */

/* Include files */
#include "_coder_ApproachObject_api.h"
#include "_coder_ApproachObject_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131594U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "ApproachObject",                    /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[5];
static uint16_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *currentMotorM0Steps, const char_T *identifier);
static uint16_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *distanceToObject, const char_T *identifier);
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *linkLengths, const char_T *identifier))[5];
static const mxArray *emlrt_marshallOut(const uint16_T u[3]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5];
static uint16_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[5]
{
  real_T (*y)[5];
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static uint16_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *currentMotorM0Steps, const char_T *identifier)
{
  uint16_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(currentMotorM0Steps), &thisId);
  emlrtDestroyArray(&currentMotorM0Steps);
  return y;
}

static uint16_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  uint16_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *distanceToObject, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(distanceToObject), &thisId);
  emlrtDestroyArray(&distanceToObject);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *linkLengths, const char_T *identifier))[5]
{
  real_T (*y)[5];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(linkLengths), &thisId);
  emlrtDestroyArray(&linkLengths);
  return y;
}
  static const mxArray *emlrt_marshallOut(const uint16_T u[3])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  static const int32_T iv1[2] = { 1, 3 };

  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxUINT16_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, *(int32_T (*)[2])&iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5]
{
  real_T (*ret)[5];
  static const int32_T dims[2] = { 1, 5 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[5])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static uint16_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  uint16_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint16", false, 0U, &dims);
  ret = *(uint16_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

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

void ApproachObject_api(const mxArray * const prhs[4], int32_T nlhs, const
  mxArray *plhs[1])
{
  uint16_T (*motorAngles)[3];
  real_T (*linkLengths)[5];
  uint16_T currentMotorM0Steps;
  uint16_T currentMotorM1Steps;
  real_T distanceToObject;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  motorAngles = (uint16_T (*)[3])mxMalloc(sizeof(uint16_T [3]));

  /* Marshall function inputs */
  linkLengths = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "linkLengths");
  currentMotorM0Steps = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]),
    "currentMotorM0Steps");
  currentMotorM1Steps = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]),
    "currentMotorM1Steps");
  distanceToObject = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]),
    "distanceToObject");

  /* Invoke the target function */
  ApproachObject(*linkLengths, currentMotorM0Steps, currentMotorM1Steps,
                 distanceToObject, *motorAngles);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*motorAngles);
}

void ApproachObject_atexit(void)
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
  ApproachObject_xil_terminate();
  ApproachObject_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void ApproachObject_initialize(void)
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

void ApproachObject_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_ApproachObject_api.c) */
