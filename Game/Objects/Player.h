//
// Created by Hypericats on 12/13/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "FacingDirection.h"
#include "PlayerState.h"
#include "../../Engine/Input/KeyInputHandler.h"
#include "../../Engine/Math/Vector2f.h"
#include "../../Engine/Scene/Animation.h"
#include "../../Engine/Scene/GameObject.h"

class Game;

class Player : public GameObject {
public:
    Player(Game* game);
    Vector2f m_velocity = Vector2f(0.0F, 0.0F);
    bool m_onGround = true;

    void updateControls(const KeyInputHandler& inputHandler, Game* game);
    void collideWith(GameObject* other, const Direction::ENUM& dir);
    void tickPhysics(Game* game);
    bool isOnGround() const;
    void setOnGround(bool bl);
    void jump();
    const Sprite* getSprite() override;

    void applyTextureYOffset(Vector2i& vec) override;

    PlayerState::ENUM getPlayerState() const;
    void setPlayerState(PlayerState::ENUM state);

    FacingDirection::ENUM getFacingDirection() const;
    void setFacingDirection(FacingDirection::ENUM direction);

private:
    Game* m_game;

    std::unordered_map<int, Animation*> m_animations;

    FacingDirection::ENUM m_facingDirection = FacingDirection::RIGHT;;
    PlayerState::ENUM m_playerState = PlayerState::IDLE;

    static inline const float GRAVITY = 0.981F;
    static inline const float MAX_GRAVITY = 20.0F;
    static inline const float JUMP_VEL = 20.0f;
    static inline const float MOVE_MULTIPLIER = 2.0f;


    void registerAnimation(FacingDirection::ENUM direction, PlayerState::ENUM state, Animation* animation);

};



#endif //PLAYER_H
