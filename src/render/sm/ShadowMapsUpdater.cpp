#include <render/sm/ShadowMapsUpdater.h>

ShadowMapsUpdater::ShadowMapsUpdater(
    ShipShadowMapUpdater& shipShadowMapUpdater) :
    _shipShadowMapUpdater(shipShadowMapUpdater)
{
}

void ShadowMapsUpdater::Update()
{
    _shipShadowMapUpdater.Update();
}

ShadowMapsUpdater* ShadowMapsUpdaterResolvingFactory::Make(Resolver& resolver)
{
    return new ShadowMapsUpdater(
        resolver.Resolve<ShipShadowMapUpdater>());
}
