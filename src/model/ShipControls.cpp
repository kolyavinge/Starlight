#include <model/ShipControls.h>

ShipControls::ShipControls()
{
    Init();
}

void ShipControls::Init()
{
    IsThrottleActive = false;
    IsBreakActive = false;
    IsTurnLeftActive = false;
    IsTurnRightActive = false;
    IsFireActive = false;
    IsNitroActive = false;
}
