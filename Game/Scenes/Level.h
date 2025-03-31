//
// Created by Hypericats on 1/14/2025.
//

#ifndef LEVEL_H
#define LEVEL_H
#include "../Game.h"

#include <list>

class Scene;

class Level : public Scene {
private:
    std::list<GameObject*> gameObjects;

public:
    Level(Game* game) : Scene("Level", game) {};

    // Gets called after the objects are loaded
    void initScene(Game* game) override; // Remove this line if not needed
    void loadGameObjects(Game* game) override;

    //void initCamera(Camera* camera) override;
    //void freeScene() override;

    void updateLevel(Game* game);
    bool isInScreen(const Box& box, Camera &camera);
    bool isInScreen(GameObject* gameObject, Camera &camera);


};



#endif //LEVEL_H
