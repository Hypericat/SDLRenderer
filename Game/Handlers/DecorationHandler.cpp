//
// Created by Hypericats on 2/24/2025.
//

#include "DecorationHandler.h"

#include <iostream>

#include "../Game.h"

DecorationHandler::DecorationHandler(Game* game, Scene* scene, int count) {
    this->m_game = game;
    m_decorations.reserve(count);
    for (int i = 0; i < count; i++) {
        Decoration* decoration = new Decoration();;
        m_decorations.push_back(decoration);
        scene->initGameObject(decoration, game);
    }
}

void DecorationHandler::updateDecorations(Game* game, Scene* scene, int x, int y, int width, int height) {

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

    Decoration* decoration = this->m_decorations.at(m_decorationIndex++);

    //std::cout << "Showing object at " << chunk->getX() + xOffset << " : " << chunk->getY() + yOffset << std::endl;

    if (decoration == nullptr) std::cout << "NULL" << std::endl;

    m_game->getWindow().getRenderer().drawLine(m_game->getScene()->getPlayer()->getPos(), Vector2i(chunk->getX() + xOffset, chunk->getY() + yOffset));

    decoration->setX(chunk->getX() + xOffset);// Crashing here because the pointer is null
    decoration->setY(chunk->getY() + yOffset);
    decoration->setVisible(true);

    delete chunk;
}

void DecorationHandler::free() {
    for (int i = 0; i < m_decorations.size(); i++) {
        delete m_decorations.at(i);
    }
    m_decorations.clear();
}


