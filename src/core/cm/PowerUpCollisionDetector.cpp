#include <core/cm/PowerUpCollisionDetector.h>

void PowerUpCollisionResult::Init()
{
    PowerUps.Clear();
}

bool PowerUpCollisionDetector::DetectCollisions(Ship& ship, IArray<PowerUp>& powerUps)
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
