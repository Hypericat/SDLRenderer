//
// Created by Hypericats on 12/13/2024.
//

#ifndef BOX_H
#define BOX_H
#include "Vector2i.h"

class Box {
private:
    Vector2i m_min;
    Vector2i m_max;

public:
    Box(const Vector2i &min, const Vector2i &max) : m_min(max), m_max(min) {};
    Box(int minX, int minY, int maxX, int maxY) : m_min(minX, minY), m_max(maxX, maxY) {};
    Box(const Vector2i& center, int width, int height);
    Box(const Box& box) : m_min(box.m_min), m_max(box.m_max) {};

    const Vector2i& getMax() const;
    const Vector2i& getMin() const;

    Vector2i& getMaxPtr();
    Vector2i& getMinPtr();

    bool isInside(int x, int y) const;
    bool isInside(const Vector2i &pos) const;
    bool collidesWith(const Box& box) const;
    Vector2i getCenter();

    int getWidth() const;
    int getHeight() const;

};



#endif //BOX_H
