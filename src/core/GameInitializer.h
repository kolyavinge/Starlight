#pragma once

#include <lib/Object.h>
#include <core/Race.h>

class GameInitializer : Object
{
public:
    void Init(Race& race);

private:
    void SetPlayerBehindStartFinishLine(Track& track, Ship& player);
    void UpdateShipPosition(Track& track, Ship& player);
};
