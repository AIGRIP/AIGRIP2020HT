/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_colourBalance_api.c
 *
 * GPU Coder version                    : 2.0
 * CUDA/C/C++ source code generated on  : 19-Nov-2020 17:09:04
 */

/* Include Files */
#include "_coder_colourBalance_api.h"
#include "_coder_colourBalance_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131595U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "colourBalance",                     /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

static const int32_T iv[3] = { 984, 740, 3 };

/* Function Declarations */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2184480];
static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2184480];
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *originalImage, const char_T *identifier))[2184480];
static const mxArray *emlrt_marshallOut(const uint8_T u[2184480]);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : uint8_T (*)[2184480]
 */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2184480]
{
  uint8_T (*y)[2184480];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : uint8_T (*)[2184480]
 */
  static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2184480]
{
  uint8_T (*ret)[2184480];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 3U, iv);
  ret = (uint8_T (*)[2184480])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *originalImage
 *                const char_T *identifier
 * Return Type  : uint8_T (*)[2184480]
 */
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *originalImage, const char_T *identifier))[2184480]
{
  emlrtMsgIdentifier thisId;
  uint8_T (*y)[2184480];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(originalImage), &thisId);
  emlrtDestroyArray(&originalImage);
  return y;
}
/*
 * Arguments    : const uint8_T u[2184480]
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const uint8_T u[2184480])
{
  static const int32_T b_iv[3] = { 0, 0, 0 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(3, &b_iv[0], mxUINT8_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv, 3);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const mxArray * const prhs[1]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void colourBalance_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  uint8_T (*colourBalancedImage)[2184480];
  uint8_T (*originalImage)[2184480];
  st.tls = emlrtRootTLSGlobal;
  colourBalancedImage = (uint8_T (*)[2184480])mxMalloc(sizeof(uint8_T [2184480]));

  /* Marshall function inputs */
  originalImage = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "originalImage");

  /* Invoke the target function */
  colourBalance(*originalImage, *colourBalancedImage);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*colourBalancedImage);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void colourBalance_atexit(void)
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
  colourBalance_xil_terminate();
  colourBalance_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void colourBalance_initialize(void)
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
void colourBalance_terminate(void)
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
 * File trailer for _coder_colourBalance_api.c
 *
 * [EOF]
 */
