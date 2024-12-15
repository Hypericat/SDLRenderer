//
// Created by Hypericats on 12/13/2024.
//

#include "Player.h"

#include <iostream>

#include "../Game.h"
#include "../../Engine/Util.h"

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
        this->m_velocity.setX(0);
        return;
    }
    if (cpy == Direction::DOWN) {
        this->setY(otherBoxOutline.getY() - (this->getBoundingBox().getHeight() >> 1));
        this->m_velocity.setY(0);
        return;
    }
    if (cpy == Direction::LEFT) {
        this->setX(otherBoxOutline.getX() + (this->getBoundingBox().getWidth() >> 1));
        this->m_velocity.setX(0);
        return;
    }
    if (cpy == Direction::UP) {
        this->setY(otherBoxOutline.getY() + (this->getBoundingBox().getHeight() >> 1));
        this->m_velocity.setY(0);
        std::cout << "TOUCHED" << std::endl;
        this->setOnGround(true);
        return;
    }
}

void Player::tickPhysics(Game *game) {
    m_velocity.multiply(0.98F);
    this->m_velocity.addY(-0.1);

    std::cout << "VEL Y : " << Util::roundAwayFromZero(m_velocity.getY()) << std::endl;
    this->addX(Util::roundAwayFromZero(m_velocity.getX()));
    this->addY(Util::roundAwayFromZero(m_velocity.getY()));
}

bool Player::isOnGround() const {
    return this->m_onGround;
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
    if (inputHandler.isKeyDown(SDL_SCANCODE_SPACE))
        this->jump();
}

void Player::setOnGround(const bool bl) {
    this->m_onGround = bl;
}

void Player::jump() {
    if (!this->isOnGround()) return;
    this->m_velocity.addY(5);
}