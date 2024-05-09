#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <render/sm/ShipShadowMapUpdater.h>

class ShadowMapsUpdater : public Object
{
    ShipShadowMapUpdater& _shipShadowMapUpdater;

public:
    ShadowMapsUpdater(
        ShipShadowMapUpdater& shipShadowMapUpdater);

    void Update();
};

class ShadowMapsUpdaterResolvingFactory : public ResolvingFactory<ShadowMapsUpdater>
{
public:
    ShadowMapsUpdater* Make(Resolver& resolver);
};
