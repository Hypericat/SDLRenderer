//
// Created by Hypericats on 12/8/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "../Sprite.h"


class GameObject {
private:
    Sprite m_sprite;
    int m_x = 0;
    int m_y = 0;
    float m_scale = 1.0F;
    int m_layer = 0;
    unsigned long id;

    bool m_registered = false;

public:
    explicit GameObject(Sprite&& sprite);
    explicit GameObject(const GameObject& gameObject);
    GameObject(Sprite&& sprite, int x, int y);
    ~GameObject();

    const Sprite* getSprite() const;
    int getX() const;
    int getY() const;
    int* getXPtr();
    int* getYPtr();
    void setX(int x);
    void setY(int y);

    int getScaledWidth() const;
    int getScaledHeight() const;

    int getLayer() const;
    bool setLayer(int layer);

    float getScale() const;
    void setScale(float f);

    bool isRegistered() const;
    void registerObject();

    const unsigned long* getId() const {
        return &id;
    }

};



#endif //GAMEOBJECT_H