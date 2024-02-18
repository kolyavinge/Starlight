#include <core/Race.h>
#include <core/RaceInitializer.h>

Race::Race() :
    _raceUpdater(EnemyAI)
{
    State = RaceState::Prepare;
    Track = nullptr;
    PlayerController.SetShip(Player);
    for (int i = 0; i < EnemiesCount; i++)
    {
        Enemies.Add(Ship());
    }
}

void Race::Init(::Track& selectedTrack)
{
    State = RaceState::Prepare;
    Track = &selectedTrack;
    RaceInitializer initializer;
    initializer.Init(*this);
    Update();
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
        *Track,
        Laps);
}
