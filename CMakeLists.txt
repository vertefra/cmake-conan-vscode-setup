cmake_minimum_required(VERSION 3.0.0)
project(CMakeTemplate VERSION 0.0.1)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Project executables
set(project_sources
    src/main.cpp
    src/lib/Engine.cpp
)

# class headers
include_directories(src/include)

# Adding executable and conan classes to linker
add_executable(main ${project_sources})
target_link_libraries(main ${CONAN_LIBS})





