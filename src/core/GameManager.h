#pragma once

#include "lib/Object.h"
#include "model/Ship.h"
#include "core/TurnAngleCalculator.h"
#include "core/VelocityCalculator.h"
#include "core/MoveLogic.h"
#include "core/CollisionDetector.h"
#include "core/PositionCorrector.h"
#include "core/GameUpdater.h"
#include "core/Controller.h"
#include "core/Game.h"

class GameManager : public Object
{
    Ship _player;
    TurnAngleCalculator _turnAngleCalculator;
    VelocityCalculator _velocityCalculator;
    MoveLogic _moveLogic;
    CollisionDetector _collisionDetector;
    GameUpdater _gameUpdater;
    Controller _playerController;
    PositionCorrector _positionCorrector;

public:
    static GameManager Instance;

    Game Game;

private:
    GameManager();
};
