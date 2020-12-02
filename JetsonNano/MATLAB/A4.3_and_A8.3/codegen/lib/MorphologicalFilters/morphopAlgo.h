//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: morphopAlgo.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 02-Dec-2020 13:31:29
//
#ifndef MORPHOPALGO_H
#define MORPHOPALGO_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder
{
  namespace images
  {
    namespace internal
    {
      namespace coder
      {
        void b_morphop_ver_hor_logical(const bool in[728160], bool o[728160]);
        void c_morphop_ver_hor_logical(const bool in[728160], bool o[728160]);
        void d_morphop_ver_hor_logical(const bool in[728160], bool o[728160]);
        void morphop_ver_hor_logical(const bool in[728160], bool o[728160]);
      }
    }
  }
}

#endif

//
// File trailer for morphopAlgo.h
//
// [EOF]
//
