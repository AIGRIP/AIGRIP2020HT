//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 03-Dec-2020 08:29:52
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
          static void b_computeParameters(const int imSize[2], const bool
            nhConn[9], int loffsets[9], int linds[9], int soffsets[18], double
            interiorStart[2], int interiorEnd[2]);
          void process2D(const bool in[728160], bool out[728160]) const;
          bool Neighborhood[9];
          int ImageSize[2];
          double InteriorStart[2];
          int InteriorEnd[2];
          int ImageNeighborLinearOffsets[9];
          double Padding;
          double PadValue;
          bool ProcessBorder;
          double NeighborhoodCenter;
          int NeighborLinearIndices[9];
          int NeighborSubscriptOffsets[18];
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
