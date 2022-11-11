cmake_minimum_required(VERSION 3.20)
project(untitled9)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled9 main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(untitled9 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

find_package(glm REQUIRED)
target_link_libraries(untitled9 glm::glm)