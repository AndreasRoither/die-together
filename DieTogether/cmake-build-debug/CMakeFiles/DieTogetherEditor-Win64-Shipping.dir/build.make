# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Andreas\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6494.38\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Andreas\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6494.38\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Andreas\Documents\git\DieTogetherProto\DieTogether

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Andreas\Documents\git\DieTogetherProto\DieTogether\cmake-build-debug

# Utility rule file for DieTogetherEditor-Win64-Shipping.

# Include the progress variables for this target.
include CMakeFiles/DieTogetherEditor-Win64-Shipping.dir/progress.make

CMakeFiles/DieTogetherEditor-Win64-Shipping:
	call F:/Games/Epic/UE_4.24/Engine/Build/BatchFiles/Build.bat DieTogetherEditor Win64 Shipping -project=C:/Users/Andreas/Documents/git/DieTogetherProto/DieTogether/DieTogether.uproject -game -progress -buildscw

DieTogetherEditor-Win64-Shipping: CMakeFiles/DieTogetherEditor-Win64-Shipping
DieTogetherEditor-Win64-Shipping: CMakeFiles/DieTogetherEditor-Win64-Shipping.dir/build.make

.PHONY : DieTogetherEditor-Win64-Shipping

# Rule to build all files generated by this target.
CMakeFiles/DieTogetherEditor-Win64-Shipping.dir/build: DieTogetherEditor-Win64-Shipping

.PHONY : CMakeFiles/DieTogetherEditor-Win64-Shipping.dir/build

CMakeFiles/DieTogetherEditor-Win64-Shipping.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DieTogetherEditor-Win64-Shipping.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DieTogetherEditor-Win64-Shipping.dir/clean

CMakeFiles/DieTogetherEditor-Win64-Shipping.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Andreas\Documents\git\DieTogetherProto\DieTogether C:\Users\Andreas\Documents\git\DieTogetherProto\DieTogether C:\Users\Andreas\Documents\git\DieTogetherProto\DieTogether\cmake-build-debug C:\Users\Andreas\Documents\git\DieTogetherProto\DieTogether\cmake-build-debug C:\Users\Andreas\Documents\git\DieTogetherProto\DieTogether\cmake-build-debug\CMakeFiles\DieTogetherEditor-Win64-Shipping.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DieTogetherEditor-Win64-Shipping.dir/depend
