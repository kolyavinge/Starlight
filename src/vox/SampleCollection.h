#pragma once

#include <lib/di/ResolvingFactory.h>
#include <lib/Object.h>
#include <audio/AudioSample.h>

class SampleCollection : public Object
{
public:
    AudioSample SelectMenuItemSample;
    AudioSample CountdownSample;
    AudioSample LaserSample;
    AudioSample MetalHitSample;
    AudioSample ExplosionSample;
    AudioSample PowerUpPickSample;

    void Init();
};

class SampleCollectionResolvingFactory : public ResolvingFactory<SampleCollection>
{
public:
    SampleCollection* Make(Resolver& resolver) override;
};
