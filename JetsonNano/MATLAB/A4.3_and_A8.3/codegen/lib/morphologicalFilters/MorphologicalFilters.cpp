//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MorphologicalFilters.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 02-Dec-2020 13:31:29
//

// Include Files
#include "MorphologicalFilters.h"
#include "MorphologicalFilters_data.h"
#include "MorphologicalFilters_initialize.h"
#include "MorphologicalFilters_internal_types.h"
#include "bsxfun.h"
#include "imerode.h"
#include "imfill.h"
#include "morphopAlgo.h"
#include "regionprops.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

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
void MorphologicalFilters(const bool colourSegmentationMask[728160], double
  centerOfObjectX, double centerOfObjectY, bool segmentationMask[728160])
{
  static bool maskFill[728160];
  coder::array<struct_T, 1U> stats;
  coder::array<double, 2U> a;
  coder::array<double, 2U> area;
  coder::array<double, 2U> centroid;
  coder::array<double, 2U> varargin_1_tmp;
  coder::array<double, 1U> distances;
  coder::array<int, 1U> r1;
  coder::array<bool, 2U> r;
  double b_centerOfObjectY[2];
  int b_i;
  int i;
  int input_sizes_idx_1;
  int j;
  int n;
  if (!isInitialized_MorphologicalFilters) {
    MorphologicalFilters_initialize();
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
  coder::regionprops(maskFill, stats);

  // Transform the Area and Centroid struct fields into arrays
  n = stats.size(0);
  if (stats.size(0) == 0) {
    i = 0;
  } else {
    i = stats.size(0);
  }

  varargin_1_tmp.set_size(1, i);
  j = 0;
  for (b_i = 0; b_i < n; b_i++) {
    varargin_1_tmp[j] = stats[b_i].Area;
    j++;
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

  varargin_1_tmp.set_size(1, i);
  j = 0;
  for (b_i = 0; b_i < n; b_i++) {
    varargin_1_tmp[j] = stats[b_i].Centroid[0];
    varargin_1_tmp[j + 1] = stats[b_i].Centroid[1];
    j += 2;
  }

  centroid.set_size(area.size(0), 2);
  input_sizes_idx_1 = area.size(0);
  for (i = 0; i < input_sizes_idx_1; i++) {
    centroid[i] = varargin_1_tmp[2 * i];
  }

  for (i = 0; i < input_sizes_idx_1; i++) {
    centroid[i + centroid.size(0)] = varargin_1_tmp[2 * i + 1];
  }

  //  Set all blobs that are samller then 250 pixels to NaN
  r.set_size(area.size(0), 1);
  input_sizes_idx_1 = area.size(0) * area.size(1);
  for (i = 0; i < input_sizes_idx_1; i++) {
    r[i] = (area[i] > 250.0);
  }

  input_sizes_idx_1 = centroid.size(0) - 1;
  distances.set_size(centroid.size(0));
  for (i = 0; i <= input_sizes_idx_1; i++) {
    distances[i] = centroid[i] * static_cast<double>(r[i]);
  }

  input_sizes_idx_1 = distances.size(0);
  for (i = 0; i < input_sizes_idx_1; i++) {
    centroid[i] = distances[i];
  }

  r.set_size(area.size(0), 1);
  input_sizes_idx_1 = area.size(0) * area.size(1);
  for (i = 0; i < input_sizes_idx_1; i++) {
    r[i] = (area[i] > 250.0);
  }

  input_sizes_idx_1 = centroid.size(0) - 1;
  distances.set_size(centroid.size(0));
  for (i = 0; i <= input_sizes_idx_1; i++) {
    distances[i] = centroid[i + centroid.size(0)] * static_cast<double>(r[i]);
  }

  input_sizes_idx_1 = distances.size(0);
  for (i = 0; i < input_sizes_idx_1; i++) {
    centroid[i + centroid.size(0)] = distances[i];
  }

  j = (centroid.size(0) << 1) - 1;
  input_sizes_idx_1 = 0;
  for (b_i = 0; b_i <= j; b_i++) {
    if (centroid[b_i] == 0.0) {
      input_sizes_idx_1++;
    }
  }

  r1.set_size(input_sizes_idx_1);
  input_sizes_idx_1 = 0;
  for (b_i = 0; b_i <= j; b_i++) {
    if (centroid[b_i] == 0.0) {
      r1[input_sizes_idx_1] = b_i + 1;
      input_sizes_idx_1++;
    }
  }

  input_sizes_idx_1 = r1.size(0) - 1;
  for (i = 0; i <= input_sizes_idx_1; i++) {
    centroid[r1[i] - 1] = rtNaN;
  }

  // Calculate which centroid is closest to the object
  b_centerOfObjectY[0] = centerOfObjectY;
  b_centerOfObjectY[1] = centerOfObjectX;
  coder::bsxfun(centroid, b_centerOfObjectY, a);
  centroid.set_size(a.size(0), 2);
  input_sizes_idx_1 = a.size(0) << 1;
  for (j = 0; j < input_sizes_idx_1; j++) {
    centroid[j] = a[j] * a[j];
  }

  if (centroid.size(0) == 0) {
    distances.set_size(0);
  } else {
    input_sizes_idx_1 = centroid.size(0);
    distances.set_size(centroid.size(0));
    for (j = 0; j < input_sizes_idx_1; j++) {
      distances[j] = centroid[j];
    }

    for (j = 0; j < input_sizes_idx_1; j++) {
      distances[j] = distances[j] + centroid[input_sizes_idx_1 + j];
    }
  }

  input_sizes_idx_1 = distances.size(0);
  for (j = 0; j < input_sizes_idx_1; j++) {
    distances[j] = std::sqrt(distances[j]);
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
      j = 2;
      exitg1 = false;
      while ((!exitg1) && (j <= distances.size(0))) {
        if (!rtIsNaN(distances[j - 1])) {
          input_sizes_idx_1 = j;
          exitg1 = true;
        } else {
          j++;
        }
      }
    }

    if (input_sizes_idx_1 == 0) {
      b_i = 0;
    } else {
      double ex;
      ex = distances[input_sizes_idx_1 - 1];
      b_i = input_sizes_idx_1 - 1;
      i = input_sizes_idx_1 + 1;
      for (j = i; j <= n; j++) {
        double d;
        d = distances[j - 1];
        if (ex > d) {
          ex = d;
          b_i = j - 1;
        }
      }
    }
  }

  // Do an new binary map with only the choosen blob
  std::memset(&segmentationMask[0], 0, 728160U * sizeof(bool));
  r1.set_size(stats[b_i].PixelIdxList.size(0));
  input_sizes_idx_1 = stats[b_i].PixelIdxList.size(0);
  for (i = 0; i < input_sizes_idx_1; i++) {
    r1[i] = static_cast<int>(stats[b_i].PixelIdxList[i]);
  }

  input_sizes_idx_1 = r1.size(0);
  for (i = 0; i < input_sizes_idx_1; i++) {
    segmentationMask[r1[i] - 1] = true;
  }

  //  Make smother edges in the image.
  coder::images::internal::coder::morphop_ver_hor_logical(segmentationMask,
    maskFill);
  coder::images::internal::coder::b_morphop_ver_hor_logical(maskFill,
    segmentationMask);
  coder::images::internal::coder::c_morphop_ver_hor_logical(segmentationMask,
    maskFill);
  coder::images::internal::coder::d_morphop_ver_hor_logical(maskFill,
    segmentationMask);

  //  Edge filter, display only the edges of the filter.
  // MorphologicalEdgeFilter run an morpological edge filter on the input image
  // and return an image with only edges.
  //    inputBinaryImage - Should be an binary image.
  //    edgeBinaryImage  - returns a binary edge image.
  //  Set the edge as high and all high pixels inside the object low.
  coder::imerode(segmentationMask, maskFill);
  for (i = 0; i < 728160; i++) {
    bool b;
    b = !maskFill[i];
    maskFill[i] = b;
    segmentationMask[i] = (segmentationMask[i] && b);
  }
}

//
// File trailer for MorphologicalFilters.cpp
//
// [EOF]
//
