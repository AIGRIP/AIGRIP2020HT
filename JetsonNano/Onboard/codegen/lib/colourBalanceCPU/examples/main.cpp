//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 06-Nov-2020 10:41:25
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
#include "colourBalance.h"
#include "colourBalance_terminate.h"

// Function Declarations
static void argInit_984x740x3_uint8_T(unsigned char result[2184480]);
static unsigned char argInit_uint8_T();
static void main_colourBalance();

// Function Definitions
//
// Arguments    : unsigned char result[2184480]
// Return Type  : void
//
static void argInit_984x740x3_uint8_T(unsigned char result[2184480])
{
  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < 984; idx0++) {
    for (int idx1 = 0; idx1 < 740; idx1++) {
      for (int idx2 = 0; idx2 < 3; idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[(idx0 + 984 * idx1) + 728160 * idx2] = argInit_uint8_T();
      }
    }
  }
}

//
// Arguments    : void
// Return Type  : unsigned char
//
static unsigned char argInit_uint8_T()
{
  return 0U;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_colourBalance()
{
  static unsigned char colourBalancedImage[2184480];
  static unsigned char uv[2184480];

  // Initialize function 'colourBalance' input arguments.
  // Initialize function input argument 'originalImage'.
  // Call the entry-point 'colourBalance'.
  argInit_984x740x3_uint8_T(uv);
  colourBalance(uv, colourBalancedImage);
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
  main_colourBalance();

  // Terminate the application.
  // You do not need to do this more than one time.
  colourBalance_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
