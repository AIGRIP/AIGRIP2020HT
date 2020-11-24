/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_parallelMotorAnglet2_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 24-Nov-2020 07:54:56
 */

#ifndef _CODER_PARALLELMOTORANGLET2_API_H
#define _CODER_PARALLELMOTORANGLET2_API_H

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
  real_T parallelMotorAnglet2(real_T motorAnglet1, real_T motorPositionM1[2],
    real_T motorPositionM2[2], real_T linkLengths[5]);
  void parallelMotorAnglet2_api(const mxArray * const prhs[4], const mxArray
    *plhs[1]);
  void parallelMotorAnglet2_atexit(void);
  void parallelMotorAnglet2_initialize(void);
  void parallelMotorAnglet2_terminate(void);
  void parallelMotorAnglet2_xil_shutdown(void);
  void parallelMotorAnglet2_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_parallelMotorAnglet2_api.h
 *
 * [EOF]
 */
