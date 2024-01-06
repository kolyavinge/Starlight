#pragma once

#include <lib/Array.h>
#include <calc/Vector3.h>
#include <render/RenderLogic.h>

class App
{
    static RenderLogic& _renderLogic;
    static Vector3 _upAxis;
    static Array<bool, 256> _keyPressed;
    static int _joyXAxis;
    static unsigned int _joyButtonsPressed;

public:
    static void Start(int argc, char** argv);

private:
    static void SetIcon();
    static void Display();
    static void Reshape(int width, int height);
    static void Keypress(unsigned char key, int x, int y);
    static void Keyup(unsigned char key, int x, int y);
    static void JoystickKeypress(unsigned int buttons, int xaxis, int yaxis, int zaxis);
    static void ApplyButtonsToController();
    static void TimerCallback(int state);
};
