//
// Created by Hypericats on 1/20/2025.
//

#include "JumpParticles.h"

#include <iostream>

#include "../Game.h"

JumpParticles::JumpParticles(): GameObject(std::move(*Sprite::fromPNG("player\\zappysmoke00.png"))) {
    this->setLayer(10000);
    this->setRenderScale(4);
    this->m_animation = new Animation();
    int length = 5;

    m_animation->addSprite(Sprite::fromPNG("player\\zappysmoke00.png"), length);
    m_animation->addSprite(Sprite::fromPNG("player\\zappysmoke01.png"), length);
    m_animation->addSprite(Sprite::fromPNG("player\\zappysmoke02.png"), length);
    m_animation->addSprite(Sprite::fromPNG("player\\zappysmoke03.png"), length);
}

const Sprite* JumpParticles::getSprite() {
    return m_animation->nextSprite();
}

void JumpParticles::postRender(Game *game) {
    if (this->m_animation->isLast()) {
        game->getScene()->freeGameObject(this->getId());
    }
}
