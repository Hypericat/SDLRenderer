//
// Created by Hypericats on 12/12/2024.
//

#ifndef TESTSCENE_H
#define TESTSCENE_H
#include "../../Engine/Scene/Scene.h"


class TestScene : public Scene {
public:
    TestScene() : Scene("Test Scene") {};

    // Gets called after the objects are loaded
    void initScene(Game* game) const override; // Remove this line if not needed
    void loadGameObjects(Game* game) override;

    void initCamera(Camera* camera) override; // Remove this line to use default implementation
    void freeScene() override; // Remove this line to use default implementation

};



#endif //TESTSCENE_H
