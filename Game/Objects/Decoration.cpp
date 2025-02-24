//
// Created by Hypericats on 2/24/2025.
//

#include "Decoration.h"

Decoration::Decoration() : GameObject(std::move(*Sprite::fromPNG("goldblock.png"))) {
    this->setCollideable(false);
    this->setRenderScale(5);
    this->setVisible(false);
}
