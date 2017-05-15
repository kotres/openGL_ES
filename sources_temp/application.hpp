#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "fenetreSDL.hpp"
#include "input.hpp"
#include "scene.hpp"

class Application
{
    Fenetre fenetre;
    Input input;
    Scene scene;

public:
    Application() {}
    void applicationLoop();
};

#endif
