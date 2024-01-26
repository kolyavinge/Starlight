#pragma once

#include <lib/Exceptions.h>
#include <lib/Array.h>
#include <calc/Vector3.h>
#include <core/GameManager.h>
#include <render/RenderLogic.h>

class AppInitException : public Exception { };

class App
{
    inline static const double _screenAspect = 16.0 / 9.0;
    inline static Vector3 _upAxis = Vector3(0.0f, 0.0f, 1.0f);

    static GameManager _gameManager;
    static RenderLogic& _renderLogic;
    static Array<bool, 256> _keyPressed;
    static int _joyXAxis;
    static unsigned int _joyButtonsPressed;

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
    static void ApplyButtonsToController();
    static void TimerCallback(int state);
};
