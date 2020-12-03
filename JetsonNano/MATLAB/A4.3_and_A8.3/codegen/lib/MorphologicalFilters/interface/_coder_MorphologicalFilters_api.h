/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_MorphologicalFilters_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 03-Dec-2020 08:29:52
 */

#ifndef _CODER_MORPHOLOGICALFILTERS_API_H
#define _CODER_MORPHOLOGICALFILTERS_API_H

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
  void MorphologicalFilters(boolean_T colourSegmentationMask[728160], real_T
    centerOfObjectX, real_T centerOfObjectY, boolean_T segmentationMask[728160]);
  void MorphologicalFilters_api(const mxArray * const prhs[3], const mxArray
    *plhs[1]);
  void MorphologicalFilters_atexit(void);
  void MorphologicalFilters_initialize(void);
  void MorphologicalFilters_terminate(void);
  void MorphologicalFilters_xil_shutdown(void);
  void MorphologicalFilters_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_MorphologicalFilters_api.h
 *
 * [EOF]
 */
