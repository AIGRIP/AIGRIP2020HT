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
#include "rt_nonfinite.h"
#include "libmwrgb2hsv_tbb.h"
#include "mwmathutil.h"
#include <string.h>

// Type Definitions
struct cell_wrap_5
{
  real_T f1[9];
};

// Variable Definitions
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

// Function Definitions
void colourSegmentation(colourSegmentationStackData *SD, const emlrtStack *sp,
  const uint8_T colourBalancedImage[2184480], real_T centerOfObjectX, real_T
  centerOfObjectY, boolean_T colourSegmentationMask[728160])
{
  cell_wrap_5 outputs[1];
  real_T d;
  real_T tmp_data_tmp;
  int32_T b_tmp_size[2];
  int32_T c_tmp_size[2];
  int32_T d_tmp_size[2];
  int32_T e_tmp_size[2];
  int32_T iv[2];
  int32_T tmp_size[2];
  int32_T b_loop_ub_tmp;
  int32_T c_loop_ub_tmp;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  int32_T loop_ub_tmp;
  int32_T xpageoffset;
  boolean_T centerColourMask[23409];

  // The function takes in a image and a rough postion of the object in the
  // image that should be segmented. and it outputs a a bitmask of the the
  // object.
  // Input:
  // colourBalancedImage = RGB image 984x740x3
  // centerOfObjectX = Objects center postion in the x-axis
  // centerOfObjectY = Objects center postion in the y-axis
  // Output:
  // colourSegmentationMask = bitmask of the segmented object
  // Transform the Image into the HSV colour space
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
    k = 0;
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

    k = static_cast<int32_T>(centerOfObjectY - 25.0) - 1;
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
  b_loop_ub_tmp = i2 - k;
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (k + i1)];
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 15.0);
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 315.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &jb_emlrtECI, sp);
  c_loop_ub_tmp = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] || SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2)
        + 984 * (k + i1)] > 315.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &jb_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] || SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &ib_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &ib_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  iv[0] = 51;
  iv[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &i_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset] = SD->f0.tmp_data[xpageoffset];
    }
  }

  // Calcualte which pixels are orange
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (k + i1)];
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp > 15.0);
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 50.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &hb_emlrtECI, sp);
  c_loop_ub_tmp = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2)
        + 984 * (k + i1)] == 15.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &gb_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] || SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &fb_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &fb_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  iv[0] = 51;
  iv[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &h_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 2601] = SD->f0.tmp_data[xpageoffset];
    }
  }

  // Calcualte which pixels are yellow
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (k + i1)];
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp > 50.0);
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 70.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &eb_emlrtECI, sp);
  c_loop_ub_tmp = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2)
        + 984 * (k + i1)] == 50.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &db_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] || SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &cb_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &cb_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  iv[0] = 51;
  iv[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &g_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 5202] = SD->f0.tmp_data[xpageoffset];
    }
  }

  // Calcualte which pixels are green
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (k + i1)];
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp > 70.0);
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 155.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &bb_emlrtECI, sp);
  c_loop_ub_tmp = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2)
        + 984 * (k + i1)] == 70.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &ab_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] || SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &y_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &y_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  iv[0] = 51;
  iv[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &f_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 7803] = SD->f0.tmp_data[xpageoffset];
    }
  }

  // Calcualte which pixels are cyan
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (k + i1)];
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp > 155.0);
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 205.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &x_emlrtECI, sp);
  c_loop_ub_tmp = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2)
        + 984 * (k + i1)] == 155.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &w_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] || SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &v_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &v_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  iv[0] = 51;
  iv[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &e_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 10404] = SD->f0.tmp_data[xpageoffset];
    }
  }

  // Calcualte which pixels are blue
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (k + i1)];
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp > 205.0);
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 260.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &u_emlrtECI, sp);
  c_loop_ub_tmp = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2)
        + 984 * (k + i1)] == 205.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &t_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] || SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &s_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &s_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  iv[0] = 51;
  iv[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &d_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 13005] = SD->f0.tmp_data[xpageoffset];
    }
  }

  // Calcualte which pixels are purple
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[(i + i2) + 984 * (k + i1)];
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp > 260.0);
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 315.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &r_emlrtECI, sp);
  c_loop_ub_tmp = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[(i + i2)
        + 984 * (k + i1)] == 260.0);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &q_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] || SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 728160] > 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &p_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 1456320] > 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &p_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.b_tmp_data[i1]);
  }

  iv[0] = 51;
  iv[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &c_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 15606] = SD->f0.tmp_data[xpageoffset];
    }
  }

  // Calcualte which pixels are white
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[((i + i2) + 984 * (k + i1)) + 1456320];
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp > 0.6);
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 0.6);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &o_emlrtECI, sp);
  c_tmp_size[0] = loop_ub_tmp + 1;
  c_tmp_size[1] = b_loop_ub_tmp + 1;
  d_tmp_size[0] = loop_ub_tmp + 1;
  d_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[((i + i2) + 984 * (k + i1)) + 728160];
      SD->f0.c_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 0.2);
      SD->f0.d_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&c_tmp_size[0], &d_tmp_size[0], &n_emlrtECI, sp);
  c_loop_ub_tmp = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] || SD->f0.b_tmp_data[i1]);
  }

  xpageoffset = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i1 = 0; i1 < xpageoffset; i1++) {
    SD->f0.c_tmp_data[i1] = (SD->f0.c_tmp_data[i1] || SD->f0.d_tmp_data[i1]);
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &c_tmp_size[0], &m_emlrtECI, sp);
  for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
    SD->f0.tmp_data[i1] = (SD->f0.tmp_data[i1] && SD->f0.c_tmp_data[i1]);
  }

  iv[0] = 51;
  iv[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &b_emlrtECI, sp);
  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      xpageoffset = i2 + 51 * i1;
      centerColourMask[xpageoffset + 18207] = SD->f0.tmp_data[xpageoffset];
    }
  }

  // Calcualte which pixels are black
  tmp_size[0] = loop_ub_tmp + 1;
  tmp_size[1] = b_loop_ub_tmp + 1;
  b_tmp_size[0] = loop_ub_tmp + 1;
  b_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[((i + i2) + 984 * (k + i1)) + 1456320];
      SD->f0.tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 0.3);
      SD->f0.b_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 0.3);
    }
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &b_tmp_size[0], &j_emlrtECI, sp);
  c_tmp_size[0] = loop_ub_tmp + 1;
  c_tmp_size[1] = b_loop_ub_tmp + 1;
  d_tmp_size[0] = loop_ub_tmp + 1;
  d_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      tmp_data_tmp = SD->f0.HSVImage[((i + i2) + 984 * (k + i1)) + 728160];
      SD->f0.c_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp < 0.2);
      SD->f0.d_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (tmp_data_tmp == 0.2);
    }
  }

  emlrtSizeEqCheckNDR2012b(&c_tmp_size[0], &d_tmp_size[0], &l_emlrtECI, sp);
  e_tmp_size[0] = loop_ub_tmp + 1;
  e_tmp_size[1] = b_loop_ub_tmp + 1;
  for (i1 = 0; i1 <= b_loop_ub_tmp; i1++) {
    for (i2 = 0; i2 <= loop_ub_tmp; i2++) {
      SD->f0.e_tmp_data[i2 + (loop_ub_tmp + 1) * i1] = (SD->f0.HSVImage[((i + i2)
        + 984 * (k + i1)) + 1456320] < 0.6);
    }
  }

  xpageoffset = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i = 0; i < xpageoffset; i++) {
    SD->f0.c_tmp_data[i] = (SD->f0.c_tmp_data[i] || SD->f0.d_tmp_data[i]);
  }

  emlrtSizeEqCheckNDR2012b(&e_tmp_size[0], &c_tmp_size[0], &k_emlrtECI, sp);
  c_loop_ub_tmp = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i = 0; i < c_loop_ub_tmp; i++) {
    SD->f0.tmp_data[i] = (SD->f0.tmp_data[i] || SD->f0.b_tmp_data[i]);
  }

  xpageoffset = (loop_ub_tmp + 1) * (b_loop_ub_tmp + 1);
  for (i = 0; i < xpageoffset; i++) {
    SD->f0.e_tmp_data[i] = (SD->f0.e_tmp_data[i] && SD->f0.c_tmp_data[i]);
  }

  emlrtSizeEqCheckNDR2012b(&tmp_size[0], &e_tmp_size[0], &j_emlrtECI, sp);
  for (i = 0; i < c_loop_ub_tmp; i++) {
    SD->f0.tmp_data[i] = (SD->f0.tmp_data[i] || SD->f0.e_tmp_data[i]);
  }

  iv[0] = 51;
  iv[1] = 51;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &emlrtECI, sp);
  for (i = 0; i < 51; i++) {
    for (i1 = 0; i1 < 51; i1++) {
      xpageoffset = i1 + 51 * i;
      centerColourMask[xpageoffset + 20808] = SD->f0.tmp_data[xpageoffset];
    }
  }

  //  Sum up all the masks and then determine which mask has the most pixels
  for (c_loop_ub_tmp = 0; c_loop_ub_tmp < 9; c_loop_ub_tmp++) {
    xpageoffset = c_loop_ub_tmp * 2601;
    d = centerColourMask[xpageoffset];
    for (k = 0; k < 2600; k++) {
      d += static_cast<real_T>(centerColourMask[(xpageoffset + k) + 1]);
    }

    outputs[0].f1[c_loop_ub_tmp] = d;
  }

  tmp_data_tmp = outputs[0].f1[0];
  xpageoffset = 1;
  for (k = 0; k < 8; k++) {
    d = outputs[0].f1[k + 1];
    if (tmp_data_tmp < d) {
      tmp_data_tmp = d;
      xpageoffset = k + 2;
    }
  }

  //  Make a mask over the whole image. The colour that is seperated
  //  is the one that had the most pixels in the square
  if (xpageoffset == 1) {
    // Red
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = (((d < 15.0) || (d == 315.0) || (d > 315.0))
          && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k + 1456320]
          > 0.3));
      }
    }
  } else if (xpageoffset == 2) {
    // Orange
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 15.0) && (d < 50.0)) || (d == 15.0))
          && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k + 1456320]
          > 0.3));
      }
    }
  } else if (xpageoffset == 3) {
    // Yellow
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 50.0) && (d < 70.0)) || (d == 50.0))
          && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k + 1456320]
          > 0.3));
      }
    }
  } else if (xpageoffset == 4) {
    // Green
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 70.0) && (d < 155.0)) || (d == 70.0))
          && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k + 1456320]
          > 0.3));
      }
    }
  } else if (xpageoffset == 5) {
    // Cyan
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 155.0) && (d < 205.0)) || (d ==
          155.0)) && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 6) {
    // Blue
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 205.0) && (d < 260.0)) || (d ==
          205.0)) && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 7) {
    // Purple
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 260.0) && (d < 315.0)) || (d ==
          260.0)) && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k +
          1456320] > 0.3));
      }
    }
  } else if (xpageoffset == 8) {
    // White
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k + 1456320];
        tmp_data_tmp = SD->f0.HSVImage[k + 728160];
        colourSegmentationMask[k] = (((d > 0.6) || (d == 0.6)) && ((tmp_data_tmp
          < 0.2) || (tmp_data_tmp == 0.2)));
      }
    }
  } else {
    // Black
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k + 1456320];
        tmp_data_tmp = SD->f0.HSVImage[k + 728160];
        colourSegmentationMask[k] = ((d < 0.3) || (d == 0.3) || ((d < 0.6) &&
          ((tmp_data_tmp < 0.2) || (tmp_data_tmp == 0.2))));
      }
    }
  }
}

// End of code generation (colourSegmentation.cpp)
