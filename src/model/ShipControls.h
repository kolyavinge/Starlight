#pragma once

#include <lib/Object.h>

class ShipControls : public Object
{
public:
    bool IsThrottleActive;
    bool IsBreakActive;
    bool IsTurnLeftActive;
    bool IsTurnRightActive;
    bool IsFireActive;

    ShipControls();

    void Init();
};
