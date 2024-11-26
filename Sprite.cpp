//
// Created by Hypericats on 11/25/2024.
//

#include "Sprite.h"

#include <utility>

Sprite::Sprite(SDL_Surface *surface, const SDL_PixelFormat *fmt, std::string path) {
    this->m_path = "assets\\textures\\" + std::move(path);
    //SDL_Surface *optimized = SDL_ConvertSurface(surface, fmt, 0);
    this->m_texture = SDL_CreateTextureFromSurface(renderer, surface);

    // remove the original
    SDL_FreeSurface(surface);
}

std::unique_ptr<Sprite> Sprite::fromBMP(const std::string& path, const SDL_PixelFormat *fmt) {
    SDL_Surface* surface = SDL_LoadBMP("C:\\Users\\Hypericats\\CLionProjects\\SDLRenderer\\assets\\textures\\test.bmp");

    if(surface == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return std::unique_ptr<Sprite> (new Sprite(surface, fmt, path));
}

SDL_Texture *Sprite::getTexture() {
    return m_texture;
}

const std::string &Sprite::getPath() {
    return m_path;
}

Sprite::~Sprite() {
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
}
