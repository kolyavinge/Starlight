#include <model/NitroCollection.h>
#include <core/NitroLogic.h>

void NitroLogic::ProcessNitro(Ship& ship)
{
    if (ship.Nitros.State == NitroState::Innactive)
    {
        if (ship.Controls.IsNitroActive)
        {
            ship.Controls.IsNitroActive = false;
            if (ship.Nitros.GetCount() > 0)
            {
                ship.Nitros.ActivateOne();
            }
        }
    }
    else if (ship.Nitros.State == NitroState::Activated)
    {
        ship.VelocityFunction.AddDelta(0.1f);
        ship.Nitros.Update();
    }
    else if (ship.Nitros.State == NitroState::Deactivated)
    {
        ship.VelocityFunction.AddDelta(-0.1f);
        ship.Nitros.Update();
    }
}
