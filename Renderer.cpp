//
// Created by Hypericats on 11/18/2024.
//

#include "Renderer.h"

#include <cstdio>
#include <iostream>
#include <ostream>
#include <SDL.h>

bool Renderer::init() {
    std::string path = "test.bmp";
    testSprite = Sprite::fromBMP(path, m_windowSurface->format);
    return true;
}

void Renderer::update() {
    //nothing for now
}

void Renderer::render() {

    //background color
    SDL_SetRenderDrawColor(this->m_renderer, 255, 0, 0, 255);
    SDL_RenderClear(this->m_renderer);

    int* mouseX = new int();
    int* mouseY = new int();
    SDL_GetMouseState(mouseX, mouseY);

    SDL_Rect rect = rectCentered(*mouseX, *mouseY, 50, 50);

    //std::cout << *mouseX << " " << *mouseY << std::endl;

    delete mouseX;
    delete mouseY;

    //rect color
    SDL_SetRenderDrawColor(this->m_renderer, 0, 255, 0, 255);

    // Render rect
    SDL_RenderFillRect(this->m_renderer, &rect);


    // Render the rect to the screen DONT CALL THIS MORE THAN ONCE PER FRAME
    //SDL_RenderPresent(this->m_renderer);

    renderTex(testSprite->getTexture());

    //SDL_UpdateWindowSurface(m_window);

    SDL_RenderPresent(this->m_renderer);
}

void Renderer::renderTex(SDL_Texture *texture) const {
    SDL_Rect rect = rectCentered(50, 50, 50, 50);

    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, texture, NULL, &rect);

    SDL_UpdateWindowSurface(m_window);

}

void Renderer::renderSprite(Sprite *sprite) const {
    if (sprite == nullptr) {
        std::cout << "sprite is null" << std::endl;
    }
    this->renderTex(sprite->getTexture());
}

void Renderer::destroy() {
    SDL_FreeSurface(this->m_windowSurface);
}

SDL_Rect Renderer::rectCentered(int x, int y, int width, int height) {
    SDL_Rect r;
    r.x = x - (width >> 1);
    r.y = y - (height >> 1);
    r.w = width;
    r.h = height;
    return r;
}

SDL_Rect Renderer::rectCoord(int x1, int y1, int x2, int y2) {
    int temp;
    if (x1 > x2) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    return rect(x1, y1, x2 - x1, y2 - y1);
}

SDL_Rect Renderer::rect(int x, int y, int width, int height) {
    return SDL_Rect { x, y, width, height };
}
