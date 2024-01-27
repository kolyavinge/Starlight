#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/TrackManager.h>
#include <core/GameUpdater.h>
#include <core/ShipController.h>
#include <core/Camera.h>
#include <core/IPauseSwitcher.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/ScreenManager.h>

class Game : public Object, public IPauseSwitcher
{
    TrackManager _trackManager;
    GameUpdater _gameUpdater;
    EmptyGameUpdater _emptyGameUpdater;
    IGameUpdater* _currentGameUpdater;
    ScreenManager _screenManager;
    bool _isPaused;

public:
    Ship Player;
    Track& Track;
    ShipController PlayerController;
    Camera Camera;
    InputDevices InputDevices;

    Game();

    void Update();
    void SwitchPause() override;
    Screen& GetCurrentScreen();
};
