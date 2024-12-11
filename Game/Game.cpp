//
// Created by Hypericats on 11/18/2024.
//

#include "Game.h"

#include <iostream>
#include <SDL_events.h>
#include <SDL_timer.h>

Game::Game(Window &window): m_window(window), m_keyInputHandler(window) {

}

void Game::run() {
    this->registerGameObject(this->m_window.getRenderer().testGameObject);
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
        this->m_keyInputHandler.handleEvent(event);
    }
}

void Game::stop() {
    this->running = false;
}

void Game::renderFrame() const {
    //Update physics and such


    // Render GameObjects
    for (const std::pair<unsigned long, GameObject*> pair : objects) {
        this->m_window.getRenderer().renderGameObject(pair.second);
    }
    //this->window.getRenderer().testRender();
    this->m_window.getRenderer().render();
}

void Game::registerGameObject(GameObject *gameObject) {
    objects.insert({*gameObject->getId(), gameObject});
}

void Game::freeGameObject(GameObject *gameObject) {
    const GameObject* ptr = objects.at(*gameObject->getId());
    objects.erase(*gameObject->getId());
    delete ptr;
}

void Game::freeGameObject(const unsigned long* id) {
    const GameObject* ptr = objects.at(*id);
    objects.erase(*id);
    delete ptr;
}


