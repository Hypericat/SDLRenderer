//
// Created by Hypericats on 12/13/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../../Engine/Input/KeyInputHandler.h"
#include "../../Engine/Scene/GameObject.h"

class Game;

class Player : public GameObject {
public:
    Player();

    void updateControls(const KeyInputHandler& inputHandler, Game* game);

};



#endif //PLAYER_H
