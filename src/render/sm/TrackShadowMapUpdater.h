#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/ShadowMapFramebufferGenerator.h>
#include <render/common/TrackRenderer.h>
#include <render/sm/ShadowMap.h>
#include <render/sm/ShadowMaps.h>

class TrackShadowMapUpdater : public Object
{
    const unsigned int _resolutionWidth;
    const unsigned int _resolutionHeight;
    TrackRenderer& _trackRenderer;
    ShadowMap& _trackShadowMap;

public:
    TrackShadowMapUpdater(
        TrackRenderer& trackRenderer,
        ShadowMaps& shadowMaps,
        ShadowMapFramebufferGenerator& shadowMapFramebufferGenerator);

    void Update();

private:
    void CalculateShadowMatrix(Vector3& lightPosition, Vector3& lookAt);
};

class TrackShadowMapUpdaterResolvingFactory : public ResolvingFactory<TrackShadowMapUpdater>
{
public:
    TrackShadowMapUpdater* Make(Resolver& resolver);
};
