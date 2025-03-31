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
    GameObject* bg = new GameObject(std::move(*Sprite::fromPNG("sky.png")));
    bg->setCollisionScale(0);
    bg->setRenderScale(8);
    populateBackground(bg);

    SmallPlatform* platform = new SmallPlatform();
    platform->setX(0);
    platform->setY(200);
    initGameObject(platform, game);

    MediumPlatform* medium = new MediumPlatform();
    medium->setX(350);
    medium->setY(100);
    initGameObject(medium, game);


    int lastX = -500;
    int lastY = 350;

    for (int i = 0; i < 100; i++) {
        WallObject* wall;
        if (rand() & 1) {
            wall = new SmallPlatform();
        } else {
            wall = new MediumPlatform();
            lastX -= 100;
        }
        lastX -= 400 + rand() % 200;
        lastY += 100 + rand() % 300 - 250;
        wall->setX(lastX);
        wall->setY(lastY);
        initGameObject(wall, game);
    }


    this->m_player = new Player(game);
    this->m_player->setY(300);
    this->m_player->setDrawHitbox(true);
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

void TestScene::initScene(Game* game) {

}
