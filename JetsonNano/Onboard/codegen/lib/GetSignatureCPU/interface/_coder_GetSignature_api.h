/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_GetSignature_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 02-Dec-2020 17:36:28
 */

#ifndef _CODER_GETSIGNATURE_API_H
#define _CODER_GETSIGNATURE_API_H

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
extern void GetSignature(boolean_T binaryEdgeImage[728160], real_T
  degreesToMeasure[360], real_T numberOfRows, real_T numberOfColumns, real_T
  signature[360], real_T YCoordToStore[360], real_T XCoordToStore[360]);
extern void GetSignature_api(const mxArray * const prhs[4], int32_T nlhs, const
  mxArray *plhs[3]);
extern void GetSignature_atexit(void);
extern void GetSignature_initialize(void);
extern void GetSignature_terminate(void);
extern void GetSignature_xil_shutdown(void);
extern void GetSignature_xil_terminate(void);

#endif

/*
 * File trailer for _coder_GetSignature_api.h
 *
 * [EOF]
 */
