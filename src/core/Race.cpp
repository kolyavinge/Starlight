#include <core/Race.h>
#include <core/RaceInitializer.h>

Race::Race() :
    _raceUpdater(EnemyAI),
    Enemies(EnemiesCount),
    _allShips(EnemiesCount + 1)
{
    State = RaceState::Prepare;
    Track = nullptr;
    PlayerController.SetShip(Player);
    for (int i = 0; i < EnemiesCount; i++)
    {
        Enemies.Add(Ship());
    }
    _allShips.Add(&Player);
    for (int i = 0; i < EnemiesCount; i++)
    {
        _allShips.Add(&Enemies[i]);
    }
}

void Race::Init(::Track& selectedTrack)
{
    State = RaceState::Prepare;
    Track = &selectedTrack;
    RaceInitializer initializer;
    initializer.Init(*this);
    BorderUpdater borderUpdater;
    for (int i = 0; i < _allShips.GetCount(); i++)
    {
        borderUpdater.Update(*_allShips[i]);
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
        _allShips,
        *Track,
        Laps);
}
