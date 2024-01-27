#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/TrackManager.h>
#include <core/GameUpdater.h>
#include <core/ShipController.h>
#include <core/Camera.h>
#include <input/InputDevices.h>

class Game : public Object
{
    TrackManager _trackManager;
    GameUpdater _gameUpdater;
    EmptyGameUpdater _emptyGameUpdater;
    IGameUpdater* _currentGameUpdater;
    bool _isPaused;

public:
    Ship Player;
    Track& Track;
    ShipController PlayerController;
    Camera Camera;
    InputDevices InputDevices;

    Game();

    void Update();
    void SwitchPause();
};
