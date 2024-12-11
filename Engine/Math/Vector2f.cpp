//
// Created by Hypericats on 12/10/2024.
//

#include "Vector2f.h"
#include "Vector2i.h"

float Vector2f::getX() const {
    return m_x;
}

float Vector2f::getY() const {
    return m_y;
}

Vector2i Vector2f::toVec2i() const {
    return Vector2i(m_x, m_y);
}

Vector2f Vector2f::operator+(Vector2f& vec) const {
    Vector2f res(getX() + vec.getX(), getX() + vec.getY());
    return res;
}

Vector2f Vector2f::operator-(Vector2f& vec) const {
    Vector2f res(getX() - vec.getX(), getX() - vec.getY());
    return res;
}

bool Vector2f::operator>(Vector2f& vec) const {
    return getY() * getY() + getX() * getX() > vec.getX() * vec.getX() + vec.getY() * vec.getY();
}

bool Vector2f::operator<(Vector2f& vec) const {
    return getY() * getY() + getX() * getX() < vec.getX() * vec.getX() + vec.getY() * vec.getY();
}

bool Vector2f::operator<=(Vector2f& vec) const {
    return *this < vec || *this == vec;
}

bool Vector2f::operator==(Vector2f &vec) const {
    return getX() == vec.getX() && getY() == vec.getY();
}

bool Vector2f::operator!=(Vector2f &vec) const {
    return !(*this == vec);
}

bool Vector2f::operator>=(Vector2f& vec) const {
    return *this > vec || *this == vec;
}

Vector2f& Vector2f::operator=(const Vector2f &vec) {
    this->m_x = vec.getX();
    this->m_y = vec.getY();
    return *this;
}

void Vector2f::setY(float y) {
    this->m_y = y;
}

void Vector2f::setX(float x) {
    this->m_x = x;
}

Vector2f::Vector2f(const Vector2i *vec2i) : Vector2f(vec2i->getX(), vec2i->getY()) {

}

Vector2f Vector2f::operator*(Vector2f &vec) const {
    return Vector2f(getX() * vec.getX(), getY() * vec.getY());
}

Vector2f Vector2f::operator/(Vector2f &vec) const {
    return Vector2f(getX() / vec.getX(), getY() / vec.getY());
}

Vector2f& Vector2f::operator+=(const Vector2f &vec) {
    this->m_x += vec.getX();
    this->m_y += vec.getY();
    return *this;
}

Vector2f & Vector2f::operator-=(const Vector2f &vec) {
    this->m_x -= vec.getX();
    this->m_y -= vec.getY();
    return *this;
}

Vector2f & Vector2f::operator/=(const Vector2f &vec) {
    this->m_x /= vec.getX();
    this->m_y /= vec.getY();
    return *this;
}

Vector2f & Vector2f::operator*=(const Vector2f &vec) {
    this->m_x *= vec.getX();
    this->m_y *= vec.getY();
    return *this;
}

const Vector2f Vector2f::ZERO = Vector2f(0.0F, 0.0F);
