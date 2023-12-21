#include <lib/Math.h>
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

float Ship::GetCurrentVelocity()
{
    if (Numeric::FloatEquals(ThrottleTime, 0.0f)) return 0.0f;
    if (ThrottleTime >= ShipMeasure::ThrottleTimeThreshold) return ShipMeasure::MaxVelocity;

    return Math::LogE(ThrottleTime + 1.0f);
}

void Ship::OrientationByFrontPoint(Vector3d& frontMiddlePoint, Vector3d direction)
{
    direction.SetLength(ShipMeasure::YLength);
    CentralLine.Front = frontMiddlePoint;
    CentralLine.Rear = frontMiddlePoint;
    CentralLine.Rear.Sub(direction);
}

void Ship::OrientationByRearPoint(Vector3d& rearMiddlePoint, Vector3d direction)
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
