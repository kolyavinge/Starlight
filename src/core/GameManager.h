#pragma once

#include "lib/Object.h"
#include "model/Ship.h"
#include "core/MoveLogic.h"
#include "core/VelocityCalculator.h"
#include "core/CollisionDetector.h"
#include "core/GameUpdater.h"
#include "core/Controller.h"
#include "core/Game.h"

class GameManager : public Object
{
    Ship _player;
    MoveLogic _moveLogic;
    VelocityCalculator _velocityCalculator;
    CollisionDetector _collisionDetector;
    GameUpdater _gameUpdater;
    Controller _playerController;

public:
    static GameManager Instance;

    Game Game;

private:
    GameManager();
};
