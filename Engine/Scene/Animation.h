//
// Created by Hypericats on 12/15/2024.
//

#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>

#include "../Sprite.h"


class Animation {
private:
    std::vector<Sprite*> sprites;
    int m_index;

public:
    Animation();
    void addSprite(Sprite* sprite, int length);
    Sprite* nextSprite();
    Sprite* getSprite(int index) const;
    int getIndex() const;
    void setIndex(int i);
    void reset();
    void free();

};



#endif //ANIMATION_H