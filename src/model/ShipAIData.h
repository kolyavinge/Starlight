#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>

class ShipAIData : public Object
{
public:
    Vector3 MovingDirection;
    int MovingPointsSteps;
    float StraightDirectionLimit;
    float MovingDirectionLength;

    ShipAIData();

    void Init();
};
