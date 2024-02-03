#pragma once

#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>
#include <ui/MenuItemSelector.h>

enum class PauseMenuItem
{
    Resume,
    StartMenu
};

class PauseMenuScreen : public Screen
{
    MenuItemSelector<PauseMenuItem, 2> _selector;

public:
    Race& Race;

    PauseMenuScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        ::Race& race);

    PauseMenuItem GetSelectedItem();
    void Activate() override;
    void ProcessInput() override;
};
