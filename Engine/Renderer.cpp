//
// Created by Hypericats on 11/18/2024.
//

#include "Renderer.h"

#include <cstdio>
#include <iostream>
#include <ostream>
#include <random>
#include <SDL.h>

bool Renderer::init() {
    std::string path = "test.bmp";
    Sprite* sprite = Sprite::fromBMP(path, m_windowSurface->format);

    testGameObject = new GameObject(std::move(*sprite));
    // Delete old instance
    delete sprite;
    return true;
}

void Renderer::update() {
    //nothing for now
}


void Renderer::render() const {
    // Render frame to the screen DON'T CALL THIS MORE THAN ONCE PER FRAME
    SDL_RenderPresent(this->m_renderer);
}

void Renderer::testRender() const {
    //background color
    SDL_SetRenderDrawColor(this->m_renderer, 255, 0, 0, 255);
    SDL_RenderClear(this->m_renderer);

    SDL_GetMouseState(testGameObject->getXPtr(), testGameObject->getYPtr());

    SDL_Rect rect = rectCentered(testGameObject->getX(), testGameObject->getY(), 50, 50);

    //rect color
    SDL_SetRenderDrawColor(this->m_renderer, 0, 255, 0, 255);

    // Render rect
    SDL_RenderFillRect(this->m_renderer, &rect);

    renderGameObject(testGameObject);
}

void Renderer::initRender() const {
    SDL_RenderClear(this->m_renderer);
}

void Renderer::renderTex(SDL_Texture *texture, const SDL_Rect *dimensions) const {
    SDL_RenderCopy(m_renderer, texture, NULL, dimensions);
    //SDL_UpdateWindowSurface(m_window); // Might not need to be called every frame
}

void Renderer::renderSprite(const Sprite *sprite, int x, int y) const {
    renderSprite(sprite, x, y, sprite->getWidth(), sprite->getHeight());
}

void Renderer::renderSprite(const Sprite *sprite, int x, int y, int width, int height) const {
    SDL_Rect dimensions;
    dimensions.x = x;
    dimensions.y = y;
    dimensions.w = width;
    dimensions.h = height;
    this->renderTex(sprite->getTexture(), &dimensions);
}

void Renderer::renderGameObject(const GameObject *gameObject) const {
    Vector2i pos(gameObject->getX(), gameObject->getY());
    this->m_camera->applyOffset(pos);
    renderSprite(gameObject->getSprite(), pos.getX(), pos.getY(), gameObject->getScaledWidth(), gameObject->getScaledHeight());
}


void Renderer::renderCenteredSprite(const Sprite *sprite, int x, int y) const {
    SDL_Rect dimensions;
    dimensions.x = x - (sprite->getWidth() >> 1);
    dimensions.y = y - (sprite->getHeight() >> 1);
    dimensions.w = sprite->getWidth();
    dimensions.h = sprite->getHeight();
    this->renderTex(sprite->getTexture(), &dimensions);
}


void Renderer::destroy() const {
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
