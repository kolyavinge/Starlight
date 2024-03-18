#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/List.h>
#include <lib/Random.h>
#include <model/Track.h>
#include <model/PowerUp.h>

class PowerUpGenerator : public Object
{
    Random _rand;

public:
    void Generate(Track& track, List<PowerUp>& powerUps);
    void UpdatePositions(Track& track, IArray<PowerUp>& powerUps);

private:
    void GeneratePowerUps(List<PowerUp>& powerUps);
    void GenerateHealthPowerUp(PowerUp& powerUp);
    void GenerateMachinegunPowerUp(PowerUp& powerUp);
    void GenerateNewPosition(Track& track, PowerUp& powerUp);
};
