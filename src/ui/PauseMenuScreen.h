#pragma once

#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>
#include <ui/LinearMenuItemSelector.h>

enum class PauseMenuItem
{
    Resume,
    StartMenu
};

class PauseMenuScreen : public Screen
{
    LinearMenuItemSelector<PauseMenuItem> _selector;

public:
    Race& Race;

    PauseMenuScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        ::Race& race);

    PauseMenuItem GetSelectedItem();
    void Activate(Screen* prevScreen) override;
    void ProcessInput() override;
};
