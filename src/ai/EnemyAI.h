#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <ai/ObstacleAvoidanceLogic.h>
#include <ai/SteeringLogic.h>

class EnemyAI : public Object
{
    ObstacleAvoidanceLogic _obstacleAvoidanceLogic;
    SteeringLogic _steeringLogic;

public:
    void ApplyFor(IArray<Ship>& enemies, IArray<Ship*>& allShips, Track& track);
    void ApplyFor(Ship& enemy, IArray<Ship*>& allShips, Track& track);
};
