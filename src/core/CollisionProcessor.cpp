#include <lib/Exceptions.h>
#include <calc/Vector3d.h>
#include <calc/VectorCalculator.h>
#include <core/TrackCollisionDetector.h>
#include <core/CollisionProcessor.h>

void CollisionProcessor::ProcessCollisions(Ship& ship, Track& track)
{
    TrackCollisionResult collisionResult;
    if (!_trackCollisionDetector.DetectCollisions(ship, track, collisionResult)) return;

    Vector3d frontDirection(ship.CentralLine.Front);
    frontDirection.Sub(ship.PrevCentralLine.Front);
    if (frontDirection.IsZero()) throw AssertException();

    ship.CentralLine = ship.PrevCentralLine;

    Vector3d normal;
    VectorCalculator::GetNormalVector2d(
        collisionResult.FromTrackPoint.X, collisionResult.FromTrackPoint.Y,
        collisionResult.ToTrackPoint.X, collisionResult.ToTrackPoint.Y,
        &normal.X, &normal.Y);

    ship.Deviation = frontDirection;
    ship.Deviation.SetLength(ship.VelocityValue);
    ship.Deviation.Reflect(normal);

    Vector3d opposite(collisionResult.OppositeTrackPoint);
    opposite.Sub(collisionResult.FromTrackPoint);
    opposite.SetLength(0.25f);
    ship.Deviation.Add(opposite);
}
