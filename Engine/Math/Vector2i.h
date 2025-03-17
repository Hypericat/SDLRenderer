//
// Created by Hypericats on 12/10/2024.
//

#ifndef VECTOR2I_H
#define VECTOR2I_H

class Vector2f;


class Vector2i {
private:
    int m_x;
    int m_y;
public:
    explicit Vector2i(int x, int y) : m_x(x), m_y(y) {};
    explicit Vector2i(float x, float y) : m_x(x), m_y(y) {};
    explicit Vector2i(const Vector2i* vec2i) : Vector2i(vec2i->m_x, vec2i->m_y) {};
    explicit Vector2i(const Vector2f* vec2f);

    int getX() const;
    int getY() const;

    Vector2f toVec2f() const;
    Vector2i operator+(Vector2i& vec) const;
    Vector2i operator-(Vector2i& vec) const;
    Vector2i operator*(Vector2i& vec) const;
    Vector2i operator/(Vector2i& vec) const;
    bool operator>(Vector2i& vec) const;
    bool operator<(Vector2i& vec) const;
    bool operator<=(Vector2i& vec) const;
    bool operator>=(Vector2i& vec) const;
    bool operator==(Vector2i& vec) const;
    bool operator!=(Vector2i& vec) const;
    Vector2i& operator=(const Vector2i& vec);
    Vector2i& operator+=(const Vector2i& vec);
    Vector2i& operator-=(const Vector2i& vec);
    Vector2i& operator*=(const Vector2i& vec);
    Vector2i& operator/=(const Vector2i& vec);

    int seed() const;

    void div(int divisor);

    void setY(int y);
    void setX(int x);
};



#endif //VECTOR2I_H
