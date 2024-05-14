#include <core/RaceInitializer.h>

RaceInitializer::RaceInitializer(
    PositionUpdater& positionUpdater,
    StartingGridInitializer& startingGridInitializer,
    RaceDistanceCalculator& raceDistanceCalculator,
    RacePositionUpdater& racePositionUpdater,
    PowerUpGenerator& powerUpGenerator) :
    _positionUpdater(positionUpdater),
    _startingGridInitializer(startingGridInitializer),
    _raceDistanceCalculator(raceDistanceCalculator),
    _racePositionUpdater(racePositionUpdater),
    _powerUpGenerator(powerUpGenerator)
{
}

void RaceInitializer::Init(
    Ship& player,
    Collection<Ship>& enemies,
    Collection<Ship*>& allShips,
    Collection<Ship*>& allShipsSortedByPositions,
    Track& track,
    List<PowerUp>& powerUps)
{
    InitShips(player, enemies);
    _startingGridInitializer.SetStartGrid(player, enemies, track);
    UpdateShipsPositions(allShips, track);
    _raceDistanceCalculator.InitBeforeStart(allShips, track);
    _racePositionUpdater.Update(allShipsSortedByPositions);
    _powerUpGenerator.Generate(track, powerUps);
}

void RaceInitializer::InitShips(Ship& player, Collection<Ship>& enemies)
{
    player.AIData.InitForPlayer();
    player.InitForPlayer();
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        enemies[i].AIData.InitForEnemy();
        enemies[i].InitForEnemy();
    }
}

void RaceInitializer::UpdateShipsPositions(Collection<Ship*>& allShips, Track& track)
{
    for (int i = 0; i < allShips.GetCount(); i++)
    {
        _positionUpdater.Update(*allShips[i], track);
    }
}

RaceInitializer* RaceInitializerResolvingFactory::Make(Resolver& resolver)
{
    return new RaceInitializer(
        resolver.Resolve<PositionUpdater>(),
        resolver.Resolve<StartingGridInitializer>(),
        resolver.Resolve<RaceDistanceCalculator>(),
        resolver.Resolve<RacePositionUpdater>(),
        resolver.Resolve<PowerUpGenerator>());
}
