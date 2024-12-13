//
// Created by Hypericats on 12/12/2024.
//

#include "TestScene.h"

TestScene::TestScene(const std::string& name): Scene(name) {

}

void TestScene::initScene(Game* game) const {
    this->m_background->setX(0);
    this->m_background->setY(0);
}



void TestScene::loadGameObjects(Game *game) {
    std::string path = "testBackground.bmp";
    Sprite* sprite = Sprite::fromBMP(path);
    this->m_background = new GameObject(std::move(*sprite));
    this->m_background->setScale(10.0F);
    this->m_background->setLayer(-10000);
    initGameObject(this->m_background, game);
}

void TestScene::initCamera(Camera *camera) {
    camera->setX(0);
    camera->setY(0);
}
