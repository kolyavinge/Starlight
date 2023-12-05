#include "lib/Math.h"
#include "lib/Numeric.h"
#include "model/Ship.h"

const float ShipMeasure::XLength = 1.0f;
const float ShipMeasure::YLength = 2.0f;
const float ShipMeasure::ZLength = 1.0f;
const float ShipMeasure::XLengthHalf = XLength / 2.0f;
const float ShipMeasure::ThrottleTimeThreshold = 2.71f;
const float ShipMeasure::MaxVelocity = 1.0f;
const float ShipMeasure::TurnAngleStep = 0.08f;
const float ShipMeasure::TurnAngleDecay = 0.05f;
const float ShipMeasure::TurnAngleThreshold = 0.8f;

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

void Ship::OrientationByFrontPoint(Vector3d frontMiddlePoint, Vector3d direction)
{
    direction.SetLength(ShipMeasure::YLength);
    CentralLine.Front = frontMiddlePoint;
    CentralLine.Rear = frontMiddlePoint;
    CentralLine.Rear.Sub(direction);
}

void Ship::OrientationByRearPoint(Vector3d rearMiddlePoint, Vector3d direction)
{
    direction.SetLength(ShipMeasure::YLength);
    CentralLine.Front = rearMiddlePoint;
    CentralLine.Rear = rearMiddlePoint;
    CentralLine.Front.Add(direction);
}
