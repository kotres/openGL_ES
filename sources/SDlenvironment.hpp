#pragma once
#ifndef SDL_ENVIRONMENT_HPP
#define SDL_ENVIRONMENT_HPP
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <iostream>


/* class SDlenvironment:
 * Handles the application's windowing and external inputs
 */

class SDlenvironment{
private:
    SDL_Window* SDLwindow;
    SDL_GLContext GLcontext;
    bool valid;
    bool initSDL();
    bool initGL();
    bool initGLEW();
public:
    SDlenvironment();
    bool isValid();
    ~SDlenvironment();
    void updateSurface();
    SDlenvironment(const SDlenvironment& obj);
    SDlenvironment& operator=(const SDlenvironment& obj);
};
#endif
