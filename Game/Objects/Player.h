//
// Created by Hypericats on 12/13/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../../Engine/Input/KeyInputHandler.h"
#include "../../Engine/Math/Vector2f.h"
#include "../../Engine/Scene/GameObject.h"

class Game;

class Player : public GameObject {
public:
    Player();
    Vector2f m_velocity = Vector2f(0.0F, 0.0F);
    bool m_onGround = true;

    void updateControls(const KeyInputHandler& inputHandler, Game* game);
    void collideWith(GameObject* other, const Direction::ENUM& dir);
    void tickPhysics(Game* game);
    bool isOnGround() const;
    void setOnGround(bool bl);
    void jump();
private:
    static inline const float GRAVITY = 0.981F;
    static inline const float MAX_GRAVITY = 20.0F;
    static inline const float JUMP_VEL = 32.0f;

};



#endif //PLAYER_H
