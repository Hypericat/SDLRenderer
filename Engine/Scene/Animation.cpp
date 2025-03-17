//
// Created by Hypericats on 12/15/2024.
//

#include "Animation.h"

#include <iostream>

Animation::Animation() {
    m_index = 0;
}

void Animation::addSprite(Sprite *sprite, const int length) {
    for (int i = 0; i < length; i++) {
        sprites.push_back(sprite);
    }
}

Sprite* Animation::nextSprite() {
    if (m_index >= sprites.size()) reset();
    return sprites.at(m_index++);
}

Sprite* Animation::nextSprite(int &index) const {
    if (index >= sprites.size()) index = 0;
    return sprites.at(index++);
}

Sprite* Animation::getSprite(int index) const {
    if (index >= sprites.size()) index = 0;
    return sprites.at(index);
}

void Animation::reset() {
    this->m_index = 0;
}

int Animation::getIndex() const {
    return this->m_index;
}

void Animation::setIndex(const int i) {
    this->m_index = i;
}

void Animation::free() {
    for (const Sprite* sprite : sprites) {
        delete sprite;
    }
    sprites.clear();
}

int Animation::getSize() {
    return sprites.size();
}

bool Animation::isLast() const {
    return m_index >= sprites.size() - 1;
}

Animation* Animation::cpSetFlip(const SDL_RendererFlip flip) {
    Animation* animation = new Animation();
    Sprite* lastSprite = nullptr;
    Sprite* newSprite = nullptr;
    for (Sprite* sprite : sprites) {
        if (lastSprite == sprite) {
            animation->addSprite(newSprite);
            continue;
        }
        // Copy texture would be better but has issues when resizing window
        newSprite = Sprite::fromFullPNG(sprite->getPath());
        newSprite->setRenderFlip(flip);
        animation->addSprite(newSprite);
        lastSprite = sprite;
    }
    return animation;
}

// This does not work
// PLEASE DO NOT USE THIS
// IT CRASHES BECAUSE FOR SOME REASON THE SPRITES BECOME NULL
Animation::Animation(const Animation &animation) {
    this->m_index = 0;
    Sprite* lastSprite = nullptr;
    Sprite* newSprite = nullptr;
    for (Sprite* sprite : animation.sprites) {
        if (lastSprite == sprite && sprite != nullptr) {
            this->addSprite(newSprite);
            continue;
        }
        if (sprite == nullptr) {
            std::cout << "NULL" << std::endl;
            continue;
        }
        this->addSprite(Sprite::fromFullPNG(sprite->getPath()));
        lastSprite = sprite;
    }
}

void Animation::addSprite(Sprite *sprite) {
    sprites.push_back(sprite);
}
