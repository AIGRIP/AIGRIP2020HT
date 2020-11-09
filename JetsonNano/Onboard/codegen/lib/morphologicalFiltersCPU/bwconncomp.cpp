//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwconncomp.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 05-Nov-2020 08:33:11
//

// Include Files
#include "bwconncomp.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const bool varargin_1[728160]
//                double *CC_Connectivity
//                double CC_ImageSize[2]
//                double *CC_NumObjects
//                ::coder::array<double, 1U> &CC_RegionIndices
//                ::coder::array<int, 1U> &CC_RegionLengths
// Return Type  : void
//
namespace coder
{
  void bwconncomp(const bool varargin_1[728160], double *CC_Connectivity, double
                  CC_ImageSize[2], double *CC_NumObjects, ::coder::array<double,
                  1U> &CC_RegionIndices, ::coder::array<int, 1U>
                  &CC_RegionLengths)
  {
    array<int, 1U> idxCount;
    array<int, 1U> labelsRenumbered;
    array<int, 1U> pixelIdxList;
    array<int, 1U> x;
    array<short, 1U> endRow;
    array<short, 1U> startCol;
    array<short, 1U> startRow;
    double numComponents;
    double y;
    int firstRunOnPreviousColumn;
    int firstRunOnThisColumn;
    int k;
    int numRuns;
    numRuns = 0;
    for (firstRunOnPreviousColumn = 0; firstRunOnPreviousColumn < 740;
         firstRunOnPreviousColumn++) {
      if (varargin_1[984 * firstRunOnPreviousColumn]) {
        numRuns++;
      }

      for (k = 0; k < 983; k++) {
        firstRunOnThisColumn = k + 984 * firstRunOnPreviousColumn;
        if (varargin_1[firstRunOnThisColumn + 1] &&
            (!varargin_1[firstRunOnThisColumn])) {
          numRuns++;
        }
      }
    }

    if (numRuns == 0) {
      CC_ImageSize[0] = 984.0;
      CC_ImageSize[1] = 740.0;
      numComponents = 0.0;
      CC_RegionIndices.set_size(0);
      CC_RegionLengths.set_size(1);
      CC_RegionLengths[0] = 0;
    } else {
      int lastRunOnPreviousColumn;
      int row;
      int runCounter;
      startRow.set_size(numRuns);
      endRow.set_size(numRuns);
      startCol.set_size(numRuns);
      runCounter = 0;
      for (firstRunOnPreviousColumn = 0; firstRunOnPreviousColumn < 740;
           firstRunOnPreviousColumn++) {
        row = 1;
        while (row <= 984) {
          while ((row <= 984) && (!varargin_1[(row + 984 *
                   firstRunOnPreviousColumn) - 1])) {
            row++;
          }

          if ((row <= 984) && varargin_1[(row + 984 * firstRunOnPreviousColumn)
              - 1]) {
            startCol[runCounter] = static_cast<short>(firstRunOnPreviousColumn +
              1);
            startRow[runCounter] = static_cast<short>(row);
            while ((row <= 984) && varargin_1[(row + 984 *
                    firstRunOnPreviousColumn) - 1]) {
              row++;
            }

            endRow[runCounter] = static_cast<short>(row - 1);
            runCounter++;
          }
        }
      }

      CC_RegionLengths.set_size(numRuns);
      for (firstRunOnThisColumn = 0; firstRunOnThisColumn < numRuns;
           firstRunOnThisColumn++) {
        CC_RegionLengths[firstRunOnThisColumn] = 0;
      }

      k = 0;
      runCounter = 1;
      row = 1;
      firstRunOnPreviousColumn = -1;
      lastRunOnPreviousColumn = -1;
      firstRunOnThisColumn = 0;
      while (k + 1 <= numRuns) {
        if (startCol[k] == runCounter + 1) {
          firstRunOnPreviousColumn = firstRunOnThisColumn + 1;
          firstRunOnThisColumn = k;
          lastRunOnPreviousColumn = k;
          runCounter = startCol[k];
        } else {
          if (startCol[k] > runCounter + 1) {
            firstRunOnPreviousColumn = -1;
            lastRunOnPreviousColumn = -1;
            firstRunOnThisColumn = k;
            runCounter = startCol[k];
          }
        }

        if (firstRunOnPreviousColumn >= 0) {
          for (int p = firstRunOnPreviousColumn - 1; p < lastRunOnPreviousColumn;
               p++) {
            if ((endRow[k] >= startRow[p] - 1) && (startRow[k] <= endRow[p] + 1))
            {
              if (CC_RegionLengths[k] == 0) {
                CC_RegionLengths[k] = CC_RegionLengths[p];
                row++;
              } else {
                if (CC_RegionLengths[k] != CC_RegionLengths[p]) {
                  int root_k;
                  int root_p;
                  for (root_k = k; root_k + 1 != CC_RegionLengths[root_k];
                       root_k = CC_RegionLengths[root_k] - 1) {
                    CC_RegionLengths[root_k] =
                      CC_RegionLengths[CC_RegionLengths[root_k] - 1];
                  }

                  for (root_p = p; root_p + 1 != CC_RegionLengths[root_p];
                       root_p = CC_RegionLengths[root_p] - 1) {
                    CC_RegionLengths[root_p] =
                      CC_RegionLengths[CC_RegionLengths[root_p] - 1];
                  }

                  if (root_k + 1 != root_p + 1) {
                    if (root_p + 1 < root_k + 1) {
                      CC_RegionLengths[root_k] = root_p + 1;
                      CC_RegionLengths[k] = root_p + 1;
                    } else {
                      CC_RegionLengths[root_p] = root_k + 1;
                      CC_RegionLengths[p] = root_k + 1;
                    }
                  }
                }
              }
            }
          }
        }

        if (CC_RegionLengths[k] == 0) {
          CC_RegionLengths[k] = row;
          row++;
        }

        k++;
      }

      labelsRenumbered.set_size(CC_RegionLengths.size(0));
      numComponents = 0.0;
      for (k = 0; k < numRuns; k++) {
        if (CC_RegionLengths[k] == k + 1) {
          numComponents++;
          labelsRenumbered[k] = static_cast<int>(numComponents);
        }

        labelsRenumbered[k] = labelsRenumbered[CC_RegionLengths[k] - 1];
      }

      CC_RegionLengths.set_size((static_cast<int>(numComponents)));
      runCounter = static_cast<int>(numComponents);
      for (firstRunOnThisColumn = 0; firstRunOnThisColumn < runCounter;
           firstRunOnThisColumn++) {
        CC_RegionLengths[firstRunOnThisColumn] = 0;
      }

      for (k = 0; k < numRuns; k++) {
        CC_RegionLengths[labelsRenumbered[k] - 1] =
          ((CC_RegionLengths[labelsRenumbered[k] - 1] + endRow[k]) - startRow[k])
          + 1;
      }

      runCounter = CC_RegionLengths.size(0);
      if (CC_RegionLengths.size(0) == 0) {
        y = 0.0;
      } else {
        y = CC_RegionLengths[0];
        for (k = 2; k <= runCounter; k++) {
          y += static_cast<double>(CC_RegionLengths[k - 1]);
        }
      }

      pixelIdxList.set_size((static_cast<int>(y)));
      x.set_size(CC_RegionLengths.size(0));
      runCounter = CC_RegionLengths.size(0);
      for (firstRunOnThisColumn = 0; firstRunOnThisColumn < runCounter;
           firstRunOnThisColumn++) {
        x[firstRunOnThisColumn] = CC_RegionLengths[firstRunOnThisColumn];
      }

      if ((CC_RegionLengths.size(0) != 1) && (CC_RegionLengths.size(0) != 0) &&
          (CC_RegionLengths.size(0) != 1)) {
        firstRunOnThisColumn = CC_RegionLengths.size(0);
        for (k = 0; k <= firstRunOnThisColumn - 2; k++) {
          x[k + 1] = x[k] + x[k + 1];
        }
      }

      idxCount.set_size((x.size(0) + 1));
      idxCount[0] = 0;
      runCounter = x.size(0);
      for (firstRunOnThisColumn = 0; firstRunOnThisColumn < runCounter;
           firstRunOnThisColumn++) {
        idxCount[firstRunOnThisColumn + 1] = x[firstRunOnThisColumn];
      }

      for (k = 0; k < numRuns; k++) {
        runCounter = (startCol[k] - 1) * 984;
        row = labelsRenumbered[k] - 1;
        firstRunOnThisColumn = startRow[k];
        firstRunOnPreviousColumn = endRow[k];
        for (lastRunOnPreviousColumn = firstRunOnThisColumn;
             lastRunOnPreviousColumn <= firstRunOnPreviousColumn;
             lastRunOnPreviousColumn++) {
          idxCount[row] = idxCount[row] + 1;
          pixelIdxList[idxCount[row] - 1] = lastRunOnPreviousColumn + runCounter;
        }
      }

      CC_ImageSize[0] = 984.0;
      CC_ImageSize[1] = 740.0;
      CC_RegionIndices.set_size(pixelIdxList.size(0));
      runCounter = pixelIdxList.size(0);
      for (firstRunOnThisColumn = 0; firstRunOnThisColumn < runCounter;
           firstRunOnThisColumn++) {
        CC_RegionIndices[firstRunOnThisColumn] =
          pixelIdxList[firstRunOnThisColumn];
      }
    }

    *CC_Connectivity = 8.0;
    *CC_NumObjects = numComponents;
  }
}

//
// File trailer for bwconncomp.cpp
//
// [EOF]
//
