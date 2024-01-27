#pragma once

#include <input/InputDevices.h>
#include <lib/Object.h>
#include <ui/IScreenNavigator.h>

enum ScreenKind
{
    StartMenuKind = 0,
    TrackSelectorKind = 1,
    PauseMenuKind = 2,
    GameKind = 3
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

    virtual void ProcessInput() = 0;
};
