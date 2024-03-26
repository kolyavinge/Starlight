#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Track.h>
#include <model/Ship.h>

class StartingGridInitializer : public Object
{
public:
    void SetStartGrid(Ship& player, IArray<Ship>& enemies, Track& track);
};

class StartingGridInitializerResolvingFactory : public ResolvingFactory<StartingGridInitializer>
{
public:
    StartingGridInitializer* Make(Resolver& resolver) override;
};
