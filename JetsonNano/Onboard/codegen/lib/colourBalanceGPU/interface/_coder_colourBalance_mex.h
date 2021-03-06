/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_colourBalance_mex.h
 *
 * GPU Coder version                    : 2.0
 * CUDA/C/C++ source code generated on  : 19-Nov-2020 17:09:04
 */

#ifndef _CODER_COLOURBALANCE_MEX_H
#define _CODER_COLOURBALANCE_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void colourBalance_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
    const mxArray *prhs[1]);
  MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T
    nrhs, const mxArray *prhs[]);
  emlrtCTX mexFunctionCreateRootTLS(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_colourBalance_mex.h
 *
 * [EOF]
 */
