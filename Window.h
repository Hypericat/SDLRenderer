//
// Created by Hypericats on 11/18/2024.
//

#ifndef WINDOW_H
#define WINDOW_H
#include <SDL_video.h>
#include <string>

#include "Renderer.h"


class Window {
private:
    SDL_Window* m_sdlWindow{};
    Renderer *m_renderer{};
    int m_width;
    int m_height;



public:
    Window(int width, int height) {
        this->m_width = width;
        this->m_height = height;
    }

    void initWindow(std::string name, int flags);
    void destroyWindow() const;

    SDL_Window *getSDLWindow();
    Renderer &getRenderer();


};



#endif //WINDOW_H
