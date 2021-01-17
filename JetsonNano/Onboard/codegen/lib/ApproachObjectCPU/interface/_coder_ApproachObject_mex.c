/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ApproachObject_mex.c
 *
 * Code generation for function '_coder_ApproachObject_mex'
 *
 */

/* Include files */
#include "_coder_ApproachObject_mex.h"
#include "_coder_ApproachObject_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void ApproachObject_mexFunction(int32_T nlhs, mxArray *plhs
  [1], int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */
void ApproachObject_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[4])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        14, "ApproachObject");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "ApproachObject");
  }

  /* Call the function. */
  ApproachObject_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&ApproachObject_atexit);

  /* Module initialization. */
  ApproachObject_initialize();

  /* Dispatch the entry-point. */
  ApproachObject_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  ApproachObject_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_ApproachObject_mex.c) */
