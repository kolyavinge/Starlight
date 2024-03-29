#pragma once

#include <lib/di/ResolvingFactory.h>
#include <audio/AudioSample.h>
#include <ui/Screen.h>
#include <vox/ScreenVox.h>
#include <vox/SampleCollection.h>

class RaceVox : public ScreenVox
{
    AudioSample& _weaponFireSample;
    AudioSample& _metalHitSample;
    AudioSample& _explosionSample;
    AudioSample& _powerUpPickSample;

public:
    RaceVox(SampleCollection& sampleCollection);

    void Voice(Screen& screen) override;
};

class RaceVoxResolvingFactory : public ResolvingFactory<RaceVox>
{
public:
    RaceVox* Make(Resolver& resolver) override;
};
