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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab7_prog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab7_prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab7_prog.dir/flags.make

CMakeFiles/lab7_prog.dir/main.cpp.o: CMakeFiles/lab7_prog.dir/flags.make
CMakeFiles/lab7_prog.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab7_prog.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab7_prog.dir/main.cpp.o -c /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/main.cpp

CMakeFiles/lab7_prog.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab7_prog.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/main.cpp > CMakeFiles/lab7_prog.dir/main.cpp.i

CMakeFiles/lab7_prog.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab7_prog.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/main.cpp -o CMakeFiles/lab7_prog.dir/main.cpp.s

CMakeFiles/lab7_prog.dir/MyTimer.cpp.o: CMakeFiles/lab7_prog.dir/flags.make
CMakeFiles/lab7_prog.dir/MyTimer.cpp.o: ../MyTimer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab7_prog.dir/MyTimer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab7_prog.dir/MyTimer.cpp.o -c /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/MyTimer.cpp

CMakeFiles/lab7_prog.dir/MyTimer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab7_prog.dir/MyTimer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/MyTimer.cpp > CMakeFiles/lab7_prog.dir/MyTimer.cpp.i

CMakeFiles/lab7_prog.dir/MyTimer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab7_prog.dir/MyTimer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/MyTimer.cpp -o CMakeFiles/lab7_prog.dir/MyTimer.cpp.s

# Object files for target lab7_prog
lab7_prog_OBJECTS = \
"CMakeFiles/lab7_prog.dir/main.cpp.o" \
"CMakeFiles/lab7_prog.dir/MyTimer.cpp.o"

# External object files for target lab7_prog
lab7_prog_EXTERNAL_OBJECTS =

lab7_prog: CMakeFiles/lab7_prog.dir/main.cpp.o
lab7_prog: CMakeFiles/lab7_prog.dir/MyTimer.cpp.o
lab7_prog: CMakeFiles/lab7_prog.dir/build.make
lab7_prog: CMakeFiles/lab7_prog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab7_prog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab7_prog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab7_prog.dir/build: lab7_prog

.PHONY : CMakeFiles/lab7_prog.dir/build

CMakeFiles/lab7_prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab7_prog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab7_prog.dir/clean

CMakeFiles/lab7_prog.dir/depend:
	cd /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/cmake-build-debug /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/cmake-build-debug /Users/demonblo/Desktop/AA_2020/aa_2020/lab7_prog/cmake-build-debug/CMakeFiles/lab7_prog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab7_prog.dir/depend

