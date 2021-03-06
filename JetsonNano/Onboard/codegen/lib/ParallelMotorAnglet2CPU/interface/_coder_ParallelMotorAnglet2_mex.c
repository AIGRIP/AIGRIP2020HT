/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_ParallelMotorAnglet2_mex.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 24-Nov-2020 08:45:51
 */

/* Include Files */
#include "_coder_ParallelMotorAnglet2_mex.h"
#include "_coder_ParallelMotorAnglet2_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[4]
 * Return Type  : void
 */
void ParallelMotorAnglet2_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[4])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        20, "ParallelMotorAnglet2");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "ParallelMotorAnglet2");
  }

  /* Call the function. */
  ParallelMotorAnglet2_api(prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

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
  mexAtExit(&ParallelMotorAnglet2_atexit);

  /* Module initialization. */
  ParallelMotorAnglet2_initialize();
  try {
    emlrtShouldCleanupOnError(emlrtRootTLSGlobal, false);

    /* Dispatch the entry-point. */
    ParallelMotorAnglet2_mexFunction(nlhs, plhs, nrhs, prhs);

    /* Module termination. */
    ParallelMotorAnglet2_terminate();
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
 * File trailer for _coder_ParallelMotorAnglet2_mex.c
 *
 * [EOF]
 */
