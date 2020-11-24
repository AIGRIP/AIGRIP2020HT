/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_inverseKinematicsPreshape_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 24-Nov-2020 07:53:31
 */

#ifndef _CODER_INVERSEKINEMATICSPRESHAPE_API_H
#define _CODER_INVERSEKINEMATICSPRESHAPE_API_H

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
  void inverseKinematicsPreshape(real_T linkLengths[5], real_T desiredPosition[2],
    real_T normalStableLine[2], real_T fingerNum, uint16_T motorAngles[3]);
  void inverseKinematicsPreshape_api(const mxArray * const prhs[4], const
    mxArray *plhs[1]);
  void inverseKinematicsPreshape_atexit(void);
  void inverseKinematicsPreshape_initialize(void);
  void inverseKinematicsPreshape_terminate(void);
  void inverseKinematicsPreshape_xil_shutdown(void);
  void inverseKinematicsPreshape_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_inverseKinematicsPreshape_api.h
 *
 * [EOF]
 */
