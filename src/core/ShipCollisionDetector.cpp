#include <core/ShipCollisionDetector.h>

bool ShipCollisionDetector::DetectCollisions(Ship& ship, List<Ship*>& allShips)
{
    for (int i = 0; i < allShips.GetCount(); i++)
    {
        if (!Object::ReferenceEquals(ship, *allShips[i]) &&
            DetectCollisions(ship, *allShips[i]))
        {
            return true;
        }
    }

    return false;
}

bool ShipCollisionDetector::DetectCollisions(Ship& ship1, Ship& ship2)
{
    return
        ship2.Border.Contains(ship1.Border.UpLeft) ||
        ship2.Border.Contains(ship1.Border.UpRight) ||
        ship2.Border.Contains(ship1.Border.DownLeft) ||
        ship2.Border.Contains(ship1.Border.DownRight);
}
