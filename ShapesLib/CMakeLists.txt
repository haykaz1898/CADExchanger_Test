cmake_minimum_required(VERSION 3.9.4)
set(CMAKE_CXX_STANDARD 17)


file(GLOB ShapesLib
     "*.h"
     "*.cpp"
)

add_library(ShapesLib SHARED ${ShapesLib})

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

