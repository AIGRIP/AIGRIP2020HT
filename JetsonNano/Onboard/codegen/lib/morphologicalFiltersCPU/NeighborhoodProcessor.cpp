//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 05-Nov-2020 08:33:11
//

// Include Files
#include "NeighborhoodProcessor.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <cfloat>
#include <cmath>

// Function Declarations
static double rt_remd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_remd_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = rtNaN;
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    double b_u1;
    if (u1 < 0.0) {
      b_u1 = std::ceil(u1);
    } else {
      b_u1 = std::floor(u1);
    }

    if ((u1 != 0.0) && (u1 != b_u1)) {
      b_u1 = std::abs(u0 / u1);
      if (!(std::abs(b_u1 - std::floor(b_u1 + 0.5)) > DBL_EPSILON * b_u1)) {
        y = 0.0 * u0;
      } else {
        y = std::fmod(u0, u1);
      }
    } else {
      y = std::fmod(u0, u1);
    }
  }

  return y;
}

//
// Arguments    : const int imSize[2]
//                const bool nhConn[9]
//                int loffsets[5]
//                int linds[5]
//                int soffsets[10]
//                double interiorStart[2]
//                int interiorEnd[2]
// Return Type  : void
//
namespace coder
{
  namespace images
  {
    namespace internal
    {
      namespace coder
      {
        void NeighborhoodProcessor::computeParameters(const int imSize[2], const
          bool nhConn[9], int loffsets[5], int linds[5], int soffsets[10],
          double interiorStart[2], int interiorEnd[2])
        {
          int a[10];
          int k;
          int nz;
          int pixelsPerImPage_idx_1;

          //  Process pixels with full neighborhood
          //  Process pixels with partial neighborhood
          //  Process pixels with full neighborhood
          //  Process pixels with partial neighborhood
          pixelsPerImPage_idx_1 = imSize[0];
          interiorStart[0] = 2.0;
          interiorEnd[0] = imSize[0] - 1;
          interiorStart[1] = 2.0;
          interiorEnd[1] = imSize[1] - 1;
          nz = nhConn[0];
          for (k = 0; k < 8; k++) {
            nz += nhConn[k + 1];
          }

          if (nz != 0) {
            double b;
            int subs_idx_1_tmp_tmp;
            nz = 0;
            for (int pind = 0; pind < 9; pind++) {
              if (nhConn[pind]) {
                subs_idx_1_tmp_tmp = static_cast<int>(rt_remd_snf((static_cast<
                  double>(pind) + 1.0) - 1.0, 3.0));
                k = static_cast<int>((static_cast<double>((pind -
                  subs_idx_1_tmp_tmp) - 1) + 1.0) / 3.0);
                soffsets[nz] = subs_idx_1_tmp_tmp + 1;
                soffsets[nz + 5] = k + 1;
                linds[nz] = static_cast<signed char>(subs_idx_1_tmp_tmp + 1) + k
                  * 3;
                loffsets[nz] = (subs_idx_1_tmp_tmp + k * pixelsPerImPage_idx_1)
                  + 1;
                nz++;
              }
            }

            b = static_cast<double>(imSize[0]) + 2.0;
            for (nz = 0; nz < 5; nz++) {
              loffsets[nz] -= static_cast<int>(b);
            }

            for (nz = 0; nz < 10; nz++) {
              a[nz] = soffsets[nz];
            }

            for (k = 0; k < 2; k++) {
              for (subs_idx_1_tmp_tmp = 0; subs_idx_1_tmp_tmp < 5;
                   subs_idx_1_tmp_tmp++) {
                nz = subs_idx_1_tmp_tmp + 5 * k;
                soffsets[nz] = a[nz] - 2;
              }
            }
          }
        }
      }
    }
  }
}

//
// File trailer for NeighborhoodProcessor.cpp
//
// [EOF]
//
