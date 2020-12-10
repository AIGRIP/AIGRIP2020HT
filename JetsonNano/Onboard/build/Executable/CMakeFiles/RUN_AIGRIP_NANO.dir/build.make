# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build

# Include any dependencies generated for this target.
include Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/depend.make

# Include the progress variables for this target.
include Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/progress.make

# Include the compile flags for this target's objects.
include Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/flags.make

Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o: Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/flags.make
Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o: ../Executable/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o"
	cd /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/Executable && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o -c /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/Executable/main.cpp

Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.i"
	cd /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/Executable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/Executable/main.cpp > CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.i

Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.s"
	cd /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/Executable && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/Executable/main.cpp -o CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.s

Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o.requires:

.PHONY : Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o.requires

Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o.provides: Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o.requires
	$(MAKE) -f Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/build.make Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o.provides.build
.PHONY : Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o.provides

Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o.provides.build: Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o


# Object files for target RUN_AIGRIP_NANO
RUN_AIGRIP_NANO_OBJECTS = \
"CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o"

# External object files for target RUN_AIGRIP_NANO
RUN_AIGRIP_NANO_EXTERNAL_OBJECTS =

Executable/RUN_AIGRIP_NANO: Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o
Executable/RUN_AIGRIP_NANO: Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/build.make
Executable/RUN_AIGRIP_NANO: /usr/local/cuda/lib64/libcudart_static.a
Executable/RUN_AIGRIP_NANO: /usr/lib/aarch64-linux-gnu/librt.so
Executable/RUN_AIGRIP_NANO: codegen/lib/ParallelMotorAnglet2CPU/libParallelMotorAnglet2CPU.a
Executable/RUN_AIGRIP_NANO: codegen/lib/InverseKinematicsPreshapeCPU/libInverseKinematicsPreshapeCPU.a
Executable/RUN_AIGRIP_NANO: codegen/lib/ApproachObjectCPU/libApproachObjectCPU.a
Executable/RUN_AIGRIP_NANO: codegen/lib/PointToLineCPU/libPointToLineCPU.a
Executable/RUN_AIGRIP_NANO: codegen/lib/ForwardKinematicsCPU/libForwardKinematicsCPU.a
Executable/RUN_AIGRIP_NANO: codegen/lib/colourBalanceGPU/libcolourBalanceGPU.a
Executable/RUN_AIGRIP_NANO: codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a
Executable/RUN_AIGRIP_NANO: imageCapture/libimageCapture.a
Executable/RUN_AIGRIP_NANO: communication/libcommunicationBT_I2C.a
Executable/RUN_AIGRIP_NANO: control/libcontrolGriperNano.a
Executable/RUN_AIGRIP_NANO: codegen/lib/colourBalanceGPU/libcolourBalanceGPU.a
Executable/RUN_AIGRIP_NANO: codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a
Executable/RUN_AIGRIP_NANO: codegen/lib/MorphologicalFiltersCPU/libMorphologicalFiltersCPU.so
Executable/RUN_AIGRIP_NANO: codegen/lib/StableLineCPU/libStableLineCPU.so
Executable/RUN_AIGRIP_NANO: codegen/lib/GetSignatureCPU/libGetSignatureCPU.so
Executable/RUN_AIGRIP_NANO: codegen/lib/GetValidGripPointsCPU/libGetValidGripPointsCPU.so
Executable/RUN_AIGRIP_NANO: imageCapture/libimageCapture.a
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_gapi.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_stitching.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_aruco.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_bgsegm.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_bioinspired.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_ccalib.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudabgsegm.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudafeatures2d.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudaobjdetect.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudastereo.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_dnn_objdetect.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_dpm.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_face.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_freetype.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_fuzzy.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_hfs.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_img_hash.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_line_descriptor.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_quality.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_reg.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_rgbd.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_saliency.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_stereo.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_structured_light.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_phase_unwrapping.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_superres.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudacodec.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_surface_matching.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_tracking.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_datasets.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_plot.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_text.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_dnn.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_videostab.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudaoptflow.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudalegacy.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudawarping.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_optflow.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_video.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_xfeatures2d.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_ml.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_shape.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_ximgproc.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_xobjdetect.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_objdetect.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_calib3d.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_features2d.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_flann.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_highgui.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_videoio.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_imgcodecs.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_xphoto.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_photo.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudaimgproc.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudafilters.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_imgproc.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudaarithm.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_core.so.4.1.0
Executable/RUN_AIGRIP_NANO: /usr/local/lib/libopencv_cudev.so.4.1.0
Executable/RUN_AIGRIP_NANO: GeneralTypedefs/libtypedefsGripperNano.a
Executable/RUN_AIGRIP_NANO: /usr/local/cuda/lib64/libcudart_static.a
Executable/RUN_AIGRIP_NANO: /usr/lib/aarch64-linux-gnu/librt.so
Executable/RUN_AIGRIP_NANO: /usr/local/cuda/lib64/libcudadevrt.a
Executable/RUN_AIGRIP_NANO: Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RUN_AIGRIP_NANO"
	cd /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/Executable && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RUN_AIGRIP_NANO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/build: Executable/RUN_AIGRIP_NANO

.PHONY : Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/build

Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/requires: Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/main.cpp.o.requires

.PHONY : Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/requires

Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/clean:
	cd /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/Executable && $(CMAKE_COMMAND) -P CMakeFiles/RUN_AIGRIP_NANO.dir/cmake_clean.cmake
.PHONY : Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/clean

Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/depend:
	cd /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/Executable /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/Executable /home/aigrip/Documents/communicationControlJetsonNano/JetsonNano/Onboard/build/Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Executable/CMakeFiles/RUN_AIGRIP_NANO.dir/depend

