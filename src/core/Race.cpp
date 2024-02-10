#include <core/Race.h>
#include <core/RaceInitializer.h>

Race::Race(
    RaceUpdater& raceUpdater) :
    _raceUpdater(raceUpdater),
    PlayerController(Player)
{
    Track = nullptr;
}

void Race::Init(::Track& selectedTrack)
{
    Track = &selectedTrack;
    RaceInitializer initializer;
    initializer.Init(*this);
    Update();
}

void Race::Start()
{
    Laps.StartFirstLap(Player);
}

void Race::Update()
{
    _raceUpdater.Update(Player, *Track, Camera, Laps);
}
