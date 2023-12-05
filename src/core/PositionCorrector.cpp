#include "calc/Vector3d.h"
#include "core/PositionCorrector.h"

void PositionCorrector::CorrectAfterFloatOperations(Ship& ship)
{
    Vector3d direction = ship.CentralLine.Front;
    direction.Sub(ship.CentralLine.Rear);
    ship.OrientationByFrontPoint(ship.CentralLine.Front, direction);
}
