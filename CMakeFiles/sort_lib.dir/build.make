# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yang/c_study

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yang/c_study

# Include any dependencies generated for this target.
include CMakeFiles/sort_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sort_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sort_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort_lib.dir/flags.make

CMakeFiles/sort_lib.dir/sort.c.o: CMakeFiles/sort_lib.dir/flags.make
CMakeFiles/sort_lib.dir/sort.c.o: sort.c
CMakeFiles/sort_lib.dir/sort.c.o: CMakeFiles/sort_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yang/c_study/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sort_lib.dir/sort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/sort_lib.dir/sort.c.o -MF CMakeFiles/sort_lib.dir/sort.c.o.d -o CMakeFiles/sort_lib.dir/sort.c.o -c /home/yang/c_study/sort.c

CMakeFiles/sort_lib.dir/sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort_lib.dir/sort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yang/c_study/sort.c > CMakeFiles/sort_lib.dir/sort.c.i

CMakeFiles/sort_lib.dir/sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort_lib.dir/sort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yang/c_study/sort.c -o CMakeFiles/sort_lib.dir/sort.c.s

# Object files for target sort_lib
sort_lib_OBJECTS = \
"CMakeFiles/sort_lib.dir/sort.c.o"

# External object files for target sort_lib
sort_lib_EXTERNAL_OBJECTS =

libsort_lib.a: CMakeFiles/sort_lib.dir/sort.c.o
libsort_lib.a: CMakeFiles/sort_lib.dir/build.make
libsort_lib.a: CMakeFiles/sort_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yang/c_study/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libsort_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/sort_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sort_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort_lib.dir/build: libsort_lib.a
.PHONY : CMakeFiles/sort_lib.dir/build

CMakeFiles/sort_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sort_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sort_lib.dir/clean

CMakeFiles/sort_lib.dir/depend:
	cd /home/yang/c_study && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yang/c_study /home/yang/c_study /home/yang/c_study /home/yang/c_study /home/yang/c_study/CMakeFiles/sort_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sort_lib.dir/depend
