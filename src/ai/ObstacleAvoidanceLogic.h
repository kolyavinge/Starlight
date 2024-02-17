#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/TrackCollisionDetector.h>

class ObstacleAvoidanceLogic : public Object
{
    TrackCollisionDetector _trackCollisionDetector;

public:
    Vector3 GetMovingDirection(Ship& ship, Track& track);

private:
    void AddResultIfCorrect(Ship& ship, Track& track, Vector3 direction, Vector3& result);
};
