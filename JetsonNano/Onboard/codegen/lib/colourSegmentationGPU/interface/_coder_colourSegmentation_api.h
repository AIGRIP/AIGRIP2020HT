/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_colourSegmentation_api.h
 *
 * GPU Coder version                    : 2.0
 * CUDA/C/C++ source code generated on  : 04-Nov-2020 14:57:40
 */

#ifndef _CODER_COLOURSEGMENTATION_API_H
#define _CODER_COLOURSEGMENTATION_API_H

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
  void colourSegmentation(uint8_T colourBalancedImage[2184480], real_T
    centerOfObjectX, real_T centerOfObjectY, boolean_T SegmentationMask[728160]);
  void colourSegmentation_api(const mxArray * const prhs[3], const mxArray *
    plhs[1]);
  void colourSegmentation_atexit(void);
  void colourSegmentation_initialize(void);
  void colourSegmentation_terminate(void);
  void colourSegmentation_xil_shutdown(void);
  void colourSegmentation_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_colourSegmentation_api.h
 *
 * [EOF]
 */
