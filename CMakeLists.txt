cmake_minimum_required(VERSION 3.0.0)
project(Pong VERSION 0.1.0)

# ====== Project settings ======

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Pong ./src/main.cpp)

# ====== Project libraries ======

target_include_directories(Pong PRIVATE ./include)
add_library(Fake STATIC ./lib/Fake.cpp)
target_link_libraries(Pong ${CONAN_LIBS} Fake)

# ====== Conan libraries ========

include(./vendors/conanbuildinfo.cmake)
conan_basic_setup()





