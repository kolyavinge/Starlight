#include <core/cm/PowerUpCollisionDetector.h>

void PowerUpCollisionResult::Init()
{
    PowerUps.Clear();
}

PowerUpCollisionDetector::PowerUpCollisionDetector(ShipCollisionDetector& shipCollisionDetector) :
    _shipCollisionDetector(shipCollisionDetector)
{
}

bool PowerUpCollisionDetector::DetectCollisions(Ship& ship, Collection<PowerUp>& powerUps)
{
    Result.Init();

    for (int i = 0; i < powerUps.GetCount(); i++)
    {
        PowerUp& powerUp = powerUps[i];
        if (!powerUp.IsActive) continue;
        if (_shipCollisionDetector.DetectCollisions(ship, powerUp.From, powerUp.To))
        {
            Result.PowerUps.Add(&powerUp);
        }
    }

    bool hasCollisions = Result.PowerUps.GetCount() > 0;

    return hasCollisions;
}

PowerUpCollisionDetector* PowerUpCollisionDetectorResolvingFactory::Make(Resolver& resolver)
{
    return new PowerUpCollisionDetector(resolver.Resolve<ShipCollisionDetector>());
}
