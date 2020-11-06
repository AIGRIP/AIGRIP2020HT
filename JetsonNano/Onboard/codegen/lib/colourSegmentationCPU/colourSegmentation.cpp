//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colourSegmentation.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 06-Nov-2020 12:01:09
//

// Include Files
#include "colourSegmentation.h"
#include "applyToMultipleDims.h"
#include "colourSegmentation_data.h"
#include "colourSegmentation_initialize.h"
#include "rgb2hsv.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
//
// The function takes in a image and a rough postion of the object in the
// image that should be segmented. and it outputs a a bitmask of the the
// object.
// Arguments    : const unsigned char colourBalancedImage[2184480]
//                double centerOfObjectX
//                double centerOfObjectY
//                bool colourSegmentationMask[728160]
// Return Type  : void
//
void colourSegmentation(const unsigned char colourBalancedImage[2184480], double
  centerOfObjectX, double centerOfObjectY, bool colourSegmentationMask[728160])
{
  static double HSVImage[2184480];
  static double b_colourBalancedImage[2184480];
  coder::array<double, 3U> b_HSVImage;
  coder::array<double, 3U> c_HSVImage;
  coder::array<double, 3U> d_HSVImage;
  coder::array<double, 3U> e_HSVImage;
  double centerHSVImage[7803];
  double nz[9];
  double d;
  double ex;
  int HSVImage_tmp;
  int b_loop_ub;
  int centerColourMask_tmp;
  int i;
  int i1;
  int i2;
  int i3;
  int loop_ub;
  bool centerColourMask[23409];
  if (!isInitialized_colourSegmentation) {
    colourSegmentation_initialize();
  }

  // Input:
  // colourBalancedImage = RGB image 984x740x3
  // centerOfObjectX = Objects center postion in the x-axis
  // centerOfObjectY = Objects center postion in the y-axis
  // Output:
  // colourSegmentationMask = bitmask of the segmented object
  // Transform the Image into the HSV colour space
  for (i = 0; i < 2184480; i++) {
    b_colourBalancedImage[i] = static_cast<double>(colourBalancedImage[i]) /
      255.0;
  }

  coder::rgb2hsv_portable(b_colourBalancedImage, HSVImage);

  // Standardize the H-values from 0-1 to 0-360
  for (i = 0; i < 740; i++) {
    for (i1 = 0; i1 < 984; i1++) {
      HSVImage_tmp = i1 + 984 * i;
      HSVImage[HSVImage_tmp] *= 360.0;
    }
  }

  // Make a small square at the center of the object and determine which
  // colour is most prevalent in the square
  // Choose square size
  // Calculate the start and end values for X and  Y
  // Take out the sqaure area from the image
  if (centerOfObjectX - 25.0 > centerOfObjectX + 25.0) {
    i = 0;
    i1 = 0;
  } else {
    i = static_cast<int>(centerOfObjectX - 25.0) - 1;
    i1 = static_cast<int>(centerOfObjectX + 25.0);
  }

  if (centerOfObjectY - 25.0 > centerOfObjectY + 25.0) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(centerOfObjectY - 25.0) - 1;
    i3 = static_cast<int>(centerOfObjectY + 25.0);
  }

  loop_ub = i1 - i;
  b_loop_ub = i3 - i2;
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = HSVImage[((i +
          centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 * i1];
      }
    }
  }

  for (i1 = 0; i1 < 7803; i1++) {
    centerHSVImage[i1] = b_HSVImage[i1];
  }

  std::memset(&centerColourMask[0], 0, 23409U * sizeof(bool));

  // Make mask in the square for every 9 colours.
  // Calcualte which pixels are red
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  c_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  d_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        d = HSVImage[((i + centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 *
          i1];
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = d;
        c_HSVImage[(centerColourMask_tmp + c_HSVImage.size(0) * i3) +
          c_HSVImage.size(0) * c_HSVImage.size(1) * i1] = d;
        d_HSVImage[(centerColourMask_tmp + d_HSVImage.size(0) * i3) +
          d_HSVImage.size(0) * d_HSVImage.size(1) * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i3 = 0; i3 < 51; i3++) {
      centerColourMask_tmp = i3 + 51 * i1;
      centerColourMask[centerColourMask_tmp] =
        (((b_HSVImage[centerColourMask_tmp] < 15.0) ||
          (c_HSVImage[centerColourMask_tmp] == 315.0) ||
          (centerHSVImage[centerColourMask_tmp] > 315.0)) &&
         (d_HSVImage[centerColourMask_tmp + 2601] > 0.2) &&
         (centerHSVImage[centerColourMask_tmp + 5202] > 0.3));
    }
  }

  // Calcualte which pixels are orange
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  c_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  d_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        d = HSVImage[((i + centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 *
          i1];
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = d;
        c_HSVImage[(centerColourMask_tmp + c_HSVImage.size(0) * i3) +
          c_HSVImage.size(0) * c_HSVImage.size(1) * i1] = d;
        d_HSVImage[(centerColourMask_tmp + d_HSVImage.size(0) * i3) +
          d_HSVImage.size(0) * d_HSVImage.size(1) * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i3 = 0; i3 < 51; i3++) {
      centerColourMask_tmp = i3 + 51 * i1;
      centerColourMask[centerColourMask_tmp + 2601] =
        ((((b_HSVImage[centerColourMask_tmp] > 15.0) &&
           (c_HSVImage[centerColourMask_tmp] < 50.0)) ||
          (centerHSVImage[centerColourMask_tmp] == 15.0)) &&
         (d_HSVImage[centerColourMask_tmp + 2601] > 0.2) &&
         (centerHSVImage[centerColourMask_tmp + 5202] > 0.3));
    }
  }

  // Calcualte which pixels are yellow
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  c_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  d_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        d = HSVImage[((i + centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 *
          i1];
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = d;
        c_HSVImage[(centerColourMask_tmp + c_HSVImage.size(0) * i3) +
          c_HSVImage.size(0) * c_HSVImage.size(1) * i1] = d;
        d_HSVImage[(centerColourMask_tmp + d_HSVImage.size(0) * i3) +
          d_HSVImage.size(0) * d_HSVImage.size(1) * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i3 = 0; i3 < 51; i3++) {
      centerColourMask_tmp = i3 + 51 * i1;
      centerColourMask[centerColourMask_tmp + 5202] =
        ((((b_HSVImage[centerColourMask_tmp] > 50.0) &&
           (c_HSVImage[centerColourMask_tmp] < 70.0)) ||
          (centerHSVImage[centerColourMask_tmp] == 50.0)) &&
         (d_HSVImage[centerColourMask_tmp + 2601] > 0.2) &&
         (centerHSVImage[centerColourMask_tmp + 5202] > 0.3));
    }
  }

  // Calcualte which pixels are green
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  c_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  d_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        d = HSVImage[((i + centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 *
          i1];
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = d;
        c_HSVImage[(centerColourMask_tmp + c_HSVImage.size(0) * i3) +
          c_HSVImage.size(0) * c_HSVImage.size(1) * i1] = d;
        d_HSVImage[(centerColourMask_tmp + d_HSVImage.size(0) * i3) +
          d_HSVImage.size(0) * d_HSVImage.size(1) * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i3 = 0; i3 < 51; i3++) {
      centerColourMask_tmp = i3 + 51 * i1;
      centerColourMask[centerColourMask_tmp + 7803] =
        ((((b_HSVImage[centerColourMask_tmp] > 70.0) &&
           (c_HSVImage[centerColourMask_tmp] < 155.0)) ||
          (centerHSVImage[centerColourMask_tmp] == 70.0)) &&
         (d_HSVImage[centerColourMask_tmp + 2601] > 0.2) &&
         (centerHSVImage[centerColourMask_tmp + 5202] > 0.3));
    }
  }

  // Calcualte which pixels are cyan
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  c_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  d_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        d = HSVImage[((i + centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 *
          i1];
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = d;
        c_HSVImage[(centerColourMask_tmp + c_HSVImage.size(0) * i3) +
          c_HSVImage.size(0) * c_HSVImage.size(1) * i1] = d;
        d_HSVImage[(centerColourMask_tmp + d_HSVImage.size(0) * i3) +
          d_HSVImage.size(0) * d_HSVImage.size(1) * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i3 = 0; i3 < 51; i3++) {
      centerColourMask_tmp = i3 + 51 * i1;
      centerColourMask[centerColourMask_tmp + 10404] =
        ((((b_HSVImage[centerColourMask_tmp] > 155.0) &&
           (c_HSVImage[centerColourMask_tmp] < 205.0)) ||
          (centerHSVImage[centerColourMask_tmp] == 155.0)) &&
         (d_HSVImage[centerColourMask_tmp + 2601] > 0.2) &&
         (centerHSVImage[centerColourMask_tmp + 5202] > 0.3));
    }
  }

  // Calcualte which pixels are blue
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  c_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  d_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        d = HSVImage[((i + centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 *
          i1];
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = d;
        c_HSVImage[(centerColourMask_tmp + c_HSVImage.size(0) * i3) +
          c_HSVImage.size(0) * c_HSVImage.size(1) * i1] = d;
        d_HSVImage[(centerColourMask_tmp + d_HSVImage.size(0) * i3) +
          d_HSVImage.size(0) * d_HSVImage.size(1) * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i3 = 0; i3 < 51; i3++) {
      centerColourMask_tmp = i3 + 51 * i1;
      centerColourMask[centerColourMask_tmp + 13005] =
        ((((b_HSVImage[centerColourMask_tmp] > 205.0) &&
           (c_HSVImage[centerColourMask_tmp] < 260.0)) ||
          (centerHSVImage[centerColourMask_tmp] == 205.0)) &&
         (d_HSVImage[centerColourMask_tmp + 2601] > 0.2) &&
         (centerHSVImage[centerColourMask_tmp + 5202] > 0.3));
    }
  }

  // Calcualte which pixels are purple
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  c_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  d_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        d = HSVImage[((i + centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 *
          i1];
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = d;
        c_HSVImage[(centerColourMask_tmp + c_HSVImage.size(0) * i3) +
          c_HSVImage.size(0) * c_HSVImage.size(1) * i1] = d;
        d_HSVImage[(centerColourMask_tmp + d_HSVImage.size(0) * i3) +
          d_HSVImage.size(0) * d_HSVImage.size(1) * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i3 = 0; i3 < 51; i3++) {
      centerColourMask_tmp = i3 + 51 * i1;
      centerColourMask[centerColourMask_tmp + 15606] =
        ((((b_HSVImage[centerColourMask_tmp] > 260.0) &&
           (c_HSVImage[centerColourMask_tmp] < 315.0)) ||
          (centerHSVImage[centerColourMask_tmp] == 260.0)) &&
         (d_HSVImage[centerColourMask_tmp + 2601] > 0.2) &&
         (centerHSVImage[centerColourMask_tmp + 5202] > 0.3));
    }
  }

  // Calcualte which pixels are white
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  c_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  d_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  e_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        d = HSVImage[((i + centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 *
          i1];
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = d;
        c_HSVImage[(centerColourMask_tmp + c_HSVImage.size(0) * i3) +
          c_HSVImage.size(0) * c_HSVImage.size(1) * i1] = d;
        d_HSVImage[(centerColourMask_tmp + d_HSVImage.size(0) * i3) +
          d_HSVImage.size(0) * d_HSVImage.size(1) * i1] = d;
        e_HSVImage[(centerColourMask_tmp + e_HSVImage.size(0) * i3) +
          e_HSVImage.size(0) * e_HSVImage.size(1) * i1] = d;
      }
    }
  }

  for (i1 = 0; i1 < 51; i1++) {
    for (i3 = 0; i3 < 51; i3++) {
      HSVImage_tmp = i3 + 51 * i1;
      centerColourMask[HSVImage_tmp + 18207] = (((b_HSVImage[HSVImage_tmp + 5202]
        > 0.6) || (c_HSVImage[HSVImage_tmp + 5202] == 0.6)) &&
        ((d_HSVImage[HSVImage_tmp + 2601] < 0.2) || (e_HSVImage[HSVImage_tmp +
        2601] == 0.2)));
    }
  }

  // Calcualte which pixels are black
  b_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  c_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  d_HSVImage.set_size(loop_ub, b_loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (centerColourMask_tmp = 0; centerColourMask_tmp < loop_ub;
           centerColourMask_tmp++) {
        d = HSVImage[((i + centerColourMask_tmp) + 984 * (i2 + i3)) + 728160 *
          i1];
        b_HSVImage[(centerColourMask_tmp + b_HSVImage.size(0) * i3) +
          b_HSVImage.size(0) * b_HSVImage.size(1) * i1] = d;
        c_HSVImage[(centerColourMask_tmp + c_HSVImage.size(0) * i3) +
          c_HSVImage.size(0) * c_HSVImage.size(1) * i1] = d;
        d_HSVImage[(centerColourMask_tmp + d_HSVImage.size(0) * i3) +
          d_HSVImage.size(0) * d_HSVImage.size(1) * i1] = d;
      }
    }
  }

  for (i = 0; i < 51; i++) {
    for (i1 = 0; i1 < 51; i1++) {
      i2 = i1 + 51 * i;
      d = centerHSVImage[i2 + 2601];
      centerColourMask[i2 + 20808] = ((b_HSVImage[i2 + 5202] < 0.3) ||
        (c_HSVImage[i2 + 5202] == 0.3) || ((d_HSVImage[i2 + 5202] < 0.6) && ((d <
        0.2) || (d == 0.2))));
    }
  }

  //  Sum up all the masks and then determine which mask has the most pixels
  coder::internal::applyToMultipleDims(centerColourMask, nz);
  ex = nz[0];
  HSVImage_tmp = 1;
  for (centerColourMask_tmp = 0; centerColourMask_tmp < 8; centerColourMask_tmp
       ++) {
    d = nz[centerColourMask_tmp + 1];
    if (ex < d) {
      ex = d;
      HSVImage_tmp = centerColourMask_tmp + 2;
    }
  }

  //  Make a mask over the whole image. The colour that is seperated
  //  is the one that had the most pixels in the square
  if (HSVImage_tmp == 1) {
    // Red
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        i2 = i1 + 984 * i;
        d = HSVImage[i2];
        colourSegmentationMask[i2] = (((d < 15.0) || (d == 315.0) || (d > 315.0))
          && (HSVImage[i2 + 728160] > 0.2) && (HSVImage[i2 + 1456320] > 0.3));
      }
    }
  } else if (HSVImage_tmp == 2) {
    // Orange
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        i2 = i1 + 984 * i;
        d = HSVImage[i2];
        colourSegmentationMask[i2] = ((((d > 15.0) && (d < 50.0)) || (d == 15.0))
          && (HSVImage[i2 + 728160] > 0.2) && (HSVImage[i2 + 1456320] > 0.3));
      }
    }
  } else if (HSVImage_tmp == 3) {
    // Yellow
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        i2 = i1 + 984 * i;
        d = HSVImage[i2];
        colourSegmentationMask[i2] = ((((d > 50.0) && (d < 70.0)) || (d == 50.0))
          && (HSVImage[i2 + 728160] > 0.2) && (HSVImage[i2 + 1456320] > 0.3));
      }
    }
  } else if (HSVImage_tmp == 4) {
    // Green
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        i2 = i1 + 984 * i;
        d = HSVImage[i2];
        colourSegmentationMask[i2] = ((((d > 70.0) && (d < 155.0)) || (d == 70.0))
          && (HSVImage[i2 + 728160] > 0.2) && (HSVImage[i2 + 1456320] > 0.3));
      }
    }
  } else if (HSVImage_tmp == 5) {
    // Cyan
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        i2 = i1 + 984 * i;
        d = HSVImage[i2];
        colourSegmentationMask[i2] = ((((d > 155.0) && (d < 205.0)) || (d ==
          155.0)) && (HSVImage[i2 + 728160] > 0.2) && (HSVImage[i2 + 1456320] >
          0.3));
      }
    }
  } else if (HSVImage_tmp == 6) {
    // Blue
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        i2 = i1 + 984 * i;
        d = HSVImage[i2];
        colourSegmentationMask[i2] = ((((d > 205.0) && (d < 260.0)) || (d ==
          205.0)) && (HSVImage[i2 + 728160] > 0.2) && (HSVImage[i2 + 1456320] >
          0.3));
      }
    }
  } else if (HSVImage_tmp == 7) {
    // Purple
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        i2 = i1 + 984 * i;
        d = HSVImage[i2];
        colourSegmentationMask[i2] = ((((d > 260.0) && (d < 315.0)) || (d ==
          260.0)) && (HSVImage[i2 + 728160] > 0.2) && (HSVImage[i2 + 1456320] >
          0.3));
      }
    }
  } else if (HSVImage_tmp == 8) {
    // White
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        i2 = i1 + 984 * i;
        d = HSVImage[i2 + 1456320];
        ex = HSVImage[i2 + 728160];
        colourSegmentationMask[i2] = (((d > 0.6) || (d == 0.6)) && ((ex < 0.2) ||
          (ex == 0.2)));
      }
    }
  } else {
    // Black
    for (i = 0; i < 740; i++) {
      for (i1 = 0; i1 < 984; i1++) {
        i2 = i1 + 984 * i;
        d = HSVImage[i2 + 1456320];
        ex = HSVImage[i2 + 728160];
        colourSegmentationMask[i2] = ((d < 0.3) || (d == 0.3) || ((d < 0.6) &&
          ((ex < 0.2) || (ex == 0.2))));
      }
    }
  }
}

//
// File trailer for colourSegmentation.cpp
//
// [EOF]
//
