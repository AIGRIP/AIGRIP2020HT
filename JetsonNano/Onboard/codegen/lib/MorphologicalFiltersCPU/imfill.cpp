//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  imfill.cpp
//
//  Code generation for function 'imfill'
//


// Include files
#include "imfill.h"
#include "imreconstruct.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
namespace coder
{
  void imfill(const bool varargin_1[728160], bool I2[728160])
  {
    static unsigned char I1[731612];
    static signed char b[731612];
    static unsigned char uv[731612];
    static signed char b_varargin_1[728160];
    array<double, 2U> y;
    double idx[1968];
    int b_nz;
    int i;
    int j;
    int nz;
    bool x[984];
    std::memset(&idx[0], 0, 1968U * sizeof(double));
    y.set_size(1, 984);
    for (i = 0; i < 984; i++) {
      y[i] = static_cast<double>(i) + 2.0;
    }

    for (i = 0; i < 984; i++) {
      idx[i] = y[i];
    }

    y.set_size(1, 740);
    for (i = 0; i < 740; i++) {
      y[i] = static_cast<double>(i) + 2.0;
    }

    for (i = 0; i < 740; i++) {
      idx[i + 984] = y[i];
    }

    for (i = 0; i < 986; i++) {
      I1[i] = 0U;
      I1[i + 730626] = 0U;
    }

    for (j = 0; j < 740; j++) {
      i = 986 * (j + 1);
      I1[i] = 0U;
      I1[i + 985] = 0U;
      std::memset(&I1[i + 1], 255, 984U * sizeof(unsigned char));
    }

    for (i = 0; i < 728160; i++) {
      b_varargin_1[i] = static_cast<signed char>(varargin_1[i]);
    }

    for (i = 0; i < 986; i++) {
      b[i] = 0;
      b[i + 730626] = 0;
    }

    for (j = 0; j < 740; j++) {
      i = 986 * (j + 1);
      b[i] = 0;
      b[i + 985] = 0;
      std::memcpy(&b[i + 1], &b_varargin_1[j * 984], 984U * sizeof(signed char));
    }

    for (i = 0; i < 731612; i++) {
      I1[i] = static_cast<unsigned char>(255U - I1[i]);
      uv[i] = static_cast<unsigned char>(255U - static_cast<unsigned char>(b[i]));
    }

    imreconstruct(I1, uv);
    for (i = 0; i < 731612; i++) {
      I1[i] = static_cast<unsigned char>(255U - I1[i]);
    }

    for (i = 0; i < 984; i++) {
      x[i] = (idx[i] != 0.0);
    }

    nz = x[0];
    for (i = 0; i < 983; i++) {
      nz += x[i + 1];
    }

    for (i = 0; i < 984; i++) {
      x[i] = (idx[i + 984] != 0.0);
    }

    b_nz = x[0];
    for (i = 0; i < 983; i++) {
      b_nz += x[i + 1];
    }

    for (i = 0; i < nz; i++) {
      for (j = 0; j < b_nz; j++) {
        I2[i + 984 * j] = (I1[(static_cast<int>(idx[i]) + 986 * (static_cast<int>
          (idx[j + 984]) - 1)) - 1] != 0);
      }
    }
  }
}

// End of code generation (imfill.cpp)
