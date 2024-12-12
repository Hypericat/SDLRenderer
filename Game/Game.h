//
// Created by Hypericats on 11/18/2024.
//

#ifndef GAME_H
#define GAME_H
#include <map>
#include <unordered_map>

#include "../Engine/Window.h"
#include "../Engine/Input/KeyInputHandler.h"


class Game {
private:
    bool running = false;
    float lastFrameDelta = 0.0F;
    Window& m_window;
    KeyInputHandler m_keyInputHandler;

    std::unordered_map<unsigned long, GameObject*> m_objects;
    std::multimap<int, GameObject*> m_layerObjects;
    void renderFrame();
    void pollWindowEvents();

public:
    const static int TARGET_FRAME_RATE = 60;
    const static int TARGET_FRAME_DELTA = 1000 / TARGET_FRAME_RATE;

    Game(Window &window);
    float getFrameDelta() const;
    void run();
    void stop();

    void registerGameObject(GameObject* gameObject);
    void freeGameObject(GameObject* gameObject);
    void freeGameObject(const unsigned long* id);

    GameObject* getObjectByID(const unsigned long* id);

    void updateTestControls() const;
};



#endif //GAME_H
