/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_morphologicalFilters_mex.c
 *
 * Code generation for function '_coder_morphologicalFilters_mex'
 *
 */

/* Include files */
#include "_coder_morphologicalFilters_mex.h"
#include "_coder_morphologicalFilters_api.h"
#include "morphologicalFilters_data.h"
#include "morphologicalFilters_initialize.h"
#include "morphologicalFilters_terminate.h"
#include "morphologicalFilters_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  morphologicalFiltersStackData *c_morphologicalFiltersStackData = NULL;
  c_morphologicalFiltersStackData = (morphologicalFiltersStackData *)
    emlrtMxCalloc(1, (size_t)1U * sizeof(morphologicalFiltersStackData));
  mexAtExit(&morphologicalFilters_atexit);

  /* Module initialization. */
  morphologicalFilters_initialize();

  /* Dispatch the entry-point. */
  morphologicalFilters_mexFunction(c_morphologicalFiltersStackData, nlhs, plhs,
    nrhs, prhs);

  /* Module termination. */
  morphologicalFilters_terminate();
  emlrtMxFree(c_morphologicalFiltersStackData);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

void morphologicalFilters_mexFunction(morphologicalFiltersStackData *SD, int32_T
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
                        20, "morphologicalFilters");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "morphologicalFilters");
  }

  /* Call the function. */
  morphologicalFilters_api(SD, prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

/* End of code generation (_coder_morphologicalFilters_mex.c) */
