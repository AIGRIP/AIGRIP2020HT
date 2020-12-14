# This CMake file is to build this "controlGriperNano" library

# Set flag and GPU architecture
set(
CUDA_NVCC_FLAGS
${CUDA_NVCC_FLAGS};
-O3
-std=c++11 -gencode arch=compute_53,code=sm_53
-gencode arch=compute_62,code=sm_62
)

# For CUDA program include all the c++ and CUDA files for the MATLAB converted library.
file(GLOB cu *.c *.cpp)

# Create a library and choose the name (linking name) for the library.
CUDA_ADD_LIBRARY(controlGriperNano SHARED ${cu})

# Make library public.
target_compile_features(controlGriperNano PUBLIC cxx_std_11)

# Make the current directory public.
target_include_directories(controlGriperNano PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

# Link the library.
target_link_libraries(controlGriperNano typedefsGripperNano -lpthread)

# Link the library.
target_link_libraries(controlGriperNano ${OpenCV_LIBS})

# Libraries for image processing.
target_link_libraries(controlGriperNano colourBalanceGPU)
target_link_libraries(controlGriperNano colourSegmentationGPU)
target_link_libraries(controlGriperNano MorphologicalFiltersCPU)

# Libraries to find the best gripping points.
target_link_libraries(controlGriperNano StableLineCPU)
target_link_libraries(controlGriperNano GetSignatureCPU)
target_link_libraries(controlGriperNano GetValidGripPointsCPU)

# Library to get an image from camera.
#target_link_libraries(controlGriperNano imageCapture)

# Library for approach.
target_link_libraries(controlGriperNano ApproachObjectCPU)
