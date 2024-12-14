//
// Created by Hypericats on 12/13/2024.
//

#include "WallObject.h"

WallObject::WallObject(const std::string &spriteName) : GameObject(std::move(*Sprite::fromBMP(spriteName))) {
    this->setDrawHitbox(true);
    this->setCollideable(true);
}
