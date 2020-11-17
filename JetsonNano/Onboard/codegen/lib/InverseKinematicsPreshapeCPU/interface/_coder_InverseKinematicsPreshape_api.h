/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_InverseKinematicsPreshape_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 17-Nov-2020 12:52:12
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
  void InverseKinematicsPreshape(real_T linkLengths[5], real_T desiredPosition[2],
    real_T normalStableLine[2], int16_T motorAngles[3]);
  void InverseKinematicsPreshape_api(const mxArray * const prhs[3], const
    mxArray *plhs[1]);
  void InverseKinematicsPreshape_atexit(void);
  void InverseKinematicsPreshape_initialize(void);
  void InverseKinematicsPreshape_terminate(void);
  void InverseKinematicsPreshape_xil_shutdown(void);
  void InverseKinematicsPreshape_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_InverseKinematicsPreshape_api.h
 *
 * [EOF]
 */
