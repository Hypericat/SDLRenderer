//
// Created by Hypericats on 12/13/2024.
//

#include "Box.h"

#include <iostream>
#include <ostream>

const Vector2i& Box::getMax() const {
    return m_max;
}

const Vector2i& Box::getMin() const {
    return m_min;
}

bool Box::isInside(const int x, const int y) const {
    return x < this->m_max.getX() && y < this->m_max.getY() && x > this->m_min.getX() && y > this->m_min.getY();
}

bool Box::isInside(const Vector2i& pos) const {
    return isInside(pos.getX(), pos.getY());
}

Direction::ENUM Box::testCollision(const Box &box) const {

    // This makes it slightly faster if not colliding, but twice as slow if colliding
    // If adding this back remove the if below for checking NONE Direction
    /*
    // Determine if intersection at all
    if (this->getMax().getX() < box.getMin().getX() ||
        this->getMin().getX() > box.getMax().getX() ||
        this->getMax().getY() < box.getMin().getY() ||
        this->getMin().getY() > box.getMax().getY()) {
        return Direction::NONE;
    }s
    */

    int dx1 = this->getMax().getX() - box.getMin().getX(); // Right
    int dy1 = this->getMax().getY() - box.getMin().getY(); // Down

    int dx2 = box.getMax().getX() - this->getMin().getX(); // Left
    int dy2 = box.getMax().getY() - this->getMin().getY(); // Up

    if (!(dx1 > 0 && dy1 > 0 && dx2 > 0 && dy2 > 0)) {
        return Direction::NONE;
    }

    // The smallest value will have the biggest overlap
    if (dy1 <= dx1 && dy1 <= dx2 && dy1 <= dy2) {
        return Direction::DOWN;
    }
    if (dx1 <= dy1 && dx1 <= dx2 && dx1 <= dy2) {
        return Direction::RIGHT;
    }
    if (dx2 <= dy1 && dx2 <= dx1 && dx2 <= dy2) {
        return Direction::LEFT;
    }
    if (dy2 <= dy1 && dy2 <= dx2 && dy2 <= dx1) {
        return Direction::UP;
    }


    std::cerr << "Could not find collision" << std::endl;
    return Direction::NONE;
}

Vector2i Box::getDirPos(const Direction::ENUM& dir) const {
    switch (dir) {
        case Direction::NONE: return getCenter();
        case Direction::DOWN: return Vector2i(m_max.getX() + m_min.getX() >> 1, m_min.getY());
        case Direction::RIGHT: return Vector2i(m_min.getX(), m_max.getY() + m_min.getY() >> 1);
        case Direction::LEFT: return Vector2i(m_max.getX(), m_max.getY() + m_min.getY() >> 1);
        case Direction::UP: return Vector2i(m_max.getX() + m_min.getX() >> 1, m_max.getY());
        default: return getCenter();
    }
}

Vector2i Box::getCenter() const {
    return Vector2i(m_max.getX() + m_min.getX() >> 1, m_max.getY() + m_min.getY() >> 1);
}

Vector2i& Box::getMaxPtr() {
    return m_max;
}

Vector2i& Box::getMinPtr() {
    return m_min;
}

Box::Box(const Vector2i& center, const int width, const int height): m_min(center), m_max(center) {
    const Vector2i half = Vector2i(width >> 1, height >> 1);

    this->m_max += half;
    this->m_min -= half;
}

int Box::getWidth() const {
    return this->getMax().getX() - this->getMin().getX();
}

int Box::getHeight() const {
    return this->getMax().getY() - this->getMin().getY();
}
