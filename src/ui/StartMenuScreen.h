#pragma once

#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>
#include <ui/MenuItemSelector.h>

enum class StartMenuItem
{
    StartGame,
    Exit
};

class StartMenuScreen : public Screen
{
    MenuItemSelector<StartMenuItem, 2> _selector;

public:
    StartMenuScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices);

    StartMenuItem GetSelectedItem();
    void Activate() override;
    void ProcessInput() override;
};
