#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class RacePreparationScreen : public Screen
{
    const int _iterationsCount;
    int _currentIteration;
    float _radiansStep;
    int _countdownNumber;
    int _countdownSwitchIteration;
    int _countdownIteration;

public:
    RacePreparationScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        Race& race);

    Race& Race;

    void Activate(Screen* prevScreen) override;
    void Update() override;

    int GetCountdownNumber();
    int GetCountdownIteration();
    int GetCountdownSwitchIteration();
};

class RacePreparationScreenResolvingFactory : public ResolvingFactory<RacePreparationScreen>
{
public:
    RacePreparationScreen* Make(Resolver& resolver) override;
};
