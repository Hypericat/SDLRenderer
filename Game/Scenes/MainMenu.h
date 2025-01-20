//
// Created by Hypericats on 1/20/2025.
//

#ifndef MAINMENU_H
#define MAINMENU_H
#include "../../Engine/Scene/Scene.h"


class MainMenu : public Scene {
public:
    MainMenu(Game* game) : Scene("Main Menu", game) {}

    void loadGameObjects(Game *game) override;
};



#endif //MAINMENU_H
