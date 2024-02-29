#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <model/Track.h>
#include <model/Ship.h>

class StartingGridInitializer : public Object
{
public:
    void SetStartGrid(Ship& player, List<Ship>& enemies, Track& track);
};
