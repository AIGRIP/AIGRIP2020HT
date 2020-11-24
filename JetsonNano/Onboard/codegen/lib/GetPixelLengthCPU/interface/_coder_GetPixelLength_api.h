/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_GetPixelLength_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 24-Nov-2020 07:46:11
 */

#ifndef _CODER_GETPIXELLENGTH_API_H
#define _CODER_GETPIXELLENGTH_API_H

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
  real_T GetPixelLength(boolean_T binaryImage[728160], real_T objectMidPoint,
                        real_T distanceToObject);
  void GetPixelLength_api(const mxArray * const prhs[3], const mxArray *plhs[1]);
  void GetPixelLength_atexit(void);
  void GetPixelLength_initialize(void);
  void GetPixelLength_terminate(void);
  void GetPixelLength_xil_shutdown(void);
  void GetPixelLength_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_GetPixelLength_api.h
 *
 * [EOF]
 */
