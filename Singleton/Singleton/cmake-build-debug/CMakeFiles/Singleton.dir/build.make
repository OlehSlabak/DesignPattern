# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\DesignPattern\Singleton\Singleton

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\DesignPattern\Singleton\Singleton\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Singleton.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Singleton.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Singleton.dir/flags.make

CMakeFiles/Singleton.dir/main.cpp.obj: CMakeFiles/Singleton.dir/flags.make
CMakeFiles/Singleton.dir/main.cpp.obj: CMakeFiles/Singleton.dir/includes_CXX.rsp
CMakeFiles/Singleton.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\DesignPattern\Singleton\Singleton\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Singleton.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Singleton.dir\main.cpp.obj -c C:\DesignPattern\Singleton\Singleton\main.cpp

CMakeFiles/Singleton.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Singleton.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\DesignPattern\Singleton\Singleton\main.cpp > CMakeFiles\Singleton.dir\main.cpp.i

CMakeFiles/Singleton.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Singleton.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\DesignPattern\Singleton\Singleton\main.cpp -o CMakeFiles\Singleton.dir\main.cpp.s

# Object files for target Singleton
Singleton_OBJECTS = \
"CMakeFiles/Singleton.dir/main.cpp.obj"

# External object files for target Singleton
Singleton_EXTERNAL_OBJECTS =

Singleton.exe: CMakeFiles/Singleton.dir/main.cpp.obj
Singleton.exe: CMakeFiles/Singleton.dir/build.make
Singleton.exe: CMakeFiles/Singleton.dir/linklibs.rsp
Singleton.exe: CMakeFiles/Singleton.dir/objects1.rsp
Singleton.exe: CMakeFiles/Singleton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\DesignPattern\Singleton\Singleton\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Singleton.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Singleton.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Singleton.dir/build: Singleton.exe
.PHONY : CMakeFiles/Singleton.dir/build

CMakeFiles/Singleton.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Singleton.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Singleton.dir/clean

CMakeFiles/Singleton.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\DesignPattern\Singleton\Singleton C:\DesignPattern\Singleton\Singleton C:\DesignPattern\Singleton\Singleton\cmake-build-debug C:\DesignPattern\Singleton\Singleton\cmake-build-debug C:\DesignPattern\Singleton\Singleton\cmake-build-debug\CMakeFiles\Singleton.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Singleton.dir/depend

