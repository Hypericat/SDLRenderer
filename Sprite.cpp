//
// Created by Hypericats on 11/25/2024.
//

#include "Sprite.h"

#include <utility>

Sprite::Sprite(SDL_Surface *surface, const SDL_PixelFormat *fmt, std::string path) {
    this->m_path = "assets\\textures\\" + std::move(path);
    //SDL_Surface *optimized = SDL_ConvertSurface(surface, fmt, 0);
    this->m_texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (this->m_texture == NULL) {
        printf("Failed to create texture from surface, most likely texture path invalid\n");
        printf("%s\n", SDL_GetError());
    }

    // remove the original
    //SDL_FreeSurface(surface);
}

Sprite* Sprite::fromBMP(std::string& path, const SDL_PixelFormat *fmt) {
    path = "C:\\Users\\Hypericats\\CLionProjects\\SDLRenderer\\assets\\textures\\test.bmp";
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());

    if(surface == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return new Sprite(surface, fmt, path);
}

SDL_Texture *Sprite::getTexture() const {
    return m_texture;
}

const std::string &Sprite::getPath() {
    return m_path;
}

Sprite::~Sprite() {
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
}
