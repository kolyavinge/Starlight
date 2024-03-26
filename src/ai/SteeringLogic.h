#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/ShipController.h>

class SteeringLogic : public Object
{
    ShipController& _controller;

public:
    SteeringLogic(ShipController& controller);

    void Update(Ship& ship);
};

class SteeringLogicResolvingFactory : public ResolvingFactory<SteeringLogic>
{
public:
    SteeringLogic* Make(Resolver& resolver) override;
};
