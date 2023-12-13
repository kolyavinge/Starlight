#pragma once

#include <lib/Object.h>
#include <calc/VectorCalculator.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/TrackCollisionDetector.h>

class CollisionProcessor : public Object
{
    VectorCalculator _vectorCalculator;

public:
    void ProcessCollisions(Ship& ship, Track& track);

private:
    TrackCollisionDetector _trackCollisionDetector;
};
