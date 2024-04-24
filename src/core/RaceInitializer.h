#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <model/PowerUp.h>
#include <core/PositionUpdater.h>
#include <core/StartingGridInitializer.h>
#include <core/RaceDistanceCalculator.h>
#include <core/PowerUpGenerator.h>

class RaceInitializer : public Object
{
    PositionUpdater& _positionUpdater;
    StartingGridInitializer& _startingGridInitializer;
    RaceDistanceCalculator& _raceDistanceCalculator;
    PowerUpGenerator& _powerUpGenerator;

public:
    RaceInitializer(
        PositionUpdater& positionUpdater,
        StartingGridInitializer& startingGridInitializer,
        RaceDistanceCalculator& raceDistanceCalculator,
        PowerUpGenerator& powerUpGenerator);

    void Init(Ship& player, IArray<Ship>& enemies, IArray<Ship*>& allShips, Track& track, List<PowerUp>& powerUps);

private:
    void InitShips(Ship& player, IArray<Ship>& enemies);
    void UpdateShipsPositions(IArray<Ship*>& allShips, Track& track);
};

class RaceInitializerResolvingFactory : public ResolvingFactory<RaceInitializer>
{
public:
    RaceInitializer* Make(Resolver& resolver) override;
};
