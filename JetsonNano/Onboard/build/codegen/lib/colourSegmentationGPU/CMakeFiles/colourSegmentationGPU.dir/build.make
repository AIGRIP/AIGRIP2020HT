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
CMAKE_SOURCE_DIR = /home/aigrip/Documents/A4.2/JetsonNano/Onboard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build

# Include any dependencies generated for this target.
include codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/depend.make

# Include the progress variables for this target.
include codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/progress.make

# Include the compile flags for this target's objects.
include codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/flags.make

codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o.depend
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o.cmake
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o: ../codegen/lib/colourSegmentationGPU/colourSegmentation.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building NVCC (Device) object codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir && /usr/bin/cmake -E make_directory /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//.
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir && /usr/bin/cmake -D verbose:BOOL=$(VERBOSE) -D build_configuration:STRING= -D generated_file:STRING=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation.cu.o -D generated_cubin_file:STRING=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation.cu.o.cubin.txt -P /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//colourSegmentationGPU_generated_colourSegmentation.cu.o.cmake

codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o.depend
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o.cmake
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o: ../codegen/lib/colourSegmentationGPU/colourSegmentation_data.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building NVCC (Device) object codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir && /usr/bin/cmake -E make_directory /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//.
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir && /usr/bin/cmake -D verbose:BOOL=$(VERBOSE) -D build_configuration:STRING= -D generated_file:STRING=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation_data.cu.o -D generated_cubin_file:STRING=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation_data.cu.o.cubin.txt -P /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//colourSegmentationGPU_generated_colourSegmentation_data.cu.o.cmake

codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o.depend
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o.cmake
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o: ../codegen/lib/colourSegmentationGPU/colourSegmentation_initialize.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building NVCC (Device) object codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir && /usr/bin/cmake -E make_directory /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//.
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir && /usr/bin/cmake -D verbose:BOOL=$(VERBOSE) -D build_configuration:STRING= -D generated_file:STRING=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o -D generated_cubin_file:STRING=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o.cubin.txt -P /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o.cmake

codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o.depend
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o.cmake
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o: ../codegen/lib/colourSegmentationGPU/colourSegmentation_terminate.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building NVCC (Device) object codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir && /usr/bin/cmake -E make_directory /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//.
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir && /usr/bin/cmake -D verbose:BOOL=$(VERBOSE) -D build_configuration:STRING= -D generated_file:STRING=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o -D generated_cubin_file:STRING=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o.cubin.txt -P /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o.cmake

codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_intermediate_link.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_intermediate_link.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_intermediate_link.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_intermediate_link.o: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building NVCC intermediate link file codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_intermediate_link.o"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU && /usr/local/cuda/bin/nvcc -std=c++11 -g -Xcompiler -fexceptions -Xcompiler -fPIC -O3 -std=c++11 -gencode arch=compute_53,code=sm_53 -gencode arch=compute_62,code=sm_62 -m64 -ccbin /usr/bin/cc -dlink /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation.cu.o /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation_data.cu.o /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir//./colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o -o /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/./colourSegmentationGPU_intermediate_link.o -Xcompiler -fPIC

# Object files for target colourSegmentationGPU
colourSegmentationGPU_OBJECTS =

# External object files for target colourSegmentationGPU
colourSegmentationGPU_EXTERNAL_OBJECTS = \
"/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o" \
"/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o" \
"/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o" \
"/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o" \
"/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_intermediate_link.o"

codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o
codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o
codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o
codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o
codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_intermediate_link.o
codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/build.make
codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libcolourSegmentationGPU.a"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU && $(CMAKE_COMMAND) -P CMakeFiles/colourSegmentationGPU.dir/cmake_clean_target.cmake
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/colourSegmentationGPU.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/build: codegen/lib/colourSegmentationGPU/libcolourSegmentationGPU.a

.PHONY : codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/build

codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/requires:

.PHONY : codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/requires

codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/clean:
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU && $(CMAKE_COMMAND) -P CMakeFiles/colourSegmentationGPU.dir/cmake_clean.cmake
.PHONY : codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/clean

codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/depend: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation.cu.o
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/depend: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_data.cu.o
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/depend: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_initialize.cu.o
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/depend: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_generated_colourSegmentation_terminate.cu.o
codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/depend: codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/colourSegmentationGPU_intermediate_link.o
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aigrip/Documents/A4.2/JetsonNano/Onboard /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/colourSegmentationGPU /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : codegen/lib/colourSegmentationGPU/CMakeFiles/colourSegmentationGPU.dir/depend

