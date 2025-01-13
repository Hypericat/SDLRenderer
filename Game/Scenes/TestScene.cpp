//
// Created by Hypericats on 12/12/2024.
//

#include "TestScene.h"

#include <iostream>
#include "../Game.h"
#include "../Objects/Player.h"
#include "../Objects/PlayerHair.h"
#include "../Objects/WallObject.h"

void TestScene::loadGameObjects(Game *game) {
    std::cout << "LOADING" << std::endl;
    std::string path = "testBackground.bmp";
    Sprite* sprite = Sprite::fromBMP(path);
    this->m_background = new GameObject(std::move(*sprite));
    this->m_background->setCollisionScale(8.0F);
    this->m_background->setRenderScale(8.0F);
    this->m_background->setLayer(-10000);
    initGameObject(this->m_background, game);

    path = "test.bmp";
    sprite = Sprite::fromBMP(path);
    GameObject* other = new GameObject(std::move(*sprite));
    other->setX(1000);
    other->setY(1000);
    other->setCollisionScale(2.0F);
    other->setRenderScale(2.0F);
    initGameObject(other, game);

    GameObject* object = new WallObject("wall.bmp");
    object->setCollisionScale(8.0F);
    object->setRenderScale(8.0F);
    initGameObject(object, game);

    GameObject* wall2 = new WallObject("wall.bmp");
    wall2->setCollisionScale(8.0F);
    wall2->setRenderScale(8.0F);
    wall2->addX(wall2->getCollisionWidth());
    wall2->addY(wall2->getCollisionHeight() + 100);

    initGameObject(wall2, game);


    this->m_player = new Player();
    this->m_player->setY(300);
    this->m_player->setDrawHitbox(true);
    initGameObject(m_player, game);

    PlayerHair* hair = new PlayerHair(this);
    initGameObject(hair, game);
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
