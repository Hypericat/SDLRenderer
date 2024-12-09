//
// Created by Hypericats on 11/18/2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <memory>
#include <SDL.h>
#include <unordered_map>

#include "Camera.h"
#include "GameObject.h"
#include "Sprite.h"


class Renderer {
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Surface *m_windowSurface;
    Camera* m_camera;
    void renderTex(SDL_Texture *texture, const SDL_Rect *dimensions) const;
    void renderSprite(const Sprite *sprite, int x, int y) const;
    void renderSprite(const Sprite *sprite, int x, int y, int width, int height) const;
    void renderCenteredSprite(const Sprite *sprite, int x, int y) const;


public:
    bool init();
    void update();
    void render() const;
    void initRender() const;
    void testRender() const;
    void destroy() const;

    void renderGameObject(const GameObject *gameObject) const;

    GameObject *testGameObject;

    static SDL_Rect rectCentered(int x, int y, int width, int height);
    static SDL_Rect rectCoord(int x1, int y1, int x2, int y2);
    static SDL_Rect rect(int x1, int y1, int x2, int y2);

    Renderer(SDL_Window *window, SDL_Renderer* renderer, Camera* camera): m_window(window), m_renderer(renderer), m_windowSurface(SDL_GetWindowSurface(m_window)), m_camera(camera) {

    }
};



#endif //RENDERER_H
