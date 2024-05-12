#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>

class ShadowMapFramebufferGenerator : public Object
{
public:
    void Generate(int resolutionWidth, int resolutionHeight, unsigned int& fboId, unsigned int& textureId);
};

class ShadowMapFramebufferGeneratorResolvingFactory : public ResolvingFactory<ShadowMapFramebufferGenerator>
{
public:
    ShadowMapFramebufferGenerator* Make(Resolver& resolver);
};
