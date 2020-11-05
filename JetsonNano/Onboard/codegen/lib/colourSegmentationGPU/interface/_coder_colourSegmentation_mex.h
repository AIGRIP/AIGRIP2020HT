/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_colourSegmentation_mex.h
 *
 * GPU Coder version                    : 2.0
 * CUDA/C/C++ source code generated on  : 05-Nov-2020 09:20:00
 */

#ifndef _CODER_COLOURSEGMENTATION_MEX_H
#define _CODER_COLOURSEGMENTATION_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void colourSegmentation_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
    nrhs, const mxArray *prhs[3]);
  MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T
    nrhs, const mxArray *prhs[]);
  emlrtCTX mexFunctionCreateRootTLS(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_colourSegmentation_mex.h
 *
 * [EOF]
 */
