//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_colourSegmentation_api.cpp
//
//  Code generation for function '_coder_colourSegmentation_api'
//


// Include files
#include "_coder_colourSegmentation_api.h"
#include "colourSegmentation.h"
#include "colourSegmentation_data.h"
#include "colourSegmentation_types.h"
#include "rt_nonfinite.h"

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *centerOfObjectX, const char_T *identifier);
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2184480];
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *colourBalancedImage, const char_T *identifier))[2184480];
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2184480];
static const mxArray *emlrt_marshallOut(const boolean_T u[728160]);

// Function Definitions
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *centerOfObjectX, const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(centerOfObjectX), &thisId);
  emlrtDestroyArray(&centerOfObjectX);
  return y;
}

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2184480]
{
  static const int32_T dims[3] = { 984, 740, 3 };

  uint8_T (*ret)[2184480];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 3U, dims);
  ret = (uint8_T (*)[2184480])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *colourBalancedImage, const char_T *identifier))[2184480]
{
  emlrtMsgIdentifier thisId;
  uint8_T (*y)[2184480];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(colourBalancedImage), &thisId);
  emlrtDestroyArray(&colourBalancedImage);
  return y;
}
  static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2184480]
{
  uint8_T (*y)[2184480];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
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
  emlrtSetDimensions((mxArray *)m, *(int32_T (*)[2])&iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

void colourSegmentation_api(colourSegmentationStackData *SD, const mxArray *
  const prhs[3], const mxArray *plhs[1])
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  real_T centerOfObjectX;
  real_T centerOfObjectY;
  uint8_T (*colourBalancedImage)[2184480];
  boolean_T (*SegmentationMask)[728160];
  st.tls = emlrtRootTLSGlobal;
  SegmentationMask = (boolean_T (*)[728160])mxMalloc(sizeof(boolean_T [728160]));

  // Marshall function inputs
  colourBalancedImage = emlrt_marshallIn(&st, emlrtAlias(prhs[0]),
    "colourBalancedImage");
  centerOfObjectX = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]),
    "centerOfObjectX");
  centerOfObjectY = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]),
    "centerOfObjectY");

  // Invoke the target function
  colourSegmentation(SD, &st, *colourBalancedImage, centerOfObjectX,
                     centerOfObjectY, *SegmentationMask);

  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*SegmentationMask);
}

// End of code generation (_coder_colourSegmentation_api.cpp)
