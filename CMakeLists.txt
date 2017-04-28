cmake_minimum_required(VERSION 3.7)
project(Wumpus)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Trap.cpp Legos.h)
add_executable(Wumpus ${SOURCE_FILES} Trap.cpp Legos.h)