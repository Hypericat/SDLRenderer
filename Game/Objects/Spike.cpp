#include "Spike.h"

#include <iostream>

#include "Player.h" // Assuming there's a Player class

Spike::Spike(Sprite&& sprite, int x, int y)
    : GameObject(std::move(sprite), sprite.getWidth(), sprite.getHeight()) {
    setX(x);
    setY(y);
    setCollideable(true);
}

void Spike::onCollision(GameObject* other, const Direction::ENUM& dir) {

}
