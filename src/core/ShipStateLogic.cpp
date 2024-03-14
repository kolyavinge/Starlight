#include <lib/Numeric.h>
#include <core/ShipStateLogic.h>

void ShipStateLogic::ProcessState(Ship& ship)
{
    if (ship.State == ShipState::Active &&
        Numeric::FloatEquals(ship.Health, 0.0f))
    {
        ship.State = ShipState::Exploded;
        ship.Controls.Init();
    }
    else if (ship.State == ShipState::Exploded)
    {
        ship.State = ShipState::Destroyed;
    }
}
