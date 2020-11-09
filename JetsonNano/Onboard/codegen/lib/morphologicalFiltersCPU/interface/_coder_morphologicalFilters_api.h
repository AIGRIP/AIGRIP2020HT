/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_morphologicalFilters_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 05-Nov-2020 08:33:11
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
  void morphologicalFilters(boolean_T colourSegmentationMask[728160], real_T
    centerOfObjectX, real_T centerOfObjectY, boolean_T segmentationMask[728160]);
  void morphologicalFilters_api(const mxArray * const prhs[3], const mxArray
    *plhs[1]);
  void morphologicalFilters_atexit(void);
  void morphologicalFilters_initialize(void);
  void morphologicalFilters_terminate(void);
  void morphologicalFilters_xil_shutdown(void);
  void morphologicalFilters_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_morphologicalFilters_api.h
 *
 * [EOF]
 */
