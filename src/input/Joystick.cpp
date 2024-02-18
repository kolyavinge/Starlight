#include <input/Joystick.h>

Joystick::Joystick()
{
    _isButton1Pressed = false;
    _isButton2Pressed = false;
    _isButton3Pressed = false;
    _isButton4Pressed = false;
    _isLeftPressed = false;
    _isRightPressed = false;
    _isUpPressed = false;
    _isDownPressed = false;
}

void Joystick::PressButton1(bool isPressed)
{
    _isButton1Pressed = isPressed;
}

void Joystick::PressButton2(bool isPressed)
{
    _isButton2Pressed = isPressed;
}

void Joystick::PressButton3(bool isPressed)
{
    _isButton3Pressed = isPressed;
}

void Joystick::PressButton4(bool isPressed)
{
    _isButton4Pressed = isPressed;
}

bool Joystick::IsButton1Pressed()
{
    return _isButton1Pressed;
}

bool Joystick::IsButton2Pressed()
{
    return _isButton2Pressed;
}

bool Joystick::IsButton3Pressed()
{
    return _isButton3Pressed;
}

bool Joystick::IsButton4Pressed()
{
    return _isButton4Pressed;
}

void Joystick::PressLeft(bool isPressed)
{
    _isLeftPressed = isPressed;
}

void Joystick::PressRight(bool isPressed)
{
    _isRightPressed = isPressed;
}

void Joystick::PressUp(bool isPressed)
{
    _isUpPressed = isPressed;
}

void Joystick::PressDown(bool isPressed)
{
    _isDownPressed = isPressed;
}

bool Joystick::IsLeftPressed()
{
    return _isLeftPressed;
}

bool Joystick::IsRightPressed()
{
    return _isRightPressed;
}

bool Joystick::IsUpPressed()
{
    return _isUpPressed;
}

bool Joystick::IsDownPressed()
{
    return _isDownPressed;
}
