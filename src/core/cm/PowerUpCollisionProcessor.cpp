#include <core/cm/PowerUpCollisionProcessor.h>

void PowerUpCollisionProcessor::ProcessPowerUpsCollisions(Ship& ship, IArray<PowerUp>& powerUps)
{
    if (!_powerUpCollisionDetector.DetectCollisions(ship, powerUps)) return;
    PowerUpCollisionResult result = _powerUpCollisionDetector.Result;
    for (int i = 0; i < result.PowerUps.GetCount(); i++)
    {
        PowerUp& p = *result.PowerUps[i];
        ProcessPowerUp(ship, p);
        p.IsActive = false;
    }
}

void PowerUpCollisionProcessor::ProcessPowerUp(Ship& ship, PowerUp& powerUp)
{
    if (powerUp.Kind == PowerUpKind::Health)
    {
        ship.AddHealth(powerUp.Value);
    }
    else if (powerUp.Kind == PowerUpKind::Machinegun)
    {
        ship.Weapon.AddBullets((int)powerUp.Value);
    }
}
