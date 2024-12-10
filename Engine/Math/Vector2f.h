//
// Created by Hypericats on 12/10/2024.
//

#ifndef VECTOR2_H
#define VECTOR2_H
#include "Vector2i.h"


class Vector2f {
private:
    const int m_x;
    const int m_y;
public:
    explicit Vector2f(int x, int y) : m_x(x), m_y(y) {};
    explicit Vector2f(float x, float y) : m_x(x), m_y(y) {};
    Vector2f(Vector2i* vec2i) : Vector2f(vec2i->m_x, vec2i->m_y) {};
    Vector2f(Vector2f* vec2f) : Vector2f(vec2f->x, vec2f->y) {};

    int getX();
    int getY();

    Vector2i toVec2i();
    Vector2f operator+(Vector2f& vec);
    Vector2f operator-(Vector2f& vec);
    bool operator>(Vector2f& vec);
    bool operator<(Vector2f& vec);
    bool operator<=(Vector2f& vec);
    bool operator>=(Vector2f& vec);
    bool operator==(Vector2f& vec);
    bool operator!=(Vector2f& vec);

    Vector2f withY(int y);
    Vector2f withX(int x);
};



#endif //VECTOR2_H
