#pragma once

#include <input/InputDevices.h>
#include <lib/Object.h>
#include <ui/IScreenNavigator.h>

enum class ScreenKind
{
    StartMenu = 0,
    TrackSelector = 1,
    PauseMenu = 2,
    Game = 3
};

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

    virtual void Activate() = 0;
    virtual void ProcessInput() = 0;
};
