#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class PositionCorrector : public Object
{
public:
    void CorrectAfterFloatOperations(Ship& ship);
};

class PositionCorrectorResolvingFactory : public ResolvingFactory<PositionCorrector>
{
public:
    PositionCorrector* Make(Resolver& resolver) override;
};
