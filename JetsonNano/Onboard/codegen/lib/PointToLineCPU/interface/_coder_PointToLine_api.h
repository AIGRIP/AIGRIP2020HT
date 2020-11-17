/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_PointToLine_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 17-Nov-2020 09:18:26
 */

#ifndef _CODER_POINTTOLINE_API_H
#define _CODER_POINTTOLINE_API_H

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
  real_T PointToLine(real_T singularityPoint[2], real_T possiblePosition[2],
                     real_T normalStableLine[2]);
  void PointToLine_api(const mxArray * const prhs[3], const mxArray *plhs[1]);
  void PointToLine_atexit(void);
  void PointToLine_initialize(void);
  void PointToLine_terminate(void);
  void PointToLine_xil_shutdown(void);
  void PointToLine_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_PointToLine_api.h
 *
 * [EOF]
 */
