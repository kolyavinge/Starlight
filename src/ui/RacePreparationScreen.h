#pragma once

#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class RacePreparationScreen : public Screen
{
    int _iterationsCount;
    float _radiansStep;

public:
    RacePreparationScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        Race& race);

    Race& Race;

    void Activate() override;
    void Update() override;
    void ProcessInput() override;
};
