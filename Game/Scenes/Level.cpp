//
// Created by Hypericats on 1/14/2025.
//

#include "Level.h"

#include "../Objects/MediumPlatform.h"
#include "../Objects/PlayerHair.h"
#include "../Objects/SmallPlatform.h"
#include "../Objects/Spike.h"

void Level::initScene(Game *game) {
    Scene::initScene(game);
}

void Level::loadGameObjects(Game *game) {
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
    medium->setCollisionScale(40);
    medium->setRenderScale(40);
    initGameObject(medium, game);

    Spike* spike = new Spike(400, 250);
    initGameObject(spike, game);


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

        if (rand() % 10 < 3) {
            Spike* spike = new Spike(lastX + rand() % 150 - 75, lastY - 50);
            initGameObject(spike, game);
        }
    }


    this->m_player = new Player(game);
    this->m_player->setY(300);
    this->m_player->setDrawHitbox(true);
    initGameObject(m_player, game);
}




