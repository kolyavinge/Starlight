#pragma once

#include <calc/Vector3d.h>
#include <render/DebugRenderLogic.h>

class App
{
    static Vector3d _upAxis;
    static DebugRenderLogic _renderLogic;
    static bool _keyPressed[256];
    static int _joyXAxis;
    static unsigned int _joyButtonsPressed;

public:
    static void Start(int argc, char** argv);

private:
    static void Display();
    static void Reshape(int width, int height);
    static void Keypress(unsigned char key, int x, int y);
    static void Keyup(unsigned char key, int x, int y);
    static void JoystickKeypress(unsigned int buttons, int xaxis, int yaxis, int zaxis);
    static void ApplyButtonsToController();
    static void TimerCallback(int state);
};
