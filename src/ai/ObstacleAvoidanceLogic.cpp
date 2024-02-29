#include <lib/Math.h>
#include <calc/Geometry.h>
#include <model/ShipMeasure.h>
#include <ai/ObstacleAvoidanceLogic.h>

Vector3 ObstacleAvoidanceLogic::GetMovingDirection(Ship& ship, List<Ship*>& allShips, Track& track)
{
    float directionLength = ship.AIData.MovingDirectionLength * ShipMeasure::YLength;
    Vector3 result = TryGetMovingDirection(ship, allShips, track, directionLength);
    while (result.IsZero())
    {
        if (directionLength < 1.0f) return Vector3(0.0f, 0.0f, 0.0f);
        result = TryGetMovingDirection(ship, allShips, track, directionLength);
        directionLength /= 2.0f;
    }
    result.Normalize();

    return result;
}

Vector3 ObstacleAvoidanceLogic::TryGetMovingDirection(Ship& ship, List<Ship*>& allShips, Track& track, float directionLength)
{
    Vector3 result;

    Vector3 straight(ship.CentralLine.Front);
    straight.Sub(ship.CentralLine.Rear);
    straight.Mul(directionLength);
    straight.Add(ship.CentralLine.Front);
    AddResultIfCorrect(ship, allShips, track, straight, result);

    Vector3 movingPoint;
    const int steps = ship.AIData.MovingPointsSteps;
    const float radiansStep = Math::PiHalf / (float)steps;
    for (int i = 1; i <= steps; i++)
    {
        movingPoint.Set(straight);
        movingPoint = Geometry::RotatePoint3d(movingPoint, ship.CentralLine.NormalFront, ship.CentralLine.Front, (float)i * radiansStep);
        AddResultIfCorrect(ship, allShips, track, movingPoint, result);

        movingPoint.Set(straight);
        movingPoint = Geometry::RotatePoint3d(movingPoint, ship.CentralLine.NormalFront, ship.CentralLine.Front, (float)-i * radiansStep);
        AddResultIfCorrect(ship, allShips, track, movingPoint, result);
    }

    return result;
}

void ObstacleAvoidanceLogic::AddResultIfCorrect(Ship& ship, List<Ship*>& allShips, Track& track, Vector3 direction, Vector3& result)
{
    if (_trackCollisionDetector.DetectCollisions(track, ship.CentralLine.TrackPointIndexFront, direction))
    {
        return;
    }

    for (int i = 0; i < allShips.GetCount(); i++)
    {
        Ship& otherShip = *allShips[i];
        if (!Object::ReferenceEquals(ship, otherShip) &&
            _shipCollisionDetector.DetectCollisions(otherShip, ship.CentralLine.Front, direction))
        {
            return;
        }
    }

    direction.Sub(ship.CentralLine.Front);
    result.Add(direction);
}
