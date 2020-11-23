//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_PointToLine_mex.cpp
//
//  Code generation for function '_coder_PointToLine_mex'
//


// Include files
#include "_coder_PointToLine_mex.h"
#include "PointToLine_data.h"
#include "PointToLine_initialize.h"
#include "PointToLine_terminate.h"
#include "_coder_PointToLine_api.h"
#include "rt_nonfinite.h"

// Function Definitions
void PointToLine_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[3])
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        11, "PointToLine");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "PointToLine");
  }

  // Call the function.
  PointToLine_api(prhs, outputs);

  // Copy over outputs to the caller.
  emlrtReturnArrays(1, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&PointToLine_atexit);

  // Module initialization.
  PointToLine_initialize();
  try {
    emlrtShouldCleanupOnError(emlrtRootTLSGlobal, false);

    // Dispatch the entry-point.
    PointToLine_mexFunction(nlhs, plhs, nrhs, prhs);

    // Module termination.
    PointToLine_terminate();
  } catch (...) {
    emlrtCleanupOnException(emlrtRootTLSGlobal);
    throw;
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_PointToLine_mex.cpp)
