#include <lib/Numeric.h>
#include <calc/Vector3.h>
#include <vox/common/ShipVox.h>

ShipVox::ShipVox(AudioDataCollection& audioDataCollection)
{
    for (int i = 0; i < SamplesCount; i++)
    {
        _weaponFireSamples[i].SetData(audioDataCollection.LaserData);
        _weaponFireSamples[i].SetGain(0.2f);

        _metalHitSamples[i].SetData(audioDataCollection.MetalHitData);
        _metalHitSamples[i].SetGain(0.4f);

        _explosionSamples[i].SetData(audioDataCollection.ExplosionData);

        _powerUpPickSamples[i].SetData(audioDataCollection.PowerUpPickData);
        _powerUpPickSamples[i].SetGain(1.5f);
        _powerUpPickSamples[i].SetPitch(2.0f);

        _engineIdleSamples[i].SetData(audioDataCollection.EngineIdleData);
        _engineIdleSamples[i].SetLooped(true);

        _engineThrottleSamples[i].SetData(audioDataCollection.EngineThrottleData);
        _engineThrottleSamples[i].SetLooped(true);
    }
}

void ShipVox::Voice(Vector3& listener, IArray<Ship*>& ships)
{
    for (int i = 0; i < ships.GetCount(); i++)
    {
        Ship& ship = *ships[i];
        VoiceShip(listener, ship, i);
    }
}

void ShipVox::Pause()
{
    for (int i = 0; i < SamplesCount; i++)
    {
        _engineIdleSamples[i].Pause();
        _engineThrottleSamples[i].Pause();
    }
}

void ShipVox::VoiceShip(Vector3& listener, Ship& ship, int shipIndex)
{
    if (!Object::ReferenceEquals(listener, ship))
    {
        SetSamplePosition(listener, ship, _metalHitSamples[shipIndex]);
        SetSamplePosition(listener, ship, _explosionSamples[shipIndex]);
        SetSamplePosition(listener, ship, _weaponFireSamples[shipIndex]);
        SetSamplePosition(listener, ship, _powerUpPickSamples[shipIndex]);
        SetSamplePosition(listener, ship, _engineIdleSamples[shipIndex]);
        SetSamplePosition(listener, ship, _engineThrottleSamples[shipIndex]);
    }

    if (ship.IsDamaged)
    {
        _metalHitSamples[shipIndex].Play();
    }

    if (ship.State == ShipState::Exploded)
    {
        _explosionSamples[shipIndex].Play();
    }

    if (ship.Weapon.IsFireActive)
    {
        _weaponFireSamples[shipIndex].Play();
    }

    if (ship.IsPowerUpPicked)
    {
        _powerUpPickSamples[shipIndex].Play();
    }

    VoiceEngine(ship, _engineIdleSamples[shipIndex], _engineThrottleSamples[shipIndex]);
}

void ShipVox::VoiceEngine(Ship& ship, AudioSample& engineIdleSample, AudioSample& engineThrottleSample)
{
    if (ship.State == ShipState::Active)
    {
        Vector3 velocity(ship.CentralLine.Front);
        velocity.Sub(ship.CentralLine.Rear);
        velocity.SetLength(ship.VelocityValue);
        engineThrottleSample.SetVelocity(velocity);

        if (ship.VelocityValue > 0.0f)
        {
            float pitch = ship.VelocityValue / ship.VelocityFunction.InitMaxVelocity;
            engineThrottleSample.SetPitch(pitch);
            if (!engineThrottleSample.IsPlayed())
            {
                engineIdleSample.Stop();
                engineThrottleSample.Play();
            }
        }
        else if (Numeric::FloatEquals(ship.VelocityValue, 0.0f))
        {
            if (!engineIdleSample.IsPlayed())
            {
                engineThrottleSample.Stop();
                engineIdleSample.Play();
            }
        }
    }
    else
    {
        engineIdleSample.Stop();
        engineThrottleSample.Stop();
    }
}

void ShipVox::SetSamplePosition(Vector3& listener, Ship& ship, AudioSample& sample)
{
    Vector3 position(ship.CentralLine.Front);
    position.Sub(listener);
    position.Mul(0.1f);
    sample.SetPosition(position);
}

ShipVox* ShipVoxResolvingFactory::Make(Resolver& resolver)
{
    return new ShipVox(
        resolver.Resolve<AudioDataCollection>());
}
