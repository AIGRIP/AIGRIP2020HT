/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_colourSegmentation_mex.c
 *
 * Code generation for function '_coder_colourSegmentation_mex'
 *
 */

/* Include files */
#include "_coder_colourSegmentation_mex.h"
#include "_coder_colourSegmentation_api.h"
#include "colourSegmentation_data.h"
#include "colourSegmentation_initialize.h"
#include "colourSegmentation_terminate.h"
#include "colourSegmentation_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void colourSegmentation_mexFunction(colourSegmentationStackData *SD, int32_T
  nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        18, "colourSegmentation");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "colourSegmentation");
  }

  /* Call the function. */
  colourSegmentation_api(SD, prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  colourSegmentationStackData *c_colourSegmentationStackDataGl = NULL;
  c_colourSegmentationStackDataGl = (colourSegmentationStackData *)emlrtMxCalloc
    (1, (size_t)1U * sizeof(colourSegmentationStackData));
  mexAtExit(&colourSegmentation_atexit);

  /* Module initialization. */
  colourSegmentation_initialize();

  /* Dispatch the entry-point. */
  colourSegmentation_mexFunction(c_colourSegmentationStackDataGl, nlhs, plhs,
    nrhs, prhs);

  /* Module termination. */
  colourSegmentation_terminate();
  emlrtMxFree(c_colourSegmentationStackDataGl);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_colourSegmentation_mex.c) */
