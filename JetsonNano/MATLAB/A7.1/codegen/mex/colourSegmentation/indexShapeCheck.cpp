//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  indexShapeCheck.cpp
//
//  Code generation for function 'indexShapeCheck'
//


// Include files
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo r_emlrtRSI = { 33,  // lineNo
  "indexShapeCheck",                   // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"// pathName 
};

static emlrtRTEInfo g_emlrtRTEI = { 121,// lineNo
  5,                                   // colNo
  "errOrWarnIf",                       // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"// pName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    void indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[2],
                         const int32_T indexSize[2])
    {
      emlrtStack st;
      st.prev = sp;
      st.tls = sp->tls;
      if ((matrixSize[1] != 1) && (indexSize[1] != 1)) {
        st.site = &r_emlrtRSI;
        if (indexSize[1] != 1) {
          emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
            "Coder:FE:PotentialMatrixMatrix_MV",
            "Coder:FE:PotentialMatrixMatrix_MV", 0);
        }
      }
    }

    void indexShapeCheck()
    {
    }
  }
}

// End of code generation (indexShapeCheck.cpp)
