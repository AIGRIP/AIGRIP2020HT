//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  colourSegmentation_types.h
//
//  Code generation for function 'colourSegmentation'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"

// Type Definitions
struct colourSegmentationStackData
{
  struct {
    real_T HSVImage[2184480];
    uint8_T maskPad[731612];
    uint8_T markerPad[731612];
    boolean_T colourSegmentationMask[728160];
    boolean_T mask[728160];
    boolean_T marker[728160];
    boolean_T tmp_data[728160];
    boolean_T b_tmp_data[728160];
    int8_T b_mask[728160];
  } f0;
};

// End of code generation (colourSegmentation_types.h)
