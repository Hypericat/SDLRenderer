//
// Created by Hypericats on 11/18/2024.
//

#include "Window.h"

#include <iostream>
#include <ostream>
#include <SDL.h>
#include <string>

#include "Renderer.h"

void Window::initWindow(std::string name, int flags) {
    //should be null without init therefore this should only call the first time
    if (this->m_sdlWindow) return;

    std::cout << "Initializing SDL window..." << std::endl;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

    // Create Window
    this->m_sdlWindow = SDL_CreateWindow(
      name.c_str(),
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      this->m_width,
      this->m_height,
      flags
    );

    //this->m_renderer = SDL_CreateRenderer(this->m_sdlWindow, -1, SDL_WINDOW_OPENGL);

    this->m_glContext = SDL_GL_CreateContext(this->m_sdlWindow);

    if(this->m_glContext == NULL) {
        printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
    }

    // just allocated it on the heap I don't care anymore
    this->m_renderer = new Renderer(m_sdlWindow, m_glContext);
    this->m_renderer->init();
}

void Window::destroyWindow() const {
    SDL_DestroyWindow(this->m_sdlWindow);
}

Renderer &Window::getRenderer() {
    return *this->m_renderer;
}

SDL_Window *Window::getSDLWindow() {
    return this->m_sdlWindow;
}

SDL_GLContext Window::getGlContext() {
    return this->m_glContext;
}
