//
// Created by Hypericats on 12/12/2024.
//

#ifndef TESTSCENE_H
#define TESTSCENE_H
#include "../../Engine/Scene/Scene.h"


class TestScene : public Scene {
public:
    explicit TestScene(const std::string& name);

    // Gets called after the objects are loaded
    void initScene(Game* game) const;
    void initCamera(Camera* camera);
    void freeScene();
    void loadGameObjects(Game* game);

};



#endif //TESTSCENE_H
