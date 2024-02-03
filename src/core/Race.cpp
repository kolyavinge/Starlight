#include <core/Race.h>
#include <core/GameInitializer.h>

Race::Race(
    GameUpdater& gameUpdater) :
    _gameUpdater(gameUpdater),
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
    _gameUpdater.Update(Player, *Track, Camera);
}
