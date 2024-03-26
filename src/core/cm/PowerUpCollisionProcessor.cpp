#include <core/cm/PowerUpCollisionProcessor.h>

PowerUpCollisionProcessor::PowerUpCollisionProcessor(PowerUpCollisionDetector& powerUpCollisionDetector) :
    _powerUpCollisionDetector(powerUpCollisionDetector)
{
}

void PowerUpCollisionProcessor::ProcessPowerUpsCollisions(Ship& ship, IArray<PowerUp>& powerUps)
{
    ship.IsPowerUpPicked = false;
    if (ship.State != ShipState::Active) return;
    if (!_powerUpCollisionDetector.DetectCollisions(ship, powerUps)) return;
    PowerUpCollisionResult result = _powerUpCollisionDetector.Result;
    for (int i = 0; i < result.PowerUps.GetCount(); i++)
    {
        PowerUp& p = *result.PowerUps[i];
        if (ProcessPowerUp(ship, p))
        {
            p.IsActive = false;
            ship.IsPowerUpPicked = true;
        }
    }
}

bool PowerUpCollisionProcessor::ProcessPowerUp(Ship& ship, PowerUp& powerUp)
{
    if (powerUp.Kind == PowerUpKind::Health)
    {
        if (!ship.IsHealtFull())
        {
            ship.AddHealth(powerUp.Value);
            return true;
        }
    }
    else if (powerUp.Kind == PowerUpKind::Machinegun)
    {
        if (!ship.Weapon.IsBulletsFull())
        {
            ship.Weapon.AddBullets((int)powerUp.Value);
            return true;
        }
    }
    else if (powerUp.Kind == PowerUpKind::Nitro)
    {
        if (!ship.Nitros.IsFull())
        {
            ship.Nitros.AddOne();
            return true;
        }
    }

    return false;
}

PowerUpCollisionProcessor* PowerUpCollisionProcessorResolvingFactory::Make(Resolver& resolver)
{
    return new PowerUpCollisionProcessor(resolver.Resolve<PowerUpCollisionDetector>());
}
