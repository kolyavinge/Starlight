#pragma once

#include <lib/di/ResolvingFactory.h>
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
    LinearMenuItemSelector<StartMenuItem> _selector;

public:
    StartMenuScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices);

    StartMenuItem GetSelectedItem();
    void Activate(Screen* prevScreen) override;
    void ProcessInput() override;
};

class StartMenuScreenResolvingFactory : public ResolvingFactory<StartMenuScreen>
{
public:
    StartMenuScreen* Make(Resolver& resolver) override;
};
