//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  colourSegmentation.cpp
//
//  Code generation for function 'colourSegmentation'
//


// Include files
#include "colourSegmentation.h"
#include "colourSegmentation_types.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "libmwippreconstruct.h"
#include "libmwrgb2hsv_tbb.h"
#include "mwmathutil.h"
#include <string.h>

// Type Definitions
struct cell_wrap_5
{
  real_T f1[9];
};

// Variable Definitions
static emlrtRSInfo emlrtRSI = { 106,   // lineNo
  "colourSegmentation",                // fcnName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pathName 
};

static emlrtRSInfo b_emlrtRSI = { 102, // lineNo
  "colourSegmentation",                // fcnName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 17,  // lineNo
  "colourSegmentation",                // fcnName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 51,  // lineNo
  "rgb2hsv",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\images\\rgb2hsv.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 190, // lineNo
  "imfill",                            // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 76,  // lineNo
  "imreconstruct",                     // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imreconstruct.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 64,  // lineNo
  "bwselect",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwselect.m"// pathName 
};

static emlrtRSInfo h_emlrtRSI = { 65,  // lineNo
  "bwselect",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwselect.m"// pathName 
};

static emlrtRSInfo i_emlrtRSI = { 66,  // lineNo
  "bwselect",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwselect.m"// pathName 
};

static emlrtRSInfo j_emlrtRSI = { 70,  // lineNo
  "bwselect",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwselect.m"// pathName 
};

static emlrtRSInfo k_emlrtRSI = { 71,  // lineNo
  "bwselect",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwselect.m"// pathName 
};

static emlrtRSInfo l_emlrtRSI = { 77,  // lineNo
  "bwselect",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwselect.m"// pathName 
};

static emlrtRSInfo n_emlrtRSI = { 8,   // lineNo
  "eml_warning",                       // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\eml\\eml_warning.m"// pathName 
};

static emlrtRSInfo o_emlrtRSI = { 13,  // lineNo
  "nullAssignment",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo p_emlrtRSI = { 17,  // lineNo
  "nullAssignment",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo q_emlrtRSI = { 185, // lineNo
  "onearg_null_assignment",            // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo s_emlrtRSI = { 16,  // lineNo
  "sub2ind",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"// pathName 
};

static emlrtRSInfo t_emlrtRSI = { 108, // lineNo
  "imfill",                            // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pathName 
};

static emlrtRSInfo u_emlrtRSI = { 223, // lineNo
  "imfill",                            // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pathName 
};

static emlrtRSInfo v_emlrtRSI = { 234, // lineNo
  "checkLocations",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pathName 
};

static emlrtRSInfo w_emlrtRSI = { 274, // lineNo
  "checkLocations",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pathName 
};

static emlrtRSInfo x_emlrtRSI = { 276, // lineNo
  "checkLocations",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pathName 
};

static emlrtRSInfo y_emlrtRSI = { 279, // lineNo
  "checkLocations",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pathName 
};

static emlrtRSInfo ab_emlrtRSI = { 76, // lineNo
  "validateattributes",                // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"// pathName 
};

static emlrtRSInfo cb_emlrtRSI = { 22, // lineNo
  "nullAssignment",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo db_emlrtRSI = { 39, // lineNo
  "find",                              // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"// pathName 
};

static emlrtRSInfo eb_emlrtRSI = { 144,// lineNo
  "eml_find",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"// pathName 
};

static emlrtECInfo emlrtECI = { -1,    // nDims
  58,                                  // lineNo
  1,                                   // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo b_emlrtECI = { -1,  // nDims
  56,                                  // lineNo
  1,                                   // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo c_emlrtECI = { -1,  // nDims
  54,                                  // lineNo
  1,                                   // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo d_emlrtECI = { -1,  // nDims
  52,                                  // lineNo
  1,                                   // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo e_emlrtECI = { -1,  // nDims
  50,                                  // lineNo
  1,                                   // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo f_emlrtECI = { -1,  // nDims
  48,                                  // lineNo
  1,                                   // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo g_emlrtECI = { -1,  // nDims
  46,                                  // lineNo
  1,                                   // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo h_emlrtECI = { -1,  // nDims
  44,                                  // lineNo
  1,                                   // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo i_emlrtECI = { -1,  // nDims
  42,                                  // lineNo
  1,                                   // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo j_emlrtECI = { 2,   // nDims
  58,                                  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo k_emlrtECI = { 2,   // nDims
  58,                                  // lineNo
  89,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo l_emlrtECI = { 2,   // nDims
  58,                                  // lineNo
  120,                                 // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo m_emlrtECI = { 2,   // nDims
  56,                                  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo n_emlrtECI = { 2,   // nDims
  56,                                  // lineNo
  91,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo o_emlrtECI = { 2,   // nDims
  56,                                  // lineNo
  28,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo p_emlrtECI = { 2,   // nDims
  54,                                  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo q_emlrtECI = { 2,   // nDims
  54,                                  // lineNo
  28,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo r_emlrtECI = { 2,   // nDims
  54,                                  // lineNo
  29,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo s_emlrtECI = { 2,   // nDims
  52,                                  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo t_emlrtECI = { 2,   // nDims
  52,                                  // lineNo
  28,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo u_emlrtECI = { 2,   // nDims
  52,                                  // lineNo
  29,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo v_emlrtECI = { 2,   // nDims
  50,                                  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo w_emlrtECI = { 2,   // nDims
  50,                                  // lineNo
  28,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo x_emlrtECI = { 2,   // nDims
  50,                                  // lineNo
  29,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo y_emlrtECI = { 2,   // nDims
  48,                                  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo ab_emlrtECI = { 2,  // nDims
  48,                                  // lineNo
  28,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo bb_emlrtECI = { 2,  // nDims
  48,                                  // lineNo
  29,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo cb_emlrtECI = { 2,  // nDims
  46,                                  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo db_emlrtECI = { 2,  // nDims
  46,                                  // lineNo
  28,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo eb_emlrtECI = { 2,  // nDims
  46,                                  // lineNo
  29,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo fb_emlrtECI = { 2,  // nDims
  44,                                  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo gb_emlrtECI = { 2,  // nDims
  44,                                  // lineNo
  28,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo hb_emlrtECI = { 2,  // nDims
  44,                                  // lineNo
  29,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo ib_emlrtECI = { 2,  // nDims
  42,                                  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtECInfo jb_emlrtECI = { 2,  // nDims
  42,                                  // lineNo
  28,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"// pName 
};

static emlrtBCInfo emlrtBCI = { 1,     // iFirst
  740,                                 // iLast
  36,                                  // lineNo
  48,                                  // colNo
  "HSVImage",                          // aName
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo emlrtDCI = { 36,    // lineNo
  48,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo b_emlrtBCI = { 1,   // iFirst
  740,                                 // iLast
  36,                                  // lineNo
  41,                                  // colNo
  "HSVImage",                          // aName
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI = { 36,  // lineNo
  41,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI = { 1,   // iFirst
  984,                                 // iLast
  36,                                  // lineNo
  34,                                  // colNo
  "HSVImage",                          // aName
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo c_emlrtDCI = { 36,  // lineNo
  34,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI = { 1,   // iFirst
  984,                                 // iLast
  36,                                  // lineNo
  27,                                  // colNo
  "HSVImage",                          // aName
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo d_emlrtDCI = { 36,  // lineNo
  27,                                  // colNo
  "colourSegmentation",                // fName
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",// pName 
  1                                    // checkKind
};

static emlrtRTEInfo emlrtRTEI = { 104, // lineNo
  31,                                  // colNo
  "imfill",                            // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pName 
};

static emlrtRTEInfo b_emlrtRTEI = { 41,// lineNo
  19,                                  // colNo
  "eml_sub2ind",                       // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"// pName 
};

static emlrtRTEInfo c_emlrtRTEI = { 31,// lineNo
  23,                                  // colNo
  "eml_sub2ind",                       // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"// pName 
};

static emlrtRTEInfo d_emlrtRTEI = { 277,// lineNo
  13,                                  // colNo
  "checkLocations",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pName 
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  278,                                 // lineNo
  23,                                  // colNo
  "",                                  // aName
  "checkLocations",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo e_emlrtRTEI = { 14,// lineNo
  37,                                  // colNo
  "validatepositive",                  // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"// pName 
};

static emlrtRTEInfo f_emlrtRTEI = { 81,// lineNo
  27,                                  // colNo
  "validate_inputs",                   // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pName 
};

static emlrtBCInfo f_emlrtBCI = { 1,   // iFirst
  986,                                 // iLast
  209,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "imfill",                            // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo g_emlrtBCI = { 1,   // iFirst
  984,                                 // iLast
  209,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "imfill",                            // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI = { 1,   // iFirst
  742,                                 // iLast
  209,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "imfill",                            // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo i_emlrtBCI = { 1,   // iFirst
  984,                                 // iLast
  209,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "imfill",                            // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",// pName 
  3                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI = { 1,   // iFirst
  740,                                 // iLast
  209,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "imfill",                            // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",// pName 
  3                                    // checkKind
};

static emlrtBCInfo k_emlrtBCI = { 1,   // iFirst
  728160,                              // iLast
  222,                                 // lineNo
  12,                                  // colNo
  "",                                  // aName
  "imfill",                            // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m",// pName 
  3                                    // checkKind
};

static emlrtECInfo kb_emlrtECI = { -1, // nDims
  184,                                 // lineNo
  9,                                   // colNo
  "imfill",                            // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\imfill.m"// pName 
};

// Function Definitions
void colourSegmentation(colourSegmentationStackData *SD, const emlrtStack *sp,
  const uint8_T colourBalancedImage[2184480], real_T centerOfObjectX, real_T
  centerOfObjectY, boolean_T SegmentationMask[728160])
{
  cell_wrap_5 outputs[1];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T imSizeT[2];
  real_T tmp_data_tmp;
  real_T x;
  int32_T b_tmp_size[2];
  int32_T c_tmp_size[2];
  int32_T d_tmp_size[2];
  int32_T e_tmp_size[2];
  int32_T locationsVar[2];
  int32_T tmp_size[2];
  int32_T locationsVar_data[1];
  int32_T seed_indices_data[1];
  int32_T b_loop_ub_tmp;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T j;
  int32_T loop_ub_tmp;
  int32_T nz;
  int32_T xpageoffset;
  int16_T idx[1968];
  int8_T varargin_2[2];
  boolean_T centerColourMask[23409];
  boolean_T b_x[984];
  boolean_T badPixels_data[1];
  boolean_T tmp_data[1];
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;

  // The function takes in a image and a rough postion of the object in the
  // image that should be segmented. and it outputs a a bitmask of the the
  // object.
  // Input:
  // colourBalancedImage = RGB image 984x740x3
  // centerOfObjectX = Objects center postion in the x-axis
  // centerOfObjectY = Objects center postion in the y-axis
  // Output:
  // SegmentationMask = bitmask of the segmented object
  // Transform the Image into the HSV colour space
  st.site = &c_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  rgb2hsv_tbb_uint8(&colourBalancedImage[0], 728160.0, &SD->f0.HSVImage[0], true);

  // Standardize the H-values from 0-1 to 0-360
  for (i = 0; i < 740; i++) {
    for (i1 = 0; i1 < 984; i1++) {
      xpageoffset = i1 + 984 * i;
      SD->f0.HSVImage[xpageoffset] *= 360.0;
    }
  }

  // Make a small square at the center of the object and determine which
  // colour is most prevalent in the square
  // Choose square size
  // Calculate the start and end values for X and  Y
  // Take out the sqaure area from the image
  if (centerOfObjectX - 25.0 > centerOfObjectX + 25.0) {
    i = 0;
    i1 = -1;
  } else {
    if (centerOfObjectX - 25.0 != static_cast<int32_T>(muDoubleScalarFloor
         (centerOfObjectX - 25.0))) {
      emlrtIntegerCheckR2012b(centerOfObjectX - 25.0, &d_emlrtDCI, sp);
    }

    if ((static_cast<int32_T>(centerOfObjectX - 25.0) < 1) ||
        (static_cast<int32_T>(centerOfObjectX - 25.0) > 984)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(centerOfObjectX - 25.0),
        1, 984, &d_emlrtBCI, sp);
    }

    i = static_cast<int32_T>(centerOfObjectX - 25.0) - 1;
    if (centerOfObjectX + 25.0 != static_cast<int32_T>(muDoubleScalarFloor
         (centerOfObjectX + 25.0))) {
      emlrtIntegerCheckR2012b(centerOfObjectX + 25.0, &c_emlrtDCI, sp);
    }

    if ((static_cast<int32_T>(centerOfObjectX + 25.0) < 1) ||
        (static_cast<int32_T>(centerOfObjectX + 25.0) > 984)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(centerOfObjectX + 25.0),
        1, 984, &c_emlrtBCI, sp);
    }

    i1 = static_cast<int32_T>(centerOfObjectX + 25.0) - 1;
  }

  if (centerOfObjectY - 25.0 > centerOfObjectY + 25.0) {
    j = 0;
    i2 = -1;
  } else {
    if (centerOfObjectY - 25.0 != static_cast<int32_T>(muDoubleScalarFloor
         (centerOfObjectY - 25.0))) {
      emlrtIntegerCheckR2012b(centerOfObjectY - 25.0, &b_emlrtDCI, sp);
    }

    if ((static_cast<int32_T>(centerOfObjectY - 25.0) < 1) ||
        (static_cast<int32_T>(centerOfObjectY - 25.0) > 740)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(centerOfObjectY - 25.0),
        1, 740, &b_emlrtBCI, sp);
    }

    j = static_cast<int32_T>(centerOfObjectY - 25.0) - 1;
    if (centerOfObjectY + 25.0 != static_cast<int32_T>(muDoubleScalarFloor
         (centerOfObjectY + 25.0))) {
      emlrtIntegerCheckR2012b(centerOfObjectY + 25.0, &emlrtDCI, sp);
    }

    if ((static_cast<int32_T>(centerOfObjectY + 25.0) < 1) ||
        (static_cast<int32_T>(centerOfObjectY + 25.0) > 740)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(centerOfObjectY + 25.0),
        1, 740, &emlrtBCI, sp);
    }

    i2 = static_cast<int32_T>(centerOfObjectY + 25.0) - 1;
  }

  memset(&centerColourMask[0], 0, 23409U * sizeof(boolean_T));

  // Make mask in the square for every 9 colours.
  // Calcualte which pixels are red
  loop_ub_tmp = i1 - i;
  b_loop_ub_tmp = i2 - j;
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (j + i1)];
      SD->f0.colourSegmentationMask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp
        < 15.0);
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 315.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &jb_emlrtECI, sp);
  nz = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] ||
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2) + 984
        * (j + i1)] > 315.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &jb_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] ||
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &ib_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &ib_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  locationsVar[0] = 51;
  locationsVar[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&locationsVar[0], 2, &tmp_size[0], 2,
    &i_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset] = SD->f0.colourSegmentationMask[xpageoffset];
    }
  }

  // Calcualte which pixels are orange
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (j + i1)];
      SD->f0.colourSegmentationMask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp
        > 15.0);
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 50.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &hb_emlrtECI, sp);
  nz = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2) + 984
        * (j + i1)] == 15.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &gb_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] ||
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &fb_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &fb_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  locationsVar[0] = 51;
  locationsVar[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&locationsVar[0], 2, &tmp_size[0], 2,
    &h_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 2601] = SD->
        f0.colourSegmentationMask[xpageoffset];
    }
  }

  // Calcualte which pixels are yellow
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (j + i1)];
      SD->f0.colourSegmentationMask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp
        > 50.0);
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 70.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &eb_emlrtECI, sp);
  nz = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2) + 984
        * (j + i1)] == 50.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &db_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] ||
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &cb_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &cb_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  locationsVar[0] = 51;
  locationsVar[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&locationsVar[0], 2, &tmp_size[0], 2,
    &g_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 5202] = SD->
        f0.colourSegmentationMask[xpageoffset];
    }
  }

  // Calcualte which pixels are green
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (j + i1)];
      SD->f0.colourSegmentationMask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp
        > 70.0);
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 155.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &bb_emlrtECI, sp);
  nz = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2) + 984
        * (j + i1)] == 70.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &ab_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] ||
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &y_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &y_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  locationsVar[0] = 51;
  locationsVar[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&locationsVar[0], 2, &tmp_size[0], 2,
    &f_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 7803] = SD->
        f0.colourSegmentationMask[xpageoffset];
    }
  }

  // Calcualte which pixels are cyan
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (j + i1)];
      SD->f0.colourSegmentationMask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp
        > 155.0);
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 205.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &x_emlrtECI, sp);
  nz = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2) + 984
        * (j + i1)] == 155.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &w_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] ||
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &v_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &v_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  locationsVar[0] = 51;
  locationsVar[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&locationsVar[0], 2, &tmp_size[0], 2,
    &e_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 10404] = SD->
        f0.colourSegmentationMask[xpageoffset];
    }
  }

  // Calcualte which pixels are blue
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (j + i1)];
      SD->f0.colourSegmentationMask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp
        > 205.0);
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 260.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &u_emlrtECI, sp);
  nz = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2) + 984
        * (j + i1)] == 205.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &t_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] ||
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &s_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &s_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  locationsVar[0] = 51;
  locationsVar[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&locationsVar[0], 2, &tmp_size[0], 2,
    &d_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 13005] = SD->
        f0.colourSegmentationMask[xpageoffset];
    }
  }

  // Calcualte which pixels are purple
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (j + i1)];
      SD->f0.colourSegmentationMask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp
        > 260.0);
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 315.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &r_emlrtECI, sp);
  nz = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2) + 984
        * (j + i1)] == 260.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &q_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] ||
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &p_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2) +
        984 * (j + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &p_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.mask[i1]);
  }

  locationsVar[0] = 51;
  locationsVar[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&locationsVar[0], 2, &tmp_size[0], 2,
    &c_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 15606] = SD->
        f0.colourSegmentationMask[xpageoffset];
    }
  }

  // Calcualte which pixels are white
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[((i + i2) + 984 * (j + i1)) + 1456320];
      SD->f0.colourSegmentationMask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp
        > 0.6);
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 0.6);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &o_emlrtECI, sp);
  c_tmp_size[0] = loop_ub_tmp + 1;
  c_tmp_size[1] = b_loop_ub_tmp + 1;
  d_tmp_size[0] = loop_ub_tmp + 1;
  d_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[((i + i2) + 984 * (j + i1)) + 728160];
      SD->f0.marker[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 0.2);
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&c_tmp_size[0], &d_tmp_size[0], &n_emlrtECI, sp);
  nz = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] ||
      SD->f0.mask[i1]);
  }

  xpageoffset = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < xpageoffset; i1++) {
    SD->f0.marker[i1] = (SD->f0.marker[i1] || SD->f0.tmp_data[i1]);
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &c_tmp_size[0], &m_emlrtECI, sp);
  for (i1 = 0; i1 < nz; i1++) {
    SD->f0.colourSegmentationMask[i1] = (SD->f0.colourSegmentationMask[i1] &&
      SD->f0.marker[i1]);
  }

  locationsVar[0] = 51;
  locationsVar[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&locationsVar[0], 2, &tmp_size[0], 2,
    &b_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 18207] = SD->
        f0.colourSegmentationMask[xpageoffset];
    }
  }

  // Calcualte which pixels are black
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[((i + i2) + 984 * (j + i1)) + 1456320];
      SD->f0.colourSegmentationMask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp
        < 0.3);
      SD->f0.mask[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &j_emlrtECI, sp);
  c_tmp_size[0] = loop_ub_tmp + 1;
  c_tmp_size[1] = b_loop_ub_tmp + 1;
  d_tmp_size[0] = loop_ub_tmp + 1;
  d_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[((i + i2) + 984 * (j + i1)) + 728160];
      SD->f0.marker[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 0.2);
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&c_tmp_size[0], &d_tmp_size[0], &l_emlrtECI, sp);
  e_tmp_size[0] = loop_ub_tmp + 1;
  e_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (j + i1)) + 1456320] < 0.6);
    }
  }

  xpageoffset = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i = 0; i < xpageoffset; i++) {
    SD->f0.marker[i] = (SD->f0.marker[i] || SD->f0.tmp_data[i]);
  }

  emlrtSizeEqCheckNDR2012b(&e_tmp_size[0], &c_tmp_size[0], &k_emlrtECI, sp);
  nz = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i = 0; i < nz; i++) {
    SD->f0.colourSegmentationMask[i] = (SD->f0.colourSegmentationMask[i] ||
      SD->f0.mask[i]);
  }

  xpageoffset = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i = 0; i < xpageoffset; i++) {
    SD->f0.b_tmp_data[i] = (SD->f0.b_tmp_data[i] && SD->f0.marker[i]);
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &e_tmp_size[0], &j_emlrtECI, sp);
  for (i = 0; i < nz; i++) {
    SD->f0.colourSegmentationMask[i] = (SD->f0.colourSegmentationMask[i] ||
      SD->f0.b_tmp_data[i]);
  }

  locationsVar[0] = 51;
  locationsVar[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&locationsVar[0], 2, &tmp_size[0], 2, &emlrtECI,
    sp);
  for (i = 0; i < 51; i++) {
    for (i1 = 0; i1 < 51; i1++) {
      xpageoffset = i1 + 51 * i;
      centerColourMask[xpageoffset + 20808] = SD->
        f0.colourSegmentationMask[xpageoffset];
    }
  }

  //  Sum up all the masks and then determine which mask has the most pixels
  for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 9; b_loop_ub_tmp++) {
    xpageoffset = b_loop_ub_tmp * 2601;
    x = centerColourMask[xpageoffset];
    for (loop_ub_tmp = 0; loop_ub_tmp < 2600; loop_ub_tmp++) {
      x += static_cast<real_T>(centerColourMask[(xpageoffset + loop_ub_tmp) + 1]);
    }

    outputs[0].f1[b_loop_ub_tmp] = x;
  }

  tmp_data_tmp = outputs[0].f1[0];
  xpageoffset = 1;
  for (loop_ub_tmp = 0; loop_ub_tmp < 8; loop_ub_tmp++) {
    x = outputs[0].f1[loop_ub_tmp + 1];
    if (tmp_data_tmp < x) {
      tmp_data_tmp = x;
      xpageoffset = loop_ub_tmp + 2;
    }
  }

  //  Make a mask over the whole image. The colour that is seperated
  //  is the one that had the most pixels in the square
  if (xpageoffset == 1) {
    // Red
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        j = i1 + 984 * i;
        x = SD->f0.HSVImage[j];
        SD->f0.colourSegmentationMask[j] = (((x < 15.0) || (x == 315.0) || (x >
          315.0)) && (SD->f0.HSVImage[j + 728160] > 0.2) && (SD->f0.HSVImage[j +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 2) {
    // Orange
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        j = i1 + 984 * i;
        x = SD->f0.HSVImage[j];
        SD->f0.colourSegmentationMask[j] = ((((x > 15.0) && (x < 50.0)) || (x ==
          15.0)) && (SD->f0.HSVImage[j + 728160] > 0.2) && (SD->f0.HSVImage[j +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 3) {
    // Yellow
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        j = i1 + 984 * i;
        x = SD->f0.HSVImage[j];
        SD->f0.colourSegmentationMask[j] = ((((x > 50.0) && (x < 70.0)) || (x ==
          50.0)) && (SD->f0.HSVImage[j + 728160] > 0.2) && (SD->f0.HSVImage[j +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 4) {
    // Green
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        j = i1 + 984 * i;
        x = SD->f0.HSVImage[j];
        SD->f0.colourSegmentationMask[j] = ((((x > 70.0) && (x < 155.0)) || (x ==
          70.0)) && (SD->f0.HSVImage[j + 728160] > 0.2) && (SD->f0.HSVImage[j +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 5) {
    // Cyan
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        j = i1 + 984 * i;
        x = SD->f0.HSVImage[j];
        SD->f0.colourSegmentationMask[j] = ((((x > 155.0) && (x < 205.0)) || (x ==
          155.0)) && (SD->f0.HSVImage[j + 728160] > 0.2) && (SD->f0.HSVImage[j +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 6) {
    // Blue
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        j = i1 + 984 * i;
        x = SD->f0.HSVImage[j];
        SD->f0.colourSegmentationMask[j] = ((((x > 205.0) && (x < 260.0)) || (x ==
          205.0)) && (SD->f0.HSVImage[j + 728160] > 0.2) && (SD->f0.HSVImage[j +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 7) {
    // Purple
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        j = i1 + 984 * i;
        x = SD->f0.HSVImage[j];
        SD->f0.colourSegmentationMask[j] = ((((x > 260.0) && (x < 315.0)) || (x ==
          260.0)) && (SD->f0.HSVImage[j + 728160] > 0.2) && (SD->f0.HSVImage[j +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 8) {
    // White
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        j = i1 + 984 * i;
        x = SD->f0.HSVImage[j + 1456320];
        tmp_data_tmp = SD->f0.HSVImage[j + 728160];
        SD->f0.colourSegmentationMask[j] = (((x > 0.6) || (x == 0.6)) &&
          ((tmp_data_tmp < 0.2) || (tmp_data_tmp == 0.2)));
      }
    }
  } else {
    // Black
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        j = i1 + 984 * i;
        x = SD->f0.HSVImage[j + 1456320];
        tmp_data_tmp = SD->f0.HSVImage[j + 728160];
        SD->f0.colourSegmentationMask[j] = ((x < 0.3) || (x == 0.3) || ((x < 0.6)
          && ((tmp_data_tmp < 0.2) || (tmp_data_tmp == 0.2))));
      }
    }
  }

  // Fill up the hole in the binary image.
  st.site = &b_emlrtRSI;
  for (i = 0; i < 728160; i++) {
    SD->f0.b_mask[i] = static_cast<int8_T>(SD->f0.colourSegmentationMask[i]);
  }

  for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 986; b_loop_ub_tmp++) {
    SD->f0.maskPad[b_loop_ub_tmp] = 0U;
    SD->f0.maskPad[b_loop_ub_tmp + 730626] = 0U;
  }

  for (j = 0; j < 740; j++) {
    xpageoffset = 986 * (j + 1);
    SD->f0.maskPad[xpageoffset] = 0U;
    SD->f0.maskPad[xpageoffset + 985] = 0U;
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 984; b_loop_ub_tmp++) {
      SD->f0.maskPad[(b_loop_ub_tmp + xpageoffset) + 1] = static_cast<uint8_T>
        (SD->f0.b_mask[b_loop_ub_tmp + 984 * j]);
    }
  }

  for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 986; b_loop_ub_tmp++) {
    SD->f0.markerPad[b_loop_ub_tmp] = 0U;
    SD->f0.markerPad[b_loop_ub_tmp + 730626] = 0U;
  }

  for (j = 0; j < 740; j++) {
    xpageoffset = 986 * (j + 1);
    SD->f0.markerPad[xpageoffset] = 0U;
    SD->f0.markerPad[xpageoffset + 985] = 0U;
    memset(&SD->f0.markerPad[xpageoffset + 1], 255, 984U * sizeof(uint8_T));
  }

  memset(&idx[0], 0, 1968U * sizeof(int16_T));
  locationsVar[0] = 1;
  seed_indices_data[0] = 984;
  locationsVar[1] = 984;
  emlrtSubAssignSizeCheckR2012b(&seed_indices_data[0], 1, &locationsVar[0], 2,
    &kb_emlrtECI, &st);
  for (i = 0; i < 984; i++) {
    idx[i] = static_cast<int16_T>(i + 2);
  }

  seed_indices_data[0] = 740;
  locationsVar[1] = 740;
  emlrtSubAssignSizeCheckR2012b(&seed_indices_data[0], 1, &locationsVar[0], 2,
    &kb_emlrtECI, &st);
  for (i = 0; i < 740; i++) {
    idx[i + 984] = static_cast<int16_T>(i + 2);
  }

  for (i = 0; i < 731612; i++) {
    SD->f0.maskPad[i] = static_cast<uint8_T>(255U - SD->f0.maskPad[i]);
    SD->f0.markerPad[i] = static_cast<uint8_T>(255U - SD->f0.markerPad[i]);
  }

  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  imSizeT[0] = 986.0;
  imSizeT[1] = 742.0;
  ippreconstruct_uint8(&SD->f0.markerPad[0], &SD->f0.maskPad[0], &imSizeT[0],
                       1.0);
  for (i = 0; i < 731612; i++) {
    SD->f0.markerPad[i] = static_cast<uint8_T>(255U - SD->f0.markerPad[i]);
  }

  for (i = 0; i < 984; i++) {
    b_x[i] = (idx[i] != 0);
  }

  xpageoffset = b_x[0];
  for (loop_ub_tmp = 0; loop_ub_tmp < 983; loop_ub_tmp++) {
    xpageoffset += b_x[loop_ub_tmp + 1];
  }

  for (i = 0; i < 984; i++) {
    b_x[i] = (idx[i + 984] != 0);
  }

  nz = b_x[0];
  for (loop_ub_tmp = 0; loop_ub_tmp < 983; loop_ub_tmp++) {
    nz += b_x[loop_ub_tmp + 1];
  }

  for (b_loop_ub_tmp = 0; b_loop_ub_tmp < xpageoffset; b_loop_ub_tmp++) {
    for (j = 0; j < nz; j++) {
      if ((static_cast<int32_T>(b_loop_ub_tmp + 1U) < 1) || (static_cast<int32_T>
           (b_loop_ub_tmp + 1U) > 984)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_loop_ub_tmp + 1U),
          1, 984, &g_emlrtBCI, &st);
      }

      i = idx[b_loop_ub_tmp];
      if (i < 1) {
        emlrtDynamicBoundsCheckR2012b(0, 1, 986, &f_emlrtBCI, &st);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           984)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, 984,
          &g_emlrtBCI, &st);
      }

      i1 = idx[j + 984];
      if ((i1 < 1) || (i1 > 742)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 742, &h_emlrtBCI, &st);
      }

      if ((static_cast<int32_T>(b_loop_ub_tmp + 1U) < 1) || (static_cast<int32_T>
           (b_loop_ub_tmp + 1U) > 984)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_loop_ub_tmp + 1U),
          1, 984, &i_emlrtBCI, &st);
      }

      if ((static_cast<int32_T>(j + 1U) < 1) || (static_cast<int32_T>(j + 1U) >
           740)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, 740,
          &j_emlrtBCI, &st);
      }

      SD->f0.colourSegmentationMask[b_loop_ub_tmp + 984 * j] = (SD->
        f0.markerPad[(i + 986 * (i1 - 1)) - 1] != 0);
    }
  }

  st.site = &emlrtRSI;
  tmp_data_tmp = muDoubleScalarRound(centerOfObjectX);
  j = 1;
  x = muDoubleScalarRound(centerOfObjectY);
  nz = 1;
  xpageoffset = 0;
  if ((tmp_data_tmp < 1.0) || (tmp_data_tmp > 984.0) || (x < 1.0) || (x > 740.0))
  {
    xpageoffset = 1;
  }

  if (xpageoffset != 0) {
    b_st.site = &g_emlrtRSI;
    c_st.site = &n_emlrtRSI;
    coder::internal::warning(&c_st);
    b_st.site = &h_emlrtRSI;
    c_st.site = &o_emlrtRSI;
    c_st.site = &p_emlrtRSI;
    locationsVar[0] = 1;
    locationsVar[1] = 1;
    tmp_size[0] = 1;
    tmp_size[1] = 0;
    d_st.site = &q_emlrtRSI;
    coder::internal::indexShapeCheck(&d_st, locationsVar, tmp_size);
    j = 0;
    b_st.site = &i_emlrtRSI;
    c_st.site = &o_emlrtRSI;
    c_st.site = &p_emlrtRSI;
    locationsVar[0] = 1;
    locationsVar[1] = 1;
    tmp_size[0] = 1;
    tmp_size[1] = 0;
    d_st.site = &q_emlrtRSI;
    coder::internal::indexShapeCheck(&d_st, locationsVar, tmp_size);
    nz = 0;
  }

  b_st.site = &j_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  loop_ub_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub_tmp <= j - 1)) {
    if ((tmp_data_tmp >= 1.0) && (tmp_data_tmp <= 984.0)) {
      loop_ub_tmp = 1;
    } else {
      emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", "MATLAB:sub2ind:IndexOutOfRange", 0);
    }
  }

  imSizeT[0] = j;
  imSizeT[1] = 1.0;
  varargin_2[0] = static_cast<int8_T>(nz);
  varargin_2[1] = 1;
  p = true;
  loop_ub_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub_tmp < 2)) {
    if (static_cast<int32_T>(imSizeT[loop_ub_tmp]) != varargin_2[loop_ub_tmp]) {
      p = false;
      exitg1 = true;
    } else {
      loop_ub_tmp++;
    }
  }

  b_p = p;
  if (!b_p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:sub2ind:SubscriptVectorSize", "MATLAB:sub2ind:SubscriptVectorSize",
      0);
  }

  loop_ub_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub_tmp <= nz - 1)) {
    if ((x >= 1.0) && (x <= 740.0)) {
      loop_ub_tmp = 1;
    } else {
      emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", "MATLAB:sub2ind:IndexOutOfRange", 0);
    }
  }

  if (0 <= j - 1) {
    seed_indices_data[0] = static_cast<int32_T>(tmp_data_tmp) + 984 * (
      static_cast<int32_T>(x) - 1);
  }

  b_st.site = &k_emlrtRSI;
  for (i = 0; i < 728160; i++) {
    SegmentationMask[i] = !SD->f0.colourSegmentationMask[i];
  }

  p = (j == 1);
  if (p && (j != 0) && (seed_indices_data[0] != 0)) {
    p = false;
  }

  b_p = p;
  if (b_p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
      "images:imfill:noInteractiveInCodegen",
      "images:imfill:noInteractiveInCodegen", 0);
  }

  c_st.site = &t_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  e_st.site = &ab_emlrtRSI;
  b_p = true;
  loop_ub_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub_tmp <= j - 1)) {
    if (seed_indices_data[0] > 0) {
      loop_ub_tmp = 1;
    } else {
      b_p = false;
      exitg1 = true;
    }
  }

  if (!b_p) {
    emlrtErrorWithMessageIdR2018a(&e_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedPositive",
      "MATLAB:imfill:expectedPositive", 3, 4, 26, "input number 2, LOCATIONS,");
  }

  nz = 0;
  if (j != 0) {
    nz = 1;
    locationsVar_data[0] = seed_indices_data[0];
  }

  if (0 <= j - 1) {
    badPixels_data[0] = (seed_indices_data[0] < 1);
  }

  if (0 <= j - 1) {
    tmp_data[0] = (seed_indices_data[0] > 728160);
  }

  for (i = 0; i < j; i++) {
    badPixels_data[0] = (badPixels_data[0] || tmp_data[0]);
  }

  d_st.site = &w_emlrtRSI;
  b_p = false;
  xpageoffset = 1;
  exitg1 = false;
  while ((!exitg1) && (xpageoffset <= j)) {
    if (!badPixels_data[0]) {
      xpageoffset = 2;
    } else {
      b_p = true;
      exitg1 = true;
    }
  }

  if (b_p) {
    d_st.site = &x_emlrtRSI;
    coder::internal::b_warning(&d_st);
    i = static_cast<int32_T>(((-1.0 - static_cast<real_T>(j)) + 1.0) / -1.0);
    emlrtForLoopVectorCheckR2012b(static_cast<real_T>(j), -1.0, 1.0,
      mxDOUBLE_CLASS, i, &d_emlrtRTEI, &c_st);
    for (xpageoffset = 0; xpageoffset < i; xpageoffset++) {
      if (j < 1) {
        emlrtDynamicBoundsCheckR2012b(0, 1, 0, &e_emlrtBCI, &c_st);
      }

      if (badPixels_data[0]) {
        d_st.site = &y_emlrtRSI;
        e_st.site = &cb_emlrtRSI;
        if (1 > nz) {
          emlrtErrorWithMessageIdR2018a(&e_st, &f_emlrtRTEI,
            "MATLAB:subsdeldimmismatch", "MATLAB:subsdeldimmismatch", 0);
        }

        nz = 0;
      }
    }
  }

  for (i = 0; i < 728160; i++) {
    SD->f0.mask[i] = !SegmentationMask[i];
    SD->f0.marker[i] = false;
  }

  if (0 <= nz - 1) {
    seed_indices_data[0] = locationsVar_data[0];
  }

  for (i = 0; i < nz; i++) {
    if ((locationsVar_data[0] < 1) || (locationsVar_data[0] > 728160)) {
      emlrtDynamicBoundsCheckR2012b(locationsVar_data[0], 1, 728160, &k_emlrtBCI,
        &b_st);
    }
  }

  if (0 <= nz - 1) {
    SD->f0.marker[seed_indices_data[0] - 1] = SD->f0.mask[locationsVar_data[0] -
      1];
  }

  c_st.site = &u_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  imSizeT[0] = 984.0;
  imSizeT[1] = 740.0;
  ippreconstruct_uint8((uint8_T *)&SD->f0.marker[0], (uint8_T *)&SD->f0.mask[0],
                       &imSizeT[0], 2.0);
  for (i = 0; i < 728160; i++) {
    SegmentationMask[i] = ((SegmentationMask[i] || SD->f0.marker[i]) &&
      SD->f0.colourSegmentationMask[i]);
  }

  b_st.site = &l_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  d_st.site = &eb_emlrtRSI;
  coder::internal::indexShapeCheck();
}

// End of code generation (colourSegmentation.cpp)
