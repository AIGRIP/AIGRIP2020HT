//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_colourBalance_api.cpp
//
//  Code generation for function '_coder_colourBalance_api'
//


// Include files
#include "_coder_colourBalance_api.h"
#include "colourBalance.h"
#include "colourBalance_data.h"
#include "colourBalance_types.h"
#include "rt_nonfinite.h"

// Variable Definitions
static const int32_T iv[3] = { 984, 740, 3 };

// Function Declarations
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2184480];
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *originalImage, const char_T *identifier))[2184480];
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2184480];
static const mxArray *emlrt_marshallOut(const uint8_T u[2184480]);

// Function Definitions
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2184480]
{
  uint8_T (*ret)[2184480];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 3U, iv);
  ret = (uint8_T (*)[2184480])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *originalImage, const char_T *identifier))[2184480]
{
  emlrtMsgIdentifier thisId;
  uint8_T (*y)[2184480];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(originalImage), &thisId);
  emlrtDestroyArray(&originalImage);
  return y;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2184480]
{
  uint8_T (*y)[2184480];
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *emlrt_marshallOut(const uint8_T u[2184480])
{
  static const int32_T b_iv[3] = { 0, 0, 0 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(3, &b_iv[0], mxUINT8_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, *(int32_T (*)[3])&iv[0], 3);
  emlrtAssign(&y, m);
  return y;
}

void colourBalance_api(colourBalanceStackData *SD, const mxArray * const prhs[1],
  const mxArray *plhs[1])
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  uint8_T (*colourBalancedImage)[2184480];
  uint8_T (*originalImage)[2184480];
  st.tls = emlrtRootTLSGlobal;
  colourBalancedImage = (uint8_T (*)[2184480])mxMalloc(sizeof(uint8_T [2184480]));

  // Marshall function inputs
  originalImage = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "originalImage");

  // Invoke the target function
  colourBalance(SD, &st, *originalImage, *colourBalancedImage);

  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*colourBalancedImage);
}

// End of code generation (_coder_colourBalance_api.cpp)
