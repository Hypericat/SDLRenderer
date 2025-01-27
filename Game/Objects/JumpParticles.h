//
// Created by Hypericats on 1/20/2025.
//

#ifndef JUMPPARTICLES_H
#define JUMPPARTICLES_H
#include "../../Engine/Scene/Animation.h"
#include "../../Engine/Scene/GameObject.h"


class JumpParticles : public GameObject {
private:
    Animation* m_animation;


public:
    JumpParticles();
    JumpParticles(const JumpParticles& jumpParticles);
    const Sprite* getSprite() override;

    void postRender(Game* game) override;
};



#endif //JUMPPARTICLES_H
