//
// Created by Hypericats on 12/12/2024.
//

#ifndef SCENE_H
#define SCENE_H
#include <vector>

#include "GameObject.h"
#include "../Camera.h"

class Game;

class Scene {
protected:
    GameObject* m_background;
    std::vector<GameObject*> m_gameObjects;
    std::string m_name;

    void initGameObject(GameObject* gameObject, Game* game);
public:
    Scene(const std::string& name);
    void loadGameObjects(Game* game);

    // Gets called after the objects are loaded
    void initScene(Game* game) const;
    void initCamera(Camera* camera);
    std::string& getName();
    std::vector<GameObject*>& getGameObjects();
    GameObject* getBackground() const;
    void freeScene();

};



#endif //SCENE_H
