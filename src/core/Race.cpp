#include <core/Race.h>
#include <core/GameInitializer.h>

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
    GameInitializer initializer;
    initializer.Init(*this);
}

void Race::Update()
{
    _raceUpdater.Update(Player, *Track, Camera);
}
