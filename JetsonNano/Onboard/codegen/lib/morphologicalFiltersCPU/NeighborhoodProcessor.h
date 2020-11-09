//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 05-Nov-2020 08:33:11
//
#ifndef NEIGHBORHOODPROCESSOR_H
#define NEIGHBORHOODPROCESSOR_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder
{
  namespace images
  {
    namespace internal
    {
      namespace coder
      {
        class NeighborhoodProcessor
        {
         public:
          static void computeParameters(const int imSize[2], const bool nhConn[9],
            int loffsets[5], int linds[5], int soffsets[10], double
            interiorStart[2], int interiorEnd[2]);
          bool Neighborhood[9];
          int ImageSize[2];
          int ImageNeighborLinearOffsets[5];
          double Padding;
          double NeighborhoodCenter;
         private:
          int NeighborLinearIndices[5];
          int NeighborSubscriptOffsets[10];
        };
      }
    }
  }
}

#endif

//
// File trailer for NeighborhoodProcessor.h
//
// [EOF]
//
