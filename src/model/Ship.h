#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/ShipCentralLine.h>
#include <model/Border.h>
#include <model/VelocityFunction.h>

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
    Border Border;
    Vector3 Deviation;
    VelocityFunction VelocityFunction;
    // ai data
    Vector3 AIMovingDirection;

    Ship();

    void Init();
    void OrientationByFrontPoint(Vector3& frontMiddlePoint, Vector3 direction);
    void OrientationByRearPoint(Vector3& rearMiddlePoint, Vector3 direction);
    bool IsMoving();
    void SetCurrentVelocity();
    float GetRollRadians();
};
