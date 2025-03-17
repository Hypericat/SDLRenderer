//
// Created by Hypericats on 12/10/2024.
//

#include "Vector2i.h"

#include <stdlib.h>

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

void Vector2i::setY(int y) {
    this->m_y = y;
}

void Vector2i::setX(int x) {
    this->m_x = x;
}

Vector2i Vector2i::operator*(Vector2i &vec) const {
    return Vector2i(getX() * vec.getX(), getY() * vec.getY());
}

Vector2i Vector2i::operator/(Vector2i &vec) const {
    return Vector2i(getX() / vec.getX(), getY() / vec.getY());
}

Vector2i& Vector2i::operator+=(const Vector2i &vec) {
    this->m_x += vec.getX();
    this->m_y += vec.getY();
    return *this;
}

Vector2i & Vector2i::operator-=(const Vector2i &vec) {
    this->m_x -= vec.getX();
    this->m_y -= vec.getY();
    return *this;
}

Vector2i & Vector2i::operator*=(const Vector2i &vec) {
    this->m_x *= vec.getX();
    this->m_y *= vec.getY();
    return *this;
}

Vector2i & Vector2i::operator/=(const Vector2i &vec) {
    this->m_x /= vec.getX();
    this->m_y /= vec.getY();
    return *this;
}

Vector2i& Vector2i::operator=(const Vector2i &vec) {
    this->m_x = vec.getX();
    this->m_y = vec.getY();
    return *this;
}

void Vector2i::div(const int divisor) {
    this->m_x /= divisor;
    this->m_y /= divisor;
}

int Vector2i::seed() const {
    return m_x ^ m_y;
}

Vector2i::Vector2i(const Vector2f *vec2f) : Vector2i(vec2f->getX(), vec2f->getY()) {

}
