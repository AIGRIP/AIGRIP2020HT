//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 17-Nov-2020 09:18:26
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
#include "PointToLine.h"
#include "PointToLine_terminate.h"

// Function Declarations
static void argInit_1x2_real_T(double result[2]);
static double argInit_real_T();
static void main_PointToLine();

// Function Definitions
//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_1x2_real_T(double result[2])
{
  // Loop over the array to initialize each element.
  for (int idx1 = 0; idx1 < 2; idx1++) {
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
static void main_PointToLine()
{
  double singularityPoint_tmp[2];
  double positionReachable;

  // Initialize function 'PointToLine' input arguments.
  // Initialize function input argument 'singularityPoint'.
  argInit_1x2_real_T(singularityPoint_tmp);

  // Initialize function input argument 'possiblePosition'.
  // Initialize function input argument 'normalStableLine'.
  // Call the entry-point 'PointToLine'.
  positionReachable = PointToLine(singularityPoint_tmp, singularityPoint_tmp,
    singularityPoint_tmp);
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
  main_PointToLine();

  // Terminate the application.
  // You do not need to do this more than one time.
  PointToLine_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//