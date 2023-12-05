#pragma once

#include "lib/Object.h"
#include "calc/Vector3d.h"
#include "model/RectBorder.h"

class ShipMeasure
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
};

class Ship : public Object
{
public:
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
    void OrientationByFrontPoint(Vector3d frontMiddlePoint, Vector3d direction);
    void OrientationByRearPoint(Vector3d rearMiddlePoint, Vector3d direction);
};
