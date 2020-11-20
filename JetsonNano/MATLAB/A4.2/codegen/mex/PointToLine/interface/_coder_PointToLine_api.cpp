//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_PointToLine_api.cpp
//
//  Code generation for function '_coder_PointToLine_api'
//


// Include files
#include "_coder_PointToLine_api.h"
#include "PointToLine.h"
#include "PointToLine_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *singularityPoint, const char_T *identifier))[2];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static const mxArray *emlrt_marshallOut(const real_T u);

// Function Definitions
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2] = { 1, 2 };

  real_T (*ret)[2];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *singularityPoint, const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(singularityPoint), &thisId);
  emlrtDestroyArray(&singularityPoint);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2]
{
  real_T (*y)[2];
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void PointToLine_api(const mxArray * const prhs[3], const mxArray *plhs[1])
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  real_T (*normalStableLine)[2];
  real_T (*possiblePosition)[2];
  real_T (*singularityPoint)[2];
  real_T positionReachable;
  st.tls = emlrtRootTLSGlobal;

  // Marshall function inputs
  singularityPoint = emlrt_marshallIn(&st, emlrtAlias(prhs[0]),
    "singularityPoint");
  possiblePosition = emlrt_marshallIn(&st, emlrtAlias(prhs[1]),
    "possiblePosition");
  normalStableLine = emlrt_marshallIn(&st, emlrtAlias(prhs[2]),
    "normalStableLine");

  // Invoke the target function
  positionReachable = PointToLine(&st, *singularityPoint, *possiblePosition,
    *normalStableLine);

  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(positionReachable);
}

// End of code generation (_coder_PointToLine_api.cpp)
