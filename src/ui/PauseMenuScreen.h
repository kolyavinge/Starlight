#pragma once

#include <core/IPauseSwitcher.h>
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
    IPauseSwitcher& _pauseSwitcher;
    MenuItemSelector<PauseMenuItem, 2> _selector;

public:
    PauseMenuScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        IPauseSwitcher& pauseSwitcher);

    PauseMenuItem GetSelectedItem();
    void Activate() override;
    void ProcessInput() override;
};
