#pragma once

#include <input/InputDevices.h>
#include <lib/Object.h>
#include <ui/IScreenNavigator.h>

enum class ScreenKind
{
    StartMenu = 0,
    TrackSelector,
    RacePreparation,
    Race,
    PauseMenu,
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
    virtual void Update();
    virtual void ProcessInput() = 0;
};
