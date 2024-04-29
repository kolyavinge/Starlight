#include <lib/Numeric.h>
#include <calc/Vector3.h>
#include <calc/Plane.h>
#include <model/ShipMeasure.h>
#include <core/cm/ShipCollisionDetector.h>

ShipCollisionResult::ShipCollisionResult()
{
    Init();
}

void ShipCollisionResult::Init()
{
    Ship1 = nullptr;
    Ship2 = nullptr;
}

bool ShipCollisionDetector::DetectCollisions(Ship& ship, Collection<Ship*>& allShips)
{
    for (int i = 0; i < allShips.GetCount(); i++)
    {
        if (!Object::ReferenceEquals(ship, *allShips[i]) &&
            DetectCollisions(ship, *allShips[i]))
        {
            Result.Ship1 = &ship;
            Result.Ship2 = allShips[i];
            return true;
        }
    }

    return false;
}

bool ShipCollisionDetector::DetectCollisions(Ship& ship1, Ship& ship2)
{
    return
        DetectCollisions(ship2, ship1.CentralLine.Front) ||
        DetectCollisions(ship2, ship1.CentralLine.Rear) ||
        DetectCollisions(ship2, ship1.Border.UpLeft) ||
        DetectCollisions(ship2, ship1.Border.UpRight) ||
        DetectCollisions(ship2, ship1.Border.DownLeft) ||
        DetectCollisions(ship2, ship1.Border.DownRight);
}

bool ShipCollisionDetector::DetectCollisions(Ship& ship, Vector3& from, Vector3& to, float stepSize)
{
    Vector3 direction(to);
    direction.Sub(from);
    const int steps = (int)(direction.GetLength() / stepSize);
    Vector3 point;
    for (int step = 1; step <= steps; step++)
    {
        direction.SetLength((float)step * stepSize);
        point.Set(from);
        point.Add(direction);
        if (DetectCollisions(ship, point))
        {
            return true;
        }
    }

    // check last point
    bool result = ship.Border.Contains(to);

    return result;
}

bool ShipCollisionDetector::DetectCollisions(Ship& ship, Vector3& point)
{
    return
        ship.Border.Contains(point) &&
        CheckBordersZ(ship, point);
}

bool ShipCollisionDetector::CheckBordersZ(Ship& ship, Vector3& point)
{
    Vector3 upperFrontPoint(ship.CentralLine.NormalFront);
    upperFrontPoint.SetLength(ShipMeasure::ZLength);
    upperFrontPoint.Add(ship.CentralLine.Front);

    Plane lowerPlane(ship.CentralLine.NormalFront, ship.CentralLine.Front);
    Plane upperPlane(ship.CentralLine.NormalFront, upperFrontPoint);

    float lowerPlaneZ = lowerPlane.GetZ(point.X, point.Y) - 0.1f;
    float upperPlaneZ = upperPlane.GetZ(point.X, point.Y) + 0.1f;
    bool betweenPlanes = Numeric::Between(point.Z, lowerPlaneZ, upperPlaneZ);

    return betweenPlanes;
}

ShipCollisionDetector* ShipCollisionDetectorResolvingFactory::Make(Resolver&)
{
    return new ShipCollisionDetector();
}
