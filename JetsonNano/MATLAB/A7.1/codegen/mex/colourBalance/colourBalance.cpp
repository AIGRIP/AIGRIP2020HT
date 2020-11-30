//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  colourBalance.cpp
//
//  Code generation for function 'colourBalance'
//


// Include files
#include "colourBalance.h"
#include "colourBalance_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Function Definitions
void colourBalance(colourBalanceStackData *SD, const emlrtStack *, const uint8_T
                   originalImage[2184480], uint8_T colourBalancedImage[2184480])
{
  real_T b;
  real_T b_b;
  real_T meanBlue;
  real_T meanGreen;
  real_T meanRed;
  int32_T iy;
  int32_T k;

  // The function takes in a image and balances the colours. So that different
  // lightnings will not have that big effect.
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
  for (k = 0; k < 728159; k++) {
    iy = (k + 1) % 984 + 984 * ((k + 1) / 984);
    meanRed += static_cast<real_T>(originalImage[iy]);
    meanGreen += static_cast<real_T>(originalImage[iy + 728160]);
    meanBlue += static_cast<real_T>(originalImage[iy + 1456320]);
  }

  real_T meanTotal;
  meanRed /= 728160.0;
  meanGreen /= 728160.0;
  meanBlue /= 728160.0;
  meanTotal = ((meanRed + meanGreen) + meanBlue) / 3.0;

  // Create a new image and use the mean value of the colours to calculate the
  // new colours
  b = meanTotal / meanRed;
  b_b = meanTotal / meanGreen;
  meanRed = meanTotal / meanBlue;
  for (k = 0; k < 740; k++) {
    for (int32_T i = 0; i < 984; i++) {
      uint8_T u;
      iy = i + 984 * k;
      meanGreen = muDoubleScalarRound(static_cast<real_T>(originalImage[iy]) * b);
      if (meanGreen < 256.0) {
        u = static_cast<uint8_T>(meanGreen);
      } else if (meanGreen >= 256.0) {
        u = MAX_uint8_T;
      } else {
        u = 0U;
      }

      SD->f0.newRedLayer[iy] = u;
      meanGreen = muDoubleScalarRound(static_cast<real_T>(originalImage[iy +
        728160]) * b_b);
      if (meanGreen < 256.0) {
        u = static_cast<uint8_T>(meanGreen);
      } else if (meanGreen >= 256.0) {
        u = MAX_uint8_T;
      } else {
        u = 0U;
      }

      SD->f0.newGreenLayer[iy] = u;
      meanGreen = muDoubleScalarRound(static_cast<real_T>(originalImage[iy +
        1456320]) * meanRed);
      if (meanGreen < 256.0) {
        u = static_cast<uint8_T>(meanGreen);
      } else if (meanGreen >= 256.0) {
        u = MAX_uint8_T;
      } else {
        u = 0U;
      }

      SD->f0.newBlueLayer[iy] = u;
    }
  }

  iy = -1;
  for (k = 0; k < 728160; k++) {
    iy++;
    colourBalancedImage[iy] = SD->f0.newBlueLayer[k];
  }

  for (k = 0; k < 728160; k++) {
    iy++;
    colourBalancedImage[iy] = SD->f0.newGreenLayer[k];
  }

  for (k = 0; k < 728160; k++) {
    iy++;
    colourBalancedImage[iy] = SD->f0.newRedLayer[k];
  }
}

// End of code generation (colourBalance.cpp)
