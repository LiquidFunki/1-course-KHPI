# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\git2\semester 2\lab4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\git2\semester 2\lab4\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab20_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab20_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab20_main.dir/flags.make

CMakeFiles/lab20_main.dir/src/main.c.obj: CMakeFiles/lab20_main.dir/flags.make
CMakeFiles/lab20_main.dir/src/main.c.obj: CMakeFiles/lab20_main.dir/includes_C.rsp
CMakeFiles/lab20_main.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\git2\semester 2\lab4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab20_main.dir/src/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab20_main.dir\src\main.c.obj   -c "D:\git2\semester 2\lab4\src\main.c"

CMakeFiles/lab20_main.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab20_main.dir/src/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\git2\semester 2\lab4\src\main.c" > CMakeFiles\lab20_main.dir\src\main.c.i

CMakeFiles/lab20_main.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab20_main.dir/src/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\git2\semester 2\lab4\src\main.c" -o CMakeFiles\lab20_main.dir\src\main.c.s

CMakeFiles/lab20_main.dir/src/list.c.obj: CMakeFiles/lab20_main.dir/flags.make
CMakeFiles/lab20_main.dir/src/list.c.obj: CMakeFiles/lab20_main.dir/includes_C.rsp
CMakeFiles/lab20_main.dir/src/list.c.obj: ../src/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\git2\semester 2\lab4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab20_main.dir/src/list.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab20_main.dir\src\list.c.obj   -c "D:\git2\semester 2\lab4\src\list.c"

CMakeFiles/lab20_main.dir/src/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab20_main.dir/src/list.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\git2\semester 2\lab4\src\list.c" > CMakeFiles\lab20_main.dir\src\list.c.i

CMakeFiles/lab20_main.dir/src/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab20_main.dir/src/list.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\git2\semester 2\lab4\src\list.c" -o CMakeFiles\lab20_main.dir\src\list.c.s

CMakeFiles/lab20_main.dir/src/data.c.obj: CMakeFiles/lab20_main.dir/flags.make
CMakeFiles/lab20_main.dir/src/data.c.obj: CMakeFiles/lab20_main.dir/includes_C.rsp
CMakeFiles/lab20_main.dir/src/data.c.obj: ../src/data.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\git2\semester 2\lab4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab20_main.dir/src/data.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab20_main.dir\src\data.c.obj   -c "D:\git2\semester 2\lab4\src\data.c"

CMakeFiles/lab20_main.dir/src/data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab20_main.dir/src/data.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\git2\semester 2\lab4\src\data.c" > CMakeFiles\lab20_main.dir\src\data.c.i

CMakeFiles/lab20_main.dir/src/data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab20_main.dir/src/data.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\git2\semester 2\lab4\src\data.c" -o CMakeFiles\lab20_main.dir\src\data.c.s

# Object files for target lab20_main
lab20_main_OBJECTS = \
"CMakeFiles/lab20_main.dir/src/main.c.obj" \
"CMakeFiles/lab20_main.dir/src/list.c.obj" \
"CMakeFiles/lab20_main.dir/src/data.c.obj"

# External object files for target lab20_main
lab20_main_EXTERNAL_OBJECTS =

lab20_main.exe: CMakeFiles/lab20_main.dir/src/main.c.obj
lab20_main.exe: CMakeFiles/lab20_main.dir/src/list.c.obj
lab20_main.exe: CMakeFiles/lab20_main.dir/src/data.c.obj
lab20_main.exe: CMakeFiles/lab20_main.dir/build.make
lab20_main.exe: CMakeFiles/lab20_main.dir/linklibs.rsp
lab20_main.exe: CMakeFiles/lab20_main.dir/objects1.rsp
lab20_main.exe: CMakeFiles/lab20_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\git2\semester 2\lab4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable lab20_main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab20_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab20_main.dir/build: lab20_main.exe

.PHONY : CMakeFiles/lab20_main.dir/build

CMakeFiles/lab20_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab20_main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab20_main.dir/clean

CMakeFiles/lab20_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\git2\semester 2\lab4" "D:\git2\semester 2\lab4" "D:\git2\semester 2\lab4\cmake-build-debug" "D:\git2\semester 2\lab4\cmake-build-debug" "D:\git2\semester 2\lab4\cmake-build-debug\CMakeFiles\lab20_main.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab20_main.dir/depend
