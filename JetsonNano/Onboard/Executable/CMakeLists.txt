# Set the main file as source file. IT CAN NOT BE A C-FILE!!!
set(SOURCE_FILES main.cpp)

# Create an executable.
CUDA_ADD_EXECUTABLE(RUN_AIGRIP_NANO ${SOURCE_FILES})

# Link the needed libraries to the source file.
target_link_libraries(RUN_AIGRIP_NANO ParallelMotorAnglet2CPU)
target_link_libraries(RUN_AIGRIP_NANO InverseKinematicsPreshapeCPU)
target_link_libraries(RUN_AIGRIP_NANO ApproachObjectCPU)
target_link_libraries(RUN_AIGRIP_NANO PointToLineCPU)
target_link_libraries(RUN_AIGRIP_NANO ForwardKinematicsCPU)

# Libraries for image processing.
target_link_libraries(RUN_AIGRIP_NANO colourBalanceGPU)
target_link_libraries(RUN_AIGRIP_NANO colourSegmentationGPU)
target_link_libraries(RUN_AIGRIP_NANO MorphologicalFiltersCPU)

# Libraries to find the best gripping points.
target_link_libraries(RUN_AIGRIP_NANO StableLineCPU)
target_link_libraries(RUN_AIGRIP_NANO GetSignatureCPU)
target_link_libraries(RUN_AIGRIP_NANO GetValidGripPointsCPU)

# Library for external communication.
target_link_libraries(RUN_AIGRIP_NANO controlGriperNano)

# Library for external communication.
target_link_libraries(RUN_AIGRIP_NANO communicationBT_I2C)

# Set CUDA properties to the executable.
set_target_properties(RUN_AIGRIP_NANO PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

# Link the needed CUDA flags.
 target_link_libraries(RUN_AIGRIP_NANO -lcublas -fopenmp ${OpenCV_LIBS} ) #-lopencv_core -lopencv_imgproc)


