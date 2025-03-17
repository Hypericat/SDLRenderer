#ifndef SPIKE_H
#define SPIKE_H

#include "../../Engine/Scene/Animation.h"
#include "../../Engine/Scene/GameObject.h"

class Spike : public GameObject {

private:
    static inline Animation* m_animation;
    int m_animationIndex = 0;

public:
    Spike(int x, int y);
    void onCollision(GameObject* other, const Direction::ENUM& dir) override;
    const Sprite* getSprite() override;

    static void initAnimation();

};

#endif // SPIKE_H
