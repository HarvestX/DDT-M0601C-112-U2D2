cmake_minimum_required(VERSION 3.13.0)
project(DDT_M0601C_112_U2D2)

add_definitions(-std=c++14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(TARGET ${PROJECT_NAME})
add_executable(${TARGET})
target_sources(${TARGET} PUBLIC src/main.cpp src/usart.cpp)
target_include_directories(${TARGET} PUBLIC include/${PROJECT_NAME})
