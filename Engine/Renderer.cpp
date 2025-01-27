//
// Created by Hypericats on 11/18/2024.
//

#include "Renderer.h"

#include <cstdio>
#include <iostream>
#include <random>
#include <SDL.h>
#include "../Game/Game.h"
#include "Window.h"


Renderer::Renderer(Game *game, SDL_Renderer *renderer) : m_renderer(renderer), m_windowSurface(SDL_GetWindowSurface(game->getWindow().getSDLWindow())) {
    this->m_game = game;
    this->m_window = &game->getWindow();
    this->m_camera = &m_window->getCamera();
    this->m_renderer = renderer;
}

bool Renderer::init() {
    std::string path = "test.bmp";
    Sprite* sprite = Sprite::fromBMP(path);

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

    int x = 0;
    int y = 0;
    SDL_GetMouseState(&x, &y);

    Vector2i worldPos = m_game->toWorldPosition(x, y);
}

void Renderer::testRender() {
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
    SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->m_renderer);
}

void Renderer::renderTex(SDL_Texture *texture, const SDL_Rect *dimensions, const SDL_RendererFlip flip) const {
    SDL_RenderCopyEx(m_renderer, texture, nullptr, dimensions, 0, nullptr, flip);
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
    this->renderTex(sprite->getTexture(), &dimensions, sprite->getFlip());
}

void Renderer::renderGameObject(GameObject *gameObject) const {
    gameObject->preRender(m_game);


    // Adjust for the fact that positions are centered
    Vector2i pos = Vector2i(gameObject->getX(), gameObject->getY());

    gameObject->applyTextureYOffset(pos);
    gameObject->applyTextureXOffset(pos);

    this->m_game->offsetToScreenPosition(pos);

    pos -= Vector2i(gameObject->getRenderWidth() >> 1, gameObject->getRenderHeight() >> 1);
    renderSprite(gameObject->getSprite(), pos.getX(), pos.getY(), gameObject->getRenderWidth(), gameObject->getRenderHeight());

    //if (gameObject->getSprite()->getPath() == "C:\\Users\\Hypericats\\CLionProjects\\SDLRenderer\\cmake-build-debug\\assets\\textures\\player\\zappysmoke00.png")
    //    std::cout << gameObject->getSprite()->getPath() << std::endl;

    gameObject->postRender(m_game);

}

void Renderer::renderCenteredSprite(const Sprite *sprite, int x, int y) const {
    SDL_Rect dimensions;
    dimensions.x = x - (sprite->getWidth() >> 1);
    dimensions.y = y - (sprite->getHeight() >> 1);
    dimensions.w = sprite->getWidth();
    dimensions.h = sprite->getHeight();
    this->renderTex(sprite->getTexture(), &dimensions, sprite->getFlip());
}

void Renderer::drawLine(const Vector2i &pos1, const Vector2i &pos2) const {
    SDL_SetRenderDrawColor(this->m_renderer, 0, 255, 0, 255);
    const Vector2i screenPos1 = m_game->toScreenPos(pos1.getX(), pos1.getY());
    const Vector2i screenPos2 = m_game->toScreenPos(pos2.getX(), pos2.getY());
    SDL_RenderDrawLine(this->m_renderer, screenPos1.getX(), screenPos1.getY(), screenPos2.getX(), screenPos2.getY());
}

void Renderer::drawBox(const Box &box) const {
    Vector2i topLeft = box.getMax();
    Vector2i bottomRight = box.getMin();
    topLeft.setX(box.getMin().getX());
    bottomRight.setX(box.getMax().getX());

    drawLine(box.getMax(), topLeft);
    drawLine(topLeft, box.getMin());
    drawLine(box.getMin(), bottomRight);
    drawLine(bottomRight, box.getMax());
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
