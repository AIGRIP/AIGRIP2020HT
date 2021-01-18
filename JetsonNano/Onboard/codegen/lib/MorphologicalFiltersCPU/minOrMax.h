//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  minOrMax.h
//
//  Code generation for function 'minOrMax'
//


#ifndef MINORMAX_H
#define MINORMAX_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder
{
  namespace internal
  {
    unsigned char maximum(const unsigned char x_data[], const int x_size[1]);
    double minimum(const ::coder::array<double, 1U> &x);
    double minimum(const double x[10]);
  }
}

#endif

// End of code generation (minOrMax.h)
