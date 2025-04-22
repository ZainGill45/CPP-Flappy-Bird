cmake_minimum_required(VERSION 4.0.1)
project(LearningCPP VERSION 0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64_windows")

find_package(raylib CONFIG REQUIRED)
add_executable(learning-cpp main.cpp)

target_link_libraries(learning-cpp PRIVATE raylib)