#include <model/Ship.h>
#include <core/Race.h>
#include <ui/RaceScreen.h>
#include <vox/RaceVox.h>

RaceVox::RaceVox()
{
    _weaponFireSample = nullptr;
    _metalHitSample = nullptr;
    _explosionSample = nullptr;
    _powerUpPickSample = nullptr;
}

void RaceVox::Init(SampleCollection& sampleCollection)
{
    _weaponFireSample = &sampleCollection.LaserSample;
    _metalHitSample = &sampleCollection.MetalHitSample;
    _explosionSample = &sampleCollection.ExplosionSample;
    _powerUpPickSample = &sampleCollection.PowerUpPickSample;
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
            _metalHitSample->SetGain(0.2f);
            _metalHitSample->Play();
        }

        if (ship.State == ShipState::Exploded)
        {
            _explosionSample->Play();
        }

        if (ship.Weapon.IsFireActive)
        {
            _weaponFireSample->SetGain(0.2f);
            _weaponFireSample->Play();
        }

        if (ship.IsPowerUpPicked)
        {
            _powerUpPickSample->SetGain(1.5f);
            _powerUpPickSample->SetPitch(2.0f);
            _powerUpPickSample->Play();
        }
    }
}

RaceVox* RaceVoxResolvingFactory::Make(Resolver&)
{
    return new RaceVox();
}
