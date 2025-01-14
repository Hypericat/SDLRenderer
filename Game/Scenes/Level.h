//
// Created by Hypericats on 1/14/2025.
//

#ifndef LEVEL_H
#define LEVEL_H
#include "../Game.h"


class Scene;

class Level : public Scene {
public:
    Level() : Scene("Level the first") {};

    // Gets called after the objects are loaded
    void initScene(Game* game) const override; // Remove this line if not needed
    void loadGameObjects(Game* game) override;

    //void initCamera(Camera* camera) override;
    //void freeScene() override;
};



#endif //LEVEL_H
