#include "lib/Math.h"
#include "lib/Numeric.h"
#include "model/Ship.h"

const float Ship::XLength = 2.0f;
const float Ship::YLength = 3.0f;
const float Ship::ZLength = 1.0f;
const float Ship::ThresholdThrottleTime = 10.0f;
const float Ship::MaxVelocity = 4.0f;
const float Ship::TurnAngleStep = 0.2f;
const float Ship::TurnAngleDecay = 0.05f;
const float Ship::TurnAngleThreshold = 2.0f;

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
    TurnAngle = 0;
    CurrentVelocityValue = 0;
    LastVelocityValue = 0;
}

float Ship::GetCurrentVelocity()
{
    if (Numeric::FloatEquals(ThrottleTime, 0.0f)) return 0.0f;
    if (ThrottleTime >= ThresholdThrottleTime) return MaxVelocity;

    return Math::LogE(ThrottleTime + 1.0f);
}
