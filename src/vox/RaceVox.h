#pragma once

#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/Race.h>
#include <audio/AudioSample.h>
#include <ui/Screen.h>
#include <vox/ScreenVox.h>
#include <vox/AudioDataCollection.h>

class RaceVox : public ScreenVox
{
    inline static const int SamplesCount = Race::EnemiesCount + 1;

    Array<AudioSample, SamplesCount> _weaponFireSamples;
    Array<AudioSample, SamplesCount> _metalHitSamples;
    Array<AudioSample, SamplesCount> _explosionSamples;
    Array<AudioSample, SamplesCount> _powerUpPickSamples;

public:
    RaceVox(AudioDataCollection& audioDataCollection);

    void Voice(Screen& screen) override;

private:
    void SetSamplePosition(Ship& player, Ship& anotherShip, AudioSample& sample);
};

class RaceVoxResolvingFactory : public ResolvingFactory<RaceVox>
{
public:
    RaceVox* Make(Resolver& resolver) override;
};
