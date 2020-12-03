//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 03-Dec-2020 08:29:52
//

// Include Files
#include "NeighborhoodProcessor.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <cfloat>
#include <cmath>
#include <cstring>

// Function Declarations
static int div_s32(int numerator, int denominator);
static double rt_remd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_s32(int numerator, int denominator)
{
  unsigned int b_numerator;
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int b_denominator;
    if (numerator < 0) {
      b_numerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      b_numerator = static_cast<unsigned int>(numerator);
    }

    if (denominator < 0) {
      b_denominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      b_denominator = static_cast<unsigned int>(denominator);
    }

    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int>(b_numerator);
    } else {
      quotient = static_cast<int>(b_numerator);
    }
  }

  return quotient;
}

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
//                int loffsets[9]
//                int linds[9]
//                int soffsets[18]
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
        void NeighborhoodProcessor::b_computeParameters(const int imSize[2],
          const bool nhConn[9], int loffsets[9], int linds[9], int soffsets[18],
          double interiorStart[2], int interiorEnd[2])
        {
          int a[18];
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
                soffsets[nz + 9] = k + 1;
                linds[nz] = static_cast<signed char>(subs_idx_1_tmp_tmp + 1) + k
                  * 3;
                loffsets[nz] = (subs_idx_1_tmp_tmp + k * pixelsPerImPage_idx_1)
                  + 1;
                nz++;
              }
            }

            b = static_cast<double>(imSize[0]) + 2.0;
            for (nz = 0; nz < 9; nz++) {
              loffsets[nz] -= static_cast<int>(b);
            }

            std::memcpy(&a[0], &soffsets[0], 18U * sizeof(int));
            for (k = 0; k < 2; k++) {
              for (subs_idx_1_tmp_tmp = 0; subs_idx_1_tmp_tmp < 9;
                   subs_idx_1_tmp_tmp++) {
                nz = subs_idx_1_tmp_tmp + 9 * k;
                soffsets[nz] = a[nz] - 2;
              }
            }
          }
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

        //
        // Arguments    : const bool in[728160]
        //                bool out[728160]
        // Return Type  : void
        //
        void NeighborhoodProcessor::process2D(const bool in[728160], bool out
          [728160]) const
        {
          array<double, 1U> c_imnh_data;
          array<double, 1U> d_imnh_data;
          array<double, 1U> e_imnh_data;
          array<double, 1U> f_imnh_data;
          double b_imnh_data[10];
          double imnh[10];
          int imnhSubs[18];
          int b_imnhInds_data[9];
          int c_imnhInds_data[9];
          int d_imnhInds_data[9];
          int imnhInds[9];
          int imnhInds_data[9];
          int nhInds[9];
          int pixelSub[2];
          int b_i;
          int b_secondDimExtents_idx_1;
          int b_trueCount;
          int c_trueCount;
          int firstInd;
          int i;
          int i1;
          int imageSize1;
          int lb_loop;
          int pind;
          int trueCount;
          int ub_loop;
          int x;
          bool out_[984];
          bool imnh_data[9];
          bool isInside[9];
          pixelSub[0] = static_cast<int>(this->InteriorStart[0]);
          pixelSub[1] = this->InteriorEnd[0];
          imageSize1 = this->ImageSize[0];
          lb_loop = static_cast<int>(this->InteriorStart[1]);
          ub_loop = this->InteriorEnd[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(imnhInds,pind,out_,i,i1,firstInd,b_i,imnh)

          for (int secondInd = lb_loop; secondInd <= ub_loop; secondInd++) {
            i = pixelSub[0];
            i1 = pixelSub[1];
            for (firstInd = i; firstInd <= i1; firstInd++) {
              pind = (secondInd - 1) * imageSize1 + firstInd;
              for (b_i = 0; b_i < 9; b_i++) {
                imnhInds[b_i] = this->ImageNeighborLinearOffsets[b_i] + pind;
              }

              for (pind = 0; pind < 9; pind++) {
                imnh[pind] = in[imnhInds[pind] - 1];
              }

              imnh[9] = 1.0;
              out_[firstInd - 1] = (::coder::internal::minimum(imnh) != 0.0);
            }

            std::memcpy(&out[secondInd * 984 + -984], &out_[0], 984U * sizeof
                        (bool));
          }

          if (this->ProcessBorder) {
            double secondDimExtents_idx_1;
            int b_firstInd;
            int b_pind;
            int b_secondInd;
            int secondDimExtents_idx_0;
            int u1;
            int z;
            bool exitg1;
            bool padValue;
            secondDimExtents_idx_1 = this->InteriorStart[1] - 1.0;
            padValue = (this->PadValue != 0.0);
            imageSize1 = this->ImageSize[0];
            u1 = this->ImageSize[0];
            if (imageSize1 < u1) {
              u1 = imageSize1;
            }

            imageSize1 = this->ImageSize[1];
            if (rtIsNaN(secondDimExtents_idx_1) || (secondDimExtents_idx_1 >
                 imageSize1)) {
              secondDimExtents_idx_0 = imageSize1;
            } else {
              secondDimExtents_idx_0 = static_cast<int>(secondDimExtents_idx_1);
            }

            for (b_secondInd = 0; b_secondInd < secondDimExtents_idx_0;
                 b_secondInd++) {
              for (b_firstInd = 1; b_firstInd <= u1; b_firstInd++) {
                b_pind = (b_secondInd * this->ImageSize[0] + b_firstInd) - 1;
                for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                  nhInds[imageSize1] = (this->
                                        ImageNeighborLinearOffsets[imageSize1] +
                                        b_pind) + 1;
                }

                pixelSub[0] = this->ImageSize[0];
                if (pixelSub[0] == 0) {
                  lb_loop = 0;
                } else {
                  lb_loop = b_pind - pixelSub[0] * div_s32(b_pind, pixelSub[0]);
                }

                ub_loop = b_pind - lb_loop;
                if (pixelSub[0] == 0) {
                  if (ub_loop == 0) {
                    z = 0;
                  } else if (ub_loop < 0) {
                    z = MIN_int32_T;
                  } else {
                    z = MAX_int32_T;
                  }
                } else if (pixelSub[0] == 1) {
                  z = ub_loop;
                } else if (pixelSub[0] == -1) {
                  z = -ub_loop;
                } else {
                  if (ub_loop >= 0) {
                    x = ub_loop;
                  } else if (ub_loop == MIN_int32_T) {
                    x = MAX_int32_T;
                  } else {
                    x = -ub_loop;
                  }

                  if (pixelSub[0] >= 0) {
                    imageSize1 = pixelSub[0];
                  } else if (pixelSub[0] == MIN_int32_T) {
                    imageSize1 = MAX_int32_T;
                  } else {
                    imageSize1 = -pixelSub[0];
                  }

                  z = div_s32(x, imageSize1);
                  x -= z * imageSize1;
                  if ((x > 0) && (x >= (imageSize1 >> 1) + (imageSize1 & 1))) {
                    z++;
                  }

                  if ((ub_loop < 0) != (pixelSub[0] < 0)) {
                    z = -z;
                  }
                }

                pixelSub[1] = z + 1;
                pixelSub[0] = lb_loop + 1;
                for (lb_loop = 0; lb_loop < 2; lb_loop++) {
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    imageSize1 = ub_loop + 9 * lb_loop;
                    imnhSubs[imageSize1] = this->
                      NeighborSubscriptOffsets[imageSize1] + pixelSub[lb_loop];
                  }
                }

                for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                  isInside[imageSize1] = true;
                }

                switch (static_cast<int>(this->Padding)) {
                 case 1:
                  b_secondDimExtents_idx_1 = 0;
                  imageSize1 = 0;
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    lb_loop = 0;
                    exitg1 = false;
                    while ((!exitg1) && (lb_loop < 2)) {
                      x = imnhSubs[ub_loop + 9 * lb_loop];
                      if ((x < 1) || (x > this->ImageSize[lb_loop])) {
                        isInside[ub_loop] = false;
                        exitg1 = true;
                      } else {
                        lb_loop++;
                      }
                    }

                    if (isInside[ub_loop]) {
                      b_secondDimExtents_idx_1++;
                      imnhInds_data[imageSize1] = nhInds[ub_loop];
                      imageSize1++;
                    }
                  }
                  break;

                 case 2:
                  b_secondDimExtents_idx_1 = 9;
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    imnhInds_data[ub_loop] = nhInds[ub_loop];
                    lb_loop = 0;
                    exitg1 = false;
                    while ((!exitg1) && (lb_loop < 2)) {
                      x = imnhSubs[ub_loop + 9 * lb_loop];
                      if ((x < 1) || (x > this->ImageSize[lb_loop])) {
                        isInside[ub_loop] = false;
                        imnhInds_data[ub_loop] = 1;
                        exitg1 = true;
                      } else {
                        lb_loop++;
                      }
                    }
                  }
                  break;

                 case 3:
                  b_secondDimExtents_idx_1 = 9;
                  for (x = 0; x < 9; x++) {
                    imnhInds_data[x] = nhInds[x];
                  }

                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    x = imnhSubs[ub_loop];
                    pixelSub[0] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x = 1;
                      pixelSub[0] = 1;
                    }

                    if (x > this->ImageSize[0]) {
                      isInside[ub_loop] = false;
                      pixelSub[0] = this->ImageSize[0];
                    }

                    x = imnhSubs[ub_loop + 9];
                    pixelSub[1] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x = 1;
                      pixelSub[1] = 1;
                    }

                    if (x > this->ImageSize[1]) {
                      isInside[ub_loop] = false;
                      pixelSub[1] = this->ImageSize[1];
                    }

                    if (!isInside[ub_loop]) {
                      imnhInds_data[ub_loop] = pixelSub[0] + (pixelSub[1] - 1) *
                        this->ImageSize[0];
                    }
                  }
                  break;

                 case 4:
                  b_secondDimExtents_idx_1 = 9;
                  for (x = 0; x < 9; x++) {
                    imnhInds_data[x] = nhInds[x];
                  }

                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    x = imnhSubs[ub_loop];
                    pixelSub[0] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x += this->ImageSize[0] << 1;
                      pixelSub[0] = x;
                    }

                    if (x > this->ImageSize[0]) {
                      isInside[ub_loop] = false;
                      x = ((this->ImageSize[0] << 1) - x) + 1;
                      pixelSub[0] = x;
                    }

                    x = imnhSubs[ub_loop + 9];
                    pixelSub[1] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x += this->ImageSize[1] << 1;
                      pixelSub[1] = x;
                    }

                    if (x > this->ImageSize[1]) {
                      isInside[ub_loop] = false;
                      x = ((this->ImageSize[1] << 1) - x) + 1;
                      pixelSub[1] = x;
                    }

                    if (!isInside[ub_loop]) {
                      imnhInds_data[ub_loop] = pixelSub[0] + (pixelSub[1] - 1) *
                        this->ImageSize[0];
                    }
                  }
                  break;
                }

                for (x = 0; x < b_secondDimExtents_idx_1; x++) {
                  imnh_data[x] = in[imnhInds_data[x] - 1];
                }

                if (this->Padding == 2.0) {
                  for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                    if (!isInside[imageSize1]) {
                      imnh_data[imageSize1] = padValue;
                    }
                  }
                }

                imageSize1 = b_secondDimExtents_idx_1 + 1;
                for (x = 0; x < b_secondDimExtents_idx_1; x++) {
                  b_imnh_data[x] = imnh_data[x];
                }

                b_imnh_data[b_secondDimExtents_idx_1] = 1.0;
                c_imnh_data.set((&b_imnh_data[0]), imageSize1);
                out[b_pind] = (::coder::internal::minimum(c_imnh_data) != 0.0);
              }
            }

            secondDimExtents_idx_0 = this->InteriorEnd[1] + 1;
            b_secondDimExtents_idx_1 = this->ImageSize[1];
            padValue = (this->PadValue != 0.0);
            if (secondDimExtents_idx_0 < 1) {
              secondDimExtents_idx_0 = 1;
            }

            imageSize1 = this->ImageSize[1];
            if (b_secondDimExtents_idx_1 >= imageSize1) {
              b_secondDimExtents_idx_1 = imageSize1;
            }

            for (b_secondInd = secondDimExtents_idx_0; b_secondInd <=
                 b_secondDimExtents_idx_1; b_secondInd++) {
              for (b_firstInd = 1; b_firstInd <= u1; b_firstInd++) {
                b_pind = ((b_secondInd - 1) * this->ImageSize[0] + b_firstInd) -
                  1;
                for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                  nhInds[imageSize1] = (this->
                                        ImageNeighborLinearOffsets[imageSize1] +
                                        b_pind) + 1;
                }

                pixelSub[0] = this->ImageSize[0];
                if (pixelSub[0] == 0) {
                  lb_loop = 0;
                } else {
                  lb_loop = b_pind - pixelSub[0] * div_s32(b_pind, pixelSub[0]);
                }

                ub_loop = b_pind - lb_loop;
                if (pixelSub[0] == 0) {
                  if (ub_loop == 0) {
                    z = 0;
                  } else if (ub_loop < 0) {
                    z = MIN_int32_T;
                  } else {
                    z = MAX_int32_T;
                  }
                } else if (pixelSub[0] == 1) {
                  z = ub_loop;
                } else if (pixelSub[0] == -1) {
                  z = -ub_loop;
                } else {
                  if (ub_loop >= 0) {
                    x = ub_loop;
                  } else if (ub_loop == MIN_int32_T) {
                    x = MAX_int32_T;
                  } else {
                    x = -ub_loop;
                  }

                  if (pixelSub[0] >= 0) {
                    imageSize1 = pixelSub[0];
                  } else if (pixelSub[0] == MIN_int32_T) {
                    imageSize1 = MAX_int32_T;
                  } else {
                    imageSize1 = -pixelSub[0];
                  }

                  z = div_s32(x, imageSize1);
                  x -= z * imageSize1;
                  if ((x > 0) && (x >= (imageSize1 >> 1) + (imageSize1 & 1))) {
                    z++;
                  }

                  if ((ub_loop < 0) != (pixelSub[0] < 0)) {
                    z = -z;
                  }
                }

                pixelSub[1] = z + 1;
                pixelSub[0] = lb_loop + 1;
                for (lb_loop = 0; lb_loop < 2; lb_loop++) {
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    imageSize1 = ub_loop + 9 * lb_loop;
                    imnhSubs[imageSize1] = this->
                      NeighborSubscriptOffsets[imageSize1] + pixelSub[lb_loop];
                  }
                }

                for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                  isInside[imageSize1] = true;
                }

                switch (static_cast<int>(this->Padding)) {
                 case 1:
                  trueCount = 0;
                  imageSize1 = 0;
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    lb_loop = 0;
                    exitg1 = false;
                    while ((!exitg1) && (lb_loop < 2)) {
                      x = imnhSubs[ub_loop + 9 * lb_loop];
                      if ((x < 1) || (x > this->ImageSize[lb_loop])) {
                        isInside[ub_loop] = false;
                        exitg1 = true;
                      } else {
                        lb_loop++;
                      }
                    }

                    if (isInside[ub_loop]) {
                      trueCount++;
                      b_imnhInds_data[imageSize1] = nhInds[ub_loop];
                      imageSize1++;
                    }
                  }
                  break;

                 case 2:
                  trueCount = 9;
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    b_imnhInds_data[ub_loop] = nhInds[ub_loop];
                    lb_loop = 0;
                    exitg1 = false;
                    while ((!exitg1) && (lb_loop < 2)) {
                      x = imnhSubs[ub_loop + 9 * lb_loop];
                      if ((x < 1) || (x > this->ImageSize[lb_loop])) {
                        isInside[ub_loop] = false;
                        b_imnhInds_data[ub_loop] = 1;
                        exitg1 = true;
                      } else {
                        lb_loop++;
                      }
                    }
                  }
                  break;

                 case 3:
                  trueCount = 9;
                  for (x = 0; x < 9; x++) {
                    b_imnhInds_data[x] = nhInds[x];
                  }

                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    x = imnhSubs[ub_loop];
                    pixelSub[0] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x = 1;
                      pixelSub[0] = 1;
                    }

                    if (x > this->ImageSize[0]) {
                      isInside[ub_loop] = false;
                      pixelSub[0] = this->ImageSize[0];
                    }

                    x = imnhSubs[ub_loop + 9];
                    pixelSub[1] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x = 1;
                      pixelSub[1] = 1;
                    }

                    if (x > this->ImageSize[1]) {
                      isInside[ub_loop] = false;
                      pixelSub[1] = this->ImageSize[1];
                    }

                    if (!isInside[ub_loop]) {
                      b_imnhInds_data[ub_loop] = pixelSub[0] + (pixelSub[1] - 1)
                        * this->ImageSize[0];
                    }
                  }
                  break;

                 case 4:
                  trueCount = 9;
                  for (x = 0; x < 9; x++) {
                    b_imnhInds_data[x] = nhInds[x];
                  }

                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    x = imnhSubs[ub_loop];
                    pixelSub[0] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x += this->ImageSize[0] << 1;
                      pixelSub[0] = x;
                    }

                    if (x > this->ImageSize[0]) {
                      isInside[ub_loop] = false;
                      x = ((this->ImageSize[0] << 1) - x) + 1;
                      pixelSub[0] = x;
                    }

                    x = imnhSubs[ub_loop + 9];
                    pixelSub[1] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x += this->ImageSize[1] << 1;
                      pixelSub[1] = x;
                    }

                    if (x > this->ImageSize[1]) {
                      isInside[ub_loop] = false;
                      x = ((this->ImageSize[1] << 1) - x) + 1;
                      pixelSub[1] = x;
                    }

                    if (!isInside[ub_loop]) {
                      b_imnhInds_data[ub_loop] = pixelSub[0] + (pixelSub[1] - 1)
                        * this->ImageSize[0];
                    }
                  }
                  break;
                }

                for (x = 0; x < trueCount; x++) {
                  imnh_data[x] = in[b_imnhInds_data[x] - 1];
                }

                if (this->Padding == 2.0) {
                  for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                    if (!isInside[imageSize1]) {
                      imnh_data[imageSize1] = padValue;
                    }
                  }
                }

                imageSize1 = trueCount + 1;
                for (x = 0; x < trueCount; x++) {
                  b_imnh_data[x] = imnh_data[x];
                }

                b_imnh_data[trueCount] = 1.0;
                d_imnh_data.set((&b_imnh_data[0]), imageSize1);
                out[b_pind] = (::coder::internal::minimum(d_imnh_data) != 0.0);
              }
            }

            secondDimExtents_idx_1 = this->InteriorStart[0] - 1.0;
            padValue = (this->PadValue != 0.0);
            imageSize1 = this->ImageSize[0];
            if (rtIsNaN(secondDimExtents_idx_1) || (secondDimExtents_idx_1 >
                 imageSize1)) {
              secondDimExtents_idx_0 = imageSize1;
            } else {
              secondDimExtents_idx_0 = static_cast<int>(secondDimExtents_idx_1);
            }

            imageSize1 = this->ImageSize[1];
            u1 = this->ImageSize[1];
            if (imageSize1 < u1) {
              u1 = imageSize1;
            }

            for (b_secondInd = 1; b_secondInd <= u1; b_secondInd++) {
              for (b_firstInd = 0; b_firstInd < secondDimExtents_idx_0;
                   b_firstInd++) {
                b_pind = (b_secondInd - 1) * this->ImageSize[0] + b_firstInd;
                for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                  nhInds[imageSize1] = (this->
                                        ImageNeighborLinearOffsets[imageSize1] +
                                        b_pind) + 1;
                }

                pixelSub[0] = this->ImageSize[0];
                if (pixelSub[0] == 0) {
                  lb_loop = 0;
                } else {
                  lb_loop = b_pind - pixelSub[0] * div_s32(b_pind, pixelSub[0]);
                }

                ub_loop = b_pind - lb_loop;
                if (pixelSub[0] == 0) {
                  if (ub_loop == 0) {
                    z = 0;
                  } else if (ub_loop < 0) {
                    z = MIN_int32_T;
                  } else {
                    z = MAX_int32_T;
                  }
                } else if (pixelSub[0] == 1) {
                  z = ub_loop;
                } else if (pixelSub[0] == -1) {
                  z = -ub_loop;
                } else {
                  if (ub_loop >= 0) {
                    x = ub_loop;
                  } else if (ub_loop == MIN_int32_T) {
                    x = MAX_int32_T;
                  } else {
                    x = -ub_loop;
                  }

                  if (pixelSub[0] >= 0) {
                    imageSize1 = pixelSub[0];
                  } else if (pixelSub[0] == MIN_int32_T) {
                    imageSize1 = MAX_int32_T;
                  } else {
                    imageSize1 = -pixelSub[0];
                  }

                  z = div_s32(x, imageSize1);
                  x -= z * imageSize1;
                  if ((x > 0) && (x >= (imageSize1 >> 1) + (imageSize1 & 1))) {
                    z++;
                  }

                  if ((ub_loop < 0) != (pixelSub[0] < 0)) {
                    z = -z;
                  }
                }

                pixelSub[1] = z + 1;
                pixelSub[0] = lb_loop + 1;
                for (lb_loop = 0; lb_loop < 2; lb_loop++) {
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    imageSize1 = ub_loop + 9 * lb_loop;
                    imnhSubs[imageSize1] = this->
                      NeighborSubscriptOffsets[imageSize1] + pixelSub[lb_loop];
                  }
                }

                for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                  isInside[imageSize1] = true;
                }

                switch (static_cast<int>(this->Padding)) {
                 case 1:
                  b_trueCount = 0;
                  imageSize1 = 0;
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    lb_loop = 0;
                    exitg1 = false;
                    while ((!exitg1) && (lb_loop < 2)) {
                      x = imnhSubs[ub_loop + 9 * lb_loop];
                      if ((x < 1) || (x > this->ImageSize[lb_loop])) {
                        isInside[ub_loop] = false;
                        exitg1 = true;
                      } else {
                        lb_loop++;
                      }
                    }

                    if (isInside[ub_loop]) {
                      b_trueCount++;
                      c_imnhInds_data[imageSize1] = nhInds[ub_loop];
                      imageSize1++;
                    }
                  }
                  break;

                 case 2:
                  b_trueCount = 9;
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    c_imnhInds_data[ub_loop] = nhInds[ub_loop];
                    lb_loop = 0;
                    exitg1 = false;
                    while ((!exitg1) && (lb_loop < 2)) {
                      x = imnhSubs[ub_loop + 9 * lb_loop];
                      if ((x < 1) || (x > this->ImageSize[lb_loop])) {
                        isInside[ub_loop] = false;
                        c_imnhInds_data[ub_loop] = 1;
                        exitg1 = true;
                      } else {
                        lb_loop++;
                      }
                    }
                  }
                  break;

                 case 3:
                  b_trueCount = 9;
                  for (x = 0; x < 9; x++) {
                    c_imnhInds_data[x] = nhInds[x];
                  }

                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    x = imnhSubs[ub_loop];
                    pixelSub[0] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x = 1;
                      pixelSub[0] = 1;
                    }

                    if (x > this->ImageSize[0]) {
                      isInside[ub_loop] = false;
                      pixelSub[0] = this->ImageSize[0];
                    }

                    x = imnhSubs[ub_loop + 9];
                    pixelSub[1] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x = 1;
                      pixelSub[1] = 1;
                    }

                    if (x > this->ImageSize[1]) {
                      isInside[ub_loop] = false;
                      pixelSub[1] = this->ImageSize[1];
                    }

                    if (!isInside[ub_loop]) {
                      c_imnhInds_data[ub_loop] = pixelSub[0] + (pixelSub[1] - 1)
                        * this->ImageSize[0];
                    }
                  }
                  break;

                 case 4:
                  b_trueCount = 9;
                  for (x = 0; x < 9; x++) {
                    c_imnhInds_data[x] = nhInds[x];
                  }

                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    x = imnhSubs[ub_loop];
                    pixelSub[0] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x += this->ImageSize[0] << 1;
                      pixelSub[0] = x;
                    }

                    if (x > this->ImageSize[0]) {
                      isInside[ub_loop] = false;
                      x = ((this->ImageSize[0] << 1) - x) + 1;
                      pixelSub[0] = x;
                    }

                    x = imnhSubs[ub_loop + 9];
                    pixelSub[1] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x += this->ImageSize[1] << 1;
                      pixelSub[1] = x;
                    }

                    if (x > this->ImageSize[1]) {
                      isInside[ub_loop] = false;
                      x = ((this->ImageSize[1] << 1) - x) + 1;
                      pixelSub[1] = x;
                    }

                    if (!isInside[ub_loop]) {
                      c_imnhInds_data[ub_loop] = pixelSub[0] + (pixelSub[1] - 1)
                        * this->ImageSize[0];
                    }
                  }
                  break;
                }

                for (x = 0; x < b_trueCount; x++) {
                  imnh_data[x] = in[c_imnhInds_data[x] - 1];
                }

                if (this->Padding == 2.0) {
                  for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                    if (!isInside[imageSize1]) {
                      imnh_data[imageSize1] = padValue;
                    }
                  }
                }

                imageSize1 = b_trueCount + 1;
                for (x = 0; x < b_trueCount; x++) {
                  b_imnh_data[x] = imnh_data[x];
                }

                b_imnh_data[b_trueCount] = 1.0;
                e_imnh_data.set((&b_imnh_data[0]), imageSize1);
                out[b_pind] = (::coder::internal::minimum(e_imnh_data) != 0.0);
              }
            }

            secondDimExtents_idx_0 = this->InteriorEnd[0] + 1;
            b_secondDimExtents_idx_1 = this->ImageSize[0];
            padValue = (this->PadValue != 0.0);
            if (secondDimExtents_idx_0 < 1) {
              secondDimExtents_idx_0 = 1;
            }

            imageSize1 = this->ImageSize[0];
            if (b_secondDimExtents_idx_1 >= imageSize1) {
              b_secondDimExtents_idx_1 = imageSize1;
            }

            for (b_secondInd = 1; b_secondInd <= u1; b_secondInd++) {
              for (b_firstInd = secondDimExtents_idx_0; b_firstInd <=
                   b_secondDimExtents_idx_1; b_firstInd++) {
                b_pind = ((b_secondInd - 1) * this->ImageSize[0] + b_firstInd) -
                  1;
                for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                  nhInds[imageSize1] = (this->
                                        ImageNeighborLinearOffsets[imageSize1] +
                                        b_pind) + 1;
                }

                pixelSub[0] = this->ImageSize[0];
                if (pixelSub[0] == 0) {
                  lb_loop = 0;
                } else {
                  lb_loop = b_pind - pixelSub[0] * div_s32(b_pind, pixelSub[0]);
                }

                ub_loop = b_pind - lb_loop;
                if (pixelSub[0] == 0) {
                  if (ub_loop == 0) {
                    z = 0;
                  } else if (ub_loop < 0) {
                    z = MIN_int32_T;
                  } else {
                    z = MAX_int32_T;
                  }
                } else if (pixelSub[0] == 1) {
                  z = ub_loop;
                } else if (pixelSub[0] == -1) {
                  z = -ub_loop;
                } else {
                  if (ub_loop >= 0) {
                    x = ub_loop;
                  } else if (ub_loop == MIN_int32_T) {
                    x = MAX_int32_T;
                  } else {
                    x = -ub_loop;
                  }

                  if (pixelSub[0] >= 0) {
                    imageSize1 = pixelSub[0];
                  } else if (pixelSub[0] == MIN_int32_T) {
                    imageSize1 = MAX_int32_T;
                  } else {
                    imageSize1 = -pixelSub[0];
                  }

                  z = div_s32(x, imageSize1);
                  x -= z * imageSize1;
                  if ((x > 0) && (x >= (imageSize1 >> 1) + (imageSize1 & 1))) {
                    z++;
                  }

                  if ((ub_loop < 0) != (pixelSub[0] < 0)) {
                    z = -z;
                  }
                }

                pixelSub[1] = z + 1;
                pixelSub[0] = lb_loop + 1;
                for (lb_loop = 0; lb_loop < 2; lb_loop++) {
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    imageSize1 = ub_loop + 9 * lb_loop;
                    imnhSubs[imageSize1] = this->
                      NeighborSubscriptOffsets[imageSize1] + pixelSub[lb_loop];
                  }
                }

                for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                  isInside[imageSize1] = true;
                }

                switch (static_cast<int>(this->Padding)) {
                 case 1:
                  c_trueCount = 0;
                  imageSize1 = 0;
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    lb_loop = 0;
                    exitg1 = false;
                    while ((!exitg1) && (lb_loop < 2)) {
                      x = imnhSubs[ub_loop + 9 * lb_loop];
                      if ((x < 1) || (x > this->ImageSize[lb_loop])) {
                        isInside[ub_loop] = false;
                        exitg1 = true;
                      } else {
                        lb_loop++;
                      }
                    }

                    if (isInside[ub_loop]) {
                      c_trueCount++;
                      d_imnhInds_data[imageSize1] = nhInds[ub_loop];
                      imageSize1++;
                    }
                  }
                  break;

                 case 2:
                  c_trueCount = 9;
                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    d_imnhInds_data[ub_loop] = nhInds[ub_loop];
                    lb_loop = 0;
                    exitg1 = false;
                    while ((!exitg1) && (lb_loop < 2)) {
                      x = imnhSubs[ub_loop + 9 * lb_loop];
                      if ((x < 1) || (x > this->ImageSize[lb_loop])) {
                        isInside[ub_loop] = false;
                        d_imnhInds_data[ub_loop] = 1;
                        exitg1 = true;
                      } else {
                        lb_loop++;
                      }
                    }
                  }
                  break;

                 case 3:
                  c_trueCount = 9;
                  for (x = 0; x < 9; x++) {
                    d_imnhInds_data[x] = nhInds[x];
                  }

                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    x = imnhSubs[ub_loop];
                    pixelSub[0] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x = 1;
                      pixelSub[0] = 1;
                    }

                    if (x > this->ImageSize[0]) {
                      isInside[ub_loop] = false;
                      pixelSub[0] = this->ImageSize[0];
                    }

                    x = imnhSubs[ub_loop + 9];
                    pixelSub[1] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x = 1;
                      pixelSub[1] = 1;
                    }

                    if (x > this->ImageSize[1]) {
                      isInside[ub_loop] = false;
                      pixelSub[1] = this->ImageSize[1];
                    }

                    if (!isInside[ub_loop]) {
                      d_imnhInds_data[ub_loop] = pixelSub[0] + (pixelSub[1] - 1)
                        * this->ImageSize[0];
                    }
                  }
                  break;

                 case 4:
                  c_trueCount = 9;
                  for (x = 0; x < 9; x++) {
                    d_imnhInds_data[x] = nhInds[x];
                  }

                  for (ub_loop = 0; ub_loop < 9; ub_loop++) {
                    x = imnhSubs[ub_loop];
                    pixelSub[0] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x += this->ImageSize[0] << 1;
                      pixelSub[0] = x;
                    }

                    if (x > this->ImageSize[0]) {
                      isInside[ub_loop] = false;
                      x = ((this->ImageSize[0] << 1) - x) + 1;
                      pixelSub[0] = x;
                    }

                    x = imnhSubs[ub_loop + 9];
                    pixelSub[1] = x;
                    if (x < 1) {
                      isInside[ub_loop] = false;
                      x += this->ImageSize[1] << 1;
                      pixelSub[1] = x;
                    }

                    if (x > this->ImageSize[1]) {
                      isInside[ub_loop] = false;
                      x = ((this->ImageSize[1] << 1) - x) + 1;
                      pixelSub[1] = x;
                    }

                    if (!isInside[ub_loop]) {
                      d_imnhInds_data[ub_loop] = pixelSub[0] + (pixelSub[1] - 1)
                        * this->ImageSize[0];
                    }
                  }
                  break;
                }

                for (x = 0; x < c_trueCount; x++) {
                  imnh_data[x] = in[d_imnhInds_data[x] - 1];
                }

                if (this->Padding == 2.0) {
                  for (imageSize1 = 0; imageSize1 < 9; imageSize1++) {
                    if (!isInside[imageSize1]) {
                      imnh_data[imageSize1] = padValue;
                    }
                  }
                }

                imageSize1 = c_trueCount + 1;
                for (x = 0; x < c_trueCount; x++) {
                  b_imnh_data[x] = imnh_data[x];
                }

                b_imnh_data[c_trueCount] = 1.0;
                f_imnh_data.set((&b_imnh_data[0]), imageSize1);
                out[b_pind] = (::coder::internal::minimum(f_imnh_data) != 0.0);
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
