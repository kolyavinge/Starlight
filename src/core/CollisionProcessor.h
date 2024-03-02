#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/TrackCollisionDetector.h>
#include <core/ShipCollisionDetector.h>

class CollisionProcessor : public Object
{
    TrackCollisionDetector _trackCollisionDetector;
    ShipCollisionDetector _shipCollisionDetector;
    bool _hasCollisions;

public:
    CollisionProcessor();

    void ProcessCollisions(Ship& ship, IArray<Ship*>& allShips, Track& track);
    bool HasCollisions();

private:
    bool ProcessTrackCollisions(Ship& ship, Track& track);
    bool ProcessShipsCollisions(Ship& ship, IArray<Ship*>& allShips);
};
