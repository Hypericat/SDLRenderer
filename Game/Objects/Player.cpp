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
    std::string str;
    Direction::toString(dir, str);
    std::cout << "Colliding with direction " << str << std::endl;
}

void Player::updateControls(const KeyInputHandler& inputHandler, Game* game) {
    if (inputHandler.isKeyDown(SDL_SCANCODE_W))
        this->addY(-10);
    if (inputHandler.isKeyDown(SDL_SCANCODE_S))
        this->addY(10);
    if (inputHandler.isKeyDown(SDL_SCANCODE_A))
        this->addX(-10);
    if (inputHandler.isKeyDown(SDL_SCANCODE_D))
        this->addX(10);
}
