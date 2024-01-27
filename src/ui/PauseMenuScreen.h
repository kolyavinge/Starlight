#pragma once

#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class PauseMenuScreen : public Screen
{
public:
    PauseMenuScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices);

    void ProcessInput() override;
};
