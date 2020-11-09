//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colourBalance.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 06-Nov-2020 10:41:25
//

// Include Files
#include "colourBalance.h"
#include <cmath>

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions
//
// Arguments    : double u
// Return Type  : double
//
static double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// The function takes in a image and balances the colours. So that different
// lightnings will not have that big effect.
// Arguments    : const unsigned char originalImage[2184480]
//                unsigned char colourBalancedImage[2184480]
// Return Type  : void
//
void colourBalance(const unsigned char originalImage[2184480], unsigned char
                   colourBalancedImage[2184480])
{
  static unsigned char newBlueLayer[728160];
  static unsigned char newGreenLayer[728160];
  static unsigned char newRedLayer[728160];
  double b;
  double b_b;
  double meanBlue;
  double meanGreen;
  double meanRed;
  int iy;
  int y_tmp;

  // Input:
  // originalImage = RGB image 984x740x3
  // Output:
  // colourBalancedImage = RGB image 984x740x3
  // Calculate number of pixales in te image
  // Calculate the mean of every colour and take the mean of every colour added
  // togheter
  meanRed = originalImage[0];
  meanGreen = originalImage[728160];
  meanBlue = originalImage[1456320];
  for (iy = 0; iy < 728159; iy++) {
    y_tmp = (iy + 1) % 984 + 984 * ((iy + 1) / 984);
    meanRed += static_cast<double>(originalImage[y_tmp]);
    meanGreen += static_cast<double>(originalImage[y_tmp + 728160]);
    meanBlue += static_cast<double>(originalImage[y_tmp + 1456320]);
  }

  double meanTotal;
  meanRed /= 728160.0;
  meanGreen /= 728160.0;
  meanBlue /= 728160.0;
  meanTotal = ((meanRed + meanGreen) + meanBlue) / 3.0;

  // Create a new image and use the mean value of the colours to calculate the
  // new colours
  b = meanTotal / meanRed;
  b_b = meanTotal / meanGreen;
  meanRed = meanTotal / meanBlue;
  for (y_tmp = 0; y_tmp < 740; y_tmp++) {
    for (iy = 0; iy < 984; iy++) {
      int i;
      unsigned char u;
      i = iy + 984 * y_tmp;
      meanGreen = rt_roundd_snf(static_cast<double>(originalImage[i]) * b);
      if (meanGreen < 256.0) {
        u = static_cast<unsigned char>(meanGreen);
      } else if (meanGreen >= 256.0) {
        u = MAX_uint8_T;
      } else {
        u = 0U;
      }

      newRedLayer[i] = u;
      meanGreen = rt_roundd_snf(static_cast<double>(originalImage[i + 728160]) *
        b_b);
      if (meanGreen < 256.0) {
        u = static_cast<unsigned char>(meanGreen);
      } else if (meanGreen >= 256.0) {
        u = MAX_uint8_T;
      } else {
        u = 0U;
      }

      newGreenLayer[i] = u;
      meanGreen = rt_roundd_snf(static_cast<double>(originalImage[i + 1456320]) *
        meanRed);
      if (meanGreen < 256.0) {
        u = static_cast<unsigned char>(meanGreen);
      } else if (meanGreen >= 256.0) {
        u = MAX_uint8_T;
      } else {
        u = 0U;
      }

      newBlueLayer[i] = u;
    }
  }

  iy = -1;
  for (y_tmp = 0; y_tmp < 728160; y_tmp++) {
    iy++;
    colourBalancedImage[iy] = newRedLayer[y_tmp];
  }

  for (y_tmp = 0; y_tmp < 728160; y_tmp++) {
    iy++;
    colourBalancedImage[iy] = newGreenLayer[y_tmp];
  }

  for (y_tmp = 0; y_tmp < 728160; y_tmp++) {
    iy++;
    colourBalancedImage[iy] = newBlueLayer[y_tmp];
  }
}

//
// File trailer for colourBalance.cpp
//
// [EOF]
//
