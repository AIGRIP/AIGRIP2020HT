//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  colourSegmentation_initialize.cpp
//
//  Code generation for function 'colourSegmentation_initialize'
//


// Include files
#include "colourSegmentation_initialize.h"
#include "_coder_colourSegmentation_mex.h"
#include "colourSegmentation_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

// Function Definitions
void colourSegmentation_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "image_toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation (colourSegmentation_initialize.cpp)
