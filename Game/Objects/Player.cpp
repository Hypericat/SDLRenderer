//
// Created by Hypericats on 12/13/2024.
//

#include "Player.h"

#include <iostream>

#include "JumpParticles.h"
#include "../Game.h"
#include "../../Engine/Util.h"

Player::Player(Game* game) : GameObject(std::move(*Sprite::fromPNG("player\\Idle\\Idle0.png")), 18, 26) {
    this->setCollisionScale(3.0F);
    this->setRenderScale(6.0f);
    this->setLayer(1000);

    this->m_game = game;

    int frameLength = 8;
    Animation *animation = new Animation(1);

    animation->addSprite(Sprite::fromPNG("player\\Idle\\Idle0.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Idle\\Idle1.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Idle\\Idle2.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Idle\\Idle3.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Idle\\Idle4.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Idle\\Idle5.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Idle\\Idle6.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Idle\\Idle7.png"), frameLength);
    registerAnimation(FacingDirection::RIGHT, PlayerState::IDLE, animation);
    registerAnimation(FacingDirection::LEFT, PlayerState::IDLE, animation->cpSetFlip(SDL_FLIP_HORIZONTAL));

    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("player\\Walk\\Walk0.png"), 4);
    animation->addSprite(Sprite::fromPNG("player\\Walk\\Walk1.png"), 4);
    animation->addSprite(Sprite::fromPNG("player\\Walk\\Walk2.png"), 4);
    animation->addSprite(Sprite::fromPNG("player\\Walk\\Walk3.png"), 4);
    animation->addSprite(Sprite::fromPNG("player\\Walk\\Walk4.png"), 4);
    animation->addSprite(Sprite::fromPNG("player\\Walk\\Walk5.png"), 4);
    animation->addSprite(Sprite::fromPNG("player\\Walk\\Walk6.png"), 4);
    animation->addSprite(Sprite::fromPNG("player\\Walk\\Walk7.png"), 4);
    registerAnimation(FacingDirection::RIGHT, PlayerState::RUNNING, animation);
    registerAnimation(FacingDirection::LEFT, PlayerState::RUNNING, animation->cpSetFlip(SDL_FLIP_HORIZONTAL));


    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("player\\Jump\\Jump00.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Jump\\Jump01.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Jump\\Jump02.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Jump\\Jump03.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Jump\\Jump04.png"), frameLength);
    registerAnimation(FacingDirection::RIGHT, PlayerState::JUMPING, animation);
    registerAnimation(FacingDirection::LEFT, PlayerState::JUMPING, animation->cpSetFlip(SDL_FLIP_HORIZONTAL));

    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("player\\Fall\\Down0.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Fall\\Down1.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Fall\\Down2.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\Fall\\Down3.png"), frameLength);
    registerAnimation(FacingDirection::RIGHT, PlayerState::FALLING, animation);
    registerAnimation(FacingDirection::LEFT, PlayerState::FALLING, animation->cpSetFlip(SDL_FLIP_HORIZONTAL));

    animation = new Animation();
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants00.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants01.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants02.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants03.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants04.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants05.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants06.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants07.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants08.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants09.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants10.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants11.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants12.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants13.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants14.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants15.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants16.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants17.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants18.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants19.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants20.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants21.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants22.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants23.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants24.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants25.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants26.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants27.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants28.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants29.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants30.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants31.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants32.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants33.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants34.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants35.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants36.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants37.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants38.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants39.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants40.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants41.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants42.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants43.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants44.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants45.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants46.png"), frameLength);
    animation->addSprite(Sprite::fromPNG("player\\IdlePants\\pants47.png"), frameLength);
    registerAnimation(FacingDirection::RIGHT, PlayerState::NUDE, animation);
    registerAnimation(FacingDirection::LEFT, PlayerState::NUDE, animation->cpSetFlip(SDL_FLIP_HORIZONTAL));
}


void Player::onCollision(GameObject *other, const Direction::ENUM& dir) {
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
    // Debug inputs
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

    bool moved = false;
    if (inputHandler.isKeyDown(SDL_SCANCODE_A)) {
        this->m_velocity.setX(0);
        this->addX(10.0f * MOVE_MULTIPLIER);
        this->setFacingDirection(FacingDirection::LEFT);

        if (isOnGround()) this->setPlayerState(PlayerState::RUNNING);
        moved = true;
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_D)) {
        this->m_velocity.setX(0);
        this->addX(10.0f * -MOVE_MULTIPLIER);
        this->setFacingDirection(FacingDirection::RIGHT);

        if (isOnGround()) this->setPlayerState(PlayerState::RUNNING);
        moved = true;
    }
    if (inputHandler.isKeyDown(SDL_SCANCODE_SPACE)) {
        this->jump();
    }

    if (!moved && this->isOnGround() && pantsDone()) this->setPlayerState(PlayerState::IDLE);
    if (!m_onGround) {
        if (this->m_velocity.getY() > 0)
            this->setPlayerState(PlayerState::JUMPING);
        else
            this->setPlayerState(PlayerState::FALLING);
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

    JumpParticles* particles = new JumpParticles();
    particles->setX(this->getX());
    particles->setY(this->getY() - 50);
    this->m_game->getScene()->initGameObject(particles, m_game);

    //particles = new JumpParticles(*particles);
    //particles->addX(5);
    //particles->addY(2);
    //this->m_game->getScene()->initGameObject(particles, m_game);
//
//
    //particles = new JumpParticles(*particles);
    //particles->addX(-10);
    //particles->addY(-4);
    //this->m_game->getScene()->initGameObject(particles, m_game);

}

const Sprite* Player::getSprite() {
    Animation *animation = m_animations.at(static_cast<int>(m_facingDirection) << 16 | static_cast<int>(m_playerState));
    if (animation == nullptr) return nullptr;
    return animation->nextSprite();
}

void Player::applyTextureYOffset(Vector2i& vec) {
    vec.setY(this->getBoundingBox().getMin().getY() + 10 * this->getRenderScale());
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


void Player::attemptPants() {
    //if (rand() % 16 == 0)
        this->m_playerState = PlayerState::NUDE;
}

void Player::die() {
    // reset the player position
    setX(50);
    setY(50);

    // add lives, a game-over state, or animations here
}

bool Player::pantsDone() const {
    if (this->m_playerState != PlayerState::NUDE) return true;
    Animation *animation = m_animations.at(static_cast<int>(m_facingDirection) << 16 | static_cast<int>(m_playerState));
    if (animation == nullptr) return true;
    if (animation->getIndex() >= animation->getSize() - 1) return true;
    return false;
}

void Player::registerAnimation(FacingDirection::ENUM direction, PlayerState::ENUM state, Animation *animation) {
    this->m_animations.emplace(static_cast<int>(direction) << 16 | static_cast<int>(state), animation);
}
