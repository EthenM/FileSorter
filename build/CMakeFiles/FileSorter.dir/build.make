# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\build

# Include any dependencies generated for this target.
include CMakeFiles/FileSorter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FileSorter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FileSorter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FileSorter.dir/flags.make

CMakeFiles/FileSorter.dir/codegen:
.PHONY : CMakeFiles/FileSorter.dir/codegen

CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.obj: CMakeFiles/FileSorter.dir/flags.make
CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.obj: C:/Users/BobG5/Desktop/Utilities/Programming/projects/FileSorter/src/exceptions/DirectoryNotFoundException.cpp
CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.obj: CMakeFiles/FileSorter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.obj -MF CMakeFiles\FileSorter.dir\src\exceptions\DirectoryNotFoundException.cpp.obj.d -o CMakeFiles\FileSorter.dir\src\exceptions\DirectoryNotFoundException.cpp.obj -c C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\exceptions\DirectoryNotFoundException.cpp

CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\exceptions\DirectoryNotFoundException.cpp > CMakeFiles\FileSorter.dir\src\exceptions\DirectoryNotFoundException.cpp.i

CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\exceptions\DirectoryNotFoundException.cpp -o CMakeFiles\FileSorter.dir\src\exceptions\DirectoryNotFoundException.cpp.s

CMakeFiles/FileSorter.dir/src/main.cpp.obj: CMakeFiles/FileSorter.dir/flags.make
CMakeFiles/FileSorter.dir/src/main.cpp.obj: C:/Users/BobG5/Desktop/Utilities/Programming/projects/FileSorter/src/main.cpp
CMakeFiles/FileSorter.dir/src/main.cpp.obj: CMakeFiles/FileSorter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FileSorter.dir/src/main.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSorter.dir/src/main.cpp.obj -MF CMakeFiles\FileSorter.dir\src\main.cpp.obj.d -o CMakeFiles\FileSorter.dir\src\main.cpp.obj -c C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\main.cpp

CMakeFiles/FileSorter.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSorter.dir/src/main.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\main.cpp > CMakeFiles\FileSorter.dir\src\main.cpp.i

CMakeFiles/FileSorter.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSorter.dir/src/main.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\main.cpp -o CMakeFiles\FileSorter.dir\src\main.cpp.s

CMakeFiles/FileSorter.dir/src/FileSorter.cpp.obj: CMakeFiles/FileSorter.dir/flags.make
CMakeFiles/FileSorter.dir/src/FileSorter.cpp.obj: C:/Users/BobG5/Desktop/Utilities/Programming/projects/FileSorter/src/FileSorter.cpp
CMakeFiles/FileSorter.dir/src/FileSorter.cpp.obj: CMakeFiles/FileSorter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FileSorter.dir/src/FileSorter.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSorter.dir/src/FileSorter.cpp.obj -MF CMakeFiles\FileSorter.dir\src\FileSorter.cpp.obj.d -o CMakeFiles\FileSorter.dir\src\FileSorter.cpp.obj -c C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\FileSorter.cpp

CMakeFiles/FileSorter.dir/src/FileSorter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSorter.dir/src/FileSorter.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\FileSorter.cpp > CMakeFiles\FileSorter.dir\src\FileSorter.cpp.i

CMakeFiles/FileSorter.dir/src/FileSorter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSorter.dir/src/FileSorter.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\FileSorter.cpp -o CMakeFiles\FileSorter.dir\src\FileSorter.cpp.s

CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.obj: CMakeFiles/FileSorter.dir/flags.make
CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.obj: C:/Users/BobG5/Desktop/Utilities/Programming/projects/FileSorter/src/FileObtainer.cpp
CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.obj: CMakeFiles/FileSorter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.obj -MF CMakeFiles\FileSorter.dir\src\FileObtainer.cpp.obj.d -o CMakeFiles\FileSorter.dir\src\FileObtainer.cpp.obj -c C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\FileObtainer.cpp

CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\FileObtainer.cpp > CMakeFiles\FileSorter.dir\src\FileObtainer.cpp.i

CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\src\FileObtainer.cpp -o CMakeFiles\FileSorter.dir\src\FileObtainer.cpp.s

# Object files for target FileSorter
FileSorter_OBJECTS = \
"CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.obj" \
"CMakeFiles/FileSorter.dir/src/main.cpp.obj" \
"CMakeFiles/FileSorter.dir/src/FileSorter.cpp.obj" \
"CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.obj"

# External object files for target FileSorter
FileSorter_EXTERNAL_OBJECTS =

FileSorter.exe: CMakeFiles/FileSorter.dir/src/exceptions/DirectoryNotFoundException.cpp.obj
FileSorter.exe: CMakeFiles/FileSorter.dir/src/main.cpp.obj
FileSorter.exe: CMakeFiles/FileSorter.dir/src/FileSorter.cpp.obj
FileSorter.exe: CMakeFiles/FileSorter.dir/src/FileObtainer.cpp.obj
FileSorter.exe: CMakeFiles/FileSorter.dir/build.make
FileSorter.exe: CMakeFiles/FileSorter.dir/linkLibs.rsp
FileSorter.exe: CMakeFiles/FileSorter.dir/objects1.rsp
FileSorter.exe: CMakeFiles/FileSorter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable FileSorter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FileSorter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FileSorter.dir/build: FileSorter.exe
.PHONY : CMakeFiles/FileSorter.dir/build

CMakeFiles/FileSorter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FileSorter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FileSorter.dir/clean

CMakeFiles/FileSorter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\build C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\build C:\Users\BobG5\Desktop\Utilities\Programming\projects\FileSorter\build\CMakeFiles\FileSorter.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FileSorter.dir/depend

