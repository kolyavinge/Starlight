#pragma once

#include "lib/Object.h"
#include "model/Ship.h"
#include "model/Track.h"
#include "model/CircleTrack.h"
#include "core/TurnAngleCalculator.h"
#include "core/VelocityCalculator.h"
#include "core/MoveLogic.h"
#include "core/CollisionDetector.h"
#include "core/PositionCorrector.h"
#include "core/BorderUpdater.h"
#include "core/GameUpdater.h"
#include "core/GameCamera.h"
#include "core/Controller.h"
#include "core/Game.h"

class GameManager : public Object
{
    Ship _player;
    CircleTrack _track;
    TurnAngleCalculator _turnAngleCalculator;
    VelocityCalculator _velocityCalculator;
    MoveLogic _moveLogic;
    CollisionDetector _collisionDetector;
    GameUpdater _gameUpdater;
    PositionCorrector _positionCorrector;
    BorderUpdater _borderUpdater;
    GameCamera _camera;
    Controller _playerController;

public:
    static GameManager Instance;

    Game Game;

private:
    GameManager();
};
