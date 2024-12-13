//
// Created by Hypericats on 12/12/2024.
//

#include "TestScene.h"

#include <iostream>
#include "../Game.h"
#include "../Objects/Player.h"

void TestScene::loadGameObjects(Game *game) {
    std::cout << "LOADING" << std::endl;
    std::string path = "testBackground.bmp";
    Sprite* sprite = Sprite::fromBMP(path);
    this->m_background = new GameObject(std::move(*sprite));
    this->m_background->setScale(10.0F);
    this->m_background->setLayer(-10000);
    initGameObject(this->m_background, game);

    path = "test.bmp";
    sprite = Sprite::fromBMP(path);
    GameObject* other = new GameObject(std::move(*sprite));
    other->setX(1000);
    other->setY(1000);
    other->setScale(2.0F);
    initGameObject(other, game);

    this->m_player = new Player();
    initGameObject(m_player, game);
}

// Can be removed
void TestScene::initCamera(Camera *camera) {
    camera->setX(0);
    camera->setY(0);
}

void TestScene::freeScene() {
    Scene::freeScene();
}

void TestScene::initScene(Game* game) const {

}
