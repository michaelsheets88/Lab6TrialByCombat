# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\MyDocs\Documents\Lab6TrialByCombat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\MyDocs\Documents\Lab6TrialByCombat

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	"C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe" -E echo "No interactive CMake dialog available."
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe" -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start D:\MyDocs\Documents\Lab6TrialByCombat\CMakeFiles D:\MyDocs\Documents\Lab6TrialByCombat\CMakeFiles\progress.marks
	$(MAKE) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start D:\MyDocs\Documents\Lab6TrialByCombat\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Wumpus

# Build rule for target.
Wumpus: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 Wumpus
.PHONY : Wumpus

# fast build rule for target.
Wumpus/fast:
	$(MAKE) -f CMakeFiles\Wumpus.dir\build.make CMakeFiles/Wumpus.dir/build
.PHONY : Wumpus/fast

Legos.obj: Legos.cpp.obj

.PHONY : Legos.obj

# target to build an object file
Legos.cpp.obj:
	$(MAKE) -f CMakeFiles\Wumpus.dir\build.make CMakeFiles/Wumpus.dir/Legos.cpp.obj
.PHONY : Legos.cpp.obj

Legos.i: Legos.cpp.i

.PHONY : Legos.i

# target to preprocess a source file
Legos.cpp.i:
	$(MAKE) -f CMakeFiles\Wumpus.dir\build.make CMakeFiles/Wumpus.dir/Legos.cpp.i
.PHONY : Legos.cpp.i

Legos.s: Legos.cpp.s

.PHONY : Legos.s

# target to generate assembly for a file
Legos.cpp.s:
	$(MAKE) -f CMakeFiles\Wumpus.dir\build.make CMakeFiles/Wumpus.dir/Legos.cpp.s
.PHONY : Legos.cpp.s

main.obj: main.cpp.obj

.PHONY : main.obj

# target to build an object file
main.cpp.obj:
	$(MAKE) -f CMakeFiles\Wumpus.dir\build.make CMakeFiles/Wumpus.dir/main.cpp.obj
.PHONY : main.cpp.obj

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles\Wumpus.dir\build.make CMakeFiles/Wumpus.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles\Wumpus.dir\build.make CMakeFiles/Wumpus.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... Wumpus
	@echo ... rebuild_cache
	@echo ... Legos.obj
	@echo ... Legos.i
	@echo ... Legos.s
	@echo ... main.obj
	@echo ... main.i
	@echo ... main.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

