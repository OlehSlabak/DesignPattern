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
CMAKE_SOURCE_DIR = "C:\DesignPattern\Decorator\Functional Decorator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\DesignPattern\Decorator\Functional Decorator\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Functional_Decorator.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Functional_Decorator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Functional_Decorator.dir/flags.make

CMakeFiles/Functional_Decorator.dir/main.cpp.obj: CMakeFiles/Functional_Decorator.dir/flags.make
CMakeFiles/Functional_Decorator.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\DesignPattern\Decorator\Functional Decorator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Functional_Decorator.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Functional_Decorator.dir\main.cpp.obj -c "C:\DesignPattern\Decorator\Functional Decorator\main.cpp"

CMakeFiles/Functional_Decorator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Functional_Decorator.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\DesignPattern\Decorator\Functional Decorator\main.cpp" > CMakeFiles\Functional_Decorator.dir\main.cpp.i

CMakeFiles/Functional_Decorator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Functional_Decorator.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\DesignPattern\Decorator\Functional Decorator\main.cpp" -o CMakeFiles\Functional_Decorator.dir\main.cpp.s

# Object files for target Functional_Decorator
Functional_Decorator_OBJECTS = \
"CMakeFiles/Functional_Decorator.dir/main.cpp.obj"

# External object files for target Functional_Decorator
Functional_Decorator_EXTERNAL_OBJECTS =

Functional_Decorator.exe: CMakeFiles/Functional_Decorator.dir/main.cpp.obj
Functional_Decorator.exe: CMakeFiles/Functional_Decorator.dir/build.make
Functional_Decorator.exe: CMakeFiles/Functional_Decorator.dir/linklibs.rsp
Functional_Decorator.exe: CMakeFiles/Functional_Decorator.dir/objects1.rsp
Functional_Decorator.exe: CMakeFiles/Functional_Decorator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\DesignPattern\Decorator\Functional Decorator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Functional_Decorator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Functional_Decorator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Functional_Decorator.dir/build: Functional_Decorator.exe
.PHONY : CMakeFiles/Functional_Decorator.dir/build

CMakeFiles/Functional_Decorator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Functional_Decorator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Functional_Decorator.dir/clean

CMakeFiles/Functional_Decorator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\DesignPattern\Decorator\Functional Decorator" "C:\DesignPattern\Decorator\Functional Decorator" "C:\DesignPattern\Decorator\Functional Decorator\cmake-build-debug" "C:\DesignPattern\Decorator\Functional Decorator\cmake-build-debug" "C:\DesignPattern\Decorator\Functional Decorator\cmake-build-debug\CMakeFiles\Functional_Decorator.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Functional_Decorator.dir/depend

