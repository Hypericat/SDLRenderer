//
// Created by Hypericats on 2/24/2025.
//

#ifndef DECORATIONHANDLER_H
#define DECORATIONHANDLER_H
#include <list>

#include "../Objects/Decoration.h"


class Game;
class Scene;

class DecorationHandler {
private:
    std::list<Decoration*> m_decorations;
public:
    DecorationHandler(Game* game, Scene* scene, int count);
    void updateDecorations(Game* game, Scene* scene);
};



#endif //DECORATIONHANDLER_H
