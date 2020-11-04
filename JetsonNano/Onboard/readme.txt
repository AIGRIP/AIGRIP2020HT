This folder contain the whole software for for the Jetson Nano.

To compile all code follow following steps:
1. Type "cd build" in the terminal from the current folder.
2. Type "cmake ..".
3. If the previuse step worked succefully, type "make" to compile 
	the whole project and create an executable.
4. If it compiled succefully, type "cd .." or "cd Executable".
5. If you type "ls", you should see a file named "RUN_AIGRIP_NANO", it is the executable.
6. To run the executable type "./RUN_AIGRIP_NANO".


This software building is based on CMake, all the "CMakeLists.txt" file 
you find in this project is to link all the libraries to easily build this project.



To add a new feature you create a folder in this directory and fill it with all the 
source code needed. Then you add an "CMakeLists.txt" to create a static library in the folder you created. 
Then write a "add_subdirectory" call in the CMake file in this folder, to link your library for this project. It
should be placed in such order that it is before all the includes that depends on it.

The folder "Executable" contains the main file for this project. We recommend you to have a c++ file as main because,
the matlab converter will add c++ libraries in the GPU converted code.


