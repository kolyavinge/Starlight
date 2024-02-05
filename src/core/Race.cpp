#include <core/Race.h>
#include <core/RaceInitializer.h>

Race::Race(
    RaceUpdater& raceUpdater) :
    _raceUpdater(raceUpdater),
    PlayerController(Player)
{
    Track = nullptr;
}

void Race::Start(::Track& selectedTrack)
{
    Track = &selectedTrack;
    RaceInitializer initializer;
    initializer.Init(*this);
    Update();
}

void Race::Update()
{
    _raceUpdater.Update(Player, *Track, Camera);
}
