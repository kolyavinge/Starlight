#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/ShipCentralLine.h>
#include <model/ShipAIData.h>
#include <model/Border.h>
#include <model/VelocityFunction.h>
#include <model/Weapon.h>
#include <model/Machinegun.h>

enum class ShipState { Active, Destroyed, Reseted };

class Ship : public Object
{
    Machinegun _weapon;

public:
    ShipState State;
    bool IsThrottleActive;
    bool IsBreakActive;
    bool IsTurnLeftActive;
    bool IsTurnRightActive;
    bool IsFireActive;
    float ThrottleTime;
    float TurnAngleRadians;
    float VelocityValue;
    float PrevVelocityValue;
    ShipCentralLine CentralLine;
    ShipCentralLine PrevCentralLine;
    Border Border;
    Vector3 Deviation;
    VelocityFunction VelocityFunction;
    ShipAIData AIData;
    Weapon& Weapon;
    float Health;

    Ship();

    void Init();
    void OrientationByFrontPoint(Vector3& frontMiddlePoint, Vector3 direction);
    void OrientationByRearPoint(Vector3& rearMiddlePoint, Vector3 direction);
    bool IsMoving();
    float GetRollRadians();
    Vector3 GetVelocityVector();
};
