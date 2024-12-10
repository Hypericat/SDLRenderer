//
// Created by Hypericats on 11/18/2024.
//

#ifndef WINDOW_H
#define WINDOW_H
#include <SDL_video.h>
#include <string>

#include "Camera.h"
#include "Renderer.h"


class Window {
private:
    SDL_Window* m_sdlWindow{};
    Renderer *m_renderer{};
    Camera m_camera{};
    int m_width;
    int m_height;



public:
    Window(int width, int height) {
        this->m_width = width;
        this->m_height = height;
    }

    void initWindow(std::string name, int flags);
    void destroyWindow() const;

    SDL_Window* getSDLWindow();
    Renderer& getRenderer();
    Camera& getCamera();


};



#endif //WINDOW_H
