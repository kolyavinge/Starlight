#include <lib/Assert.h>
#include <calc/Vector3.h>
#include <calc/Physics.h>
#include <core/CollisionProcessor.h>

CollisionProcessor::CollisionProcessor()
{
    _hasCollisions = false;
}

void CollisionProcessor::ProcessCollisions(Ship& ship, List<Ship*>& allShips, Track& track)
{
    _hasCollisions =
        ProcessTrackCollisions(ship, track) ||
        ProcessShipsCollisions(ship, allShips);
}

bool CollisionProcessor::HasCollisions()
{
    return _hasCollisions;
}

bool CollisionProcessor::ProcessTrackCollisions(Ship& ship, Track& track)
{
    if (!_trackCollisionDetector.DetectCollisions(ship, track)) return false;
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

    return true;
}

bool CollisionProcessor::ProcessShipsCollisions(Ship& ship, List<Ship*>& allShips)
{
    if (!_shipCollisionDetector.DetectCollisions(ship, allShips)) return false;

    ship.CentralLine = ship.PrevCentralLine;

    Vector3 frontDirection(ship.CentralLine.Front);
    frontDirection.Sub(ship.CentralLine.Rear);

    NewVelocityResult result = Physics::GetNewVelocityAfterCollision(
        1.0f, frontDirection, 1.0f, frontDirection);

    result.Velocity1.SetLength(1.0f);
    ship.Deviation.Add(result.Velocity1);

    ship.ThrottleTime /= 1.5f;

    return true;
}
