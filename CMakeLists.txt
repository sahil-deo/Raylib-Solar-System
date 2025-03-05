cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(SOLAR_SYSTEM)

set(RAYLIB_DIR "C:/Users/shree/Desktop/Code/c++/Raylib/RayLib Solar System/Libs")

link_directories(${PROJECT_SOURCE_DIR}/libs)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(Solar main.cpp)

target_link_libraries(Solar raylib opengl32 gdi32 winmm)