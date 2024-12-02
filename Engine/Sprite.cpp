//
// Created by Hypericats on 11/25/2024.
//

#include "Sprite.h"

#include <SDL_filesystem.h>
#include <utility>

Sprite::Sprite(SDL_Surface *surface, const SDL_PixelFormat *fmt, std::string path, int width, int height, float scale) {
    this->m_path = path;
    this->m_texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->width = width;
    this->height = height;
    this->scale = scale;

    if (this->m_texture == NULL) {
        printf("Failed to create texture from surface, most likely texture path invalid\n");
        printf("%s\n", SDL_GetError());
    }

    // Probably fine to call
    SDL_FreeSurface(surface);
}

Sprite::Sprite(SDL_Surface *surface, const SDL_PixelFormat *fmt, std::string path) {
    this->m_path = path;
    this->m_texture = SDL_CreateTextureFromSurface(renderer, surface);

    this->scale = 1.0F;
    this->width = -1;
    this->height = -1;

    // Set width and height
    SDL_QueryTexture(this->m_texture, nullptr, nullptr, &width, &height);

    // Probably fine to call
    SDL_FreeSurface(surface);
}


Sprite* Sprite::fromBMP(std::string& path, const SDL_PixelFormat *fmt) {

    path = std::string(SDL_GetBasePath()) + R"(\assets\textures\)" + path;
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());

    if(surface == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return new Sprite(surface, fmt, path);
}

SDL_Texture *Sprite::getTexture() const {
    return this->m_texture;
}

const std::string &Sprite::getPath() {
    return this->m_path;
}

int Sprite::getWidth() const {
    return this->getDefaultWidth() * this->scale;
}

int Sprite::getHeight() const {
    return this->getDefaultHeight() * this->scale;
}

int Sprite::getDefaultWidth() const {
    return this->width;
}

int Sprite::getDefaultHeight() const {
    return this->height;
}

void Sprite::setWidth(int width) {
    this->width = width;
}

void Sprite::setHeight(int height) {
    this->height = height;
}

void Sprite::setScale(float scale) {
    this->scale = scale;
}


std::string Sprite::toString() const {
    return std::string ("Sprite: " + this->m_path + " width : " + (this->width + " height : " + this->height));
}

Sprite::~Sprite() {
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
}
