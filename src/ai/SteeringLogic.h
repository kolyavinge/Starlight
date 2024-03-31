#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/ShipController.h>

class SteeringLogic : public Object
{
    ShipController& _controller;

public:
    SteeringLogic(ShipController& controller);

    void Update(Ship& ship, Track& track);

private:
    void ProcessSteering(Ship& ship);
    void ProcessThrottle(Ship& ship, Track& track);
};

class SteeringLogicResolvingFactory : public ResolvingFactory<SteeringLogic>
{
public:
    SteeringLogic* Make(Resolver& resolver) override;
};
