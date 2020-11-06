/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * colourSegmentation_initialize.c
 *
 * Code generation for function 'colourSegmentation_initialize'
 *
 */

/* Include files */
#include "colourSegmentation_initialize.h"
#include "_coder_colourSegmentation_mex.h"
#include "colourSegmentation_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

/* Function Declarations */
static void colourSegmentation_once(void);

/* Function Definitions */
static void colourSegmentation_once(void)
{
  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",
                  0U, 1U, 11U, 9U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "colourSegmentation", 0, -1, 5468);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 10U, 5444, -1, 5457);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 5285, -1, 5433);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 5113, -1, 5237);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 4918, -1, 5065);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 4722, -1, 4869);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 4528, -1, 4675);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 4336, -1, 4481);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 4144, -1, 4288);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 3952, -1, 4096);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 3761, -1, 3905);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 544, -1, 3608);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 3727, 3747, 3907, 5462);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 3907, 3931, 4098, 5462);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 4098, 4122, 4290, 5462);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 4290, 4314, 4483, 5462);
  covrtIfInit(&emlrtCoverageInstance, 0U, 4U, 4483, 4507, 4677, 5462);
  covrtIfInit(&emlrtCoverageInstance, 0U, 5U, 4677, 4701, 4871, 5462);
  covrtIfInit(&emlrtCoverageInstance, 0U, 6U, 4871, 4895, 5067, 5462);
  covrtIfInit(&emlrtCoverageInstance, 0U, 7U, 5067, 5091, 5239, 5462);
  covrtIfInit(&emlrtCoverageInstance, 0U, 8U, 5239, 5263, 5435, 5462);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void colourSegmentation_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    colourSegmentation_once();
  }
}

/* End of code generation (colourSegmentation_initialize.c) */
