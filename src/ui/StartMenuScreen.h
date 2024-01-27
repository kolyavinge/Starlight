#pragma once

#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class StartMenuScreen : public Screen
{
public:
    StartMenuScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices);

    void ProcessInput() override;
};
