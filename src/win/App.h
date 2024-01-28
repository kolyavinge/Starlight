#pragma once

#include <lib/Exceptions.h>
#include <core/Game.h>
#include <render/ui/RenderManager.h>

class AppInitException : public Exception { };

class App
{
    inline static Game _game;
    inline static RenderManager _renderManager;

public:
    static void Start(int argc, char** argv);
    static void Shutdown();

private:
    static void SetIcon();
    static void Display();
    static void Reshape(int width, int height);
    static void Keypress(unsigned char key, int x, int y);
    static void Keyup(unsigned char key, int x, int y);
    static void JoystickKeypress(unsigned int buttons, int xaxis, int yaxis, int zaxis);
    static void TimerCallback(int state);
};
