#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Camera.h>
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
    Camera& _camera;
    Race& _race;

public:
    RacePreparationScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        Camera& camera,
        Race& race);

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
