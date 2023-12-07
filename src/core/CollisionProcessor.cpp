#include "core/CollisionProcessor.h"

void CollisionProcessor::ProcessCollisions(Ship& ship, Track& track)
{
    if (_trackCollisionDetector.DetectCollisions(ship, track))
    {
        ship.CentralLine = ship.PrevCentralLine;
    }
}
