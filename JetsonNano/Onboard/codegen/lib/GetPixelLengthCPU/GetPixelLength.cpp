//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: GetPixelLength.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Nov-2020 07:46:11
//

// Include Files
#include "GetPixelLength.h"

// Function Definitions
//
// This function will calculate the width of an object in an image taken
// by a raspberry
// Arguments    : const bool binaryImage[728160]
//                double objectMidPoint
//                double distanceToObject
// Return Type  : double
//
double GetPixelLength(const bool binaryImage[728160], double objectMidPoint,
                      double distanceToObject)
{
  int nz;
  int nz_tmp;

  // Input:
  // binaryImage = An binary image where an object have been segmentated
  // objectMidPoint = A rough estimation of the objects midpoint. midpoint
  // is calculated with pixels in the image
  // distanceToObject = distance to object in mm.
  // Output:
  // lengthPixel = What one pixel equals for distance in the real world.
  //  Set the standard vaiabels for the camera
  // Check
  // Calculate the width of the object in pixels
  nz_tmp = 984 * (static_cast<int>(objectMidPoint) - 1);
  nz = binaryImage[nz_tmp];
  for (int k = 0; k < 983; k++) {
    nz += binaryImage[(k + nz_tmp) + 1];
  }

  // Calculate the width of the object on the sensor in mm
  // Calculate the width of the object in the real world
  // Calculate what length one pixel corresponds to in the real world
  return distanceToObject * (6.35 * static_cast<double>(nz) / 740.0) / 3.04 /
    static_cast<double>(nz);
}

//
// File trailer for GetPixelLength.cpp
//
// [EOF]
//
