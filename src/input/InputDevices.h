#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <input/Keyboard.h>
#include <input/Joystick.h>

class InputDevices : public Object
{
public:
    Keyboard Keyboard;
    Joystick Joystick;
};

class InputDevicesResolvingFactory : public ResolvingFactory<InputDevices>
{
public:
    InputDevices* Make(Resolver& resolver) override;
};
