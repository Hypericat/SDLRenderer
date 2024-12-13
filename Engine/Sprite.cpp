//
// Created by Hypericats on 11/25/2024.
//

#include "Sprite.h"

#include <SDL_filesystem.h>
#include <utility>

#include "Util.h"

Sprite::Sprite(SDL_Surface *surface, const std::string& path, int width, int height) {
    this->m_path = path;
    this->m_texture = SDL_CreateTextureFromSurface(renderer, surface);
    this->m_width = width;
    this->m_height = height;

    if (this->m_texture == NULL) {
        printf("Failed to create texture from surface, most likely texture path invalid\n");
        printf("%s\n", SDL_GetError());
    }

    // Probably fine to call
    SDL_FreeSurface(surface);
}

Sprite::Sprite(const Sprite &sprite) {
    this->m_path = sprite.m_path;
    this->m_texture = Util::copyTexture(sprite.m_texture, renderer);
    this->m_width = sprite.m_width;
    this->m_height = sprite.m_height;
}



Sprite::Sprite(SDL_Surface *surface, const std::string &path) {
    this->m_path = path;
    this->m_texture = SDL_CreateTextureFromSurface(renderer, surface);

    this->m_width = -1;
    this->m_height = -1;

    // Set width and height
    SDL_QueryTexture(this->m_texture, nullptr, nullptr, &m_width, &m_height);

    // Probably fine to call
    SDL_FreeSurface(surface);
}


Sprite* Sprite::fromBMP(const std::string& path) {
    const std::string fullPath = std::string(SDL_GetBasePath()) + R"(assets\textures\)" + path;
    SDL_Surface* surface = SDL_LoadBMP(fullPath.c_str());

    if(surface == NULL) {
        printf( "Unable to load image %s! SDL Error: %s\n", fullPath.c_str(), SDL_GetError() );
    }

    return new Sprite(surface, fullPath);
}

SDL_Texture *Sprite::getTexture() const {
    return this->m_texture;
}

const std::string &Sprite::getPath() {
    return this->m_path;
}

int Sprite::getWidth() const {
    return this->m_width;
}

int Sprite::getHeight() const {
    return this->m_height;
}

void Sprite::setWidth(int width) {
    this->m_width = width;
}

void Sprite::setHeight(int height) {
    this->m_height = height;
}

Sprite::Sprite(Sprite &&other) noexcept {
    this->m_texture = other.m_texture;
    this->m_path = std::move(other.m_path);
    this->m_width = other.m_width;
    this->m_height = other.m_height;

    // Remove other instance so it isn't freed
    other.m_texture = nullptr;
}

Sprite& Sprite::operator=(Sprite&& other) noexcept {
    if (this == &other) return *this;

    // If had existing texture free it
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
    }

    this->m_texture = other.m_texture;
    this->m_path = std::move(other.m_path);
    this->m_width = other.m_width;
    this->m_height = other.m_height;


    // Remove other instance so it isn't freed
    other.m_texture = nullptr;
    return *this;
}


std::string Sprite::toString() const {
    return std::string ("Sprite: " + this->m_path + " width : " + (this->m_width + " height : " + this->m_height));
}

Sprite::~Sprite() {
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
}
