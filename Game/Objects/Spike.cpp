#include "Spike.h"
#include "Player.h" // Assuming there's a Player class

Spike::Spike(Sprite&& sprite, int x, int y)
    : GameObject(std::move(sprite), sprite.getWidth(), sprite.getHeight()) {
    setX(x);
    setY(y);
    setCollideable(true); // Ensure it interacts with other objects
}

void Spike::onCollision(GameObject* other) {
    if (auto player = dynamic_cast<Player*>(other)) {
        player->die(); // Call death function
    }
}
