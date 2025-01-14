//
// Created by Hypericats on 1/13/2025.
//

#ifndef PLAYERHAIR_H
#define PLAYERHAIR_H
#include "../../Engine/Scene/GameObject.h"
#include "../../Engine/Scene/Scene.h"

class Scene;

class PlayerHair : public GameObject {
public:
    explicit PlayerHair(Scene* scene);
    void preRender() override;

private:
    Scene* scene;
    const int xOffset = 5;
    const int yOffset = 42;

};



#endif //PLAYERHAIR_H
