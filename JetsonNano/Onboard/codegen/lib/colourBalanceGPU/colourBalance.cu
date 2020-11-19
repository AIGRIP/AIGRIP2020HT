//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colourBalance.cu
//
// GPU Coder version                    : 2.0
// CUDA/C/C++ source code generated on  : 19-Nov-2020 17:09:04
//

// Include Files
#include "colourBalance.h"
#include "MWCudaDimUtility.hpp"

// Function Declarations
static __device__ double atomicOpreal_T(double *address, double value);
static __global__ void colourBalance_kernel1(const unsigned char originalImage
  [2184480], double *y);
static __global__ void colourBalance_kernel2(const unsigned char originalImage
  [2184480], double *y);
static __global__ void colourBalance_kernel3(const unsigned char originalImage
  [2184480], double *y);
static __global__ void colourBalance_kernel4(const unsigned char originalImage
  [2184480], double *y);
static __global__ void colourBalance_kernel5(const unsigned char originalImage
  [2184480], double *y);
static __global__ void colourBalance_kernel6(const unsigned char originalImage
  [2184480], double *y);
static __global__ void colourBalance_kernel7(const double *y, const double
  meanRed, const unsigned char originalImage[2184480], unsigned char
  newGreenLayer[728160], unsigned char newRedLayer[728160]);
static __global__ void colourBalance_kernel8(const double meanRed, const
  unsigned char originalImage[2184480], unsigned char newBlueLayer[728160]);
static __global__ void colourBalance_kernel9(const unsigned char newRedLayer
  [728160], const int initAuxVar, unsigned char colourBalancedImage[2184480]);
static __device__ double rt_roundd_snf_device(double u);
static __device__ double shflDown2(double in1, unsigned int offset, unsigned int
  mask);
static __device__ double threadGroupReduction(double val, unsigned int lane,
  unsigned int mask);
static __device__ double workGroupReduction(double val, unsigned int mask,
  unsigned int numActiveWarps);

// Function Definitions
//
// Arguments    : double *address
//                double value
// Return Type  : double
//
static __device__ double atomicOpreal_T(double *address, double value)
{
  unsigned long long int old;
  unsigned long long int *address_as_up;
  address_as_up = (unsigned long long int *)address;
  old = *address_as_up;
  unsigned long long int assumed;
  do {
    assumed = old;
    old = atomicCAS(address_as_up, old, __double_as_longlong(value +
      __longlong_as_double(old)));
  } while (assumed != old);

  return __longlong_as_double(old);
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const unsigned char originalImage[2184480]
//                double *y
// Return Type  : void
//
static __global__ __launch_bounds__(32, 1) void colourBalance_kernel1(const
  unsigned char originalImage[2184480], double *y)
{
  int tmpIdx;
  tmpIdx = static_cast<int>(mwGetGlobalThreadIndex());
  if (tmpIdx < 1) {
    // Input:
    // originalImage = RGB image 984x740x3
    // Output:
    // colourBalancedImage = RGB image 984x740x3
    // Calculate number of pixales in te image
    // Calculate the mean of every colour and take the mean of every colour added 
    // togheter
    *y = static_cast<double>(originalImage[0]);
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const unsigned char originalImage[2184480]
//                double *y
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourBalance_kernel2(const
  unsigned char originalImage[2184480], double *y)
{
  double tmpRed0;
  unsigned int blockStride;
  unsigned int idx;
  unsigned int m;
  unsigned int thBlkId;
  unsigned int threadId;
  unsigned int threadStride;
  threadStride = static_cast<unsigned int>(mwGetTotalThreadsLaunched());
  threadId = static_cast<unsigned int>(mwGetGlobalThreadIndex());
  thBlkId = static_cast<unsigned int>(mwGetThreadIndexWithinBlock());
  blockStride = static_cast<unsigned int>(mwGetThreadsPerBlock());
  tmpRed0 = 0.0;
  if (mwIsLastBlock()) {
    m = 728159U % blockStride;
    if (m > 0U) {
      blockStride = m;
    }
  }

  blockStride = ((blockStride + warpSize) - 1U) / warpSize;
  if (threadId <= 728158U) {
    tmpRed0 = static_cast<double>(originalImage[(static_cast<int>(threadId) + 1)
      % 984 + 984 * ((static_cast<int>(threadId) + 1) / 984)]);
  }

  m = __ballot_sync(MAX_uint32_T, threadId <= 728158U);
  for (idx = threadId + threadStride; idx <= 728158U; idx += threadStride) {
    tmpRed0 += static_cast<double>(originalImage[(static_cast<int>(idx) + 1) %
      984 + 984 * ((static_cast<int>(idx) + 1) / 984)]);
  }

  tmpRed0 = workGroupReduction(tmpRed0, m, blockStride);
  if (thBlkId == 0U) {
    atomicOpreal_T(&y[0], tmpRed0);
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const unsigned char originalImage[2184480]
//                double *y
// Return Type  : void
//
static __global__ __launch_bounds__(32, 1) void colourBalance_kernel3(const
  unsigned char originalImage[2184480], double *y)
{
  int tmpIdx;
  tmpIdx = static_cast<int>(mwGetGlobalThreadIndex());
  if (tmpIdx < 1) {
    *y = static_cast<double>(originalImage[728160]);
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const unsigned char originalImage[2184480]
//                double *y
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourBalance_kernel4(const
  unsigned char originalImage[2184480], double *y)
{
  double tmpRed0;
  unsigned int blockStride;
  unsigned int idx;
  unsigned int m;
  unsigned int thBlkId;
  unsigned int threadId;
  unsigned int threadStride;
  threadStride = static_cast<unsigned int>(mwGetTotalThreadsLaunched());
  threadId = static_cast<unsigned int>(mwGetGlobalThreadIndex());
  thBlkId = static_cast<unsigned int>(mwGetThreadIndexWithinBlock());
  blockStride = static_cast<unsigned int>(mwGetThreadsPerBlock());
  tmpRed0 = 0.0;
  if (mwIsLastBlock()) {
    m = 728159U % blockStride;
    if (m > 0U) {
      blockStride = m;
    }
  }

  blockStride = ((blockStride + warpSize) - 1U) / warpSize;
  if (threadId <= 728158U) {
    tmpRed0 = static_cast<double>(originalImage[((static_cast<int>(threadId) + 1)
      % 984 + 984 * ((static_cast<int>(threadId) + 1) / 984)) + 728160]);
  }

  m = __ballot_sync(MAX_uint32_T, threadId <= 728158U);
  for (idx = threadId + threadStride; idx <= 728158U; idx += threadStride) {
    tmpRed0 += static_cast<double>(originalImage[((static_cast<int>(idx) + 1) %
      984 + 984 * ((static_cast<int>(idx) + 1) / 984)) + 728160]);
  }

  tmpRed0 = workGroupReduction(tmpRed0, m, blockStride);
  if (thBlkId == 0U) {
    atomicOpreal_T(&y[0], tmpRed0);
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const unsigned char originalImage[2184480]
//                double *y
// Return Type  : void
//
static __global__ __launch_bounds__(32, 1) void colourBalance_kernel5(const
  unsigned char originalImage[2184480], double *y)
{
  int tmpIdx;
  tmpIdx = static_cast<int>(mwGetGlobalThreadIndex());
  if (tmpIdx < 1) {
    *y = static_cast<double>(originalImage[1456320]);
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const unsigned char originalImage[2184480]
//                double *y
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourBalance_kernel6(const
  unsigned char originalImage[2184480], double *y)
{
  double tmpRed0;
  unsigned int blockStride;
  unsigned int idx;
  unsigned int m;
  unsigned int thBlkId;
  unsigned int threadId;
  unsigned int threadStride;
  threadStride = static_cast<unsigned int>(mwGetTotalThreadsLaunched());
  threadId = static_cast<unsigned int>(mwGetGlobalThreadIndex());
  thBlkId = static_cast<unsigned int>(mwGetThreadIndexWithinBlock());
  blockStride = static_cast<unsigned int>(mwGetThreadsPerBlock());
  tmpRed0 = 0.0;
  if (mwIsLastBlock()) {
    m = 728159U % blockStride;
    if (m > 0U) {
      blockStride = m;
    }
  }

  blockStride = ((blockStride + warpSize) - 1U) / warpSize;
  if (threadId <= 728158U) {
    tmpRed0 = static_cast<double>(originalImage[((static_cast<int>(threadId) + 1)
      % 984 + 984 * ((static_cast<int>(threadId) + 1) / 984)) + 1456320]);
  }

  m = __ballot_sync(MAX_uint32_T, threadId <= 728158U);
  for (idx = threadId + threadStride; idx <= 728158U; idx += threadStride) {
    tmpRed0 += static_cast<double>(originalImage[((static_cast<int>(idx) + 1) %
      984 + 984 * ((static_cast<int>(idx) + 1) / 984)) + 1456320]);
  }

  tmpRed0 = workGroupReduction(tmpRed0, m, blockStride);
  if (thBlkId == 0U) {
    atomicOpreal_T(&y[0], tmpRed0);
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double *y
//                const double meanRed
//                const unsigned char originalImage[2184480]
//                unsigned char newGreenLayer[728160]
//                unsigned char newRedLayer[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourBalance_kernel7(const
  double *y, const double meanRed, const unsigned char originalImage[2184480],
  unsigned char newGreenLayer[728160], unsigned char newRedLayer[728160])
{
  unsigned long threadId;
  int i;
  int k;
  threadId = mwGetGlobalThreadIndex();
  i = static_cast<int>(threadId % 984UL);
  k = static_cast<int>((threadId - static_cast<unsigned long>(i)) / 984UL);
  if ((static_cast<int>(k < 740)) && (static_cast<int>(i < 984))) {
    double d;
    unsigned char u;
    d = rt_roundd_snf_device(static_cast<double>(originalImage[i + 984 * k]) *
      meanRed);
    if (d < 256.0) {
      u = static_cast<unsigned char>(d);
    } else if (d >= 256.0) {
      u = MAX_uint8_T;
    } else {
      u = static_cast<unsigned char>(0U);
    }

    newRedLayer[i + 984 * k] = u;
    d = rt_roundd_snf_device(static_cast<double>(originalImage[(i + 984 * k) +
      728160]) * *y);
    if (d < 256.0) {
      u = static_cast<unsigned char>(d);
    } else if (d >= 256.0) {
      u = MAX_uint8_T;
    } else {
      u = static_cast<unsigned char>(0U);
    }

    newGreenLayer[i + 984 * k] = u;
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const double meanRed
//                const unsigned char originalImage[2184480]
//                unsigned char newBlueLayer[728160]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourBalance_kernel8(const
  double meanRed, const unsigned char originalImage[2184480], unsigned char
  newBlueLayer[728160])
{
  unsigned long threadId;
  int i;
  int k;
  threadId = mwGetGlobalThreadIndex();
  i = static_cast<int>(threadId % 984UL);
  k = static_cast<int>((threadId - static_cast<unsigned long>(i)) / 984UL);
  if ((static_cast<int>(k < 740)) && (static_cast<int>(i < 984))) {
    double d;
    unsigned char u;
    d = rt_roundd_snf_device(static_cast<double>(originalImage[(i + 984 * k) +
      1456320]) * meanRed);
    if (d < 256.0) {
      u = static_cast<unsigned char>(d);
    } else if (d >= 256.0) {
      u = MAX_uint8_T;
    } else {
      u = static_cast<unsigned char>(0U);
    }

    newBlueLayer[i + 984 * k] = u;
  }
}

//
// Arguments    : dim3 blockArg
//                dim3 gridArg
//                const unsigned char newRedLayer[728160]
//                const int initAuxVar
//                unsigned char colourBalancedImage[2184480]
// Return Type  : void
//
static __global__ __launch_bounds__(512, 1) void colourBalance_kernel9(const
  unsigned char newRedLayer[728160], const int initAuxVar, unsigned char
  colourBalancedImage[2184480])
{
  int j;
  j = static_cast<int>(mwGetGlobalThreadIndex());
  if (j < 728160) {
    colourBalancedImage[(initAuxVar + j) + 1] = newRedLayer[j];
  }
}

//
// Arguments    : double u
// Return Type  : double
//
static __device__ double rt_roundd_snf_device(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// Arguments    : double in1
//                unsigned int offset
//                unsigned int mask
// Return Type  : double
//
static __device__ double shflDown2(double in1, unsigned int offset, unsigned int
  mask)
{
  int2 tmp;
  tmp = *(int2 *)&in1;
  tmp.x = __shfl_down_sync(mask, tmp.x, offset);
  tmp.y = __shfl_down_sync(mask, tmp.y, offset);
  return *(double *)&tmp;
}

//
// Arguments    : double val
//                unsigned int lane
//                unsigned int mask
// Return Type  : double
//
static __device__ double threadGroupReduction(double val, unsigned int lane,
  unsigned int mask)
{
  unsigned int activeSize;
  unsigned int offset;
  activeSize = __popc(mask);
  offset = (activeSize + 1U) / 2U;
  while (activeSize > 1U) {
    double other;
    other = shflDown2(val, offset, mask);
    if (lane + offset < activeSize) {
      val += other;
    }

    activeSize = offset;
    offset = (offset + 1U) / 2U;
  }

  return val;
}

//
// Arguments    : double val
//                unsigned int mask
//                unsigned int numActiveWarps
// Return Type  : double
//
static __device__ double workGroupReduction(double val, unsigned int mask,
  unsigned int numActiveWarps)
{
  __shared__ double shared[32];
  unsigned int lane;
  unsigned int thBlkId;
  thBlkId = static_cast<unsigned int>(mwGetThreadIndexWithinBlock());
  lane = thBlkId % warpSize;
  thBlkId /= warpSize;
  val = threadGroupReduction(val, lane, mask);
  if (lane == 0U) {
    shared[thBlkId] = val;
  }

  __syncthreads();
  mask = __ballot_sync(MAX_uint32_T, lane < numActiveWarps);
  val = shared[lane];
  if (thBlkId == 0U) {
    val = threadGroupReduction(val, lane, mask);
  }

  return val;
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
  double meanBlue;
  double meanGreen;
  double meanRed;
  double meanTotal;
  double y;
  double *gpu_y;
  int initAuxVar;
  int iy;
  int j;
  unsigned char (*gpu_colourBalancedImage)[2184480];
  unsigned char (*gpu_originalImage)[2184480];
  unsigned char (*gpu_newBlueLayer)[728160];
  unsigned char (*gpu_newGreenLayer)[728160];
  unsigned char (*gpu_newRedLayer)[728160];
  bool colourBalancedImage_dirtyOnCpu;
  bool newBlueLayer_dirtyOnGpu;
  bool originalImage_dirtyOnCpu;
  cudaMalloc(&gpu_newRedLayer, 728160UL);
  cudaMalloc(&gpu_newGreenLayer, 728160UL);
  cudaMalloc(&gpu_colourBalancedImage, 2184480UL);
  cudaMalloc(&gpu_newBlueLayer, 728160UL);
  cudaMalloc(&gpu_y, 8UL);
  cudaMalloc(&gpu_originalImage, 2184480UL);
  colourBalancedImage_dirtyOnCpu = false;

  // Input:
  // originalImage = RGB image 984x740x3
  // Output:
  // colourBalancedImage = RGB image 984x740x3
  // Calculate number of pixales in te image
  // Calculate the mean of every colour and take the mean of every colour added
  // togheter
  cudaMemcpy(gpu_originalImage, (void *)&originalImage[0], 2184480UL,
             cudaMemcpyHostToDevice);
  colourBalance_kernel1<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
    (*gpu_originalImage, gpu_y);
  colourBalance_kernel2<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_originalImage, gpu_y);
  cudaMemcpy(&y, gpu_y, 8UL, cudaMemcpyDeviceToHost);
  meanRed = y / 728160.0;
  colourBalance_kernel3<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
    (*gpu_originalImage, gpu_y);
  colourBalance_kernel4<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_originalImage, gpu_y);
  cudaMemcpy(&y, gpu_y, 8UL, cudaMemcpyDeviceToHost);
  meanGreen = y / 728160.0;
  colourBalance_kernel5<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>
    (*gpu_originalImage, gpu_y);
  colourBalance_kernel6<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_originalImage, gpu_y);
  cudaMemcpy(&y, gpu_y, 8UL, cudaMemcpyDeviceToHost);
  meanBlue = y / 728160.0;
  meanTotal = ((meanRed + meanGreen) + meanBlue) / 3.0;

  // Create a new image and use the mean value of the colours to calculate the
  // new colours
  meanRed = meanTotal / meanRed;
  y = meanTotal / meanGreen;
  cudaMemcpy(gpu_y, &y, 8UL, cudaMemcpyHostToDevice);
  colourBalance_kernel7<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>(gpu_y,
    meanRed, *gpu_originalImage, *gpu_newGreenLayer, *gpu_newRedLayer);
  originalImage_dirtyOnCpu = true;
  colourBalance_kernel8<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>(meanTotal /
    meanBlue, *gpu_originalImage, *gpu_newBlueLayer);
  newBlueLayer_dirtyOnGpu = true;
  iy = -1;
  for (j = 0; j < 728160; j++) {
    iy = j;
    if (newBlueLayer_dirtyOnGpu) {
      cudaMemcpy(&newBlueLayer[0], gpu_newBlueLayer, 728160UL,
                 cudaMemcpyDeviceToHost);
      newBlueLayer_dirtyOnGpu = false;
    }

    colourBalancedImage[j] = newBlueLayer[j];
    colourBalancedImage_dirtyOnCpu = true;
  }

  initAuxVar = iy;
  for (j = 0; j < 728160; j++) {
    iy = (initAuxVar + j) + 1;
    if (originalImage_dirtyOnCpu) {
      cudaMemcpy(&newGreenLayer[0], gpu_newGreenLayer, 728160UL,
                 cudaMemcpyDeviceToHost);
      originalImage_dirtyOnCpu = false;
    }

    colourBalancedImage[iy] = newGreenLayer[j];
    colourBalancedImage_dirtyOnCpu = true;
  }

  if (colourBalancedImage_dirtyOnCpu) {
    cudaMemcpy(gpu_colourBalancedImage, &colourBalancedImage[0], 2184480UL,
               cudaMemcpyHostToDevice);
  }

  colourBalance_kernel9<<<dim3(1423U, 1U, 1U), dim3(512U, 1U, 1U)>>>
    (*gpu_newRedLayer, iy, *gpu_colourBalancedImage);
  cudaMemcpy(&colourBalancedImage[0], gpu_colourBalancedImage, 2184480UL,
             cudaMemcpyDeviceToHost);
  cudaFree(*gpu_originalImage);
  cudaFree(gpu_y);
  cudaFree(*gpu_newBlueLayer);
  cudaFree(*gpu_colourBalancedImage);
  cudaFree(*gpu_newGreenLayer);
  cudaFree(*gpu_newRedLayer);
}

//
// File trailer for colourBalance.cu
//
// [EOF]
//
