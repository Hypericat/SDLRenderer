//
// Created by Hypericats on 12/8/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Sprite.h"


class GameObject {
private:
    Sprite m_sprite;
    int m_x = 0;
    int m_y = 0;
    unsigned long id;

public:
    explicit GameObject(Sprite&& sprite);
    GameObject(Sprite&& sprite, int x, int y);
    ~GameObject();

    //add copy constructor

    const Sprite* getSprite() const;
    int getX() const;
    int getY() const;
    int* getXPtr();
    int* getYPtr();
    void setX(int x);
    void setY(int y);

    const unsigned long* getId() {
        return &id;
    }

};



#endif //GAMEOBJECT_H
