#include <lib/Numeric.h>
#include <core/ShipStateLogic.h>

void ShipStateLogic::ProcessState(Ship& ship)
{
    if (Numeric::FloatEquals(ship.Health, 0.0f))
    {
        ship.State = ShipState::Destroyed;
    }
}
