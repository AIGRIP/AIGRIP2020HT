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
CMAKE_SOURCE_DIR = /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build

# Include any dependencies generated for this target.
include imageCapture/CMakeFiles/imageCapture.dir/depend.make

# Include the progress variables for this target.
include imageCapture/CMakeFiles/imageCapture.dir/progress.make

# Include the compile flags for this target's objects.
include imageCapture/CMakeFiles/imageCapture.dir/flags.make

imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o: imageCapture/CMakeFiles/imageCapture.dir/flags.make
imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o: ../imageCapture/imageCapture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o"
	cd /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/imageCapture && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imageCapture.dir/imageCapture.cpp.o -c /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/imageCapture/imageCapture.cpp

imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imageCapture.dir/imageCapture.cpp.i"
	cd /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/imageCapture && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/imageCapture/imageCapture.cpp > CMakeFiles/imageCapture.dir/imageCapture.cpp.i

imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imageCapture.dir/imageCapture.cpp.s"
	cd /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/imageCapture && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/imageCapture/imageCapture.cpp -o CMakeFiles/imageCapture.dir/imageCapture.cpp.s

imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o.requires:

.PHONY : imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o.requires

imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o.provides: imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o.requires
	$(MAKE) -f imageCapture/CMakeFiles/imageCapture.dir/build.make imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o.provides.build
.PHONY : imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o.provides

imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o.provides.build: imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o


# Object files for target imageCapture
imageCapture_OBJECTS = \
"CMakeFiles/imageCapture.dir/imageCapture.cpp.o"

# External object files for target imageCapture
imageCapture_EXTERNAL_OBJECTS =

imageCapture/libimageCapture.a: imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o
imageCapture/libimageCapture.a: imageCapture/CMakeFiles/imageCapture.dir/build.make
imageCapture/libimageCapture.a: imageCapture/CMakeFiles/imageCapture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libimageCapture.a"
	cd /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/imageCapture && $(CMAKE_COMMAND) -P CMakeFiles/imageCapture.dir/cmake_clean_target.cmake
	cd /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/imageCapture && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imageCapture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
imageCapture/CMakeFiles/imageCapture.dir/build: imageCapture/libimageCapture.a

.PHONY : imageCapture/CMakeFiles/imageCapture.dir/build

imageCapture/CMakeFiles/imageCapture.dir/requires: imageCapture/CMakeFiles/imageCapture.dir/imageCapture.cpp.o.requires

.PHONY : imageCapture/CMakeFiles/imageCapture.dir/requires

imageCapture/CMakeFiles/imageCapture.dir/clean:
	cd /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/imageCapture && $(CMAKE_COMMAND) -P CMakeFiles/imageCapture.dir/cmake_clean.cmake
.PHONY : imageCapture/CMakeFiles/imageCapture.dir/clean

imageCapture/CMakeFiles/imageCapture.dir/depend:
	cd /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/imageCapture /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/imageCapture /home/aigrip/Documents/controlMainNano/JetsonNano/Onboard/build/imageCapture/CMakeFiles/imageCapture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : imageCapture/CMakeFiles/imageCapture.dir/depend

