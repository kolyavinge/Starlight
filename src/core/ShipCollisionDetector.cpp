#include <core/ShipCollisionDetector.h>

bool ShipCollisionDetector::DetectCollisions(Ship& ship, List<Ship*>& allShips)
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

bool ShipCollisionDetector::DetectCollisions(Ship& ship, Vector3& from, Vector3& to)
{
    Vector3 direction(to);
    direction.Sub(from);
    const float stepSize = 0.5f;
    const int steps = (int)(direction.GetLength() / stepSize);
    Vector3 point;
    for (int step = 1; step <= steps; step++)
    {
        direction.SetLength((float)step * stepSize);
        point.Set(from);
        point.Add(direction);
        if (ship.Border.Contains(point))
        {
            return true;
        }
    }

    // check last point
    bool result = ship.Border.Contains(to);

    return result;
}

bool ShipCollisionDetector::DetectCollisions(Ship& ship1, Ship& ship2)
{
    return
        ship2.Border.Contains(ship1.CentralLine.Front) ||
        ship2.Border.Contains(ship1.CentralLine.Rear) ||
        ship2.Border.Contains(ship1.Border.UpLeft) ||
        ship2.Border.Contains(ship1.Border.UpRight) ||
        ship2.Border.Contains(ship1.Border.DownLeft) ||
        ship2.Border.Contains(ship1.Border.DownRight);
}
