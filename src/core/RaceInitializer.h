#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>

class RaceInitializer : public Object
{
public:
    void Init(Race& race);

private:
    void InitShips(Race& race);
    void SetStartGrid(Race& race);
    void UpdateShipsPositions(Race& race);
    void GeneratePowerUps(Race& race);
};

class RaceInitializerResolvingFactory : public ResolvingFactory<RaceInitializer>
{
public:
    RaceInitializer* Make(Resolver& resolver) override;
};
