#include <core/PositionUpdater.h>
#include <core/StartingGridInitializer.h>
#include <core/RaceInitializer.h>

void RaceInitializer::Init(Race& race)
{
    InitShips(race);
    SetStartGrid(race);
    UpdateShipsPositions(race);
    SetAIData(race);
}

void RaceInitializer::InitShips(Race& race)
{
    race.Player.Init();
    for (int i = 0; i < race.Enemies.GetCount(); i++)
    {
        race.Enemies[i].Init();
    }
}

void RaceInitializer::SetStartGrid(Race& race)
{
    StartingGridInitializer initializer;
    initializer.SetStartGrid(race.Player, race.Enemies, *race.Track);
}

void RaceInitializer::UpdateShipsPositions(Race& race)
{
    PositionUpdater positionUpdater;
    positionUpdater.Update(race.Player, *race.Track);
    for (int i = 0; i < race.Enemies.GetCount(); i++)
    {
        positionUpdater.Update(race.Enemies[i], *race.Track);
    }
}

void RaceInitializer::SetAIData(Race& race)
{
    for (int i = 0; i < race.Enemies.GetCount(); i++)
    {
        race.Enemies[i].AIData.Init();
    }
}
