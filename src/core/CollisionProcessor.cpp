#include <lib/Exceptions.h>
#include <calc/Vector3.h>
#include <calc/VectorCalculator.h>
#include <core/CollisionProcessor.h>

void CollisionProcessor::ProcessCollisions(Ship& ship, Track& track)
{
    if (!_trackCollisionDetector.DetectCollisions(ship, track)) return;
    TrackCollisionResult& collisionResult = _trackCollisionDetector.Result;

    Vector3 frontDirection(ship.CentralLine.Front);
    frontDirection.Sub(ship.PrevCentralLine.Front);
    if (frontDirection.IsZero()) throw AssertException();

    ship.CentralLine = ship.PrevCentralLine;

    Vector3 normal;
    VectorCalculator::GetNormalVector2d(
        collisionResult.FromTrackPoint.X, collisionResult.FromTrackPoint.Y,
        collisionResult.ToTrackPoint.X, collisionResult.ToTrackPoint.Y,
        &normal.X, &normal.Y);

    Vector3 newDeviation = frontDirection;
    newDeviation.SetLength(ship.VelocityValue);
    newDeviation.Reflect(normal);

    Vector3 opposite(collisionResult.OppositeTrackPoint);
    opposite.Sub(collisionResult.FromTrackPoint);
    opposite.SetLength(0.25f);
    newDeviation.Add(opposite);

    ship.Deviation.Add(newDeviation);
}
