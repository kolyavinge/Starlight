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
#include <core/Camera.h>
#include <core/Laps.h>

class RaceUpdater : public Object
{
    TurnAngleCalculator _turnAngleCalculator;
    VelocityCalculator _velocityCalculator;
    MoveLogic _moveLogic;
    CollisionProcessor _collisionProcessor;
    PositionCorrector _positionCorrector;
    BorderUpdater _borderUpdater;
    PositionUpdater _positionUpdater;

public:
    void Update(
        Ship& player,
        Track& track,
        Camera& camera,
        Laps& laps);

private:
    void SaveCurrentShipsPositions(Ship& player);
};
