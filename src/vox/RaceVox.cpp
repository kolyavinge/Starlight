#include <model/Ship.h>
#include <core/Race.h>
#include <ui/RaceScreen.h>
#include <vox/RaceVox.h>

RaceVox::RaceVox(AudioDataCollection& audioDataCollection) :
    _weaponFireSample(audioDataCollection.LaserData),
    _metalHitSample(audioDataCollection.MetalHitData),
    _explosionSample(audioDataCollection.ExplosionData),
    _powerUpPickSample(audioDataCollection.PowerUpPickData)
{
}

void RaceVox::Voice(Screen& screen)
{
    RaceScreen& raceScreen = (RaceScreen&)screen;
    Race& race = raceScreen.Race;

    for (int i = 0; i < race.AllShips.GetCount(); i++)
    {
        Ship& ship = *race.AllShips[i];

        if (ship.IsDamaged)
        {
            _metalHitSample.SetGain(0.2f);
            _metalHitSample.Play();
        }

        if (ship.State == ShipState::Exploded)
        {
            _explosionSample.Play();
        }

        if (ship.Weapon.IsFireActive)
        {
            _weaponFireSample.SetGain(0.2f);
            _weaponFireSample.Play();
        }

        if (ship.IsPowerUpPicked)
        {
            _powerUpPickSample.SetGain(1.5f);
            _powerUpPickSample.SetPitch(2.0f);
            _powerUpPickSample.Play();
        }
    }
}

RaceVox* RaceVoxResolvingFactory::Make(Resolver& resolver)
{
    return new RaceVox(resolver.Resolve<AudioDataCollection>());
}
