#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/RoadTrack1.h>
#include <core/GameUpdater.h>
#include <core/GameCamera.h>
#include <core/Controller.h>
#include <core/Game.h>

class GameManager : public Object
{
    Ship _player;
    RoadTrack1 _track;
    GameUpdater _gameUpdater;
    GameCamera _camera;
    Controller _playerController;

public:
    static GameManager Instance;

    Game Game;

private:
    GameManager();
};
