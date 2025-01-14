//
// Created by Hypericats on 1/14/2025.
//

#include "Level.h"

#include "../Objects/MediumPlatform.h"
#include "../Objects/PlayerHair.h"
#include "../Objects/SmallPlatform.h"

void Level::initScene(Game *game) const {
    Scene::initScene(game);
}

void Level::loadGameObjects(Game *game) {
    GameObject* bg = new GameObject(std::move(*Sprite::fromPNG("sky.png")));
    bg->setCollisionScale(0);
    bg->setRenderScale(6);
    populateBackground(bg);

    SmallPlatform* platform = new SmallPlatform();
    platform->setX(0);
    platform->setY(200);
    initGameObject(platform, game);

    MediumPlatform* medium = new MediumPlatform();
    medium->setX(500);
    medium->setY(100);
    initGameObject(medium, game);


    this->m_player = new Player();
    this->m_player->setY(300);
    this->m_player->setDrawHitbox(true);
    initGameObject(m_player, game);

    PlayerHair* hair = new PlayerHair(this);
    initGameObject(hair, game);
}
