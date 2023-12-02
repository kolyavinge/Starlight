#pragma once

#include "lib/Object.h"
#include "calc/Vector3d.h"

class Ship : public Object
{
public:
    static const float XLength;
    static const float YLength;
    static const float ZLength;
    static const float ThresholdThrottleTime;
    static const float MaxVelocity;
    static const float TurnAngleStep;
    static const float TurnAngleDecay;
    static const float TurnAngleThreshold;

    bool IsThrottleActive;
    bool IsBreakActive;
    bool IsTurnLeftActive;
    bool IsTurnRightActive;
    float ThrottleTime;
    float TurnAngle;
    float CurrentVelocityValue;
    float LastVelocityValue;
    Vector3d FrontMiddlePoint;
    Vector3d RearMiddlePoint;

    Ship();

    void Init();
    float GetCurrentVelocity();
};
