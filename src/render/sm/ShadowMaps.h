#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <render/sm/ShadowMap.h>

class ShadowMaps : public Object
{
public:
    Array<ShadowMap, Race::EnemiesCount + 1> ShipShadowMaps;
    ShadowMap TrackShadowMap;
};

class ShadowMapsResolvingFactory : public ResolvingFactory<ShadowMaps>
{
public:
    ShadowMaps* Make(Resolver& resolver);
};
