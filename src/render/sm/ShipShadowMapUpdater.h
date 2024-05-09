#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <render/common/ShipsRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/sm/ShadowMap.h>
#include <render/sm/ShadowMaps.h>

class ShipShadowMapUpdater : public Object
{
    const unsigned int _resolutionWidth;
    const unsigned int _resolutionHeight;
    Race& _race;
    ShipsRenderer& _shipsRenderer;
    TrackRenderer& _trackRenderer;
    ShadowMap& _shipShadowMap;
    unsigned int _fboId;

public:
    ShipShadowMapUpdater(
        Race& race,
        ShipsRenderer& shipsRenderer,
        TrackRenderer& trackRenderer,
        ShadowMaps& shadowMaps);

    void Update();

private:
    void InitFBO();
};

class ShipShadowMapUpdaterResolvingFactory : public ResolvingFactory<ShipShadowMapUpdater>
{
public:
    ShipShadowMapUpdater* Make(Resolver& resolver);
};
