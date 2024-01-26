#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <core/TrackManager.h>
#include <core/GameUpdater.h>
#include <core/Camera.h>
#include <core/ShipController.h>
#include <core/Game.h>
#include <input/InputDevices.h>

class GameManager : public Object
{
    Ship _player;
    TrackManager _trackManager;
    GameUpdater _gameUpdater;
    Camera _camera;
    ShipController _playerController;

public:
    Game Game;
    InputDevices InputDevices;

    GameManager();

    void UpdateGame();
};
