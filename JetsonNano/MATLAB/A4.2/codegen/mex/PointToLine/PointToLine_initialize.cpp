//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  PointToLine_initialize.cpp
//
//  Code generation for function 'PointToLine_initialize'
//


// Include files
#include "PointToLine_initialize.h"
#include "PointToLine_data.h"
#include "_coder_PointToLine_mex.h"
#include "rt_nonfinite.h"

// Variable Definitions
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

// Function Declarations
static void PointToLine_once();

// Function Definitions
static void PointToLine_once()
{
  const int32_T postfix_exprs_0_0[7] = { 0, 1, -3, 2, 3, -3, -2 };

  const int32_T postfix_exprs_0_1[7] = { 0, 1, -3, 2, 3, -3, -2 };

  const int32_T cond_ends_0_0[4] = { 1233, 1260, 1289, 1316 };

  const int32_T cond_ends_0_1[4] = { 1430, 1457, 1486, 1513 };

  const int32_T cond_starts_0_0[4] = { 1210, 1237, 1266, 1293 };

  const int32_T cond_starts_0_1[4] = { 1407, 1434, 1463, 1490 };

  mex_InitInfAndNan();

  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.2\\PointToLine.m",
                  0U, 1U, 5U, 4U, 0U, 0U, 0U, 0U, 0U, 8U, 2U);

  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "PointToLine", 1, -1, 2034);

  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1330, -1, 1371);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 1527, -1, 1568);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1990, -1, 2011);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 1671, -1, 1872);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 1035, -1, 1078);

  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 1171, 1197, 1389, 1589);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 1206, 1317, 1586, 1589);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 1403, 1514, 1586, 1589);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 1956, 1981, -1, 2020);

  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 0U, 1209, 1317, 4, 0, *(int32_T (*)
    [4])&cond_starts_0_0[0], *(int32_T (*)[4])&cond_ends_0_0[0], 7, *(int32_T (*)
    [7])&postfix_exprs_0_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 1U, 1406, 1514, 4, 4, *(int32_T (*)
    [4])&cond_starts_0_1[0], *(int32_T (*)[4])&cond_ends_0_1[0], 7, *(int32_T (*)
    [7])&postfix_exprs_0_1[0]);

  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void PointToLine_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    PointToLine_once();
  }
}

// End of code generation (PointToLine_initialize.cpp)
