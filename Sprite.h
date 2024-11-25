//
// Created by Hypericats on 11/25/2024.
//

#ifndef SPRITE_H
#define SPRITE_H
#include <memory>
#include <SDL_surface.h>
#include <string>


class Sprite {
private:
    Sprite(SDL_Surface *surface, const SDL_PixelFormat *fmt, std::string path);
    SDL_Surface *m_surface;
    std::string m_path;

public:
    static std::unique_ptr<Sprite> fromBMP(const std::string& path, const SDL_PixelFormat *fmt);
    ~Sprite();

    SDL_Surface *getSurface();
    const std::string& getPath();
};



#endif //SPRITE_H
