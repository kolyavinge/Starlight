#pragma once

#include <lib/di/ResolvingFactory.h>
#include <lib/Object.h>
#include <audio/AudioData.h>

class AudioDataCollection : public Object
{
public:
    AudioData SelectMenuItemData;
    AudioData CountdownData;
    AudioData LaserData;
    AudioData MetalHitData;
    AudioData ExplosionData;
    AudioData PowerUpPickData;

    void Init();
};

class AudioDataCollectionResolvingFactory : public ResolvingFactory<AudioDataCollection>
{
public:
    AudioDataCollection* Make(Resolver& resolver) override;
};
