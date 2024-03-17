#include <core/Race.h>
#include <core/RaceInitializer.h>

Race::Race() :
    _raceUpdater(EnemyAI),
    AllShips(EnemiesCount + 1)
{
    State = RaceState::Prepare;
    Track = nullptr;
    PlayerController.SetShip(Player);
    for (int i = 0; i < EnemiesCount; i++)
    {
        Enemies[i].Init();
    }
    AllShips.Add(&Player);
    for (int i = 0; i < EnemiesCount; i++)
    {
        AllShips.Add(&Enemies[i]);
    }
}

void Race::Init(::Track& selectedTrack)
{
    State = RaceState::Prepare;
    Track = &selectedTrack;
    RaceInitializer initializer;
    initializer.Init(*this);
    BorderUpdater borderUpdater;
    for (int i = 0; i < AllShips.GetCount(); i++)
    {
        borderUpdater.Update(*AllShips[i]);
    }
}

void Race::Start()
{
    State = RaceState::Start;
    Laps.StartFirstLap();
}

void Race::Pause()
{
    Laps.StopTimer();
}

void Race::Resume()
{
    Laps.ResumeTimer();
}

void Race::Update()
{
    _raceUpdater.Update(
        State,
        Player,
        Enemies,
        AllShips,
        PowerUps,
        *Track,
        Laps);
}
