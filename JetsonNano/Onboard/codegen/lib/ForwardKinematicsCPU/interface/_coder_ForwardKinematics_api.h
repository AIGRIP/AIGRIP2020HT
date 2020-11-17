/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_ForwardKinematics_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 17-Nov-2020 13:53:46
 */

#ifndef _CODER_FORWARDKINEMATICS_API_H
#define _CODER_FORWARDKINEMATICS_API_H

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
  void ForwardKinematics(real_T linkLengths[5], real_T motorPositionM1[2],
    real_T motorAnglet1, real_T motorAnglet2, real_T jointPostions[8], real_T
    opticalSensorPosition[2]);
  void ForwardKinematics_api(const mxArray * const prhs[4], int32_T nlhs, const
    mxArray *plhs[2]);
  void ForwardKinematics_atexit(void);
  void ForwardKinematics_initialize(void);
  void ForwardKinematics_terminate(void);
  void ForwardKinematics_xil_shutdown(void);
  void ForwardKinematics_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_ForwardKinematics_api.h
 *
 * [EOF]
 */
