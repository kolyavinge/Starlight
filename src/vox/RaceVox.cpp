#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <ui/RaceScreen.h>
#include <vox/RaceVox.h>

RaceVox::RaceVox(AudioDataCollection& audioDataCollection)
{
    for (int i = 0; i < SamplesCount; i++)
    {
        _weaponFireSamples[i].SetData(audioDataCollection.LaserData);
        _metalHitSamples[i].SetData(audioDataCollection.MetalHitData);
        _explosionSamples[i].SetData(audioDataCollection.ExplosionData);
        _powerUpPickSamples[i].SetData(audioDataCollection.PowerUpPickData);
    }
}

void RaceVox::Voice(Screen& screen)
{
    RaceScreen& raceScreen = (RaceScreen&)screen;
    Race& race = raceScreen.Race;
    Ship& player = race.Player;

    for (int i = 0; i < race.AllShips.GetCount(); i++)
    {
        Ship& ship = *race.AllShips[i];

        if (!Object::ReferenceEquals(player, ship))
        {
            SetSamplePosition(player, ship, _metalHitSamples[i]);
            SetSamplePosition(player, ship, _explosionSamples[i]);
            SetSamplePosition(player, ship, _weaponFireSamples[i]);
            SetSamplePosition(player, ship, _powerUpPickSamples[i]);
        }

        if (ship.IsDamaged)
        {
            _metalHitSamples[i].SetGain(0.4f);
            _metalHitSamples[i].Play();
        }

        if (ship.State == ShipState::Exploded)
        {
            _explosionSamples[i].Play();
        }

        if (ship.Weapon.IsFireActive)
        {
            _weaponFireSamples[i].SetGain(0.2f);
            _weaponFireSamples[i].Play();
        }

        if (ship.IsPowerUpPicked)
        {
            _powerUpPickSamples[i].SetGain(1.5f);
            _powerUpPickSamples[i].SetPitch(2.0f);
            _powerUpPickSamples[i].Play();
        }
    }
}

void RaceVox::SetSamplePosition(Ship& player, Ship& anotherShip, AudioSample& sample)
{
    Vector3 position(anotherShip.CentralLine.Front);
    position.Sub(player.CentralLine.Front);
    position.Mul(0.1f);
    sample.SetPosition(position);
}

RaceVox* RaceVoxResolvingFactory::Make(Resolver& resolver)
{
    return new RaceVox(resolver.Resolve<AudioDataCollection>());
}
