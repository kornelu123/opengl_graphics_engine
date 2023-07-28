cmake_minimum_required(VERSION 3.24)

project(opengl_graphics_engine)

set(CMAKE_CXX_STANDARD 17)

include_directories(
	${PROJECT_SOURCE_DIR}/inc
	${PROJECT_SOURCE_DIR}/src
)

file(GLOB ALL_SRC
	"${PROJECT_SOURCE_DIR}/inc/*.h"
	"${PROJECT_SOURCE_DIR}/src/*.c"
)

add_executable(opengl_graphics_engine ${ALL_SRC})

find_library(GLUT libglut.so)
find_library(GL libGL.so)
find_library(GLFW libglfw3.a)


target_link_libraries(opengl_graphics_engine ${GLUT} ${GL} ${GLFW}  m)
