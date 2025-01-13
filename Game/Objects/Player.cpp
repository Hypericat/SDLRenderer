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

    int frameLength = 5;
    Animation *animation = new Animation();

    animation->addSprite(Sprite::fromPNG("player\\idle00.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle01.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle02.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle03.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle04.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle05.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle06.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle07.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle08.png"), frameLength);
    registerAnimation(FacingDirection::RIGHT, PlayerState::IDLE, animation);

    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("player\\idle00.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle01.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle02.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle03.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle04.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle05.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle06.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle07.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\idle08.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    registerAnimation(FacingDirection::LEFT, PlayerState::IDLE, animation);

    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("player\\runFast00.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast01.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast02.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast03.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast04.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast05.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast06.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast07.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast08.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast09.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast10.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast11.png"), frameLength);
    registerAnimation(FacingDirection::RIGHT, PlayerState::RUNNING, animation);

    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("player\\runFast00.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast01.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast02.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast03.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast04.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast05.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast06.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast07.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast08.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast09.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast10.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\runFast11.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    registerAnimation(FacingDirection::LEFT, PlayerState::RUNNING, animation);

    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("player\\jumpFast00.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\jumpFast01.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\jumpFast02.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\jumpFast03.png"), frameLength);
    registerAnimation(FacingDirection::RIGHT, PlayerState::JUMPING, animation);

    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("player\\jumpFast00.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\jumpFast01.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\jumpFast02.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\jumpFast03.png")->setRenderFlip(SDL_FLIP_HORIZONTAL), frameLength);
    registerAnimation(FacingDirection::LEFT, PlayerState::JUMPING, animation);



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
    bool moved = false;

    if (inputHandler.isKeyDown(SDL_SCANCODE_W)) {
        this->m_velocity.setY(0);
        this->addY(20);
        //this->setRenderScale(this->getRenderScale() + 0.1f);
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_S)) {
        this->addY(-20);
        this->m_velocity.setY(0);
        //this->setRenderScale(this->getRenderScale() - 0.1f);
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_A)) {
        this->m_velocity.setX(0);
        this->addX(20);
        this->setFacingDirection(FacingDirection::LEFT);

        if (isOnGround()) this->setPlayerState(PlayerState::RUNNING);
        moved = true;
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_D)) {
        this->m_velocity.setX(0);
        this->addX(-20);
        this->setFacingDirection(FacingDirection::RIGHT);

        if (isOnGround()) this->setPlayerState(PlayerState::RUNNING);
        moved = true;
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_SPACE)) {
        this->jump();
    }

    if (!moved && this->isOnGround()) this->setPlayerState(PlayerState::IDLE);
    if (!m_onGround) this->setPlayerState(PlayerState::JUMPING);
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
    Animation *animation = m_animations.at(static_cast<int>(m_facingDirection) << 16 | static_cast<int>(m_playerState));
    if (animation == nullptr) return nullptr;
    return animation->nextSprite();
}

void Player::applyTextureYOffset(Vector2i& vec) {
    vec.setY(this->getBoundingBox().getMin().getY() + 16 * this->getRenderScale());
}

PlayerState::ENUM Player::getPlayerState() const {
    return this->m_playerState;
}

void Player::setPlayerState(const PlayerState::ENUM state) {
    this->m_playerState = state;
}

FacingDirection::ENUM Player::getFacingDirection() const {
    return this->m_facingDirection;
}

void Player::setFacingDirection(const FacingDirection::ENUM direction) {
    this->m_facingDirection = direction;
}

void Player::registerAnimation(FacingDirection::ENUM direction, PlayerState::ENUM state, Animation *animation) {
    this->m_animations.emplace(static_cast<int>(direction) << 16 | static_cast<int>(state), animation);
}
