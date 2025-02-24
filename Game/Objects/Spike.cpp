#include "Spike.h"

#include <iostream>

#include "Player.h" // Assuming there's a Player class

Spike::Spike(int x, int y) : GameObject(std::move(*Sprite::fromPNG("spike.png"))) {
    setX(x);
    setY(y);
    this->setDrawHitbox(true);
    this->setCollideable(true);
    this->setCollisionScale(0.3F);
    this->setRenderScale(0.5f);
    this->setLayer(800);

    int frameLength = 8;
    m_animation = new Animation();

    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_00.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_01.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_02.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_03.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_04.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_05.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_06.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_07.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_09.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_10.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_11.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_12.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_13.png"), frameLength);
    m_animation->addSprite(Sprite::fromPNG("spike\\sprite_14.png"), frameLength);
}

const Sprite* Spike::getSprite() {
    return this->m_animation->nextSprite();
}

void Spike::onCollision(GameObject* other, const Direction::ENUM& dir) {
    Player* player = dynamic_cast<Player*>(other);
    if (player) {
        player->die();
    }
}
