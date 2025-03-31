//
// Created by Hypericats on 2/24/2025.
//

#include "Decoration.h"

Decoration::Decoration() : GameObject(std::move(*Sprite::fromPNG("decorations\\PlanetRed.png"))) {
    this->setCollideable(false);
    this->setRenderScale(5);
    this->setLayer(120);
    this->setVisible(false);
}

void Decoration::init() {
    if (animations.size() > 0) return;
    Animation* animation = new Animation();
    animation->addSprite(Sprite::fromPNG("decorations\\PlanetRed.png"), 1);
    animations.push_back(animation);

    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("decorations\\Asteroid0.png"), 10);
    animation->addSprite(Sprite::fromPNG("decorations\\Asteroid1.png"), 10);
    animations.push_back(animation);
}

void Decoration::random() {
    int old = decorationIndex;
    this->decorationIndex = rand() % animations.size();
    if (decorationIndex != old)
        this->animationIndex = 0;
}

const Sprite* Decoration::getSprite() {
    return animations.at(decorationIndex)->nextSprite(this->animationIndex);
}
