//
// Created by Hypericats on 11/18/2024.
//

#include "Window.h"

#include <iostream>
#include <ostream>
#include <SDL.h>
#include <string>

#include "Renderer.h"
#include "../Game/Game.h"

void Window::initWindow(std::string name, int flags, Game* game) {
    //should be null without init therefore this should only call the first time
    if (this->m_sdlWindow) return;

    std::cout << "Initializing SDL window..." << std::endl;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // Create Window
    this->m_sdlWindow = SDL_CreateWindow(
      name.c_str(),
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      this->dimensions.getX(),
      this->dimensions.getY(),
      flags
    );

    SDL_Renderer *internalRenderer = SDL_CreateRenderer(this->m_sdlWindow, -1, SDL_WINDOW_OPENGL);

    Sprite::renderer = internalRenderer;


    this->m_renderer = new Renderer(game, internalRenderer);
    this->m_renderer->init();
}

void Window::destroyWindow() const {
    m_renderer->destroy();
    SDL_DestroyWindow(this->m_sdlWindow);
    delete this->m_renderer;
}

Renderer &Window::getRenderer() const {
    return *this->m_renderer;
}

SDL_Window *Window::getSDLWindow() const {
    return this->m_sdlWindow;
}

Camera& Window::getCamera() {
    return this->m_camera;
}

Vector2i* Window::getDimensions() {
    return &this->dimensions;
}

Vector2i Window::getCenter() const {
    return Vector2i(dimensions.getX() >> 1, dimensions.getY() >> 1);
}
