#include <vox/ui/RaceVox.h>

RaceVox::RaceVox(
    ShipVox& shipVox,
    Race& race) :
    _shipVox(shipVox),
    _race(race)
{
}

void RaceVox::Deactivate()
{
    _shipVox.Pause();
}

void RaceVox::Voice(Screen&)
{
    _shipVox.Voice(_race.Player.CentralLine.Front, _race.AllShips);
}

RaceVox* RaceVoxResolvingFactory::Make(Resolver& resolver)
{
    return new RaceVox(
        resolver.Resolve<ShipVox>(),
        resolver.Resolve<Race>());
}
