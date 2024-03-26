#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/ShipController.h>

class NitroActivationLogic : public Object
{
    ShipController& _controller;

public:
    NitroActivationLogic(ShipController& controller);

    void Apply(Ship& ship, Track& track);
};

class NitroActivationLogicResolvingFactory : public ResolvingFactory<NitroActivationLogic>
{
public:
    NitroActivationLogic* Make(Resolver& resolver) override;
};
