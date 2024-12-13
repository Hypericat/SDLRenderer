//
// Created by Hypericats on 11/25/2024.
//

#ifndef SPRITE_H
#define SPRITE_H
#include <memory>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <string>


class Sprite {
private:
    SDL_Texture *m_texture;
    std::string m_path;
    int m_width;
    int m_height;

public:
    Sprite(SDL_Surface *surface, const std::string& path, int width, int height);
    Sprite(SDL_Surface *surface, const std::string& path);
    Sprite(Sprite&& other) noexcept;
    Sprite(const Sprite &sprite);
    static Sprite* fromBMP(std::string& path);
    ~Sprite();

    // Move Operator
    Sprite& operator=(Sprite&& other) noexcept;


    //idc
    inline static SDL_Renderer *renderer;

    SDL_Texture* getTexture() const;
    const std::string& getPath();

    int getWidth() const;
    int getHeight() const;

    void setWidth(int width);
    void setHeight(int height);
    std::string toString() const;

};



#endif //SPRITE_H
