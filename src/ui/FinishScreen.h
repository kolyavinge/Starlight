#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>
#include <ai/EnemyAI.h>

class FinishScreen : public Screen
{
    int _iterationCount;
    EnemyAI& _enemyAI;

public:
    const int IterationsCount;

    FinishScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        EnemyAI& enemyAI,
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
