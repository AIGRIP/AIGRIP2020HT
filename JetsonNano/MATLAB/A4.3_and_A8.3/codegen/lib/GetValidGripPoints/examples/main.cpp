//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 11:25:48
//

//***********************************************************************
// This automatically generated example C++ main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************

// Include Files
#include "main.h"
#include "GetValidGripPoints.h"
#include "GetValidGripPoints_terminate.h"
#include "rt_nonfinite.h"

// Function Declarations
static void argInit_d11x1_real_T(double result_data[], int result_size[1]);
static double argInit_real_T();
static void main_GetValidGripPoints();

// Function Definitions

//
// Arguments    : double result_data[]
//                int result_size[1]
// Return Type  : void
//
static void argInit_d11x1_real_T(double result_data[], int result_size[1])
{
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size[0] = 2;

  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < 2; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_data[idx0] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_GetValidGripPoints()
{
  double targetPointYPixel_data[11];
  int targetPointYPixel_size[1];
  double targetPointXPixel_data[11];
  int targetPointXPixel_size[1];
  double normalPointYPixel_data[11];
  int normalPointYPixel_size[1];
  double normalPointXPixel_data[11];
  int normalPointXPixel_size[1];
  double distanceToObject_tmp;
  unsigned short motorSteps[3];
  double bestTargetPointY;
  double bestTargetPointX;
  double bestNormalPointY;
  double bestNormalPointX;

  // Initialize function 'GetValidGripPoints' input arguments.
  // Initialize function input argument 'targetPointYPixel'.
  argInit_d11x1_real_T(targetPointYPixel_data, targetPointYPixel_size);

  // Initialize function input argument 'targetPointXPixel'.
  argInit_d11x1_real_T(targetPointXPixel_data, targetPointXPixel_size);

  // Initialize function input argument 'normalPointYPixel'.
  argInit_d11x1_real_T(normalPointYPixel_data, normalPointYPixel_size);

  // Initialize function input argument 'normalPointXPixel'.
  argInit_d11x1_real_T(normalPointXPixel_data, normalPointXPixel_size);
  distanceToObject_tmp = argInit_real_T();

  // Call the entry-point 'GetValidGripPoints'.
  GetValidGripPoints(targetPointYPixel_data, targetPointYPixel_size,
                     targetPointXPixel_data, targetPointXPixel_size,
                     normalPointYPixel_data, normalPointYPixel_size,
                     normalPointXPixel_data, normalPointXPixel_size,
                     distanceToObject_tmp, distanceToObject_tmp, motorSteps,
                     &bestTargetPointY, &bestTargetPointX, &bestNormalPointY,
                     &bestNormalPointX);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. 
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_GetValidGripPoints();

  // Terminate the application.
  // You do not need to do this more than one time.
  GetValidGripPoints_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
