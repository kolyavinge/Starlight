#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/TrackCollisionDetector.h>

class CollisionProcessor : public Object
{
public:
    void ProcessCollisions(Ship& ship, Track& track);

private:
    TrackCollisionDetector _trackCollisionDetector;
};
