# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix"

# Include any dependencies generated for this target.
include CMakeFiles/multMatrixClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/multMatrixClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/multMatrixClient.dir/flags.make

CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.o: CMakeFiles/multMatrixClient.dir/flags.make
CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.o: main_multMatrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.o -c "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/main_multMatrix.cpp"

CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/main_multMatrix.cpp" > CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.i

CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/main_multMatrix.cpp" -o CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.s

CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.o: CMakeFiles/multMatrixClient.dir/flags.make
CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.o: multmatrix_stub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.o -c "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/multmatrix_stub.cpp"

CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/multmatrix_stub.cpp" > CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.i

CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/multmatrix_stub.cpp" -o CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.s

CMakeFiles/multMatrixClient.dir/utils.cpp.o: CMakeFiles/multMatrixClient.dir/flags.make
CMakeFiles/multMatrixClient.dir/utils.cpp.o: utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/multMatrixClient.dir/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/multMatrixClient.dir/utils.cpp.o -c "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/utils.cpp"

CMakeFiles/multMatrixClient.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/multMatrixClient.dir/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/utils.cpp" > CMakeFiles/multMatrixClient.dir/utils.cpp.i

CMakeFiles/multMatrixClient.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/multMatrixClient.dir/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/utils.cpp" -o CMakeFiles/multMatrixClient.dir/utils.cpp.s

# Object files for target multMatrixClient
multMatrixClient_OBJECTS = \
"CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.o" \
"CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.o" \
"CMakeFiles/multMatrixClient.dir/utils.cpp.o"

# External object files for target multMatrixClient
multMatrixClient_EXTERNAL_OBJECTS =

multMatrixClient: CMakeFiles/multMatrixClient.dir/main_multMatrix.cpp.o
multMatrixClient: CMakeFiles/multMatrixClient.dir/multmatrix_stub.cpp.o
multMatrixClient: CMakeFiles/multMatrixClient.dir/utils.cpp.o
multMatrixClient: CMakeFiles/multMatrixClient.dir/build.make
multMatrixClient: CMakeFiles/multMatrixClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable multMatrixClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/multMatrixClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/multMatrixClient.dir/build: multMatrixClient

.PHONY : CMakeFiles/multMatrixClient.dir/build

CMakeFiles/multMatrixClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/multMatrixClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/multMatrixClient.dir/clean

CMakeFiles/multMatrixClient.dir/depend:
	cd "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix" "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix" "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix" "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix" "/home/jorge/Documentos/Programacion de sistemas distribuidos/Practica1/multMatrix/CMakeFiles/multMatrixClient.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/multMatrixClient.dir/depend
