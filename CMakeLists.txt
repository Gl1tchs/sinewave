cmake_minimum_required(VERSION 3.23)

set(_ ${CMAKE_CURRENT_LIST_DIR})

project("sinewave"
	VERSION "1.0"
	DESCRIPTION "Sinewave Animation Using OpenGL"
	LANGUAGES CXX
)

add_executable(sinewave
${_}/include/color.hpp ${_}/include/object.hpp
${_}/include/pyramid.hpp ${_}/include/transform.hpp
${_}/include/vector.hpp ${_}/src/object.cpp
${_}/src/pyramid.cpp ${_}/src/main.cpp
)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)
find_package(GLU REQUIRED)

add_dependencies(sinewave OpenGL::OpenGL)

include_directories(${GLUT_INCLUDE_DIRS} ${_}/include/)

target_link_libraries(sinewave OpenGL::OpenGL GLUT::GLUT GLU)
