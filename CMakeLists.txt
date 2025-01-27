cmake_minimum_required(VERSION 3.29)
project(SDLRenderer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SDLRenderer main.cpp
        Engine/Window.cpp
        Engine/Window.h
        Game/Game.cpp
        Game/Game.h
        Engine/Renderer.cpp
        Engine/Renderer.h
        Engine/Sprite.cpp
        Engine/Sprite.h
        Engine/Scene/GameObject.cpp
        Engine/Scene/GameObject.h
        Engine/Scene/GameObjectDispatcher.cpp
        Engine/Scene/GameObjectDispatcher.h
        Engine/Camera.cpp
        Engine/Camera.h
        Engine/Math/Vector2i.cpp
        Engine/Math/Vector2i.h
        Engine/Math/Vector2f.cpp
        Engine/Math/Vector2f.h
        Engine/Input/KeyInputHandler.cpp
        Engine/Input/KeyInputHandler.h
        Engine/Util.cpp
        Engine/Util.h
        Engine/Scene/Scene.cpp
        Engine/Scene/Scene.h
        Game/Scenes/TestScene.cpp
        Game/Scenes/TestScene.h
        Game/Objects/Player.cpp
        Game/Objects/Player.h
        Engine/Math/Box.cpp
        Engine/Math/Box.h
        Game/Objects/WallObject.cpp
        Game/Objects/WallObject.h
        Engine/Math/Direction.h
        Engine/Scene/Animation.cpp
        Engine/Scene/Animation.h
        Game/Objects/PlayerHair.cpp
        Game/Objects/PlayerHair.h
        Game/Objects/FacingDirection.h
        Game/Objects/PlayerState.h
        Game/Objects/SmallPlatform.cpp
        Game/Objects/SmallPlatform.h
        Game/Objects/MediumPlatform.cpp
        Game/Objects/MediumPlatform.h
        Game/Scenes/Level.cpp
        Game/Scenes/Level.h
        Game/Scenes/MainMenu.cpp
        Game/Scenes/MainMenu.h
        Game/Objects/JumpParticles.cpp
        Game/Objects/JumpParticles.h
        Game/Objects/TextObject.cpp
        Game/Objects/TextObject.h
)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/SDL2")
find_package(SDL2 REQUIRED)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/SDL2_image")
find_package(SDL2_image REQUIRED SDL2_image>=2.0.0)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/SDL2_ttf")
find_package(SDL2_ttf)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS}, "SDL2_ttf/x86_64-w64-mingw32/include")

target_link_libraries(SDLRenderer SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)


# Removes terminal and adds static libraries for release
if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -O3")
    target_link_options(SDLRenderer PRIVATE "-mwindows")
endif ()




#set(GLEW_INCLUDE_DIR "glew-2.2.0/include")
#
#set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/glew-2.2.0)
#
#find_package(glew-2.2.0 REQUIRED)
#
#target_link_libraries(engine PUBLIC ${GLEW_LIBRARY})





