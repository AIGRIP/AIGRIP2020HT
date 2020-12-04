//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 02-Dec-2020 17:30:04
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
#include "StableLine.h"
#include "StableLine_terminate.h"
#include "rt_nonfinite.h"

// Function Declarations
static void argInit_1x360_real_T(double result[360]);
static double argInit_real_T();
static void main_StableLine();

// Function Definitions

//
// Arguments    : double result[360]
// Return Type  : void
//
static void argInit_1x360_real_T(double result[360])
{
  // Loop over the array to initialize each element.
  for (int idx1 = 0; idx1 < 360; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
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
static void main_StableLine()
{
  double YCoordinates_tmp[360];
  double dv[360];
  double targetPointF1Y[11];
  double targetPointF1X[11];
  double normalPointF1Y[11];
  double normalPointF1X[11];
  double targetPointF2Y[11];
  double targetPointF2X[11];
  double normalPointF2Y[11];
  double normalPointF2X[11];
  double targetPointF0Y;
  double targetPointF0X;
  double normalPointF0Y;
  double normalPointF0X;
  double signatureRadiusTargetF1[11];
  double signatureRadiusTargetF2[11];

  // Initialize function 'StableLine' input arguments.
  // Initialize function input argument 'degreesMeasured'.
  // Initialize function input argument 'YCoordinates'.
  argInit_1x360_real_T(YCoordinates_tmp);

  // Initialize function input argument 'XCoordinates'.
  // Initialize function input argument 'signatureRadius'.
  // Call the entry-point 'StableLine'.
  argInit_1x360_real_T(dv);
  StableLine(dv, YCoordinates_tmp, YCoordinates_tmp, YCoordinates_tmp,
             targetPointF1Y, targetPointF1X, normalPointF1Y, normalPointF1X,
             targetPointF2Y, targetPointF2X, normalPointF2Y, normalPointF2X,
             &targetPointF0Y, &targetPointF0X, &normalPointF0Y, &normalPointF0X,
             signatureRadiusTargetF1, signatureRadiusTargetF2);
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
  main_StableLine();

  // Terminate the application.
  // You do not need to do this more than one time.
  StableLine_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
