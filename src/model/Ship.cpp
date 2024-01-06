#include <lib/Numeric.h>
#include <model/ShipMeasure.h>
#include <model/Ship.h>

Ship::Ship()
{
    Init();
}

void Ship::Init()
{
    IsThrottleActive = false;
    IsBreakActive = false;
    IsTurnLeftActive = false;
    IsTurnRightActive = false;
    ThrottleTime = 0;
    TurnAngleRadians = 0;
    VelocityValue = 0;
    PrevVelocityValue = 0;
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

void Ship::SetCurrentVelocity()
{
    VelocityValue = VelocityFunction.GetValue(ThrottleTime);
}

float Ship::GetRollRadians()
{
    return -0.5f * TurnAngleRadians;
}
