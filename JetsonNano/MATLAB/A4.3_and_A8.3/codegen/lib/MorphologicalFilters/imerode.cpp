//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imerode.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 02-Dec-2020 13:31:29
//

// Include Files
#include "imerode.h"
#include "NeighborhoodProcessor.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const bool A[728160]
//                bool B[728160]
// Return Type  : void
//
namespace coder
{
  void imerode(const bool A[728160], bool B[728160])
  {
    images::internal::coder::NeighborhoodProcessor np;
    int iv[2];
    int i;
    bool bv[9];
    np.ImageSize[0] = 984;
    np.ImageSize[1] = 740;
    np.Padding = 1.0;
    np.ProcessBorder = true;
    np.NeighborhoodCenter = 2.0;
    np.PadValue = 0.0;
    for (i = 0; i < 9; i++) {
      np.Neighborhood[i] = true;
      np.ImageNeighborLinearOffsets[i] = 0;
      np.NeighborLinearIndices[i] = 0;
    }

    std::memset(&np.NeighborSubscriptOffsets[0], 0, 18U * sizeof(int));
    iv[0] = 984;
    iv[1] = 740;
    for (i = 0; i < 9; i++) {
      bv[i] = true;
    }

    images::internal::coder::NeighborhoodProcessor::b_computeParameters((iv),
      (bv), (np.ImageNeighborLinearOffsets), (np.NeighborLinearIndices),
      (np.NeighborSubscriptOffsets), (np.InteriorStart), (np.InteriorEnd));
    np.process2D(A, B);
  }
}

//
// File trailer for imerode.cpp
//
// [EOF]
//
