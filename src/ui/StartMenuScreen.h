#pragma once

#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>
#include <ui/LinearMenuItemSelector.h>

enum class StartMenuItem
{
    StartGame,
    Exit
};

class StartMenuScreen : public Screen
{
    LinearMenuItemSelector<StartMenuItem, 2> _selector;

public:
    StartMenuScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices);

    StartMenuItem GetSelectedItem();
    void Activate(Screen* prevScreen) override;
    void ProcessInput() override;
};
