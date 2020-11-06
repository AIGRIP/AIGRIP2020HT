//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_colourBalance_mex.cpp
//
//  Code generation for function '_coder_colourBalance_mex'
//


// Include files
#include "_coder_colourBalance_mex.h"
#include "_coder_colourBalance_api.h"
#include "colourBalance_data.h"
#include "colourBalance_initialize.h"
#include "colourBalance_terminate.h"
#include "colourBalance_types.h"
#include "rt_nonfinite.h"

// Function Definitions
void colourBalance_mexFunction(colourBalanceStackData *SD, int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[1])
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        13, "colourBalance");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "colourBalance");
  }

  // Call the function.
  colourBalance_api(SD, prhs, outputs);

  // Copy over outputs to the caller.
  emlrtReturnArrays(1, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  colourBalanceStackData *colourBalanceStackDataGlobal = NULL;
  colourBalanceStackDataGlobal = new colourBalanceStackData;
  mexAtExit(&colourBalance_atexit);

  // Module initialization.
  colourBalance_initialize();
  try {
    emlrtShouldCleanupOnError(emlrtRootTLSGlobal, false);

    // Dispatch the entry-point.
    colourBalance_mexFunction(colourBalanceStackDataGlobal, nlhs, plhs, nrhs,
      prhs);

    // Module termination.
    colourBalance_terminate();
  } catch (...) {
    emlrtCleanupOnException(emlrtRootTLSGlobal);
    throw;
  }

  delete colourBalanceStackDataGlobal;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_colourBalance_mex.cpp)
