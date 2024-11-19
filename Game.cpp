//
// Created by Hypericats on 11/18/2024.
//

#include "Game.h"

#include <iostream>
#include <SDL_events.h>
#include <SDL_timer.h>

Game::Game(Window &window): window(window) {

}

void Game::run() {
    this->running = true;


    Uint64 startFrameTime;
    while (this->running) {
        startFrameTime = SDL_GetPerformanceCounter();

        pollWindowEvents();
        renderFrame();
        lastFrameDelta = (SDL_GetPerformanceCounter() - startFrameTime) * 1000 / (float) SDL_GetPerformanceFrequency();

        int sleepTime = int (TARGET_FRAME_DELTA - lastFrameDelta);
        if (sleepTime > 0)
            SDL_Delay(sleepTime);
    }
}

float Game::getFrameDelta() const {
    return this->lastFrameDelta;
}

void Game::pollWindowEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            std::cout << "Quitting!" << std::endl;
            this->stop();
        }
    }
}

void Game::stop() {
    this->running = false;
}

void Game::renderFrame() {
    this->window.getRenderer().render();
    SDL_GL_SwapWindow(window.getSDLWindow());
}


