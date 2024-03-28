#pragma once

#include <lib/di/ResolvingFactory.h>
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

class PauseMenuScreenResolvingFactory : public ResolvingFactory<PauseMenuScreen>
{
public:
    PauseMenuScreen* Make(Resolver& resolver) override;
};
