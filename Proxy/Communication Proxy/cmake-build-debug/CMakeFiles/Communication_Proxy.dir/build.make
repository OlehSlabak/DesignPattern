# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\DesignPattern\Proxy\Communication Proxy"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\DesignPattern\Proxy\Communication Proxy\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Communication_Proxy.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\Communication_Proxy.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Communication_Proxy.dir\flags.make

CMakeFiles\Communication_Proxy.dir\main.cpp.obj: CMakeFiles\Communication_Proxy.dir\flags.make
CMakeFiles\Communication_Proxy.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\DesignPattern\Proxy\Communication Proxy\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Communication_Proxy.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\ENTERP~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Communication_Proxy.dir\main.cpp.obj /FdCMakeFiles\Communication_Proxy.dir\ /FS -c "D:\DesignPattern\Proxy\Communication Proxy\main.cpp"
<<

CMakeFiles\Communication_Proxy.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Communication_Proxy.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\ENTERP~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Communication_Proxy.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\DesignPattern\Proxy\Communication Proxy\main.cpp"
<<

CMakeFiles\Communication_Proxy.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Communication_Proxy.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\ENTERP~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Communication_Proxy.dir\main.cpp.s /c "D:\DesignPattern\Proxy\Communication Proxy\main.cpp"
<<

# Object files for target Communication_Proxy
Communication_Proxy_OBJECTS = \
"CMakeFiles\Communication_Proxy.dir\main.cpp.obj"

# External object files for target Communication_Proxy
Communication_Proxy_EXTERNAL_OBJECTS =

Communication_Proxy.exe: CMakeFiles\Communication_Proxy.dir\main.cpp.obj
Communication_Proxy.exe: CMakeFiles\Communication_Proxy.dir\build.make
Communication_Proxy.exe: CMakeFiles\Communication_Proxy.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\DesignPattern\Proxy\Communication Proxy\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Communication_Proxy.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Communication_Proxy.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\ENTERP~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Communication_Proxy.dir\objects1.rsp @<<
 /out:Communication_Proxy.exe /implib:Communication_Proxy.lib /pdb:"D:\DesignPattern\Proxy\Communication Proxy\cmake-build-debug\Communication_Proxy.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Communication_Proxy.dir\build: Communication_Proxy.exe
.PHONY : CMakeFiles\Communication_Proxy.dir\build

CMakeFiles\Communication_Proxy.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Communication_Proxy.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Communication_Proxy.dir\clean

CMakeFiles\Communication_Proxy.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\DesignPattern\Proxy\Communication Proxy" "D:\DesignPattern\Proxy\Communication Proxy" "D:\DesignPattern\Proxy\Communication Proxy\cmake-build-debug" "D:\DesignPattern\Proxy\Communication Proxy\cmake-build-debug" "D:\DesignPattern\Proxy\Communication Proxy\cmake-build-debug\CMakeFiles\Communication_Proxy.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Communication_Proxy.dir\depend

