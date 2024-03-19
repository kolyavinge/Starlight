#pragma once

#include <lib/Object.h>
#include <core/Race.h>

class RaceInitializer : Object
{
public:
    void Init(Race& race);

private:
    void InitShips(Race& race);
    void SetStartGrid(Race& race);
    void UpdateShipsPositions(Race& race);
    void GeneratePowerUps(Race& race);
};
