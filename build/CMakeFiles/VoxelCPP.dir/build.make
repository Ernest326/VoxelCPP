# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = C:\Users\Ernest\Documents\VoxelCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ernest\Documents\VoxelCPP\build

# Include any dependencies generated for this target.
include CMakeFiles/VoxelCPP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/VoxelCPP.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/VoxelCPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VoxelCPP.dir/flags.make

CMakeFiles/VoxelCPP.dir/src/App/app.cpp.obj: CMakeFiles/VoxelCPP.dir/flags.make
CMakeFiles/VoxelCPP.dir/src/App/app.cpp.obj: CMakeFiles/VoxelCPP.dir/includes_CXX.rsp
CMakeFiles/VoxelCPP.dir/src/App/app.cpp.obj: C:/Users/Ernest/Documents/VoxelCPP/src/App/app.cpp
CMakeFiles/VoxelCPP.dir/src/App/app.cpp.obj: CMakeFiles/VoxelCPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ernest\Documents\VoxelCPP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VoxelCPP.dir/src/App/app.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VoxelCPP.dir/src/App/app.cpp.obj -MF CMakeFiles\VoxelCPP.dir\src\App\app.cpp.obj.d -o CMakeFiles\VoxelCPP.dir\src\App\app.cpp.obj -c C:\Users\Ernest\Documents\VoxelCPP\src\App\app.cpp

CMakeFiles/VoxelCPP.dir/src/App/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VoxelCPP.dir/src/App/app.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ernest\Documents\VoxelCPP\src\App\app.cpp > CMakeFiles\VoxelCPP.dir\src\App\app.cpp.i

CMakeFiles/VoxelCPP.dir/src/App/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VoxelCPP.dir/src/App/app.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ernest\Documents\VoxelCPP\src\App\app.cpp -o CMakeFiles\VoxelCPP.dir\src\App\app.cpp.s

CMakeFiles/VoxelCPP.dir/src/App/window.cpp.obj: CMakeFiles/VoxelCPP.dir/flags.make
CMakeFiles/VoxelCPP.dir/src/App/window.cpp.obj: CMakeFiles/VoxelCPP.dir/includes_CXX.rsp
CMakeFiles/VoxelCPP.dir/src/App/window.cpp.obj: C:/Users/Ernest/Documents/VoxelCPP/src/App/window.cpp
CMakeFiles/VoxelCPP.dir/src/App/window.cpp.obj: CMakeFiles/VoxelCPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ernest\Documents\VoxelCPP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VoxelCPP.dir/src/App/window.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VoxelCPP.dir/src/App/window.cpp.obj -MF CMakeFiles\VoxelCPP.dir\src\App\window.cpp.obj.d -o CMakeFiles\VoxelCPP.dir\src\App\window.cpp.obj -c C:\Users\Ernest\Documents\VoxelCPP\src\App\window.cpp

CMakeFiles/VoxelCPP.dir/src/App/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VoxelCPP.dir/src/App/window.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ernest\Documents\VoxelCPP\src\App\window.cpp > CMakeFiles\VoxelCPP.dir\src\App\window.cpp.i

CMakeFiles/VoxelCPP.dir/src/App/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VoxelCPP.dir/src/App/window.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ernest\Documents\VoxelCPP\src\App\window.cpp -o CMakeFiles\VoxelCPP.dir\src\App\window.cpp.s

CMakeFiles/VoxelCPP.dir/src/main.cpp.obj: CMakeFiles/VoxelCPP.dir/flags.make
CMakeFiles/VoxelCPP.dir/src/main.cpp.obj: CMakeFiles/VoxelCPP.dir/includes_CXX.rsp
CMakeFiles/VoxelCPP.dir/src/main.cpp.obj: C:/Users/Ernest/Documents/VoxelCPP/src/main.cpp
CMakeFiles/VoxelCPP.dir/src/main.cpp.obj: CMakeFiles/VoxelCPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Ernest\Documents\VoxelCPP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VoxelCPP.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VoxelCPP.dir/src/main.cpp.obj -MF CMakeFiles\VoxelCPP.dir\src\main.cpp.obj.d -o CMakeFiles\VoxelCPP.dir\src\main.cpp.obj -c C:\Users\Ernest\Documents\VoxelCPP\src\main.cpp

CMakeFiles/VoxelCPP.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VoxelCPP.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ernest\Documents\VoxelCPP\src\main.cpp > CMakeFiles\VoxelCPP.dir\src\main.cpp.i

CMakeFiles/VoxelCPP.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VoxelCPP.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ernest\Documents\VoxelCPP\src\main.cpp -o CMakeFiles\VoxelCPP.dir\src\main.cpp.s

# Object files for target VoxelCPP
VoxelCPP_OBJECTS = \
"CMakeFiles/VoxelCPP.dir/src/App/app.cpp.obj" \
"CMakeFiles/VoxelCPP.dir/src/App/window.cpp.obj" \
"CMakeFiles/VoxelCPP.dir/src/main.cpp.obj"

# External object files for target VoxelCPP
VoxelCPP_EXTERNAL_OBJECTS =

VoxelCPP.exe: CMakeFiles/VoxelCPP.dir/src/App/app.cpp.obj
VoxelCPP.exe: CMakeFiles/VoxelCPP.dir/src/App/window.cpp.obj
VoxelCPP.exe: CMakeFiles/VoxelCPP.dir/src/main.cpp.obj
VoxelCPP.exe: CMakeFiles/VoxelCPP.dir/build.make
VoxelCPP.exe: thirdparty/glfw/src/libglfw3.a
VoxelCPP.exe: thirdparty/glad/libglad.a
VoxelCPP.exe: thirdparty/stb_image/libstb_image.a
VoxelCPP.exe: CMakeFiles/VoxelCPP.dir/linkLibs.rsp
VoxelCPP.exe: CMakeFiles/VoxelCPP.dir/objects1.rsp
VoxelCPP.exe: CMakeFiles/VoxelCPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Ernest\Documents\VoxelCPP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable VoxelCPP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\VoxelCPP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VoxelCPP.dir/build: VoxelCPP.exe
.PHONY : CMakeFiles/VoxelCPP.dir/build

CMakeFiles/VoxelCPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\VoxelCPP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/VoxelCPP.dir/clean

CMakeFiles/VoxelCPP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ernest\Documents\VoxelCPP C:\Users\Ernest\Documents\VoxelCPP C:\Users\Ernest\Documents\VoxelCPP\build C:\Users\Ernest\Documents\VoxelCPP\build C:\Users\Ernest\Documents\VoxelCPP\build\CMakeFiles\VoxelCPP.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/VoxelCPP.dir/depend

