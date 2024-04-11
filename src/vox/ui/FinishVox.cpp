#include <vox/ui/FinishVox.h>

FinishVox::FinishVox(
    Camera& camera,
    Race& race,
    ShipVox& shipVox) :
    _camera(camera),
    _race(race),
    _shipVox(shipVox)
{
}

void FinishVox::Deactivate()
{
    _shipVox.Pause();
}

void FinishVox::Voice(Screen&)
{
    _shipVox.Voice(_camera.Position, _race.AllShips);
}

FinishVox* FinishVoxResolvingFactory::Make(Resolver& resolver)
{
    return new FinishVox(
        resolver.Resolve<Camera>(),
        resolver.Resolve<Race>(),
        resolver.Resolve<ShipVox>());
}
