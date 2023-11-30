#pragma once

#include "lib/Object.h"
#include "calc/Vector3d.h"

class Ship : public Object
{
public:
    bool IsThrottleActive;
    bool IsBreakActive;
    bool IsTurnLeftActive;
    bool IsTurnRightActive;
    float Throttle;
    float TurnAngle;
    Vector3d Velocity;

    Ship();

    void Init();
};
