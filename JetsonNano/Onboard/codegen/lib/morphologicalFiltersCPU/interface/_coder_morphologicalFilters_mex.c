/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_morphologicalFilters_mex.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 05-Nov-2020 08:33:11
 */

/* Include Files */
#include "_coder_morphologicalFilters_mex.h"
#include "_coder_morphologicalFilters_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&morphologicalFilters_atexit);

  /* Module initialization. */
  morphologicalFilters_initialize();
  try {
    emlrtShouldCleanupOnError(emlrtRootTLSGlobal, false);

    /* Dispatch the entry-point. */
    morphologicalFilters_mexFunction(nlhs, plhs, nrhs, prhs);

    /* Module termination. */
    morphologicalFilters_terminate();
  } catch (...) {
    emlrtCleanupOnException(emlrtRootTLSGlobal);
    throw;
  }
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void morphologicalFilters_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[3])
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
                        20, "morphologicalFilters");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "morphologicalFilters");
  }

  /* Call the function. */
  morphologicalFilters_api(prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

/*
 * File trailer for _coder_morphologicalFilters_mex.c
 *
 * [EOF]
 */
