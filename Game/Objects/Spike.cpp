#include "Spike.h"

#include <iostream>

#include "Player.h" // Assuming there's a Player class

Spike::Spike(int x, int y) : GameObject(std::move(*Sprite::fromPNG("spike\\sprite_00.png"))) {
    setX(x);
    setY(y);
    this->setDrawHitbox(true);
    this->setCollideable(true);
    this->setCollisionScale(3.5f);
    this->setRenderScale(5.0f);
    this->setLayer(800);
}

const Sprite* Spike::getSprite() {
    return m_animation->nextSprite(this->m_animationIndex);
}

void Spike::onCollision(GameObject* other, const Direction::ENUM& dir) {
    Player* player = dynamic_cast<Player*>(other);
    if (player) {
        player->die();
    }
}

void Spike::initAnimation() {
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
