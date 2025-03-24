//
// Created by Hypericats on 11/18/2024.
//

#include "Game.h"

#include <chrono>
#include <iostream>
#include <SDL_events.h>
#include <SDL_timer.h>

#include "Scenes/Level.h"
#include "Scenes/MainMenu.h"
#include "Scenes/TestScene.h"

Game::Game(Window &window): m_window(window), m_keyInputHandler(window) {


}

void Game::run() {
    this->loadScene(new Level(this));

    this->running = true;


    Uint64 startFrameTime;
    while (this->running) {
        startFrameTime = SDL_GetPerformanceCounter();

        pollWindowEvents();
        updatePhysics();
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
    Vector2i pos(-screenX, -screenY);
    pos -= this->m_window.getCenter();
    this->m_window.getCamera().applyOffset(pos);
    return pos;
}

Vector2i Game::toScreenPos(const int worldX, const int worldY) {
    Vector2i pos(-worldX, -worldY);
    pos += this->m_window.getCenter();
    this->m_window.getCamera().negateOffset(pos);
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

void Game::updatePhysics() {
    Player* player = this->m_scene->getPlayer();
    if (player == nullptr) return;

    // Update controls before so the camera does not lag behind
    player->updateControls(this->m_keyInputHandler, this);
    player->tickPhysics(this);
    player->updateBoundingBox();

    bool playerCollidedDown = false;
    //Update physics and such
    for (const std::pair<int, GameObject*> pair : m_layerObjects) {
        if (pair.second->isCollideable() && pair.second->getId() != player->getId()) {
            if (Direction::ENUM dir = pair.second->getBoundingBox().testCollision(player->getBoundingBox()); dir != Direction::NONE) {
                // Both player & object will receive the collide event
                player->onCollision(pair.second, dir);
                pair.second->onCollision(player, dir);
                player->updateBoundingBox();
                if (dir == Direction::DOWN) {
                    playerCollidedDown = true;
                }
                continue;
            }
        }

        pair.second->updateBoundingBox();
    }

    if (!playerCollidedDown) {
        player->setOnGround(false);
    }

    this->getWindow().getCamera().setPos(player->getPos());
}

void Game::renderFrame() {
    this->m_window.getRenderer().initRender();

    this->m_scene->onRender(this);
    for (GameObject* bg : this->m_scene->getBackgrounds()) {
        this->m_window.getRenderer().renderGameObject(bg);
    }
    // Render GameObjects
    for (const std::pair<int, GameObject*> pair : m_layerObjects) {
        if (!pair.second->isVisible()) continue;

        this->m_window.getRenderer().renderGameObject(pair.second);
        if (pair.second->shouldDrawHitbox())
            this->m_window.getRenderer().drawBox(pair.second->getBoundingBox());



        if(!pair.second->isCollideable()) {
            this->m_window.getRenderer().drawLine(pair.second->getPos(), this->getScene()->getPlayer()->getBoundingBox().getCenter());
        }
    }
    //this->window.getRenderer().testRender();
    this->m_window.getRenderer().render();


    //Post frame render
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
        if (it->second->getId() == gameObject->getId()) {
            m_layerObjects.erase(it);
            break;
        }
    }
    delete ptr;
}

Scene* Game::getScene() {
    return this->m_scene;
}

void Game::freeGameObject(const unsigned long* id) {
    freeGameObject(getObjectByID(id));
}

Window& Game::getWindow() {
    return this->m_window;
}

void Game::loadScene(Scene *scene) {
    if (this->m_scene != nullptr && scene != m_scene) {
        this->m_scene->freeScene();
        delete m_scene;
    }


    this->m_scene = scene;
    scene->loadGameObjects(this);
    scene->initScene(this);
}

void Game::updateTestControls() const {
    if (this->m_keyInputHandler.isKeyDown(SDL_SCANCODE_W))
        this->m_window.getCamera().setY(m_window.getCamera().getY() + 10);
    if (this->m_keyInputHandler.isKeyDown(SDL_SCANCODE_S))
        this->m_window.getCamera().setY(m_window.getCamera().getY() - 10);
    if (this->m_keyInputHandler.isKeyDown(SDL_SCANCODE_A))
        this->m_window.getCamera().setX(m_window.getCamera().getX() + 10);
    if (this->m_keyInputHandler.isKeyDown(SDL_SCANCODE_D))
        this->m_window.getCamera().setX(m_window.getCamera().getX() - 10);
}


