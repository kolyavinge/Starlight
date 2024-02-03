#pragma once

#include <model/Ship.h>
#include <model/Track.h>
#include <core/TurnAngleCalculator.h>
#include <core/VelocityCalculator.h>
#include <core/MoveLogic.h>
#include <core/CollisionProcessor.h>
#include <core/PositionCorrector.h>
#include <core/BorderUpdater.h>
#include <core/PositionUpdater.h>
#include <core/LapCounter.h>
#include <core/Camera.h>

class GameUpdater : public Object
{
    TurnAngleCalculator _turnAngleCalculator;
    VelocityCalculator _velocityCalculator;
    MoveLogic _moveLogic;
    CollisionProcessor _collisionProcessor;
    PositionCorrector _positionCorrector;
    BorderUpdater _borderUpdater;
    PositionUpdater _positionUpdater;
    LapCounter _lapCounter;

public:
    void Update(
        Ship& player,
        Track& track,
        Camera& camera);

private:
    void SaveCurrentShipsPositions(Ship& player);
};
