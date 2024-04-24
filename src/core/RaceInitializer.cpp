#include <core/RaceInitializer.h>

RaceInitializer::RaceInitializer(
    PositionUpdater& positionUpdater,
    StartingGridInitializer& startingGridInitializer,
    RaceDistanceCalculator& raceDistanceCalculator,
    PowerUpGenerator& powerUpGenerator) :
    _positionUpdater(positionUpdater),
    _startingGridInitializer(startingGridInitializer),
    _raceDistanceCalculator(raceDistanceCalculator),
    _powerUpGenerator(powerUpGenerator)
{
}

void RaceInitializer::Init(Ship& player, IArray<Ship>& enemies, IArray<Ship*>& allShips, Track& track, List<PowerUp>& powerUps)
{
    InitShips(player, enemies);
    _startingGridInitializer.SetStartGrid(player, enemies, track);
    UpdateShipsPositions(allShips, track);
    _raceDistanceCalculator.InitBeforeStart(allShips, track);
    _powerUpGenerator.Generate(track, powerUps);
}

void RaceInitializer::InitShips(Ship& player, IArray<Ship>& enemies)
{
    player.AIData.InitForPlayer();
    player.Init();
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        enemies[i].AIData.InitForEnemy();
        enemies[i].Init();
    }
}

void RaceInitializer::UpdateShipsPositions(IArray<Ship*>& allShips, Track& track)
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
        resolver.Resolve<PowerUpGenerator>());
}
