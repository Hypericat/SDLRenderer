//
// Created by Hypericats on 12/12/2024.
//

#include "Scene.h"

#include <iostream>

#include "../../Game/Game.h"

Scene::Scene(const std::string& name, Game* game) {
    this->m_name = name;
    this->m_game = game;
}

void Scene::initScene(Game* game) {
    this->m_decorationHandler = new DecorationHandler(game, this);
}

void Scene::initGameObject(GameObject *gameObject, Game* game) {
    this->m_gameObjects.emplace(*gameObject->getId(), gameObject);
    game->registerGameObject(gameObject);
}

std::string& Scene::getName() {
    return m_name;
}

void Scene::initCamera(Camera *camera) {
    camera->setX(0);
    camera->setY(0);
}

std::vector<GameObject*>& Scene::getBackgrounds() {
    return this->backgrounds;
}

GameObject* Scene::getGameObject(unsigned long *id) {
    return this->m_gameObjects.at(*id);
}

void Scene::freeGameObject(const unsigned long *id) {
    this->m_gameObjects.erase(*id);
    this->m_game->freeGameObject(id);
}

void Scene::freeScene() {
    for (const GameObject* background : this->backgrounds) {
        delete background;
    }
    backgrounds.clear();

    for (std::pair<unsigned long, GameObject*> p : this->m_gameObjects) {
        delete p.second;
    }

    this->m_gameObjects.clear();
    delete this->m_decorationHandler;
}

Player* Scene::getPlayer() {
    return this->m_player;
}

void Scene::updateDecorations(Game* game) {

}

void Scene::onRender(Game* game) {
    this->updateBackground(game);
    this->updateDecorations(game);
}

void Scene::updateBackground(Game *game) {
    if (this->backgrounds.empty()) return;
    const Camera* camera = &game->getWindow().getCamera();
    GameObject* background = this->backgrounds.at(0);
    int width = background->getRenderWidth();
    int height = background->getRenderHeight();

    // This rounds it down, it's not completely useless
    int finalY = camera->getY() / height * height;
    int finalX   = camera->getX() / width * width;



    int xSign = game->getWindow().getCamera().getX() & SIGN_BIT_MASK | 1;
    int ySign = game->getWindow().getCamera().getY() & SIGN_BIT_MASK | 1;

    // Set to -1 if -2147483647
    if (xSign & SIGN_BIT_MASK) {
        // Value is negative
        xSign = -1;
    }
    if (ySign & SIGN_BIT_MASK) {
        // Value is negative
        ySign = -1;
    }

    background->setY(finalY);
    background->setX(finalX);

    this->backgrounds.at(1)->setX(finalX + width * xSign);
    this->backgrounds.at(1)->setY(finalY);

    this->backgrounds.at(2)->setX(finalX);
    this->backgrounds.at(2)->setY(finalY + height * ySign);

    this->backgrounds.at(3)->setX(finalX + width * xSign);
    this->backgrounds.at(3)->setY(finalY + height * ySign);
}

DecorationHandler* Scene::getDecorationHandler() const {
    return this->m_decorationHandler;
}

void Scene::populateBackground(GameObject *bg) {
    bg->setX(0);
    bg->setY(0);
    this->backgrounds.reserve(4);
    this->backgrounds.push_back(bg);
    this->backgrounds.push_back(new GameObject(*bg));
    this->backgrounds.push_back(new GameObject(*bg));
    this->backgrounds.push_back(new GameObject(*bg));
}
