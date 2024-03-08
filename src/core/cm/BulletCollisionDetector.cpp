#include <model/Bullet.h>
#include <core/cm/BulletCollisionDetector.h>

BulletCollisionDetector::BulletCollisionDetector()
{
    Result.Init();
}

bool BulletCollisionDetector::DetectCollisions(Ship& targetShip, IArray<Ship*>& allShips)
{
    Result.Init();
    for (int shipIndex = 0; shipIndex < allShips.GetCount(); shipIndex++)
    {
        Ship& otherShip = *allShips[shipIndex];
        if (Object::ReferenceEquals(targetShip, otherShip)) continue;
        for (int bulletIndex = 0; bulletIndex < otherShip.Weapon.Bullets.GetCount(); bulletIndex++)
        {
            Bullet& bullet = otherShip.Weapon.Bullets[bulletIndex];
            if (!bullet.IsActive) continue;
            if (_shipCollisionDetector.DetectCollisions(targetShip, bullet.PrevPosition, bullet.Position))
            {
                Result.Bullets.Add(&bullet);
            }
        }
    }

    bool hasCollisions = Result.Bullets.GetCount() > 0;

    return hasCollisions;
}
