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
include codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/depend.make

# Include the progress variables for this target.
include codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/progress.make

# Include the compile flags for this target's objects.
include codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/flags.make

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/flags.make
codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o: ../codegen/lib/PointToLineCPU/PointToLine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o -c /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine.cpp

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.i"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine.cpp > CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.i

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.s"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine.cpp -o CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.s

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o.requires:

.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o.requires

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o.provides: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o.requires
	$(MAKE) -f codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/build.make codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o.provides.build
.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o.provides

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o.provides.build: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o


codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/flags.make
codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o: ../codegen/lib/PointToLineCPU/PointToLine_data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o -c /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine_data.cpp

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.i"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine_data.cpp > CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.i

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.s"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine_data.cpp -o CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.s

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o.requires:

.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o.requires

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o.provides: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o.requires
	$(MAKE) -f codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/build.make codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o.provides.build
.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o.provides

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o.provides.build: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o


codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/flags.make
codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o: ../codegen/lib/PointToLineCPU/PointToLine_initialize.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o -c /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine_initialize.cpp

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.i"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine_initialize.cpp > CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.i

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.s"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine_initialize.cpp -o CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.s

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o.requires:

.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o.requires

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o.provides: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o.requires
	$(MAKE) -f codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/build.make codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o.provides.build
.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o.provides

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o.provides.build: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o


codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/flags.make
codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o: ../codegen/lib/PointToLineCPU/PointToLine_terminate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o -c /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine_terminate.cpp

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.i"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine_terminate.cpp > CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.i

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.s"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU/PointToLine_terminate.cpp -o CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.s

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o.requires:

.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o.requires

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o.provides: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o.requires
	$(MAKE) -f codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/build.make codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o.provides.build
.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o.provides

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o.provides.build: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o


# Object files for target PointToLineCPU
PointToLineCPU_OBJECTS = \
"CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o" \
"CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o" \
"CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o" \
"CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o"

# External object files for target PointToLineCPU
PointToLineCPU_EXTERNAL_OBJECTS =

codegen/lib/PointToLineCPU/libPointToLineCPU.a: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o
codegen/lib/PointToLineCPU/libPointToLineCPU.a: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o
codegen/lib/PointToLineCPU/libPointToLineCPU.a: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o
codegen/lib/PointToLineCPU/libPointToLineCPU.a: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o
codegen/lib/PointToLineCPU/libPointToLineCPU.a: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/build.make
codegen/lib/PointToLineCPU/libPointToLineCPU.a: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libPointToLineCPU.a"
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && $(CMAKE_COMMAND) -P CMakeFiles/PointToLineCPU.dir/cmake_clean_target.cmake
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PointToLineCPU.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/build: codegen/lib/PointToLineCPU/libPointToLineCPU.a

.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/build

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/requires: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine.cpp.o.requires
codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/requires: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_data.cpp.o.requires
codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/requires: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_initialize.cpp.o.requires
codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/requires: codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/PointToLine_terminate.cpp.o.requires

.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/requires

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/clean:
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU && $(CMAKE_COMMAND) -P CMakeFiles/PointToLineCPU.dir/cmake_clean.cmake
.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/clean

codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/depend:
	cd /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aigrip/Documents/A4.2/JetsonNano/Onboard /home/aigrip/Documents/A4.2/JetsonNano/Onboard/codegen/lib/PointToLineCPU /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU /home/aigrip/Documents/A4.2/JetsonNano/Onboard/build/codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : codegen/lib/PointToLineCPU/CMakeFiles/PointToLineCPU.dir/depend

