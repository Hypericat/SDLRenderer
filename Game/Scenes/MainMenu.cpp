//
// Created by Hypericats on 1/20/2025.
//

#include "MainMenu.h"

#include <iostream>

#include "../Objects/PlayerHair.h"
#include "../Objects/SmallPlatform.h"
#include "../Objects/TextObject.h"

void MainMenu::loadGameObjects(Game *game) {
    GameObject* bg = new GameObject(std::move(*Sprite::fromPNG("sky.png")));
    bg->setCollisionScale(0);
    bg->setRenderScale(8);
    populateBackground(bg);


    TextObject* text = new TextObject("hello");
    text->setLayer(8);
    text->setCollideable(false);
    text->setRenderScale(800);
    initGameObject(text, game);

}
