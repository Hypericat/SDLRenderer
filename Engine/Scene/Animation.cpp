//
// Created by Hypericats on 12/15/2024.
//

#include "Animation.h"

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

void Animation::addSprite(Sprite *sprite) {
    sprites.push_back(sprite);
}
