#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class FinishScreen : public Screen
{
    int _iterationCount;

public:
    const int IterationsCount;

    FinishScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        Race& race);

    Race& Race;

    void Activate(Screen* prevScreen) override;
    void Update() override;
    int GetCurrentIteration();
};

class FinishScreenResolvingFactory : public ResolvingFactory<FinishScreen>
{
public:
    FinishScreen* Make(Resolver& resolver) override;
};
