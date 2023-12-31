#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>
#include <model/RectBorder.h>
#include <model/VelocityFunction.h>

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
    VelocityFunction VelocityFunction;

    Ship();

    void Init();
    void OrientationByFrontPoint(Vector3d& frontMiddlePoint, Vector3d direction);
    void OrientationByRearPoint(Vector3d& rearMiddlePoint, Vector3d direction);
    bool IsMoving();
    void SetCurrentVelocity();
};
