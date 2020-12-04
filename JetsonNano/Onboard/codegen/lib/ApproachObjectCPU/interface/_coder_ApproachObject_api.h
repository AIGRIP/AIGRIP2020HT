/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_ApproachObject_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 04-Dec-2020 11:28:08
 */

#ifndef _CODER_APPROACHOBJECT_API_H
#define _CODER_APPROACHOBJECT_API_H

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
  void ApproachObject(real_T linkLengths[5], real_T currentMotorM0Steps, real_T
                      currentMotorM1Steps, real_T distanceToObject, real_T
                      motorAngles[3]);
  void ApproachObject_api(const mxArray * const prhs[4], const mxArray *plhs[1]);
  void ApproachObject_atexit(void);
  void ApproachObject_initialize(void);
  void ApproachObject_terminate(void);
  void ApproachObject_xil_shutdown(void);
  void ApproachObject_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_ApproachObject_api.h
 *
 * [EOF]
 */
