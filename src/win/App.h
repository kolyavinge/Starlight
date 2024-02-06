#pragma once

#include <lib/Exceptions.h>
#include <game/Game.h>

class AppInitException : public Exception { };

class App
{
    inline static Game _game;

public:
    static void Start(int argc, char** argv);
    static void Shutdown();

private:
    static void SetIcon();
    static void Display();
    static void Reshape(int width, int height);
    static void JoystickKeypress(unsigned int buttons, int xaxis, int yaxis, int zaxis);
    static void TimerCallback(int state);
};
