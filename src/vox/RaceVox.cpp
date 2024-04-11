#include <lib/Object.h>
#include <lib/Numeric.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <vox/RaceVox.h>

RaceVox::RaceVox(
    AudioDataCollection& audioDataCollection,
    Race& race) :
    _race(race)
{
    for (int i = 0; i < SamplesCount; i++)
    {
        _weaponFireSamples[i].SetData(audioDataCollection.LaserData);
        _metalHitSamples[i].SetData(audioDataCollection.MetalHitData);
        _explosionSamples[i].SetData(audioDataCollection.ExplosionData);
        _powerUpPickSamples[i].SetData(audioDataCollection.PowerUpPickData);
        _engineIdleSamples[i].SetData(audioDataCollection.EngineIdleData);
        _engineThrottleSamples[i].SetData(audioDataCollection.EngineThrottleData);
        _engineIdleSamples[i].SetLooped(true);
        _engineThrottleSamples[i].SetLooped(true);
    }
}

void RaceVox::Voice(Screen&)
{
    for (int i = 0; i < _race.AllShips.GetCount(); i++)
    {
        Ship& ship = *_race.AllShips[i];
        VoiceShip(_race.Player, ship, i);
    }
}

void RaceVox::Deactivate()
{
    for (int i = 0; i < SamplesCount; i++)
    {
        _engineIdleSamples[i].Pause();
        _engineThrottleSamples[i].Pause();
    }
}

void RaceVox::VoiceShip(Ship& player, Ship& ship, int shipIndex)
{
    if (!Object::ReferenceEquals(player, ship))
    {
        SetSamplePosition(player, ship, _metalHitSamples[shipIndex]);
        SetSamplePosition(player, ship, _explosionSamples[shipIndex]);
        SetSamplePosition(player, ship, _weaponFireSamples[shipIndex]);
        SetSamplePosition(player, ship, _powerUpPickSamples[shipIndex]);
        SetSamplePosition(player, ship, _engineIdleSamples[shipIndex]);
        SetSamplePosition(player, ship, _engineThrottleSamples[shipIndex]);
    }

    if (ship.IsDamaged)
    {
        _metalHitSamples[shipIndex].SetGain(0.4f);
        _metalHitSamples[shipIndex].Play();
    }

    if (ship.State == ShipState::Exploded)
    {
        _explosionSamples[shipIndex].Play();
    }

    if (ship.Weapon.IsFireActive)
    {
        _weaponFireSamples[shipIndex].SetGain(0.2f);
        _weaponFireSamples[shipIndex].Play();
    }

    if (ship.IsPowerUpPicked)
    {
        _powerUpPickSamples[shipIndex].SetGain(1.5f);
        _powerUpPickSamples[shipIndex].SetPitch(2.0f);
        _powerUpPickSamples[shipIndex].Play();
    }

    VoiceEngine(ship, _engineIdleSamples[shipIndex], _engineThrottleSamples[shipIndex]);
}

void RaceVox::VoiceEngine(Ship& ship, AudioSample& engineIdleSample, AudioSample& engineThrottleSample)
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

void RaceVox::SetSamplePosition(Ship& player, Ship& ship, AudioSample& sample)
{
    Vector3 position(ship.CentralLine.Front);
    position.Sub(player.CentralLine.Front);
    position.Mul(0.1f);
    sample.SetPosition(position);
}

RaceVox* RaceVoxResolvingFactory::Make(Resolver& resolver)
{
    return new RaceVox(
        resolver.Resolve<AudioDataCollection>(),
        resolver.Resolve<Race>());
}
