#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class NitroLogic : public Object
{
public:
    void ProcessNitro(Ship& ship);
};

class NitroLogicResolvingFactory : public ResolvingFactory<NitroLogic>
{
public:
    NitroLogic* Make(Resolver& resolver) override;
};
