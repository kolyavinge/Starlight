#pragma once

#include <lib/Exceptions.h>
#include <calc/Vector3.h>
#include <core/Game.h>
#include <render/ui/ScreenRenderer.h>

class AppInitException : public Exception { };

class App
{
    inline static const double _screenAspect = 16.0 / 9.0;
    inline static Vector3 _upAxis = Vector3(0.0f, 0.0f, 1.0f);
    inline static Game _game;

    static ScreenRenderer& _screenRenderer;

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
