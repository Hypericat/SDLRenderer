//
// Created by Hypericats on 12/9/2024.
//

#include "Camera.h"

Vector2i& Camera::getPos() {
    return m_cameraPosition;
}

int Camera::getX() const {
    return this->m_cameraPosition.getX();
}

int Camera::getY() const {
    return this->m_cameraPosition.getY();
}

float Camera::getZoom() const {
    return this->m_zoom;
}

void Camera::setX(int x) {
    this->m_cameraPosition.setX(x);
}

void Camera::setY(int y) {
    this->m_cameraPosition.setY(y);
}

void Camera::setPos(const Vector2i &pos) {
    this->m_cameraPosition = pos;
}

void Camera::setZoom(float zoom) {
    this->m_zoom = zoom;
}

void Camera::applyOffset(Vector2i &vec) const {
    vec -= this->m_cameraPosition;
}

void Camera::negateOffset(Vector2i &vec) const {
    vec += this->m_cameraPosition;
}
