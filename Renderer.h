//
// Created by Hypericats on 11/18/2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>



class Renderer {
private:
    SDL_Window *window;
    SDL_GLContext context;
    bool gRenderQuad = true;


public:
    bool init();
    void update();
    void render();
    void close();

    Renderer(SDL_Window *window, SDL_GLContext context): window(window), context(context) {};


};



#endif //RENDERER_H
