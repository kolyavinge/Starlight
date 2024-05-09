#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <render/sm/ShadowMap.h>

class ShadowMaps : public Object
{
public:
    ShadowMap ShipShadowMap;
};

class ShadowMapsResolvingFactory : public ResolvingFactory<ShadowMaps>
{
public:
    ShadowMaps* Make(Resolver& resolver);
};
