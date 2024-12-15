//
// Created by Hypericats on 12/8/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "../Sprite.h"
#include "../Math/Box.h"
#include "../Math/Vector2i.h"


class GameObject {
private:
    Sprite m_sprite;
    int m_x = 0;
    int m_y = 0;
    float m_scale = 1.0F;
    int m_layer = 0;
    Box m_boundingBox;
    unsigned long id;
    bool m_drawHitbox = false;
    bool m_registered = false;
    bool m_collideable = false;

public:
    explicit GameObject(Sprite&& sprite);
    GameObject(const GameObject& gameObject);
    GameObject(Sprite&& sprite, int x, int y);

    virtual ~GameObject();

    const Sprite* getSprite() const;
    int getX() const;
    int getY() const;
    int* getXPtr();
    int* getYPtr();
    void setX(int x);
    void setY(int y);
    void addY(int y);
    void addX(int x);

    int getScaledWidth() const;
    int getScaledHeight() const;

    int getLayer() const;
    bool setLayer(int layer);

    float getScale() const;
    void setScale(float f);

    bool isRegistered() const;
    void registerObject();

    const Box& getBoundingBox();
    virtual void updateBoundingBox();

    Vector2i getPos() const;

    bool shouldDrawHitbox() const;
    void setDrawHitbox(bool b);

    bool isCollideable() const;
    void setCollideable(bool b);

    void setAxisFromDir(const Vector2i& vec, const Direction::ENUM& dir);




    const unsigned long* getId() const {
        return &id;
    }

};



#endif //GAMEOBJECT_H
