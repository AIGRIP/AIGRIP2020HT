/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_MorphologicalFilters_mex.c
 *
 * Code generation for function '_coder_MorphologicalFilters_mex'
 *
 */

/* Include files */
#include "_coder_MorphologicalFilters_mex.h"
#include "MorphologicalFilters_data.h"
#include "MorphologicalFilters_initialize.h"
#include "MorphologicalFilters_terminate.h"
#include "MorphologicalFilters_types.h"
#include "_coder_MorphologicalFilters_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void MorphologicalFilters_mexFunction(MorphologicalFiltersStackData *SD, int32_T
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
                        20, "MorphologicalFilters");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "MorphologicalFilters");
  }

  /* Call the function. */
  MorphologicalFilters_api(SD, prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  MorphologicalFiltersStackData *c_MorphologicalFiltersStackData = NULL;
  c_MorphologicalFiltersStackData = (MorphologicalFiltersStackData *)
    emlrtMxCalloc(1, (size_t)1U * sizeof(MorphologicalFiltersStackData));
  mexAtExit(&MorphologicalFilters_atexit);

  /* Module initialization. */
  MorphologicalFilters_initialize();

  /* Dispatch the entry-point. */
  MorphologicalFilters_mexFunction(c_MorphologicalFiltersStackData, nlhs, plhs,
    nrhs, prhs);

  /* Module termination. */
  MorphologicalFilters_terminate();
  emlrtMxFree(c_MorphologicalFiltersStackData);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_MorphologicalFilters_mex.c) */
