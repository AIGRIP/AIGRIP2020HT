This folder contain the whole software for the Jetson Nano.

To compile all code follow following steps:
1. Type "mkdir build" in the terminal from the current folder.
2. Type "cd build"
3. Type "cmake .."
4. If the previuse step worked succefully, type "make" to compile
the whole project and create an executable.
5. If it compiled succefully, type "cd Executable".
6. If you type "ls", you should see a file named "RUN_AIGRIP_NANO", it is the executable.
7. To run the executable type "./RUN_AIGRIP_NANO".

This software building is based on CMake, all the "CMakeLists.txt" file
you find in this project is to link all the libraries to easily build this project. It is recommended to
get familiar to CMake, to get an understanding of this structure.

The folder "Executable" contains the main file for this project. We recommend you to have a c++ file as main because,
the matlab converter will add c++ libraries in the GPU converted code.
