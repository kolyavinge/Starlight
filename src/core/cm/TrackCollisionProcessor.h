#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/cm/TrackCollisionDetector.h>

class TrackCollisionProcessor : public Object
{
    TrackCollisionDetector _trackCollisionDetector;

public:
    bool ProcessTrackCollisions(Ship& ship, Track& track);
};
