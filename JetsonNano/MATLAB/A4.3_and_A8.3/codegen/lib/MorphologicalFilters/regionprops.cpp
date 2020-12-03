//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: regionprops.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 02-Dec-2020 13:31:29
//

// Include Files
#include "regionprops.h"
#include "MorphologicalFilters_internal_types.h"
#include "bwconncomp.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Type Definitions
struct b_struct_T
{
  double Area;
  double Centroid[2];
  double BoundingBox[4];
  double MajorAxisLength;
  double MinorAxisLength;
  double Eccentricity;
  double Orientation;
  coder::array<bool, 2U> Image;
  coder::array<bool, 2U> FilledImage;
  double FilledArea;
  double EulerNumber;
  double Extrema[16];
  double EquivDiameter;
  double Extent;
  coder::array<double, 1U> PixelIdxList;
  coder::array<double, 2U> PixelList;
  double Perimeter;
  double Circularity;
  coder::array<double, 1U> PixelValues;
  double WeightedCentroid[2];
  double MeanIntensity;
  double MinIntensity;
  double MaxIntensity;
  coder::array<double, 2U> SubarrayIdx;
  double SubarrayIdxLengths[2];
};

// Function Definitions
//
// Arguments    : const bool varargin_1[728160]
//                ::coder::array<struct_T, 1U> &outstats
// Return Type  : void
//
namespace coder
{
  void regionprops(const bool varargin_1[728160], ::coder::array<struct_T, 1U>
                   &outstats)
  {
    array<b_struct_T, 1U> stats;
    array<double, 1U> CC_RegionIndices;
    array<int, 1U> idxCount;
    array<int, 1U> regionLengths;
    b_struct_T b_statsOneObj;
    struct_T statsOneObj;
    double b_expl_temp[2];
    double CC_NumObjects;
    double expl_temp;
    int b_k;
    int i;
    int i1;
    int k;
    int xpageoffset;
    bwconncomp(varargin_1, &expl_temp, b_expl_temp, &CC_NumObjects,
               CC_RegionIndices, regionLengths);
    statsOneObj.Area = 0.0;
    statsOneObj.Centroid[0] = 0.0;
    statsOneObj.Centroid[1] = 0.0;
    statsOneObj.PixelIdxList.set_size(0);
    outstats.set_size((static_cast<int>(CC_NumObjects)));
    xpageoffset = static_cast<int>(CC_NumObjects);
    for (i = 0; i < xpageoffset; i++) {
      outstats[i] = statsOneObj;
    }

    b_statsOneObj.Area = 0.0;
    b_statsOneObj.Centroid[0] = 0.0;
    b_statsOneObj.Centroid[1] = 0.0;
    b_statsOneObj.BoundingBox[0] = 0.0;
    b_statsOneObj.BoundingBox[1] = 0.0;
    b_statsOneObj.BoundingBox[2] = 0.0;
    b_statsOneObj.BoundingBox[3] = 0.0;
    b_statsOneObj.MajorAxisLength = 0.0;
    b_statsOneObj.MinorAxisLength = 0.0;
    b_statsOneObj.Eccentricity = 0.0;
    b_statsOneObj.Orientation = 0.0;
    b_statsOneObj.Image.set_size(0, 0);
    b_statsOneObj.FilledImage.set_size(0, 0);
    b_statsOneObj.FilledArea = 0.0;
    b_statsOneObj.EulerNumber = 0.0;
    std::memset(&b_statsOneObj.Extrema[0], 0, 16U * sizeof(double));
    b_statsOneObj.EquivDiameter = 0.0;
    b_statsOneObj.Extent = 0.0;
    b_statsOneObj.PixelIdxList.set_size(0);
    b_statsOneObj.PixelList.set_size(0, 2);
    b_statsOneObj.Perimeter = 0.0;
    b_statsOneObj.Circularity = 0.0;
    b_statsOneObj.PixelValues.set_size(0);
    b_statsOneObj.MeanIntensity = 0.0;
    b_statsOneObj.MinIntensity = 0.0;
    b_statsOneObj.MaxIntensity = 0.0;
    b_statsOneObj.SubarrayIdx.set_size(1, 0);
    b_statsOneObj.WeightedCentroid[0] = 0.0;
    b_statsOneObj.SubarrayIdxLengths[0] = 0.0;
    b_statsOneObj.WeightedCentroid[1] = 0.0;
    b_statsOneObj.SubarrayIdxLengths[1] = 0.0;
    stats.set_size((static_cast<int>(CC_NumObjects)));
    xpageoffset = static_cast<int>(CC_NumObjects);
    for (i = 0; i < xpageoffset; i++) {
      stats[i] = b_statsOneObj;
    }

    if (CC_NumObjects != 0.0) {
      if ((regionLengths.size(0) != 1) && (regionLengths.size(0) != 0) &&
          (regionLengths.size(0) != 1)) {
        i = regionLengths.size(0);
        for (k = 0; k <= i - 2; k++) {
          regionLengths[k + 1] = regionLengths[k] + regionLengths[k + 1];
        }
      }

      idxCount.set_size((regionLengths.size(0) + 1));
      idxCount[0] = 0;
      xpageoffset = regionLengths.size(0);
      for (i = 0; i < xpageoffset; i++) {
        idxCount[i + 1] = regionLengths[i];
      }

      i = static_cast<int>(CC_NumObjects);
      for (k = 0; k < i; k++) {
        i1 = idxCount[k + 1];
        if (idxCount[k] + 1 > i1) {
          b_k = 0;
          i1 = 0;
        } else {
          b_k = idxCount[k];
        }

        xpageoffset = i1 - b_k;
        stats[k].PixelIdxList.set_size(xpageoffset);
        for (i1 = 0; i1 < xpageoffset; i1++) {
          stats[k].PixelIdxList[i1] = CC_RegionIndices[b_k + i1];
        }
      }
    }

    i = stats.size(0);
    for (k = 0; k < i; k++) {
      stats[k].Area = stats[k].PixelIdxList.size(0);
    }

    i = stats.size(0);
    for (k = 0; k < i; k++) {
      xpageoffset = stats[k].PixelIdxList.size(0);
      if (stats[k].PixelIdxList.size(0) != 0) {
        regionLengths.set_size(stats[k].PixelIdxList.size(0));
        for (i1 = 0; i1 < xpageoffset; i1++) {
          regionLengths[i1] = static_cast<int>(stats[k].PixelIdxList[i1]) - 1;
        }

        idxCount.set_size(regionLengths.size(0));
        xpageoffset = regionLengths.size(0);
        for (i1 = 0; i1 < xpageoffset; i1++) {
          idxCount[i1] = regionLengths[i1] / 984;
        }

        xpageoffset = regionLengths.size(0);
        for (i1 = 0; i1 < xpageoffset; i1++) {
          regionLengths[i1] = regionLengths[i1] - idxCount[i1] * 984;
        }

        stats[k].PixelList.set_size(idxCount.size(0), 2);
        xpageoffset = idxCount.size(0);
        for (i1 = 0; i1 < xpageoffset; i1++) {
          stats[k].PixelList[i1] = idxCount[i1] + 1;
        }

        xpageoffset = regionLengths.size(0);
        for (i1 = 0; i1 < xpageoffset; i1++) {
          stats[k].PixelList[i1 + stats[k].PixelList.size(0)] = regionLengths[i1]
            + 1;
        }
      } else {
        stats[k].PixelList.set_size(0, 2);
      }
    }

    i = stats.size(0);
    for (k = 0; k < i; k++) {
      i1 = stats[k].PixelList.size(0);
      if (stats[k].PixelList.size(0) == 0) {
        b_expl_temp[0] = 0.0;
        b_expl_temp[1] = 0.0;
      } else {
        b_expl_temp[0] = static_cast<int>(stats[k].PixelList[0]);
        for (b_k = 2; b_k <= i1; b_k++) {
          b_expl_temp[0] += static_cast<double>(static_cast<int>(stats[k].
            PixelList[b_k - 1]));
        }

        xpageoffset = stats[k].PixelList.size(0);
        b_expl_temp[1] = static_cast<int>(stats[k].PixelList[xpageoffset]);
        for (b_k = 2; b_k <= i1; b_k++) {
          b_expl_temp[1] += static_cast<double>(static_cast<int>(stats[k].
            PixelList[(xpageoffset + b_k) - 1]));
        }
      }

      stats[k].Centroid[0] = b_expl_temp[0] / static_cast<double>(stats[k].
        PixelList.size(0));
      stats[k].Centroid[1] = b_expl_temp[1] / static_cast<double>(stats[k].
        PixelList.size(0));
    }

    i = stats.size(0);
    for (k = 0; k < i; k++) {
      outstats[k].Area = stats[k].Area;
      outstats[k].Centroid[0] = stats[k].Centroid[0];
      outstats[k].Centroid[1] = stats[k].Centroid[1];
      i1 = stats[k].PixelIdxList.size(0);
      outstats[k].PixelIdxList.set_size(stats[k].PixelIdxList.size(0));
      for (b_k = 0; b_k < i1; b_k++) {
        outstats[k].PixelIdxList[b_k] = stats[k].PixelIdxList[b_k];
      }
    }
  }
}

//
// File trailer for regionprops.cpp
//
// [EOF]
//
