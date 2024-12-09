//
// Created by Hypericats on 11/18/2024.
//

#ifndef GAME_H
#define GAME_H
#include <map>
#include <unordered_map>

#include "../Engine/Window.h"


class Game {
private:
    bool running = false;
    float lastFrameDelta = 0.0F;
    Window& window;
    std::unordered_map<unsigned long, GameObject*> objects;
    void renderFrame() const;
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
};



#endif //GAME_H
