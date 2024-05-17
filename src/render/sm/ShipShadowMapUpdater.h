#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <gl/ShadowMapFramebufferGenerator.h>
#include <render/common/ShipRenderer.h>
#include <render/sm/ShadowMap.h>
#include <render/sm/ShadowMaps.h>

class ShipShadowMapUpdater : public Object
{
    const unsigned int _resolutionWidthHeight;
    Race& _race;
    ShipRenderer& _shipRenderer;
    ShadowMap& _playerShipShadowMap;
    Collection<ShadowMap>& _enemyShipShadowMaps;

public:
    ShipShadowMapUpdater(
        Race& race,
        ShipRenderer& shipRenderer,
        ShadowMaps& shadowMaps,
        ShadowMapFramebufferGenerator& shadowMapFramebufferGenerator);

    void Update();

private:
    void Update(Ship& ship, ShadowMap& shadowMap);
    void CalculateShadowMatrix(Ship& ship, ShadowMap& shadowMap, Vector3& lightPosition);
};

class ShipShadowMapUpdaterResolvingFactory : public ResolvingFactory<ShipShadowMapUpdater>
{
public:
    ShipShadowMapUpdater* Make(Resolver& resolver);
};
