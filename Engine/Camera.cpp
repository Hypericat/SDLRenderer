//
// Created by Hypericats on 12/9/2024.
//

#include "Camera.h"

int Camera::getX() const {
    return this->m_x;
}

int Camera::getY() const {
    return this->m_y;
}

float Camera::getZoom() const {
    return this->m_zoom;
}

void Camera::setX(int x) {
    this->m_x = x;
}

void Camera::setY(int y) {
    this->m_y = y;
}

void Camera::setZoom(float zoom) {
    this->m_zoom = zoom;
}
