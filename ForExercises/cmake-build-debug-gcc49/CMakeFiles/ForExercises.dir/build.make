# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = "/Users/carl/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6397.106/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/carl/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6397.106/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/carl/Desktop/01Project/Cpp/ForExercises

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/carl/Desktop/01Project/Cpp/ForExercises/cmake-build-debug-gcc49

# Include any dependencies generated for this target.
include CMakeFiles/ForExercises.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ForExercises.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ForExercises.dir/flags.make

CMakeFiles/ForExercises.dir/main.cpp.o: CMakeFiles/ForExercises.dir/flags.make
CMakeFiles/ForExercises.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/carl/Desktop/01Project/Cpp/ForExercises/cmake-build-debug-gcc49/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ForExercises.dir/main.cpp.o"
	/usr/local/Cellar/gcc@4.9/4.9.4_2/bin/g++-4.9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ForExercises.dir/main.cpp.o -c /Users/carl/Desktop/01Project/Cpp/ForExercises/main.cpp

CMakeFiles/ForExercises.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ForExercises.dir/main.cpp.i"
	/usr/local/Cellar/gcc@4.9/4.9.4_2/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carl/Desktop/01Project/Cpp/ForExercises/main.cpp > CMakeFiles/ForExercises.dir/main.cpp.i

CMakeFiles/ForExercises.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ForExercises.dir/main.cpp.s"
	/usr/local/Cellar/gcc@4.9/4.9.4_2/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carl/Desktop/01Project/Cpp/ForExercises/main.cpp -o CMakeFiles/ForExercises.dir/main.cpp.s

# Object files for target ForExercises
ForExercises_OBJECTS = \
"CMakeFiles/ForExercises.dir/main.cpp.o"

# External object files for target ForExercises
ForExercises_EXTERNAL_OBJECTS =

ForExercises: CMakeFiles/ForExercises.dir/main.cpp.o
ForExercises: CMakeFiles/ForExercises.dir/build.make
ForExercises: CMakeFiles/ForExercises.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/carl/Desktop/01Project/Cpp/ForExercises/cmake-build-debug-gcc49/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ForExercises"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ForExercises.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ForExercises.dir/build: ForExercises

.PHONY : CMakeFiles/ForExercises.dir/build

CMakeFiles/ForExercises.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ForExercises.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ForExercises.dir/clean

CMakeFiles/ForExercises.dir/depend:
	cd /Users/carl/Desktop/01Project/Cpp/ForExercises/cmake-build-debug-gcc49 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/carl/Desktop/01Project/Cpp/ForExercises /Users/carl/Desktop/01Project/Cpp/ForExercises /Users/carl/Desktop/01Project/Cpp/ForExercises/cmake-build-debug-gcc49 /Users/carl/Desktop/01Project/Cpp/ForExercises/cmake-build-debug-gcc49 /Users/carl/Desktop/01Project/Cpp/ForExercises/cmake-build-debug-gcc49/CMakeFiles/ForExercises.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ForExercises.dir/depend

