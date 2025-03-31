//
// Created by Hypericats on 2/24/2025.
//

#ifndef DECORATION_H
#define DECORATION_H
#include <vector>

#include "../../Engine/Scene/Animation.h"
#include "../../Engine/Scene/GameObject.h"


class Decoration : public GameObject {
private:
    int animationIndex = 0;
    int decorationIndex = 0;
    static inline std::vector<Animation*> animations;


public:
    static void init();
    explicit Decoration();

    void random();
    const Sprite* getSprite() override;
};



#endif //DECORATION_H
