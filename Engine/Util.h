//
// Created by Hypericats on 12/11/2024.
//

#ifndef UTIL_H
#define UTIL_H
#include <SDL_render.h>


class Util {
public:
    static SDL_Texture* copyTexture(SDL_Texture* texture, SDL_Renderer* renderer);

};



#endif //UTIL_H
