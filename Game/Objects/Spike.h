#ifndef SPIKE_H
#define SPIKE_H

#include "../../Engine/Scene/Animation.h"
#include "../../Engine/Scene/GameObject.h"

class Spike : public GameObject {

private:
    Animation* m_animation;

public:
    Spike(int x, int y);
    void onCollision(GameObject* other, const Direction::ENUM& dir) override;
    const Sprite* getSprite() override;

};

#endif // SPIKE_H
