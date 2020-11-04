//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colourSegmentation.cu
//
// GPU Coder version                    : 2.0
// CUDA/C/C++ source code generated on  : 04-Nov-2020 15:12:57
//

// Include Files
#include "colourSegmentation.h"
#include "MWCudaDimUtility.hpp"
#include "MWLaunchParametersUtilities.hpp"

// Type Definitions
struct cell_wrap_7
{
  double f1[9];
};

// Function Declarations
static __global__ void colourSegmentation_kernel1(const unsigned char
  colourBalancedImage[2184480], double Xin[2184480]);
static __global__ void colourSegmentation_kernel10(const bool HSVImage_data
  [728160], bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel11(const double HSVImage[2184480],
  const int i2, const int i, const int HSVImage_size[2], const int b_i, const
  int i1, bool HSVImage_data[728160]);
static __global__ void colourSegmentation_kernel12(const bool HSVImage_data
  [728160], bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel13(const double HSVImage[2184480],
  const int i2, const int i, const int HSVImage_size[2], const int b_i, const
  int i1, bool HSVImage_data[728160]);
static __global__ void colourSegmentation_kernel14(const bool HSVImage_data
  [728160], bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel15(const double HSVImage[2184480],
  const int i2, const int i, const int HSVImage_size[2], const int b_i, const
  int i1, bool HSVImage_data[728160]);
static __global__ void colourSegmentation_kernel16(const bool HSVImage_data
  [728160], bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel17(const double HSVImage[2184480],
  const int i2, const int i, const int HSVImage_size[2], const int b_i, const
  int i1, bool HSVImage_data[728160]);
static __global__ void colourSegmentation_kernel18(const bool HSVImage_data
  [728160], bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel19(const double HSVImage[2184480],
  const int i2, const int i, const int HSVImage_size[2], const int b_i, const
  int i1, bool HSVImage_data[728160]);
static __global__ void colourSegmentation_kernel2(const double Xin[2184480],
  double HSVImage[2184480]);
static __global__ void colourSegmentation_kernel20(const bool HSVImage_data
  [728160], bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel21(const double HSVImage[2184480],
  const int i2, const int i, const int HSVImage_size[2], const int b_i, const
  int i1, bool HSVImage_data[728160]);
static __global__ void colourSegmentation_kernel22(const bool HSVImage_data
  [728160], bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel23(const bool centerColourMask
  [23409], cell_wrap_7 outputs[1]);
static __global__ void colourSegmentation_kernel24(const double HSVImage[2184480],
  bool SegmentationMask[728160]);
static __global__ void colourSegmentation_kernel25(const double HSVImage[2184480],
  bool SegmentationMask[728160]);
static __global__ void colourSegmentation_kernel26(const double HSVImage[2184480],
  bool SegmentationMask[728160]);
static __global__ void colourSegmentation_kernel27(const double HSVImage[2184480],
  bool SegmentationMask[728160]);
static __global__ void colourSegmentation_kernel28(const double HSVImage[2184480],
  bool SegmentationMask[728160]);
static __global__ void colourSegmentation_kernel29(const double HSVImage[2184480],
  bool SegmentationMask[728160]);
static __global__ void colourSegmentation_kernel3(double HSVImage[2184480]);
static __global__ void colourSegmentation_kernel30(const double HSVImage[2184480],
  bool SegmentationMask[728160]);
static __global__ void colourSegmentation_kernel31(const double HSVImage[2184480],
  bool SegmentationMask[728160]);
static __global__ void colourSegmentation_kernel32(const double HSVImage[2184480],
  bool SegmentationMask[728160]);
static __global__ void colourSegmentation_kernel4(bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel5(const double HSVImage[2184480],
  const int i2, const int i, const int HSVImage_size[2], const int b_i, const
  int i1, bool HSVImage_data[728160]);
static __global__ void colourSegmentation_kernel6(const bool HSVImage_data
  [728160], bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel7(const double HSVImage[2184480],
  const int i2, const int i, const int HSVImage_size[2], const int b_i, const
  int i1, bool HSVImage_data[728160]);
static __global__ void colourSegmentation_kernel8(const bool HSVImage_data
  [728160], bool centerColourMask[23409]);
static __global__ void colourSegmentation_kernel9(const double HSVImage[2184480],
  const int i2, const int i, const int HSVImage_size[2], const int b_i, const
  int i1, bool HSVImage_data[728160]);

// Function Definitions
//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const unsigned char colourBalancedImage[2184480]
//                double Xin[2184480]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel1(
  const unsigned char colourBalancedImage[2184480], double Xin[2184480])
{
  int ix;
  ix = static_cast<int>(mwGetGlobalThreadIndex());
  if (ix < 2184480) {
    // Input:
    // colourBalancedImage = RGB image 984x740x3
    // centerOfObjectX = Objects center postion in the x-axis
    // centerOfObjectY = Objects center postion in the y-axis
    // Output:
    // SegmentationMask = bitmask of the segmented object
    // Transform the Image into the HSV colour space
    Xin[ix] = static_cast<double>(colourBalancedImage[ix]) / 255.0;
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool HSVImage_data[728160]
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel10(
  const bool HSVImage_data[728160], bool centerColourMask[23409])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 51UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        51UL);
  if ((static_cast<int>(ix < 51)) && (static_cast<int>(xpageoffset < 51))) {
    centerColourMask[(xpageoffset + 51 * ix) + 5202] = HSVImage_data[xpageoffset
      + 51 * ix];
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                const int i2
//                const int i
//                const int HSVImage_size[2]
//                const int b_i
//                const int i1
//                bool HSVImage_data[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(1024, 1) void colourSegmentation_kernel11(
  const double HSVImage[2184480], const int i2, const int i, const int
  HSVImage_size[2], const int b_i, const int i1, bool HSVImage_data[728160])
{
  unsigned long idx;
  long loopEnd;
  unsigned long threadId;
  unsigned long threadStride;
  threadId = mwGetGlobalThreadIndex();
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<long>(b_i) + 1L) * (static_cast<long>(i1) + 1L) - 1L;
  for (idx = threadId; idx <= static_cast<unsigned long>(loopEnd); idx +=
       threadStride) {
    int ix;
    int xpageoffset;
    xpageoffset = static_cast<int>(idx % (static_cast<unsigned long>(b_i) + 1UL));
    ix = static_cast<int>((idx - static_cast<unsigned long>(xpageoffset)) / (
      static_cast<unsigned long>(b_i) + 1UL));
    HSVImage_data[xpageoffset + HSVImage_size[0] * ix] = ((static_cast<int>((
      static_cast<int>((static_cast<int>((static_cast<int>(HSVImage[(i +
      xpageoffset) + 984 * (i2 + ix)] > 70.0)) && (static_cast<int>(HSVImage[(i
      + xpageoffset) + 984 * (i2 + ix)] < 155.0)))) || (static_cast<int>
      (HSVImage[(i + xpageoffset) + 984 * (i2 + ix)] == 70.0)))) && (
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 728160] >
                       0.2)))) && (static_cast<int>(HSVImage[((i + xpageoffset)
      + 984 * (i2 + ix)) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool HSVImage_data[728160]
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel12(
  const bool HSVImage_data[728160], bool centerColourMask[23409])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 51UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        51UL);
  if ((static_cast<int>(ix < 51)) && (static_cast<int>(xpageoffset < 51))) {
    centerColourMask[(xpageoffset + 51 * ix) + 7803] = HSVImage_data[xpageoffset
      + 51 * ix];
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                const int i2
//                const int i
//                const int HSVImage_size[2]
//                const int b_i
//                const int i1
//                bool HSVImage_data[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(1024, 1) void colourSegmentation_kernel13(
  const double HSVImage[2184480], const int i2, const int i, const int
  HSVImage_size[2], const int b_i, const int i1, bool HSVImage_data[728160])
{
  unsigned long idx;
  long loopEnd;
  unsigned long threadId;
  unsigned long threadStride;
  threadId = mwGetGlobalThreadIndex();
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<long>(b_i) + 1L) * (static_cast<long>(i1) + 1L) - 1L;
  for (idx = threadId; idx <= static_cast<unsigned long>(loopEnd); idx +=
       threadStride) {
    int ix;
    int xpageoffset;
    xpageoffset = static_cast<int>(idx % (static_cast<unsigned long>(b_i) + 1UL));
    ix = static_cast<int>((idx - static_cast<unsigned long>(xpageoffset)) / (
      static_cast<unsigned long>(b_i) + 1UL));
    HSVImage_data[xpageoffset + HSVImage_size[0] * ix] = ((static_cast<int>((
      static_cast<int>((static_cast<int>((static_cast<int>(HSVImage[(i +
      xpageoffset) + 984 * (i2 + ix)] > 155.0)) && (static_cast<int>(HSVImage[(i
      + xpageoffset) + 984 * (i2 + ix)] < 205.0)))) || (static_cast<int>
      (HSVImage[(i + xpageoffset) + 984 * (i2 + ix)] == 155.0)))) && (
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 728160] >
                       0.2)))) && (static_cast<int>(HSVImage[((i + xpageoffset)
      + 984 * (i2 + ix)) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool HSVImage_data[728160]
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel14(
  const bool HSVImage_data[728160], bool centerColourMask[23409])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 51UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        51UL);
  if ((static_cast<int>(ix < 51)) && (static_cast<int>(xpageoffset < 51))) {
    centerColourMask[(xpageoffset + 51 * ix) + 10404] =
      HSVImage_data[xpageoffset + 51 * ix];
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                const int i2
//                const int i
//                const int HSVImage_size[2]
//                const int b_i
//                const int i1
//                bool HSVImage_data[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(1024, 1) void colourSegmentation_kernel15(
  const double HSVImage[2184480], const int i2, const int i, const int
  HSVImage_size[2], const int b_i, const int i1, bool HSVImage_data[728160])
{
  unsigned long idx;
  long loopEnd;
  unsigned long threadId;
  unsigned long threadStride;
  threadId = mwGetGlobalThreadIndex();
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<long>(b_i) + 1L) * (static_cast<long>(i1) + 1L) - 1L;
  for (idx = threadId; idx <= static_cast<unsigned long>(loopEnd); idx +=
       threadStride) {
    int ix;
    int xpageoffset;
    xpageoffset = static_cast<int>(idx % (static_cast<unsigned long>(b_i) + 1UL));
    ix = static_cast<int>((idx - static_cast<unsigned long>(xpageoffset)) / (
      static_cast<unsigned long>(b_i) + 1UL));
    HSVImage_data[xpageoffset + HSVImage_size[0] * ix] = ((static_cast<int>((
      static_cast<int>((static_cast<int>((static_cast<int>(HSVImage[(i +
      xpageoffset) + 984 * (i2 + ix)] > 205.0)) && (static_cast<int>(HSVImage[(i
      + xpageoffset) + 984 * (i2 + ix)] < 260.0)))) || (static_cast<int>
      (HSVImage[(i + xpageoffset) + 984 * (i2 + ix)] == 205.0)))) && (
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 728160] >
                       0.2)))) && (static_cast<int>(HSVImage[((i + xpageoffset)
      + 984 * (i2 + ix)) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool HSVImage_data[728160]
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel16(
  const bool HSVImage_data[728160], bool centerColourMask[23409])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 51UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        51UL);
  if ((static_cast<int>(ix < 51)) && (static_cast<int>(xpageoffset < 51))) {
    centerColourMask[(xpageoffset + 51 * ix) + 13005] =
      HSVImage_data[xpageoffset + 51 * ix];
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                const int i2
//                const int i
//                const int HSVImage_size[2]
//                const int b_i
//                const int i1
//                bool HSVImage_data[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(1024, 1) void colourSegmentation_kernel17(
  const double HSVImage[2184480], const int i2, const int i, const int
  HSVImage_size[2], const int b_i, const int i1, bool HSVImage_data[728160])
{
  unsigned long idx;
  long loopEnd;
  unsigned long threadId;
  unsigned long threadStride;
  threadId = mwGetGlobalThreadIndex();
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<long>(b_i) + 1L) * (static_cast<long>(i1) + 1L) - 1L;
  for (idx = threadId; idx <= static_cast<unsigned long>(loopEnd); idx +=
       threadStride) {
    int ix;
    int xpageoffset;
    xpageoffset = static_cast<int>(idx % (static_cast<unsigned long>(b_i) + 1UL));
    ix = static_cast<int>((idx - static_cast<unsigned long>(xpageoffset)) / (
      static_cast<unsigned long>(b_i) + 1UL));
    HSVImage_data[xpageoffset + HSVImage_size[0] * ix] = ((static_cast<int>((
      static_cast<int>((static_cast<int>((static_cast<int>(HSVImage[(i +
      xpageoffset) + 984 * (i2 + ix)] > 260.0)) && (static_cast<int>(HSVImage[(i
      + xpageoffset) + 984 * (i2 + ix)] < 315.0)))) || (static_cast<int>
      (HSVImage[(i + xpageoffset) + 984 * (i2 + ix)] == 260.0)))) && (
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 728160] >
                       0.2)))) && (static_cast<int>(HSVImage[((i + xpageoffset)
      + 984 * (i2 + ix)) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool HSVImage_data[728160]
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel18(
  const bool HSVImage_data[728160], bool centerColourMask[23409])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 51UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        51UL);
  if ((static_cast<int>(ix < 51)) && (static_cast<int>(xpageoffset < 51))) {
    centerColourMask[(xpageoffset + 51 * ix) + 15606] =
      HSVImage_data[xpageoffset + 51 * ix];
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                const int i2
//                const int i
//                const int HSVImage_size[2]
//                const int b_i
//                const int i1
//                bool HSVImage_data[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(1024, 1) void colourSegmentation_kernel19(
  const double HSVImage[2184480], const int i2, const int i, const int
  HSVImage_size[2], const int b_i, const int i1, bool HSVImage_data[728160])
{
  unsigned long idx;
  long loopEnd;
  unsigned long threadId;
  unsigned long threadStride;
  threadId = mwGetGlobalThreadIndex();
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<long>(b_i) + 1L) * (static_cast<long>(i1) + 1L) - 1L;
  for (idx = threadId; idx <= static_cast<unsigned long>(loopEnd); idx +=
       threadStride) {
    int ix;
    int xpageoffset;
    xpageoffset = static_cast<int>(idx % (static_cast<unsigned long>(b_i) + 1UL));
    ix = static_cast<int>((idx - static_cast<unsigned long>(xpageoffset)) / (
      static_cast<unsigned long>(b_i) + 1UL));
    HSVImage_data[xpageoffset + HSVImage_size[0] * ix] = ((static_cast<int>((
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 1456320]
                       > 0.6)) || (static_cast<int>(HSVImage[((i + xpageoffset)
      + 984 * (i2 + ix)) + 1456320] == 0.6)))) && (static_cast<int>((
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 728160] <
                       0.2)) || (static_cast<int>(HSVImage[((i + xpageoffset) +
      984 * (i2 + ix)) + 728160] == 0.2)))));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double Xin[2184480]
//                double HSVImage[2184480]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel2(
  const double Xin[2184480], double HSVImage[2184480])
{
  double varargin_1[3];
  double h;
  double tmp;
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    double d1;
    double d2;
    double delta;
    double v;
    int i;
    d = Xin[xpageoffset + 984 * ix];
    varargin_1[0] = d;
    d1 = Xin[(xpageoffset + 984 * ix) + 728160];
    varargin_1[1] = d1;
    d2 = Xin[(xpageoffset + 984 * ix) + 1456320];
    varargin_1[2] = d2;
    v = d;
    for (i = 0; i < 2; i++) {
      if (v < varargin_1[i + 1]) {
        v = varargin_1[i + 1];
      }
    }

    varargin_1[0] = d;
    varargin_1[1] = d1;
    varargin_1[2] = d2;
    tmp = d;
    for (i = 0; i < 2; i++) {
      if (tmp > varargin_1[i + 1]) {
        tmp = varargin_1[i + 1];
      }
    }

    delta = v - tmp;
    tmp = delta;
    if (delta == 0.0) {
      tmp = 1.0;
    }

    h = 0.0;
    if (d == v) {
      h = (d1 - d2) / tmp;
    }

    if (d1 == v) {
      h = (d2 - d) / tmp + 2.0;
    }

    if (d2 == v) {
      h = (d - d1) / tmp + 4.0;
    }

    h /= 6.0;
    if (h < 0.0) {
      h++;
    }

    tmp /= v;
    if (delta == 0.0) {
      h = 0.0;
      tmp = 0.0;
    }

    if (!static_cast<int>(v != 0.0)) {
      tmp = 0.0;
    }

    HSVImage[xpageoffset + 984 * ix] = h;
    HSVImage[(xpageoffset + 984 * ix) + 728160] = tmp;
    HSVImage[(xpageoffset + 984 * ix) + 1456320] = v;
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool HSVImage_data[728160]
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel20(
  const bool HSVImage_data[728160], bool centerColourMask[23409])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 51UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        51UL);
  if ((static_cast<int>(ix < 51)) && (static_cast<int>(xpageoffset < 51))) {
    centerColourMask[(xpageoffset + 51 * ix) + 18207] =
      HSVImage_data[xpageoffset + 51 * ix];
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                const int i2
//                const int i
//                const int HSVImage_size[2]
//                const int b_i
//                const int i1
//                bool HSVImage_data[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(1024, 1) void colourSegmentation_kernel21(
  const double HSVImage[2184480], const int i2, const int i, const int
  HSVImage_size[2], const int b_i, const int i1, bool HSVImage_data[728160])
{
  unsigned long idx;
  long loopEnd;
  unsigned long threadId;
  unsigned long threadStride;
  threadId = mwGetGlobalThreadIndex();
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<long>(b_i) + 1L) * (static_cast<long>(i1) + 1L) - 1L;
  for (idx = threadId; idx <= static_cast<unsigned long>(loopEnd); idx +=
       threadStride) {
    int ix;
    int xpageoffset;
    xpageoffset = static_cast<int>(idx % (static_cast<unsigned long>(b_i) + 1UL));
    ix = static_cast<int>((idx - static_cast<unsigned long>(xpageoffset)) / (
      static_cast<unsigned long>(b_i) + 1UL));
    HSVImage_data[xpageoffset + HSVImage_size[0] * ix] = ((static_cast<int>((
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 1456320]
                       < 0.3)) || (static_cast<int>(HSVImage[((i + xpageoffset)
      + 984 * (i2 + ix)) + 1456320] == 0.3)))) || (static_cast<int>((
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 1456320]
                       < 0.6)) && (static_cast<int>((static_cast<int>(HSVImage
      [((i + xpageoffset) + 984 * (i2 + ix)) + 728160] < 0.2)) || (static_cast<
      int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 728160] == 0.2)))))));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool HSVImage_data[728160]
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel22(
  const bool HSVImage_data[728160], bool centerColourMask[23409])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 51UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        51UL);
  if ((static_cast<int>(ix < 51)) && (static_cast<int>(xpageoffset < 51))) {
    centerColourMask[(xpageoffset + 51 * ix) + 20808] =
      HSVImage_data[xpageoffset + 51 * ix];
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool centerColourMask[23409]
//                cell_wrap_7 outputs[1]
// Return Type  : void
//
static __global__ __launch_bounds__(32, 1) void colourSegmentation_kernel23(
  const bool centerColourMask[23409], cell_wrap_7 outputs[1])
{
  double d;
  int i;
  i = static_cast<int>(mwGetGlobalThreadIndex());
  if (i < 9) {
    int xpageoffset;

    //  Sum up all the masks and then determine which mask has the most pixels
    xpageoffset = i * 2601;
    d = static_cast<double>(centerColourMask[xpageoffset]);
    for (int ix = 0; ix < 2600; ix++) {
      d += static_cast<double>(centerColourMask[(xpageoffset + ix) + 1]);
    }

    outputs[0].f1[i] = d;
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                bool SegmentationMask[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel24(
  const double HSVImage[2184480], bool SegmentationMask[728160])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    double d1;
    d = HSVImage[(xpageoffset + 984 * ix) + 1456320];
    d1 = HSVImage[(xpageoffset + 984 * ix) + 728160];
    SegmentationMask[xpageoffset + 984 * ix] = ((static_cast<int>((static_cast<
      int>(d < 0.3)) || (static_cast<int>(d == 0.3)))) || (static_cast<int>((
      static_cast<int>(d < 0.6)) && (static_cast<int>((static_cast<int>(d1 < 0.2))
      || (static_cast<int>(d1 == 0.2)))))));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                bool SegmentationMask[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel25(
  const double HSVImage[2184480], bool SegmentationMask[728160])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    double d1;
    d = HSVImage[(xpageoffset + 984 * ix) + 1456320];
    d1 = HSVImage[(xpageoffset + 984 * ix) + 728160];
    SegmentationMask[xpageoffset + 984 * ix] = ((static_cast<int>((static_cast<
      int>(d > 0.6)) || (static_cast<int>(d == 0.6)))) && (static_cast<int>((
      static_cast<int>(d1 < 0.2)) || (static_cast<int>(d1 == 0.2)))));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                bool SegmentationMask[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel26(
  const double HSVImage[2184480], bool SegmentationMask[728160])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    d = HSVImage[xpageoffset + 984 * ix];
    SegmentationMask[xpageoffset + 984 * ix] = ((static_cast<int>((static_cast<
      int>((static_cast<int>((static_cast<int>(d > 260.0)) && (static_cast<int>
      (d < 315.0)))) || (static_cast<int>(d == 260.0)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 728160] > 0.2)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                bool SegmentationMask[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel27(
  const double HSVImage[2184480], bool SegmentationMask[728160])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    d = HSVImage[xpageoffset + 984 * ix];
    SegmentationMask[xpageoffset + 984 * ix] = ((static_cast<int>((static_cast<
      int>((static_cast<int>((static_cast<int>(d > 205.0)) && (static_cast<int>
      (d < 260.0)))) || (static_cast<int>(d == 205.0)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 728160] > 0.2)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                bool SegmentationMask[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel28(
  const double HSVImage[2184480], bool SegmentationMask[728160])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    d = HSVImage[xpageoffset + 984 * ix];
    SegmentationMask[xpageoffset + 984 * ix] = ((static_cast<int>((static_cast<
      int>((static_cast<int>((static_cast<int>(d > 155.0)) && (static_cast<int>
      (d < 205.0)))) || (static_cast<int>(d == 155.0)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 728160] > 0.2)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                bool SegmentationMask[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel29(
  const double HSVImage[2184480], bool SegmentationMask[728160])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    d = HSVImage[xpageoffset + 984 * ix];
    SegmentationMask[xpageoffset + 984 * ix] = ((static_cast<int>((static_cast<
      int>((static_cast<int>((static_cast<int>(d > 70.0)) && (static_cast<int>(d
      < 155.0)))) || (static_cast<int>(d == 70.0)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 728160] > 0.2)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                double HSVImage[2184480]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel3
  (double HSVImage[2184480])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    HSVImage[xpageoffset + 984 * ix] *= 360.0;
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                bool SegmentationMask[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel30(
  const double HSVImage[2184480], bool SegmentationMask[728160])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    d = HSVImage[xpageoffset + 984 * ix];
    SegmentationMask[xpageoffset + 984 * ix] = ((static_cast<int>((static_cast<
      int>((static_cast<int>((static_cast<int>(d > 50.0)) && (static_cast<int>(d
      < 70.0)))) || (static_cast<int>(d == 50.0)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 728160] > 0.2)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                bool SegmentationMask[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel31(
  const double HSVImage[2184480], bool SegmentationMask[728160])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    d = HSVImage[xpageoffset + 984 * ix];
    SegmentationMask[xpageoffset + 984 * ix] = ((static_cast<int>((static_cast<
      int>((static_cast<int>((static_cast<int>(d > 15.0)) && (static_cast<int>(d
      < 50.0)))) || (static_cast<int>(d == 15.0)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 728160] > 0.2)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                bool SegmentationMask[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel32(
  const double HSVImage[2184480], bool SegmentationMask[728160])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 984UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        984UL);
  if ((static_cast<int>(ix < 740)) && (static_cast<int>(xpageoffset < 984))) {
    double d;
    d = HSVImage[xpageoffset + 984 * ix];
    SegmentationMask[xpageoffset + 984 * ix] = ((static_cast<int>((static_cast<
      int>((static_cast<int>((static_cast<int>(d < 15.0)) || (static_cast<int>(d
      == 315.0)))) || (static_cast<int>(d > 315.0)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 728160] > 0.2)))) && (static_cast<int>
      (HSVImage[(xpageoffset + 984 * ix) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel4(bool
  centerColourMask[23409])
{
  int ix;
  ix = static_cast<int>(mwGetGlobalThreadIndex());
  if (ix < 23409) {
    centerColourMask[ix] = false;
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                const int i2
//                const int i
//                const int HSVImage_size[2]
//                const int b_i
//                const int i1
//                bool HSVImage_data[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(1024, 1) void colourSegmentation_kernel5(
  const double HSVImage[2184480], const int i2, const int i, const int
  HSVImage_size[2], const int b_i, const int i1, bool HSVImage_data[728160])
{
  unsigned long idx;
  long loopEnd;
  unsigned long threadId;
  unsigned long threadStride;
  threadId = mwGetGlobalThreadIndex();
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<long>(b_i) + 1L) * (static_cast<long>(i1) + 1L) - 1L;
  for (idx = threadId; idx <= static_cast<unsigned long>(loopEnd); idx +=
       threadStride) {
    int ix;
    int xpageoffset;
    xpageoffset = static_cast<int>(idx % (static_cast<unsigned long>(b_i) + 1UL));
    ix = static_cast<int>((idx - static_cast<unsigned long>(xpageoffset)) / (
      static_cast<unsigned long>(b_i) + 1UL));
    HSVImage_data[xpageoffset + HSVImage_size[0] * ix] = ((static_cast<int>((
      static_cast<int>((static_cast<int>((static_cast<int>(HSVImage[(i +
      xpageoffset) + 984 * (i2 + ix)] < 15.0)) || (static_cast<int>(HSVImage[(i
      + xpageoffset) + 984 * (i2 + ix)] == 315.0)))) || (static_cast<int>
      (HSVImage[(i + xpageoffset) + 984 * (i2 + ix)] > 315.0)))) && (
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 728160] >
                       0.2)))) && (static_cast<int>(HSVImage[((i + xpageoffset)
      + 984 * (i2 + ix)) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool HSVImage_data[728160]
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel6(
  const bool HSVImage_data[728160], bool centerColourMask[23409])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 51UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        51UL);
  if ((static_cast<int>(ix < 51)) && (static_cast<int>(xpageoffset < 51))) {
    centerColourMask[xpageoffset + 51 * ix] = HSVImage_data[xpageoffset + 51 *
      ix];
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                const int i2
//                const int i
//                const int HSVImage_size[2]
//                const int b_i
//                const int i1
//                bool HSVImage_data[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(1024, 1) void colourSegmentation_kernel7(
  const double HSVImage[2184480], const int i2, const int i, const int
  HSVImage_size[2], const int b_i, const int i1, bool HSVImage_data[728160])
{
  unsigned long idx;
  long loopEnd;
  unsigned long threadId;
  unsigned long threadStride;
  threadId = mwGetGlobalThreadIndex();
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<long>(b_i) + 1L) * (static_cast<long>(i1) + 1L) - 1L;
  for (idx = threadId; idx <= static_cast<unsigned long>(loopEnd); idx +=
       threadStride) {
    int ix;
    int xpageoffset;
    xpageoffset = static_cast<int>(idx % (static_cast<unsigned long>(b_i) + 1UL));
    ix = static_cast<int>((idx - static_cast<unsigned long>(xpageoffset)) / (
      static_cast<unsigned long>(b_i) + 1UL));
    HSVImage_data[xpageoffset + HSVImage_size[0] * ix] = ((static_cast<int>((
      static_cast<int>((static_cast<int>((static_cast<int>(HSVImage[(i +
      xpageoffset) + 984 * (i2 + ix)] > 15.0)) && (static_cast<int>(HSVImage[(i
      + xpageoffset) + 984 * (i2 + ix)] < 50.0)))) || (static_cast<int>
      (HSVImage[(i + xpageoffset) + 984 * (i2 + ix)] == 15.0)))) && (
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 728160] >
                       0.2)))) && (static_cast<int>(HSVImage[((i + xpageoffset)
      + 984 * (i2 + ix)) + 1456320] > 0.3)));
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const bool HSVImage_data[728160]
//                bool centerColourMask[23409]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourSegmentation_kernel8(
  const bool HSVImage_data[728160], bool centerColourMask[23409])
{
  unsigned long threadId;
  int ix;
  int xpageoffset;
  threadId = mwGetGlobalThreadIndex();
  xpageoffset = static_cast<int>(threadId % 51UL);
  ix = static_cast<int>((threadId - static_cast<unsigned long>(xpageoffset)) /
                        51UL);
  if ((static_cast<int>(ix < 51)) && (static_cast<int>(xpageoffset < 51))) {
    centerColourMask[(xpageoffset + 51 * ix) + 2601] = HSVImage_data[xpageoffset
      + 51 * ix];
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double HSVImage[2184480]
//                const int i2
//                const int i
//                const int HSVImage_size[2]
//                const int b_i
//                const int i1
//                bool HSVImage_data[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(1024, 1) void colourSegmentation_kernel9(
  const double HSVImage[2184480], const int i2, const int i, const int
  HSVImage_size[2], const int b_i, const int i1, bool HSVImage_data[728160])
{
  unsigned long idx;
  long loopEnd;
  unsigned long threadId;
  unsigned long threadStride;
  threadId = mwGetGlobalThreadIndex();
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = (static_cast<long>(b_i) + 1L) * (static_cast<long>(i1) + 1L) - 1L;
  for (idx = threadId; idx <= static_cast<unsigned long>(loopEnd); idx +=
       threadStride) {
    int ix;
    int xpageoffset;
    xpageoffset = static_cast<int>(idx % (static_cast<unsigned long>(b_i) + 1UL));
    ix = static_cast<int>((idx - static_cast<unsigned long>(xpageoffset)) / (
      static_cast<unsigned long>(b_i) + 1UL));
    HSVImage_data[xpageoffset + HSVImage_size[0] * ix] = ((static_cast<int>((
      static_cast<int>((static_cast<int>((static_cast<int>(HSVImage[(i +
      xpageoffset) + 984 * (i2 + ix)] > 50.0)) && (static_cast<int>(HSVImage[(i
      + xpageoffset) + 984 * (i2 + ix)] < 70.0)))) || (static_cast<int>
      (HSVImage[(i + xpageoffset) + 984 * (i2 + ix)] == 50.0)))) && (
      static_cast<int>(HSVImage[((i + xpageoffset) + 984 * (i2 + ix)) + 728160] >
                       0.2)))) && (static_cast<int>(HSVImage[((i + xpageoffset)
      + 984 * (i2 + ix)) + 1456320] > 0.3)));
  }
}

//
// The function takes in a image and a rough postion of the object in the
// image that should be segmented. and it outputs a a bitmask of the the
// object.
// Arguments    : const unsigned char colourBalancedImage[2184480]
//                double centerOfObjectX
//                double centerOfObjectY
//                bool SegmentationMask[728160]
// Return Type  : void
//
void colourSegmentation(const unsigned char colourBalancedImage[2184480], double
  centerOfObjectX, double centerOfObjectY, bool SegmentationMask[728160])
{
  cell_wrap_7 outputs[1];
  cell_wrap_7 (*gpu_outputs)[1];
  dim3 b_block;
  dim3 b_grid;
  dim3 block;
  dim3 c_block;
  dim3 c_grid;
  dim3 d_block;
  dim3 d_grid;
  dim3 e_block;
  dim3 e_grid;
  dim3 f_block;
  dim3 f_grid;
  dim3 g_block;
  dim3 g_grid;
  dim3 grid;
  dim3 h_block;
  dim3 h_grid;
  dim3 i_block;
  dim3 i_grid;
  double (*gpu_HSVImage)[2184480];
  double (*gpu_Xin)[2184480];
  double ex;
  int HSVImage_size[2];
  int b_HSVImage_size[2];
  int c_HSVImage_size[2];
  int d_HSVImage_size[2];
  int e_HSVImage_size[2];
  int f_HSVImage_size[2];
  int g_HSVImage_size[2];
  int h_HSVImage_size[2];
  int i_HSVImage_size[2];
  int (*b_gpu_HSVImage_size)[2];
  int (*c_gpu_HSVImage_size)[2];
  int (*d_gpu_HSVImage_size)[2];
  int (*e_gpu_HSVImage_size)[2];
  int (*f_gpu_HSVImage_size)[2];
  int (*g_gpu_HSVImage_size)[2];
  int (*gpu_HSVImage_size)[2];
  int (*h_gpu_HSVImage_size)[2];
  int (*i_gpu_HSVImage_size)[2];
  int b_i;
  int b_i1;
  int i;
  int i1;
  int i2;
  int i3;
  unsigned char (*gpu_colourBalancedImage)[2184480];
  bool (*gpu_HSVImage_data)[728160];
  bool (*gpu_SegmentationMask)[728160];
  bool (*gpu_centerColourMask)[23409];
  bool validLaunchParams;
  cudaMalloc(&gpu_SegmentationMask, 728160UL);
  cudaMalloc(&gpu_outputs, 72UL);
  cudaMalloc(&i_gpu_HSVImage_size, 8UL);
  cudaMalloc(&h_gpu_HSVImage_size, 8UL);
  cudaMalloc(&g_gpu_HSVImage_size, 8UL);
  cudaMalloc(&f_gpu_HSVImage_size, 8UL);
  cudaMalloc(&e_gpu_HSVImage_size, 8UL);
  cudaMalloc(&d_gpu_HSVImage_size, 8UL);
  cudaMalloc(&c_gpu_HSVImage_size, 8UL);
  cudaMalloc(&b_gpu_HSVImage_size, 8UL);
  cudaMalloc(&gpu_HSVImage_data, 728160UL);
  cudaMalloc(&gpu_centerColourMask, 23409UL);
  cudaMalloc(&gpu_HSVImage_size, 8UL);
  cudaMalloc(&gpu_HSVImage, 17475840UL);
  cudaMalloc(&gpu_Xin, 17475840UL);
  cudaMalloc(&gpu_colourBalancedImage, 2184480UL);

  // Input:
  // colourBalancedImage = RGB image 984x740x3
  // centerOfObjectX = Objects center postion in the x-axis
  // centerOfObjectY = Objects center postion in the y-axis
  // Output:
  // SegmentationMask = bitmask of the segmented object
  // Transform the Image into the HSV colour space
  cudaMemcpy(gpu_colourBalancedImage, (void *)&colourBalancedImage[0], 2184480UL,
             cudaMemcpyHostToDevice);
  colourSegmentation_kernel1<<<dim3(4267U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_colourBalancedImage, *gpu_Xin);
  colourSegmentation_kernel2<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_Xin, *gpu_HSVImage);

  // Standardize the H-values from 0-1 to 0-360
  colourSegmentation_kernel3<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage);

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

  colourSegmentation_kernel4<<<dim3(46U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_centerColourMask);

  // Make mask in the square for every 9 colours.
  // Calcualte which pixels are red
  b_i = (i1 - i) - 1;
  b_i1 = (i3 - i2) - 1;
  HSVImage_size[0] = b_i + 1;
  HSVImage_size[1] = b_i1 + 1;
  validLaunchParams = mwGetLaunchParameters(static_cast<double>((b_i + 1L) *
    (b_i1 + 1L)), &grid, &block, 1024U, 65535U);
  if (validLaunchParams) {
    cudaMemcpy(gpu_HSVImage_size, &HSVImage_size[0], 8UL, cudaMemcpyHostToDevice);
    colourSegmentation_kernel5<<<grid, block>>>(*gpu_HSVImage, i2, i,
      *gpu_HSVImage_size, b_i, b_i1, *gpu_HSVImage_data);
  }

  colourSegmentation_kernel6<<<dim3(6U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage_data, *gpu_centerColourMask);

  // Calcualte which pixels are orange
  b_i = (i1 - i) - 1;
  b_i1 = (i3 - i2) - 1;
  b_HSVImage_size[0] = b_i + 1;
  b_HSVImage_size[1] = b_i1 + 1;
  validLaunchParams = mwGetLaunchParameters(static_cast<double>((b_i + 1L) *
    (b_i1 + 1L)), &b_grid, &b_block, 1024U, 65535U);
  if (validLaunchParams) {
    cudaMemcpy(b_gpu_HSVImage_size, &b_HSVImage_size[0], 8UL,
               cudaMemcpyHostToDevice);
    colourSegmentation_kernel7<<<b_grid, b_block>>>(*gpu_HSVImage, i2, i,
      *b_gpu_HSVImage_size, b_i, b_i1, *gpu_HSVImage_data);
  }

  colourSegmentation_kernel8<<<dim3(6U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage_data, *gpu_centerColourMask);

  // Calcualte which pixels are yellow
  b_i = (i1 - i) - 1;
  b_i1 = (i3 - i2) - 1;
  c_HSVImage_size[0] = b_i + 1;
  c_HSVImage_size[1] = b_i1 + 1;
  validLaunchParams = mwGetLaunchParameters(static_cast<double>((b_i + 1L) *
    (b_i1 + 1L)), &c_grid, &c_block, 1024U, 65535U);
  if (validLaunchParams) {
    cudaMemcpy(c_gpu_HSVImage_size, &c_HSVImage_size[0], 8UL,
               cudaMemcpyHostToDevice);
    colourSegmentation_kernel9<<<c_grid, c_block>>>(*gpu_HSVImage, i2, i,
      *c_gpu_HSVImage_size, b_i, b_i1, *gpu_HSVImage_data);
  }

  colourSegmentation_kernel10<<<dim3(6U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage_data, *gpu_centerColourMask);

  // Calcualte which pixels are green
  b_i = (i1 - i) - 1;
  b_i1 = (i3 - i2) - 1;
  d_HSVImage_size[0] = b_i + 1;
  d_HSVImage_size[1] = b_i1 + 1;
  validLaunchParams = mwGetLaunchParameters(static_cast<double>((b_i + 1L) *
    (b_i1 + 1L)), &d_grid, &d_block, 1024U, 65535U);
  if (validLaunchParams) {
    cudaMemcpy(d_gpu_HSVImage_size, &d_HSVImage_size[0], 8UL,
               cudaMemcpyHostToDevice);
    colourSegmentation_kernel11<<<d_grid, d_block>>>(*gpu_HSVImage, i2, i,
      *d_gpu_HSVImage_size, b_i, b_i1, *gpu_HSVImage_data);
  }

  colourSegmentation_kernel12<<<dim3(6U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage_data, *gpu_centerColourMask);

  // Calcualte which pixels are cyan
  b_i = (i1 - i) - 1;
  b_i1 = (i3 - i2) - 1;
  e_HSVImage_size[0] = b_i + 1;
  e_HSVImage_size[1] = b_i1 + 1;
  validLaunchParams = mwGetLaunchParameters(static_cast<double>((b_i + 1L) *
    (b_i1 + 1L)), &e_grid, &e_block, 1024U, 65535U);
  if (validLaunchParams) {
    cudaMemcpy(e_gpu_HSVImage_size, &e_HSVImage_size[0], 8UL,
               cudaMemcpyHostToDevice);
    colourSegmentation_kernel13<<<e_grid, e_block>>>(*gpu_HSVImage, i2, i,
      *e_gpu_HSVImage_size, b_i, b_i1, *gpu_HSVImage_data);
  }

  colourSegmentation_kernel14<<<dim3(6U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage_data, *gpu_centerColourMask);

  // Calcualte which pixels are blue
  b_i = (i1 - i) - 1;
  b_i1 = (i3 - i2) - 1;
  f_HSVImage_size[0] = b_i + 1;
  f_HSVImage_size[1] = b_i1 + 1;
  validLaunchParams = mwGetLaunchParameters(static_cast<double>((b_i + 1L) *
    (b_i1 + 1L)), &f_grid, &f_block, 1024U, 65535U);
  if (validLaunchParams) {
    cudaMemcpy(f_gpu_HSVImage_size, &f_HSVImage_size[0], 8UL,
               cudaMemcpyHostToDevice);
    colourSegmentation_kernel15<<<f_grid, f_block>>>(*gpu_HSVImage, i2, i,
      *f_gpu_HSVImage_size, b_i, b_i1, *gpu_HSVImage_data);
  }

  colourSegmentation_kernel16<<<dim3(6U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage_data, *gpu_centerColourMask);

  // Calcualte which pixels are purple
  b_i = (i1 - i) - 1;
  b_i1 = (i3 - i2) - 1;
  g_HSVImage_size[0] = b_i + 1;
  g_HSVImage_size[1] = b_i1 + 1;
  validLaunchParams = mwGetLaunchParameters(static_cast<double>((b_i + 1L) *
    (b_i1 + 1L)), &g_grid, &g_block, 1024U, 65535U);
  if (validLaunchParams) {
    cudaMemcpy(g_gpu_HSVImage_size, &g_HSVImage_size[0], 8UL,
               cudaMemcpyHostToDevice);
    colourSegmentation_kernel17<<<g_grid, g_block>>>(*gpu_HSVImage, i2, i,
      *g_gpu_HSVImage_size, b_i, b_i1, *gpu_HSVImage_data);
  }

  colourSegmentation_kernel18<<<dim3(6U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage_data, *gpu_centerColourMask);

  // Calcualte which pixels are white
  b_i = (i1 - i) - 1;
  b_i1 = (i3 - i2) - 1;
  h_HSVImage_size[0] = b_i + 1;
  h_HSVImage_size[1] = b_i1 + 1;
  validLaunchParams = mwGetLaunchParameters(static_cast<double>((b_i + 1L) *
    (b_i1 + 1L)), &h_grid, &h_block, 1024U, 65535U);
  if (validLaunchParams) {
    cudaMemcpy(h_gpu_HSVImage_size, &h_HSVImage_size[0], 8UL,
               cudaMemcpyHostToDevice);
    colourSegmentation_kernel19<<<h_grid, h_block>>>(*gpu_HSVImage, i2, i,
      *h_gpu_HSVImage_size, b_i, b_i1, *gpu_HSVImage_data);
  }

  colourSegmentation_kernel20<<<dim3(6U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage_data, *gpu_centerColourMask);

  // Calcualte which pixels are black
  b_i = (i1 - i) - 1;
  b_i1 = (i3 - i2) - 1;
  i_HSVImage_size[0] = b_i + 1;
  i_HSVImage_size[1] = b_i1 + 1;
  validLaunchParams = mwGetLaunchParameters(static_cast<double>((b_i + 1L) *
    (b_i1 + 1L)), &i_grid, &i_block, 1024U, 65535U);
  if (validLaunchParams) {
    cudaMemcpy(i_gpu_HSVImage_size, &i_HSVImage_size[0], 8UL,
               cudaMemcpyHostToDevice);
    colourSegmentation_kernel21<<<i_grid, i_block>>>(*gpu_HSVImage, i2, i,
      *i_gpu_HSVImage_size, b_i, b_i1, *gpu_HSVImage_data);
  }

  colourSegmentation_kernel22<<<dim3(6U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_HSVImage_data, *gpu_centerColourMask);

  //  Sum up all the masks and then determine which mask has the most pixels
  colourSegmentation_kernel23<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
    (*gpu_centerColourMask, *gpu_outputs);
  i1 = 1;
  cudaMemcpy(&outputs[0], gpu_outputs, 72UL, cudaMemcpyDeviceToHost);
  validLaunchParams = false;
  ex = outputs[0].f1[0];
  for (i = 0; i < 8; i++) {
    if (validLaunchParams) {
      cudaMemcpy(&outputs[0], gpu_outputs, 72UL, cudaMemcpyDeviceToHost);
      validLaunchParams = false;
    }

    if (ex < outputs[0].f1[i + 1]) {
      ex = outputs[0].f1[i + 1];
      i1 = i + 2;
    }
  }

  //  Make a mask over the whole image. The colour that is seperated
  //  is the one that had the most pixels in the square
  if (i1 == 1) {
    // Red
    colourSegmentation_kernel32<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
      (*gpu_HSVImage, *gpu_SegmentationMask);
  } else if (i1 == 2) {
    // Orange
    colourSegmentation_kernel31<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
      (*gpu_HSVImage, *gpu_SegmentationMask);
  } else if (i1 == 3) {
    // Yellow
    colourSegmentation_kernel30<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
      (*gpu_HSVImage, *gpu_SegmentationMask);
  } else if (i1 == 4) {
    // Green
    colourSegmentation_kernel29<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
      (*gpu_HSVImage, *gpu_SegmentationMask);
  } else if (i1 == 5) {
    // Cyan
    colourSegmentation_kernel28<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
      (*gpu_HSVImage, *gpu_SegmentationMask);
  } else if (i1 == 6) {
    // Blue
    colourSegmentation_kernel27<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
      (*gpu_HSVImage, *gpu_SegmentationMask);
  } else if (i1 == 7) {
    // Purple
    colourSegmentation_kernel26<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
      (*gpu_HSVImage, *gpu_SegmentationMask);
  } else if (i1 == 8) {
    // White
    colourSegmentation_kernel25<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
      (*gpu_HSVImage, *gpu_SegmentationMask);
  } else {
    // Black
    colourSegmentation_kernel24<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
      (*gpu_HSVImage, *gpu_SegmentationMask);
  }

  // Fill up the hole in the binary image.
  // maskFill =imfill(colourSegmentationMask,'holes');
  //
  //  SegmentationMask = bwselect(maskFill,centerOfObjectY,centerOfObjectX);
  cudaMemcpy(&SegmentationMask[0], gpu_SegmentationMask, 728160UL,
             cudaMemcpyDeviceToHost);
  cudaFree(*gpu_colourBalancedImage);
  cudaFree(*gpu_Xin);
  cudaFree(*gpu_HSVImage);
  cudaFree(*gpu_HSVImage_size);
  cudaFree(*gpu_centerColourMask);
  cudaFree(*gpu_HSVImage_data);
  cudaFree(*b_gpu_HSVImage_size);
  cudaFree(*c_gpu_HSVImage_size);
  cudaFree(*d_gpu_HSVImage_size);
  cudaFree(*e_gpu_HSVImage_size);
  cudaFree(*f_gpu_HSVImage_size);
  cudaFree(*g_gpu_HSVImage_size);
  cudaFree(*h_gpu_HSVImage_size);
  cudaFree(*i_gpu_HSVImage_size);
  cudaFree(*gpu_outputs);
  cudaFree(*gpu_SegmentationMask);
}

//
// File trailer for colourSegmentation.cu
//
// [EOF]
//
