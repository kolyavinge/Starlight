#pragma once

#include "render/DebugRenderLogic.h"

class App
{
public:
    static void Start(int argc, char** argv);

private:
    static DebugRenderLogic _renderLogic;

    static void Display();
    static void Reshape(int width, int height);
    static void Keypress(unsigned char key, int x, int y);
    static void Keyup(unsigned char key, int x, int y);
    static void TimerCallback(int state);
};
