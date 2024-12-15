//
// Created by Hypericats on 12/13/2024.
//

#include "Player.h"

#include <iostream>

#include "../Game.h"

Player::Player() : GameObject(std::move(*Sprite::fromBMP("player.bmp"))) {
    this->setScale(10.0F);
    this->setLayer(1000);
    this->setDrawHitbox(true);
}

void Player::collideWith(GameObject *other, const Direction::ENUM& dir) {
    Direction::ENUM cpy = dir;
    Direction::negate(cpy);
    Vector2i otherBoxOutline = other->getBoundingBox().getDirPos(cpy);

    // Cpy is the direction we are hitting from the perspective of the gameObject
    // Dir is from the player perspective
    if (cpy == Direction::RIGHT) {
        this->setX(otherBoxOutline.getX() - (this->getBoundingBox().getWidth() >> 1));
        return;
    }
    if (cpy == Direction::DOWN) {
        this->setY(otherBoxOutline.getY() - (this->getBoundingBox().getHeight() >> 1));
        return;
    }
    if (cpy == Direction::LEFT) {
        this->setX(otherBoxOutline.getX() + (this->getBoundingBox().getWidth() >> 1));
        return;
    }
    if (cpy == Direction::UP) {
        this->setY(otherBoxOutline.getY() + (this->getBoundingBox().getHeight() >> 1));
        return;
    }
}

void Player::updateControls(const KeyInputHandler& inputHandler, Game* game) {
    if (inputHandler.isKeyDown(SDL_SCANCODE_W))
        this->addY(10);
    if (inputHandler.isKeyDown(SDL_SCANCODE_S))
        this->addY(-10);
    if (inputHandler.isKeyDown(SDL_SCANCODE_A))
        this->addX(10);
    if (inputHandler.isKeyDown(SDL_SCANCODE_D))
        this->addX(-10);
}
