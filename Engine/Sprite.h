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
    Sprite(SDL_Surface *surface, const SDL_PixelFormat *fmt, std::string path, int width, int height, float scale);
    Sprite(SDL_Surface *surface, const SDL_PixelFormat *fmt, std::string path);

    SDL_Texture *m_texture;
    std::string m_path;
    int width;
    int height;
    float scale;

public:
    Sprite(Sprite&& other) noexcept;
    static Sprite* fromBMP(std::string& path, const SDL_PixelFormat *fmt);
    ~Sprite();

    // Move Operator
    Sprite& operator=(Sprite&& other) noexcept;


    //idc
    inline static SDL_Renderer *renderer;

    SDL_Texture* getTexture() const;
    const std::string& getPath();

    int getWidth() const;
    int getDefaultWidth() const;
    int getHeight() const;
    int getDefaultHeight() const;

    void setWidth(int width);
    void setHeight(int height);
    void setScale(float scale);
    std::string toString() const;

};



#endif //SPRITE_H
