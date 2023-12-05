#include "lib/Math.h"
#include "lib/Numeric.h"
#include "model/Ship.h"

const float Ship::XLength = 1.0f;
const float Ship::YLength = 2.0f;
const float Ship::ZLength = 1.0f;
const float Ship::XLengthHalf = XLength / 2.0f;
const float Ship::ThrottleTimeThreshold = 2.71f;
const float Ship::MaxVelocity = 1.0f;
const float Ship::TurnAngleStep = 0.08f;
const float Ship::TurnAngleDecay = 0.05f;
const float Ship::TurnAngleThreshold = 0.8f;

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
    CurrentVelocityValue = 0;
    LastVelocityValue = 0;
}

float Ship::GetCurrentVelocity()
{
    if (Numeric::FloatEquals(ThrottleTime, 0.0f)) return 0.0f;
    if (ThrottleTime >= ThrottleTimeThreshold) return MaxVelocity;

    return Math::LogE(ThrottleTime + 1.0f);
}

void Ship::SetFrontOrientation(Vector3d frontMiddlePoint, Vector3d direction)
{
    direction.SetLength(Ship::YLength);
    FrontMiddlePoint = frontMiddlePoint;
    RearMiddlePoint = frontMiddlePoint;
    RearMiddlePoint.Sub(direction);
}

void Ship::SetRearOrientation(Vector3d rearMiddlePoint, Vector3d direction)
{
    direction.SetLength(Ship::YLength);
    FrontMiddlePoint = rearMiddlePoint;
    RearMiddlePoint = rearMiddlePoint;
    FrontMiddlePoint.Add(direction);
}
