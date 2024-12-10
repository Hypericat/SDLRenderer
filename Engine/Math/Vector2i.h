//
// Created by Hypericats on 12/10/2024.
//

#ifndef VECTOR2_H
#define VECTOR2_H
#include "Vector2f.h"


class Vector2i {
private:
    const int m_x;
    const int m_y;
public:
    explicit Vector2i(int x, int y) : m_x(x), m_y(y) {};
    explicit Vector2i(float x, float y) : m_x(x), m_y(y) {};
    Vector2i(Vector2i* vec2i) : Vector2i(vec2i->m_x, vec2i->m_y) {};
    Vector2i(Vector2f* vec2f) : Vector2i(vec2f->x, vec2f->y) {};

    int getX();
    int getY();

    Vector2f toVec2f();
    Vector2i operator+(Vector2i& vec);
    Vector2i operator-(Vector2i& vec);
    bool operator>(Vector2i& vec);
    bool operator<(Vector2i& vec);
    bool operator<=(Vector2i& vec);
    bool operator>=(Vector2i& vec);
    bool operator==(Vector2i& vec);
    bool operator!=(Vector2i& vec);

    Vector2i withY(int y);
    Vector2i withX(int x);
};



#endif //VECTOR2_H
