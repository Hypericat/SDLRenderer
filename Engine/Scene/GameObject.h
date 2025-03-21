//
// Created by Hypericats on 12/8/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "../Sprite.h"
#include "../Math/Box.h"
#include "../Math/Vector2i.h"

class Game;

class GameObject {
private:
    Sprite m_sprite;
    int m_x = 0;
    int m_y = 0;
    int m_width = 0;
    int m_height;
    float m_collisionScale = 1.0F;
    float m_renderScale = 1.0F;
    int m_layer = 0;
    unsigned long id;
    bool m_drawHitbox = false;
    bool m_registered = false;
    bool m_collideable = false;
    bool m_visible = true;

protected:
    Box m_boundingBox;

public:
    explicit GameObject(Sprite&& sprite);
    GameObject(const GameObject& gameObject);
    GameObject(Sprite&& sprite, int width, int height);

    virtual ~GameObject();

    virtual const Sprite* getSprite();
    int getX() const;
    int getY() const;
    int* getXPtr();
    int* getYPtr();
    void setX(int x);
    void setY(int y);
    void addY(int y);
    void addX(int x);

    virtual void onCollision(GameObject* other, const Direction::ENUM& dir);

    int getCollisionWidth() const;
    int getCollisionHeight() const;

    int getRenderWidth() const;
    int getRenderHeight() const;

    int getLayer() const;
    bool setLayer(int layer);

    float getCollisionScale() const;
    void setCollisionScale(float f);

    void setRenderScale(float f);
    float getRenderScale() const;

    bool isRegistered() const;
    void registerObject();

    const Box& getBoundingBox();
    virtual void updateBoundingBox();

    bool isVisible();
    void setVisible(bool visible);

    Vector2i getPos() const;

    bool shouldDrawHitbox() const;
    void setDrawHitbox(bool b);

    bool isCollideable() const;
    void setCollideable(bool b);

    void setAxisFromDir(const Vector2i& vec, const Direction::ENUM& dir);

    virtual void applyTextureXOffset(Vector2i& vec);
    virtual void applyTextureYOffset(Vector2i& vec);

    virtual void preRender(Game* game);
    virtual void postRender(Game* game);




    const unsigned long* getId() const {
        return &id;
    }

};



#endif //GAMEOBJECT_H
