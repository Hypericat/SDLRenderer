//
// Created by Hypericats on 11/18/2024.
//

#ifndef WINDOW_H
#define WINDOW_H
#include <SDL_video.h>
#include <string>

#include "Camera.h"
#include "Renderer.h"

class Game;

class Window {
private:
    SDL_Window* m_sdlWindow{};
    Renderer *m_renderer{};
    Camera m_camera{};
    Vector2i dimensions {0, 0};



public:
    Window(int width, int height) {
        this->dimensions.setX(width);
        this->dimensions.setY(height);
    }

    void initWindow(std::string name, int flags, Game *game);
    void destroyWindow() const;
    Vector2i getCenter() const;


    Vector2i* getDimensions();

    SDL_Window* getSDLWindow() const;
    Renderer& getRenderer() const;
    Camera& getCamera();


};



#endif //WINDOW_H
