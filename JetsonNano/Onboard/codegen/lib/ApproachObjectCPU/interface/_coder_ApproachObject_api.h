/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ApproachObject_api.h
 *
 * Code generation for function '_coder_ApproachObject_api'
 *
 */

#ifndef _CODER_APPROACHOBJECT_API_H
#define _CODER_APPROACHOBJECT_API_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void ApproachObject(real_T linkLengths[5], uint16_T currentMotorM0Steps,
  uint16_T currentMotorM1Steps, real_T distanceToObject, uint16_T motorAngles[3]);
extern void ApproachObject_api(const mxArray * const prhs[4], int32_T nlhs,
  const mxArray *plhs[1]);
extern void ApproachObject_atexit(void);
extern void ApproachObject_initialize(void);
extern void ApproachObject_terminate(void);
extern void ApproachObject_xil_shutdown(void);
extern void ApproachObject_xil_terminate(void);

#endif

/* End of code generation (_coder_ApproachObject_api.h) */
