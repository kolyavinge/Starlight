#pragma once

#include "lib/Object.h"
#include "model/Ship.h"
#include "core/TurnAngleCalculator.h"
#include "core/VelocityCalculator.h"
#include "core/MoveLogic.h"
#include "core/CollisionDetector.h"
#include "core/PositionCorrector.h"

class GameUpdater : public Object
{
    Ship& _player;
    TurnAngleCalculator& _turnAngleCalculator;
    VelocityCalculator& _velocityCalculator;
    MoveLogic& _moveLogic;
    CollisionDetector& _collisionDetector;
    PositionCorrector& _positionCorrector;

public:
    GameUpdater(
        Ship& player,
        TurnAngleCalculator& turnAngleCalculator,
        VelocityCalculator& velocityCalculator,
        MoveLogic& moveLogic,
        CollisionDetector& collisionDetector,
        PositionCorrector& positionCorrector);

    void Update();
};
