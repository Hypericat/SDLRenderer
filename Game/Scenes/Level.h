//
// Created by Hypericats on 1/14/2025.
//

#ifndef LEVEL_H
#define LEVEL_H
#include "../Game.h"


class Scene;

class Level : public Scene {
private:
    std::vector<GameObject*> gameObjects;

public:
    Level(Game* game) : Scene("Level", game) {};

    // Gets called after the objects are loaded
    void initScene(Game* game) override; // Remove this line if not needed
    void loadGameObjects(Game* game) override;

    //void initCamera(Camera* camera) override;
    //void freeScene() override;
};



#endif //LEVEL_H
