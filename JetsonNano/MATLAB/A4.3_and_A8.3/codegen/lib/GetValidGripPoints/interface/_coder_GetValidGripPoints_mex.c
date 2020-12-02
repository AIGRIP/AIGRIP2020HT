/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_GetValidGripPoints_mex.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 02-Dec-2020 11:25:48
 */

/* Include Files */
#include "_coder_GetValidGripPoints_mex.h"
#include "_coder_GetValidGripPoints_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void GetValidGripPoints_mexFunction(int32_T nlhs, mxArray
  *plhs[5], int32_T nrhs, const mxArray *prhs[6]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[5]
 *                int32_T nrhs
 *                const mxArray *prhs[6]
 * Return Type  : void
 */
void GetValidGripPoints_mexFunction(int32_T nlhs, mxArray *plhs[5], int32_T nrhs,
  const mxArray *prhs[6])
{
  const mxArray *outputs[5];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        18, "GetValidGripPoints");
  }

  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "GetValidGripPoints");
  }

  /* Call the function. */
  GetValidGripPoints_api(prhs, nlhs, outputs);

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
  mexAtExit(&GetValidGripPoints_atexit);

  /* Module initialization. */
  GetValidGripPoints_initialize();

  /* Dispatch the entry-point. */
  GetValidGripPoints_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  GetValidGripPoints_terminate();
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
 * File trailer for _coder_GetValidGripPoints_mex.c
 *
 * [EOF]
 */
