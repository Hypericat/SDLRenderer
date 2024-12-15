//
// Created by Hypericats on 12/13/2024.
//

#include "Player.h"

#include <iostream>

#include "../Game.h"
#include "../../Engine/Util.h"

Player::Player() : GameObject(std::move(*Sprite::fromPNG("player\\idle00.png")), 13, 18) {
    this->setCollisionScale(6.0F);
    this->setRenderScale(8.0f);
    this->setLayer(1000);

    idleAnimation = Animation();
    int length = 5;
    idleAnimation.addSprite(Sprite::fromPNG("player\\idle00.png"), length);
    idleAnimation.addSprite(Sprite::fromPNG("player\\idle01.png"), length);
    idleAnimation.addSprite(Sprite::fromPNG("player\\idle02.png"), length);
    idleAnimation.addSprite(Sprite::fromPNG("player\\idle03.png"), length);
    idleAnimation.addSprite(Sprite::fromPNG("player\\idle04.png"), length);
    idleAnimation.addSprite(Sprite::fromPNG("player\\idle05.png"), length);
    idleAnimation.addSprite(Sprite::fromPNG("player\\idle06.png"), length);
    idleAnimation.addSprite(Sprite::fromPNG("player\\idle07.png"), length);
    idleAnimation.addSprite(Sprite::fromPNG("player\\idle08.png"), length);

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
        this->setOnGround(true);
        return;
    }
}

void Player::tickPhysics(Game *game) {
    //m_velocity.multiply(0.98F);

    float currentVelocity = m_velocity.getY();
    if (currentVelocity > -MAX_GRAVITY) {
        this->m_velocity.addY(std::max(-GRAVITY, -(currentVelocity + MAX_GRAVITY)));
    }


    this->addX((int) Util::roundAwayFromZero(m_velocity.getX()));
    this->addY((int) Util::roundAwayFromZero(m_velocity.getY()));
}

bool Player::isOnGround() const {
    return this->m_onGround;
}


void Player::updateControls(const KeyInputHandler& inputHandler, Game* game) {
    if (inputHandler.isKeyDown(SDL_SCANCODE_W)) {
        this->m_velocity.setY(0);
        this->addY(30);
        //this->setRenderScale(this->getRenderScale() + 0.1f);
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_S)) {
        this->addY(-30);
        this->m_velocity.setY(0);
        //this->setRenderScale(this->getRenderScale() - 0.1f);
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_A)) {
        this->m_velocity.setX(0);
        this->addX(30);
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_D)) {
        this->m_velocity.setX(0);
        this->addX(-30);
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_SPACE)) {
        this->jump();
    }
}

void Player::setOnGround(const bool bl) {
    this->m_onGround = bl;
    if (!bl) return;
    this->m_velocity.setX(0);
    this->m_velocity.setY(0);
}

void Player::jump() {
    if (!this->isOnGround()) return;
    if (this->m_velocity.getY() < 0) {
        this->m_velocity.setY(0);
    }
    this->m_velocity.addY(JUMP_VEL);
}

const Sprite* Player::getSprite() {
    return idleAnimation.nextSprite();
}

void Player::applyTextureYOffset(Vector2i& vec) {
    vec.setY(this->getBoundingBox().getMin().getY() + 16 * this->getRenderScale());
}
