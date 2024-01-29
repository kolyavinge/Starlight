#pragma once

#include <lib/Object.h>

class Joystick : public Object
{
    bool _isButton1Pressed;
    bool _isButton2Pressed;
    bool _isButton3Pressed;
    bool _isLeftPressed;
    bool _isRightPressed;
    bool _isUpPressed;
    bool _isDownPressed;

public:
    Joystick();

    void PressButton1(bool isPressed);
    void PressButton2(bool isPressed);
    void PressButton3(bool isPressed);
    bool IsButton1Pressed();
    bool IsButton2Pressed();
    bool IsButton3Pressed();
    void PressLeft(bool isPressed);
    void PressRight(bool isPressed);
    void PressUp(bool isPressed);
    void PressDown(bool isPressed);
    bool IsLeftPressed();
    bool IsRightPressed();
    bool IsUpPressed();
    bool IsDownPressed();
};
