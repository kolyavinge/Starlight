#pragma once

#include <input/InputDevices.h>
#include <lib/Object.h>
#include <ui/ScreenKind.h>
#include <ui/IScreenNavigator.h>

class Screen : public Object
{
protected:
    IScreenNavigator& _navigator;
    InputDevices& _inputDevices;

public:
    const ScreenKind Kind;

    Screen(
        ScreenKind kind,
        IScreenNavigator& navigator,
        InputDevices& inputDevices);

    virtual void Activate(Screen* prevScreen);
    virtual void Deactivate();
    virtual void Update();
    virtual void ProcessInput();
};
