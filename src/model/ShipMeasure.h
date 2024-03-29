#pragma once

class ShipMeasure
{
public:
    inline static const float Mass = 100.0f;
    inline static const float XLength = 2.0f;
    inline static const float YLength = 2.0f;
    inline static const float ZLength = 0.5f;
    inline static const float XLengthHalf = XLength / 2.0f;
    inline static const float YLengthHalf = YLength / 2.0f;
    inline static const float TurnAngleStep = 0.08f;
    inline static const float TurnAngleDecay = 0.05f;
    inline static const float MaxTurnAngle = 0.2f;
};
