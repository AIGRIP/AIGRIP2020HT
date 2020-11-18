/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_ParallelMotorAnglet2_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 17-Nov-2020 09:15:26
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
  real_T ParallelMotorAnglet2(real_T motorAnglet1, real_T motorPositionM1[2],
    real_T motorPositionM2[2], real_T linkLengths[5]);
  void ParallelMotorAnglet2_api(const mxArray * const prhs[4], const mxArray
    *plhs[1]);
  void ParallelMotorAnglet2_atexit(void);
  void ParallelMotorAnglet2_initialize(void);
  void ParallelMotorAnglet2_terminate(void);
  void ParallelMotorAnglet2_xil_shutdown(void);
  void ParallelMotorAnglet2_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_ParallelMotorAnglet2_api.h
 *
 * [EOF]
 */
