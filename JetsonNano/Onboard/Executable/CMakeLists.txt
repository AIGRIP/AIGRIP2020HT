# Set the main file as source file. IT CAN NOT BE A C-FILE!!!
set(SOURCE_FILES main.cpp)

# Create an executable.
CUDA_ADD_EXECUTABLE(RUN_AIGRIP_NANO ${SOURCE_FILES})

# Link the needed libraries to the source file.
target_link_libraries(RUN_AIGRIP_NANO colourBalanceGPU)
target_link_libraries(RUN_AIGRIP_NANO colourSegmentationGPU)
target_link_libraries(RUN_AIGRIP_NANO morphologicalFiltersCPU)


# Set CUDA properties to the executable.
set_target_properties(RUN_AIGRIP_NANO PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

# Link the needed CUDA flags.
target_link_libraries(RUN_AIGRIP_NANO -lcublas -fopenmp)
