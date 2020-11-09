//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: morphologicalFilters.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 05-Nov-2020 08:33:11
//

// Include Files
#include "morphologicalFilters.h"
#include "bwconncomp.h"
#include "imfill.h"
#include "morphologicalFilters_data.h"
#include "morphologicalFilters_initialize.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Type Definitions
struct struct_T
{
  double Area;
  double Centroid[2];
  coder::array<double, 1U> PixelIdxList;
};

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
// The function takes in a binary image where the colours have been segmentated
// and a rough postion of the object in the image that should be segmented.
// and it outputs a a bitmask of the the object.
// Arguments    : const bool colourSegmentationMask[728160]
//                double centerOfObjectX
//                double centerOfObjectY
//                bool segmentationMask[728160]
// Return Type  : void
//
void morphologicalFilters(const bool colourSegmentationMask[728160], double
  centerOfObjectX, double centerOfObjectY, bool segmentationMask[728160])
{
  static bool maskFill[728160];
  coder::array<b_struct_T, 1U> b_stats;
  coder::array<struct_T, 1U> stats;
  coder::array<double, 2U> centroid;
  coder::array<double, 2U> varargin_1;
  coder::array<double, 2U> z1;
  coder::array<double, 1U> distances;
  coder::array<unsigned int, 2U> area;
  coder::array<unsigned int, 2U> varargin_1_tmp;
  coder::array<int, 1U> idxCount;
  coder::array<int, 1U> r1;
  coder::array<int, 1U> regionLengths;
  coder::array<bool, 2U> r;
  b_struct_T b_statsOneObj;
  struct_T statsOneObj;
  double sz[2];
  double CC_NumObjects;
  double expl_temp;
  int b_i;
  int i;
  int input_sizes_idx_1;
  int k;
  int n;
  int xpageoffset;
  if (!isInitialized_morphologicalFilters) {
    morphologicalFilters_initialize();
  }

  // Input:
  // colourBalancedImage = Binary map 984x740
  // centerOfObjectX = Objects center postion in the x-axis
  // centerOfObjectY = Objects center postion in the y-axis
  // Output:
  // SegmentationMask = Binary map 984x740 of the object
  // Fill up the hole in the binary image.
  coder::imfill(colourSegmentationMask, maskFill);

  // Get the data about the different blobs in the image
  coder::bwconncomp(maskFill, &expl_temp, sz, &CC_NumObjects, distances,
                    regionLengths);
  statsOneObj.Area = 0.0;
  statsOneObj.Centroid[0] = 0.0;
  statsOneObj.Centroid[1] = 0.0;
  statsOneObj.PixelIdxList.set_size(0);
  stats.set_size((static_cast<int>(CC_NumObjects)));
  xpageoffset = static_cast<int>(CC_NumObjects);
  for (i = 0; i < xpageoffset; i++) {
    stats[i] = statsOneObj;
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
  b_stats.set_size((static_cast<int>(CC_NumObjects)));
  xpageoffset = static_cast<int>(CC_NumObjects);
  for (i = 0; i < xpageoffset; i++) {
    b_stats[i] = b_statsOneObj;
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
      b_i = idxCount[k + 1];
      if (idxCount[k] + 1 > b_i) {
        input_sizes_idx_1 = 0;
        b_i = 0;
      } else {
        input_sizes_idx_1 = idxCount[k];
      }

      xpageoffset = b_i - input_sizes_idx_1;
      b_stats[k].PixelIdxList.set_size(xpageoffset);
      for (b_i = 0; b_i < xpageoffset; b_i++) {
        b_stats[k].PixelIdxList[b_i] = distances[input_sizes_idx_1 + b_i];
      }
    }
  }

  i = b_stats.size(0);
  for (k = 0; k < i; k++) {
    b_stats[k].Area = b_stats[k].PixelIdxList.size(0);
  }

  i = b_stats.size(0);
  for (k = 0; k < i; k++) {
    xpageoffset = b_stats[k].PixelIdxList.size(0);
    if (b_stats[k].PixelIdxList.size(0) != 0) {
      regionLengths.set_size(b_stats[k].PixelIdxList.size(0));
      for (b_i = 0; b_i < xpageoffset; b_i++) {
        regionLengths[b_i] = static_cast<int>(b_stats[k].PixelIdxList[b_i]) - 1;
      }

      idxCount.set_size(regionLengths.size(0));
      xpageoffset = regionLengths.size(0);
      for (b_i = 0; b_i < xpageoffset; b_i++) {
        idxCount[b_i] = regionLengths[b_i] / 984;
      }

      xpageoffset = regionLengths.size(0);
      for (b_i = 0; b_i < xpageoffset; b_i++) {
        regionLengths[b_i] = regionLengths[b_i] - idxCount[b_i] * 984;
      }

      b_stats[k].PixelList.set_size(idxCount.size(0), 2);
      xpageoffset = idxCount.size(0);
      for (b_i = 0; b_i < xpageoffset; b_i++) {
        b_stats[k].PixelList[b_i] = idxCount[b_i] + 1;
      }

      xpageoffset = regionLengths.size(0);
      for (b_i = 0; b_i < xpageoffset; b_i++) {
        b_stats[k].PixelList[b_i + b_stats[k].PixelList.size(0)] =
          regionLengths[b_i] + 1;
      }
    } else {
      b_stats[k].PixelList.set_size(0, 2);
    }
  }

  i = b_stats.size(0);
  for (k = 0; k < i; k++) {
    b_i = b_stats[k].PixelList.size(0);
    if (b_stats[k].PixelList.size(0) == 0) {
      sz[0] = 0.0;
      sz[1] = 0.0;
    } else {
      sz[0] = static_cast<int>(b_stats[k].PixelList[0]);
      for (input_sizes_idx_1 = 2; input_sizes_idx_1 <= b_i; input_sizes_idx_1++)
      {
        sz[0] += static_cast<double>(static_cast<int>(b_stats[k]
          .PixelList[input_sizes_idx_1 - 1]));
      }

      xpageoffset = b_stats[k].PixelList.size(0);
      sz[1] = static_cast<int>(b_stats[k].PixelList[xpageoffset]);
      for (input_sizes_idx_1 = 2; input_sizes_idx_1 <= b_i; input_sizes_idx_1++)
      {
        sz[1] += static_cast<double>(static_cast<int>(b_stats[k].PixelList
          [(xpageoffset + input_sizes_idx_1) - 1]));
      }
    }

    b_stats[k].Centroid[0] = sz[0] / static_cast<double>(b_stats[k].
      PixelList.size(0));
    b_stats[k].Centroid[1] = sz[1] / static_cast<double>(b_stats[k].
      PixelList.size(0));
  }

  i = b_stats.size(0);
  for (k = 0; k < i; k++) {
    stats[k].Area = b_stats[k].Area;
    stats[k].Centroid[0] = b_stats[k].Centroid[0];
    stats[k].Centroid[1] = b_stats[k].Centroid[1];
    b_i = b_stats[k].PixelIdxList.size(0);
    stats[k].PixelIdxList.set_size(b_stats[k].PixelIdxList.size(0));
    for (input_sizes_idx_1 = 0; input_sizes_idx_1 < b_i; input_sizes_idx_1++) {
      stats[k].PixelIdxList[input_sizes_idx_1] = b_stats[k]
        .PixelIdxList[input_sizes_idx_1];
    }
  }

  // Transform the Area and Centroid struct fields into arrays
  n = stats.size(0);
  if (stats.size(0) == 0) {
    i = 0;
  } else {
    i = stats.size(0);
  }

  varargin_1_tmp.set_size(1, i);
  xpageoffset = 0;
  for (b_i = 0; b_i < n; b_i++) {
    varargin_1_tmp[xpageoffset] = static_cast<unsigned int>(stats[b_i].Area);
    xpageoffset++;
  }

  if (varargin_1_tmp.size(1) != 0) {
    input_sizes_idx_1 = varargin_1_tmp.size(1);
  } else {
    input_sizes_idx_1 = 0;
  }

  area.set_size(input_sizes_idx_1, 1);
  for (i = 0; i < input_sizes_idx_1; i++) {
    area[i] = varargin_1_tmp[i];
  }

  n = stats.size(0);
  if (stats.size(0) == 0) {
    i = 0;
  } else {
    i = stats.size(0) << 1;
  }

  varargin_1.set_size(1, i);
  xpageoffset = 0;
  for (b_i = 0; b_i < n; b_i++) {
    varargin_1[xpageoffset] = stats[b_i].Centroid[0];
    varargin_1[xpageoffset + 1] = stats[b_i].Centroid[1];
    xpageoffset += 2;
  }

  centroid.set_size(area.size(0), 2);
  xpageoffset = area.size(0);
  for (i = 0; i < xpageoffset; i++) {
    centroid[i] = varargin_1[2 * i];
  }

  for (i = 0; i < xpageoffset; i++) {
    centroid[i + centroid.size(0)] = varargin_1[2 * i + 1];
  }

  //  Set all blobs that are samller then 250 pixels to NaN
  r.set_size(area.size(0), 1);
  xpageoffset = area.size(0) * area.size(1);
  for (i = 0; i < xpageoffset; i++) {
    r[i] = (static_cast<int>(area[i]) > 250);
  }

  input_sizes_idx_1 = centroid.size(0) - 1;
  distances.set_size(centroid.size(0));
  for (i = 0; i <= input_sizes_idx_1; i++) {
    distances[i] = centroid[i] * static_cast<double>(r[i]);
  }

  xpageoffset = distances.size(0);
  for (i = 0; i < xpageoffset; i++) {
    centroid[i] = distances[i];
  }

  r.set_size(area.size(0), 1);
  xpageoffset = area.size(0) * area.size(1);
  for (i = 0; i < xpageoffset; i++) {
    r[i] = (static_cast<int>(area[i]) > 250);
  }

  input_sizes_idx_1 = centroid.size(0) - 1;
  distances.set_size(centroid.size(0));
  for (i = 0; i <= input_sizes_idx_1; i++) {
    distances[i] = centroid[i + centroid.size(0)] * static_cast<double>(r[i]);
  }

  xpageoffset = distances.size(0);
  for (i = 0; i < xpageoffset; i++) {
    centroid[i + centroid.size(0)] = distances[i];
  }

  xpageoffset = (centroid.size(0) << 1) - 1;
  input_sizes_idx_1 = 0;
  for (b_i = 0; b_i <= xpageoffset; b_i++) {
    if (centroid[b_i] == 0.0) {
      input_sizes_idx_1++;
    }
  }

  r1.set_size(input_sizes_idx_1);
  input_sizes_idx_1 = 0;
  for (b_i = 0; b_i <= xpageoffset; b_i++) {
    if (centroid[b_i] == 0.0) {
      r1[input_sizes_idx_1] = b_i + 1;
      input_sizes_idx_1++;
    }
  }

  xpageoffset = r1.size(0) - 1;
  for (i = 0; i <= xpageoffset; i++) {
    centroid[r1[i] - 1] = rtNaN;
  }

  // Calculate which centroid is closest to the object
  varargin_1.set_size(centroid.size(0), 2);
  if (centroid.size(0) != 0) {
    input_sizes_idx_1 = (centroid.size(0) != 1);
    i = centroid.size(0) - 1;
    for (k = 0; k <= i; k++) {
      varargin_1[k] = centroid[input_sizes_idx_1 * k] - centerOfObjectY;
    }

    i = varargin_1.size(0) - 1;
    for (k = 0; k <= i; k++) {
      varargin_1[k + varargin_1.size(0)] = centroid[input_sizes_idx_1 * k +
        centroid.size(0)] - centerOfObjectX;
    }
  }

  z1.set_size(varargin_1.size(0), 2);
  input_sizes_idx_1 = varargin_1.size(0) << 1;
  for (k = 0; k < input_sizes_idx_1; k++) {
    z1[k] = varargin_1[k] * varargin_1[k];
  }

  if (z1.size(0) == 0) {
    distances.set_size(0);
  } else {
    input_sizes_idx_1 = z1.size(0);
    distances.set_size(z1.size(0));
    for (xpageoffset = 0; xpageoffset < input_sizes_idx_1; xpageoffset++) {
      distances[xpageoffset] = z1[xpageoffset];
    }

    for (xpageoffset = 0; xpageoffset < input_sizes_idx_1; xpageoffset++) {
      distances[xpageoffset] = distances[xpageoffset] + z1[input_sizes_idx_1 +
        xpageoffset];
    }
  }

  input_sizes_idx_1 = distances.size(0);
  for (k = 0; k < input_sizes_idx_1; k++) {
    distances[k] = std::sqrt(distances[k]);
  }

  n = distances.size(0);
  if (distances.size(0) <= 2) {
    if (distances.size(0) == 1) {
      b_i = 0;
    } else if ((distances[0] > distances[1]) || (rtIsNaN(distances[0]) &&
                (!rtIsNaN(distances[1])))) {
      b_i = 1;
    } else {
      b_i = 0;
    }
  } else {
    if (!rtIsNaN(distances[0])) {
      input_sizes_idx_1 = 1;
    } else {
      bool exitg1;
      input_sizes_idx_1 = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= distances.size(0))) {
        if (!rtIsNaN(distances[k - 1])) {
          input_sizes_idx_1 = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (input_sizes_idx_1 == 0) {
      b_i = 0;
    } else {
      expl_temp = distances[input_sizes_idx_1 - 1];
      b_i = input_sizes_idx_1 - 1;
      i = input_sizes_idx_1 + 1;
      for (k = i; k <= n; k++) {
        CC_NumObjects = distances[k - 1];
        if (expl_temp > CC_NumObjects) {
          expl_temp = CC_NumObjects;
          b_i = k - 1;
        }
      }
    }
  }

  // Do an new binary map with only the choosen blob
  std::memset(&segmentationMask[0], 0, 728160U * sizeof(bool));
  r1.set_size(stats[b_i].PixelIdxList.size(0));
  xpageoffset = stats[b_i].PixelIdxList.size(0);
  for (i = 0; i < xpageoffset; i++) {
    r1[i] = static_cast<int>(stats[b_i].PixelIdxList[i]);
  }

  xpageoffset = r1.size(0);
  for (i = 0; i < xpageoffset; i++) {
    segmentationMask[r1[i] - 1] = true;
  }
}

//
// File trailer for morphologicalFilters.cpp
//
// [EOF]
//
