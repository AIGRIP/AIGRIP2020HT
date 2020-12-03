/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_StableLine_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 02-Dec-2020 17:30:04
 */

#ifndef _CODER_STABLELINE_API_H
#define _CODER_STABLELINE_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void StableLine(real_T degreesMeasured[360], real_T YCoordinates[360],
  real_T XCoordinates[360], real_T signatureRadius[360], real_T targetPointF1Y
  [11], real_T targetPointF1X[11], real_T normalPointF1Y[11], real_T
  normalPointF1X[11], real_T targetPointF2Y[11], real_T targetPointF2X[11],
  real_T normalPointF2Y[11], real_T normalPointF2X[11], real_T *targetPointF0Y,
  real_T *targetPointF0X, real_T *normalPointF0Y, real_T *normalPointF0X, real_T
  signatureRadiusTargetF1[11], real_T signatureRadiusTargetF2[11]);
extern void StableLine_api(const mxArray * const prhs[4], int32_T nlhs, const
  mxArray *plhs[14]);
extern void StableLine_atexit(void);
extern void StableLine_initialize(void);
extern void StableLine_terminate(void);
extern void StableLine_xil_shutdown(void);
extern void StableLine_xil_terminate(void);

#endif

/*
 * File trailer for _coder_StableLine_api.h
 *
 * [EOF]
 */
