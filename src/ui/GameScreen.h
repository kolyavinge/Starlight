#pragma once

#include <core/ShipController.h>
#include <core/IPauseSwitcher.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class GameScreen : public Screen
{
    ShipController& _playerController;
    IPauseSwitcher& _pauseSwitcher;

public:
    GameScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        ShipController& playerController,
        IPauseSwitcher& pauseSwitcher);

    void Activate() override;
    void ProcessInput() override;
};
