//
// Created by Hypericats on 1/27/2025.
//

#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H
#include "../../Engine/Scene/GameObject.h"


class TextObject : public GameObject {
public:
    explicit TextObject(const std::string& text);
    void setText(const std::string& text);
private:
    Sprite* spriteFromString(const std::string& text);

};



#endif //TEXTOBJECT_H
