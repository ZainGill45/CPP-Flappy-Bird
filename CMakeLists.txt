cmake_minimum_required(VERSION 4.0.1)
project(LearningCPP VERSION 0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64_windows")

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/assets
    COMMENT "Copying assets to build directory"
)

find_package(raylib CONFIG REQUIRED)
add_executable(cpp-flappy-bird main.cpp)
add_dependencies(cpp-flappy-bird copy_assets)

target_link_libraries(cpp-flappy-bird PRIVATE raylib)