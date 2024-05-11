#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <model/PowerUp.h>
#include <core/PositionUpdater.h>
#include <core/StartingGridInitializer.h>
#include <core/RaceDistanceCalculator.h>
#include <core/RacePositionUpdater.h>
#include <core/PowerUpGenerator.h>

class RaceInitializer : public Object
{
    PositionUpdater& _positionUpdater;
    StartingGridInitializer& _startingGridInitializer;
    RaceDistanceCalculator& _raceDistanceCalculator;
    RacePositionUpdater& _racePositionUpdater;
    PowerUpGenerator& _powerUpGenerator;

public:
    RaceInitializer(
        PositionUpdater& positionUpdater,
        StartingGridInitializer& startingGridInitializer,
        RaceDistanceCalculator& raceDistanceCalculator,
        RacePositionUpdater& racePositionUpdater,
        PowerUpGenerator& powerUpGenerator);

    void Init(
        Ship& player,
        Collection<Ship>& enemies,
        Collection<Ship*>& allShips,
        Collection<Ship*>& allShipsSortedByPositions,
        Track& track,
        List<PowerUp>& powerUps);

private:
    void InitShips(Ship& player, Collection<Ship>& enemies);
    void UpdateShipsPositions(Collection<Ship*>& allShips, Track& track);
};

class RaceInitializerResolvingFactory : public ResolvingFactory<RaceInitializer>
{
public:
    RaceInitializer* Make(Resolver& resolver) override;
};
