cmake_minimum_required(VERSION 3.1.0)
project(DDT_M0601C_112_U2D2)

add_definitions(-std=c++14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(TARGET ${PROJECT_NAME} PRIVATE src/main.cpp)
add_executable(${TARGET})
target_sources(${TARGET})
target_include_directories(${TARGET} PUBLIC include)
