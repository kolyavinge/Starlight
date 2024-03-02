#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/Track.h>
#include <model/Ship.h>

class StartingGridInitializer : public Object
{
public:
    void SetStartGrid(Ship& player, IArray<Ship>& enemies, Track& track);
};
