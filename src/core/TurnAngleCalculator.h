#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class TurnAngleCalculator : public Object
{
public:
    void CalculateTurnAngle(Ship& ship);

private:
    float GetMaxTurnAngle(Ship& ship);
};

class TurnAngleCalculatorResolvingFactory : public ResolvingFactory<TurnAngleCalculator>
{
public:
    TurnAngleCalculator* Make(Resolver& resolver) override;
};
