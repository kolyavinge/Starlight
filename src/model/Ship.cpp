#include <lib/Numeric.h>
#include <model/ShipMeasure.h>
#include <model/Ship.h>

Ship::Ship() :
    Weapon(_weapon)
{
    Init();
}

void Ship::Init()
{
    State = ShipState::Active;
    IsThrottleActive = false;
    IsBreakActive = false;
    IsTurnLeftActive = false;
    IsTurnRightActive = false;
    IsFireActive = false;
    ThrottleTime = 0;
    TurnAngleRadians = 0;
    VelocityValue = 0;
    PrevVelocityValue = 0;
    CentralLine.Init();
    Border.Init();
    AIData.Init();
    Weapon.Init();
    Health = 1.0f;
}

void Ship::OrientationByFrontPoint(Vector3& frontMiddlePoint, Vector3 direction)
{
    direction.SetLength(ShipMeasure::YLength);
    CentralLine.Front = frontMiddlePoint;
    CentralLine.Rear = frontMiddlePoint;
    CentralLine.Rear.Sub(direction);
}

void Ship::OrientationByRearPoint(Vector3& rearMiddlePoint, Vector3 direction)
{
    direction.SetLength(ShipMeasure::YLength);
    CentralLine.Front = rearMiddlePoint;
    CentralLine.Rear = rearMiddlePoint;
    CentralLine.Front.Add(direction);
}

bool Ship::IsMoving()
{
    return !Numeric::FloatEquals(VelocityValue, 0.0f) || !Deviation.IsZero();
}

float Ship::GetRollRadians()
{
    return -1.0f * TurnAngleRadians;
}

Vector3 Ship::GetVelocityVector()
{
    Vector3 result;
    if (VelocityValue > 0.0f)
    {
        result.Set(CentralLine.Front);
        result.Sub(CentralLine.Rear);
        result.SetLength(VelocityValue);
    }

    return result;
}
