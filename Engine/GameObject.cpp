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

GameObject::~GameObject() {

}
