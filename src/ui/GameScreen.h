#pragma once

#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class GameScreen : public Screen
{
public:
    GameScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        Race& race);

    Race& Race;

    void Activate() override;
    void Update() override;
    void ProcessInput() override;
};
