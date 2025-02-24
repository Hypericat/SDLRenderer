//
// Created by Hypericats on 2/24/2025.
//

#include "DecorationHandler.h"
#include "../Game.h"

DecorationHandler::DecorationHandler(Game* game, Scene* scene, int count) {
    m_decorations.resize(count);
    for (int i = 0; i < count; i++) {
        m_decorations.push_back(new Decoration());
    }
}

void DecorationHandler::updateDecorations(Game* game, Scene* scene) {

}
