#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class BorderUpdater : public Object
{
public:
    void Update(Ship& ship);
};

class BorderUpdaterResolvingFactory : public ResolvingFactory<BorderUpdater>
{
public:
    BorderUpdater* Make(Resolver& resolver) override;
};
