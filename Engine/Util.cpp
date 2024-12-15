//
// Created by Hypericats on 12/11/2024.
//

#include "Util.h"
#include <math.h>

SDL_Texture* Util::copyTexture(SDL_Texture* texture, SDL_Renderer* renderer) {
    Uint32 format;
    int width;
    int height;
    SDL_BlendMode blendMode;

    SDL_QueryTexture(texture, &format, NULL, &width, &height);
    SDL_GetTextureBlendMode(texture, &blendMode);
    SDL_Texture *renderTarget = SDL_GetRenderTarget(renderer);

    // Create a new texture with the same properties
    SDL_Texture *copy = SDL_CreateTexture(renderer, format, SDL_TEXTUREACCESS_TARGET, width, height);
    SDL_SetTextureBlendMode(copy, SDL_BLENDMODE_NONE);
    SDL_SetRenderTarget(renderer, copy);

    // Render the full original texture onto the new one
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetTextureBlendMode(copy, blendMode);
    SDL_SetRenderTarget(renderer, renderTarget);
    return copy;
}

float Util::roundAwayFromZero(const float f) {
    return f < 0 ? std::floor(f) : std::ceil(f);
}