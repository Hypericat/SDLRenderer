//
// Created by Hypericats on 12/10/2024.
//

#include "Vector2i.h"

#include <algorithm>

int Vector2i::getX() {
    return m_x;
}

int Vector2i::getY() {
    return m_y;
}

Vector2f&& Vector2i::toVec2f() {

}

Vector2i Vector2i::operator+(Vector2i& vec) {
    Vector2i res(getX() + vec.getX(), getX() + vec.getY());
    return res;
}

Vector2i Vector2i::operator-(Vector2i& vec) {
    Vector2i res(getX() - vec.getX(), getX() - vec.getY());
    return res;
}

bool Vector2i::operator>(Vector2i& vec) {
    return getY() * getY() + getX() * getX() > vec.getX() * vec.getX() + vec.getY() * vec.getY();
}

bool Vector2i::operator<(Vector2i& vec) {
    return getY() * getY() + getX() * getX() < vec.getX() * vec.getX() + vec.getY() * vec.getY();
}

bool Vector2i::operator<=(Vector2i& vec) {
    return *this < vec || *this == vec;
}

bool Vector2i::operator==(Vector2i &vec) {
    return getX() == vec.getX() && getY() == vec.getY();
}

bool Vector2i::operator!=(Vector2i &vec) {
    return !(*this == vec);
}

bool Vector2i::operator>=(Vector2i& vec) {
    return *this > vec || *this == vec;
}

Vector2i Vector2i::withY(int y) {
    return Vector2i(getX(), y);
}

Vector2i Vector2i::withX(int x) {
    return Vector2i(x, getY());
}
