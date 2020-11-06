/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * colourSegmentation.c
 *
 * Code generation for function 'colourSegmentation'
 *
 */

/* Include files */
#include "colourSegmentation.h"
#include "applyToMultipleDims.h"
#include "colourSegmentation_data.h"
#include "colourSegmentation_emxutil.h"
#include "colourSegmentation_types.h"
#include "rt_nonfinite.h"
#include "libmwrgb2hsv_tbb.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 99,    /* lineNo */
  5,                                   /* colNo */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 37,    /* lineNo */
  34,                                  /* colNo */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  984,                                 /* iLast */
  37,                                  /* lineNo */
  34,                                  /* colNo */
  "HSVImage",                          /* aName */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 37,  /* lineNo */
  41,                                  /* colNo */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  984,                                 /* iLast */
  37,                                  /* lineNo */
  41,                                  /* colNo */
  "HSVImage",                          /* aName */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 37,  /* lineNo */
  48,                                  /* colNo */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  740,                                 /* iLast */
  37,                                  /* lineNo */
  48,                                  /* colNo */
  "HSVImage",                          /* aName */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 37,  /* lineNo */
  55,                                  /* colNo */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  740,                                 /* iLast */
  37,                                  /* lineNo */
  55,                                  /* colNo */
  "HSVImage",                          /* aName */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  37,                                  /* lineNo */
  1,                                   /* colNo */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 37,  /* lineNo */
  25,                                  /* colNo */
  "colourSegmentation",                /* fName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"/* pName */
};

static emlrtRSInfo c_emlrtRSI = { 99,  /* lineNo */
  "colourSegmentation",                /* fcnName */
  "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A7.1\\colourSegmentation.m"/* pathName */
};

/* Function Declarations */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "disp", true, location);
}

void colourSegmentation(colourSegmentationStackData *SD, const emlrtStack *sp,
  const uint8_T colourBalancedImage[2184480], real_T centerOfObjectX, real_T
  centerOfObjectY, boolean_T colourSegmentationMask[728160])
{
  static const int32_T iv1[3] = { 51, 51, 3 };

  static const int32_T iv2[2] = { 1, 5 };

  static const char_T u[5] = { 'e', 'r', 'r', 'o', 'r' };

  emlrtStack st;
  emxArray_real_T *HSVImage;
  emxArray_real_T *b_HSVImage;
  emxArray_real_T *c_HSVImage;
  emxArray_real_T *d_HSVImage;
  const mxArray *m;
  const mxArray *y;
  real_T centerHSVImage[7803];
  real_T nz[9];
  real_T d;
  real_T ex;
  int32_T iv[3];
  int32_T HSVImage_tmp;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  int32_T loop_ub;
  boolean_T centerColourMask[23409];
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /* The function takes in a image and a rough postion of the object in the */
  /* image that should be segmented. and it outputs a a bitmask of the the */
  /* object. */
  /* Input: */
  /* colourBalancedImage = RGB image 984x740x3 */
  /* centerOfObjectX = Objects center postion in the x-axis */
  /* centerOfObjectY = Objects center postion in the y-axis */
  /* Output: */
  /* colourSegmentationMask = bitmask of the segmented object */
  /* Transform the Image into the HSV colour space */
  rgb2hsv_tbb_uint8(&colourBalancedImage[0], 728160.0, &SD->f0.HSVImage[0], true);

  /* Standardize the H-values from 0-1 to 0-360 */
  for (i = 0; i < 740; i++) {
    for (i1 = 0; i1 < 984; i1++) {
      HSVImage_tmp = i1 + 984 * i;
      SD->f0.HSVImage[HSVImage_tmp] *= 360.0;
    }
  }

  /* Make a small square at the center of the object and determine which  */
  /* colour is most prevalent in the square */
  /* Choose square size */
  /* Calculate the start and end values for X and  Y */
  /* Take out the sqaure area from the image */
  if (centerOfObjectX - 25.0 > centerOfObjectX + 25.0) {
    i = 0;
    i1 = 0;
  } else {
    if (centerOfObjectX - 25.0 != (int32_T)muDoubleScalarFloor(centerOfObjectX -
         25.0)) {
      emlrtIntegerCheckR2012b(centerOfObjectX - 25.0, &emlrtDCI, sp);
    }

    if (((int32_T)(centerOfObjectX - 25.0) < 1) || ((int32_T)(centerOfObjectX -
          25.0) > 984)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(centerOfObjectX - 25.0), 1, 984,
        &emlrtBCI, sp);
    }

    i = (int32_T)(centerOfObjectX - 25.0) - 1;
    if (centerOfObjectX + 25.0 != (int32_T)muDoubleScalarFloor(centerOfObjectX +
         25.0)) {
      emlrtIntegerCheckR2012b(centerOfObjectX + 25.0, &b_emlrtDCI, sp);
    }

    if (((int32_T)(centerOfObjectX + 25.0) < 1) || ((int32_T)(centerOfObjectX +
          25.0) > 984)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(centerOfObjectX + 25.0), 1, 984,
        &b_emlrtBCI, sp);
    }

    i1 = (int32_T)(centerOfObjectX + 25.0);
  }

  if (centerOfObjectY - 25.0 > centerOfObjectY + 25.0) {
    k = 0;
    i2 = 0;
  } else {
    if (centerOfObjectY - 25.0 != (int32_T)muDoubleScalarFloor(centerOfObjectY -
         25.0)) {
      emlrtIntegerCheckR2012b(centerOfObjectY - 25.0, &c_emlrtDCI, sp);
    }

    if (((int32_T)(centerOfObjectY - 25.0) < 1) || ((int32_T)(centerOfObjectY -
          25.0) > 740)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(centerOfObjectY - 25.0), 1, 740,
        &c_emlrtBCI, sp);
    }

    k = (int32_T)(centerOfObjectY - 25.0) - 1;
    if (centerOfObjectY + 25.0 != (int32_T)muDoubleScalarFloor(centerOfObjectY +
         25.0)) {
      emlrtIntegerCheckR2012b(centerOfObjectY + 25.0, &d_emlrtDCI, sp);
    }

    if (((int32_T)(centerOfObjectY + 25.0) < 1) || ((int32_T)(centerOfObjectY +
          25.0) > 740)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(centerOfObjectY + 25.0), 1, 740,
        &d_emlrtBCI, sp);
    }

    i2 = (int32_T)(centerOfObjectY + 25.0);
  }

  emxInit_real_T(sp, &HSVImage, 3, &emlrtRTEI, true);
  loop_ub = i1 - i;
  iv[0] = loop_ub;
  b_loop_ub = i2 - k;
  iv[1] = b_loop_ub;
  iv[2] = 3;
  emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, &iv[0], 3, &emlrtECI, sp);
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = SD->f0.HSVImage[((i + HSVImage_tmp) +
          984 * (k + i2)) + 728160 * i1];
      }
    }
  }

  for (i1 = 0; i1 < 7803; i1++) {
    centerHSVImage[i1] = HSVImage->data[i1];
  }

  memset(&centerColourMask[0], 0, 23409U * sizeof(boolean_T));
  emxInit_real_T(sp, &b_HSVImage, 3, &emlrtRTEI, true);
  emxInit_real_T(sp, &c_HSVImage, 3, &emlrtRTEI, true);

  /* Make mask in the square for every 9 colours.  */
  /* Calcualte which pixels are red */
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  i1 = b_HSVImage->size[0] * b_HSVImage->size[1] * b_HSVImage->size[2];
  b_HSVImage->size[0] = loop_ub;
  b_HSVImage->size[1] = b_loop_ub;
  b_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_HSVImage, i1, &emlrtRTEI);
  i1 = c_HSVImage->size[0] * c_HSVImage->size[1] * c_HSVImage->size[2];
  c_HSVImage->size[0] = loop_ub;
  c_HSVImage->size[1] = b_loop_ub;
  c_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c_HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        d = SD->f0.HSVImage[((i + HSVImage_tmp) + 984 * (k + i2)) + 728160 * i1];
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = d;
        b_HSVImage->data[(HSVImage_tmp + b_HSVImage->size[0] * i2) +
          b_HSVImage->size[0] * b_HSVImage->size[1] * i1] = d;
        c_HSVImage->data[(HSVImage_tmp + c_HSVImage->size[0] * i2) +
          c_HSVImage->size[0] * c_HSVImage->size[1] * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      HSVImage_tmp = i2 + 51 * i1;
      centerColourMask[HSVImage_tmp] = (((HSVImage->data[HSVImage_tmp] < 15.0) ||
        (b_HSVImage->data[HSVImage_tmp] == 315.0) ||
        (centerHSVImage[HSVImage_tmp] > 315.0)) && (c_HSVImage->
        data[HSVImage_tmp + 2601] > 0.2) && (centerHSVImage[HSVImage_tmp + 5202]
        > 0.3));
    }
  }

  /* Calcualte which pixels are orange */
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  i1 = b_HSVImage->size[0] * b_HSVImage->size[1] * b_HSVImage->size[2];
  b_HSVImage->size[0] = loop_ub;
  b_HSVImage->size[1] = b_loop_ub;
  b_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_HSVImage, i1, &emlrtRTEI);
  i1 = c_HSVImage->size[0] * c_HSVImage->size[1] * c_HSVImage->size[2];
  c_HSVImage->size[0] = loop_ub;
  c_HSVImage->size[1] = b_loop_ub;
  c_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c_HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        d = SD->f0.HSVImage[((i + HSVImage_tmp) + 984 * (k + i2)) + 728160 * i1];
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = d;
        b_HSVImage->data[(HSVImage_tmp + b_HSVImage->size[0] * i2) +
          b_HSVImage->size[0] * b_HSVImage->size[1] * i1] = d;
        c_HSVImage->data[(HSVImage_tmp + c_HSVImage->size[0] * i2) +
          c_HSVImage->size[0] * c_HSVImage->size[1] * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      HSVImage_tmp = i2 + 51 * i1;
      centerColourMask[HSVImage_tmp + 2601] = ((((HSVImage->data[HSVImage_tmp] >
        15.0) && (b_HSVImage->data[HSVImage_tmp] < 50.0)) ||
        (centerHSVImage[HSVImage_tmp] == 15.0)) && (c_HSVImage->
        data[HSVImage_tmp + 2601] > 0.2) && (centerHSVImage[HSVImage_tmp + 5202]
        > 0.3));
    }
  }

  /* Calcualte which pixels are yellow */
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  i1 = b_HSVImage->size[0] * b_HSVImage->size[1] * b_HSVImage->size[2];
  b_HSVImage->size[0] = loop_ub;
  b_HSVImage->size[1] = b_loop_ub;
  b_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_HSVImage, i1, &emlrtRTEI);
  i1 = c_HSVImage->size[0] * c_HSVImage->size[1] * c_HSVImage->size[2];
  c_HSVImage->size[0] = loop_ub;
  c_HSVImage->size[1] = b_loop_ub;
  c_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c_HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        d = SD->f0.HSVImage[((i + HSVImage_tmp) + 984 * (k + i2)) + 728160 * i1];
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = d;
        b_HSVImage->data[(HSVImage_tmp + b_HSVImage->size[0] * i2) +
          b_HSVImage->size[0] * b_HSVImage->size[1] * i1] = d;
        c_HSVImage->data[(HSVImage_tmp + c_HSVImage->size[0] * i2) +
          c_HSVImage->size[0] * c_HSVImage->size[1] * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      HSVImage_tmp = i2 + 51 * i1;
      centerColourMask[HSVImage_tmp + 5202] = ((((HSVImage->data[HSVImage_tmp] >
        50.0) && (b_HSVImage->data[HSVImage_tmp] < 70.0)) ||
        (centerHSVImage[HSVImage_tmp] == 50.0)) && (c_HSVImage->
        data[HSVImage_tmp + 2601] > 0.2) && (centerHSVImage[HSVImage_tmp + 5202]
        > 0.3));
    }
  }

  /* Calcualte which pixels are green */
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  i1 = b_HSVImage->size[0] * b_HSVImage->size[1] * b_HSVImage->size[2];
  b_HSVImage->size[0] = loop_ub;
  b_HSVImage->size[1] = b_loop_ub;
  b_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_HSVImage, i1, &emlrtRTEI);
  i1 = c_HSVImage->size[0] * c_HSVImage->size[1] * c_HSVImage->size[2];
  c_HSVImage->size[0] = loop_ub;
  c_HSVImage->size[1] = b_loop_ub;
  c_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c_HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        d = SD->f0.HSVImage[((i + HSVImage_tmp) + 984 * (k + i2)) + 728160 * i1];
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = d;
        b_HSVImage->data[(HSVImage_tmp + b_HSVImage->size[0] * i2) +
          b_HSVImage->size[0] * b_HSVImage->size[1] * i1] = d;
        c_HSVImage->data[(HSVImage_tmp + c_HSVImage->size[0] * i2) +
          c_HSVImage->size[0] * c_HSVImage->size[1] * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      HSVImage_tmp = i2 + 51 * i1;
      centerColourMask[HSVImage_tmp + 7803] = ((((HSVImage->data[HSVImage_tmp] >
        70.0) && (b_HSVImage->data[HSVImage_tmp] < 155.0)) ||
        (centerHSVImage[HSVImage_tmp] == 70.0)) && (c_HSVImage->
        data[HSVImage_tmp + 2601] > 0.2) && (centerHSVImage[HSVImage_tmp + 5202]
        > 0.3));
    }
  }

  /* Calcualte which pixels are cyan */
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  i1 = b_HSVImage->size[0] * b_HSVImage->size[1] * b_HSVImage->size[2];
  b_HSVImage->size[0] = loop_ub;
  b_HSVImage->size[1] = b_loop_ub;
  b_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_HSVImage, i1, &emlrtRTEI);
  i1 = c_HSVImage->size[0] * c_HSVImage->size[1] * c_HSVImage->size[2];
  c_HSVImage->size[0] = loop_ub;
  c_HSVImage->size[1] = b_loop_ub;
  c_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c_HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        d = SD->f0.HSVImage[((i + HSVImage_tmp) + 984 * (k + i2)) + 728160 * i1];
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = d;
        b_HSVImage->data[(HSVImage_tmp + b_HSVImage->size[0] * i2) +
          b_HSVImage->size[0] * b_HSVImage->size[1] * i1] = d;
        c_HSVImage->data[(HSVImage_tmp + c_HSVImage->size[0] * i2) +
          c_HSVImage->size[0] * c_HSVImage->size[1] * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      HSVImage_tmp = i2 + 51 * i1;
      centerColourMask[HSVImage_tmp + 10404] = ((((HSVImage->data[HSVImage_tmp] >
        155.0) && (b_HSVImage->data[HSVImage_tmp] < 205.0)) ||
        (centerHSVImage[HSVImage_tmp] == 155.0)) && (c_HSVImage->
        data[HSVImage_tmp + 2601] > 0.2) && (centerHSVImage[HSVImage_tmp + 5202]
        > 0.3));
    }
  }

  /* Calcualte which pixels are blue */
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  i1 = b_HSVImage->size[0] * b_HSVImage->size[1] * b_HSVImage->size[2];
  b_HSVImage->size[0] = loop_ub;
  b_HSVImage->size[1] = b_loop_ub;
  b_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_HSVImage, i1, &emlrtRTEI);
  i1 = c_HSVImage->size[0] * c_HSVImage->size[1] * c_HSVImage->size[2];
  c_HSVImage->size[0] = loop_ub;
  c_HSVImage->size[1] = b_loop_ub;
  c_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c_HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        d = SD->f0.HSVImage[((i + HSVImage_tmp) + 984 * (k + i2)) + 728160 * i1];
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = d;
        b_HSVImage->data[(HSVImage_tmp + b_HSVImage->size[0] * i2) +
          b_HSVImage->size[0] * b_HSVImage->size[1] * i1] = d;
        c_HSVImage->data[(HSVImage_tmp + c_HSVImage->size[0] * i2) +
          c_HSVImage->size[0] * c_HSVImage->size[1] * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      HSVImage_tmp = i2 + 51 * i1;
      centerColourMask[HSVImage_tmp + 13005] = ((((HSVImage->data[HSVImage_tmp] >
        205.0) && (b_HSVImage->data[HSVImage_tmp] < 260.0)) ||
        (centerHSVImage[HSVImage_tmp] == 205.0)) && (c_HSVImage->
        data[HSVImage_tmp + 2601] > 0.2) && (centerHSVImage[HSVImage_tmp + 5202]
        > 0.3));
    }
  }

  /* Calcualte which pixels are purple */
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  i1 = b_HSVImage->size[0] * b_HSVImage->size[1] * b_HSVImage->size[2];
  b_HSVImage->size[0] = loop_ub;
  b_HSVImage->size[1] = b_loop_ub;
  b_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_HSVImage, i1, &emlrtRTEI);
  i1 = c_HSVImage->size[0] * c_HSVImage->size[1] * c_HSVImage->size[2];
  c_HSVImage->size[0] = loop_ub;
  c_HSVImage->size[1] = b_loop_ub;
  c_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c_HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        d = SD->f0.HSVImage[((i + HSVImage_tmp) + 984 * (k + i2)) + 728160 * i1];
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = d;
        b_HSVImage->data[(HSVImage_tmp + b_HSVImage->size[0] * i2) +
          b_HSVImage->size[0] * b_HSVImage->size[1] * i1] = d;
        c_HSVImage->data[(HSVImage_tmp + c_HSVImage->size[0] * i2) +
          c_HSVImage->size[0] * c_HSVImage->size[1] * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      HSVImage_tmp = i2 + 51 * i1;
      centerColourMask[HSVImage_tmp + 15606] = ((((HSVImage->data[HSVImage_tmp] >
        260.0) && (b_HSVImage->data[HSVImage_tmp] < 315.0)) ||
        (centerHSVImage[HSVImage_tmp] == 260.0)) && (c_HSVImage->
        data[HSVImage_tmp + 2601] > 0.2) && (centerHSVImage[HSVImage_tmp + 5202]
        > 0.3));
    }
  }

  emxInit_real_T(sp, &d_HSVImage, 3, &emlrtRTEI, true);

  /* Calcualte which pixels are white */
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  i1 = b_HSVImage->size[0] * b_HSVImage->size[1] * b_HSVImage->size[2];
  b_HSVImage->size[0] = loop_ub;
  b_HSVImage->size[1] = b_loop_ub;
  b_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_HSVImage, i1, &emlrtRTEI);
  i1 = c_HSVImage->size[0] * c_HSVImage->size[1] * c_HSVImage->size[2];
  c_HSVImage->size[0] = loop_ub;
  c_HSVImage->size[1] = b_loop_ub;
  c_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c_HSVImage, i1, &emlrtRTEI);
  i1 = d_HSVImage->size[0] * d_HSVImage->size[1] * d_HSVImage->size[2];
  d_HSVImage->size[0] = loop_ub;
  d_HSVImage->size[1] = b_loop_ub;
  d_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, d_HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        d = SD->f0.HSVImage[((i + HSVImage_tmp) + 984 * (k + i2)) + 728160 * i1];
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = d;
        b_HSVImage->data[(HSVImage_tmp + b_HSVImage->size[0] * i2) +
          b_HSVImage->size[0] * b_HSVImage->size[1] * i1] = d;
        c_HSVImage->data[(HSVImage_tmp + c_HSVImage->size[0] * i2) +
          c_HSVImage->size[0] * c_HSVImage->size[1] * i1] = d;
        d_HSVImage->data[(HSVImage_tmp + d_HSVImage->size[0] * i2) +
          d_HSVImage->size[0] * d_HSVImage->size[1] * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i2 = 0; i2 < 51; i2++) {
      HSVImage_tmp = i2 + 51 * i1;
      centerColourMask[HSVImage_tmp + 18207] = (((HSVImage->data[HSVImage_tmp +
        5202] > 0.6) || (b_HSVImage->data[HSVImage_tmp + 5202] == 0.6)) &&
        ((c_HSVImage->data[HSVImage_tmp + 2601] < 0.2) || (d_HSVImage->
        data[HSVImage_tmp + 2601] == 0.2)));
    }
  }

  emxFree_real_T(&d_HSVImage);

  /* Calcualte which pixels are black */
  i1 = HSVImage->size[0] * HSVImage->size[1] * HSVImage->size[2];
  HSVImage->size[0] = loop_ub;
  HSVImage->size[1] = b_loop_ub;
  HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, HSVImage, i1, &emlrtRTEI);
  i1 = b_HSVImage->size[0] * b_HSVImage->size[1] * b_HSVImage->size[2];
  b_HSVImage->size[0] = loop_ub;
  b_HSVImage->size[1] = b_loop_ub;
  b_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_HSVImage, i1, &emlrtRTEI);
  i1 = c_HSVImage->size[0] * c_HSVImage->size[1] * c_HSVImage->size[2];
  c_HSVImage->size[0] = loop_ub;
  c_HSVImage->size[1] = b_loop_ub;
  c_HSVImage->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c_HSVImage, i1, &emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (HSVImage_tmp = 0; HSVImage_tmp < loop_ub; HSVImage_tmp++) {
        d = SD->f0.HSVImage[((i + HSVImage_tmp) + 984 * (k + i2)) + 728160 * i1];
        HSVImage->data[(HSVImage_tmp + HSVImage->size[0] * i2) + HSVImage->size
          [0] * HSVImage->size[1] * i1] = d;
        b_HSVImage->data[(HSVImage_tmp + b_HSVImage->size[0] * i2) +
          b_HSVImage->size[0] * b_HSVImage->size[1] * i1] = d;
        c_HSVImage->data[(HSVImage_tmp + c_HSVImage->size[0] * i2) +
          c_HSVImage->size[0] * c_HSVImage->size[1] * i1] = d;
      }
    }
  }

  for (i = 0; i < 51; i++) {
    for (i1 = 0; i1 < 51; i1++) {
      k = i1 + 51 * i;
      d = centerHSVImage[k + 2601];
      centerColourMask[k + 20808] = ((HSVImage->data[k + 5202] < 0.3) ||
        (b_HSVImage->data[k + 5202] == 0.3) || ((c_HSVImage->data[k + 5202] <
        0.6) && ((d < 0.2) || (d == 0.2))));
    }
  }

  emxFree_real_T(&c_HSVImage);
  emxFree_real_T(&b_HSVImage);
  emxFree_real_T(&HSVImage);

  /*  Sum up all the masks and then determine which mask has the most pixels */
  applyToMultipleDims(centerColourMask, nz);
  ex = nz[0];
  HSVImage_tmp = 1;
  for (k = 0; k < 8; k++) {
    d = nz[k + 1];
    if (ex < d) {
      ex = d;
      HSVImage_tmp = k + 2;
    }
  }

  memset(&colourSegmentationMask[0], 0, 728160U * sizeof(boolean_T));

  /*  Make a mask over the whole image. The colour that is seperated */
  /*  is the one that had the most pixels in the square */
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, HSVImage_tmp == 1)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);

    /* Red */
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = (((d < 15.0) || (d == 315.0) || (d > 315.0))
          && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k + 1456320]
          > 0.3));
      }
    }
  } else if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 1, HSVImage_tmp == 2)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);

    /* Orange */
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 15.0) && (d < 50.0)) || (d == 15.0))
          && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k + 1456320]
          > 0.3));
      }
    }
  } else if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 2, HSVImage_tmp == 3)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);

    /* Yellow */
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 50.0) && (d < 70.0)) || (d == 50.0))
          && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k + 1456320]
          > 0.3));
      }
    }
  } else if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 3, HSVImage_tmp == 4)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);

    /* Green */
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 70.0) && (d < 155.0)) || (d == 70.0))
          && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k + 1456320]
          > 0.3));
      }
    }
  } else if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 4, HSVImage_tmp == 5)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);

    /* Cyan */
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 155.0) && (d < 205.0)) || (d ==
          155.0)) && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k +
          1456320] > 0.3));
      }
    }
  } else if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 5, HSVImage_tmp == 6)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);

    /* Blue */
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 205.0) && (d < 260.0)) || (d ==
          205.0)) && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k +
          1456320] > 0.3));
      }
    }
  } else if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 6, HSVImage_tmp == 7)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 7U);

    /* Purple */
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k];
        colourSegmentationMask[k] = ((((d > 260.0) && (d < 315.0)) || (d ==
          260.0)) && (SD->f0.HSVImage[k + 728160] > 0.2) && (SD->f0.HSVImage[k +
          1456320] > 0.3));
      }
    }
  } else if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 7, HSVImage_tmp == 8)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 8U);

    /* White */
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k + 1456320];
        ex = SD->f0.HSVImage[k + 728160];
        colourSegmentationMask[k] = (((d > 0.6) || (d == 0.6)) && ((ex < 0.2) ||
          (ex == 0.2)));
      }
    }
  } else if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 8, HSVImage_tmp == 9)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 9U);

    /* Black */
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        k = i1 + 984 * i;
        d = SD->f0.HSVImage[k + 1456320];
        ex = SD->f0.HSVImage[k + 728160];
        colourSegmentationMask[k] = ((d < 0.3) || (d == 0.3) || ((d < 0.6) &&
          ((ex < 0.2) || (ex == 0.2))));
      }
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 10U);
    y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(sp, 5, m, &u[0]);
    emlrtAssign(&y, m);
    st.site = &c_emlrtRSI;
    disp(&st, y, &emlrtMCI);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (colourSegmentation.c) */
