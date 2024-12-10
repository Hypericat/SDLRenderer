cmake_minimum_required(VERSION 3.29)
project(SDLRenderer)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/SDL2")


add_executable(SDLRenderer main.cpp
        Engine/Window.cpp
        Engine/Window.h
        Game/Game.cpp
        Game/Game.h
        Engine/Renderer.cpp
        Engine/Renderer.h
        Engine/Sprite.cpp
        Engine/Sprite.h
        Engine/GameObject.cpp
        Engine/GameObject.h
        Engine/GameObjectDispatcher.cpp
        Engine/GameObjectDispatcher.h
        Engine/Camera.cpp
        Engine/Camera.h
)


find_package(SDL2 REQUIRED)

include_directories("${SDL2_INCLUDE_DIRS}")

target_link_libraries(SDLRenderer SDL2::SDL2)




#set(GLEW_INCLUDE_DIR "glew-2.2.0/include")
#
#set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/glew-2.2.0)
#
#find_package(glew-2.2.0 REQUIRED)
#
#target_link_libraries(engine PUBLIC ${GLEW_LIBRARY})





