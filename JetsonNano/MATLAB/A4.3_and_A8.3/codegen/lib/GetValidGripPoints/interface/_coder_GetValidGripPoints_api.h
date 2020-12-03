/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_GetValidGripPoints_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 02-Dec-2020 13:40:33
 */

#ifndef _CODER_GETVALIDGRIPPOINTS_API_H
#define _CODER_GETVALIDGRIPPOINTS_API_H

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
extern void GetValidGripPoints(real_T targetPointYPixel_data[], int32_T
  targetPointYPixel_size[1], real_T targetPointXPixel_data[], int32_T
  targetPointXPixel_size[1], real_T normalPointYPixel_data[], int32_T
  normalPointYPixel_size[1], real_T normalPointXPixel_data[], int32_T
  normalPointXPixel_size[1], real_T distanceToObject, real_T fingerNumber,
  uint16_T motorSteps[3], real_T *bestTargetPointY, real_T *bestTargetPointX,
  real_T *bestNormalPointY, real_T *bestNormalPointX);
extern void GetValidGripPoints_api(const mxArray * const prhs[6], int32_T nlhs,
  const mxArray *plhs[5]);
extern void GetValidGripPoints_atexit(void);
extern void GetValidGripPoints_initialize(void);
extern void GetValidGripPoints_terminate(void);
extern void GetValidGripPoints_xil_shutdown(void);
extern void GetValidGripPoints_xil_terminate(void);

#endif

/*
 * File trailer for _coder_GetValidGripPoints_api.h
 *
 * [EOF]
 */
