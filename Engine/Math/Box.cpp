//
// Created by Hypericats on 12/13/2024.
//

#include "Box.h"

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

bool Box::collidesWith(const Box &box) const {
    /*
    int temp;
    int x1 = this->getMax().getX();
    int x2 = box.getMax().getX();
    int y1 = this->getMin().getY();
    int y2 = box.getMin().getY();

    if (x1 < x2) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }

    if (y1 < y2) {
        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    // X1 is bigger than x2
    // Y1 is bigger than y2
    */

    return !(this->getMax().getX() < box.getMin().getX() ||
             this->getMin().getX() > box.getMax().getX() ||
             this->getMax().getY() < box.getMin().getY() ||
             this->getMin().getY() > box.getMax().getY());
}

Vector2i Box::getCenter() {
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
