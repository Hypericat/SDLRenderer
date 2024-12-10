//
// Created by Hypericats on 12/10/2024.
//

#ifndef VECTOR2f_H
#define VECTOR2f_H

class Vector2i;


class Vector2f {
private:
    const float m_x;
    const float m_y;
public:
    explicit Vector2f(int x, int y) : m_x(x), m_y(y) {};
    explicit Vector2f(float x, float y) : m_x(x), m_y(y) {};
    explicit Vector2f(const Vector2i* vec2i);
    explicit Vector2f(const Vector2f* vec2f) : Vector2f(vec2f->m_x, vec2f->m_y) {};

    float getX() const;
    float getY() const;

    Vector2i toVec2i() const;
    Vector2f operator+(Vector2f& vec) const;
    Vector2f operator-(Vector2f& vec) const;
    bool operator>(Vector2f& vec) const;
    bool operator<(Vector2f& vec) const;
    bool operator<=(Vector2f& vec) const;
    bool operator>=(Vector2f& vec) const;
    bool operator==(Vector2f& vec) const;
    bool operator!=(Vector2f& vec) const;

    Vector2f withY(float y) const;
    Vector2f withX(float x) const;
};



#endif //VECTOR2f_H
