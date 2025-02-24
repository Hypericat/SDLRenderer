//
// Created by Hypericats on 12/12/2024.
//

#ifndef SCENE_H
#define SCENE_H
#include <vector>

#include "GameObject.h"
#include "../Camera.h"
#include "../../Game/Handlers/DecorationHandler.h"
#include "../../Game/Objects/Player.h"

class Game;

class Scene {
protected:
    Player* m_player = nullptr;
    DecorationHandler* m_decorationHandler = nullptr;
    std::vector<GameObject*> backgrounds = std::vector<GameObject*>();
    std::unordered_map<unsigned long, GameObject*> m_gameObjects;
    std::string m_name;

    virtual void updateBackground(Game* game);
    virtual void updateDecorations(Game* game);

public:
    virtual ~Scene() = default;
    explicit Scene(const std::string& name, Game* game);

    std::string& getName();
    std::vector<GameObject*>& getBackgrounds();
    GameObject* getGameObject(unsigned long* id);
    void freeGameObject(const unsigned long* id);

    Player* getPlayer();

    // Gets called after the objects are loaded
    virtual void initScene(Game* game);
    virtual void loadGameObjects(Game* game) = 0; // Must be implemented
    virtual void initCamera(Camera* camera);
    virtual void freeScene();
    virtual void onRender(Game* game);
    void initGameObject(GameObject* gameObject, Game* game);

    DecorationHandler* getDecorationHandler() const;



protected:
    virtual void populateBackground(GameObject* bg);

private:
    static constexpr int SIGN_BIT_MASK = 1 << 31;
    Game* m_game;

};



#endif //SCENE_H
