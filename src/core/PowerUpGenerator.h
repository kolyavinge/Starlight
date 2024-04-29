#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/List.h>
#include <lib/Random.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Track.h>
#include <model/PowerUp.h>

class PowerUpGenerator : public Object
{
    Random _rand;

public:
    void Generate(Track& track, List<PowerUp>& powerUps);
    void UpdatePositions(Track& track, Collection<PowerUp>& powerUps);

private:
    void GeneratePowerUps(List<PowerUp>& powerUps);
    void GenerateHealthPowerUp(PowerUp& powerUp);
    void GenerateMachinegunPowerUp(PowerUp& powerUp);
    void GenerateNitroPowerUp(PowerUp& powerUp);
    void GenerateNewPosition(Track& track, PowerUp& powerUp);
};

class PowerUpGeneratorResolvingFactory : public ResolvingFactory<PowerUpGenerator>
{
public:
    PowerUpGenerator* Make(Resolver& resolver) override;
};
