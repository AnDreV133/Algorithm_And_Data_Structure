# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files (x86)/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files (x86)/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "T:/c github pc/Algorithm_And_Data_Structure"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "T:/c github pc/Algorithm_And_Data_Structure/build"

# Include any dependencies generated for this target.
include CMakeFiles/mystring.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mystring.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mystring.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mystring.dir/flags.make

CMakeFiles/mystring.dir/mystring/mystring.cpp.obj: CMakeFiles/mystring.dir/flags.make
CMakeFiles/mystring.dir/mystring/mystring.cpp.obj: T:/c\ github\ pc/Algorithm_And_Data_Structure/mystring/mystring.cpp
CMakeFiles/mystring.dir/mystring/mystring.cpp.obj: CMakeFiles/mystring.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="T:/c github pc/Algorithm_And_Data_Structure/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mystring.dir/mystring/mystring.cpp.obj"
	C:/Users/dmitr/gcc/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mystring.dir/mystring/mystring.cpp.obj -MF CMakeFiles/mystring.dir/mystring/mystring.cpp.obj.d -o CMakeFiles/mystring.dir/mystring/mystring.cpp.obj -c "T:/c github pc/Algorithm_And_Data_Structure/mystring/mystring.cpp"

CMakeFiles/mystring.dir/mystring/mystring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mystring.dir/mystring/mystring.cpp.i"
	C:/Users/dmitr/gcc/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "T:/c github pc/Algorithm_And_Data_Structure/mystring/mystring.cpp" > CMakeFiles/mystring.dir/mystring/mystring.cpp.i

CMakeFiles/mystring.dir/mystring/mystring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mystring.dir/mystring/mystring.cpp.s"
	C:/Users/dmitr/gcc/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "T:/c github pc/Algorithm_And_Data_Structure/mystring/mystring.cpp" -o CMakeFiles/mystring.dir/mystring/mystring.cpp.s

# Object files for target mystring
mystring_OBJECTS = \
"CMakeFiles/mystring.dir/mystring/mystring.cpp.obj"

# External object files for target mystring
mystring_EXTERNAL_OBJECTS =

libmystring.a: CMakeFiles/mystring.dir/mystring/mystring.cpp.obj
libmystring.a: CMakeFiles/mystring.dir/build.make
libmystring.a: CMakeFiles/mystring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="T:/c github pc/Algorithm_And_Data_Structure/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmystring.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mystring.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mystring.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mystring.dir/build: libmystring.a
.PHONY : CMakeFiles/mystring.dir/build

CMakeFiles/mystring.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mystring.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mystring.dir/clean

CMakeFiles/mystring.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "T:/c github pc/Algorithm_And_Data_Structure" "T:/c github pc/Algorithm_And_Data_Structure" "T:/c github pc/Algorithm_And_Data_Structure/build" "T:/c github pc/Algorithm_And_Data_Structure/build" "T:/c github pc/Algorithm_And_Data_Structure/build/CMakeFiles/mystring.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/mystring.dir/depend

