/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_StableLine_mex.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 02-Dec-2020 17:30:04
 */

/* Include Files */
#include "_coder_StableLine_mex.h"
#include "_coder_StableLine_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void StableLine_mexFunction(int32_T nlhs, mxArray *plhs[14],
  int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[14]
 *                int32_T nrhs
 *                const mxArray *prhs[4]
 * Return Type  : void
 */
void StableLine_mexFunction(int32_T nlhs, mxArray *plhs[14], int32_T nrhs, const
  mxArray *prhs[4])
{
  const mxArray *outputs[14];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        10, "StableLine");
  }

  if (nlhs > 14) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "StableLine");
  }

  /* Call the function. */
  StableLine_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
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
  mexAtExit(&StableLine_atexit);

  /* Module initialization. */
  StableLine_initialize();

  /* Dispatch the entry-point. */
  StableLine_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  StableLine_terminate();
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
 * File trailer for _coder_StableLine_mex.c
 *
 * [EOF]
 */
