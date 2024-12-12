//
// Created by Hypericats on 12/8/2024.
//

#include "GameObject.h"

#include "GameObjectDispatcher.h"

GameObject::GameObject(Sprite&& sprite) : m_sprite(std::move(sprite)) {
    this->id = GameObjectDispatcher::getNextID();
}

GameObject::GameObject(Sprite&& sprite, const int x, const int y) : m_sprite(std::move(sprite)) {
    this->id = GameObjectDispatcher::getNextID();
    this->m_x = x;
    this->m_y = y;
}

GameObject::GameObject(const GameObject &gameObject) : m_sprite(gameObject.m_sprite) {
    this->id = GameObjectDispatcher::getNextID();
    this->m_layer = gameObject.m_layer;
    this->m_scale = gameObject.m_scale;
    this->m_x = gameObject.getX();
    this->m_y = gameObject.getY();
}

const Sprite* GameObject::getSprite() const {
    return &this->m_sprite;
}

int GameObject::getX() const {
    return this->m_x;
}

int GameObject::getY() const {
    return this->m_y;
}

int* GameObject::getXPtr() {
    return &this->m_x;
}

int* GameObject::getYPtr() {
    return &this->m_y;
}

void GameObject::setX(const int x) {
    this->m_x = x;
}

void GameObject::setY(const int y) {
    this->m_y = y;
}

int GameObject::getLayer() const {
    return this->m_layer;
}

float GameObject::getScale() const {
    return this->m_scale;
}

void GameObject::setScale(float f) {
    this->m_scale = f;
}

// The layer must be set before it is added to the scene or it will not work correctly

void GameObject::setLayer(int layer) {
    this->m_layer = layer;
}

int GameObject::getScaledWidth() const {
    return this->getScale() * this->m_sprite.getWidth();
}

int GameObject::getScaledHeight() const {
    return this->getScale() * this->m_sprite.getHeight();
}

int GameObject::getLogicalLayer() const {
    return 2147483647 - this->m_layer;
}

GameObject::~GameObject() {

}

