//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  main.cpp
//
//  Code generation for function 'main'
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

// Include files
#include "main.h"
#include "MorphologicalFilters.h"
#include "MorphologicalFilters_terminate.h"
#include "rt_nonfinite.h"

// Function Declarations
static void argInit_984x740_boolean_T(bool result[728160]);
static bool argInit_boolean_T();
static double argInit_real_T();
static void main_MorphologicalFilters();

// Function Definitions
static void argInit_984x740_boolean_T(bool result[728160])
{
  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < 984; idx0++) {
    for (int idx1 = 0; idx1 < 740; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + 984 * idx1] = argInit_boolean_T();
    }
  }
}

static bool argInit_boolean_T()
{
  return false;
}

static double argInit_real_T()
{
  return 0.0;
}

static void main_MorphologicalFilters()
{
  static bool bv[728160];
  static bool segmentationMask[728160];
  double centerOfObjectX_tmp;
  double errorNoImage;

  // Initialize function 'MorphologicalFilters' input arguments.
  // Initialize function input argument 'colourSegmentationMask'.
  centerOfObjectX_tmp = argInit_real_T();

  // Call the entry-point 'MorphologicalFilters'.
  argInit_984x740_boolean_T(bv);
  MorphologicalFilters(bv, centerOfObjectX_tmp, centerOfObjectX_tmp,
                       &errorNoImage, segmentationMask);
}

int main(int, const char * const [])
{
  // The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. 
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_MorphologicalFilters();

  // Terminate the application.
  // You do not need to do this more than one time.
  MorphologicalFilters_terminate();
  return 0;
}

// End of code generation (main.cpp)
