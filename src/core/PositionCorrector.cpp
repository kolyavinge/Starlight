#include "core/PositionCorrector.h"

void PositionCorrector::CorrectAfterFloatOperations(Ship& ship)
{
    ship.FrontMiddlePoint.Sub(ship.RearMiddlePoint);
    ship.FrontMiddlePoint.Normalize();
    ship.FrontMiddlePoint.Mul(Ship::YLength);
    ship.FrontMiddlePoint.Add(ship.RearMiddlePoint);
}
