#include <model/TrackPointInfo.h>
#include <ai/NitroActivationLogic.h>

NitroActivationLogic::NitroActivationLogic(ShipController& controller) :
    _controller(controller)
{
}

void NitroActivationLogic::Apply(Ship& ship, Track& track)
{
    if (ship.Nitros.GetCount() == 0) return;
    _controller.SetShip(ship);
    if (track.PointInfos[ship.CentralLine.TrackPointIndexFront].Kind == TrackPointKind::Straight)
    {
        _controller.ActivateNitro();
    }
}

NitroActivationLogic* NitroActivationLogicResolvingFactory::Make(Resolver& resolver)
{
    return new NitroActivationLogic(resolver.Resolve<ShipController>());
}
