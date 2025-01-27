//
// Created by Hypericats on 1/27/2025.
//

#include "TextObject.h"

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"

TextObject::TextObject(const std::string &text) : GameObject(std::move(*spriteFromString(text))) {

}

void TextObject::setText(const std::string &text) {

}

Sprite* TextObject::spriteFromString(const std::string &text) {
    //this opens a font style and sets a size
    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

    // this is the color in rgb format,
    // maxing out all would give you the color white,
    // and it will be your text's color
    SDL_Color White = {255, 255, 255};

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), White);

    // now you can convert it into a texture
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Sprite::renderer, surfaceMessage);

    SDL_FreeSurface(surfaceMessage);
    return new Sprite(tex, "");
}
