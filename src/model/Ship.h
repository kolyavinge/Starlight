#pragma once

#include "lib/Object.h"
#include "calc/Vector3d.h"
#include "model/RectBorder.h"

class Ship : public Object
{
public:
    static const float XLength;
    static const float YLength;
    static const float ZLength;
    static const float XLengthHalf;
    static const float ThrottleTimeThreshold;
    static const float MaxVelocity;
    static const float TurnAngleStep;
    static const float TurnAngleDecay;
    static const float TurnAngleThreshold;

    bool IsThrottleActive;
    bool IsBreakActive;
    bool IsTurnLeftActive;
    bool IsTurnRightActive;
    float ThrottleTime;
    float TurnAngleRadians;
    float CurrentVelocityValue;
    float LastVelocityValue;
    Vector3d FrontMiddlePoint;
    Vector3d RearMiddlePoint;
    RectBorder Border;

    Ship();

    void Init();
    float GetCurrentVelocity();
    void SetFrontOrientation(Vector3d frontMiddlePoint, Vector3d direction);
    void SetRearOrientation(Vector3d rearMiddlePoint, Vector3d direction);
};
