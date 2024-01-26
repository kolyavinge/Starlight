#pragma once

#include <lib/Object.h>
#include <input/Keyboard.h>
#include <input/Joystick.h>

class InputDevices : public Object
{
public:
    Keyboard Keyboard;
    Joystick Joystick;
};
