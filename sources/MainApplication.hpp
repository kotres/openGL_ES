#pragma once
#ifndef MAIN_APPLICATION_HPP
#define MAIN_APPLICATION_HPP

#include "SDlenvironment.hpp"
#include "SDLinputHandler.hpp"

class MainApplication
{
private:
    SDlenvironment sdlEnvironment;
    SDLinputHandler inputs;
public:
    MainApplication();
    void execute();
};

#endif
