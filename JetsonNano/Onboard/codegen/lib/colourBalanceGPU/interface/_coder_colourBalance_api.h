/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_colourBalance_api.h
 *
 * GPU Coder version                    : 2.0
 * CUDA/C/C++ source code generated on  : 04-Nov-2020 10:52:24
 */

#ifndef _CODER_COLOURBALANCE_API_H
#define _CODER_COLOURBALANCE_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void colourBalance(uint8_T originalImage[2184480], uint8_T
                     colourBalancedImage[2184480]);
  void colourBalance_api(const mxArray * const prhs[1], const mxArray *plhs[1]);
  void colourBalance_atexit(void);
  void colourBalance_initialize(void);
  void colourBalance_terminate(void);
  void colourBalance_xil_shutdown(void);
  void colourBalance_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_colourBalance_api.h
 *
 * [EOF]
 */
