/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_GetValidGripPoints_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 03-Dec-2020 12:39:31
 */

#ifndef _CODER_GETVALIDGRIPPOINTS_API_H
#define _CODER_GETVALIDGRIPPOINTS_API_H

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
  void GetValidGripPoints(real_T targetPointYPixel_data[], int32_T
    targetPointYPixel_size[1], real_T targetPointXPixel_data[], int32_T
    targetPointXPixel_size[1], real_T normalPointYPixel_data[], int32_T
    normalPointYPixel_size[1], real_T normalPointXPixel_data[], int32_T
    normalPointXPixel_size[1], real_T distanceToObject, real_T fingerNumber,
    real_T offset, uint16_T motorSteps[3], real_T *bestTargetPointY, real_T
    *bestTargetPointX, real_T *bestNormalPointY, real_T *bestNormalPointX);
  void GetValidGripPoints_api(const mxArray * const prhs[7], int32_T nlhs, const
    mxArray *plhs[5]);
  void GetValidGripPoints_atexit(void);
  void GetValidGripPoints_initialize(void);
  void GetValidGripPoints_terminate(void);
  void GetValidGripPoints_xil_shutdown(void);
  void GetValidGripPoints_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_GetValidGripPoints_api.h
 *
 * [EOF]
 */
