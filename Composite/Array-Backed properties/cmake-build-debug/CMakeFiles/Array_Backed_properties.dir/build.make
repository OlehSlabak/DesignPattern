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
CMAKE_SOURCE_DIR = "C:\DesignPattern\Composite\Array-Backed properties"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\DesignPattern\Composite\Array-Backed properties\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Array_Backed_properties.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Array_Backed_properties.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Array_Backed_properties.dir/flags.make

CMakeFiles/Array_Backed_properties.dir/main.cpp.obj: CMakeFiles/Array_Backed_properties.dir/flags.make
CMakeFiles/Array_Backed_properties.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\DesignPattern\Composite\Array-Backed properties\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Array_Backed_properties.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Array_Backed_properties.dir\main.cpp.obj -c "C:\DesignPattern\Composite\Array-Backed properties\main.cpp"

CMakeFiles/Array_Backed_properties.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Array_Backed_properties.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\DesignPattern\Composite\Array-Backed properties\main.cpp" > CMakeFiles\Array_Backed_properties.dir\main.cpp.i

CMakeFiles/Array_Backed_properties.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Array_Backed_properties.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\DesignPattern\Composite\Array-Backed properties\main.cpp" -o CMakeFiles\Array_Backed_properties.dir\main.cpp.s

# Object files for target Array_Backed_properties
Array_Backed_properties_OBJECTS = \
"CMakeFiles/Array_Backed_properties.dir/main.cpp.obj"

# External object files for target Array_Backed_properties
Array_Backed_properties_EXTERNAL_OBJECTS =

Array_Backed_properties.exe: CMakeFiles/Array_Backed_properties.dir/main.cpp.obj
Array_Backed_properties.exe: CMakeFiles/Array_Backed_properties.dir/build.make
Array_Backed_properties.exe: CMakeFiles/Array_Backed_properties.dir/linklibs.rsp
Array_Backed_properties.exe: CMakeFiles/Array_Backed_properties.dir/objects1.rsp
Array_Backed_properties.exe: CMakeFiles/Array_Backed_properties.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\DesignPattern\Composite\Array-Backed properties\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Array_Backed_properties.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Array_Backed_properties.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Array_Backed_properties.dir/build: Array_Backed_properties.exe
.PHONY : CMakeFiles/Array_Backed_properties.dir/build

CMakeFiles/Array_Backed_properties.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Array_Backed_properties.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Array_Backed_properties.dir/clean

CMakeFiles/Array_Backed_properties.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\DesignPattern\Composite\Array-Backed properties" "C:\DesignPattern\Composite\Array-Backed properties" "C:\DesignPattern\Composite\Array-Backed properties\cmake-build-debug" "C:\DesignPattern\Composite\Array-Backed properties\cmake-build-debug" "C:\DesignPattern\Composite\Array-Backed properties\cmake-build-debug\CMakeFiles\Array_Backed_properties.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Array_Backed_properties.dir/depend

