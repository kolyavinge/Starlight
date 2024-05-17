#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <render/sm/ShadowMap.h>

class ShadowMaps : public Object
{
public:
    ShadowMap PlayerShipShadowMap;
    Array<ShadowMap, Race::EnemiesCount> EnemyShipShadowMaps;
    ShadowMap TrackShadowMap;
};

class ShadowMapsResolvingFactory : public ResolvingFactory<ShadowMaps>
{
public:
    ShadowMaps* Make(Resolver& resolver);
};
