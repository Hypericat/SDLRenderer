//
// Created by Hypericats on 12/12/2024.
//

#include "Scene.h"
#include "../../Game/Game.h"

Scene::Scene(const std::string& name) {
    this->m_name = name;
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

std::vector<GameObject*>& Scene::getBackgrounds() {
    return this->backgrounds;
}

void Scene::freeScene() {
    for (const GameObject* background : this->backgrounds) {
        delete background;
    }
    backgrounds.clear();

    for (const GameObject* gameObject : this->m_gameObjects) {
        delete gameObject;
    }

    this->m_gameObjects.clear();
}

Player* Scene::getPlayer() {
    return this->m_player;
}

void Scene::updateBackground(Game *game) {
    if (this->backgrounds.empty()) return;
    const Camera* camera = &game->getWindow().getCamera();
    GameObject* background = this->backgrounds.at(0);
    int width = background->getRenderWidth();
    int height = background->getRenderHeight();
    int yDistance = camera->getY() / height;
    int xDistance = camera->getX() / width;
    int finalY = yDistance * height;
    int finalX   = xDistance * width;
    background->setY(finalY);
    background->setX(finalX);

    // Not plus or minus, depends on sign of positon

    this->backgrounds.at(1)->setX(finalX + width);
    this->backgrounds.at(1)->setY(finalY);

    this->backgrounds.at(2)->setX(finalX);
    this->backgrounds.at(2)->setY(finalY + height);

    this->backgrounds.at(3)->setX(finalX + width);
    this->backgrounds.at(3)->setY(finalY + height);
    this->backgrounds.at(3)->setRenderScale(100);
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
