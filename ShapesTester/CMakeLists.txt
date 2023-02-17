
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/ShapesLib
					${PROJECT_SOURCE_DIR}/ShapesTester)

add_executable(Shapes ShapesTester.cpp)

target_link_libraries(Shapes ShapesLib)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

set_target_properties(
		Shapes
		PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)