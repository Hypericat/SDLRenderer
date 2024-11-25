#define SDL_MAIN_HANDLED

#include <SDL.h>

#include "Game.h"
#include "Window.h"

static const std::string WINDOW_TITLE = "Mighty Triangle";

int main(int argc, char *argv[]) {
    Window window = Window(640, 480);
    window.initWindow(WINDOW_TITLE, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    Game game = Game(window);
    game.run();

    window.destroyWindow();
    SDL_Quit();
    return 0;
}
