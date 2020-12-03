/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MorphologicalEdgeFilter.c
 *
 * Code generation for function 'MorphologicalEdgeFilter'
 *
 */

/* Include files */
#include "MorphologicalEdgeFilter.h"
#include "MorphologicalFilters_data.h"
#include "rt_nonfinite.h"
#include "libmwmorphop_binary_tbb.h"

/* Function Definitions */
void MorphologicalEdgeFilter(const boolean_T inputBinaryImage[728160], boolean_T
  edgeBinaryImage[728160])
{
  real_T asizeT[2];
  real_T nsizeT[2];
  int32_T i;
  boolean_T nhood[9];
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0U);

  /* MorphologicalEdgeFilter run an morpological edge filter on the input image */
  /* and return an image with only edges. */
  /*    inputBinaryImage - Should be an binary image. */
  /*    edgeBinaryImage  - returns a binary edge image. */
  /*  Set the edge as high and all high pixels inside the object low. */
  for (i = 0; i < 9; i++) {
    nhood[i] = true;
  }

  asizeT[0] = 984.0;
  nsizeT[0] = 3.0;
  asizeT[1] = 740.0;
  nsizeT[1] = 3.0;
  erode_binary_ones33_tbb(&inputBinaryImage[0], &asizeT[0], 2.0, &nhood[0],
    &nsizeT[0], 2.0, &edgeBinaryImage[0]);
  for (i = 0; i < 728160; i++) {
    edgeBinaryImage[i] = (inputBinaryImage[i] && (!edgeBinaryImage[i]));
  }
}

/* End of code generation (MorphologicalEdgeFilter.c) */
