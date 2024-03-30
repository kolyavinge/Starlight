#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <calc/Vector3.h>

class ShipMovingDirections : public Object
{
public:
    List<Vector3> AvailableDirections;
    List<bool> EnabledDirections;
    Vector3 ResultDirection;

    void Init();
};

class ShipAIData : public Object
{
public:
    ShipMovingDirections MovingDirections;
    int MovingPointsSteps;
    float StraightDirectionLimit;
    float MovingDirectionLength;
    float VelocityDelta;

    ShipAIData();

    void InitForPlayer();
    void InitForEnemy();
};
