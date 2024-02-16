#include <core/Race.h>
#include <core/RaceInitializer.h>

Race::Race(
    RaceUpdater& raceUpdater) :
    _raceUpdater(raceUpdater),
    PlayerController(Player)
{
    State = RaceState::Prepare;
    Track = nullptr;
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
    _raceUpdater.Update(State, Player, *Track, Laps);
}
