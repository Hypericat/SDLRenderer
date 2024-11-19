//
// Created by Hypericats on 11/18/2024.
//

#include "Renderer.h"

#include <cstdio>
#include <SDL_opengl.h>
#include <GL\GLU.h>

bool Renderer::init() {
    //enable vsync
    SDL_GL_SetSwapInterval(1);
    GLenum error = GL_NO_ERROR;

    //Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Check for error
    error = glGetError();
    if(error != GL_NO_ERROR) {
        printf( "Error initializing OpenGL! %p\n", gluErrorString(error));
        return false;
    }

    //Initialize Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Check for error
    error = glGetError();
    if(error != GL_NO_ERROR) {
        printf( "Error initializing OpenGL! %p\n", gluErrorString(error));
        return false;
    }

    //Initialize clear color
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    error = glGetError();
    if(error != GL_NO_ERROR) {
        printf( "Error initializing OpenGL! %p\n", gluErrorString(error));
        return false;
    }

    return true;
}

void Renderer::update() {
    //nothing for now
}

void Renderer::render() {
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    //Render quad
    if(gRenderQuad)
    {
        glBegin( GL_QUADS );
        glVertex2f( -0.5f, -0.5f );
        glVertex2f( 0.5f, -0.5f );
        glVertex2f( 0.5f, 0.5f );
        glVertex2f( -0.5f, 0.5f );
        glEnd();
    }
}

void Renderer::close() {

}
