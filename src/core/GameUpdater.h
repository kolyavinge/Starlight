#pragma once

#include "lib/Object.h"
#include "model/Ship.h"
#include "core/TurnAngleCalculator.h"
#include "core/VelocityCalculator.h"
#include "core/MoveLogic.h"
#include "core/CollisionDetector.h"
#include "core/PositionCorrector.h"
#include "core/BorderUpdater.h"
#include "core/GameCamera.h"

class GameUpdater : public Object
{
    TurnAngleCalculator _turnAngleCalculator;
    VelocityCalculator _velocityCalculator;
    MoveLogic _moveLogic;
    CollisionDetector _collisionDetector;
    PositionCorrector _positionCorrector;
    BorderUpdater _borderUpdater;
    Ship& _player;
    GameCamera& _camera;

public:
    GameUpdater(
        Ship& player,
        GameCamera& camera);

    void Update();
};
