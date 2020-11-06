cmake_minimum_required(VERSION 3.10)

# Find the package that is needed for the project
find_package(CUDA REQUIRED)


# Print CUDA version
message(STATUS "CUDA library status:")
message(STATUS "    version: ${CUDA_VERSION}")
message(STATUS "    include path: ${CUDA_INCLUDE_DIRS}")
message(STATUS "    libraries: ${CUDA_LIBRARIES}")
set(CUDA_NVCC_FLAGS -O3;--relocatable-device-code=true; -gencode arch=compute_53,code=sm_53; -x cu) # nvcc flags


set(CUDA_HOST_COMPILATION_CPP ON)
set(CUDA_NVCC_FLAGS -std=c++11 -g -Xcompiler -fexceptions -Xcompiler -fPIC)
set(CMAKE_C_FLAGS "-g -fPIC")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g -fPIC")
set(CUDA_SEPARABLE_COMPILATION ON)

# The subdirectory should be in order of how they depend on each other.


add_subdirectory(codegen/lib/colourBalanceGPU/) # colourBalanceGPU is a static library

add_subdirectory(codegen/lib/colourSegmentationGPU/) # colourSegmentationGPU is a static library

add_subdirectory(codegen/lib/morphologicalFiltersCPU/) # 

add_subdirectory(codegen/lib/colourBalanceCPU/) # colourBalanceCPU is a static library


add_subdirectory(codegen/lib/colourSegmentationCPU/) # colourBalanceCPU is a static library

add_subdirectory(Executable/) # Executable on all included libraries/functions




