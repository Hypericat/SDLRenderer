#ifndef SPIKE_H
#define SPIKE_H

#include "../../Engine/Scene/GameObject.h"

class Spike : public GameObject {
public:
    Spike(Sprite&& sprite, int x, int y);

    void onCollision(GameObject* other);
};

#endif // SPIKE_H
