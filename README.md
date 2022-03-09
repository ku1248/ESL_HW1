# ESL_HW1
// make a directory to put all the binary files and generated Makefile
mkdir build

// CMake takes the current directory as build directory.
cd build

//Generating Makefiles, the given path must contain CMakeLists.txt
cmake ..

//Compile the SystemC source code.
make

// Run the program
make run
