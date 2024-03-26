#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class VelocityCalculator : public Object
{
public:
    void CalculateVelocity(Ship& ship);
};

class VelocityCalculatorResolvingFactory : public ResolvingFactory<VelocityCalculator>
{
public:
    VelocityCalculator* Make(Resolver& resolver) override;
};
