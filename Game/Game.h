//
// Created by Hypericats on 11/18/2024.
//

#ifndef GAME_H
#define GAME_H
#include "../Engine/Window.h"


class Game {
private:
    bool running = false;
    float lastFrameDelta;
    Window& window;
    void renderFrame();
    void pollWindowEvents();

public:
    const static int TARGET_FRAME_RATE = 60;
    const static int TARGET_FRAME_DELTA = 1000 / TARGET_FRAME_RATE;

    Game(Window &window);
    float getFrameDelta() const;
    void run();
    void stop();
};



#endif //GAME_H
