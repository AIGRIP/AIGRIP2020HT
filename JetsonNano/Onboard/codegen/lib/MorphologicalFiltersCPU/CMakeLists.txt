# This CMake file is to build this "MorphologicalFiltersCPU" library

# Set flag and GPU architecture
set(
CUDA_NVCC_FLAGS
${CUDA_NVCC_FLAGS};
-O3
-std=c++11 -gencode arch=compute_53,code=sm_53
-gencode arch=compute_62,code=sm_62
)

# For CUDA program include all the c++ and CUDA files for the MATLAB converted library.
file(GLOB cu *.c *.cpp *.h)


# Create a library and choose the name (linking name) for the library.
CUDA_ADD_LIBRARY(MorphologicalFiltersCPU SHARED ${cu})

# Make library public.
target_compile_features(MorphologicalFiltersCPU PUBLIC cxx_std_11)

# Make the current directory public.
target_include_directories(MorphologicalFiltersCPU PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

# Link the library.
target_link_libraries(MorphologicalFiltersCPU)
