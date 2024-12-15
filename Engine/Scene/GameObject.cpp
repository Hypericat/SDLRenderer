//
// Created by Hypericats on 12/8/2024.
//

#include "GameObject.h"

#include "GameObjectDispatcher.h"

GameObject::GameObject(Sprite&& sprite) : m_sprite(std::move(sprite)), m_width(sprite.getWidth()), m_height(sprite.getHeight()), m_boundingBox(this->getPos(), this->getCollisionWidth(), this->getCollisionHeight()) {
    this->id = GameObjectDispatcher::getNextID();
}

GameObject::GameObject(Sprite&& sprite, const int width, const int height) : m_sprite(std::move(sprite)), m_width(width), m_height(height), m_boundingBox(this->getPos(), this->getCollisionWidth(), this->getCollisionHeight()) {
    this->id = GameObjectDispatcher::getNextID();
}

GameObject::GameObject(const GameObject &gameObject) : m_sprite(gameObject.m_sprite), m_width(gameObject.m_width), m_height(gameObject.m_height), m_boundingBox(this->getPos(), this->getCollisionWidth(), this->getCollisionHeight()) {
    this->id = GameObjectDispatcher::getNextID();
    this->m_layer = gameObject.m_layer;
    this->m_collisionScale = gameObject.m_collisionScale;
    this->m_x = gameObject.getX();
    this->m_y = gameObject.getY();
}

const Sprite* GameObject::getSprite() {
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

float GameObject::getCollisionScale() const {
    return this->m_collisionScale;
}

void GameObject::setCollisionScale(const float f) {
    this->m_collisionScale = f;
}

void GameObject::updateBoundingBox() {
    this->m_boundingBox = Box(this->getPos(), this->getCollisionWidth(), this->getCollisionHeight());
}

const Box& GameObject::getBoundingBox() {
    return this->m_boundingBox;
}


bool GameObject::shouldDrawHitbox() const {
    return this->m_drawHitbox;
}

bool GameObject::isCollideable() const {
    return this->m_collideable;
}

void GameObject::setCollideable(bool b) {
    this->m_collideable = b;
}

void GameObject::setDrawHitbox(bool b) {
    this->m_drawHitbox = b;
}

Vector2i GameObject::getPos() const {
    return Vector2i(this->m_x, this->m_y);
}

void GameObject::addY(const int y) {
    this->m_y += y;
}

void GameObject::addX(const int x) {
    this->m_x += x;
}

void GameObject::setAxisFromDir(const Vector2i &vec, const Direction::ENUM &dir) {
    if (dir == Direction::NONE) return;
    if (dir == Direction::UP || dir == Direction::DOWN) {
        this->m_y = vec.getY();
        return;
    }
    this->m_x = vec.getX();
}

// The layer must be set before it is added to the scene or it will not work correctly
bool GameObject::setLayer(const int layer) {
    if (this->isRegistered()) return false;
    this->m_layer = layer;
    return true;
}

int GameObject::getCollisionWidth() const {
    return this->getCollisionScale() * this->m_width;
}

int GameObject::getCollisionHeight() const {
    return this->getCollisionScale() * this->m_height;
}

bool GameObject::isRegistered() const {
    return this->m_registered;
}

int GameObject::getRenderWidth() const {
    return this->getRenderScale() * this->m_sprite.getWidth();
}

int GameObject::getRenderHeight() const {
    return this->getRenderScale() * this->m_sprite.getHeight();
}

void GameObject::setRenderScale(float f) {
    this->m_renderScale = f;
}

float GameObject::getRenderScale() const {
    return this->m_renderScale;
}

void GameObject::registerObject() {
    this->m_registered = true;
}

GameObject::~GameObject() {

}

void GameObject::applyTextureXOffset(Vector2i& vec) {

}

void GameObject::applyTextureYOffset(Vector2i& vec) {

}

