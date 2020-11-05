//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imreconstruct.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 05-Nov-2020 08:33:11
//

// Include Files
#include "imreconstruct.h"
#include "NeighborhoodProcessor.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : unsigned char marker[731612]
//                const unsigned char mask[731612]
// Return Type  : void
//
namespace coder
{
  void imreconstruct(unsigned char marker[731612], const unsigned char mask
                     [731612])
  {
    static int locationStack[1463224];
    static const bool nhConn[9] = { false, true, false, true, true, true, false,
      true, false };

    double dv[2];
    int imnhSubs[10];
    int iv2[10];
    int imnhInds_[5];
    int imnhInds_data[5];
    int iv[5];
    int iv1[2];
    int pixelSub[2];
    int marker_size[1];
    int b_x;
    int i;
    int ind;
    int pInd;
    int stackTop;
    int x;
    int z;
    unsigned char marker_data[5];
    unsigned char u;
    unsigned char u0;
    bool isInside[5];
    bool exitg1;
    for (i = 0; i < 731612; i++) {
      u = mask[i];
      if (marker[i] > u) {
        marker[i] = u;
      }
    }

    for (i = 0; i < 5; i++) {
      iv[i] = 0;
      imnhInds_[i] = 0;
    }

    for (z = 0; z < 10; z++) {
      iv2[z] = 0;
    }

    iv1[0] = 986;
    iv1[1] = 742;
    images::internal::coder::NeighborhoodProcessor::computeParameters((iv1),
      (nhConn), (iv), (imnhInds_), (iv2), (dv), (pixelSub));
    for (pInd = 0; pInd < 731612; pInd++) {
      for (i = 0; i < 5; i++) {
        imnhInds_[i] = (iv[i] + pInd) + 1;
      }

      i = pInd - 986 * (pInd / 986);
      x = pInd - i;
      if (x >= 0) {
        b_x = x;
      } else {
        b_x = -x;
      }

      z = b_x / 986;
      b_x -= z * 986;
      if ((b_x > 0) && (b_x >= 493)) {
        z++;
      }

      if (x < 0) {
        z = -z;
      }

      pixelSub[1] = z + 1;
      pixelSub[0] = i + 1;
      for (x = 0; x < 2; x++) {
        for (b_x = 0; b_x < 5; b_x++) {
          i = b_x + 5 * x;
          imnhSubs[i] = iv2[i] + pixelSub[x];
        }
      }

      i = 0;
      x = 0;
      for (ind = 0; ind < 5; ind++) {
        isInside[ind] = true;
        b_x = 0;
        exitg1 = false;
        while ((!exitg1) && (b_x < 2)) {
          z = imnhSubs[ind + 5 * b_x];
          if ((z < 1) || (z > -244 * b_x + 986)) {
            isInside[ind] = false;
            exitg1 = true;
          } else {
            b_x++;
          }
        }

        if (isInside[ind]) {
          i++;
          imnhInds_data[x] = imnhInds_[ind];
          x++;
        }
      }

      marker_size[0] = i;
      for (z = 0; z < i; z++) {
        marker_data[z] = marker[imnhInds_data[z] - 1];
      }

      u0 = internal::maximum(marker_data, marker_size);
      u = mask[pInd];
      if (u0 < u) {
        marker[pInd] = u0;
      } else {
        marker[pInd] = u;
      }
    }

    stackTop = -1;
    for (pInd = 731611; pInd >= 0; pInd--) {
      for (i = 0; i < 5; i++) {
        imnhInds_[i] = (iv[i] + pInd) + 1;
      }

      i = pInd - 986 * (pInd / 986);
      x = pInd - i;
      if (x >= 0) {
        b_x = x;
      } else {
        b_x = -x;
      }

      z = b_x / 986;
      b_x -= z * 986;
      if ((b_x > 0) && (b_x >= 493)) {
        z++;
      }

      if (x < 0) {
        z = -z;
      }

      pixelSub[1] = z + 1;
      pixelSub[0] = i + 1;
      for (x = 0; x < 2; x++) {
        for (b_x = 0; b_x < 5; b_x++) {
          i = b_x + 5 * x;
          imnhSubs[i] = iv2[i] + pixelSub[x];
        }
      }

      i = 0;
      x = 0;
      for (ind = 0; ind < 5; ind++) {
        isInside[ind] = true;
        b_x = 0;
        exitg1 = false;
        while ((!exitg1) && (b_x < 2)) {
          z = imnhSubs[ind + 5 * b_x];
          if ((z < 1) || (z > -244 * b_x + 986)) {
            isInside[ind] = false;
            exitg1 = true;
          } else {
            b_x++;
          }
        }

        if (isInside[ind]) {
          i++;
          imnhInds_data[x] = imnhInds_[ind];
          x++;
        }
      }

      marker_size[0] = i;
      for (z = 0; z < i; z++) {
        marker_data[z] = marker[imnhInds_data[z] - 1];
      }

      u0 = internal::maximum(marker_data, marker_size);
      u = mask[pInd];
      if (u0 < u) {
        marker[pInd] = u0;
      } else {
        marker[pInd] = u;
      }

      ind = 0;
      exitg1 = false;
      while ((!exitg1) && (ind <= i - 1)) {
        z = marker[imnhInds_data[ind] - 1];
        if ((z < marker[pInd]) && (z < mask[imnhInds_data[ind] - 1])) {
          stackTop++;
          locationStack[stackTop] = pInd + 1;
          exitg1 = true;
        } else {
          ind++;
        }
      }
    }

    while (stackTop + 1 > 0) {
      pInd = locationStack[stackTop] - 1;
      stackTop--;
      for (i = 0; i < 5; i++) {
        imnhInds_[i] = (iv[i] + pInd) + 1;
      }

      i = pInd - 986 * (pInd / 986);
      x = pInd - i;
      if (x >= 0) {
        b_x = x;
      } else if (x == MIN_int32_T) {
        b_x = MAX_int32_T;
      } else {
        b_x = -x;
      }

      z = b_x / 986;
      b_x -= z * 986;
      if ((b_x > 0) && (b_x >= 493)) {
        z++;
      }

      if (x < 0) {
        z = -z;
      }

      pixelSub[1] = z + 1;
      pixelSub[0] = i + 1;
      for (x = 0; x < 2; x++) {
        for (b_x = 0; b_x < 5; b_x++) {
          i = b_x + 5 * x;
          imnhSubs[i] = iv2[i] + pixelSub[x];
        }
      }

      i = 0;
      x = 0;
      for (ind = 0; ind < 5; ind++) {
        isInside[ind] = true;
        b_x = 0;
        exitg1 = false;
        while ((!exitg1) && (b_x < 2)) {
          z = imnhSubs[ind + 5 * b_x];
          if ((z < 1) || (z > -244 * b_x + 986)) {
            isInside[ind] = false;
            exitg1 = true;
          } else {
            b_x++;
          }
        }

        if (isInside[ind]) {
          i++;
          imnhInds_data[x] = imnhInds_[ind];
          x++;
        }
      }

      for (ind = 0; ind < i; ind++) {
        if (marker[imnhInds_data[ind] - 1] < marker[pInd]) {
          u = mask[imnhInds_data[ind] - 1];
          if (marker[imnhInds_data[ind] - 1] != u) {
            if (marker[pInd] < u) {
              marker[imnhInds_data[ind] - 1] = marker[pInd];
            } else {
              marker[imnhInds_data[ind] - 1] = u;
            }

            stackTop++;
            locationStack[stackTop] = imnhInds_data[ind];
          }
        }
      }
    }
  }
}

//
// File trailer for imreconstruct.cpp
//
// [EOF]
//
