#pragma once

#include "lib/Object.h"
#include "model/Ship.h"
#include "core/VelocityCalculator.h"
#include "core/MoveLogic.h"
#include "core/CollisionDetector.h"

class GameUpdater : public Object
{
    Ship& _player;
    VelocityCalculator& _velocityCalculator;
    MoveLogic& _moveLogic;
    CollisionDetector& _collisionDetector;

public:
    GameUpdater(
        Ship& player,
        VelocityCalculator& velocityCalculator,
        MoveLogic& moveLogic,
        CollisionDetector& collisionDetector);

    void Update();
};
