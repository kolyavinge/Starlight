#include <lib/Assert.h>
#include <calc/Vector3.h>
#include <core/CollisionProcessor.h>

CollisionProcessor::CollisionProcessor()
{
    _hasCollisions = false;
}

void CollisionProcessor::ProcessCollisions(Ship& ship, Track& track)
{
    _hasCollisions = _trackCollisionDetector.DetectCollisions(ship, track);
    if (!_hasCollisions) return;
    TrackCollisionResult& collisionResult = _trackCollisionDetector.Result;

    Vector3 frontDirection(ship.CentralLine.Front);
    frontDirection.Sub(ship.PrevCentralLine.Front);
    Assert::False(frontDirection.IsZero());

    ship.CentralLine = ship.PrevCentralLine;

    Vector3 opposite(collisionResult.OppositeTrackPoint);
    opposite.Sub(collisionResult.FromTrackPoint);
    opposite.SetLength(0.5f);
    ship.Deviation.Add(opposite);

    ship.ThrottleTime /= 4.0f;
}

bool CollisionProcessor::HasCollisions()
{
    return _hasCollisions;
}
