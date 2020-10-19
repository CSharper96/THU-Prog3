cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

find_path(STB_INCLUDE_DIRS "stb.h")

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${STB_INCLUDE_DIRS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
