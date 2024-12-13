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
    //this->m_window.getRenderer().testGameObject->setLayer(200);
    //this->registerGameObject(this->m_window.getRenderer().testGameObject);
    //GameObject* other = new GameObject(*this->m_window.getRenderer().testGameObject);
    //other->setX(1000);
    //other->setY(1000);
    //other->setScale(1.5F);
    //other->setLayer(21);
    //this->registerGameObject(other);

    std::string name = "GAME";

    this->m_scene = new Scene(name);

    m_scene->loadGameObjects(this);
    m_scene->initScene(this);

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

        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
            Vector2i* size = this->getWindow().getDimensions();
            size->setX(event.window.data1);
            size->setY(event.window.data2);
        }

        this->m_keyInputHandler.handleEvent(event);
    }
}

Vector2i Game::toWorldPosition(int screenX, int screenY) {
    Vector2i pos(screenX, screenY);
    pos -= this->m_window.getCenter();
    this->m_window.getCamera().negateOffset(pos);
    return pos;
}

Vector2i Game::toScreenPos(const int worldX, const int worldY) {
    Vector2i pos(worldX, worldY);
    pos += this->m_window.getCenter();
    this->m_window.getCamera().applyOffset(pos);
    return pos;
}

void Game::offsetToWorldPosition(Vector2i &pos) {
    pos = toWorldPosition(pos.getX(), pos.getY());
}

void Game::offsetToScreenPosition(Vector2i &pos) {
    pos = toScreenPos(pos.getX(), pos.getY());
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
    gameObject->registerObject();
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

Window& Game::getWindow() {
    return this->m_window;
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


