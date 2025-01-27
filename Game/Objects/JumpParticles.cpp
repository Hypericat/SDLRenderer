//
// Created by Hypericats on 1/20/2025.
//

#include "JumpParticles.h"

#include <iostream>

#include "../Game.h"

JumpParticles::JumpParticles(): GameObject(std::move(*Sprite::fromPNG("player\\jumpParticle0.png"))) {
    this->setLayer(10000);
    this->setRenderScale(3);
    this->m_animation = new Animation();
    int length = 5;

    m_animation->addSprite(Sprite::fromPNG("player\\jumpParticle0.png"), length);
    m_animation->addSprite(Sprite::fromPNG("player\\jumpParticle1.png"), length);
    m_animation->addSprite(Sprite::fromPNG("player\\jumpParticle2.png"), length);
    m_animation->addSprite(Sprite::fromPNG("player\\jumpParticle3.png"), length);
}

JumpParticles::JumpParticles(const JumpParticles &jumpParticles): GameObject(jumpParticles) {
    this->m_animation = jumpParticles.m_animation->cpSetFlip(SDL_FLIP_NONE);
}

const Sprite* JumpParticles::getSprite() {
    return m_animation->nextSprite();
}

void JumpParticles::postRender(Game *game) {
    if (this->m_animation->isLast()) {
        game->getScene()->freeGameObject(this->getId());
    }
}
