#include <lib/Exceptions.h>
#include <lib/Math.h>
#include <calc/Geometry.h>
#include <model/ShipMeasure.h>
#include <ai/ObstacleAvoidanceLogic.h>

Vector3 ObstacleAvoidanceLogic::GetMovingDirection(Ship& ship, Track& track)
{
    Vector3 result;

    Vector3 straight(ship.CentralLine.Front);
    straight.Sub(ship.CentralLine.Rear);
    straight.Mul(10.0f * ShipMeasure::YLength);
    straight.Add(ship.CentralLine.Front);
    AddResultIfCorrect(ship, track, straight, result);

    Vector3 direction;
    const int steps = 5;
    const float radiansStep = Math::PiHalf / (float)steps;
    for (int i = 1; i <= steps; i++)
    {
        direction.Set(straight);
        direction = Geometry::RotatePoint3d(direction, ship.CentralLine.NormalFront, ship.CentralLine.Front, (float)i * radiansStep);
        AddResultIfCorrect(ship, track, direction, result);

        direction.Set(straight);
        direction = Geometry::RotatePoint3d(direction, ship.CentralLine.NormalFront, ship.CentralLine.Front, (float)-i * radiansStep);
        AddResultIfCorrect(ship, track, direction, result);
    }

    if (result.IsZero()) throw ObjectStateException();
    result.Normalize();

    return result;
}

void ObstacleAvoidanceLogic::AddResultIfCorrect(Ship& ship, Track& track, Vector3 direction, Vector3& result)
{
    if (!_trackCollisionDetector.DetectCollisions(track, ship.CentralLine.TrackPointIndexFront, direction))
    {
        direction.Sub(ship.CentralLine.Front);
        result.Add(direction);
    }
}
