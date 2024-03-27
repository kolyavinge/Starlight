#include <core/RaceInitializer.h>

RaceInitializer::RaceInitializer(
    PositionUpdater& positionUpdater,
    StartingGridInitializer& startingGridInitializer,
    PowerUpGenerator& powerUpGenerator) :
    _positionUpdater(positionUpdater),
    _startingGridInitializer(startingGridInitializer),
    _powerUpGenerator(powerUpGenerator)
{
}

void RaceInitializer::Init(Ship& player, IArray<Ship>& enemies, Track& track, List<PowerUp>& powerUps)
{
    InitShips(player, enemies);
    _startingGridInitializer.SetStartGrid(player, enemies, track);
    UpdateShipsPositions(player, enemies, track);
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

void RaceInitializer::UpdateShipsPositions(Ship& player, IArray<Ship>& enemies, Track& track)
{
    _positionUpdater.Update(player, track);
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        _positionUpdater.Update(enemies[i], track);
    }
}

RaceInitializer* RaceInitializerResolvingFactory::Make(Resolver& resolver)
{
    return new RaceInitializer(
        resolver.Resolve<PositionUpdater>(),
        resolver.Resolve<StartingGridInitializer>(),
        resolver.Resolve<PowerUpGenerator>());
}
