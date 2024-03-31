#include <lib/Math.h>
#include <calc/Geometry.h>
#include <model/ShipMeasure.h>
#include <ai/ObstacleAvoidanceLogic.h>

ObstacleAvoidanceLogic::ObstacleAvoidanceLogic(
    TrackCollisionDetector& trackCollisionDetector,
    ShipCollisionDetector& shipCollisionDetector) :
    _trackCollisionDetector(trackCollisionDetector),
    _shipCollisionDetector(shipCollisionDetector)
{
}

void ObstacleAvoidanceLogic::CalculateMovingDirection(Ship& ship, IArray<Ship*>& allShips, Track& track)
{
    float directionLength = ship.AIData.MovingDirectionLength * ShipMeasure::YLength;
    TryCalculateMovingDirection(ship, allShips, track, directionLength);
    while (ship.AIData.MovingDirections.ResultDirection.IsZero())
    {
        directionLength /= 2.0f;
        if (directionLength < 1.0f)
        {
            ship.AIData.MovingDirections.Init();
            return;
        }
        TryCalculateMovingDirection(ship, allShips, track, directionLength);
    }
    ship.AIData.MovingDirections.ResultDirection.Normalize();
}

void ObstacleAvoidanceLogic::TryCalculateMovingDirection(Ship& ship, IArray<Ship*>& allShips, Track& track, float directionLength)
{
    ship.AIData.MovingDirections.Init();
    GenerateAvailableDirections(ship, directionLength);
    EnableDirections(ship, allShips, track, directionLength);
    CalculateResultDirection(ship.AIData.MovingDirections);
}

void ObstacleAvoidanceLogic::GenerateAvailableDirections(Ship& ship, float directionLength)
{
    Vector3 straight(ship.CentralLine.Front);
    straight.Sub(ship.CentralLine.Rear);
    straight.SetLength(directionLength);

    Vector3 movingPoint;
    const int steps = ship.AIData.MovingPointsSteps;
    const float radiansStep = Math::PiQuarter / (float)steps;
    for (int i = 1; i <= steps; i++)
    {
        movingPoint.Set(straight);
        movingPoint = Geometry::RotatePoint3d(movingPoint, ship.CentralLine.NormalFront, (float)i * radiansStep);
        ship.AIData.MovingDirections.AvailableDirections.Add(movingPoint);

        movingPoint.Set(straight);
        movingPoint = Geometry::RotatePoint3d(movingPoint, ship.CentralLine.NormalFront, (float)-i * radiansStep);
        ship.AIData.MovingDirections.AvailableDirections.Add(movingPoint);
    }
}

void ObstacleAvoidanceLogic::EnableDirections(Ship& ship, IArray<Ship*>& allShips, Track& track, float directionLength)
{
    for (int i = 0; i < ship.AIData.MovingDirections.AvailableDirections.GetCount(); i++)
    {
        Vector3& direction = ship.AIData.MovingDirections.AvailableDirections[i];
        ship.AIData.MovingDirections.EnabledDirections.Add(IsDirectionEnabled(ship, allShips, track, direction, directionLength));
    }
}

bool ObstacleAvoidanceLogic::IsDirectionEnabled(Ship& ship, IArray<Ship*>& allShips, Track& track, Vector3 direction, float directionLength)
{
    direction.Add(ship.CentralLine.Front);

    if (_trackCollisionDetector.DetectCollisions(track, ship.CentralLine.TrackPointIndexFront + 100, direction)) // +100 ???
    {
        return false;
    }

    for (int i = 0; i < allShips.GetCount(); i++)
    {
        Ship& otherShip = *allShips[i];
        if (!Object::ReferenceEquals(ship, otherShip) &&
            GetLengthBetweenShips(ship, otherShip) < directionLength &&
            _shipCollisionDetector.DetectCollisions(otherShip, ship.CentralLine.Front, direction, 0.5f))
        {
            return false;
        }
    }

    return true;
}

float ObstacleAvoidanceLogic::GetLengthBetweenShips(Ship& ship, Ship& otherShip)
{
    Vector3 length(ship.CentralLine.Front);
    length.Sub(otherShip.CentralLine.Rear);

    return length.GetLength();
}

void ObstacleAvoidanceLogic::CalculateResultDirection(ShipMovingDirections& movingDirections)
{
    for (int i = 0; i < movingDirections.AvailableDirections.GetCount(); i++)
    {
        if (movingDirections.EnabledDirections[i])
        {
            movingDirections.ResultDirection.Add(movingDirections.AvailableDirections[i]);
        }
    }
}

ObstacleAvoidanceLogic* ObstacleAvoidanceLogicResolvingFactory::Make(Resolver& resolver)
{
    return new ObstacleAvoidanceLogic(
        resolver.Resolve<TrackCollisionDetector>(),
        resolver.Resolve<ShipCollisionDetector>());
}
