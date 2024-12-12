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
    this->m_window.getRenderer().testGameObject->setLayer(-200);
    this->registerGameObject(this->m_window.getRenderer().testGameObject);
    GameObject* other = new GameObject(*this->m_window.getRenderer().testGameObject);
    other->setX(500);
    other->setY(500);
    other->setScale(1.5F);
    other->setLayer(21);
    this->registerGameObject(other);

    // Need copy constructor for objects
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

void Game::renderFrame() {
    //Update physics and such
    this->updateTestControls();




    this->m_window.getRenderer().initRender();

    // Render GameObjects
    for (const std::pair<int, GameObject*> pair : m_layerObjects) {
        this->m_window.getRenderer().renderGameObject(pair.second);
    }
    //this->window.getRenderer().testRender();
    this->m_window.getRenderer().render();
}

GameObject* Game::getObjectByID(const unsigned long *id) {
    auto it = m_objects.find(*id);
    if (it != m_objects.end()) {
        return it->second;
    }
    return nullptr;
}

void Game::registerGameObject(GameObject *gameObject) {
    m_objects.insert({*gameObject->getId(), gameObject});
    m_layerObjects.insert({gameObject->getLayer(), gameObject});
}

void Game::freeGameObject(GameObject *gameObject) {
    const GameObject* ptr = m_objects.at(*gameObject->getId());
    m_objects.erase(*gameObject->getId());

    auto range = m_layerObjects.equal_range(gameObject->getLayer());
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == gameObject) {
            m_layerObjects.erase(it);
            break;
        }
    }
    delete ptr;
}

void Game::freeGameObject(const unsigned long* id) {
    freeGameObject(getObjectByID(id));
}

void Game::updateTestControls() const {
    if (this->m_keyInputHandler.isKeyDown(SDL_SCANCODE_W))
        this->m_window.getCamera().setY(m_window.getCamera().getY() - 10);
    if (this->m_keyInputHandler.isKeyDown(SDL_SCANCODE_S))
        this->m_window.getCamera().setY(m_window.getCamera().getY() + 10);
    if (this->m_keyInputHandler.isKeyDown(SDL_SCANCODE_A))
        this->m_window.getCamera().setX(m_window.getCamera().getX() - 10);
    if (this->m_keyInputHandler.isKeyDown(SDL_SCANCODE_D))
        this->m_window.getCamera().setX(m_window.getCamera().getX() + 10);
}


