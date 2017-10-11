#pragma once
#ifndef SDL_INPUT_HANDLER
#define SDL_INPUT_HANDLER
#include <SDL2/SDL.h>


//handles all the key and mouse events for the application

class SDLinputHandler{
private:
    bool up,down,left,right,pause,quit,action;
    int x,y;
public:
    SDLinputHandler();
    void updateIputs();
    bool getUp();
    bool getDown();
    bool getLeft();
    bool getRight();
    bool getPause();
    bool getQuit();
    bool getAction();
    int getX();
    int getY();
};

#endif
