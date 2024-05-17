#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/ShadowMapFramebufferGenerator.h>
#include <render/sm/ShadowMaps.h>

class EmptyShadowMapInitializer : public Object
{
    ShadowMap& _emptyShadowMap;

public:
    EmptyShadowMapInitializer(
        ShadowMaps& shadowMaps,
        ShadowMapFramebufferGenerator& shadowMapFramebufferGenerator);

    void Init();
};

class EmptyShadowMapInitializerResolvingFactory : public ResolvingFactory<EmptyShadowMapInitializer>
{
public:
    EmptyShadowMapInitializer* Make(Resolver& resolver);
};
