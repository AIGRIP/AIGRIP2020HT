//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  morphopAlgo.h
//
//  Code generation for function 'morphopAlgo'
//


#ifndef MORPHOPALGO_H
#define MORPHOPALGO_H

// Include files
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

// End of code generation (morphopAlgo.h)
