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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/douglaslange/ProjectsCpp/Labyrinth

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/douglaslange/ProjectsCpp/Labyrinth/build

# Include any dependencies generated for this target.
include CMakeFiles/lucca.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lucca.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lucca.dir/flags.make

CMakeFiles/lucca.dir/src/labyrinth.cpp.o: CMakeFiles/lucca.dir/flags.make
CMakeFiles/lucca.dir/src/labyrinth.cpp.o: ../src/labyrinth.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/douglaslange/ProjectsCpp/Labyrinth/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lucca.dir/src/labyrinth.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lucca.dir/src/labyrinth.cpp.o -c /Users/douglaslange/ProjectsCpp/Labyrinth/src/labyrinth.cpp

CMakeFiles/lucca.dir/src/labyrinth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lucca.dir/src/labyrinth.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/douglaslange/ProjectsCpp/Labyrinth/src/labyrinth.cpp > CMakeFiles/lucca.dir/src/labyrinth.cpp.i

CMakeFiles/lucca.dir/src/labyrinth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lucca.dir/src/labyrinth.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/douglaslange/ProjectsCpp/Labyrinth/src/labyrinth.cpp -o CMakeFiles/lucca.dir/src/labyrinth.cpp.s

CMakeFiles/lucca.dir/src/lucca.cpp.o: CMakeFiles/lucca.dir/flags.make
CMakeFiles/lucca.dir/src/lucca.cpp.o: ../src/lucca.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/douglaslange/ProjectsCpp/Labyrinth/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lucca.dir/src/lucca.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lucca.dir/src/lucca.cpp.o -c /Users/douglaslange/ProjectsCpp/Labyrinth/src/lucca.cpp

CMakeFiles/lucca.dir/src/lucca.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lucca.dir/src/lucca.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/douglaslange/ProjectsCpp/Labyrinth/src/lucca.cpp > CMakeFiles/lucca.dir/src/lucca.cpp.i

CMakeFiles/lucca.dir/src/lucca.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lucca.dir/src/lucca.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/douglaslange/ProjectsCpp/Labyrinth/src/lucca.cpp -o CMakeFiles/lucca.dir/src/lucca.cpp.s

CMakeFiles/lucca.dir/lucca/main.cpp.o: CMakeFiles/lucca.dir/flags.make
CMakeFiles/lucca.dir/lucca/main.cpp.o: ../lucca/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/douglaslange/ProjectsCpp/Labyrinth/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lucca.dir/lucca/main.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lucca.dir/lucca/main.cpp.o -c /Users/douglaslange/ProjectsCpp/Labyrinth/lucca/main.cpp

CMakeFiles/lucca.dir/lucca/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lucca.dir/lucca/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/douglaslange/ProjectsCpp/Labyrinth/lucca/main.cpp > CMakeFiles/lucca.dir/lucca/main.cpp.i

CMakeFiles/lucca.dir/lucca/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lucca.dir/lucca/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/douglaslange/ProjectsCpp/Labyrinth/lucca/main.cpp -o CMakeFiles/lucca.dir/lucca/main.cpp.s

# Object files for target lucca
lucca_OBJECTS = \
"CMakeFiles/lucca.dir/src/labyrinth.cpp.o" \
"CMakeFiles/lucca.dir/src/lucca.cpp.o" \
"CMakeFiles/lucca.dir/lucca/main.cpp.o"

# External object files for target lucca
lucca_EXTERNAL_OBJECTS =

lucca: CMakeFiles/lucca.dir/src/labyrinth.cpp.o
lucca: CMakeFiles/lucca.dir/src/lucca.cpp.o
lucca: CMakeFiles/lucca.dir/lucca/main.cpp.o
lucca: CMakeFiles/lucca.dir/build.make
lucca: CMakeFiles/lucca.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/douglaslange/ProjectsCpp/Labyrinth/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lucca"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lucca.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lucca.dir/build: lucca

.PHONY : CMakeFiles/lucca.dir/build

CMakeFiles/lucca.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lucca.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lucca.dir/clean

CMakeFiles/lucca.dir/depend:
	cd /Users/douglaslange/ProjectsCpp/Labyrinth/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/douglaslange/ProjectsCpp/Labyrinth /Users/douglaslange/ProjectsCpp/Labyrinth /Users/douglaslange/ProjectsCpp/Labyrinth/build /Users/douglaslange/ProjectsCpp/Labyrinth/build /Users/douglaslange/ProjectsCpp/Labyrinth/build/CMakeFiles/lucca.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lucca.dir/depend

