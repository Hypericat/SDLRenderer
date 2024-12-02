//
// Created by Hypericats on 11/18/2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <memory>
#include <SDL.h>

#include "Sprite.h"


class Renderer {
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Surface *m_windowSurface;
    bool gRenderQuad = true;
    void renderTex(SDL_Texture *texture) const;
    void renderSprite(Sprite *sprite) const;


public:
    bool init();
    void update();
    void render();
    void destroy();

    Sprite* testSprite = nullptr;

    static SDL_Rect rectCentered(int x, int y, int width, int height);
    static SDL_Rect rectCoord(int x1, int y1, int x2, int y2);
    static SDL_Rect rect(int x1, int y1, int x2, int y2);

    Renderer(SDL_Window *window, SDL_Renderer* renderer): m_window(window), m_renderer(renderer), m_windowSurface(SDL_GetWindowSurface(m_window)) {

    }


};



#endif //RENDERER_H
