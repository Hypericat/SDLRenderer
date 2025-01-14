//
// Created by Hypericats on 11/25/2024.
//

#ifndef SPRITE_H
#define SPRITE_H
#include <memory>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL_image.h>
#include <string>


class Sprite {
private:
    SDL_Texture *m_texture;
    std::string m_path;
    int m_width;
    int m_height;
    SDL_RendererFlip m_flip = SDL_FLIP_NONE;

public:
    Sprite(SDL_Surface *surface, const std::string& path, int width, int height);
    Sprite(SDL_Surface *surface, const std::string& path);
    Sprite(SDL_Texture *texture, const std::string& path);
    Sprite(SDL_Texture *texture, const std::string& path, int width, int height);
    Sprite(Sprite&& other) noexcept;
    Sprite(const Sprite &sprite);
    static Sprite* fromBMP(const std::string& path);
    static Sprite* fromPNG(const std::string& path);
    static Sprite* fromFullPNG(const std::string& path);
    static Sprite* fromPNG(const std::string& path, int width, int height);
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

    SDL_RendererFlip getFlip() const;
    Sprite* setRenderFlip(SDL_RendererFlip flip);


};



#endif //SPRITE_H
