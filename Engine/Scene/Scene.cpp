//
// Created by Hypericats on 12/12/2024.
//

#include "Scene.h"
#include "../../Game/Game.h"

Scene::Scene(const std::string& name) {
    this->m_name = name;
    this->m_background = nullptr;
}

void Scene::initScene(Game* game) const {

}

void Scene::initGameObject(GameObject *gameObject, Game* game) {
    this->m_gameObjects.push_back(gameObject);
    game->registerGameObject(gameObject);
}

std::string& Scene::getName() {
    return m_name;
}

void Scene::initCamera(Camera *camera) {
    camera->setX(0);
    camera->setY(0);
}

std::vector<GameObject*>& Scene::getGameObjects() {
    return this->m_gameObjects;
}

GameObject* Scene::getBackground() const {
    return this->m_background;
}

void Scene::freeScene() {
    delete this->m_background;
    this->m_background = nullptr;

    for (const GameObject* gameObject : this->m_gameObjects) {
        delete gameObject;
    }

    this->m_gameObjects.clear();
}

Player* Scene::getPlayer() {
    return this->m_player;
}
