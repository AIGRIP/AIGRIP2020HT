/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * morphologicalFilters_initialize.c
 *
 * Code generation for function 'morphologicalFilters_initialize'
 *
 */

/* Include files */
#include "morphologicalFilters_initialize.h"
#include "_coder_morphologicalFilters_mex.h"
#include "morphologicalFilters_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

/* Function Declarations */
static void morphologicalFilters_once(void);

/* Function Definitions */
static void morphologicalFilters_once(void)
{
  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\morphologicalFilters.m",
                  0U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "morphologicalFilters", 0, -1,
               1432);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 576, -1, 1425);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void morphologicalFilters_initialize(void)
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
  emlrtLicenseCheckR2012b(&st, "image_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    morphologicalFilters_once();
  }
}

/* End of code generation (morphologicalFilters_initialize.c) */
