/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_GetValidGripPoints_api.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 02-Dec-2020 11:25:48
 */

/* Include Files */
#include "_coder_GetValidGripPoints_api.h"
#include "_coder_GetValidGripPoints_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131594U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "GetValidGripPoints",                /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static const mxArray *b_emlrt_marshallOut(const real_T u);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *distanceToObject, const char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *targetPointYPixel, const char_T *identifier, real_T **y_data, int32_T y_size
  [1]);
static const mxArray *emlrt_marshallOut(const uint16_T u[3]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T **y_data
 *                int32_T y_size[1]
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
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
 *                const mxArray *distanceToObject
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *distanceToObject, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(distanceToObject), &thisId);
  emlrtDestroyArray(&distanceToObject);
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
 *                real_T **ret_data
 *                int32_T ret_size[1]
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 11 };

  const boolean_T bv[1] = { true };

  int32_T iv[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv[0],
    iv);
  ret_size[0] = iv[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *targetPointYPixel
 *                const char_T *identifier
 *                real_T **y_data
 *                int32_T y_size[1]
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *targetPointYPixel, const char_T *identifier, real_T **y_data, int32_T y_size
  [1])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(targetPointYPixel), &thisId, y_data, y_size);
  emlrtDestroyArray(&targetPointYPixel);
}

/*
 * Arguments    : const uint16_T u[3]
 * Return Type  : const mxArray *
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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
 * Arguments    : const mxArray * const prhs[6]
 *                int32_T nlhs
 *                const mxArray *plhs[5]
 * Return Type  : void
 */
void GetValidGripPoints_api(const mxArray * const prhs[6], int32_T nlhs, const
  mxArray *plhs[5])
{
  uint16_T (*motorSteps)[3];
  real_T (*targetPointYPixel_data)[11];
  int32_T targetPointYPixel_size[1];
  real_T (*targetPointXPixel_data)[11];
  int32_T targetPointXPixel_size[1];
  real_T (*normalPointYPixel_data)[11];
  int32_T normalPointYPixel_size[1];
  real_T (*normalPointXPixel_data)[11];
  int32_T normalPointXPixel_size[1];
  real_T distanceToObject;
  real_T fingerNumber;
  real_T bestTargetPointY;
  real_T bestTargetPointX;
  real_T bestNormalPointY;
  real_T bestNormalPointX;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  motorSteps = (uint16_T (*)[3])mxMalloc(sizeof(uint16_T [3]));

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "targetPointYPixel", (real_T **)
                   &targetPointYPixel_data, targetPointYPixel_size);
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "targetPointXPixel", (real_T **)
                   &targetPointXPixel_data, targetPointXPixel_size);
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "normalPointYPixel", (real_T **)
                   &normalPointYPixel_data, normalPointYPixel_size);
  emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "normalPointXPixel", (real_T **)
                   &normalPointXPixel_data, normalPointXPixel_size);
  distanceToObject = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]),
    "distanceToObject");
  fingerNumber = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "fingerNumber");

  /* Invoke the target function */
  GetValidGripPoints(*targetPointYPixel_data, targetPointYPixel_size,
                     *targetPointXPixel_data, targetPointXPixel_size,
                     *normalPointYPixel_data, normalPointYPixel_size,
                     *normalPointXPixel_data, normalPointXPixel_size,
                     distanceToObject, fingerNumber, *motorSteps,
                     &bestTargetPointY, &bestTargetPointX, &bestNormalPointY,
                     &bestNormalPointX);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*motorSteps);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(bestTargetPointY);
  }

  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(bestTargetPointX);
  }

  if (nlhs > 3) {
    plhs[3] = b_emlrt_marshallOut(bestNormalPointY);
  }

  if (nlhs > 4) {
    plhs[4] = b_emlrt_marshallOut(bestNormalPointX);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void GetValidGripPoints_atexit(void)
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
  GetValidGripPoints_xil_terminate();
  GetValidGripPoints_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void GetValidGripPoints_initialize(void)
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
void GetValidGripPoints_terminate(void)
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
 * File trailer for _coder_GetValidGripPoints_api.c
 *
 * [EOF]
 */
