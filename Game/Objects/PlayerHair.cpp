//
// Created by Hypericats on 1/13/2025.
//

#include "PlayerHair.h"
#include "../../Engine/Scene/Scene.h"

PlayerHair::PlayerHair(Scene* scene): GameObject(std::move(*Sprite::fromPNG("player\\hair.png")), 13, 18) {
    this->setRenderScale(6.0f);
    this->setLayer(990);
    this->scene = scene;
}

void PlayerHair::preRender(Game* game) {
    this->setY(scene->getPlayer()->getY() + yOffset);
    this->setX(scene->getPlayer()->getX() + xOffset);
}
