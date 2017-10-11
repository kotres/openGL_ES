#include "SDLinputHandler.hpp"

SDLinputHandler::SDLinputHandler()
:up(false),down(false),left(false),right(false),
pause(false),quit(false),action(false),x(0),y(0)
{}

void SDLinputHandler::updateIputs()
{
    SDL_Event events;
    while( SDL_PollEvent( &events ) != 0 ){
        switch (events.type) {
        case SDL_QUIT:
            quit=true;
            break;
        case SDL_MOUSEBUTTONDOWN:
            action=true;
            break;
        case SDL_MOUSEBUTTONUP:
            action=false;
            break;
        case SDL_KEYDOWN:
            switch(events.key.keysym.sym){
            case SDLK_z:
                up=true;
                break;
            case SDLK_s:
                down=true;
                break;
            case SDLK_q:
                left=true;
                break;
            case SDLK_d:
                right=true;
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch(events.key.keysym.sym){
            case SDLK_z:
                up=false;
                break;
            case SDLK_s:
                down=false;
                break;
            case SDLK_q:
                left=false;
                break;
            case SDLK_d:
                right=false;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    SDL_GetMouseState(&x, &y);
}

bool SDLinputHandler::getAction()
{
    return action;
}

bool SDLinputHandler::getPause()
{
    return pause;
}

bool SDLinputHandler::getQuit()
{
    return quit;
}

bool SDLinputHandler::getUp()
{
    return up;
}

bool SDLinputHandler::getDown()
{
    return down;
}

bool SDLinputHandler::getLeft()
{
    return left;
}

bool SDLinputHandler::getRight()
{
    return right;
}

int SDLinputHandler::getX()
{
    return x;
}

int SDLinputHandler::getY()
{
    return y;
}

