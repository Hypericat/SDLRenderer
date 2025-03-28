//
// Created by Hypericats on 2/24/2025.
//

#ifndef DECORATIONHANDLER_H
#define DECORATIONHANDLER_H

#include <vector>
#include <Math.h>

#include "../Objects/Decoration.h"


class Game;
class Scene;

class DecorationHandler {
private:
    Game* m_game;
    int m_decorationIndex = 0;
    std::pmr::vector<Decoration*> m_decorations;
    void decorate(const Vector2i* chunk, int width, int height);
public:
    DecorationHandler(Game* game, Scene* scene, int count);
    void updateDecorations(Game* game, Scene* scene, int x, int y, int width, int height);
    void free();
};



#endif //DECORATIONHANDLER_H
