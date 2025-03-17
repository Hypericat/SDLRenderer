//
// Created by Hypericats on 2/24/2025.
//

#include "DecorationHandler.h"

#include <iostream>

#include "../Game.h"

DecorationHandler::DecorationHandler(Game* game, Scene* scene, int count) {
    m_decorations.resize(count);
    for (int i = 0; i < count; i++) {
        m_decorations.push_back(new Decoration());
    }
}

void DecorationHandler::updateDecorations(Game* game, Scene* scene, int x, int y, int width, int height) {
    if (true) return;

    this->m_decorationIndex = 0;
    decorate(new Vector2i(x, y), width, height);
    decorate(new Vector2i((x + width), y), width, height);
    decorate(new Vector2i(x, (y + height)), width, height);
    decorate(new Vector2i((x + width), (y + height)), width, height);



    //Vector2i cameraPos = camera.getPos();
}

void DecorationHandler::decorate(const Vector2i* chunk, int width, int height) {
    if (this->m_decorationIndex >= this->m_decorations.size()) return;

    srand(chunk->seed());

    // Returns true half the time
    // It should?
    if (rand() & 1) return;
    int xOffset = rand() %  width;
    int yOffset = rand() % height;

    std::cout << "Width : " << width << ", offset : " << xOffset << std::endl;

    Decoration* decoration = this->m_decorations.at(m_decorationIndex++);

    decoration->setX(chunk->getX() + xOffset);// Crashing here because the pointer is null
    decoration->setY(chunk->getY() + yOffset);
    decoration->setVisible(true);

    delete chunk;
}


