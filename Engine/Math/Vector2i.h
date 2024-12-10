//
// Created by Hypericats on 12/10/2024.
//

#ifndef VECTOR2i_H
#define VECTOR2i_H
#include "Vector2f.h"


class Vector2i {
private:
    const int m_x;
    const int m_y;
public:
    explicit Vector2i(int x, int y) : m_x(x), m_y(y) {};
    explicit Vector2i(float x, float y) : m_x(x), m_y(y) {};
    explicit Vector2i(const Vector2i* vec2i) : Vector2i(vec2i->m_x, vec2i->m_y) {};
    explicit Vector2i(const Vector2f* vec2f) : Vector2i(vec2f->getX(), vec2f->getY()) {};

    int getX() const;
    int getY() const;

    Vector2f toVec2f() const;
    Vector2i operator+(Vector2i& vec) const;
    Vector2i operator-(Vector2i& vec) const;
    bool operator>(Vector2i& vec) const;
    bool operator<(Vector2i& vec) const;
    bool operator<=(Vector2i& vec) const;
    bool operator>=(Vector2i& vec) const;
    bool operator==(Vector2i& vec) const;
    bool operator!=(Vector2i& vec) const;

    Vector2i withY(int y) const;
    Vector2i withX(int x) const;
};



#endif //VECTOR2i_H
