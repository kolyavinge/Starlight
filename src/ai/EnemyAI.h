#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <ai/ObstacleAvoidanceLogic.h>
#include <ai/SteeringLogic.h>

class EnemyAI : public Object
{
    ObstacleAvoidanceLogic _obstacleAvoidanceLogic;
    SteeringLogic _steeringLogic;

public:
    void ApplyFor(List<Ship>& enemies, List<Ship*>& allShips, Track& track);
    void ApplyFor(Ship& enemy, List<Ship*>& allShips, Track& track);
};
