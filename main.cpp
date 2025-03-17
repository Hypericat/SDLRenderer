#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>

#include "Game/Game.h"
#include "Engine/Window.h"
#include "Game/Objects/Spike.h"

static const std::string WINDOW_TITLE = "Mighty Triangle";

// Don't forget to put files into release cache, else it won't work in release mode

int main(int argc, char *argv[]) {
    Window window = Window(640, 480);

    Game game = Game(window);
    window.initWindow(WINDOW_TITLE, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN, &game);

    // Init
    Spike::initAnimation();


    game.run();

    window.destroyWindow();
    SDL_Quit();
    return 0;
}


