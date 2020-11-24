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
CMAKE_SOURCE_DIR = /home/aigrip/Documents/realWidth/JetsonNano/Onboard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build

# Include any dependencies generated for this target.
include communication/CMakeFiles/communicationBT_I2C.dir/depend.make

# Include the progress variables for this target.
include communication/CMakeFiles/communicationBT_I2C.dir/progress.make

# Include the compile flags for this target's objects.
include communication/CMakeFiles/communicationBT_I2C.dir/flags.make

communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o: communication/CMakeFiles/communicationBT_I2C.dir/flags.make
communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o: ../communication/communication.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o"
	cd /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/communication && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/communicationBT_I2C.dir/communication.cpp.o -c /home/aigrip/Documents/realWidth/JetsonNano/Onboard/communication/communication.cpp

communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/communicationBT_I2C.dir/communication.cpp.i"
	cd /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/communication && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aigrip/Documents/realWidth/JetsonNano/Onboard/communication/communication.cpp > CMakeFiles/communicationBT_I2C.dir/communication.cpp.i

communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/communicationBT_I2C.dir/communication.cpp.s"
	cd /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/communication && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aigrip/Documents/realWidth/JetsonNano/Onboard/communication/communication.cpp -o CMakeFiles/communicationBT_I2C.dir/communication.cpp.s

communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o.requires:

.PHONY : communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o.requires

communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o.provides: communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o.requires
	$(MAKE) -f communication/CMakeFiles/communicationBT_I2C.dir/build.make communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o.provides.build
.PHONY : communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o.provides

communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o.provides.build: communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o


# Object files for target communicationBT_I2C
communicationBT_I2C_OBJECTS = \
"CMakeFiles/communicationBT_I2C.dir/communication.cpp.o"

# External object files for target communicationBT_I2C
communicationBT_I2C_EXTERNAL_OBJECTS =

communication/libcommunicationBT_I2C.a: communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o
communication/libcommunicationBT_I2C.a: communication/CMakeFiles/communicationBT_I2C.dir/build.make
communication/libcommunicationBT_I2C.a: communication/CMakeFiles/communicationBT_I2C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcommunicationBT_I2C.a"
	cd /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/communication && $(CMAKE_COMMAND) -P CMakeFiles/communicationBT_I2C.dir/cmake_clean_target.cmake
	cd /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/communication && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/communicationBT_I2C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
communication/CMakeFiles/communicationBT_I2C.dir/build: communication/libcommunicationBT_I2C.a

.PHONY : communication/CMakeFiles/communicationBT_I2C.dir/build

communication/CMakeFiles/communicationBT_I2C.dir/requires: communication/CMakeFiles/communicationBT_I2C.dir/communication.cpp.o.requires

.PHONY : communication/CMakeFiles/communicationBT_I2C.dir/requires

communication/CMakeFiles/communicationBT_I2C.dir/clean:
	cd /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/communication && $(CMAKE_COMMAND) -P CMakeFiles/communicationBT_I2C.dir/cmake_clean.cmake
.PHONY : communication/CMakeFiles/communicationBT_I2C.dir/clean

communication/CMakeFiles/communicationBT_I2C.dir/depend:
	cd /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aigrip/Documents/realWidth/JetsonNano/Onboard /home/aigrip/Documents/realWidth/JetsonNano/Onboard/communication /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/communication /home/aigrip/Documents/realWidth/JetsonNano/Onboard/build/communication/CMakeFiles/communicationBT_I2C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : communication/CMakeFiles/communicationBT_I2C.dir/depend

