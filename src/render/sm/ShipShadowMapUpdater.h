#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <render/common/ShipRenderer.h>
#include <render/sm/ShadowMap.h>
#include <render/sm/ShadowMaps.h>

class ShipShadowMapUpdater : public Object
{
    const unsigned int _resolutionWidth;
    const unsigned int _resolutionHeight;
    Race& _race;
    ShipRenderer& _shipRenderer;
    Collection<ShadowMap>& _shipShadowMaps;

public:
    ShipShadowMapUpdater(
        Race& race,
        ShipRenderer& shipRenderer,
        ShadowMaps& shadowMaps);

    void Update();

private:
    void Update(Ship& ship, ShadowMap& shadowMap);
    void CalculateShadowMatrix(Ship& ship, ShadowMap& shadowMap, Vector3& lightPosition);
    void InitFBO(ShadowMap& shadowMap);
};

class ShipShadowMapUpdaterResolvingFactory : public ResolvingFactory<ShipShadowMapUpdater>
{
public:
    ShipShadowMapUpdater* Make(Resolver& resolver);
};
