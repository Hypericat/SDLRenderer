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
    virtual ~Scene() = default;
    explicit Scene(const std::string& name);

    std::string& getName();
    std::vector<GameObject*>& getGameObjects();
    GameObject* getBackground() const;

    // Gets called after the objects are loaded
    virtual void initScene(Game* game) const;
    virtual void loadGameObjects(Game* game) = 0; // Must be implemented
    virtual void initCamera(Camera* camera);
    virtual void freeScene();

};



#endif //SCENE_H
