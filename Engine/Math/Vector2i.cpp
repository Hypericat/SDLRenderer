//
// Created by Hypericats on 12/10/2024.
//

#include "Vector2i.h"
#include "Vector2f.h"


int Vector2i::getX() const {
    return m_x;
}

int Vector2i::getY() const {
    return m_y;
}

Vector2f Vector2i::toVec2f() const {
    return Vector2f(m_x, m_y);
}

Vector2i Vector2i::operator+(Vector2i& vec) const {
    Vector2i res(getX() + vec.getX(), getX() + vec.getY());
    return res;
}

Vector2i Vector2i::operator-(Vector2i& vec) const {
    Vector2i res(getX() - vec.getX(), getX() - vec.getY());
    return res;
}

bool Vector2i::operator>(Vector2i& vec) const {
    return getY() * getY() + getX() * getX() > vec.getX() * vec.getX() + vec.getY() * vec.getY();
}

bool Vector2i::operator<(Vector2i& vec) const {
    return getY() * getY() + getX() * getX() < vec.getX() * vec.getX() + vec.getY() * vec.getY();
}

bool Vector2i::operator<=(Vector2i& vec) const {
    return *this < vec || *this == vec;
}

bool Vector2i::operator==(Vector2i &vec) const {
    return getX() == vec.getX() && getY() == vec.getY();
}

bool Vector2i::operator!=(Vector2i &vec) const {
    return !(*this == vec);
}

bool Vector2i::operator>=(Vector2i& vec) const {
    return *this > vec || *this == vec;
}

Vector2i Vector2i::withY(int y) const {
    return Vector2i(getX(), y);
}

Vector2i Vector2i::withX(int x) const {
    return Vector2i(x, getY());
}

Vector2i::Vector2i(const Vector2f *vec2f) : Vector2i(vec2f->getX(), vec2f->getY()) {

}
