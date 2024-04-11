#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <core/Race.h>
#include <audio/AudioSample.h>
#include <vox/common/AudioDataCollection.h>

class ShipVox : public Object
{
    inline static const int SamplesCount = Race::EnemiesCount + 1;

    Array<AudioSample, SamplesCount> _weaponFireSamples;
    Array<AudioSample, SamplesCount> _metalHitSamples;
    Array<AudioSample, SamplesCount> _explosionSamples;
    Array<AudioSample, SamplesCount> _powerUpPickSamples;
    Array<AudioSample, SamplesCount> _engineIdleSamples;
    Array<AudioSample, SamplesCount> _engineThrottleSamples;

public:
    ShipVox(AudioDataCollection& audioDataCollection);

    void Voice(Vector3& listener, IArray<Ship*>& ships);
    void Pause();
    void SetEngineIdleGain(float gain);

private:
    void VoiceShip(Vector3& listener, Ship& ship, int shipIndex);
    void VoiceEngine(Ship& ship, AudioSample& engineIdleSample, AudioSample& engineThrottleSample);
    void SetSamplePosition(Vector3& listener, Ship& ship, AudioSample& sample);
};

class ShipVoxResolvingFactory : public ResolvingFactory<ShipVox>
{
public:
    ShipVox* Make(Resolver& resolver) override;
};
