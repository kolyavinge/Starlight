#pragma once

#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/Race.h>
#include <audio/AudioSample.h>
#include <ui/Screen.h>
#include <vox/common/AudioDataCollection.h>
#include <vox/ui/ScreenVox.h>

class RaceVox : public ScreenVox
{
    inline static const int SamplesCount = Race::EnemiesCount + 1;

    Array<AudioSample, SamplesCount> _weaponFireSamples;
    Array<AudioSample, SamplesCount> _metalHitSamples;
    Array<AudioSample, SamplesCount> _explosionSamples;
    Array<AudioSample, SamplesCount> _powerUpPickSamples;
    Array<AudioSample, SamplesCount> _engineIdleSamples;
    Array<AudioSample, SamplesCount> _engineThrottleSamples;
    Race& _race;

public:
    RaceVox(
        AudioDataCollection& audioDataCollection,
        Race& race);

    void Voice(Screen& screen) override;
    void Deactivate() override;

private:
    void VoiceShip(Ship& player, Ship& ship, int shipIndex);
    void VoiceEngine(Ship& ship, AudioSample& engineIdleSample, AudioSample& engineThrottleSample);
    void SetSamplePosition(Ship& player, Ship& ship, AudioSample& sample);
};

class RaceVoxResolvingFactory : public ResolvingFactory<RaceVox>
{
public:
    RaceVox* Make(Resolver& resolver) override;
};
