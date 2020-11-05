/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bwconncomp.c
 *
 * Code generation for function 'bwconncomp'
 *
 */

/* Include files */
#include "bwconncomp.h"
#include "eml_int_forloop_overflow_check.h"
#include "morphologicalFilters_data.h"
#include "morphologicalFilters_emxutil.h"
#include "morphologicalFilters_types.h"
#include "rt_nonfinite.h"
#include "useConstantDim.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 79,  /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 71,  /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 70,  /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 69,  /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 57,  /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 44, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 23, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 51, /* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 149,/* lineNo */
  "uf_new_pair",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 150,/* lineNo */
  "uf_new_pair",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 153,/* lineNo */
  "uf_new_pair",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 48,  /* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 55,  /* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  233,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "fillRunVectors",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  234,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "fillRunVectors",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "fillRunVectors",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 69,  /* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 69,  /* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "uf_find_root",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "uf_find_root",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_find_root",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "uf_find_root",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_union",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_union",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_union",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_union",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ob_emlrtRTEI = { 48,/* lineNo */
  27,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 49,/* lineNo */
  25,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 50,/* lineNo */
  28,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 39,/* lineNo */
  35,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 69,/* lineNo */
  31,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 14,/* lineNo */
  5,                                   /* colNo */
  "cumsum",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 11,/* lineNo */
  6,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 70,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

/* Function Definitions */
void bwconncomp(const emlrtStack *sp, const boolean_T varargin_1[728160], real_T
                *CC_Connectivity, real_T CC_ImageSize[2], real_T *CC_NumObjects,
                emxArray_real_T *CC_RegionIndices, emxArray_int32_T
                *CC_RegionLengths)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_int16_T *endRow;
  emxArray_int16_T *startCol;
  emxArray_int16_T *startRow;
  emxArray_int32_T *idxCount;
  emxArray_int32_T *labelsRenumbered;
  emxArray_int32_T *pixelIdxList;
  emxArray_int32_T *x;
  real_T numComponents;
  real_T y;
  int32_T exitg1;
  int32_T firstRunOnPreviousColumn;
  int32_T firstRunOnThisColumn;
  int32_T i;
  int32_T k;
  int32_T lastRunOnPreviousColumn;
  int32_T numRuns;
  int32_T p;
  int32_T root_k;
  int32_T root_p;
  int32_T row;
  int32_T runCounter;
  boolean_T overflow;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &bb_emlrtRSI;
  numRuns = 0;
  for (firstRunOnPreviousColumn = 0; firstRunOnPreviousColumn < 740;
       firstRunOnPreviousColumn++) {
    if (varargin_1[984 * firstRunOnPreviousColumn]) {
      numRuns++;
    }

    for (k = 0; k < 983; k++) {
      i = k + 984 * firstRunOnPreviousColumn;
      if (varargin_1[i + 1] && (!varargin_1[i])) {
        numRuns++;
      }
    }
  }

  emxInit_int16_T(&st, &startRow, 1, &cc_emlrtRTEI, true);
  emxInit_int16_T(&st, &endRow, 1, &cc_emlrtRTEI, true);
  emxInit_int16_T(&st, &startCol, 1, &cc_emlrtRTEI, true);
  if (numRuns == 0) {
    startRow->size[0] = 0;
    endRow->size[0] = 0;
    startCol->size[0] = 0;
    CC_RegionLengths->size[0] = 0;
  } else {
    if (numRuns < 0) {
      emlrtNonNegativeCheckR2012b(numRuns, &b_emlrtDCI, &st);
    }

    i = startRow->size[0];
    startRow->size[0] = numRuns;
    emxEnsureCapacity_int16_T(&st, startRow, i, &ob_emlrtRTEI);
    i = endRow->size[0];
    endRow->size[0] = numRuns;
    emxEnsureCapacity_int16_T(&st, endRow, i, &pb_emlrtRTEI);
    i = startCol->size[0];
    startCol->size[0] = numRuns;
    emxEnsureCapacity_int16_T(&st, startCol, i, &qb_emlrtRTEI);
    b_st.site = &cb_emlrtRSI;
    runCounter = 1;
    for (firstRunOnPreviousColumn = 0; firstRunOnPreviousColumn < 740;
         firstRunOnPreviousColumn++) {
      row = 1;
      while (row <= 984) {
        while ((row <= 984) && (!varargin_1[(row + 984 *
                 firstRunOnPreviousColumn) - 1])) {
          row++;
        }

        if ((row <= 984) && varargin_1[(row + 984 * firstRunOnPreviousColumn) -
            1]) {
          if ((runCounter < 1) || (runCounter > startCol->size[0])) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, startCol->size[0],
              &fb_emlrtBCI, &b_st);
          }

          startCol->data[runCounter - 1] = (int16_T)(firstRunOnPreviousColumn +
            1);
          if (runCounter > startRow->size[0]) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, startRow->size[0],
              &gb_emlrtBCI, &b_st);
          }

          startRow->data[runCounter - 1] = (int16_T)row;
          while ((row <= 984) && varargin_1[(row + 984 *
                  firstRunOnPreviousColumn) - 1]) {
            row++;
          }

          if (runCounter > endRow->size[0]) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, endRow->size[0],
              &nb_emlrtBCI, &b_st);
          }

          endRow->data[runCounter - 1] = (int16_T)(row - 1);
          runCounter++;
        }
      }
    }

    i = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = numRuns;
    emxEnsureCapacity_int32_T(&st, CC_RegionLengths, i, &sb_emlrtRTEI);
    for (i = 0; i < numRuns; i++) {
      CC_RegionLengths->data[i] = 0;
    }

    k = 1;
    runCounter = 1;
    row = 1;
    firstRunOnPreviousColumn = -1;
    lastRunOnPreviousColumn = -1;
    firstRunOnThisColumn = 1;
    while (k <= numRuns) {
      if ((k < 1) || (k > startCol->size[0])) {
        emlrtDynamicBoundsCheckR2012b(k, 1, startCol->size[0], &hb_emlrtBCI, &st);
      }

      i = startCol->data[k - 1];
      if (i == runCounter + 1) {
        firstRunOnPreviousColumn = firstRunOnThisColumn;
        firstRunOnThisColumn = k;
        lastRunOnPreviousColumn = k - 1;
        if (k > startCol->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k, 1, startCol->size[0], &ob_emlrtBCI,
            &st);
        }

        runCounter = startCol->data[k - 1];
      } else {
        if (k > startCol->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k, 1, startCol->size[0], &ib_emlrtBCI,
            &st);
        }

        if (i > runCounter + 1) {
          firstRunOnPreviousColumn = -1;
          lastRunOnPreviousColumn = -1;
          firstRunOnThisColumn = k;
          if (k > startCol->size[0]) {
            emlrtDynamicBoundsCheckR2012b(k, 1, startCol->size[0], &pb_emlrtBCI,
              &st);
          }

          runCounter = i;
        }
      }

      if (firstRunOnPreviousColumn >= 0) {
        for (p = firstRunOnPreviousColumn; p <= lastRunOnPreviousColumn; p++) {
          if (k > endRow->size[0]) {
            emlrtDynamicBoundsCheckR2012b(k, 1, endRow->size[0], &sb_emlrtBCI,
              &st);
          }

          if ((p < 1) || (p > startRow->size[0])) {
            emlrtDynamicBoundsCheckR2012b(p, 1, startRow->size[0], &tb_emlrtBCI,
              &st);
          }

          if (endRow->data[k - 1] >= startRow->data[p - 1] - 1) {
            if (k > startRow->size[0]) {
              emlrtDynamicBoundsCheckR2012b(k, 1, startRow->size[0],
                &ub_emlrtBCI, &st);
            }

            if (p > endRow->size[0]) {
              emlrtDynamicBoundsCheckR2012b(p, 1, endRow->size[0], &vb_emlrtBCI,
                &st);
            }

            if (startRow->data[k - 1] <= endRow->data[p - 1] + 1) {
              if (k > CC_RegionLengths->size[0]) {
                emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
                  &wb_emlrtBCI, &st);
              }

              i = CC_RegionLengths->data[k - 1];
              if (i == 0) {
                if (p > CC_RegionLengths->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(p, 1, CC_RegionLengths->size[0],
                    &ac_emlrtBCI, &st);
                }

                if (k > CC_RegionLengths->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
                    &bc_emlrtBCI, &st);
                }

                CC_RegionLengths->data[k - 1] = CC_RegionLengths->data[p - 1];
                row++;
              } else {
                if (k > CC_RegionLengths->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
                    &xb_emlrtBCI, &st);
                }

                if (p > CC_RegionLengths->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(p, 1, CC_RegionLengths->size[0],
                    &yb_emlrtBCI, &st);
                }

                if (i != CC_RegionLengths->data[p - 1]) {
                  b_st.site = &db_emlrtRSI;
                  c_st.site = &eb_emlrtRSI;
                  root_k = k;
                  do {
                    exitg1 = 0;
                    if ((root_k < 1) || (root_k > CC_RegionLengths->size[0])) {
                      emlrtDynamicBoundsCheckR2012b(root_k, 1,
                        CC_RegionLengths->size[0], &cc_emlrtBCI, &c_st);
                    }

                    i = CC_RegionLengths->data[root_k - 1];
                    if (root_k != i) {
                      if (root_k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1,
                          CC_RegionLengths->size[0], &dc_emlrtBCI, &c_st);
                      }

                      if ((i < 1) || (i > CC_RegionLengths->size[0])) {
                        emlrtDynamicBoundsCheckR2012b(i, 1,
                          CC_RegionLengths->size[0], &dc_emlrtBCI, &c_st);
                      }

                      if (root_k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1,
                          CC_RegionLengths->size[0], &ec_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[root_k - 1] =
                        CC_RegionLengths->data[i - 1];
                      if (root_k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1,
                          CC_RegionLengths->size[0], &fc_emlrtBCI, &c_st);
                      }

                      root_k = CC_RegionLengths->data[root_k - 1];
                    } else {
                      exitg1 = 1;
                    }
                  } while (exitg1 == 0);

                  c_st.site = &fb_emlrtRSI;
                  root_p = p;
                  do {
                    exitg1 = 0;
                    if ((root_p < 1) || (root_p > CC_RegionLengths->size[0])) {
                      emlrtDynamicBoundsCheckR2012b(root_p, 1,
                        CC_RegionLengths->size[0], &cc_emlrtBCI, &c_st);
                    }

                    i = CC_RegionLengths->data[root_p - 1];
                    if (root_p != i) {
                      if (root_p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1,
                          CC_RegionLengths->size[0], &dc_emlrtBCI, &c_st);
                      }

                      if ((i < 1) || (i > CC_RegionLengths->size[0])) {
                        emlrtDynamicBoundsCheckR2012b(i, 1,
                          CC_RegionLengths->size[0], &dc_emlrtBCI, &c_st);
                      }

                      if (root_p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1,
                          CC_RegionLengths->size[0], &ec_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[root_p - 1] =
                        CC_RegionLengths->data[i - 1];
                      if (root_p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1,
                          CC_RegionLengths->size[0], &fc_emlrtBCI, &c_st);
                      }

                      root_p = CC_RegionLengths->data[root_p - 1];
                    } else {
                      exitg1 = 1;
                    }
                  } while (exitg1 == 0);

                  if (root_k != root_p) {
                    c_st.site = &gb_emlrtRSI;
                    if (root_p < root_k) {
                      if (root_k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1,
                          CC_RegionLengths->size[0], &hc_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[root_k - 1] = root_p;
                      if (k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(k, 1,
                          CC_RegionLengths->size[0], &jc_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[k - 1] = root_p;
                    } else {
                      if (root_p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1,
                          CC_RegionLengths->size[0], &gc_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[root_p - 1] = root_k;
                      if (p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(p, 1,
                          CC_RegionLengths->size[0], &ic_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[p - 1] = root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      if (k > CC_RegionLengths->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
          &qb_emlrtBCI, &st);
      }

      if (CC_RegionLengths->data[k - 1] == 0) {
        if (k > CC_RegionLengths->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
            &rb_emlrtBCI, &st);
        }

        CC_RegionLengths->data[k - 1] = row;
        row++;
      }

      k++;
    }
  }

  if (numRuns == 0) {
    CC_ImageSize[0] = 984.0;
    CC_ImageSize[1] = 740.0;
    runCounter = 0;
    CC_RegionIndices->size[0] = 0;
    i = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = 1;
    emxEnsureCapacity_int32_T(sp, CC_RegionLengths, i, &tb_emlrtRTEI);
    CC_RegionLengths->data[0] = 0;
  } else {
    emxInit_int32_T(sp, &labelsRenumbered, 1, &bc_emlrtRTEI, true);
    i = labelsRenumbered->size[0];
    labelsRenumbered->size[0] = CC_RegionLengths->size[0];
    emxEnsureCapacity_int32_T(sp, labelsRenumbered, i, &rb_emlrtRTEI);
    numComponents = 0.0;
    st.site = &ab_emlrtRSI;
    for (k = 0; k < numRuns; k++) {
      if (k + 1 > CC_RegionLengths->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, CC_RegionLengths->size[0],
          &bb_emlrtBCI, sp);
      }

      if (CC_RegionLengths->data[k] == k + 1) {
        numComponents++;
        if (k + 1 > labelsRenumbered->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, labelsRenumbered->size[0],
            &eb_emlrtBCI, sp);
        }

        labelsRenumbered->data[k] = (int32_T)numComponents;
      }

      if (k + 1 > CC_RegionLengths->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, CC_RegionLengths->size[0],
          &cb_emlrtBCI, sp);
      }

      i = CC_RegionLengths->data[k];
      if ((i < 1) || (i > labelsRenumbered->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, labelsRenumbered->size[0],
          &cb_emlrtBCI, sp);
      }

      if (k + 1 > labelsRenumbered->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, labelsRenumbered->size[0],
          &db_emlrtBCI, sp);
      }

      labelsRenumbered->data[k] = labelsRenumbered->data[i - 1];
    }

    if (numComponents != (int32_T)numComponents) {
      emlrtIntegerCheckR2012b(numComponents, &c_emlrtDCI, sp);
    }

    i = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = (int32_T)numComponents;
    emxEnsureCapacity_int32_T(sp, CC_RegionLengths, i, &ub_emlrtRTEI);
    if ((int32_T)numComponents != (int32_T)numComponents) {
      emlrtIntegerCheckR2012b(numComponents, &c_emlrtDCI, sp);
    }

    row = (int32_T)numComponents;
    for (i = 0; i < row; i++) {
      CC_RegionLengths->data[i] = 0;
    }

    st.site = &y_emlrtRSI;
    for (k = 0; k < numRuns; k++) {
      if (k + 1 > labelsRenumbered->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, labelsRenumbered->size[0],
          &x_emlrtBCI, sp);
      }

      i = labelsRenumbered->data[k];
      if ((i < 1) || (i > CC_RegionLengths->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, CC_RegionLengths->size[0],
          &jb_emlrtBCI, sp);
      }

      if (k + 1 > endRow->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, endRow->size[0], &kb_emlrtBCI,
          sp);
      }

      if (k + 1 > startRow->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, startRow->size[0], &lb_emlrtBCI,
          sp);
      }

      runCounter = labelsRenumbered->data[k];
      if ((runCounter < 1) || (runCounter > CC_RegionLengths->size[0])) {
        emlrtDynamicBoundsCheckR2012b(runCounter, 1, CC_RegionLengths->size[0],
          &mb_emlrtBCI, sp);
      }

      CC_RegionLengths->data[runCounter - 1] = ((CC_RegionLengths->data[i - 1] +
        endRow->data[k]) - startRow->data[k]) + 1;
    }

    st.site = &x_emlrtRSI;
    b_st.site = &hb_emlrtRSI;
    c_st.site = &ib_emlrtRSI;
    runCounter = CC_RegionLengths->size[0];
    if (CC_RegionLengths->size[0] == 0) {
      y = 0.0;
    } else {
      d_st.site = &jb_emlrtRSI;
      y = CC_RegionLengths->data[0];
      e_st.site = &kb_emlrtRSI;
      if (2 > CC_RegionLengths->size[0]) {
        overflow = false;
      } else {
        overflow = (CC_RegionLengths->size[0] > 2147483646);
      }

      if (overflow) {
        f_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (k = 2; k <= runCounter; k++) {
        y += (real_T)CC_RegionLengths->data[k - 1];
      }
    }

    if (!(y >= 0.0)) {
      emlrtNonNegativeCheckR2012b(y, &e_emlrtDCI, sp);
    }

    if (y != (int32_T)y) {
      emlrtIntegerCheckR2012b(y, &d_emlrtDCI, sp);
    }

    emxInit_int32_T(sp, &pixelIdxList, 1, &ac_emlrtRTEI, true);
    emxInit_int32_T(sp, &x, 1, &dc_emlrtRTEI, true);
    i = pixelIdxList->size[0];
    pixelIdxList->size[0] = (int32_T)y;
    emxEnsureCapacity_int32_T(sp, pixelIdxList, i, &vb_emlrtRTEI);
    st.site = &w_emlrtRSI;
    b_st.site = &lb_emlrtRSI;
    runCounter = 2;
    if (CC_RegionLengths->size[0] != 1) {
      runCounter = 1;
    }

    i = x->size[0];
    x->size[0] = CC_RegionLengths->size[0];
    emxEnsureCapacity_int32_T(&b_st, x, i, &wb_emlrtRTEI);
    row = CC_RegionLengths->size[0];
    for (i = 0; i < row; i++) {
      x->data[i] = CC_RegionLengths->data[i];
    }

    emxInit_int32_T(&b_st, &idxCount, 1, &xb_emlrtRTEI, true);
    c_st.site = &mb_emlrtRSI;
    useConstantDim(&c_st, x, runCounter);
    i = idxCount->size[0];
    idxCount->size[0] = x->size[0] + 1;
    emxEnsureCapacity_int32_T(sp, idxCount, i, &xb_emlrtRTEI);
    idxCount->data[0] = 0;
    row = x->size[0];
    for (i = 0; i < row; i++) {
      idxCount->data[i + 1] = x->data[i];
    }

    emxFree_int32_T(&x);
    st.site = &v_emlrtRSI;
    for (k = 0; k < numRuns; k++) {
      if (k + 1 > startCol->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, startCol->size[0], &y_emlrtBCI,
          sp);
      }

      runCounter = (startCol->data[k] - 1) * 984;
      if (k + 1 > labelsRenumbered->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, labelsRenumbered->size[0],
          &kc_emlrtBCI, sp);
      }

      row = labelsRenumbered->data[k];
      if (k + 1 > startRow->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, startRow->size[0], &lc_emlrtBCI,
          sp);
      }

      firstRunOnPreviousColumn = startRow->data[k];
      if (k + 1 > endRow->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, endRow->size[0], &mc_emlrtBCI,
          sp);
      }

      lastRunOnPreviousColumn = endRow->data[k];
      st.site = &u_emlrtRSI;
      for (firstRunOnThisColumn = firstRunOnPreviousColumn; firstRunOnThisColumn
           <= lastRunOnPreviousColumn; firstRunOnThisColumn++) {
        if ((row < 1) || (row > idxCount->size[0])) {
          emlrtDynamicBoundsCheckR2012b(row, 1, idxCount->size[0], &ab_emlrtBCI,
            sp);
        }

        idxCount->data[row - 1]++;
        if (row > idxCount->size[0]) {
          emlrtDynamicBoundsCheckR2012b(row, 1, idxCount->size[0], &nc_emlrtBCI,
            sp);
        }

        i = idxCount->data[row - 1];
        if ((i < 1) || (i > pixelIdxList->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i, 1, pixelIdxList->size[0],
            &nc_emlrtBCI, sp);
        }

        pixelIdxList->data[i - 1] = firstRunOnThisColumn + runCounter;
      }
    }

    emxFree_int32_T(&idxCount);
    emxFree_int32_T(&labelsRenumbered);
    CC_ImageSize[0] = 984.0;
    CC_ImageSize[1] = 740.0;
    runCounter = (int32_T)numComponents;
    i = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = pixelIdxList->size[0];
    emxEnsureCapacity_real_T(sp, CC_RegionIndices, i, &yb_emlrtRTEI);
    row = pixelIdxList->size[0];
    for (i = 0; i < row; i++) {
      CC_RegionIndices->data[i] = pixelIdxList->data[i];
    }

    emxFree_int32_T(&pixelIdxList);
  }

  emxFree_int16_T(&startCol);
  emxFree_int16_T(&endRow);
  emxFree_int16_T(&startRow);
  *CC_Connectivity = 8.0;
  *CC_NumObjects = runCounter;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (bwconncomp.c) */
