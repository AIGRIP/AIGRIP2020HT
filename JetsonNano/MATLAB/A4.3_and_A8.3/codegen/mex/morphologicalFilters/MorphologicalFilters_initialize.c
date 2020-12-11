/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MorphologicalFilters_initialize.c
 *
 * Code generation for function 'MorphologicalFilters_initialize'
 *
 */

/* Include files */
#include "MorphologicalFilters_initialize.h"
#include "MorphologicalFilters_data.h"
#include "_coder_MorphologicalFilters_mex.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

/* Function Declarations */
static void MorphologicalFilters_once(void);

/* Function Definitions */
static void MorphologicalFilters_once(void)
{
  mex_InitInfAndNan();

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\Samue\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalFilters.m",
                  0U, 1U, 2U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "MorphologicalFilters", 0, -1,
               1844);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1818, -1, 1834);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 550, -1, 1722);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 1777, 1813, -1, 1839);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\Samue\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\MorphologicalEdgeFilter.m",
                  1U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "MorphologicalEdgeFilter", 0, -1,
               439);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 362, -1, 434);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);
}

void MorphologicalFilters_initialize(void)
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
    MorphologicalFilters_once();
  }
}

/* End of code generation (MorphologicalFilters_initialize.c) */
