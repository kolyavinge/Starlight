#pragma once

#include <lib/List.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/RaceState.h>
#include <core/TurnAngleCalculator.h>
#include <core/VelocityCalculator.h>
#include <core/MoveLogic.h>
#include <core/CollisionProcessor.h>
#include <core/PositionCorrector.h>
#include <core/BorderUpdater.h>
#include <core/PositionUpdater.h>
#include <core/Laps.h>
#include <ai/EnemyAI.h>

class RaceUpdater : public Object
{
    TurnAngleCalculator _turnAngleCalculator;
    VelocityCalculator _velocityCalculator;
    MoveLogic _moveLogic;
    CollisionProcessor _collisionProcessor;
    PositionCorrector _positionCorrector;
    BorderUpdater _borderUpdater;
    PositionUpdater _positionUpdater;
    EnemyAI& _enemyAI;

public:
    RaceUpdater(EnemyAI& enemyAI);

    void Update(
        RaceState& state,
        Ship& player,
        List<Ship>& enemies,
        Track& track,
        Laps& laps);

private:
    void Update(Ship& ship, Track& track);
    void SaveCurrentShipsPositions(Ship& ship);
};
