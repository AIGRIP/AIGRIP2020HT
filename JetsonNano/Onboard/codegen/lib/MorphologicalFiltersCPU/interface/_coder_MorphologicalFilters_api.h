/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_MorphologicalFilters_api.h
 *
 * Code generation for function 'MorphologicalFilters'
 *
 */

#ifndef _CODER_MORPHOLOGICALFILTERS_API_H
#define _CODER_MORPHOLOGICALFILTERS_API_H

/* Include files */
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
  void MorphologicalFilters(boolean_T colourSegmentationMask[728160], real_T
    centerOfObjectX, real_T centerOfObjectY, real_T *errorNoImage, boolean_T
    segmentationMask[728160]);
  void MorphologicalFilters_api(const mxArray * const prhs[3], int32_T nlhs,
    const mxArray *plhs[2]);
  void MorphologicalFilters_atexit(void);
  void MorphologicalFilters_initialize(void);
  void MorphologicalFilters_terminate(void);
  void MorphologicalFilters_xil_shutdown(void);
  void MorphologicalFilters_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (_coder_MorphologicalFilters_api.h) */
