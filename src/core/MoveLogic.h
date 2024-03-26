#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class MoveLogic : public Object
{
public:
    void MoveShip(Ship& ship);

private:
    void MoveStraight(Ship& ship, float moveDistance);
    void MoveAround(Ship& ship, float moveDistance);
    void GetPivotPoint(Ship& ship, float frontTurnRadius, Vector3& pivot);
    void Assert(Ship& ship, float frontTurnRadius, float rearTurnRadius, Vector3& pivot);
};

class MoveLogicResolvingFactory : public ResolvingFactory<MoveLogic>
{
public:
    MoveLogic* Make(Resolver& resolver) override;
};
