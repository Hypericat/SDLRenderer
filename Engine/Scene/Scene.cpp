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
    this->m_background->setX(0);
    this->m_background->setY(0);
}

void Scene::initGameObject(GameObject *gameObject, Game* game) {
    this->m_gameObjects.push_back(gameObject);
    game->registerGameObject(gameObject);
}

std::string& Scene::getName() {
    return m_name;
}

void Scene::loadGameObjects(Game *game) {
    std::string path = "testBackground.bmp";
    Sprite* sprite = Sprite::fromBMP(path);
    this->m_background = new GameObject(std::move(*sprite));
    this->m_background->setScale(10.0F);
    this->m_background->setLayer(-10000);
    initGameObject(this->m_background, game);
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
