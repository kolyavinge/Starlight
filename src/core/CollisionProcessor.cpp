#include "calc/Vector3d.h"
#include "core/TrackCollisionDetector.h"
#include "core/CollisionProcessor.h"

void CollisionProcessor::ProcessCollisions(Ship& ship, Track& track)
{
    TrackCollisionResult collisionResult;
    if (!_trackCollisionDetector.DetectCollisions(ship, track, collisionResult)) return;

    Vector3d frontDirection(ship.CentralLine.Front);
    frontDirection.Sub(ship.PrevCentralLine.Front);

    ship.CentralLine = ship.PrevCentralLine;
    ship.CentralLine.Front.Sub(frontDirection);
    ship.CentralLine.Rear.Sub(frontDirection);

    Vector3d normal;
    _vectorCalculator.GetNormalVector2d(
        collisionResult.From.X, collisionResult.From.Y,
        collisionResult.To.X, collisionResult.To.Y,
        &normal.X, &normal.Y);

    ship.Deviation = frontDirection;
    ship.Deviation.SetLength(ship.VelocityValue);
    ship.Deviation.Reflect(normal);
}
