# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/cmake-3.9.2/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.9.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/travis/build/malegkin/print_ip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/travis/build/malegkin/print_ip

# Include any dependencies generated for this target.
include test/CMakeFiles/test_to_ip_string.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_to_ip_string.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_to_ip_string.dir/flags.make

test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o: test/CMakeFiles/test_to_ip_string.dir/flags.make
test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o: test/test_to_ip_string.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/malegkin/print_ip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o"
	cd /home/travis/build/malegkin/print_ip/test && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o -c /home/travis/build/malegkin/print_ip/test/test_to_ip_string.cpp

test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.i"
	cd /home/travis/build/malegkin/print_ip/test && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/malegkin/print_ip/test/test_to_ip_string.cpp > CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.i

test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.s"
	cd /home/travis/build/malegkin/print_ip/test && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/malegkin/print_ip/test/test_to_ip_string.cpp -o CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.s

test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o.requires:

.PHONY : test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o.requires

test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o.provides: test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/test_to_ip_string.dir/build.make test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o.provides.build
.PHONY : test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o.provides

test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o.provides.build: test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o


# Object files for target test_to_ip_string
test_to_ip_string_OBJECTS = \
"CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o"

# External object files for target test_to_ip_string
test_to_ip_string_EXTERNAL_OBJECTS =

test/test_to_ip_string: test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o
test/test_to_ip_string: test/CMakeFiles/test_to_ip_string.dir/build.make
test/test_to_ip_string: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so
test/test_to_ip_string: test/CMakeFiles/test_to_ip_string.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/travis/build/malegkin/print_ip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_to_ip_string"
	cd /home/travis/build/malegkin/print_ip/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_to_ip_string.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_to_ip_string.dir/build: test/test_to_ip_string

.PHONY : test/CMakeFiles/test_to_ip_string.dir/build

test/CMakeFiles/test_to_ip_string.dir/requires: test/CMakeFiles/test_to_ip_string.dir/test_to_ip_string.cpp.o.requires

.PHONY : test/CMakeFiles/test_to_ip_string.dir/requires

test/CMakeFiles/test_to_ip_string.dir/clean:
	cd /home/travis/build/malegkin/print_ip/test && $(CMAKE_COMMAND) -P CMakeFiles/test_to_ip_string.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_to_ip_string.dir/clean

test/CMakeFiles/test_to_ip_string.dir/depend:
	cd /home/travis/build/malegkin/print_ip && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/travis/build/malegkin/print_ip /home/travis/build/malegkin/print_ip/test /home/travis/build/malegkin/print_ip /home/travis/build/malegkin/print_ip/test /home/travis/build/malegkin/print_ip/test/CMakeFiles/test_to_ip_string.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_to_ip_string.dir/depend

