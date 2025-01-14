//
// Created by Hypericats on 12/12/2024.
//

#include "TestScene.h"

#include <iostream>
#include "../Game.h"
#include "../Objects/MediumPlatform.h"
#include "../Objects/Player.h"
#include "../Objects/PlayerHair.h"
#include "../Objects/SmallPlatform.h"

void TestScene::loadGameObjects(Game *game) {
    std::cout << "LOADING" << std::endl;
    std::string path = "testBackground.bmp";
    Sprite* sprite = Sprite::fromBMP(path);

    GameObject* bg = new GameObject(std::move(*sprite));
    bg->setCollisionScale(8.0F);
    bg->setRenderScale(8.0F);
    bg->setLayer(-10000);
    this->populateBackground(bg);

    path = "test.bmp";
    sprite = Sprite::fromBMP(path);
    GameObject* other = new GameObject(std::move(*sprite));
    other->setX(1000);
    other->setY(1000);
    other->setCollisionScale(2.0F);
    other->setRenderScale(2.0F);
    initGameObject(other, game);


    SmallPlatform* platform = new SmallPlatform();
    platform->setX(500);
    platform->setY(100);
    initGameObject(platform, game);

    MediumPlatform* medium = new MediumPlatform();
    medium->setX(1000);
    medium->setY(200);
    initGameObject(medium, game);


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
