#include "calc/Vector3d.h"
#include "core/PositionCorrector.h"

void PositionCorrector::CorrectAfterFloatOperations(Ship& ship)
{
    Vector3d direction = ship.FrontMiddlePoint;
    direction.Sub(ship.RearMiddlePoint);
    ship.SetFrontOrientation(ship.FrontMiddlePoint, direction);
}
