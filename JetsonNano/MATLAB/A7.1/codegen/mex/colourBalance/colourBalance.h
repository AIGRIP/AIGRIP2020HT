//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  colourBalance.h
//
//  Code generation for function 'colourBalance'
//


#pragma once

// Include files
#include "colourBalance_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void colourBalance(colourBalanceStackData *SD, const emlrtStack *sp, const
                   uint8_T originalImage[2184480], uint8_T colourBalancedImage
                   [2184480]);

// End of code generation (colourBalance.h)
