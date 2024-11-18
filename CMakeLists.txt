cmake_minimum_required(VERSION 3.29)
project(SDLRenderer)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/SDL2")


add_executable(SDLRenderer main.cpp
        Window.cpp
        Window.h
        Game.cpp
        Game.h
        Renderer.cpp
        Renderer.h)


find_package(SDL2 REQUIRED)
include_directories("${SDL2_INCLUDE_DIRS}")
target_link_libraries(SDLRenderer SDL2::SDL2)





