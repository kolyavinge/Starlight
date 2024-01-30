#pragma once

#include <lib/Object.h>
#include <core/ShipController.h>
#include <core/IGameStarter.h>
#include <core/IPauseSwitcher.h>
#include <input/InputDevices.h>
#include <ui/StartMenuScreen.h>
#include <ui/TrackSelectorScreen.h>
#include <ui/PauseMenuScreen.h>
#include <ui/GameScreen.h>
#include <ui/IScreenNavigator.h>

class ScreenManager : public Object, public IScreenNavigator
{
    StartMenuScreen _startMenuScreen;
    TrackSelectorScreen _trackSelectorScreen;
    PauseMenuScreen _pauseMenuScreen;
    GameScreen _gameScreen;
    Screen* _currentScreen;

public:
    ScreenManager(
        InputDevices& inputDevices,
        ShipController& playerController,
        IGameStarter& gameStarter,
        IPauseSwitcher& pauseSwitcher);

    Screen& GetCurrentScreen();

    void NavigateToStartMenu() override;
    void NavigateToTrackSelector() override;
    void NavigateToPauseMenu() override;
    void NavigateToGame() override;
};
