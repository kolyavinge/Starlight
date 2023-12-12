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

class ShipCentralLine : public Object
{
public:
    Vector3d Front;
    Vector3d Rear;
    Vector3d NormalFront;
    Vector3d NormalRear;
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
    float VelocityValue;
    float PrevVelocityValue;
    ShipCentralLine CentralLine;
    ShipCentralLine PrevCentralLine;
    RectBorder Border;
    Vector3d Deviation;

    Ship();

    void Init();
    float GetCurrentVelocity();
    void OrientationByFrontPoint(Vector3d& frontMiddlePoint, Vector3d direction);
    void OrientationByRearPoint(Vector3d& rearMiddlePoint, Vector3d direction);
};
